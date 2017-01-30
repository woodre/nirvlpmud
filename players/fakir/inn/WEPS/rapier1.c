#include "/players/fakir/color.h"
inherit "/obj/weapon.c";
reset (arg) {
   ::reset(arg);
   if(arg) return;

   set_name("rapier");
   set_alias("sword");
   set_short(YELLOW+ "Bleached Bone " +OFF+BROWN+ "Rapier"+OFF);
   set_long(  "The handle of this rapier is "+YELLOW+"human bone"+OFF+ " covered in dry skin.\n"+
              "Its blade is pure black, and enchanted with an evil forged\n"+
              "in the moulten pits of the Dark One.\n");

   set_class(18);
   set_weight(3);
   set_value(2500);
   set_type("sword");
  /* change to other|evil
   set_hit_func(this_object());   
  */
  set_params("other|evil",0,"evil_hit");
 }

evil_hit(attacker)  {

   int W;
   W=random(20);
   if(W > 15)     {
   write("The rapier strikes " +YELLOW+"|*|*|*|  B O N E  |*|*|*|"+OFF+     " and  \n\n"+

     WHITE+"                         *~* T H E  F L E S H *~* \n\n "+OFF+

         "                                      falls from "+attacker->query_name()+"!!! \n\n");

      say("The rapier strikes" +YELLOW+"|*|*|*|  B O N E  |*|*|*|"+OFF+ " and  \n\n"+

     WHITE+"                         *~* T H E   F L E S H *~*\n\n "+OFF+

         "                                       falls from "+attacker->query_name()+"!!! \n\n");
   return 7;
                  }
   return;
                  }
