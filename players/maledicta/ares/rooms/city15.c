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
YEL+"########"+NORM+"  [Main Street] & [Emperor's Way]\n"+
YEL+"##"+NORM+HIB+"A"+NORM+HIR+"x"+NORM+BOLD+"---"+NORM+YEL+"#"+NORM+"\n"+
YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"W"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+"  As you walk along Main Street you come\n"+
BOLD+"---+"+NORM+YEL+"##"+NORM+BOLD+"+-"+NORM+"  to a T in the road that splits off to\n"+
YEL+"#"+NORM+HIB+"a"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"B"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+"  the east and onto Emperor's Way. An\n"+
YEL+"#"+NORM+HIB+"I"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  armory stands to the west with a sign\n"+
YEL+"#"+NORM+BOLD+"--+---"+NORM+YEL+"#"+NORM+"  over its door. The main road leads north\n"+
YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  to the castle gates and south.\n");

   add_item(
      "street",
      "A wide street that cuts through the center of New Ares and leads up to the\n"+
      "gates of the Emperor's Castle");
   add_item(
      "T",
      "A T in the street that connects Main and Emperor's Way");
   add_item(
      "road",
      "A wide road that is made of a thick stone that is worn in many places");
   add_item(
      "gates",
      "The large iron gates of the Castle's outer wall");
   add_item(
      "castle",
      "The tall spired castle of the Templars. It is known as Fortress\n"+
      "Stone");
   add_item(
      "armory",
      "A large shop that sells armor to warriors of the lands");
   add_item(
      "sign", 
      "The sign reads, "+HIM+"The Emperor's Shield"+NORM+"");
   
   /*
   add_exit(ROOMS+"city16","north"); 
   */
   add_exit(ROOMS+"city14","south"); 
   add_exit(ROOMS+"city17","east"); 
   add_exit(ROOMS+"armor_store","shop");
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
