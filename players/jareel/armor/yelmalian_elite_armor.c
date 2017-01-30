inherit "obj/armor";
#include "/players/jareel/ansi.h"
reset() {
  set_name("elite armor");
  set_alias("armor");
    set_short(RED+"["+BOLD+YEL+"Yelmalian"+NORM+RED+"]"+BOLD+YEL+" Elite armor"+NORM);
  set_long(
"This armor is very well crafted the golden glow reflects\n"+
"the surounding light.  A sun has been crested in the middle\n"+
"of the chest.  The armor emits a lot of light.\n");
  set_ac(3);
  set_light(1);
  set_type("armor");
  set_weight(5);
  set_value(1500);
}
short(){
string heh;
heh = ""+RED+"["+BOLD+YEL+"";
if(environment()){
if(environment()->is_player()) heh += environment()->query_name()+NORM+RED+"] "+BOLD+YEL+"Elite Armor"+NORM+" ";
else heh += "Yelmalian"+NORM+RED+"]"+NORM+BOLD+YEL+" Elite Armor"+NORM;
}
else heh += "Yelmalian"+NORM+RED+"]"+NORM+BOLD+YEL+" Elite Armor"+NORM;
/*if(broke) heh += " [BROKEN]";
if(wielded) heh += " (wielded)";*/
if(worn) heh += " (worn)";
return heh;
}
