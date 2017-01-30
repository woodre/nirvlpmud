#include "/players/jaraxle/define.h"
inherit "obj/monster.c";

int x;
reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name(GRN+"Goblin "+HIM+"Shaman"+NORM);
   set_alias("shaman");
   set_alt_name("goblin");
   set_race("goblin");
   set_short(GRN+"Goblin "+HIM+"Shaman"+NORM);
set_long(" A tall slender creature that holds an\n"+
         "old crooked cane.  A large crown of\n"+
         "colorful feathers is planted on its\n"+
         "head.  Various shapes of bones make\n"+
         "up a necklace which is wrapped around\n"+
         "its hairy neck.\n");
   set_level(12);
   set_hp(180);
   set_al(-1000);
   set_ac(7);
   set_aggressive(0);
   set_wc(15);
   set_dead_ob(this_object());
}

monster_died() {
   tell_room(environment(this_object()),
      "The "+GRN+"Goblin "+HIM+"Shaman"+NORM+" plops to the ground lifeless.\n");
   return 0; }


special1(){
   
   string ATT_NAME,msg;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   
   say("The Goblin Shaman raises his hands, calling down "+RED+"fire"+HIR+"-"+NORM+RED+"rain"+NORM+"!\n");
   say("\t"+RED+"`'.    `'.     `'.\n"+
      "\t   '  `'. "+HIR+"*"+NORM+RED+"  `'.  "+HIR+"*"+NORM+"\n"+
      "\t"+RED+"`'. `"+HIR+"*"+NORM+RED+"   '.     "+HIR+"*"+NORM+"\n"+
      "\t"+HIR+"   *       *\n"+NORM);
   attacker_ob->hit_player(20+random(6));
}

special2(){
   
   string ATT_NAME,msg;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   
   say(GRN+"Goblin "+HIM+"Shaman"+NORM+" strikes "+ATT_NAME+" in the chest with a\n\t"+HIY+"bolt of "+HIW+"~"+HIY+"lightning"+HIW+"~"+NORM+" from its staff.\n");
   
   attacker_ob->hit_player(14+random(6));
}

check_uni(){
   object uni;
   uni = present("unicorn",environment());
   if(uni){
      say("\tThe "+GRN+"Goblin "+HIM+"Shaman"+NORM+" notices the "+HIW+"Unicorn"+NORM+"!\n");
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
