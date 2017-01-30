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

YEL+"##"+NORM+HIB+"A"+NORM+BOLD+"+-"+NORM+HIR+"x"+NORM+BOLD+"-"+NORM+YEL+"#"+NORM+"\n"+

YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"W"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+"  You continue along the road which is surrounded\n"+

BOLD+"---+"+NORM+YEL+"##"+NORM+BOLD+"+-"+NORM+"  by numerous houses and to the south a large\n"+

YEL+"#"+NORM+HIB+"a"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"B"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+"  weapons shop.  A sign hangs over its wooden\n"+

YEL+"#"+NORM+HIB+"I"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  door. The road continues to the east, south,\n"+

YEL+"#"+NORM+BOLD+"--+---"+NORM+YEL+"#"+NORM+"  and west towards Main Street.\n"+

YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"\n");



   add_item(

      "road",

      "This is the road known as the Emperor's Way. It cuts east and\n"+

      "west through the city. To the east it begins to curve south");

   add_item(

      "houses",

      "Several midsized houses that line the road");

   add_item(

      "shop",

      "A large shop that supplies weapons to the warriors of this realm");

   add_item(

      "sign",

      "The sign reads: The crown defender");

   add_item(

      "door",

      "A large oak door that leads into the weapons shop");

   add_item(

      "street",

      "A wide street that cuts north to south through the town");

   

   add_exit(ROOMS+"wep_store2","shop"); 

   add_exit(ROOMS+"city19","east"); 

   add_exit(ROOMS+"city17","west"); 

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

