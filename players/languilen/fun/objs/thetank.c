#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define DTANK find_object(AREA+"intank.c")
inherit "/obj/treasure";

reset(arg){
    if(arg) return;
    set_id("tank");
    set_long("The dunk tank...\n");
    set_weight(10000);
    set_value(0);
}
short(){
    if( !testtank() ){
       short_desc = "The "+HIB+"Dunk"+HIG+" Tank"+NORM+" (empty)";
    } else {
      short_desc = "The "+HIB+"Dunk"+HIG+" Tank"+NORM+" holds: "+(string)capitalize(DTANK->query_dunkee()->query_name());
    }
    return short_desc;
}

get() { return 1; }

testtank(){
     if(!DTANK){ return 0; }
     if( DTANK->query_dunkee() ){ return 1; }
     return 0;
}
