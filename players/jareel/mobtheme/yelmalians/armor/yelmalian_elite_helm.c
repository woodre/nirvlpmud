inherit "obj/armor";
#include "/players/jareel/ansi.h"
#define USER environment(this_object())

reset() {
  set_name("Elite Helm");
  set_alias("helm");

set_short(RED+"["+BOLD+YEL+"Yelmalian"+NORM+RED+"]"+BOLD+YEL+" Elite Helm"+NORM);
  set_long(
"This helmet is very well crafted the golden glow reflects\n"+
"the surounding light.  The Armor seems to glow with solar\n"+
"power.\n");
  set_ac(2);
  set_light(1);
  set_type("helmet");
  set_weight(1);
  set_value(1200);
}

short(){
string heh;
heh = ""+RED+"["+BOLD+YEL+"";
if(environment()){
if(environment()->is_player()) heh += environment()->query_name()+NORM+RED+"] "+BOLD+YEL+"Elite Helm"+NORM+" ";
else heh += "Yelmalian"+NORM+RED+"]"+NORM+BOLD+YEL+" Elite Helm"+NORM;
}
else heh += "Yelmalian"+NORM+RED+"]"+NORM+BOLD+YEL+" Elite Helm"+NORM;
if(worn) heh += " (worn)";
return heh;
}
