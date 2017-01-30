#include "/players/fred/ansi.h"
inherit "/obj/armor";
object helmet;
int on;

reset(arg) {
  if(arg) return;
  set_name("goggles");          
  set_short(BOLD+BLK+"Night "+NORM+GRN+"Vision "+NORM+"goggles");
  set_long(
  "  Some nifty night vision goggles that allow you to\n"+
  "see in the dark without lighting up the entire room.\n");

  set_type("helmet");
  set_ac(1);
  set_weight(1);
  set_value(100);
}

short(){
     if(worn) {
     return BOLD+RED+environment()->query_name()+"'s "+BLK+"Night "+NORM+GRN+"Vision "+NORM+"goggles (worn)";
       }
     else {
     return BOLD+BLK+"Night "+NORM+GRN+"Vision "+NORM+"goggles"; 
    } 
   }

wear(str){
  if(!id(str)) return 0;
    if(worn) return 0; 
::wear(str);
  write("You slip on the goggles and suddenly the room is clear!\n");
  set_light(1);
  return 1; }  

remove(str){
  if(!id(str)) return 0;
    if(!worn) return 0;
 ::remove(str);
  write("You remove the goggles.\n");
  set_light(-1);
  return 1; }
