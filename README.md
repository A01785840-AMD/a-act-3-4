# Investigación y Reflexión sobre Árboles Binarios de Búsqueda (BST)

## Introducción

En el contexto de este proyecto, donde se analizan registros de logs con el objetivo de identificar accesos maliciosos,
como intentos repetidos desde direcciones IP potencialmente comprometidas, es fundamental utilizar estructuras de datos
que permitan organizar y clasificar eficientemente grandes volúmenes de información. En este caso, se ha optado por
utilizar un **Árbol Binario de Búsqueda (BST)** para almacenar y clasificar direcciones IP según su número de accesos,
lo cual facilita la detección rápida de comportamientos anómalos que podrían indicar una red infectada o el uso de una
botnet.

## Reflexión sobre el uso de BST

### Ventajas teóricas

Los árboles binarios de búsqueda son ideales para organizar datos de manera jerárquica, especialmente cuando se desea
clasificar elementos numéricos o buscar elementos extremos (como máximos o mínimos). Sus ventajas incluyen:

* **Ordenamiento implícito**: Al insertar elementos según una clave (en este caso, el número de accesos), el BST
  mantiene los datos ordenados sin necesidad de aplicar algoritmos de ordenamiento adicionales.
* **Búsqueda eficiente**: Permite encontrar elementos, como IPs con un número específico de accesos, en tiempo
  promedio $O(\log n)$ si el árbol está balanceado.
* **Recorrido estructurado**: Facilita recorrer los datos en orden o en orden inverso, útil para extraer las IPs con más
  actividad.

### Por qué se utilizaron

En este proyecto, las características del BST representan una ventaja significativa por las siguientes razones:

1. **Detección de patrones extremos**: Permite acceder rápidamente a las IPs con más accesos, clave para identificar
   posibles bots o ataques DDoS.

2. **No se necesita modificación dinámica por IP**: Una vez que se cuenta el número de accesos por IP, no es necesario
   modificar los datos, solo organizarlos y consultarlos eficientemente.

3. **Agrupación natural por frecuencia**: Las IPs con igual número de accesos se almacenan juntas, lo que facilita el
   análisis por grupos de comportamiento.

4. **Priorización de riesgos**: Al recorrer el BST en orden descendente, se prioriza el análisis de las IPs más
   sospechosas, permitiendo actuar rápidamente.

## Conclusión

El uso de un Árbol Binario de Búsqueda ha demostrado ser una elección eficiente y adecuada para el análisis de logs
orientado a la ciberseguridad. Su capacidad para ordenar y clasificar automáticamente los accesos permite identificar
rápidamente patrones anómalos y potenciales redes comprometidas. En comparación con otras estructuras, el BST aporta una
solución clara, jerárquica y eficaz sin añadir complejidad innecesaria al sistema.
