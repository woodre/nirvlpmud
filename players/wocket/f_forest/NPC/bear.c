#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster.c";

reset(arg){
  ::reset();
  if(arg) return;
  set_name("bear");
  set_short(YEL+"A brown bear"+OFF);
  set_level(17);
  set_wc(75);
  set_ac(5);
  set_hp(160);
}
