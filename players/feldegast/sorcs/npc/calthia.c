#include "/players/wocket/closed/ansi.h"
#include "../defs.h"

inherit TEACHER;

reset(arg){
  ::reset(arg);
  if(arg) return;
  set_short(HIY+"Calthia the Rainbow Mage"+NORM);
  set_name("calthia");
  set_long(
"Calthia is a stunningly beautiful woman.  Her hair seems spun of gold, her\n\
eyes like deep pools of water, and her skin as fair as fresh milk.  She wears\n\
a silky garment that emphasizes and clings to her every curve.  It is a tribute\n\
to her mastery of the School of Illusion that she is over a century old.  You\n\
may 'ask' her for assistance in your studies.\n");
  set_level(30);
  set_hp(500);
  set_wc(50);
  set_ac(60);

  add_spell("light","light",5000,5);
  add_spell("blur field","blur_field",10000,15);
  add_spell("darkness","darkness",20000,15);
  add_spell("dazzle","dazzle",30000,20);
  add_spell("invisibility","invisibility",40000,20);
  add_spell("mirror image","mirror_image",200000,25);
  add_spell("prismatic lights","prismatic_lights",250000,30);

}

