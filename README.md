<h1 align="center">
	fract-ol
</h1>

<h2 align="center">
	<img src="https://github.com/dxe58709/dxe58709/blob/main/42_badges/fract-ole.png" alt="42 fractol" />
</h2>

## Summary
> <i> One of the first graphical projects at 42 school, fract-ol generates beautiful fractals from the complex numbers of an iterative mathematical construct.
> A fractal is a fragmented geometrical figure that infinitely repeats itself at smaller scales.
> This project uses the school's graphical library, MiniLibX.</i>

## Getting started
First, clone this repository and `cd` into it:

```zsh
#!/bin/zsh
git clone https://github.com/dxe58709/fract-ol; cd fract-ol
```

Compile using `make`:
```
#!/bin/zsh
make
```

## Usage
---

Note that this project was tested on Linux only. It may run on MacOS with small adjustments to the Makefile, as described in hsmits and jvan-sni's [42 Docs](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html).

---

## Executing Fract-ol

At execution time, you must specify a fractal to display. You may also provide other optional parameters:
```zsh
#!/bin/zsh
./fractol <type> <options>
```

Types are :
* ```mandelbrot```: Mandelbrot fractal
* ```julia```: Julia fractal

For the Julia fractal set (and only this set), two additional parameters can be specified as calculation values. 
These represent a complex number that will change the shape of the Julia fractal.
They must be fractional numbers between 2.0 and -2.0. For example:

```shell
#!/bin/zsh
./fractol julia 0.285 -0.01
```
### mandelbrot
<h2 align="center">
<img width="600" alt="dxe59709_fractol" src="https://github.com/dxe58709/fractol/assets/133973097/e4b716ec-4eb7-43c0-a023-508d184df062">
</h2>
