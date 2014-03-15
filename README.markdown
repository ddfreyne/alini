alini
=====

alini is a simple parser for INI files written in C.

Usage
-----

alini is generally used this way:

1. Create a parser using `alini_parser_create()`.
2. Set the callback that will be called when a key/value pair is found using
   `alini_parser_setcallback_foundkvpair()`.
3. Start the parser using `alini_parser_start()`.
4. Cleanup by disposing the parser using `alini_parser_dispose()`.

Example:

```c
alini_parser_t *parser;
alini_parser_create(&parser, "config.ini");
alini_parser_setcallback_foundkvpair(parser, &mycallback);
alini_parser_start(parser);
alini_parser_dispose(parser);
```

Where `mycallback` is defined as follows:

```c
void mycallback(alini_parser_t *parser, char *section, char *key, char *value) {
   // ...
}
```

To "step" the parser, i.e. have it parse the next key/value pair and call the
callback, use `alini_parser_step()`. Generally, this should not be necessary;
you can always use `alini_parser_start()` instead.

To stop the parsing process, use `alini_parser_halt()`. No further callbacks
will be called.

The parser should not be disposed in a callback method; it should instead be
deallocated afterwards.

Licence
-------

Copyright (c) 2003-2009 Denis Defreyne

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
