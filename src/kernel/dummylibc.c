/* Dummy standard C library for the benchmarks
   Copyright (C) 2018 Embecosm Limited
   Contributor: Jeremy Bennett <jeremy.bennett@embecosm.com>
   This file is part of the Bristol/Embecosm Embedded Benchmark Suite.
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
   SPDX-License-Identifier: GPL-3.0-or-later */

/* The purpose of this library is to measure the size of code excluding target
   dependent C library code. It only makes sense if it is used with
   -gc-sections. */

#include <time.h>
#include <stdio.h>
#include "helpers.h"

/* Avoid conflict with ferror defined as a macro, which is the case on some
   systems.  */
#ifdef ferror
#undef ferror
#endif

void * __locale_ctype_ptr;
int __errno;
char *_ctype_;

struct _reent *_impure_ptr;

void NORETURN abort (void) {
  while (1);
}


void * memmove (void *dest UNUSED, const void *src UNUSED, unsigned int n UNUSED ) {
  return 0;
}


int memcmp (const void *s1 UNUSED, const void *s2 UNUSED, unsigned int n UNUSED) {
  return 0;
}


int rand (void) {
  return 0;
}


void srand (unsigned int seed UNUSED ) {
}


void * calloc (unsigned int nmemb UNUSED, unsigned int size UNUSED ) {
  return 0;
}


void * malloc (unsigned int size UNUSED ) {
  return  0;
}


void free (void *ptr UNUSED ) {
}


void NORETURN __assert_func (const char *arg1 UNUSED, int arg2 UNUSED, const char *arg3 UNUSED, const char *arg4 UNUSED) {
  while (1)
    ;
}

char * strcpy (char *dest UNUSED, const char *src UNUSED ) {
  return  0;
}


char *strchr (const char *s UNUSED, int c UNUSED ) {
  return  0;
}


long int strtol (const char *nptr UNUSED, char **endptr UNUSED, int base UNUSED ) {
  return 0;
}


int strcmp (const char *s1 UNUSED, const char *s2 UNUSED ) {
  return 0;
}

int strncmp (const char *s1 UNUSED, const char *s2 UNUSED, size_t n UNUSED) {
  return 0;
}

char * strcat (char *dest UNUSED, const char *src UNUSED) {
  return 0;
}

int printf (const char *format UNUSED, ...) {
  return 0;
}

int fprintf (FILE *stream UNUSED, const char *format UNUSED, ...) {
  return 0;
}

int sprintf (char *str UNUSED, const char *format UNUSED,  ...) {
  return 0;
}

int putchar (int c UNUSED) {
  return 0;
}


int puts (const char *s UNUSED) {
  return 0;
}

clock_t clock (void) {
  return (clock_t) 0;
}

int atoi (const char *nptr UNUSED) {
  return 0;
}

double atof (const char *nptr UNUSED) {
  return 0.0;
}

FILE * fopen (const char *pathname UNUSED,
              const char *mode UNUSED) {
  return NULL;
}

int fflush (FILE *stream UNUSED) {
  return 0;
}

int ferror (FILE *stream UNUSED) {
  return 0;
}

int fileno (FILE *stream UNUSED) {
  return 0;
}

int fscanf (FILE *stream UNUSED,  const char *format UNUSED, ...) {
  return 0;
}

int sscanf (const char *str UNUSED, const char *format UNUSED, ...) {
  return 0;
}

void qsort (void *base UNUSED, size_t nmemb UNUSED, size_t size UNUSED, int (*compar)(const void *, const void *) UNUSED) {
}

int fgetc (FILE *stream UNUSED) {
  return 0;
}

int getc (FILE *stream UNUSED) {
  return 0;
}

int ungetc (int c UNUSED, FILE *stream UNUSED) {
  return 0;
}

int fputc (int ch UNUSED, FILE *stream UNUSED) {
  return 0;
}

int putc (int ch UNUSED, FILE *stream UNUSED) {
  return 0;
}

char * fgets (char *s UNUSED, int size UNUSED, FILE *stream UNUSED) {
  return NULL;
}

int fclose (FILE *stream UNUSED) {
  return 0;
}

size_t fwrite (const void *ptr UNUSED, size_t size UNUSED, size_t nmemb UNUSED, FILE *stream UNUSED) {
  return 0;
}

int fputs (const char *s UNUSED, FILE *stream UNUSED) {
  return 0;
}

size_t fread (void *ptr UNUSED, size_t size UNUSED, size_t nmemb UNUSED, FILE *stream UNUSED) {
  return 0;
}

void NORETURN exit (int status UNUSED) {
  while (1);
}

char * getenv (const char *name UNUSED) {
  return 0;
}

void * memchr (const void *s UNUSED, int c UNUSED, size_t n UNUSED) {
  return 0;
}


