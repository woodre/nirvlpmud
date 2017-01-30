#include "/players/jaraxle/define.h"
inherit "obj/monster.c";

int x;
reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name(GRN+"Goblin "+YEL+"Archer"+NORM);
   set_alias("archer");
   set_alt_name("goblin");
   set_race("goblin");
   set_short(GRN+"Goblin "+YEL+"Archer"+NORM);
set_long("  A thin, dark green tinted creature with red\n"+
         "beady eyes, and large pointed ears.  It's teeth\n"+
         "are rotted within its crooked smile.  A long\n"+
         "bow rests in it's thin fingers, with a quiver\n"+
         "strapped to its chest.\n");
   set_level(12);
   set_hp(180);
   set_al(-1000);
   set_ac(4);
   set_aggressive(0);
   set_wc(18);
   set_dead_ob(this_object());
}

monster_died() {
   tell_room(environment(this_object()),
      "The "+GRN+"Goblin "+YEL+"Archer"+NORM+" slups to the ground lifeless.\n");
   return 0; }


special1(){
   
   string ATT_NAME,msg;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   
   say(GRN+"Goblin "+YEL+"Archer"+NORM+" fires a pair of arrows at "+ATT_NAME+"!\n");
   
attacker_ob->hit_player(2+random(6));
}

special2(){
   
   string ATT_NAME,msg;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   
   say(GRN+"Goblin "+YEL+"Archer"+NORM+" fires an arrow into "+ATT_NAME+"!\n");
   
attacker_ob->hit_player(6+random(2));
}

check_uni(){
   object uni;
   uni = present("unicorn",environment());
   if(uni){
say("\tThe "+GRN+"Goblin "+YEL+"Archer"+NORM+" notices the "+HIW+"Unicorn"+NORM+"!\n");
      switch(random(4)){
case 0: say("The "+GRN+"Goblin "+YEL+"Archer"+NORM+" drives an arrow into the "+HIW+"Unicorn"+NORM+"!\n");
         break;
case 1: say("The "+GRN+"Goblin "+YEL+"Archer"+NORM+" fires an arrow into the "+HIW+"Unicorn"+NORM+"!\n");
         break;
case 2: say("The "+GRN+"Goblin "+YEL+"Archer"+NORM+" shoots a "+HIR+"flaming arrow"+NORM+" into the "+HIW+"Unicorn"+NORM+"!\n");
         break;
case 3: say("The "+GRN+"Goblin "+YEL+"Archer"+NORM+" shoots a "+HIM+"poisoned arrow"+NORM+" into the "+HIW+"Unicorn"+NORM+"!\n");
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
