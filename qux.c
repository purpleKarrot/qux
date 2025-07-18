// Copyright 2025 Daniel Pfeifer <daniel@pfeifer-mail.de>
// This work is free. You can redistribute it and/or modify it under the
// terms of the Do What The Fuck You Want To Public License, Version 2,
// as published by Sam Hocevar. See http://www.wtfpl.net/ for more details.

#include "qux.h"

#include <stdio.h>
#include <stdlib.h>

char* qux(char const* const x, char const* const y) {
  char const* const format = "%s, %s!";
  int const len = snprintf(NULL, 0, format, x, y);
  char *str = malloc(len + 1);
  snprintf(str, len + 1, format, x, y);
  return str;
}

void qux_free(char* str) {
  free(str);
}
