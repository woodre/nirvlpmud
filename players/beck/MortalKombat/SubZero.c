inherit "/obj/monster.c";
#include "/players/beck/MortalKombat/MKWarrior.h"


reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("Sub-Zero");
   set_race("warrior");
   set_alias("sub-zero");
   set_short("Sub-Zero");
   set_long("Sub-Zero is dressed in a blue ninja suit.  \n"+
      "The actual name and origin of this warrior is unknown.\n"+
      "However based on his uniform, it is believed he belongs\n"+
      "to the Lin Kuei, a legendary clan of Chinese ninjas.\n"+
      "As his name implies, he has mastered the element of cold.\n"+
      "His deep freeze leaves an opponent at his mercy.\n"+ 
      "");
   Reset();
}


        
   
