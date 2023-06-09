# Fract-ol
This project was developed for 42 school. For comprehensive information regarding the requirements, please consult the PDF file in the subject folder of the repository. Furthermore, I have provided my notes and a concise summary below.
``` diff
+ Keywords: Similar repeated patterns
+ Similarity occurs at different scales
+ Leaf, trees, cauliflower, bronchial system, coast line
+ Set of complex numbers (real + imaginary numbers)
```
_Mindmap based on [The Mandelbrot Set - Numberphile](https://www.youtube.com/watch?v=NGMRB4O922I) (shinckel, 2023)_
![mind-map_fract-ol1](https://github.com/shinckel/fract-ol/assets/115558344/8defe75f-a496-430f-a00a-eeb4680f1eb2)

_Graph from [Geogebra, author Ben Sparks](https://www.geogebra.org/m/BUVhcRSv#material/Npd3kBKn).
"Simple exploration of the Mandelbrot Set (and the orbits of the iteration with different 'c' values). Stable orbits are coloured black. The colours 'outside' the set are determined by how quickly the iteration diverges..."_
<img width="931" alt="Screenshot 2023-06-09 at 4 39 46 PM" src="https://github.com/shinckel/fract-ol/assets/115558344/17ff352b-6b10-4576-98d4-47d550d81e3c">

## High-level Overview
By iterating the formula z = z^2 + c and evaluating the behavior of the resulting complex numbers, it is possible to classify each pixel on the canvas as either part of the Mandelbrot set (bounded) or not (escaped).

## Concepts


## Project Description
- This project is about creating a small fractal exploration program. First, you have to know what a fractal is.
- You must use the MiniLibX. Either the version available on the school machines, or installing it using its sources.
- You have to turn in a Makefile which will compile your source files. It must not relink.
- Global variables are forbidden.

### Rendering
- Your program must offer the Julia set and the Mandelbrot set.
- The mouse wheel zooms in and out, almost infinitely (within the limits of the computer). This is the very principle of fractals.

 ### Graphic management
- Your program has to display the image in a window.
- Pressing ESC must close the window and quit the program in a clean way.
- Clicking on the cross on the window’s frame must close the window and quit the program in a clean way.
- The use of the images of the MiniLibX is mandatory.

## Concepts
