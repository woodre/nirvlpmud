#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define TP this_player()
#define DTANK find_object(AREA+"intank.c")
inherit "/obj/treasure";

int softballs;

reset(arg){
    if(arg) return;
    softballs = 3;
    set_id("ball");
    set_alias("softball");
    set_long("It's a softball for you to throw at the dunktank target.\n"+
             "To use it simply 'throw_ball'.\n");
    set_weight(1);
}
init(){
    ::init();
    add_action("throw_ball","throw_ball");
}
short(){
    while(softballs>1){ return ("("+softballs+") softballs"); }
    return ("A softball");
}
throw_ball(){
    if(!present("tank", environment(TP))){
       notify_fail("This is for use at the dunk tank only!\n");
       return 0;
    }
    if(!DTANK || !DTANK->query_dunkee() ){
       notify_fail("There is nobody in the tank!  You don't want to waste the ball.\n");
       return 0;
    }
    say(TP->query_name()+" draws "+TP->query_possesive()+" arm back and throws the ball.\n");
    write("You draw your arm back and throw the ball.\n");
    if(random(50) > TP->query_attrib("str")+TP->query_attrib("luc")){
       write("You just missed the target.\n");
       say(TP->query_name()+" just missed the target.\n");
    } else {
       write("You hit the target!\n");
       say(TP->query_name()+" hit the target!\n");
       tell_room(environment(TP), DTANK->query_dunkee()->query_name()+" flails wildly for a moment then...\n"+HIB+
                     "         S \n"+
                     "             P \n"+
                     "                 L\n"+
                     "                     A\n"+
                     "                         S\n"+
                     "                             H"+NORM+" \n"+
                     DTANK->query_dunkee()->query_name()+" falls into the water!\n");
       emit_channel("junk", "You hear a big "+HIB+"SPLASH"+NORM+" as "+TP->query_name()+" dunks "+DTANK->query_dunkee()->query_name()+" in the "+HIR+"Fun"+HIY+"house"+HIB+" Dunk"+HIG+" Tank"+NORM+"!\n");
       tell_room(environment(TP),"The attendant hurries over and pulls "+DTANK->query_dunkee()->query_name()+" from the tank\n");
       DTANK->dunked();
    }
    while(--softballs){ return 1; } 
    destruct(this_object());
    return 1;
}

query_value() { return softballs * 5; }
