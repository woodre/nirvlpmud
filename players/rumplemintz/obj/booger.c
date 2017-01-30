/* Flickable booger - Rumplemintz
 */

#include <ansi.h>

inherit "/obj/treasure";

void reset(int arg){
    if(arg) return;
    set_id("booger");
    set_short("A booger");
    set_long("It's a really nasty booger, wonder who picked it.\n"+
      "Maybe you could 'flick' it on someone and get it off your finger.\n");
    set_weight(0);
    set_value(0);
}

void init(){
    ::init();
    add_action("flick_it", "flick");
}

int flick_it(string str){
    if(!str){
	notify_fail("Use: flick <who>\n");
	return 0;
    }
    if(!find_player(str)){
	notify_fail("Cannot find "+str+"\n");
	return 0;
    }
    move_object(this_object(), find_player(str));
    write("You just flicked a booger at "+find_player(str)->query_name()+"!\n");
    say(this_player()->query_name()+" flicked a booger at "+find_player(str)->query_name()+"!\n");
    tell_object(find_player(str), "Someone just flicked a "+GRN+"booger "+NORM+"on you!\n");
    return 1;
}
