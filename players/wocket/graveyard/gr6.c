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
"   The clouds begin to part ever so slightly allowing rays of light\n"+
"to filter through the grey sky.  Reflecting against the rain\n"+
"the sky looks afire.  The path forks to the west and southeast,\n"+
"as well as continuing north as it winds its way around the hills\n"+
"of graves.\n";
items = ({
  "clouds","They are dark grey and cast strange shadows on the ground",
  "path","Its a narrow path the winds through the graveyard",
  "graves","They look like fingers reaching from the ground",
  "hills","They are covered with stone graves",
    "sky","It is dark grey as clouds part slightly",
});


dest_dir = ({
    PATH+"gr4.c","north",
    PATH+"gr7.c","west",
    PATH+"gr11.c","southeast",
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
