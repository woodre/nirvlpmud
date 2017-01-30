#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("wood troll");
set_alias("troll");
set_alt_name("hawthorn");
set_race("creature");
set_short("Hawthorn, the wood troll");
set_long(
  "This stocky, powerfully built wood troll is one of the forest's\n"+
  "inhabitants.  He tends to the needs of the forest creatures and\n"+
  "doesn't take kindly to strangers wandering in the glade.\n");

set_level(20);
  set_hp(500);
  set_al(-100);
if(!present("willow club")) {
  move_object(clone_object("players/eurale/Glade/OBJ/club.c"),
    this_object()); }
init_command("wield club");
  set_wc(30);
  set_ac(17);
  set_aggressive(1);
  set_dead_ob(this_object());

set_a_chat_chance(15);
  load_a_chat("Hawthorn jumps straight at you......\n");
  load_a_chat("The wood troll quickly retreats....\n");
  load_a_chat("'GET OUT OF MY GLADE!', screams Hawthorn\n");
  load_a_chat("You feel a sharp pain as Hawthorn strikes you...\n");

}

monster_died() {
  move_object(clone_object("players/eurale/Glade/OBJ/newt_skin.c"),
    environment(this_object()));
return 0; }
