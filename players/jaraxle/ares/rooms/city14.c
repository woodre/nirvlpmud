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

YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  [Main Street]\n"+

YEL+"##"+NORM+HIB+"A"+NORM+BOLD+"+---"+NORM+YEL+"#"+NORM+"\n"+

YEL+"###"+NORM+HIR+"x"+NORM+YEL+"#"+NORM+HIB+"W"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+"  You walk along the main street of New \n"+

BOLD+"---+"+NORM+YEL+"##"+NORM+BOLD+"+-"+NORM+"  Ares. Along the road are several small\n"+

YEL+"#"+NORM+HIB+"a"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"B"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+"  shops and houses. The road slopes \n"+

YEL+"#"+NORM+HIB+"I"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  upward here to the north and leads up\n"+

YEL+"#"+NORM+BOLD+"--+---"+NORM+YEL+"#"+NORM+"  to the castle gates. The road also\n"+ 

YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  continues to the south.\n");



   add_item(

      "street",

      "A wide, well used street that cuts through the center of New Ares");

   add_item(

      "road",

      "A wide, well used road that cuts through the center of New Ares");

   add_item(

      "shops",

      "Small shops made of brown stone and covered with a wooden thatch roof");

   add_item(

      "houses",

      "Several mid-sized houses that line the street");

   add_item(

      "gates",

      "The large outer gates of the Emperor's Castle");

   add_item(

      "castle",

      "The tall spired castle of the Templars. It is known as Fortress\n"+

      "Stone");

   add_exit(ROOMS+"city15","north"); 

   add_exit(ROOMS+"city10","south");

   move_object(clone_object("/players/fred/tcity/vraalen.c"), this_object());

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

