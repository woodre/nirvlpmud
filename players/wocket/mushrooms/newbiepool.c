#include "/players/wocket/closed/ansi.h"
inherit "/obj/treasure";

reset(arg){
   if(arg) return;
    set_id("pool");
    set_short("A "+HIB+"pool"+NORM+" of crystal clear water");
    set_long("This is a magikal pool for newbies.  You might wish to 'drink' from it.\n");
}
get(){ return 0; }

init(){
    add_action("drink","drink");
}

int drink(string str){
if(!str || str != "water"){
notify_fail("What would you like to drink?\n");
return 0;
}
if(this_player()->query_level() > 5){
write("You are to experienced to drink from this pool.\n");
return 1;
}
if(this_player()->query_spell_point() < 25){
write("You dont have enought magic to drink the mystic waters.\n");
return 1;
}
write("You drink from the pond and feel better.\nThe mystic water drains some of your magical potential.\n");
this_player()->add_hit_point(random(10)+15);
this_player()->add_spell_point(-25);
say(this_player()->query_name()+" drink from the water.\n");
return 1;
}
