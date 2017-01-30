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
"  This dwarf is grim and surly looking with an even worse disposition.\n"+
"His features are haggard and forlorn.  He glares at you with heavy lidded\n"+
"eyes from within his well bearded face.\n");
  set_gender("male");
  set_race("dwarf");
  set_level(20);
move_object(clone_object("/players/khrell/closed/dwarf/obj/dwaxe.c"));
init_command("wield axe");
  set_wc(37);
move_object(clone_object("/players/khrell/closed/dwarf/obj/dwhelm1.c"));
init_command("wear helm");
move_object(clone_object("/players/khrell/closed/dwarf/obj/dwchain.c"));
init_command("wear chain");
move_object(clone_object("/players/khrell/closed/dwarf/obj/dwshield.c"));
init_command("wear shield"); 
move_object(clone_object("/players/khrell/closed/dwarf/obj/dwchboots.c"));
init_command("wear boots"); 
  set_ac(30);
  set_hp(600);
  set_al(1000);
  set_aggressive(0);

set_chat_chance(10);
load_chat("The dwarf runs his thumb over his axe blade.\n");
load_chat("The dwarf glares at you.\n");
load_chat("The dwarf grumbles in your general direction.\n");
load_chat("You catch the dwarf reaching for your coins.\n");

set_a_chat_chance(10);
load_a_chat("The dwarf headbutts you in the groin!!\n");

set_multi_cast(0);

add_spell("axe chop",
"The dwarf $HR$hacks$N$ and $R$cleaves$N$ into you!"\n,
"#MN# $HR$hacks$N$ and $R$chops$N$ into #TN#!"\n,
25,({28,28}),({"physical","physical"}),1);

add_spell("shield block",
"You are smashed fully in the face by a shield!"\n,
"#TN# is smashed in the face by a skillful shield bash by #MN#."\n,
40,(65, ("physical"));

gold = clone_object("obj/money");
gold->set_money(random(2000) + 2000);
move_object(gold,this_object());
}