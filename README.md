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
![mind-map_fract-ol1](https://github.com/shinckel/fract-ol/assets/115558344/2d9a9093-52f4-4745-bb16-f70fe271a709)

![mind-map_fract-ol2](https://github.com/shinckel/fract-ol/assets/115558344/19d4a58a-f14f-42d7-83dd-25b7bfb79be0)

![mind-map_fract-ol3](https://github.com/shinckel/fract-ol/assets/115558344/8a88c0ec-d51d-4c1b-9a35-4e0809c0620b)

_Graph from [Geogebra, author Ben Sparks](https://www.geogebra.org/m/BUVhcRSv#material/Npd3kBKn).
"Simple exploration of the Mandelbrot Set (and the orbits of the iteration with different 'c' values). Stable orbits are coloured black. The colours 'outside' the set are determined by how quickly the iteration diverges..."_
<img width="955" alt="Screenshot 2023-08-01 at 8 56 42 PM" src="https://github.com/shinckel/fract-ol/assets/115558344/31569515-089e-4398-9cd8-40938f9d05ea">

_Visualization of the Mandelbrot and Julia iteration, made by Stefan Bion [Click here](https://www.stefanbion.de/fraktal-generator/mandeliteration.htm)_
![mind-map_fract-ol4](https://github.com/shinckel/fract-ol/assets/115558344/f2f7f03c-56d1-4274-9c37-0bfe48c6fca0)

## High-level Overview

The Mandelbrot set, denoted M, is the set of complex numbers `c` such that the critical point `z = 0` of the polynomial $P(z) = z^2 + c$ has an orbit that is not attracted to infinity. By iterating the formula $f_{c}(z) = z^2 + c$ and evaluating the behavior of the resulting complex numbers, it is possible to classify each pixel on the canvas as either part of the Mandelbrot set (bounded) or not (escaped). **Theorem: The orbit of 0 tends to infinity if and only if at some point it has modulus >2.**

1. Choose a maximal iteration number `N`;
2. For each pixel `p` of the image:
- Let `c` be the complex number represented by `p`
- Let `z` be a complex variable
- Set `z` to `0`
3. Do the following `N` times:    
- If `|z|>2` then color the pixel white, end this loop prematurely, go to the next pixel
- Otherwise replace z by `z*z+c`, a.k.a. iterate through the Mandelbrot formula
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
| **`git submodule`** | `git submodule add git@github.com:shinckel/libft.git` | To add an external library to your project, it will generate a `.gitmodules` file. P.S. You must add targets to the Makefile! |
| **`xquartz`** | `brew install --cask xquartz` | allows cross-platform applications using X11 for the GUI to run on macOS |
| **`X11`** | x | enables users to run graphical applications on a remote server and interact with them using their local display and I/O devices |
| **`Create canvas`** | `mlx_init()` `mlx_new_window()` `mlx_loop()` | Initializes the MiniLibX library and assigns the mlx(connection with the graphical server); creates a new window using the specified width, height, and name, and assigns the window pointer to `fractal.win`; enters the event loop of MiniLibX, which continuously listens for events such as key presses and mouse movements. This function call will keep the program running until the window is closed |
|**`put some color`**|  `for (int x = 0; x < fractal.width; x++) { for (int y = 0; y < fractal.height; y++) { mlx_pixel_put(fractal.mlx, fractal.win, x, y, bg_color); } }` | Manage the color pixel per pixel: `graphical server` - `window pointer` - `x/y coordinates` - `color` |
| **`handling events`** | `mlx_key_hook(fractal.win, deal_keys, (void *)0);` | Intercepting function calls or messages or events passed between software components. Code that handles such intercepted function calls, events or messages is called a [hook](https://harm-smits.github.io/42docs/libs/minilibx/hooks.html#hooking-into-key-events). In this case, intercepting keyboard or mouse event |
| **`scanline methods`**| x | (a.k.a. raster scan) All pixels in the image will be scanned. For each pixel, the color has to be determined. The coordinates of the pixel are converted into mathematical parameters. Then an algorithm is run on that parameter |
| [aspect ratio](https://www.youtube.com/watch?v=B3pjri-5sPc) | `width / height` `4:3` `320x40` | display an image of a specific size, inside a rectangle that is another size(difference between image and container) |
| **`double`** | `double zx` `double pi = 3.14159` | to handle the floating-point calculations accurately |
| **`orbit trap`** | $0 * 0 - 0 * 0 + (-0.5) = -0.5$ ... $(-0.5) * (-0.5) - 0 * 0 + (-0.5) = 0.25 - 0.5 = -0.25$ | an orbit refers to a sequence of values generated by repeatedly applying a function or transformation to an initial value. Each value in the sequence becomes the input for the next iteration, and the process continues indefinitely or until a specific condition is met. The behavior of the orbit: does the point belong to the fractal set? does it tend to infinity, remain bounded, or exhibit certain patterns? |
| **`Theorem`** | `The orbit of 0 tends to infinity if and only if at some point it has modulus >2` | The modulus of a complex number measures its distance from the origin (0, 0) in the complex plane. Mathematically, if $z = a + bi$, where $a$ is the real part and $b$ is the imaginary part, then the modulus(a.k.a. magnitude) $z$ is given by $sqrt(a^2 + b^2)$. **If there exists a value in the orbit whose distance from the origin exceeds 2, then the orbit will eventually escape to infinity.** modulus of $z$: $\sqrt{3^2 + 4^2} = \sqrt{9 + 16} = \sqrt{25} = 5$ |
| $f_{c}(z) = z^2 + c$ | $(x^2 - y^2) + (2xy)i + (c_re + c_imi)$ | in the complex plane, `x` is the real axis, therefore the real component of `z`, and `y` is the imaginary axis, the imaginary component of `z`. To calculate `zx`, I will extract the first part of the formula: `fractal->zx_new = zx * zx - zy * zy + fractal->cx;`, and for `zy`: `fractal->zy_new = 2 * zx * zy + fractal->cy;` |
| modulus of $z = sqrt(a^2 + b^2) > 2$ | `zx * zx + zy * zy > 4.0` | I don't need to calculate the square root of $(a^2 + b^2)$ as any number bigger than $4$ will have the square root bigger than $2$, as $\sqrt{4} = 2$ |
| **`xarrow`** **`yarrow`** | `c.x = (x + frac->xarrow) / frac->zoom * (0.47 + 2.0) / (WIDTH - 1) - 2.0;` | position horizontally `xarrow` and vertically `yarrow` relative to the pixel coordinates `x` `y`. These values are necessary for moving the drawing in the screen through the key hooks |
| **`Mandelbrot boundary`** | $x = (-2.0, 0.47)$ $y = (-1.12, 1.12)$ | These are the coordinates of the outer boundary of the mandelbrot set. I can use it as value to establish its size in relation to the screen <img width="462" alt="Screenshot 2023-08-01 at 9 01 23 PM" src="https://github.com/shinckel/fract-ol/assets/115558344/00e56d57-ed79-40c4-adf2-4b4403ced309"> |
| **`smooth colors`** | $iter + 1 - log(log(sqrt(zx * zx + zy * zy))) / log(2)$ | escape time (how long does it take, a.k.a. number of iterations, before going to infinity?), **color algorithms**: the "bands" are generated because we can only set colors to pixels in discrete numbers of iterations, therefore the colors are divided as solid areas. The outermost solid color is the one out of the bailout radius. References: [Plotting algorithms - Wikipedia](https://en.wikipedia.org/wiki/Plotting_algorithms_for_the_Mandelbrot_set), [Renormalizing the Mandelbrot Escape](http://linas.org/art-gallery/escape/escape.html), [Mandelbrot Set Coloring Presentation](https://www.youtube.com/watch?v=r5rDs_qINMg), [Draw a Mandelbrot set fractal with smoothly shaded colors in C#](http://www.csharphelper.com/howtos/howto_mandelbrot_smooth.html#google_vignette) |
| [42 docs](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html) | `BitShifting` `void my_mlx_pixel_put(t_data *data, int x, int y, int color)` | In my opinion, these are two concepts really important for this project. The first, how RGB [colors](https://harm-smits.github.io/42docs/libs/minilibx/colors.html) can be encoded in int format, the second, [pushing images to a window](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#pushing-images-to-a-window) instead of drawing pixel per pixel |
| **`Julia set`** | $f_{c}(z) = z^2 + c$ | It is deeply connected to the Mandelbrot set, the same formula a.k.a patterns that emerge from the Mandelbrot map. Key concept: instead of the complex number $c$ being related to the pixel you are iterating in the complex plane, it will be just a constant. If there is no imaginary part, the set will be symmetrical. [Summary](https://www.cantorsparadise.com/the-julia-set-e03c29bed3d0), [different types](http://paulbourke.net/fractals/juliaset/) |
| **`hooks`** | TAB = `65289` `XK_Tab` | [key codes](https://docs.oracle.com/cd/E67482_01/oscar/pdf/45/OnlineHelp_45/helpOnPS2keyCodes.html). For an improved version, I could use Keysyms instead. They are defined in two standard include files: `<X11/keysym.h>` and `<X11/keysymdef.h>` |
| **`color pallette`** | `rgb1 = ((int)(mu * 25) % 256) << 16;` | I could have more control of my `get_color()` results throught the establishment of a prior pallette. In my current implementation, I am multiplying my smooth value by a factor that produces variations in RGB values, and then normalizing it to the needed range (256 possible values in R, G and B). I could be much more efficient, see the example below in C++: |
```c
private Color GetColor(double mu)
        {
            int clr1 = (int)mu;
            double t2 = mu - clr1;
            double t1 = 1 - t2;
            clr1 = clr1 % Colors.Count;
            int clr2 = (clr1 + 1) % Colors.Count;

            byte r = (byte)(Colors[clr1].R * t1 + Colors[clr2].R * t2);
            byte g = (byte)(Colors[clr1].G * t1 + Colors[clr2].G * t2);
            byte b = (byte)(Colors[clr1].B * t1 + Colors[clr2].B * t2);

            return Color.FromArgb(255, r, g, b);
        }
```

## Some of my results
<img width="720" alt="Screenshot 2023-08-01 at 9 02 19 PM" src="https://github.com/shinckel/fract-ol/assets/115558344/95fd79cb-250e-4e9c-ba16-e4c55313c0be">
<img width="720" alt="Screenshot 2023-08-01 at 9 02 42 PM" src="https://github.com/shinckel/fract-ol/assets/115558344/8f24e898-c47c-4da4-88cc-6c0ec63dc868">
<img width="717" alt="Screenshot 2023-08-01 at 9 03 16 PM" src="https://github.com/shinckel/fract-ol/assets/115558344/e1470d14-0a30-4687-abb2-cc0df154a8b9">
<img width="720" alt="Screenshot 2023-08-01 at 9 04 09 PM" src="https://github.com/shinckel/fract-ol/assets/115558344/dbcf5609-cd0e-4b80-ac78-d7f2b4aad94f">
<img width="720" alt="Screenshot 2023-08-01 at 9 04 27 PM" src="https://github.com/shinckel/fract-ol/assets/115558344/18fa9604-eb6a-45fe-9764-57780aea5ce7">
<img width="719" alt="Screenshot 2023-08-01 at 9 05 04 PM" src="https://github.com/shinckel/fract-ol/assets/115558344/68fc2e9e-8d00-4b19-8658-eec732edc755">
<img width="720" alt="Screenshot 2023-08-01 at 9 05 36 PM" src="https://github.com/shinckel/fract-ol/assets/115558344/a8991435-989d-4927-9690-8b42482b2c6c">
<img width="720" alt="Screenshot 2023-08-01 at 9 06 09 PM" src="https://github.com/shinckel/fract-ol/assets/115558344/e875cb24-4090-4699-9391-dd98f21787bc">
<img width="718" alt="Screenshot 2023-08-01 at 9 06 33 PM" src="https://github.com/shinckel/fract-ol/assets/115558344/b4597b9b-a930-40ba-8ece-4e97415b3d0a">
<img width="720" alt="Screenshot 2023-08-01 at 9 06 52 PM" src="https://github.com/shinckel/fract-ol/assets/115558344/729b7073-60fe-45aa-859f-89891c0ef3be">
