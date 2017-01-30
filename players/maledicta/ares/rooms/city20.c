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
YEL+"########"+NORM+"  [Emperor's Way]\n"+
YEL+"##"+NORM+HIB+"A"+NORM+BOLD+"+---"+NORM+YEL+"#"+NORM+"\n"+
YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"W"+NORM+HIR+"x"+NORM+YEL+"#"+NORM+"  The road continues in its shallow descent here\n"+
BOLD+"---+"+NORM+YEL+"##"+NORM+BOLD+"+-"+NORM+"  towards the south and continues back up to the\n"+
YEL+"#"+NORM+HIB+"a"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"B"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+"  north to a bend in the road. Several houses\n"+
YEL+"#"+NORM+HIB+"I"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  line the road and are crowded together in a \n"+
YEL+"#"+NORM+BOLD+"--+---"+NORM+YEL+"#"+NORM+"  very uncomfortable way. Directly ahead is a \n"+
YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  T in the road that meets up with another road.\n");

   add_item(
      "road",
      "This is a wide road known as Emperor's Way. It leads down the\n"+
      "hill to the south or back up to the north");
   add_item(
      "houses",
      "Several low grade houses that are crammed together along the road");
   
   add_exit(ROOMS+"city19","north"); 
   add_exit(ROOMS+"city21","south"); 
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
