# sli

sli, is a Simple Lua Interpreter (...or SLI), used as a lua host application for my upcoming projects,
and also serves as an experiment in the road to learning C/C++ in the same time.

## To build (...)

You need `gcc` or any other c compiler.
open a terminal and type `gcc sli.c -o sli -Ipath/to/include -Lpath/to/lua53.dll -llua53`

U.I.: please note, that im using modified lua headers, which will be radically changes over time.
      currently not much, but it's worth a note, so i included them in the `include` dir.

## License
sli is licensed under the [MIT license](https://raw.githubusercontent.com/Aerobird98/sli/master/LICENSE.txt).