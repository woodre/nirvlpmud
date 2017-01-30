#include "/players/eurale/closed/ansi.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("kunjukdan");
set_alias("polearm");
set_short("Kunjukdan");
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

weapon_hit(attacker){
int W;
W = random(13);
if(W>9)  {
  say(
  "The Kunjukdan is swung fiercely at its foe....\n");

  write(
  "\nYou grasp the Kunjukdan with both hands....\n"+
  "Rare back and SWING it viciously at your opponent..\n\n");
  return 2;
   }
return;
}

init() {
  ::init();
  move_object(clone_object("players/eurale/Space/OBJ/kunjukdan"),
    environment(this_object()));
  destruct(this_object());
}
