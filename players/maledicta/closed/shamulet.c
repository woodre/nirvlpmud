/*  A gift to Bardtest(legion), who has helped with
    testing the bards...a truly, truly, gay guild. */

#include "/players/maledicta/ansi.h"

#define USER environment()
#define ATT USER->query_attack()
#define ATTN ATT->query_name()

long(){ 
write(
"You wear around your neck the Symbol of Shardak.  It is made\n"+
"from an unknown red metal that glints eerily in the light. A\n"+
"power emanates from within it, and you feel its evil might.\n");
return 1;
}

query_weight(){ return 0; }
query_value(){ return 0; }

extra_look(){
if(environment())
return environment()->query_name()+" wears a "+RED+"Symbol of Shardak"+NORM+""; 
}

id(str){
return str == "symbol" ||
       str == "generic_wc_bonus";
}

drop(){ return 1; }
get(){ return 1; }

query_auto_load(){ return "/players/maledicta/closed/shamulet.c:"; }

gen_wc_bonus(){
if(!USER->query_weapon()) return 13;
if(random(100) < 30){
 tell_room(environment(USER),
 HIW+"The muscles on Legion's arms ripple with power"+NORM+BOLD+"..."+NORM+"\n"+
 HIW+"The Draconic Shadow of "+NORM+RED+"Shardak"+HIW+" encircles him with might!\n"+NORM);
 return 1;
 }
else if(random(100) < 10){
 USER->add_alignment(-300);
 tell_room(environment(USER),
 HIW+"Legion's body takes on the form of the "+NORM+RED+"Dragon"+NORM+BOLD+"..."+NORM+"\n"+
 HIW+ATTN+" is sundered by Legion's dark power!"+NORM+"\n");
 return 3;
 } 	
return 0;
}

