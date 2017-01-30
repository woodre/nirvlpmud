#include "defs.h"

inherit "/obj/treasure.c";

void reset(int arg) {
  if(arg) return;
  set_id("map");
  set_alias("scroll");
  set_short("Map of Sudakan");
  set_long("The map is drawn on a sheepskin hide with a fine pen.  The notations\n"+
           "and the legend are written with a neat but not flashy scrawl.  You\n"+
           "can 'read' it.\n");
  set_weight(1);
  set_value(50);
  set_read(
"                                              ***\n"+
"                                           ---*5*---\n"+
"1. Gate Plaza                             /    |    \\\n"+
"2. Marketplace                           /     |     \\\n"+
"3. Merchant Plaza                       /      |      \\\n"+
"4. Tabernacle Square                 ***       *       ***\n"+ 
"5. Royal Plaza                       *4*------*2*------*3*\n"+
"                                     ***       *       ***\n"+
"                                        \\      |      /\n"+
"                                         \\     |     /\n"+
"                                          \\    |    /\n"+
"                                           ---*1*---\n"+
"                                              ***\n"+
"\n");
}
