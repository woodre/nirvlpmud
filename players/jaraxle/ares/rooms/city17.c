#include "../define.h"

inherit ROOM;



reset(arg) {



  if(!present("civilian_mob", this_object())){

   MO(CO("/players/jaraxle/ares/mobs/civilian"), this_object());

   if(random(100) < 50) MO(CO("/players/jaraxle/ares/mobs/civilian"), this_object());

   }

  if(random(100) < 30){

   if(!present("townguard_mob", this_object())){

   MO(CO("/players/jaraxle/ares/mobs/tguard"), this_object());

   if(random(100) < 10) MO(CO("/players/jaraxle/ares/mobs/tguard"), this_object());

   }

  }

/*

  if(random(100) < 10){

   if(!present("special_mob", this_object())){

   MO(CO("/players/jaraxle/ares/mobs/special_mob"), this_object());

   }

  }

*/

   if(arg) return;

   set_short(RED+"New Ares"+NORM);

   set_light(1);

   set_long(

YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  [Emperor's Way]\n"+

YEL+"##"+NORM+HIB+"A"+NORM+BOLD+"+"+NORM+HIR+"x"+NORM+BOLD+"--"+NORM+YEL+"#"+NORM+"\n"+

YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"W"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+"  You walk along the road known as the Emperor's\n"+

BOLD+"---+"+NORM+YEL+"##"+NORM+BOLD+"+-"+NORM+"  Way.  It is a narrow street that winds through\n"+

YEL+"#"+NORM+HIB+"a"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"B"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+"  the back and eastern side of the city. To the\n"+

YEL+"#"+NORM+HIB+"I"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  west is the armor shop and a T in the road that\n"+

YEL+"#"+NORM+BOLD+"--+---"+NORM+YEL+"#"+NORM+"  meets up with Main Street. The road also \n"+

YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  continues to the east.\n");



   add_item(

      "road",

      "A wide street known as Emperors Way");

   add_item(

      "T",

      "A T in the street that connects Main and Emperor's Way");

   add_item(

      "street",

      "A wide road that is made of a thick stone that is worn in many places");

   add_item(

      "castle",

      "The tall spired castle of the Templars of New Ares and its lands");

   add_item(

      "shop",

      "A large shop that sells armor to warriors of the lands");

 

   add_exit(ROOMS+"city18","east"); 

   add_exit(ROOMS+"city15","west"); 

   }



init(){

 ::init();

 add_action("get_key", "key");

 }



get_key(){

 write("\n\n"+HIM+"Map Key Code:"+NORM+"\n"+

       "   A "+HIM+"-"+NORM+"  Armorer\n"+

       "   B "+HIM+"-"+NORM+"  Bar\n"+

       "   I "+HIM+"-"+NORM+"  Inn\n"+

       "   W "+HIM+"-"+NORM+"  WeaponSmith\n"+

       "   a "+HIM+"-"+NORM+"  Alchemist\n"+

       "   x "+HIM+"-"+NORM+"  You!\n\n\n");

  return 1;

  }

