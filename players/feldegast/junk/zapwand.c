#include "defs.h"
inherit "obj/treasure.c";

void reset(int arg) {
  if(arg) return;
  set_id("wand");
  set_short("A lightning wand");
  set_long("To use: shazam <target>\n");
  set_weight(0);
}

void init() {
  if(TPN=="Gaston")
    add_action("shazam","shazam");
}

shazam(str) {
  object targ;
  if(!str) return 0;
  targ=find_player(str);
  targ->hit_player(1000);
  targ->hit_player(1000);
  targ->hit_player(1000);
  write("Shazam!\n");
  tell_object(targ,"Shazam!\n");
  return 1;
}
