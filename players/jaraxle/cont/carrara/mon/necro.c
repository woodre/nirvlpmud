#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";
int x;
string my_name;
reset(arg)  {
   switch(random(4)){
      case 0: my_name = "than";
      break;
      case 1: my_name = "hectic";
      break;
      case 2: my_name = "rubick";
      break;
      case 3: my_name = "widow";
      break;
   }
   ::reset(arg);
   if(arg) return;
   
   set_name(my_name);
   set_alias("necro");
   set_alt_name("necromancer");
   set_race("necromancer");
   set_level(20);
   set_hp(500+random(50));
   set_al(-1000);
   set_aggressive(0);
   set_dead_ob(this_object());
   enable_commands();
   move_object(clone_object("/players/wocket/necro/guildob.c"),TO);
   move_object(clone_object("/players/wocket/necro/obj/wep/harvester"),TO);
   move_object(clone_object("/players/mythos/awep/katana.c"),TO);
   move_object(clone_object("/players/dusan/area1/armors/bboots.c"),TO);
   move_object(clone_object("/players/dusan/area1/armors/bnecklace.c"),TO);
   move_object(clone_object("/players/dusan/area1/armors/bring.c"),TO);
   move_object(clone_object("/players/dusan/area1/armors/vskin.c"),TO);
   move_object(clone_object("/players/dusan/area1/armors/bhelm.c"),TO);
   move_object(clone_object("/players/dusan/area1/armors/bplate.c"),TO);
   move_object(clone_object("/players/dusan/area1/armors/bshield.c"),TO);
   command("wield katana",TO);
   command("wear armor",TO);
   command("wear ring",TO);
   command("wear cloak",TO);
   command("wear boots",TO);
   command("wear ring",TO);
   command("wear amulet",TO);
   command("wear shield",TO);
   command("wear misc",TO);
   command("wear helmet",TO);
   set_wc(30);
   set_ac(17);
}
short(){ return capitalize(my_name)+", "+BOLD+"the Minister of Souls"+NORM; }
long(){
   write(capitalize(my_name)+" has a small "+BOLD+"skull"+NORM+" tattoo upon the forehead.\n");
   write("A thin person, of about 5 and one half feet in height.\n"+
      "A foul stench can be smelled suffocating the air around\n"+
      ""+capitalize(my_name)+".  A glint of a sharp dagger can be seen strapped\n"+
      "in "+capitalize(my_name)+"'s belt.\n");
}

monster_died() {
   tell_room(environment(this_object()),
      "The spirit fades to nothingness.\n");
   return 0; }


anguish(){
   
   string ATT_NAME,msg;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   
   tell_object(attacker_ob, capitalize(my_name)+" throws a glowing sphere at you.\n"+capitalize(my_name)+" crushes a vile of blood in its hand.\n");
   tell_room(environment(), capitalize(my_name)+" throws a glowing sphere at "+ATT_NAME+".\n"+capitalize(my_name)+" crushes a vile of blood in its hand.\n", ({ attacker_ob }));
   
   attacker_ob->hit_player(20+random(21));
}

kill_me(){
   
   string ATT_NAME,msg;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   
   tell_object(attacker_ob, capitalize(my_name)+" pours blood upon the ground and a red mist rises up attempting to pull you under.\n");
   tell_room(environment(), capitalize(my_name)+" pours blood upon the ground and a red mist rises up attempting to pull "+ATT_NAME+" under.\n", ({ attacker_ob }));
   attacker_ob->hit_player(25+random(7));
}

eat_me(){
   object blah;
   blah=present("corpse");
   if(blah) {
      say(capitalize(my_name)+" wields harvester.\n"+
         "With great care, "+capitalize(my_name)+" harvests an eye from the corpse.\n"+
         "With great care, "+capitalize(my_name)+" harvests a piece of skin from the corpse.\n"+
         "With great care, "+capitalize(my_name)+" harvests 5 vials of blood from the corpse.\n");
      say(capitalize(my_name)+" wields Katana.\n");
      command("harvest corpse",this_player());
      destruct(blah);
   }
}


heart_beat(){
   int i;
   ::heart_beat();
   if(!attacker_ob){
      x = random(2);
      switch(x){
         
         case 0: eat_me();
         break;
         case 1: eat_me();
      }
   }
   if(attacker_ob){
      i = random(15);
      switch(i){
         
         case 0..4: anguish();
         break;
         
         case 5..9: kill_me();
         break;
         
         case 10..14: return 0;
         break;
      }
   }
}

