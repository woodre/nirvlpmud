#include "../define.h"
inherit ROOM;

reset(arg) {

  if(!present("civilian_mob", this_object())){
   MO(CO("/players/maledicta/ares/mobs/civilian"), this_object());
   if(random(100) < 50) MO(CO("/players/maledicta/ares/mobs/civilian"), this_object());
   }
  if(random(100) < 30){
   if(!present("townguard_mob", this_object())){
   MO(CO("/players/maledicta/ares/mobs/tguard"), this_object());
   if(random(100) < 10) MO(CO("/players/maledicta/ares/mobs/tguard"), this_object());
   }
  }
/*
  if(random(100) < 10){
   if(!present("special_mob", this_object())){
   MO(CO("/players/maledicta/ares/mobs/special_mob"), this_object());
   }
  }
*/
   if(arg) return;
   set_short(RED+"New Ares"+NORM);
   set_light(1);
   set_long(
YEL+"########"+NORM+"  [Western Hearth Street]\n"+
YEL+"##"+NORM+HIB+"A"+NORM+BOLD+"+---"+NORM+YEL+"#"+NORM+"\n"+
YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"W"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+"  The cobble street of Western Hearth extends\n"+
BOLD+"---+"+NORM+YEL+"##"+NORM+BOLD+"+-"+NORM+"  before you.  To the west is a deadend and the\n"+
YEL+"#"+NORM+HIB+"a"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"B"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+"  Inn of New Ares. To the east is the inter-\n"+
YEL+"#"+NORM+HIB+"I"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  section of Main and Hearth. \n"+
YEL+"#"+NORM+BOLD+"-"+NORM+HIR+"x"+NORM+BOLD+"+---"+NORM+YEL+"#"+NORM+"  \n"+
YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"\n");

   add_item(
      "street",
      "A narrow cobble street that extends east and west through the city");
   add_item(
      "deadend",
      "The street ends there");
   add_item(
      "inn",
      "A large Inn located near the end of the street. It is a comfortable and\n"+
      "well known place");
  
   set_chance(6);
   add_msg("A man pushing a cart creaks by you.");
   add_msg("A woman and her child cross the street.");
   add_msg("A bird flies overhead chirping.");
   add_msg("A dog barks nearby.");
   add_msg("A group of adventurers pass by on their way to the Inn.");
   add_msg("You hear some construction going on in a nearby house.");
 
   add_exit(ROOMS+"city2","east");
   add_exit(ROOMS+"city7","west");
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
