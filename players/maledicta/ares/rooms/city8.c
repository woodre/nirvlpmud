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
YEL+"########"+NORM+"  [Main Street]\n"+
YEL+"##"+NORM+HIB+"A"+NORM+BOLD+"+---"+NORM+YEL+"#"+NORM+"\n"+
YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"W"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+"  You walk along Main street and pass several\n"+
BOLD+"---+"+NORM+YEL+"##"+NORM+BOLD+"+-"+NORM+"  small shops. The street descends slightly as\n"+
YEL+"#"+NORM+HIB+"a"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"B"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+"  it extends to the north. To the south is a  \n"+
YEL+"#"+NORM+HIB+"I"+NORM+YEL+"#"+NORM+HIR+"x"+NORM+YEL+"####"+NORM+"  large well at the intersection of Main and\n"+
YEL+"#"+NORM+BOLD+"--+---"+NORM+YEL+"#"+NORM+"  Hearth streets. Far off to the north you\n"+
YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  see the castle of the Templars.\n");

   add_item(
      "street",
      "A wide street that descends to the north");
   add_item(
      "shops",
      "Small shops that line the street, each selling simple trinkets and\n"+
      "supplies");
   add_item(
      "well",
      "A large public well to the south. It is a gathering place for many people");
   add_item(
      "intersection",
      "The intersection of Main and Hearth streets. A well is located there");
   add_item(
      "castle",
      "A large multi-towered castle that sits behind several walls on a high hill. It\n"+
      "is known as Fortress Stone");
   set_chance(12);
   add_msg("A wagon creaks down the street as it descends to the north.");
   add_msg("Several town guards walk by.");
   add_msg("A family strolls by talking and laughing.");
   add_msg("An unpleasant smell drifts out from a nearby stable.");
   add_msg("A group of adventurers pass by laughing and swearing.");
   add_msg("A dog pads by, its tongue lolled to the side and its tail wagging.");
 
   add_exit(ROOMS+"city9","north"); 
   add_exit(ROOMS+"city2","south");
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
