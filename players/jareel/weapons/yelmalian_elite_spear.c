#include "/players/jareel/ansi.h"
inherit "/obj/weapon";

reset(arg){
    if(arg) return;
    ::reset(arg);
set_alt_name("elitesspear");
set_id("spear");
set_alias("elite spear");

set_short(RED+"["+BOLD+YEL+"Yelmalian"+NORM+RED+"]"+BOLD+YEL+" Elite Spear"+NORM);
set_long("This finely crafted spear was forged in the heat of the Yelmalian\n"+
"blast furnaces, that are powered with Yelmalian solar magiks.  Its\n"+
"golden glow strikes fear in chaotic hearts.\n");

set_class(17);
set_weight(2);
set_type("spear");
set_value(1100);
set_light(1);
set_hit_func(this_object());

}
 
weapon_hit(attacker){
int i;
i = random(3);
if(i==1){
write(BOLD+"The golden spear jabs deep\n"+
"\n"+
""+BOLD+YEL+BLINK+"              S U N F I R E !!!!!!\n"+
"\n"+
"                          "+NORM+" burns its victim!!"+NORM+"\n");
return 1;
}
}
short(){
string heh;
heh = ""+RED+"["+BOLD+YEL+"";
if(environment()){
if(environment()->is_player()) heh += environment()->query_name()+NORM+RED+"] "+BOLD+YEL+"Elite Spear"+NORM+" ";
else heh += "Yelmalian"+NORM+RED+"]"+NORM+BOLD+YEL+" Elite Spear"+NORM;
}
else heh += "Yelmalian"+NORM+RED+"]"+NORM+BOLD+YEL+" Elite Spear"+NORM;
if(broke) heh += " [BROKEN]";
if(wielded) heh += " (wielded)";
return heh;
}
