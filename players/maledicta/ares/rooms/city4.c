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
YEL+"########"+NORM+"  [Eastern Hearth Street]\n"+
YEL+"##"+NORM+HIB+"A"+NORM+BOLD+"+---"+NORM+YEL+"#"+NORM+"\n"+
YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"W"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+"  You stand along Eastern Hearth street. It is  \n"+
BOLD+"---+"+NORM+YEL+"##"+NORM+BOLD+"+-"+NORM+"  made of a rough cobble and extends a little\n"+
YEL+"#"+NORM+HIB+"a"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"B"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+"  further to the east and back to the intersection\n"+
YEL+"#"+NORM+HIB+"I"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  to the west. Houses surround you to the north\n"+
YEL+"#"+NORM+BOLD+"--+-"+NORM+HIR+"x"+NORM+BOLD+"-"+NORM+YEL+"#"+NORM+"  and south.\n"+
YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"\n");

   add_item(
      "street",
      "A narrow cobble street that dead-ends just ahead");
   add_item(
      "cobble",
      "A rough stone that is cemented into the ground");
   add_item(
      "intersection",
      "A large open area with a well in its center");
   add_item(
      "well",
      "The public well of New Ares");
   add_item(
      "houses",
      "Midsized houses that belong to the middle class of New Ares");
   set_chance(12);
   add_msg("A family passes by chatting.");
   add_msg("A team of horses pulls a carriage by on the road.");
   add_msg("Several birds fly by overhead.");
   add_msg("A dog barks somewhere in the distance.");
   add_msg("The smell of food drifts in from a nearby house.");
   add_msg("A woman walks by and smiles.");
 
   add_exit(ROOMS+"city5","east"); 
   add_exit(ROOMS+"city3","west");
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
