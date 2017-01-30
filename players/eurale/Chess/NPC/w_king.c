#include "/players/eurale/Chess/DEF.h"
#define DAEMON "/players/eurale/Chess/NPC/Daemon.c"
inherit "obj/monster";
object gold;
int FIGHTING;

reset(arg)  {
	::reset(arg);
if(arg) return;
FIGHTING = 0;
	
set_name("platinum king");
set_alias("king");
set_race("undead");
	
set_short(HIY+"Platinum King"+NORM);
set_long(
  "The royal ruler of the platinum chess empire.\n");
	
set_level(20);
set_hp(550);
set_al(250);
move_object(clone_object("players/eurale/Chess/OBJ/tshield"),TO);
init_command("wear shield");
set_wc(37);
set_ac(17);
set_heal(3,2);
set_aggressive(0);
set_gender("male");
	
set_chance(14);
set_spell_dam(25 + random(25));
	
set_spell_mess1(
	HIY+"The king pummels his oponent!\n"+NORM);
	
set_spell_mess2(
	HIY+"The king pummels you unmercifully!\n"+NORM);
	
gold = clone_object("obj/money");
gold->set_money(3000 + random(1500));
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
              HIY+"The Platinum King attacks its enemy!\n"+NORM);
            attack_object(ob);
          }
        }
      }
      ob = next;
    }
  }

if(present("pet",environment(TO)) && (!attacker_ob)) {
  call_out("no_pet",1);
  return 1; }
}

no_pet() {
object pet;
pet = present("pet",environment(TO));
tell_room(environment(),HIY+
  "The king snarls and screams, 'I hate pets in my presence!'\n"+NORM);
TO->attack_object(pet);
return 1;
}
