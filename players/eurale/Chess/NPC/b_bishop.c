#include "/players/eurale/Chess/DEF.h"
#define DAEMON "/players/eurale/Chess/NPC/Daemon.c"
inherit "obj/monster";
object gold;
int FIGHTING;

reset(arg)  {
	::reset(arg);
if(arg) return;
FIGHTING = 0;
	
set_name("ebony bishop");
set_alias("bishop");
set_race("undead");
	
set_short(GRY+"Ebony Bishop"+NORM);
set_long(
  "A ebony piece with a pointed religious head covering.\n");
	
set_level(20);
set_hp(700);
set_al(-200);
move_object(clone_object("players/eurale/Chess/OBJ/ring"),TO);
init_command("wear ring");
set_wc(45);
set_ac(16);
set_heal(2,4);
set_aggressive(0);
set_gender("male");
	
set_chance(14);
set_spell_dam(20 + random(22));
	
set_spell_mess1(
	GRY+"The bishop pummels his oponent!\n"+NORM);
	
set_spell_mess2(
	GRY+"The bishop pummels you unmercifully!\n"+NORM);
	
gold = clone_object("obj/money");
gold->set_money(1900 + random(1500));
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
              GRY+"The Ebony Bishop attacks its enemy!\n"+NORM);
            attack_object(ob);
          }
        }
      }
      ob = next;
    }
  }
}
