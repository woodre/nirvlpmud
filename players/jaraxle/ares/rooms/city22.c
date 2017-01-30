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

YEL+"##"+NORM+HIB+"A"+NORM+BOLD+"+---"+NORM+YEL+"#"+NORM+"\n"+

YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"W"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+"  You arrive at a dingy cul-de-sac at the end\n"+

BOLD+"---+"+NORM+YEL+"##"+NORM+BOLD+"+-"+NORM+"  of Emperor's Way. To the west is a small bar\n"+

YEL+"#"+NORM+HIB+"a"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"B"+NORM+HIR+"x"+NORM+YEL+"#"+NORM+"  with a sign hanging crookedly over its door.\n"+

YEL+"#"+NORM+HIB+"I"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  A few abandoned houses surround it and collect\n"+ 

YEL+"#"+NORM+BOLD+"--+---"+NORM+YEL+"#"+NORM+"  the trash of the city in their dalapidated\n"+

YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  hulks. The road continues back to the north.\n");

   add_item(

      "road",

      "A narrow road that leads down towards an intersection");

   add_item(

      "intersection",

      "The intersection of Emperor's Way and Manastream road. It appears to not be\n"+

      "very busy");

   add_item(

      "houses",

      "A few broken down houses used by rats and the homeless");

   add_item(

      "bar",

      "A small dingey bar that lies down a short alley and faces out to\n"+

      "the north. The front door is surrounded by trash and there are\n"+

      "no apparent windows");

   add_item(

      "door",

      "A thick oak door that has seen much abuse");

   add_item(

      "trash",

      "Rotting food and broken pieces of glass and wood");

   add_item(

      "sign",

      "The sign reads, 'The Dangerous Blade'");

      

   add_exit(ROOMS+"city21","north"); 

   add_exit(ROOMS+"bar1","bar"); 

   }



init(){

 ::init();

 add_action("get_key", "key");

 add_action("woo", "bar");

 }



woo(){ 

 write("\n\nYou travel down the short alley to the west and enter the bar...\n\n");

 return;

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

