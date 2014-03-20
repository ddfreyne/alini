/*
 * test.c
 *
 * Copyright (c) 2003-2009 Denis Defreyne
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include <stdio.h>

#include "alini.h"

/*
 * This is an example of how to use alini. Basically: 
 * 1. create parser
 * 2. set the 'found key/value pair' callback
 * 3. start the parser
 * 4. dispose the parser
 */

static void staticserverconfig_alini_callback_foundkvpair(alini_parser_t *parser, char *section, char *key, char *value)
{
	printf("[%10s] %20s => %s\n", section, key, value);
}

int main(int argc, char *argv[])
{
	alini_parser_t *parser;

	/* check number of arguments */
	if(2 != argc)
	{
		printf("usage: %s [path]\n", argv[0]);
		return 1;
	}
	
	/* create parser */
	if(-1 == alini_parser_create(&parser, argv[1]))
	{
		printf("Couldn't create parser! Is the file '%s' readable?\n", argv[1]);
		return 2;
	}
	
	/* set 'found key/value pair' callback */
	alini_parser_setcallback_foundkvpair(parser, &staticserverconfig_alini_callback_foundkvpair);
	
	/* start parser */
	alini_parser_start(parser);
	
	/* dispose parser */
	alini_parser_dispose(parser);
	parser = NULL;
	
	return 0;
}
