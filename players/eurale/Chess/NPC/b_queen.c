#include "/players/eurale/Chess/DEF.h"
#define DAEMON "/players/eurale/Chess/NPC/Daemon.c"
inherit "obj/monster";
object gold;
int FIGHTING;

reset(arg)  {
	::reset(arg);
if(arg) return;
FIGHTING = 0;
	
set_name("ebony queen");
set_alias("queen");
set_race("undead");
	
set_short(GRY+"Ebony Queen"+NORM);
set_long(
  "The wife of the Ebony King, she is the power behind the throne.\n");
	
set_level(20);
set_hp(600);
set_al(-300);
move_object(clone_object("players/eurale/Chess/OBJ/sash"),TO);
init_command("wear sash");
set_wc(38);
set_ac(17);
set_heal(2,1);
set_aggressive(0);
set_gender("male");
	
set_chance(15);
set_spell_dam(30 + random(35));
	
set_spell_mess1(
	GRY+"The queen gouges her oponent!\n"+NORM);
	
set_spell_mess2(
	GRY+"The queen gouges you deeply!\n"+NORM);
	
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
              GRY+"The Ebony Queen attacks its enemy!\n"+NORM);
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
  "The queen screams and attacks!\n"+NORM);
TO->attack_object(pet);
return 1;
}
