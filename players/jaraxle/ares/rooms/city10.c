#include "../define.h"

inherit ROOM;



reset(arg) {



  if(!present("citizen", this_object())){

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

YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  [Main Street] & [Celestial Avenue]\n"+

YEL+"##"+NORM+HIB+"A"+NORM+BOLD+"+---"+NORM+YEL+"#"+NORM+"\n"+

YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"W"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+"  You arrive at a T in the road. To the west\n"+

BOLD+"---"+HIR+"x"+NORM+YEL+"##"+NORM+BOLD+"+-"+NORM+"  is the road leading to the Temple district\n"+

YEL+"#"+NORM+HIB+"a"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"B"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+"  of New Ares with Large Spires and Towers \n"+

YEL+"#"+NORM+HIB+"I"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  rising high over the walls of that protected\n"+

YEL+"#"+NORM+BOLD+"--+---"+NORM+YEL+"#"+NORM+"  area. Main street continues to the north and\n"+

YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  south.\n");



   add_item(

      "road",

      "A clean narrow road that leads up to the gates of the Temple District");

   add_item(

      "spires",

      "Tall towers that reach for dominance of the sky over the tall walls of\n"+

      "the temple district");

   add_item(

      "towers",

      "Tall towers that reach for dominance of the sky over the tall walls of\n"+

      "the temple district");

   add_item(

      "walls",

      "The walls are made of a white stone and stand high over the houses that\n"+

      "are nearby");

   add_item(

      "street",

      "A wide well used street that cuts through the center of town");

   add_item(

      "gates", 

      "Steel gates that are blessed with the power of the gods and able to\n"+

      "withstand almost any attack");

   add_exit(ROOMS+"city14","north"); 

   add_exit(ROOMS+"city11","west"); 

   add_exit(ROOMS+"city9","south"); 

   move_object(clone_object("/players/fred/tcity/statue.c"), this_object());

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

