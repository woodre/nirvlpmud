#include "/players/eurale/Chess/DEF.h"
#define DAEMON "/players/eurale/Chess/NPC/Daemon.c"
inherit "obj/monster";
object gold;
int FIGHTING;

reset(arg)  {
	::reset(arg);
if(arg) return;
FIGHTING = 0;
	
set_name("ebony pawn");
set_alias("pawn");
set_race("undead");
	
set_short(GRY+"Ebony Pawn"+NORM);
set_long(
	"A ebony chessman footsoldier of the lowest rank.\n");
	
set_level(15);
set_hp(200);
set_al(-50);
set_wc(33);
set_ac(13);
set_heal(1,2);
set_aggressive(0);
set_gender("male");
	
set_chance(12);
set_spell_dam(5 + random(16));
	
set_spell_mess1(
	GRY+"The pawn lands a crushing blow!\n"+NORM);
	
set_spell_mess2(
	GRY+"The pawn clubs you solidly!\n"+NORM);
	
gold = clone_object("obj/money");
gold->set_money(525 + random(150));
move_object(gold,TO);
}

heart_beat() {
object ob,att,next;
	::heart_beat();
	
if(!environment()) return;

/*  If attacker isn't in daemon, add them  */
if(attacker_ob){
  if(!DAEMON->check_black(attacker_ob->query_real_name())){
    DAEMON->black(attacker_ob->query_real_name());
  }
}

/*  Check for an enemy of white  */
ob = first_inventory(environment(this_object()));
if(!attacker_ob){
  while(ob) {
    next = next_inventory(environment(this_object()));
      if(living(ob) && !ob->query_npc() && !ob->query_ghost()){
        if(!attacker_ob){
          if(DAEMON->check_black(ob->query_real_name())){
            tell_room(environment(),
              GRY+"The Ebony Pawn attacks its enemy!\n"+NORM);
            attack_object(ob);
          }
        }
      }
      ob = next;
    }
  }
}
