/*
File: copper2.c
Author: Feldegast
Date: 11/02/98
Revised: 03/23/02
Description:
  Copper street
*/

#include "defs.h"

inherit ROOM;

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="Copper Street";
  long_desc=
"    Copper street bends to the west here, but the rampant\n"+
"poverty and filth continues unabated.  An impromptu garbage\n"+
"heap sits in the middle of the street, preventing most people\n"+
"from going west unless they have pressing business.\n";
  items=({
    "garbage","You see numerous odds and ends, stuff even the most\n"+
           "desperate can't find a use for.  There's nothing\n"+
           "useful to you here",
    
    "heap","You see numerous odds and ends, stuff even the most\n"+
           "desperate can't find a use for.  There's nothing\n"+
           "useful to you here"
  });
  dest_dir=({
    PATH+"copper1","north",
    PATH+"copper3","west",
  });
}   
