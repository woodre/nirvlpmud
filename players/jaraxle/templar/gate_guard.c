#include "/players/jaraxle/ansi.h"
#define DAEMON "/players/jaraxle/templar/gdaemon.c"
#define CRIME "/players/boltar/templar/daemon/Criminal.c"
inherit "obj/monster.c";

object gold,helmet,armor,weapon;


reset(arg)  {
	::reset(arg);
	if(arg) return;
	
	set_name("guard");
	set_alt_name("townguard_gate_mob");
	set_alias("templar");
	set_race("human");
	set_short(BOLD+"Templar "+NORM+GRN+"Gate Guard"+NORM);
	set_long(
		"  This is one of the many guards who watches over the Templars\n"+
		"city. He is dressed in a full suit of white plate armor, the\n"+
		"red templar cross prominently displayed across the breastplate.\n"+
		"His face is hidden away behind a protective visor. He seems\n"+
	"ready for any attack.\n");
	set_level(20);
	set_hp(650);
	set_al(1000);
	weapon = clone_object("players/jaraxle/templar/items/pike");
	move_object(weapon, this_object());
	command("wield pike", this_object());
	armor = clone_object("players/jaraxle/templar/items/fullplate2");
	move_object(armor, this_object());
	command("wear fullplate", this_object());
	helmet = clone_object("players/jaraxle/templar/items/helmet");
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

heal_self(int i){  
  if(i < 1) return;
  hit_point += i;
  if(hit_point > max_hp) hit_point = max_hp;
  }

add_hit_point(int i){
  if(i < 1) return;
  hit_point += i;
  if(hit_point > max_hp) hit_point = max_hp;
  }

query_templar_guard(){ return 1; }

heart_beat(){
	int x;
	object ob;
	object att;
	object next;
	::heart_beat();
	if(!environment()) return;
	
	ob = first_inventory(environment(this_object()));
	
	if(query_wc() < 30) set_wc(30);
	if(query_ac() < 20) set_ac(20);
	
	if(!query_attack()){
		while(ob) {
			att = ob->query_attack();
			next = next_inventory(ob);
         if(living(ob) && !ob->query_npc() && !ob->query_ghost()){
         if(CRIME->Query(ob->query_name())){
            tell_room(environment(),
            "The guard calls out, \""+HIR+"CRIMINAL!!!"+NORM+"\"\n");
            attack_object(ob);
            } 
         }
       if(!query_attack())
			if(att && !ob->query_ghost() && (ob->query_templar_guard() || present("KnightInvite", ob))){
				tell_room(environment(),
				"The Templar Guard rushes to the attack!\n\n");
				attack_object(att);
			}
			ob = next;
		}
	}
}


monster_died(){
if(DAEMON->query_gl(1)){
   tell_room(environment(),
   HIG+"\nTemplar reinforcements arrive!"+NORM+"\n\n");
if(query_attack()){
   write_file("/players/jaraxle/templar/logs/GUARD1",
   query_attack()->query_name()+" "+ctime(time())+".\n");
   }
   move_object(clone_object("/players/jaraxle/ares/mobs/gate_guard.c"), environment());
  /* DAEMON->sub_guards(1); */
   send();
   }
}

send() {
   object list;
   object cross;
   int i;
   list = users();
   for(i=0; i<sizeof(list); i++) {
      cross = present("KnightTemplar",list[i]);
      if (cross && !cross->query_block()) {
          tell_object(list[i], 
          HIR+"(Templar War) A City Gate guard has been killed!"+NORM+"\n");
       }
   }
}
