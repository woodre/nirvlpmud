#include "/players/khrell/define.h"
#include <ansi.h>

inherit "/players/vertebraker/closed/std/monster.c";

reset(arg) {
object gold;
  ::reset(arg);
  if(arg) return;
  set_name("Dwarf Longbeard");
  set_alt_name("longbeard");
  set_alias("dwarf");
  set_short("A Dwarf Longbeard");
  set_long(
"  This dwarf is grim and surly looking with an even worse disposition.\n"+
"His features are haggard and grim.  Through an ornately decorated helm\n"+
"he watches for intruders.  As with all of this type, his great beard is\n"+
"well tended and long.\n");
  set_gender("male");
  set_race("dwarf");
  set_level(23);
move_object(clone_object("/players/khrell/closed/dwarf/obj/dwgraxe.c"));
init_command("wield axe");
  set_wc(36);
move_object(clone_object("/players/khrell/closed/dwarf/obj/dwhelm2.c"));
init_command("wear helm");  
move_object(clone_object("/players/khrell/closed/dwarf/obj/dwchain.c"));
init_command("wear chain");
move_object(clone_object("/players/khrell/closed/dwarf/obj/dwshield.c"));
init_command("wear shield"); 
move_object(clone_object("/players/khrell/closed/dwarf/obj/dwchboots.c"));
init_command("wear boots"); 
  set_ac(35);
  set_hp(650);
  set_al(1000);
  set_aggressive(0);

set_chat_chance(10);
load_chat("The dwarf moans and shuffles about.\n");
load_chat("The dwarf stares vacantly at you.\n");
load_chat("The dwarf groans.\n");
load_chat("You feel a chill creep up your spine.\n");

set_a_chat_chance(10);
load_a_chat("The dwarf headbutts you in the groin!!\n");

set_multi_cast(0);

add_spell("axe chop",
"The dwarf $HR$hacks$N$ and $R$cleaves$N$ into you!"\n,
"#MN# $HR$hacks$N$ and $R$cleaves$N$ into #TN#!"\n,
25,({30,30}),({"physical","physical"}),1);

add_spell("shield block",
"You are smashed fully in the face by a shield!"\n,
"#TN# is smashed in the face by a skillful shield bash by #MN#."\n,
45,(75, ("physical"));

gold = clone_object("obj/money");
gold->set_money(random(2000) + 2050);
move_object(gold,this_object());
}