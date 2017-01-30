#include "/players/khrell/define.h"
#include <ansi.h>

inherit "/obj/monster.c";

reset(arg) {
object gold;
  ::reset(arg);
  if(arg) return;
  set_name("A Forge Golem");
  set_alt_name("forge");
  set_alias("golem");
  set_short("A Forge Golem");
  set_long(
"  This golem is the pinnacle of dwarven craftmenship.  It resembles a large\n"+
"dwarf crafted from a single piece of metal ore.  Intricate dwarven runes \n"+
"flicker and glow on the golem's skin.\n");
  set_race("golem");
  set_level(23);
  set_wc(67);
  set_ac(30);
  set_ac_bonus(10);
  set_hp(1600);
  set_heal(50,1); 
  set_hp_bonus(1000);
  set_al(0);


set_chat_chance(10);
load_chat("The golem make a deep rumbling sound.\n");
load_chat("The golem stares.\n");
load_chat("The golem doesn't seem to notice you.\n");
load_chat("You feel as if the heat could overwhelm you.\n");
load_chat("You sweat from the heat of the golem.\n");


set_multi_cast(0);

add_spell("pound",
"The golem $HR$smashes$N$ and $R$pounds$N$ you!\n",
"#MN# $HR$smashes$N$ and $R$pounds$N$ into #TN#!\n",
25,({70,60}),({"physical","physical"}),1);

add_spell("shoulder block",
"You are smashed fully in the face by massive shoulder!\n",
"#TN# is smashed in the face by shoulder block by #MN#.\n",
40,105,"physical");

add_spell("furnace rage",
"The golem glows brightly with the power of the furnace\n"+
"then unleashes the ....\n"+
"     $HR$FFFFFF  IIIII  RRRR   EEEEE\n"+
"     FF        I    R   R  EE\n"+
"     FFFF      I    R  R   EEEE\n"+
"     FF        I    RRR    EE\n"+
"     FF        I    R  R   EE\n"+
"     FF      IIIII  R   R  EEEEE$N$\n",
10,({75,75}),({"other|fire","other|good"}),1);

gold = clone_object("obj/money");
gold->set_money(random(5000) + 6000);
move_object(gold,this_object());
}

init() {
::init();
  add_action("stop_move","south");
  }

stop_move() {
  if(this_player()->is_npc()) return 0;
  if(this_player()->query_ghost()) return 0;
  write("The Forge Golem smashes you with its fists!\n");
  if(!query_attack()) attack_object(this_player());
  this_player()->hit_player(60);
  return 1; }

monster_died() {
  tell_room(environment(this_object()),
  "The golem staggers, drops to its knees, then collapses to the ground\n\n\n"+
  "with a loud"+HIW+" C R A S H"+NORM+" !\n");
    return 0;
}
