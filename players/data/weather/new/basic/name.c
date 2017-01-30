/*
 * /basic/name.c
 */

#include <libs.h>

inherit "kernel/support/name";

varargs mixed to_vis_name(mixed name, status dont_capitalize) {
  return LIB_NAME->to_vis_name(name);
}
