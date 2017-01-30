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

YEL+"##"+NORM+HIB+"A"+NORM+BOLD+"+--"+NORM+HIR+"x"+NORM+YEL+"#"+NORM+"\n"+

YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"W"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+"  Here the road bends suddenly and sweeps down\n"+

BOLD+HIR+"x"+NORM+BOLD+"--+"+NORM+YEL+"##"+NORM+BOLD+"+-"+NORM+"  hill to the south.  It also continues back to\n"+

YEL+"#"+NORM+HIB+"a"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"B"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+"  the west towards Main Street. There are several\n"+

YEL+"#"+NORM+HIB+"I"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  buildings here, as well as houses. You can\n"+

YEL+"#"+NORM+BOLD+"--+---"+NORM+YEL+"#"+NORM+"  barely make out a tall wall to the east which\n"+

YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  seems to shimmer with a greenish power.\n");



   add_item(

      "road",

      "Here the Emperor's Way turns to the south or leads to the west\n"+

      "towards Main Street");

   add_item(

      "street",

      "Main street is far to the west and leads north and south through\n"+

      "the city");

   add_item(

      "buildings",

      "Several large buildings that line the streets");

   add_item(

      "houses",

      "Several small houses that line the street");

   add_item(

      "wall",

      "A tall wall that stands behind the buildings to the east. It\n"+

      "shimmers with a magical power");

   add_item(

      "power",

      "A green mana that infuses the wall with energy");

   

   add_exit(ROOMS+"city20","south");

   add_exit(ROOMS+"city18","west"); 

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

