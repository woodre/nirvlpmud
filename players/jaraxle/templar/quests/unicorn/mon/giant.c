#include "/players/jaraxle/define.h"
inherit "obj/monster.c";

int x;
reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name(GRN+"Goblin "+RED+"Giant"+NORM);
   set_alias("giant");
   set_alt_name("goblin");
   set_race("goblin");
   set_short(GRN+"Goblin "+RED+"Giant"+NORM);
set_long("  A huge, dark green tinted creature with red\n"+
         "beady eyes, enormous hands and gigantic feet.\n");
   set_level(12);
   set_hp(225);
   set_al(-1000);
   set_ac(10);
   set_aggressive(0);
   set_wc(15);
   set_dead_ob(this_object());
}

monster_died() {
   tell_room(environment(this_object()),
      "The "+GRN+"Goblin "+RED+"Giant"+NORM+" crashes to the ground lifeless.\n");
   return 0; }


special1(){
   
   string ATT_NAME,msg;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   
say(GRN+"Goblin "+RED+"Giant"+NORM+" smashes "+ATT_NAME+" with a pair of huge fists.\n");
   
attacker_ob->hit_player(10+random(6));
}

special2(){
   
   string ATT_NAME,msg;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   
say(GRN+"Goblin "+RED+"Giant"+NORM+" drops a huge foot on "+ATT_NAME+"'s chest!\n");
   
attacker_ob->hit_player(14+random(6));
}

check_uni(){
   object uni;
   uni = present("unicorn",environment());
   if(uni){
say("\tThe "+GRN+"Goblin "+RED+"Giant"+NORM+" notices the "+HIW+"Unicorn"+NORM+"!\n");
      switch(random(4)){
case 0: say("The "+GRN+"Goblin"+RED+" Giant"+NORM+" pounds on the "+HIW+"Unicorn"+NORM+" with massive fists.\n");
         break;
case 1: say("The "+GRN+"Goblin"+RED+" Giant"+NORM+" kicks the "+HIW+"Unicorn"+NORM+" in the ribs.\n");
         break;
case 2: say("The "+GRN+"Goblin"+RED+" Giant"+NORM+" punches the "+HIW+"Unicorn"+NORM+" on the head.\n");
         break;
case 3: say("The "+GRN+"Goblin"+RED+" Giant"+NORM+" squeezes the "+HIW+"Unicorn"+NORM+" by the neck.\n");
        break;
      }
uni->hit_player(10+random(10));
   }
}

heart_beat(){
   int i;
   ::heart_beat();
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
