#include "/players/jaraxle/define.h"
inherit "obj/monster.c";

int x;
reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name(HIW+"Unicorn"+NORM);
   set_alias("unicorn");
   set_alt_name("unicorn");
   set_race("unicorn");
   set_short(HIW+"Unicorn"+NORM);
set_long(" A beautiful and rare creature that resembles\n"+
         "a powerful white horse.  An ivory white horn\n"+
         "grows from the top of its head, almost looking\n"+
         "as two wide strands of hair have twisted together.\n"+
         "A georgous mane of white hair flows effortlessly\n"+
         "as if a constant wind were upon it.\n");
   set_level(20);
   set_hp(50+random(50));
   set_al(1500);
   set_ac(0);
   set_aggressive(0);
   set_can_kill(0);
   set_wc(0);
   set_dead_ob(this_object());
   
   
}

monster_died() {
   tell_room(environment(this_object()),
      "The "+HIW+"Unicorn"+NORM+" lets out a final breath as it lays silently to rest.\n"+
      "\t"+HIM+"["+NORM+" You have failed in your quest to free the "+HIW+"Unicorn"+NORM+"! "+HIM+"]\n"+NORM);
   return 0; }


special1(){
   say("The horn of the "+HIW+"Unicorn"+NORM+" "+HIC+"glows"+NORM+" brightly.\n");
   this_object()->heal_self(1+random(25));
}


heart_beat(){
   int i;
   ::heart_beat();
   if(attacker_ob){
      i = random(10);
      switch(i){
         
         case 0..3: special1();
         break;
         
        case 4..9: return 0;
         break;
      }
   }
}
