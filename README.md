# so_long

Este es mi proyecto so_long para la escuela 42. El objetivo principal de este proyecto es crear un pequeño juego 2D utilizando la librería gráfica MiniLibX. Es una excelente introducción al trabajo con ventanas, manejo de eventos, renderizado de texturas y sprites en C.

## Descripcion
so_long es un juego de vista cenital donde el jugador debe explorar un mapa, recolectar todos los coleccionables y finalmente alcanzar la salida para ganar. Todo esto, intentando realizar la menor cantidad de movimientos posibles.

## Caracteristicas Principales
- Uso de la librería MiniLibX para renderizar gráficos y gestionar la ventana.
- Manejo fluido de eventos de teclado (hooks) y cierre seguro de ventanas.
- Parseo profundo de mapas .ber con validaciones estrictas (el mapa debe ser rectangular, estar completamente cerrado por muros, y tener un camino válido que conecte al jugador con los coleccionables y la salida).
- Gestión rigurosa de la memoria para garantizar que el juego cierre completamente libre de leaks.

## Los Mapas (.ber)
El juego recibe como argumento un archivo con extensión .ber que define la estructura del nivel.
Los caracteres válidos para la construcción del mapa son:
- 0 : Espacio vacío (por donde se puede caminar)
- 1 : Muro (obstáculo insalvable)
- C : Coleccionable (hay que recogerlos todos)
- E : Salida (solo se activa cuando recoges todos los coleccionables)
- P : Posición inicial del jugador

Ejemplo de un mapa válido:
```text
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

## Compilacion y Ejecucion

### Requisitos
Asegúrate de tener instalados make y gcc (o clang), junto con las dependencias del sistema operativo correspondientes a la versión de la MiniLibX que estés utilizando (dependencias de X11/XQuartz en macOS/Linux).

### Compilación Estándar
Para compilar la versión obligatoria del juego, sitúate en la raíz del repositorio y ejecuta:
```bash
make
```
Esto generará el ejecutable so_long.

### Compilación Bonus
Si quieres jugar con enemigos, compila el proyecto ejecutando:
```bash
make bonus
```

### Ejecución
Una vez compilado, puedes iniciar el juego pasándole la ruta de un mapa válido como argumento:
```bash
./so_long mapas/mapa_ejemplo.ber
```

## Controles
- W o Flecha Arriba : Mover hacia arriba
- A o Flecha Izquierda : Mover hacia la izquierda
- S o Flecha Abajo : Mover hacia abajo
- D o Flecha Derecha : Mover hacia la derecha
- ESC o hacer clic en la X de la ventana : Salir del juego de forma limpia y segura

## Funcionalidades del Bonus
La versión compilada con make bonus incluye mejoras visuales y mecánicas para enriquecer la jugabilidad:
- Enemigos (Patrullas): Enemigos que añaden dificultad al mapa. Si el jugador entra en contacto con uno, el juego termina inmediatamente (Game Over).

---
Desarrollado por Blukker (bsaldana)
