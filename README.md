# Fract-ol
This project was developed for 42 school. For comprehensive information regarding the requirements, please consult the PDF file in the subject folder of the repository. Furthermore, I have provided my notes and a concise summary below.
``` diff
+ keywords: similar repeated patterns
+ similarity occurs at different scales
+ leaf, trees, cauliflower, bronchial system, coast line
+ set of complex numbers (real + imaginary)
+ estable iteration
```
_Mindmaps (shinckel, 2023)_
![mind-map_fract-ol1](https://github.com/shinckel/fract-ol/assets/115558344/2ab02efd-7e0a-4ee9-90f2-67190a281f34)

_Graph from [Geogebra, author Ben Sparks](https://www.geogebra.org/m/BUVhcRSv#material/Npd3kBKn).
"Simple exploration of the Mandelbrot Set (and the orbits of the iteration with different 'c' values). Stable orbits are coloured black. The colours 'outside' the set are determined by how quickly the iteration diverges..."_
<img width="931" alt="Screenshot 2023-06-09 at 4 39 46 PM" src="https://github.com/shinckel/fract-ol/assets/115558344/17ff352b-6b10-4576-98d4-47d550d81e3c">

_Visualization of the Mandelbrot and Julia iteration, made by Stefan Bion [Click here](https://www.stefanbion.de/fraktal-generator/mandeliteration.htm)_
![juliaset](https://github.com/shinckel/fract-ol/assets/115558344/ff6bb7db-8d32-45e8-a765-10b30c5ba116)

## High-level Overview

The Mandelbrot set, denoted M, is the set of complex numbers `c` such that the critical point `z = 0` of the polynomial $P(z) = z^2 + c$ has an orbit that is not attracted to infinity. By iterating the formula $f_{c}(z) = z^2 + c$ and evaluating the behavior of the resulting complex numbers, it is possible to classify each pixel on the canvas as either part of the Mandelbrot set (bounded) or not (escaped). **Theorem: The orbit of 0 tends to infinity if and only if at some point it has modulus >2.**

1. Choose a maximal iteration number N;
2. For each pixel p of the image:
		Let c be the complex number represented by p
		Let z be a complex variable
		Set z to 0
3. Do the following N times:    
		If |z|>2 then color the pixel white, end this loop prematurely, go to the next pixel
		Otherwise replace z by z*z+c
4. If the loop above reached its natural end: color the pixel p in black
5. Go to the next pixel

**References:** <br /> 
[Math University Toulouse](https://www.math.univ-toulouse.fr/~cheritat/wiki-draw/index.php/Mandelbrot_set#Basic_algorithm) <br />
[WikiBooks](https://en.wikibooks.org/wiki/Fractals#Introduction) <br />
[The Nature of Code, chapter 8](https://natureofcode.com/book/chapter-8-fractals/) <br />
[Distance Estimator algorithm](http://mrob.com/pub/muency/distanceestimator.html)

## Concepts

| Task | Prototype | Description |
|:----|:-----:|:--------:|
| **`git submodule`** | `git submodule add ./libft` | to add an external library into yor project, it will generate a `.gitmodules` file. P.S. You must add targets to the Makefile! |
| **`xquartz`** | `brew install --cask xquartz` | allows cross-platform applications using X11 for the GUI to run on macOS |
| **`X11`** | x | enables users to run graphical applications on a remote server and interact with them using their local display and I/O devices |
| **`Create canvas`** | `mlx_init()` `mlx_new_window()` `mlx_loop()` | initializes the MiniLibX library and assigns the mlx(connection with the graphical server); creates a new window using the specified width, height, and name, and assigns the window pointer to `fractal.win`; enters the event loop of MiniLibX, which continuously listens for events such as key presses and mouse movements. This function call will keep the program running until the window is closed |
|**`put some color`**|  `for (int x = 0; x < fractal.width; x++) { for (int y = 0; y < fractal.height; y++) { mlx_pixel_put(fractal.mlx, fractal.win, x, y, bg_color); } }` | manage the color pixel per pixel: `graphical server` - `window pointer` - `x/y coordinates` - `color` |
| **`handling events`** | `mlx_key_hook(fractal.win, deal_keys, (void *)0);` |  |
| **`scanline methods`**| | (a.k.a. raster scan) all pixels in the image will be scanned. For each pixel, the color has to be determined. The coordinates of the pixel are converted into mathematical parameters. Then an algorithm is run on that parameter |
| [aspect ratio](https://www.youtube.com/watch?v=B3pjri-5sPc) | `width / height` `4:3` `320x40` | display an image of a specific size, inside a rectangle that is another size(difference between image and container) |
| **`double`** | `double zx` `double pi = 3.14159` | to handle the floating-point calculations accurately |
| **`orbit trap`** | $0 * 0 - 0 * 0 + (-0.5) = -0.5$ ... $(-0.5) * (-0.5) - 0 * 0 + (-0.5) = 0.25 - 0.5 = -0.25$ | an orbit refers to a sequence of values generated by repeatedly applying a function or transformation to an initial value. Each value in the sequence becomes the input for the next iteration, and the process continues indefinitely or until a specific condition is met. Behavior of the orbit: the point belongs to the fractal set or not? does it tend to infinity, remain bounded, or exhibit certain patterns? |
| **`Theorem`** | `The orbit of 0 tends to infinity if and only if at some point it has modulus >2` | the modulus of a complex number measures its distance from the origin (0, 0) in the complex plane. Mathematically, if $z = a + bi$, where $a$ is the real part and $b$ is the imaginary part, then the modulus(a.k.a. magnitude) $z$ is given by $sqrt(a^2 + b^2)$. **If there exists a value in the orbit whose distance from the origin exceeds 2, then the orbit will eventually escape to infinity.** modulus of $z$: $\sqrt{3^2 + 4^2} = \sqrt{9 + 16} = \sqrt{25} = 5$ |
| $f_{c}(z) = z^2 + c$ | $(x^2 - y^2) + (2xy)i + (c_re + c_imi)$ | in the complex plane, `x` is the real axis, therefore the real component of `z`, and `y` is the imaginary axis, the imaginary component of `z`. To calculate `zx`, I will extract the first part of the formula: `fractal->zx_new = zx * zx - zy * zy + fractal->cx;`, and for `zy`: `fractal->zy_new = 2 * zx * zy + fractal->cy;` |
| modulus of $z = sqrt(a^2 + b^2) > 2$ | `zx * zx + zy * zy > 4.0` | I don't need to calculate the square root of $(a^2 + b^2)$ as any number bigger than $4$ will have the square root bigger than $2$, as $\sqrt{4} = 2$ |
| **`xarrow`** **`yarrow`** | | position horizontally `xarrow` and vertically `yarrow` relative to the pixel coordinates `x` `y` |
| **`Mandelbrot boundary`** | $x = (-2.0, 0.47)$ $y = (-1.12, 1.12)$ | these are the coordinates of the outer boundary of the mandelbrot set. I can use it as values to establish its size in relation to the screen <img width="471" alt="Screenshot 2023-06-30 at 1 47 10 PM" src="https://github.com/shinckel/fract-ol/assets/115558344/f23248c8-8389-4291-a6d6-5d8153d596a4"> |
| **`smooth colors`** | $iter + 1 - log(log(sqrt(zx * zx + zy * zy))) / log(2)$ | escape time (how long does it take, a.k.a. number of iterations, before going to infinity?), **color algorithms**: the "bands" are generated because we can only set colors to pixels in discrete numbers of iterations, therefore the colors are divided as solid areas. The outermost solid color is the one out of the bailout radius. References: [Plotting algorithms - Wikipedia](https://en.wikipedia.org/wiki/Plotting_algorithms_for_the_Mandelbrot_set), [Renormalizing the Mandelbrot Escape](http://linas.org/art-gallery/escape/escape.html), [Mandelbrot Set Coloring Presentation](https://www.youtube.com/watch?v=r5rDs_qINMg), [Draw a Mandelbrot set fractal with smoothly shaded colors in C#](http://www.csharphelper.com/howtos/howto_mandelbrot_smooth.html#google_vignette) |
| [42 docs](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html) | | |
| **`Julia set`** |  | it is deeply connected to the Mandelbrot set, a.k.a patterns that emerge from it. Key concept: instead of the complex number $c$ being related to the pixel that you are iterating in the complex plane, it will be just a constant. If there is no imaginary part, the set will be symmetrical. [Summary](https://www.cantorsparadise.com/the-julia-set-e03c29bed3d0), [different types](http://paulbourke.net/fractals/juliaset/)  |

```c
frac->cx = (x + frac->xarrow) / frac->zoom
	* (0.47 + 2.0) / (frac->width) - 2.0;
frac->cy = (y + frac->yarrow) / frac->zoom
	* (1.12 + 1.12) / (frac->width) - 1.12;

set cx and cy to the complex plane pixels
total range (but only showing positives)
0 * ((0.47 + 2.0) / 1280) = 0
1280 * ((0.47 + 2.0) / 1280) = 0.47 + 2.0 = 2.47
now, with negatives
0 * ((0.47 + 2.0) / 1280) - 2.0 = -2.0
1280 * ((0.47 + 2.0) / 1280) - 2.0 = 0.47
```
