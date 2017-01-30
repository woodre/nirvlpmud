inherit "obj/armor";
#include "/players/jareel/ansi.h"
#define USER environment(this_object())

     reset() {
       set_name("elite boots");
       set_alias("boots");
       set_short(RED+"["+BOLD+YEL+"Yelmalian"+NORM+RED+"]"+BOLD+YEL+" Elite Boots"+NORM);
       set_long(
         "This Armor is very well crafted the golden glow reflects\n"+
         "the surounding light.  The Armor seems to glow with solar\n"+
         "power.\n");
       set_ac(2);
       set_light(1);
       set_type("armor");
       set_weight(4);
       set_value(1200);
       }

     short(){
       string heh;
         heh = ""+RED+"["+BOLD+YEL+"";
           if(environment()){
           if(environment()->is_player()) heh += environment()->query_name()+NORM+RED+"] "+BOLD+YEL+"Elite Boots"+NORM+" ";
           else heh += "Yelmalian"+NORM+RED+"]"+NORM+BOLD+YEL+" Elite Boots"+NORM;
       }

       else heh += "Yelmalian"+NORM+RED+"]"+NORM+BOLD+YEL+" Elite Boots"+NORM;
       /*if(broke) heh += " [BROKEN]";
         if(wielded) heh += " (wielded)";*/
         if(worn) heh += " (worn)";
       return heh;
       }
