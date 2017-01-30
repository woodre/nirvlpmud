inherit "obj/armor";
#include "/players/jareel/ansi.h"
#define USER environment(this_object())

reset() {
  set_name("Elite Shield");
  set_alias("shield");

set_short(RED+"["+BOLD+YEL+"Yelmalian"+NORM+RED+"]"+BOLD+YEL+" Elite Shield"+NORM);
  set_long(
"This shield is very well crafted the golden glow reflects\n"+
"the surounding light.  The Armor seems to glow with solar\n"+
"power.\n");
  set_ac(2);
  set_light(2);
  set_type("shield");
  set_weight(1);
  set_value(1200);
}

short(){
string heh;
heh = ""+RED+"["+BOLD+YEL+"";
if(environment()){
if(environment()->is_player()) heh += environment()->query_name()+NORM+RED+"] "+BOLD+YEL+"Elite Shield"+NORM+" ";
else heh += "Yelmalian"+NORM+RED+"]"+NORM+BOLD+YEL+" Elite Shield"+NORM;
}
else heh += "Yelmalian"+NORM+RED+"]"+NORM+BOLD+YEL+" Elite Shield"+NORM;
if(worn) heh += " (worn)";
return heh;
}
