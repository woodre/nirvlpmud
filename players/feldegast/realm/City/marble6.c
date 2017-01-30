/*
File: marble6.c
Author: Feldegast
Date: 11/02/98
Revised: 03/23/02
Description:
  A plaza.
*/

#include "defs.h"

inherit ROOM;

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"  Marble street, Calador's main thoroughfare, widens here to form the\n"+
"Plaza of the Merchants, a place of commerce for as long as Calador\n"+
"itself has existed.  In the center of the plaza is the large statue\n"+
"of some ancient hero.  To the south is an armour shop.  Marble street\n"+
"runs east-west while bronze street starts to the north.\n";
  items=({
    "street",   "The street itself is cobbled, and well-maintained",
    "plaza",    "reflexive",
    "statue",   "The stone statue is of a mighty hero raising his sword high, as\n"+
                "though leading a charge",
    "shop",     "On the south side of the plaza is a small armor shop made out of\n"+
                "wood and stone",
  });
  dest_dir=({
    PATH+"bronze1","north",
    PATH+"marble5","west",
    PATH+"marble7","east",
    PATH+"armshop","south"
  });
}   
