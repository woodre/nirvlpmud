#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";
string my_name;
object fucked;

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   switch(random(1)){
      case 0: my_name = lower_case("/players/jaraxle/closed/names"->get_male_name());
      break;
      case 1: my_name =
      lower_case("/players/jaraxle/closed/names"->get_female_name());
      break;
   }
   
   set_name("demon");
   set_alias("possessed");
   set_alt_name(my_name);
   set_race("human");
   set_short(capitalize(my_name)+" "+BLK+BOLD+"["+CYN+"possessed"+BLK+"]"+NORM);
   set_level(18);
   set_hp(400+random(51));
   set_al(0);
   set_wc(26);
   set_ac(15);
   set_aggressive(0);
   set_chance(20);
   set_spell_dam(30+random(16));
   
   set_spell_mess1(
      "\n\nThe Mage summons a storm of "+BLK+BOLD+"ash"+NORM+" and "+RED+"brimstone"+NORM+" over the room!\n");
   set_spell_mess2(
      "\n\nThe Mage summons a storm of "+BLK+BOLD+"ash"+NORM+" and "+RED+"brimstone"+NORM+" over the room!\n"+
      HIR+"\tThe ashen storm burns your body!\n"+NORM);
   set_dead_ob(this_object());
   
}

init(){
   ::init();
   if (this_player()->is_player()) fucked = this_player();
}


monster_died() {
   tell_room(environment(this_object()), "The Fox crashes to the ground lifeless.\n");
   return 0; }

heart_beat(){
   object here, there;
   here = environment(this_object());
   there = environment(fucked);
   ::heart_beat();
   if(here != there){
      move_object(this_object(), environment(fucked)); 
   say("A zombie rushes in to the room!\n");
   }
   
}
