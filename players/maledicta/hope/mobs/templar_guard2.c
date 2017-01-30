#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

object gold,helmet,armor,weapon;


reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("guard");
set_alt_name("templar_guard");
set_alias("templar");
set_race("human");
set_short(BOLD+"Templar "+NORM+GRN+"Guard"+NORM);
set_long(
"  This is one of the many guards who watches over the Templars\n"+
"castle. He is dressed in a full suit of white plate armor, the\n"+
"red templar cross prominently displayed across the breastplate.\n"+
"His face is hidden away behind a protective visor. He seems\n"+
"ready for any attack. If you have lost your cross, type: cross\n"+
"and the guard will go and get you a new one.\n"); 
set_level(20);
set_hp(650);
set_al(1000);
weapon = clone_object("players/maledicta/templar/items/pike");
move_object(weapon, this_object());
command("wield pike", this_object());
armor = clone_object("players/maledicta/templar/items/fullplate2");
move_object(armor, this_object());
command("wear fullplate", this_object());
helmet = clone_object("players/maledicta/templar/items/helmet");
move_object(helmet, this_object());
command("wear helmet", this_object());
set_wc(30);
set_ac(20);
set_aggressive(0);
set_heart_beat(1);
set_dead_ob(this_object());
set_chance(15);
set_spell_dam(20);
set_spell_mess1(
  "The Templar guard skillfully strikes out at his foe!\n");
set_spell_mess2(
  "You are slammed in the chest by the Templars heavy pike!\n");
gold = clone_object("obj/money");
gold->set_money(500);
move_object(gold,this_object());
}

init(){
	::init();
if(!present("KnightInvite", this_player())){
  add_action("block_exit","north", 1);
  add_action("block_exit","south", 1);
  add_action("block_exit","east", 1);
  add_action("block_exit","west", 1);
  add_action("block_exit","up", 1);
  add_action("block_exit","down", 1);
  }
}

query_templar_guard(){ return 1; }


heal_self(int i){
if(i < 0){
tell_room(environment(),
"The Templar Guard shrugs the attack off!\n");
return 1;
}
::heal_self(i);
return 1;
}


block_exit(){
	write("The guard steps forward and says, 'You are not invited, please leave.'\n");
    return 1;
}


heart_beat(){
int x;
object ob;
object att;
object next;
::heart_beat();		
ob = first_inventory(environment(this_object()));
if(query_wc() < 30) set_wc(30);
if(query_ac() < 20) set_ac(20);

if(query_attack() && present("fear_link", query_attack()))
  destruct(present("fear_link", query_attack()));

if(!query_attack()){
  while(ob) {
      att = ob->query_attack();
      next = next_inventory(ob);
	  if(att && ob->query_templar_guard()){
		  tell_room(environment(),
			  "The Templar Guard rushes to the attack!\n\n");
		  attack_object(att);
		       }
	  
  ob = next;      
  }
}

}

monster_died(){
write_file("/players/maledicta/hope/norm",
           "Killed by: "+attacker_ob->query_name()+" on "+ctime(time())+".\n");
return 1;
}
