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
YEL+"########"+NORM+"  [Emperor's Way] & [Manastream Road]\n"+
YEL+"##"+NORM+HIB+"A"+NORM+BOLD+"+---"+NORM+YEL+"#"+NORM+"\n"+
YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"W"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+"  You arrive at a T in the road which connects\n"+
BOLD+"---+"+NORM+YEL+"##"+NORM+HIR+"x"+NORM+BOLD+"-"+NORM+"  Emperor's Way and Manastream road to one\n"+
YEL+"#"+NORM+HIB+"a"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"B"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+"  another. The road continues upward to the\n"+
YEL+"#"+NORM+HIB+"I"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  south and there appears to be a bar at its\n"+
YEL+"#"+NORM+BOLD+"--+---"+NORM+YEL+"#"+NORM+"  crest. A large shimmering gate stands to the\n"+
YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  east with the road rising to the north.\n");

   add_item(
      "crest",
      "The crest of the hill");
   add_item(
      "T",
      "A T in the street that connects Emperor's Way and Manastream road");
   add_item(
      "road",
      "A wide road that is made of a thick stone that is worn in many places");
   add_item(
      "gate",
      "The beautiful gate that leads into the Wizards district");
   add_item(
      "bar",
      "A small bar at the top of the hill to the south"); 
   add_exit(ROOMS+"city20","north"); 
   add_exit(ROOMS+"city22","south"); 
   add_exit(ROOMS+"city23","east");
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
