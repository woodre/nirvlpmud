#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/tvroom.c";

reset(arg){
  if(arg) return;
short_desc = HIY+"CyberNinja Balcony"+NORM;
long_desc = "   "+
"There are many plush seats here for viewing the activities \n"+
"below.  A railing lines the edge to keep spectators back. The\n"+
"carpet is red and very thick.  Below one can see the entire\n"+
"arena mat along with the judges.  Banners hang above as awards\n"+
"to past heros.  The view is one of the best.\n";
items = ({
"seats","They are carved from wood and have plush cushions",
"railing","It is made from a dark wood and is well crafted",
"carpet","It is very thick and red",
"below","You see the CyberNinja area mat",
"banners","Large banners hang overhead as tribute to past heros",
"judges","They sit and watch the match",
"view","It is an excellent view for watching an arena battle",
}); 
smells = ({
"default","You smell blood and sweat from below",
});
listens = ({
"default","You hear cheering and betting from below",
});

dest_dir = ({
"/players/wocket/closed/cyber/a_entrance.c","leave",
});
set_light(1);
}

init(){
  ::init();
add_action("yell","yell");
add_action("newlook","l");
add_action("newlook","look");
}

newlook(str){
if(str != "at arena") return 0;
write(HIY+"CyberNinja Arena"+NORM+" [e,w,leave]\n");
write("   "+
"This is the CyberNinja Arena.  A large white mat lines\n"+
"the floor leading to the east and west.  Red lines mark\n"+
"boundries upon the mat.  Beyond that, pads for the kneeling\n"+
"judges lay.  Above are balcony sitting for those that wish\n"+
"to spectate the events.  Two short red lines mark the center\n"+
"of the mat.\n"+
"    There are three obvious exits: east, west, and leave\n");
write(HIR+"East of the arena:\n"+NORM);
write_inventory("/players/wocket/closed/cyber/newarenac.c");
write(HIR+"Center of the arena:\n"+NORM);
write_inventory("/players/wocket/closed/cyber/newarena.c");
write(HIR+"West of the arena:\n"+NORM);
write_inventory("/players/wocket/closed/cyber/newarenab.c");
return 1;
}

write_inventory(str){
object ob,next;
ob = first_inventory(str);
while(ob){
next = next_inventory(ob);
write("  "+ob->short()+".\n");
ob = next;
}
}
yell(str){
if(!str){
    notify_fail("What would you like to yell?\n");
    return 0;
}
 write(HIY+"You yell to the arena: "+NORM+str+"\n");
 say(HIY+this_player()->query_name()+" yells to the arena: "+NORM+str+"\n");
 tell_room("/players/wocket/closed/cyber/newarena.c",HIY+this_player()->query_name()+" yells from the balcony: "+NORM+str+"\n");
 tell_room("/players/wocket/closed/cyber/newarenab.c",HIY+this_player()->query_name()+" yells from the balcony: "+NORM+str+"\n");
 tell_room("/players/wocket/closed/cyber/newarenac.c",HIY+this_player()->query_name()+" yells from the balcony: "+NORM+str+"\n");
return 1;
}
