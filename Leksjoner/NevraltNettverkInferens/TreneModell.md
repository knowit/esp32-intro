## TensorFlow Lite modell for mikrokontrollere

[![Open In Colab](https://colab.research.google.com/assets/colab-badge.svg)](https://colab.research.google.com/github/knowit/esp32-intro/blob/master/Leksjoner/NevraltNettverkInferens/sin_model_tflite.ipynb)

Som en veldig enkel demonstasjon så lager vi en modell trent på data generert av sinus funksjonen. Målet er en modell som for en verdi, `x` kan predikere veridens sinus, `y`.

All koden for dette finner du i denne [jupyter notebooken](./sin_model_tflite.ipynb). Du kan også kjøre koden selv i [Google Colab](https://colab.research.google.com/github/knowit/esp32-intro/blob/master/Leksjoner/NevraltNettverkInferens/sin_model_tflite.ipynb)

### Konvertere TenorFlow modeller til TensorFlow Lite modeller

Når man jobber med TensorFlow så er det mest vanlig å jobbe med det som en backend til [Keras](https://keras.io/), et veldig høy-level maskinlæringsbibliotek.

Keras-koden i python for sette opp og trene et enkelt sekvensielt nevralt nett ser slik ut:
```python
# Simple sequential neural network
model = tf.keras.Sequential([
  keras.layers.Dense(16, activation='relu', input_shape=(1,)),
  keras.layers.Dense(16, activation='relu'),
  keras.layers.Dense(1)
])

# Select optimizer and loss function 
model.compile(optimizer='adam', loss="mse", metrics=["mae"])

# Train on some data
model.fit(x_train, y_train, epochs=100,
          validation_data=(x_validate, y_validate))

# Serialize and save model to `my_tensorflow_model/`
model.save('my_tensorflow_model')
```

Merk siste linjen som serialiserer og lagrer modellen til disk. Med TensorFlow som backend får man modellen serialisert til TenorFlow sitt `SavedModel`-format. Ved hjelp av `TFLiteConverter` i TensorFlow Lite kan vi konvertere denne til en TensorFlow Lite modell

```python
# Open converter on a TensorFlow SavedModel
converter = tf.lite.TFLiteConverter.from_saved_model('my_tensorflow_model')

# Do the conversion, return value is a byte-array
model_tflite = converter.convert()

# Save model to a file named `my_tensorflow_lite_model.tflite`
open('my_tensorflow_lite_model.tflite', "wb").write(model_tflite)
```

### Optimalisert modell for mikrokontrollere 

For mikrokontrollere er det nyttig å optimalisere modellen for både bedre ytelse og mindre minnebruk

Koden under optimalisere modellen slik at alle trente parametere blir redusert til byte heltall. Dette vil selvfølgelig redusere størrelsen på modellen og bruke mindre minne, men også forbedre ytelsen ettersom heltallsoperasjoner på de fleste mikrokontrollere er mye raskere enn flyttallsoperasjoner 
```python
# Open converter on a TensorFlow SavedModel
converter = tf.lite.TFLiteConverter.from_saved_model('my_tensorflow_model')

# Enforce default optimization
converter.optimizations = [tf.lite.Optimize.DEFAULT]

# Define a representative dataset for optimizing quantization parameters
def representative_dataset():
  for i in range(500):
    yield([x_train[i].reshape(1, 1)])
converter.representative_dataset = representative_dataset

# Enforce only byte-integer operations and model input and output as byte-integers
converter.target_spec.supported_ops = [tf.lite.OpsSet.TFLITE_BUILTINS_INT8]
converter.inference_input_type = tf.int8
converter.inference_output_type = tf.int8

# Do the conversion, return value is a byte-array
model_tflite = converter.convert()

# Save model to a file named `my_optimized_tensorflow_lite_model.tflite`
open('my_optimized_tensorflow_lite_model.tflite', "wb").write(model_tflite)
```

Du kan lese mer om optimalisering av TensorFlow Lite modeller [her](https://www.tensorflow.org/lite/performance/model_optimization)

Etter alle parametere i modellen har blitt _kvantisert_ til heltall kan du bruke `Interpreter`-klassen med Python APIet for å sjekke kvantifiseringsparameterene. Vi kommer til å trenge disse verdiene når vi flytter modellen over på mikrokontroller, så det kan være greit å lagre dem til en fil
```python
interpreter = tf.lite.Interpreter(model_content=model_tflite)

input_scale, input_zero_point = interpreter.get_input_details()[0]['quantization'] 
output_scale, output_zero_point = interpreter.get_output_details()[0]['quantization']

# Example:
# quantized_data = input_data / input_scale + input_zero_point
# output_data    = (quantized_data - output_zero_point) * output_scale
```

### TensorFlow Lite modell til mikrokontroller

Siden vi skriver programmet på mikrokontrolleren i C/C++ så kan vi bare konvertere hele filen til en hexdump i en C-array. Dette er gjort veldig enkelt med `xxd`

```
$ apt-get update && apt-get -qq install xxd
$ xxd -i my_optimized_tensorflow_lite_model.tflite > my_optimized_tensorflow_lite_model.cc
$ head my_optimized_tensorflow_lite_model.cc
unsigned char my_optimized_tensorflow_lite_model_tflite[] = {
  0x20, 0x00, 0x00, 0x00, 0x54, 0x46, 0x4c, 0x33, 0x00, 0x00, 0x00, 0x00,
  0x14, 0x00, 0x20, 0x00, 0x1c, 0x00, 0x18, 0x00, 0x14, 0x00, 0x10, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x08, 0x00, 0x04, 0x00, 0x14, 0x00, 0x00, 0x00,
  0x1c, 0x00, 0x00, 0x00, 0xa4, 0x00, 0x00, 0x00, 0xd4, 0x00, 0x00, 0x00,
  0x28, 0x03, 0x00, 0x00, 0x38, 0x03, 0x00, 0x00, 0x34, 0x09, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x0c, 0x00, 0x14, 0x00, 0x10, 0x00, 0x0c, 0x00, 0x08, 0x00, 0x04, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00,
  0x24, 0x00, 0x00, 0x00, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
```
