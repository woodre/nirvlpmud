#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";
int x;

reset(arg)  {
   object gold;
   ::reset(arg);
   if(arg) return;
   set_name(YEL+"Inland Taipan"+NORM);
   set_alias("taipan");
   set_race("serpent");
   set_short(YEL+"Inland Taipan"+NORM);
   set_level(20);
   set_hp(550+random(50));
   set_al(-1500);
   set_ac(17);
   set_aggressive(0);
   set_wc_bonus(20);
   set_dead_ob(this_object());
   gold = clone_object("obj/money");
   gold->set_money(3000+random(999));                              
   move_object(gold,this_object());
   set_wander(30, 0, ({ "pass" }));
} 
long(){
   write("blah/n");
}

monster_died() {
   tell_room(environment(this_object()),
      "The Taipan flops violently then abrubtly stops moving.\n");
   return 0;
}


eat_me(){
   object blah;
   blah=present("corpse");
   if(blah) {
      move_object(blah,this_object());
      say("The Taipan begins to swallow the corpse.\n");
      say("The Taipan engulfs the corpse fully, draining all life.\n");
      destruct(blah);
   }
}


venom(){
   
   string ATT_NAME;
   if(attacker_ob && present(attacker_ob)) { ATT_NAME = attacker_ob->query_name();
      
      tell_room(environment(), "The Taipan strikes "+ATT_NAME+"!\n"+ATT_NAME+" begins to look sick.\n", ({ attacker_ob }));
      tell_object(attacker_ob,  "The Taipan strikes you!\nYou begin to feel "+GRN+"sick"+NORM+".\n");
      attacker_ob->hit_player(16+random(16));
   }
}


tail(){
   
   string ATT_NAME;
   if(attacker_ob && present(attacker_ob)) { ATT_NAME = attacker_ob->query_name();
      tell_room(environment(), "The Taipan "+RED+"slashes"+NORM+" "+ATT_NAME+" with its tail.\n", ({ attacker_ob }));
      tell_object(attacker_ob, "The Taipan "+RED+"slashes"+NORM+" you with its tail.\n");
      attacker_ob->hit_player(25+random(16));
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
      i = random(20);
      switch(i){
         
         case 0..4: tail();
         break;
         
         case 5..9: venom();
         break;
         
         case 10..15: return;
         break;
      }
   }
}
