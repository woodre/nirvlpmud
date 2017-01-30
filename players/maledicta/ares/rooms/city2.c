/*   Bar Area-  Maledicta [01.06.01] */

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
YEL+"########"+NORM+"  Intersection [Main] & [Hearth]\n"+
YEL+"##"+NORM+HIB+"A"+NORM+BOLD+"+---"+NORM+YEL+"#"+NORM+"\n"+
YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"W"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+"  This is the intersection of Main and Hearth\n"+
BOLD+"---+"+NORM+YEL+"##"+NORM+BOLD+"+-"+NORM+"  street.  The cobble road of Hearth spreads\n"+
YEL+"#"+NORM+HIB+"a"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"B"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+"  to the east and west, with the inn standing\n"+
YEL+"#"+NORM+HIB+"I"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  at the western end. Main street slopes just\n"+
YEL+"#"+NORM+BOLD+"--"+HIR+"x"+NORM+BOLD+"---"+NORM+YEL+"#"+NORM+"  slightly down to the north. A large well\n"+
YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  surrounded by statues stands before you.\n");

   add_item(
      "street",
      "A wide street that cuts through the center of New Ares");
   add_item(
      "cobble",
      "A rough stone street that extends to the east and west");
   add_item(
      "inn",
      "The famous Inn of New Ares. It is a huge structure that is very\n"+
      "welcoming in such harsh times");
   add_item(
      "well",
"            "+YEL+" ________         \n"+
"            ||||||||||"+NORM+BOLD+"  _"+NORM+"     \n"+
"            "+YEL+"||||||||||"+NORM+BOLD+"-'      \n"+
"             |______|         \n"+
"            "+NORM+HIW+"|_|-| ' _|        \n"+
"            || _  |_ |        \n"+
"            |_|_|_|__| "+NORM+"       \n"); 
   add_item(
      "statues",
      "Several tall statues of the great Generals and Rulers of Ares");
   set_chance(12);
   add_msg("An older woman pulls water from the well.");
   add_msg("A pair of riders move past you on the road.");
   add_msg("A bird sings from atop a nearby statue.");
   add_msg("A guard walks by and smiles.");
   add_msg("An older couple walk by chatting.");
   add_msg("A young child sits and plays near the well.");
 
   add_exit(ROOMS+"city8","north"); 
   add_exit(ROOMS+"city3","east"); 
   add_exit(ROOMS+"city6","west"); 
   add_exit(ROOMS+"city1","exit"); 
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
