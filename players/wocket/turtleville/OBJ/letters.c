#include "/players/wocket/closed/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
  if(arg) return;
set_id("letters");
set_short("A bundle of letters");
set_long("This is a bundle of letters.  Big ones, small ones, white\n"+
  "ones, and red ones.  Many are addresed to turtillian citizens.\n"+
  "Stamps rest in the lower right hand corners.\n");
set_value(500+random(500));
set_read("You shouldn't read other peoples mail.\n");
set_weight(1);
}
