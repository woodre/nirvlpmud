#include "/players/softly/closed/ansi.h"
inherit "/obj/treasure";

reset(arg)  {
  if(arg) return;

   set_id("brass clasp");
   set_short("A Brass Clasp");
   set_alias("clasp");
   set_long("An ornate filigree brass clasp used to\n"+
            "anchor clothing and similar objects.\n");
   set_weight(1);
   set_value(1000);
}
