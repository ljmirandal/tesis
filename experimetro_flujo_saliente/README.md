# Archivos de la Tesis

Existe una carpeta llamada `flujoneutrones` para cada sección del flujo. Si deseas utilizarla, debes cambiarla por la carpeta "codigo" eliminando lo que está entre paréntesis.

Para compilar el código en una carpeta diferente, debes utilizar el siguiente comando:

`cmake -DGeant4_DIR=/opt/geant4/lib/Geant4-10.3.3/ ../humedadvariada/codigo; make -j2`

Para ejecutar el código, utiliza el siguiente comando:

`./wcd -m input.in > archivo.txt`

Si deseas cambiar la humedad, debes acceder a la siguiente dirección: `humedadvariada/codigo/src/`. Luego, ingresa al archivo DetectorConstruction.cc con el editor de texto `vim`.

En la línea 103, escribe `sueloBS` (0% de humedad), `sueloBH5` (5% de humedad), `sueloBH15" (15% de humedad), `sueloBH25` (25% de humedad) o `sueloBH30` (30% de humedad).

Espero que esto sea de ayuda. Si tienes alguna pregunta, no dudes en hacerla :)
