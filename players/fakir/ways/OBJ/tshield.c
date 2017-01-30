#include "/players/fakir/color.h"
#define USER environment(this_object())
#define ATT USER->query_attack()
#define LIVING USER->is_living()
inherit "obj/armor";


reset(arg) {
 ::reset(arg);
set_name("shield");
set_alias("shield tears");
set_short(BOLD+BLUE+"Shield of Tears"+OFF);
set_long(
"A tear-drop shaped shield, made of crystalline vapor.\n"+
"It is transparent, and a pale blue mist swirls within.\n"+
"The lower half of the shield is circumscribed in jagged,\n"+
"serrated, tear like teeth.  He who wears this shield\n"+
"shall triumph over his enemy if his determination holds.\n"); 
set_ac(1);
set_type("shield");
set_weight(4);
set_value(2500);  
}


do_special(owner){
if(random(100) < (USER->query_attrib("wil"))/2 && ATT) {
if(ATT->is_npc())
ATT->heal_self(-(USER->query_attrib("str") / 4));
else ATT->add_hit_point(-(USER->query_attrib("str") / 4));
tell_object(USER,
"The mists within the shield cry out and a small tear breaks loose!\n"+
"     "+BOLD+RED+"....BLOOD GUSHES...."+OFF+"\n");
tell_room(environment(USER),
USER->query_name()+" invokes his shield and a small crystal tear cuts into the heart of "+ATT->query_name()+"!\n", ({USER}));
return 0;
}
return 0;
}	
	
