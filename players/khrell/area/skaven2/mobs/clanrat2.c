#include "/players/khrell/define.h"
#include <ansi.h>

inherit "/players/vertebraker/closed/std/monster.c";

reset(arg) {
object gold;
  ::reset(arg);
  if(arg) return;
  set_name("clanrat");
  set_alias("clanrat");
  set_short("Clanrat of Clan Moulder");
  set_long(
"  The clanrats of the clan Moulder are slightly more healthy then\n"+
"the others of Fester Blight.  \n"+
"their cities.  They are often equipped for battle even when not\n"+
"at war.\n");
  set_gender("male");
  set_race("skaven");
  set_level(19);
move_object(clone_object("/players/khrell/area/skaven2/obj/sword.c"));
init_command("wield sword");  
  set_wc(28);
move_object(clone_object("/players/khrell/area/skaven2/obj/clanrshield.c"));
init_command("wear shield");  
  set_ac(18);
  set_hp(460);
  set_al(-1000);
  set_aggro(0, 0, 0);
  add_money(random(2000) + 1000);  

  set_chat_chance(10);
load_chat("The clanrat looks nervously about.\n");
load_chat("The clanrat twitches its whiskers.\n");

  set_a_chat_chance(10);
load_a_chat("The clanrat bares its fangs and squirts the musk of fear.\n");

  set_multi_cast(0);
  
add_spell("sword thrust",
"The #MN# impales you on his sword with a quick stab!\n",
"The #MN# impales #MN# on his sword with a quick stab!\n",
25,50,"physical");
}

init() {
::init();
  add_action("stop_move","north");
  add_action("stop_move","south");
  add_action("stop_move","west");
  add_action("stop_move","east");
  add_action("stop_move","enter");
  add_action("stop_move","up");
  add_action("stop_move","down");
  
  }

stop_move() {
  if(this_player()->is_npc()) return 0;
  if(this_player()->query_ghost()) return 0;
  write("The clanrat stabs you painfully with his sword!\n");
  if(!query_attack()) attack_object(this_player());
  this_player()->hit_player(50);
  return 1; }
