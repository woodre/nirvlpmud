/*
File: repshop.c
Author: Feldegast
Date: 11/02/98
Revised: 03/23/02
Description:
  A shop for repairing weapons.
*/

#include "defs.h"
inherit ROOM;

reset(arg) 
{
  if(!present("shopkeeper")) {
    move_object(clone_object(MON_PATH+"kager.c"));
  }
  if (arg) return;
  set_light(1);
  short_desc="Kager's Repair Shop";
  long_desc=
"    This somewhat messy repair shop is full of numerous\n"+
"broken or dull weapons as well as dilapidated farming\n"+
"instruments brought in by local farmers.  In the center of\n"+
"the shop is a forge and to the side is a grindstone for\n"+
"sharpening blades.  In the back are supplies of lumber\n"+
"and stock.\n";
  items=({
    "weapons","Set on tables and racks, you don't think these damaged goods\n"+
              "are worth bothering with",
    "instruments","Set on tables and racks, you don't think these damaged goods\n"+
              "are worth bothering with",
    "forge","It isn't quite a smithy, but all the tools of the trade are here"+
            "and well maintained",
    "grindstone","A huge wheel of stone with a foot pedal and braces.  It is for\n"+
                 "sharpening blades",
    "lumber","Lumber of good quality precut in commonly needed shapes",
    "stock","Long metal bars propped against the wall"
  });
  dest_dir=({
    PATH+"bronze1","west"
  });
}   
