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
YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"W"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+"  You have arrived at a small cul-de-sac at\n"+
BOLD+"---+"+NORM+YEL+"##"+NORM+BOLD+"+-"+NORM+"  the end of Western Hearth street. To the\n"+
YEL+"#"+NORM+HIB+"a"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"B"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+"  north is the large Inn of New Ares. The\n"+
YEL+"#"+NORM+HIB+"I"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  street extends back to the east and the\n"+
YEL+"#"+NORM+HIR+"x"+NORM+BOLD+"-+---"+NORM+YEL+"#"+NORM+"  intersection of Main and Hearth.\n"+
YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"\n");

   add_item(
      "street",
      "A narrow cobble street that extends from east to west through the city");
   add_item(
      "inn",
      "The large Inn of New Ares. It is a three story tall white stone buiding\n"+
      "with wooden shutters and a large oak door. It is reknowned for its service");
   add_item(
      "intersection",
      "The intersection of Main and Hearth streets. It is a very busy place");
   set_chance(12);
   add_msg("An elf enters the Inn of New Ares.");
   add_msg("A human enters the Inn of New Ares.");
   add_msg("An adventuring group enters the Inn.");
   add_msg("A bird chirps from its high perch on the roof of the Inn.");
   add_msg("A pleasant smell reaches you from the kitchen of the Inn.");
   add_msg("A family walks by talking and laughing.");
 
   add_exit(ROOMS+"city6","east"); 
   add_exit(ROOMS+"inn1","inn");
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
