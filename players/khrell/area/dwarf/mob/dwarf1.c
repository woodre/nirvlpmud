#include "/players/khrell/define.h"
#include <ansi.h>

inherit "/players/vertebraker/closed/std/monster.c";

reset(arg) {
object gold;
  ::reset(arg);
  if(arg) return;
  set_name("Dwarf Warrior");
  set_alt_name("warrior");
  set_alias("dwarf");
  set_short("A Dwarf Warrior");
  set_long(
"  This dwarf was once grim and surly looking with an even worse disposition.\n"+
"Now his features are haggard and forlorn.  Empty eye sockets gaze out blankly\n"+
"from within its pale and gaunt face.\n");
  set_gender("male");
  set_race("dwarf");
  set_level(20);
move_object(clone_object("/players/khrell/area/dwarf/obj/dwaxe.c"));
init_command("wield axe");
  set_wc(35);
move_object(clone_object("/players/khrell/area/dwarf/obj/dwchain.c"));
init_command("wear chain");
move_object(clone_object("/players/khrell/area/dwarf/obj/dwshield.c"));
init_command("wear shield"); 
move_object(clone_object("/players/khrell/area/dwarf/obj/dwchboots.c"));
init_command("wear boots"); 
  set_ac(25);
  set_hp(550);
  set_al(1000);
  set_aggressive(0);
  add_money(3000);

set_chat_chance(10);
load_chat("The dwarf grumbles and shuffles about.\n");
load_chat("The dwarf glares suspiciously at you.\n");
load_chat("The dwarf grumbles.\n");

set_a_chat_chance(10);
load_a_chat("The dwarf headbutts you in the groin!!\n");

gold = clone_object("obj/money");
gold->set_money(3000);
move_object(gold,this_object());
}
