# Fract-ol
This project was developed for 42 school. For comprehensive information regarding the requirements, please consult the PDF file in the subject folder of the repository. Furthermore, I have provided my notes and a concise summary below.
``` diff
+ Keywords: Similar repeated patterns
+ Similarity occurs at different scales
+ Leaf, trees, cauliflower, bronchial system, coast line
+ Set of complex numbers (real + imaginary)
```
_Mindmap based on [The Mandelbrot Set - Numberphile](https://www.youtube.com/watch?v=NGMRB4O922I) (shinckel, 2023)_
![mind-map_fract-ol1](https://github.com/shinckel/fract-ol/assets/115558344/2ab02efd-7e0a-4ee9-90f2-67190a281f34)

_Graph from [Geogebra, author Ben Sparks](https://www.geogebra.org/m/BUVhcRSv#material/Npd3kBKn).
"Simple exploration of the Mandelbrot Set (and the orbits of the iteration with different 'c' values). Stable orbits are coloured black. The colours 'outside' the set are determined by how quickly the iteration diverges..."_
<img width="931" alt="Screenshot 2023-06-09 at 4 39 46 PM" src="https://github.com/shinckel/fract-ol/assets/115558344/17ff352b-6b10-4576-98d4-47d550d81e3c">

## High-level Overview
By iterating the formula $f_{c}(z) = z^2 + c$ and evaluating the behavior of the resulting complex numbers, it is possible to classify each pixel on the canvas as either part of the Mandelbrot set (bounded) or not (escaped).


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

## High-level Overview

## Concepts

| Task | Prototype | Description |
|:----|:-----:|:--------:|
| **`git submodule`** | `git submodule add ./libft` | to add an external library into yor project, it will generate a `.gitmodules` file. P.S. You must add targets to the Makefile! |
| **`xquartz`** | `brew install --cask xquartz` | allows cross-platform applications using X11 for the GUI to run on macOS |
| **`X11`** | x | enables users to run graphical applications on a remote server and interact with them using their local display and I/O devices |
| **`Create canvas`** | `mlx_init()` `mlx_new_window()` `mlx_loop()` | initializes the MiniLibX library and assigns the mlx(connection with the graphical server); creates a new window using the specified width, height, and name, and assigns the window pointer to `fractal.win`; enters the event loop of MiniLibX, which continuously listens for events such as key presses and mouse movements. This function call will keep the program running until the window is closed |
|**`put some color`**|  `for (int x = 0; x < fractal.width; x++) { for (int y = 0; y < fractal.height; y++) { mlx_pixel_put(fractal.mlx, fractal.win, x, y, bg_color); } }` | manage the color pixel per pixel: `graphical server` - `window pointer` - `x/y coordinates` - `color` |
| **`handling events`** | `mlx_key_hook(fractal.win, deal_keys, (void *)0);` |  |