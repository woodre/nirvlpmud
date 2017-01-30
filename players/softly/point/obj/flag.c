#include "/players/softly/closed/ansi.h"
inherit "obj/treasure.c";

reset(arg){

   set_id("flag");
   set_alias("jolly roger");
   set_short(BOLD+"Jolly Roger"+NORM);
   set_long("A ragged remnant of a black flag bearing\n\
a white skull and crossbones.\n");
   set_weight(1);
   set_value(100);
}

