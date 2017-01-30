#include "/players/khrell/define.h"
#include <ansi.h>

inherit "/players/vertebraker/closed/std/monster.c";

reset(arg) {
object gold;
  ::reset(arg);
  if(arg) return;
  set_name("clanrat");
  set_alias("clanrat");
  set_short("Clanrat");
  set_long(
"The clanrats of skavendom are the rank and file soldiers of the\n"+
"Underempire.  It is they that make up the vast population of\n"+
"their cities.  They are often equipped for battle even when not\n"+
"at war.\n");
  set_gender("male");
  set_race("skaven");
  set_level(19);
move_object(clone_object("/players/khrell/weapons/skaven/clanrspear.c"));
init_command("wield spear");  
  set_wc(28);
move_object(clone_object("/players/khrell/armors/skaven/clanrshield.c"));
init_command("wear shield");  
  set_ac(16);
  set_hp(450);
  set_al(-1000);
  set_aggro(0, 0, 0);
  add_money(3000);  

  set_chat_chance(10);
load_chat("The clanrat looks nervously about.\n");
load_chat("The clanrat twitches its whiskers.\n");

  set_a_chat_chance(10);
load_a_chat("The clanrat bares its fangs and squirts the musk of fear.\n");

  set_multi_cast(0);
  
add_spell("spear thrust",
"The #MN# impales you on his spear with a quick thrust!\n",
"The #MN# impales his foe on his spear with a quick thrust!\n",
25,30,"physical");
}

init() {
::init();
  add_action("stop_move","north");
  add_action("stop_move","south");
  add_action("stop_move","west");
  add_action("stop_move","east");
  add_action("stop_move","enter");
  
  }

stop_move() {
  if(this_player()->is_npc()) return 0;
  if(this_player()->query_ghost()) return 0;
  write("The clanrat stabs you painfully with his spear!\n");
  if(!query_attack()) attack_object(this_player());
  this_player()->hit_player(50);
  return 1; }
