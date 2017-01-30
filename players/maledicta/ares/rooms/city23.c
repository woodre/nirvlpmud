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
YEL+"########"+NORM+"  [Manastream Road]\n"+
YEL+"##"+NORM+HIB+"A"+NORM+BOLD+"+---"+NORM+YEL+"#"+NORM+"\n"+
YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"W"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+"  You stand before the huge magical gate that \n"+
BOLD+"---+"+NORM+YEL+"##"+NORM+BOLD+"+"+HIR+"x"+NORM+"  separates the city from the Mage District. A\n"+
YEL+"#"+NORM+HIB+"a"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"B"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+"  large green glowing wall rises up and surrounds\n"+
YEL+"#"+NORM+HIB+"I"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  that entire portion of the city. Tall towers \n"+
YEL+"#"+NORM+BOLD+"--+---"+NORM+YEL+"#"+NORM+"  challenge each other for dominance of the sky\n"+
YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  behind the wall. The road also leads west.\n");
   add_item(
      "gate",
      "A shimmering gate of some unknown metallic substance and magical energies.\n"+
      "It is used to separate the Mage District from the common.\n"+HIR+" It is closed"+NORM);
   add_item(
      "wall",
      "A beautiful wall made of stone and green energy. It is said to be\n"+
      "indestructible");
   add_item(
      "city",
      "The Mage District of the City of Ares");
   add_item(
      "towers",
      "Tall towers that rise up in the Mage District and contort their way\n"+
      "high into the sky");
   add_item(
      "sky",
      "The blue sky over the City of Ares");
   add_item(
      "road",
      "A narrow road that leads west or through the closed gate");
   
   add_exit(ROOMS+"city21","west"); 
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
