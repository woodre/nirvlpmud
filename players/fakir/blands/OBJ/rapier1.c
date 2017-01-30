#include "/players/fakir/color.h"
inherit "/obj/weapon.c";
reset (arg) {
   ::reset(arg);
   if(arg) return;

   set_name("rapier");
   set_alias("sword");
   set_short(RED+"Red " +OFF+MAGENTA+ "Ajah " +OFF+RED+ "Rapier"+OFF);
   set_long(  "The blade of this rapier is "+RED+"blood red "+OFF+ "from tip to hilt, \n"+
              "and the hilt is stylized with the representation of a \n"+
              "flame on both sides; a "+WHITE+ "white teardrop " +OFF+ "with the point \n"+
              "upward. This is the symbol of Tar Valon and the Aes Sedai. \n");

   set_class(18);
   set_weight(3);
   set_value(10000);
   set_type("sword");
   set_hit_func(this_object());   
 }

weapon_hit(attacker)  {

   int W;
   W=random(20);
   if(W > 14)     {
   write("The teardrop symbols glow" +WHITE+" W H I T E  H O T "+OFF+ "and a \n\n"+

     RED+"                 R E D   F L A M E\n\n "+OFF+

         "             arcs into the heart of "+attacker->query_name()+"!!! \n\n");

      say("The teardrop symbols glow" +WHITE+" W H I T E  H O T "+OFF+ "and a \n\n"+

     RED+"                 R E D   F L A M E\n\n "+OFF+

         "             arcs into the heart of "+attacker->query_name()+"!!! \n\n");
   return 10;
                  }
   return;
                  }