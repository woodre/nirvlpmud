inherit "/obj/treasure.c";
#include <ansi.h>

reset(){
    set_id("flesh");
    set_alias("rotting flesh");
    set_short("A small pile of "+GRN+"rotting flesh"+NORM);
    set_long("A small pile of flesh came from a fallen zombie.\n");
    set_weight(3);
    set_value(0);
    call_out("dustme",10+random(10));
}

dustme(){
    if(environment()){
	tell_object(environment(this_object()),GRN+"The flesh decays and seeps into the ground.\n"+NORM);
	tell_room(environment(this_object()),GRN+"The flesh decays and seeps into the ground.\n"+NORM);
	destruct(this_object());
    }
}
