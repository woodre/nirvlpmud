#include "/players/eurale/Chess/DEF.h"
#define DAEMON "/players/eurale/Chess/NPC/Daemon.c"
inherit "obj/monster";
object gold;
int FIGHTING;

reset(arg)  {
	::reset(arg);
if(arg) return;
FIGHTING = 0;
	
set_name("platinum rook");
set_alias("rook");
set_race("undead");
	
set_short(HIY+"Platinum Rook"+NORM);
set_long(
  "A platinum colored, castle-shaped corner piece.\n");
	
set_level(18);
set_hp(400);
set_al(100);
set_wc(30);
set_ac(15);
set_heal(1,2);
set_aggressive(0);
set_gender("male");
	
set_chance(13);
set_spell_dam(10 + random(20));
	
set_spell_mess1(
	HIY+"The rook lands a smashing blow!\n"+NORM);
	
set_spell_mess2(
	HIY+"The rook smashes you solidly!\n"+NORM);
	
gold = clone_object("obj/money");
gold->set_money(3200 + random(400));
move_object(gold,TO);
}

heart_beat() {
object ob,att,next;
	::heart_beat();
	
if(!environment()) return;

/*  If attacker isn't in daemon, add them  */
if(attacker_ob){
  if(!DAEMON->check_white(attacker_ob->query_real_name())){
    DAEMON->white(attacker_ob->query_real_name());
  }
}

/*  Check for an enemy of white  */
ob = first_inventory(environment(this_object()));
if(!attacker_ob){
  while(ob) {
    next = next_inventory(environment(this_object()));
      if(living(ob) && !ob->query_npc() && !ob->query_ghost()){
        if(!attacker_ob){
          if(DAEMON->check_white(ob->query_real_name())){
            tell_room(environment(),
              HIY+"The Platinum Rook attacks its enemy!\n"+NORM);
            attack_object(ob);
          }
        }
      }
      ob = next;
    }
  }
}
