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

YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  [Celestial Avenue]\n"+

YEL+"##"+NORM+HIB+"A"+NORM+BOLD+"+---"+NORM+YEL+"#"+NORM+"\n"+

YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"W"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+"  You stand on a short stretch of road that\n"+

BOLD+"--"+HIR+"x"+NORM+BOLD+"+"+NORM+YEL+"##"+NORM+BOLD+"+-"+NORM+"  extends to a gate to the west. To the east\n"+

YEL+"#"+NORM+HIB+"a"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"B"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+"  is a T in the road that connects to Main\n"+

YEL+"#"+NORM+HIB+"I"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  street. Several large houses line the road\n"+

YEL+"#"+NORM+BOLD+"--+---"+NORM+YEL+"#"+NORM+"  here, each belonging to an upper class\n"+

YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  citizen of New Ares.\n");



   add_item(

      "road",

      "Paved with flagstones, this short road extends to the gate to the west and\n"+

      "to the main road to the east");

   add_item(

      "gate",

      "A beautiful gate that leads into the Temple District");

   add_item(

      "t",

      "A T in the road that connects Main street and Celestial avenue");

   add_item(

      "street",

      "Main street is a wide road that is well used by the populace");

   add_item(

      "houses",

      "Being so close to the Temple district you see only large expensive houses");

   

   add_exit(ROOMS+"city10","east"); 

   add_exit(ROOMS+"city12","west"); 

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

