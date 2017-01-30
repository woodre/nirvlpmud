#include "/players/eurale/Chess/DEF.h"
#define DAEMON "/players/eurale/Chess/NPC/Daemon.c"
inherit "obj/monster";
object gold;
int FIGHTING;

reset(arg)  {
	::reset(arg);
if(arg) return;
FIGHTING = 0;
	
set_name("ebony knight");
set_alias("knight");
set_race("undead");
	
set_short(GRY+"Ebony Knight"+NORM);
set_long(
  "A ebony colored piece shaped like a horse's head.\n");
	
set_level(19);
set_hp(450);
set_al(-150);
move_object(clone_object("players/eurale/Chess/OBJ/sword"),TO);
init_command("wield sword");
set_wc(32);
set_ac(16);
set_heal(2,4);
set_aggressive(0);
set_gender("male");
	
set_chance(14);
set_spell_dam(19 + random(25));
	
set_spell_mess1(
	GRY+"The knight punches fiercely!\n"+NORM);
	
set_spell_mess2(
	GRY+"The knight punches you in the face!\n"+NORM);
	
gold = clone_object("obj/money");
gold->set_money(2100 + random(1500));
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
              GRY+"The Ebony Knight attacks its enemy!\n"+NORM);
            attack_object(ob);
          }
        }
      }
      ob = next;
    }
  }
}
