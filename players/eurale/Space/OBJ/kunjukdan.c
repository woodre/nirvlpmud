#include "/players/eurale/closed/ansi.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("kunjukdan");
set_alias("polearm");
set_short(YEL+"Kun"+GRN+"jukdan"+NORM);
set_long(
  "This 9 foot long polearm has a wicked blade on the end.  The \n"+
  "blade is made from a large bone and hand shaped and sharpened\n"+
  "to inflict maximum damage.  The polished bamboo shaft eases\n"+
  "the weight that a weapon of this length would carry.  There is\n"+
  "a wrapped leather section to provide a better gripping surface\n"+
  "and a large hand guard to protect the user against injury while\n"+
  "parrying a blade or sword.\n");

set_type("polearm");  /*  sword/knife/club/axe/bow/polearm  */
set_class(18);
set_weight(3);
set_value(900);
set_hit_func(this_object());
}

wear() {
  int wear;
  wear = 2*hits/15;
  return wear; }

weapon_hit(attacker){
if(random(13) > 8) {
  say(
  BOLD+"The Kunjukdan is swung fiercely at its foe....\n"+NORM);

  write(
  "\n"+HIR+
  "You SWING the Kunjukdan VICIOUSLY at your opponent..\n\n"+NORM);
  return 5; }
return;
}
