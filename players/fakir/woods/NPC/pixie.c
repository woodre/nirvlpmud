#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("pixie");
set_race("fairy");
set_short(WHITE+"Pixie"+OFF);
set_long(
  "Liquid blue eyes and soft yellow hair give this creature a feminine\n"+
  "look, but looks can be deceiving.  Lovers of practical jokes of all\n"+
  "kinds, these creatures are the bane of humans everywhere.\n");

move_object(clone_object("/players/fakir/woods/WEP/stick.c"),
(this_object()));
init_command("wield stick");

set_level(2);
set_hp(30);
set_al(-100);
set_wc(6);
set_ac(3);
}

