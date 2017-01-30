#include "/players/dreamspeakr/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

     set_name("carmen");
     set_alias("carmen");
     set_alt_name("carmen");
     set_race("sex goddess");
     set_gender("female");
     set_short(RED+"Carmen"+NORM+", The Goddess of Birthdays");
     set_long(
         "\n"+
         "    Dressed in nothing but spiked high heel shoes, she \n"+
         "stands before you.  Covered in cake she almost looks eatable.\n"+
         "She sings happy birthday to those who are near and dear to \n"+
         "our hearts.\n");

     set_level(40);
     set_hp(2800);
     set_al(10000);
     set_ac(40);
     set_wc(50);
     set_chat_chance(30);
       load_chat(RED+"Carmen sings"+NORM+":  Happy birthday to you!\n");
       load_chat(RED+"Carmen sings"+NORM+":  Happy birthday to Chelios!\n"); 
       load_chat(RED+"Carmen"+NORM+" spanks Chelios!\n");
}
