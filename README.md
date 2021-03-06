# :dragon_face: java2cpp

FLEX &amp; BISON Java to C++ translator.

> :warning: **Warning:** java2cpp is still under development and constant changes.
> 
> :eyes: Full 50+ pages documentation available in 🇪🇸**Spanish**:mexico: [here.](https://github.com/martinezlucas98/java2cpp/blob/04903688d741634bf9f98a4f56cdbcde8a5dc74c/Documentacion%20java2cpp%20-%20Lucas%20Martinez%20y%20Joaquin%20Caballero.pdf)
> <br/><br/>

# Documentation

## Quick Start

Simply pipe your input file into the translator executable `a.out` :

```bash
./a.out < YOUR_PATH_TO_FILE/FILE.java
```

## Compiling Lex And Yacc

Make sure you've installed flex and bison on your system.

If you choose to modify the lex `java2cpp.l` or yacc `java2cpp.y` files, you would need to step through the following commands in the terminal to update your file changes.

First you should run:

```bash
lex java2cpp.l
```

Second:

```bash
yacc java2cpp.y
```

Third and last:

```bash
cc y.tab.c -ly -ll
```

Then you can run java2cpp as stated on the [quick start section.](https://github.com/martinezlucas98/java2cpp/blob/main/README.md#quick-start)

# Contributing

You are more than welcome to help java2cpp become more robust by adding new features, fixing bugs, improving the documentations, and a lot more.

All you need to do is fork this repo and begin coding! :tada:

Please read the [contributing guide](https://github.com/martinezlucas98/java2cpp/blob/7deaf1ec1d95bb6df4a303eae44b620190cfb075/CONTRIBUTING.md) to learn about our contributing rules and standards.
