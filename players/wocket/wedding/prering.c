/* approved by Mythos - <8-12-1999> */
#include "/players/wocket/closed/ansi.h"
inherit "obj/treasure.c";

reset(arg){
    set_id("ring");
    set_short("A "+RED+"roseate"+NORM+" ring");
    set_long("This gold ring has the hint of rose as it gives off a soft glow\n"+
"from the surrounding light.  You might want to slide it upon your\n"+
    "loved ones finger as a symbol of your affection.\n");
set_light(1);
}

init(){
    add_action("new_place","slide");
}


new_place(string str){
object ring;
object love;
string arg1;
if(!str){
    notify_fail("Usage: slide ring on <person>\n");
    return 0;
}
if(sscanf(str,"ring on %s",arg1) != 1){
    notify_fail("Usage: slide ring on <person>\n");
    return 0;
}
love = find_player(arg1);
if(!love || (environment(love) != environment(this_player())) ){
    notify_fail("Usage: slide ring on <person>\n");
    return 0;
}

ring = clone_object("/players/wocket/wedding/ring.c");
ring->set_spouse(this_player()->query_real_name());
move_object(ring,love);
say(this_player()->query_name()+" places the ring upon "+love->query_name()+"'s finger.\n",love);
write("You place the ring upon "+love->query_name()+"'s finger.\n");
say("You place the ring upon "+capitalize(str)+"'s finger.\n",love);
tell_object(love,this_player()->query_name()+" places a ring upon your finger.\n");
destruct(this_object());
return 1;
}
