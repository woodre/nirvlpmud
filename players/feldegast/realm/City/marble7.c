/*
File: marble7.c
Author: Feldegast
Date: 04/01/02
Description:
  Marble street.
*/

#include "defs.h"

inherit ROOM;

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"  Marble street, Calador's main thoroughfare, winds east and west\n\
through low hills covered in shops, offices, and other places of\n\
business.  The townspeople crowd the streets as they go about their\n\
daily business.  Amber street begins to the south.\n";
  items=({
    "street",     "The street itself is cobbled, and well-maintained",
    "townspeople","They hustle and bustle about on their daily business",
    "hills",      "The hills are covered in buildings, some at awkward angles to others",
    "shops",      "None of the shops appear to be of interest to you",
    "offices",    "None of the shops appear to be of interest to you",
  });
  dest_dir=({
    PATH+"marble5", "west",
    PATH+"marble8", "east",
    PATH+"amber1","south"
  });
}   
