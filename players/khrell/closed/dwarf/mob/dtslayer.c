#include "/players/khrell/define.h"
#include <ansi.h>

inherit "/players/vertebraker/closed/std/monster.c";

reset(arg) {
object gold;
  ::reset(arg);
  if(arg) return;
  set_name("Dwarf Troll-Slayer");
  set_alt_name("slayer");
  set_alias("dwarf");
  set_short("A Dwarf Troll-Slayer");
  set_long(
"  The dwarfs of the slayer cult are grim surly and ill tempered as a\n"+
"a dwarf can be.  Some past slight or event gave them the overwhelming\n"+
"stain of dishonor, and to atone for their 'sins' they symbolically will\n"+
"shave their head leaving only a strip of hair left in the middle.  This\n"+
"hair will be spiked to stand erect.  Also they are driven to seek death\n"+
"will seek out larger and larger monsters to attempt to kill or if they\n"+
"die then they have their honor restored.\n");
  set_gender("male");
  set_race("dwarf");
  set_level(18);
move_object(clone_object("/players/khrell/closed/dwarf/obj/dwgraxe.c"));
init_command("wield axe");
  set_wc(40);
  set_ac(20);
  set_hp(700);
  set_al(500);
  set_aggressive(0);

set_chat_chance(10);
load_chat("The dwarf runs his thumb over his axe blade.\n");
load_chat("The dwarf glares at you.\n");
load_chat("The dwarf grumbles and looks for trouble.\n");
load_chat("You catch the dwarf sizing you up.\n");

set_a_chat_chance(10);
load_a_chat("The dwarf headbutts you in the groin!!\n");

set_multi_cast(0);

add_spell("axe chop",
"The dwarf $HR$hacks$N$ and $R$cleaves$N$ into you!"\n,
"#MN# $HR$hacks$N$ and $R$chops$N$ into #TN#!"\n,
25,({28,28}),({"physical","physical"}),1);

add_spell("head chop",
"You are smashed in the head by a large brutal axe!"\n,
"#TN# is smashed in the head by a large brutal axe by #MN#."\n,
40,(75, ("physical"));

add_spell("groin butt",
"The dwarf throws his head forward,\n"+
"~~~~~he butts you in the groin once~~~~\n"+
"   ~~~~~~~then butts you again~~~~~~\n"+
"~~~~~~and finally drives his thick head in again for one last massive butt!\n",
"#TN# is smashed in the groin by a massive headbutt, not once, not twice, but thrice!"\n,
100,({30,30,40}),({"physical","physical","physical"}));


init() {
::init();
  add_action("stop_move","north");
  add_action("stop_move","south");
  add_action("stop_move","west");
  add_action("stop_move","east");
  }

stop_move() {
  if(this_player()->is_npc()) return 0;
  if(this_player()->query_ghost()) return 0;
  write("The troll-slayer blocks you with his axe!\n");
  if(!query_attack()) attack_object(this_player());
  this_player()->hit_player(50);
  return 1; }