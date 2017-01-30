#define PATH "/players/wocket/graveyard/"
#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/graveyard/groom.c";

int num;
reset(arg){
int i;
if(!present("dryant 4")) {
i = random(2);
if(i == 1){
    i = random(2);
    if(i == 1) get_giant();
    get_giant();
}
}
num = random(3);
    if(arg) return;
short_desc = BLU+"A Dryant Graveyard"+NORM;
long_desc = ""+
"   The path comes to a grassy conclusion, leading only back to the\n"+
"east.  Tombstones surround the end of the path, covering here and\n"+
"the area to the south.  The graveyard appears to be closed in by a \n"+
"glowing fence of sorts.  It seems like its to keep something out\n"+
"or in.  A small crypt is set off in the corner and is covered\n"+
"with moss.\n";

items = ({
  "clouds","They are dark grey and cast strange shadows on the ground",
  "grass","It is a dull green, looking almost undead",
  "path","They ends here, leading only to the east",
  "tombstones","They surround you like fingers reaching through the ground",
  "fence","It glows a "+BLU+"strange dark blue"+NORM+" as it prevents things from entering or leaving",
  "crypt","A stone crypt covered in moss and ivy.  Perhaps you could 'enter' it",
});

dest_dir = ({
    PATH+"gr7.c","east",
    PATH+"gr9.c","south",
});

listens = ({
    "default","Strange silence fills the room",
    "wind","It wails as the breeze passes by you",
});
smells = ({
    "default","A horrible stench is coming from the ground",
});
set_light(1);
}

init(){
    ::init();
    add_action("search","search");
    add_action("enter","enter");
}

int enter(string str){
if(str != "crypt"){
    notify_fail("What would you like to enter?\n");
    return 0;
}
write("You enter the crypt.\n");
say(this_player()->query_name()+" enters the crypt.\n");
move_object(this_player(),PATH+"crypt1b.c");
say(this_player()->query_name()+" enters the crypt.\n");
command("glance",this_player());
return 1;
}
get_giant(int i){
if(!i) i = random(3);
switch(i){
case 0: move_object(clone_object("/players/wocket/graveyard/ggiant.c"),this_object()); break;
case 1: move_object(clone_object("/players/wocket/graveyard/sgiant.c"),this_object()); break;
case 2: move_object(clone_object("/players/wocket/graveyard/zgiant.c"),this_object()); break;
}
}

search(){
object mon;
if(num == 0){
    notify_fail("You find nothing of interest.\n");
    return 0;
}
num--;
write("You notice a dryant.\n");
get_giant();
return 1;
}
