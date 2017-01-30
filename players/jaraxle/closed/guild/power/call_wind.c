#include "/players/jaraxle/closed/guild/sdefine.h"
#include "/players/jaraxle/ansi.h"
object earthment, windment;
main(string str, object gob, object player)
{
   earthment = present("earth_element", ENV);
   windment = present("wind_element", ENV);
   
   if(USER->query_ghost()) return 0;
   
   /*
   if(GOB->query_earth_element() <= 0){ write("You do not know how to call earth.\n"); return 1; }
   */
   if(windment){ write(HIC+"Winds"+NORM+" are already whipping through the area.\n"); return 1; }
   tell_room(environment(USER),
      capitalize(NAME)+" raises "+UP+" hands to the sky and lets out an ear piercing whistle.\n"+
      HIC+"\tWinds"+NORM+" rush into the room, whipping around the land.\n", ({ USER }));
   write("You raise your hands to the sky and whistle.\n");
   write(HIC+"\tWinds"+NORM+" rush into the room, whipping around the land.\n");
   write(CYN+"\t\t["+HIW+"You bring wind into the room"+NORM+CYN+"]\n"+NORM);
   move_object(clone_object("/players/jaraxle/closed/guild/elements/wind.c"),environment(USER));
   
   if(earthment){
      tell_room(environment(USER), "The "+HIC+"winds"+NORM+" punish the "+YEL+"earth"+NORM+", making things once chaotic level again.\n");
      
      destruct(earthment);
      return 1; }
   return 1; }
