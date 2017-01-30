#include "/players/jaraxle/define.h"
inherit "obj/monster.c";

int x;
reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name(GRN+"Goblin Raider"+NORM);
   set_alias("raider");
   set_alt_name("goblin");
   set_race("goblin");
   set_short(GRN+"Goblin Raider"+NORM);
   set_long("  A short, green tinted creature with dark red\n"+
      "beady eyes.  It's teeth are rotted and pointy.\n"+
      "Small clawed hands hold a rusted sword.\n");
   set_level(12);
   set_hp(180);
   set_al(-1000);
   set_ac(7);
   set_aggressive(0);
   set_wc(16);
   set_dead_ob(this_object());
}

monster_died() {
   tell_room(environment(this_object()),
      "The "+GRN+"Goblin Raider"+NORM+" slups to the ground lifeless.\n");
   return 0; }


special1(){
   
   string ATT_NAME,msg;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   
   say(GRN+"Goblin Raider"+NORM+" charges at "+ATT_NAME+"!\n");
   
   attacker_ob->hit_player(10+random(6));
}

special2(){
   
   string ATT_NAME,msg;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   
   say(GRN+"Goblin Raider"+NORM+" slashes wildly "+ATT_NAME+"!\n");
   
   attacker_ob->hit_player(20+random(6));
}

check_uni(){
   object uni;
   uni = present("unicorn",environment());
   if(uni){
      say("\tThe "+GRN+"Goblin Raider"+NORM+" notices the "+HIW+"Unicorn"+NORM+"!\n");
      switch(random(4)){
         case 0: say("The "+GRN+"Goblin Raider "+HIR+"slashes"+NORM+" at the "+HIW+"Unicorn"+NORM+".\n");
         break;
         case 1: say("The "+GRN+"Goblin Raider"+HIR+" stabs"+NORM+" its weapon into the "+HIW+"Unicorn"+NORM+".\n");
         break;
         case 2: say("The "+GRN+"Goblin Raider"+NORM+RED+" hacks"+NORM+" into the "+YEL+"flesh"+NORM+" of the "+HIW+"Unicorn"+NORM+".\n");
         break;
         case 3: say("The "+GRN+"Goblin Raider"+NORM+BLU+" drives"+NORM+" its sword "+RED+"deep"+NORM+" into the "+HIW+"Unicorn"+NORM+".\n");
         break;
      }
      uni->hit_player(10+random(10));
   }
}

heart_beat(){
   int i, x, z;
   ::heart_beat();
   if(!attacker_ob){
      object *obs;
      obs=all_inventory(environment(this_object()));
      x = sizeof(obs);
      for(z = 0; z < x; z++){
         if(obs[z]->query_guild_name() == "Knights Templar"){
attacked_by(obs[z]);
          }
      }
   }
   
   
   if(attacker_ob){
      i = random(10);
      switch(i){
         
         case 0..1: special1();
         break;
         
         case 2: special2();
         break;
         
         case 3..5: check_uni();
         break;
         
         case 6..9: return 0;
         break;
      }
   }
}
