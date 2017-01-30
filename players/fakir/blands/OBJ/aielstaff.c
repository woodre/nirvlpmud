#include "/players/fakir/color.h"
inherit "/obj/weapon.c";
reset (arg) {
   ::reset(arg);
   if(arg) return;

   set_name("aielstaff");
   set_alias("staff");
   set_short(CYAN+ "An Aielman's Staff"+OFF);
   set_long("A staff cut from the "+CYAN+"Avendesora"+OFF+"\n"+
              "which in the old tounge means the \n"+
               CYAN+ "TREE of LIFE" +OFF+" \n");

   set_class(18);
   set_weight(3);
   set_value(3500);
   set_hit_func(this_object());
    }
weapon_hit(attacker)  {
   
   int S;

   S=random(15);
   if(S > 10)  {
   say("The staff bonds its life to "+this_player()->query_name()+" and \n"+
         CYAN+"       WITHERS the SOUL "+OFF+" of its foe. \n");
   write("Your staff bonds its life to yours and \n"+
         CYAN+"       WITHERS the SOUL  "+OFF+" of your foe. \n");
   return 6;
      }
   return;
      }
