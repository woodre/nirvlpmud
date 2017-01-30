#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("sprite");
set_race("fairy");
set_short(BOLD+YELLOW+"Sprite"+OFF);
set_long(
  "Clear as glass and almost without form, this fairy creature spends\n"+
  "most of its time vexing the larger fairy folk, or trying to steal\n"+
  "small bits of odd treasure from them.  They have a delicate though\n"+
  "rather evil nature, just as most in the realm of fairy.\n");

move_object(clone_object("/players/fakir/woods/WEP/needle.c"),
(this_object()));
init_command("wield needle");

set_level(1);
set_hp(15);
set_al(-100);
set_wc(5);
set_ac(3);
}

