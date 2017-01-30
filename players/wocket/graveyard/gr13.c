#define PATH "/players/wocket/graveyard/"
#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/graveyard/groom.c";

int num;
reset(arg){
int i;
    ::reset();
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
"   The graves are scattered everywhere.  To the west and south\n"+
"lies a fence blocking passage in that direction, and to\n"+
"the far west a path can faintly be made out.  There is also\n"+
"a large crypt entrance here, but it has been covered in\n"+
"overgrown ivy for a long time.\n";

items = ({
  "clouds","They are dark grey and cast strange shadows on the ground",
  "graves","They are gentle reminders of mortality",
  "fence","It glows a "+BLU+"strange dark blue"+NORM+" as it prevents things from entering of leaving",
  "crypt","It is a stone crypt covered in ivy.  Perhaps you could 'enter' it",
  "ivy","Its green vines spread like tenticles across the stone surface of the crypt",
});
dest_dir = ({
    PATH+"gr12.c","north",
    PATH+"gr14.c","west",
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

enter(string str){
if(str != "crypt"){
    notify_fail("What would you like to enter?\n");
    return 0;
}
write("You enter the crypt.\n");
say(this_player()->query_name()+" enters the crypt.\n");
move_object(this_player(),"/players/wocket/graveyard/crypt1.c");
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
