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

YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  [East Hearth Street]\n"+

YEL+"##"+NORM+HIB+"A"+NORM+BOLD+"+---"+NORM+YEL+"#"+NORM+"\n"+

YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"W"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+"  This is the rough cobble street of Eastern \n"+

BOLD+"---+"+NORM+YEL+"##"+NORM+BOLD+"+-"+NORM+"  Hearth.  To the east are several houses of\n"+

YEL+"#"+NORM+HIB+"a"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"B"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+"  the middle class of New Ares. To the west\n"+

YEL+"#"+NORM+HIB+"I"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  is the intersection of Main and Hearth, and\n"+

YEL+"#"+NORM+BOLD+"--+"+HIR+"x"+NORM+BOLD+"--"+NORM+YEL+"#"+NORM+"  beyond is the Inn.\n"+

YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"\n");



   add_item(

      "street",

      "A rough cobble street that runs east and west through the city");

   add_item(

      "houses",

      "Mid-sized houses that belong to the middle class of New Ares. They\n"+

      "are in good condition");

   add_item(

      "intersection",

      "The busy intersection of Main and Hearth");

   add_item(

      "inn",

      "A large Inn at the western end of Hearth Street");

   set_chance(12);

   add_msg("A couple passes you on the street.");

   add_msg("A man on a horse rides by.");

   add_msg("A carriage clunks by loudly.");

   add_msg("A small child with his parents passes by.");

   add_msg("Someone yells across the street.");

   add_msg("The smell of food drifts from a nearby house.");

 

   add_exit(ROOMS+"city2","west"); 

   add_exit(ROOMS+"city4","east");

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

