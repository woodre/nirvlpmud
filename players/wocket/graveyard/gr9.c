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
"   Tombstones fill the landscape as dark clouds move in above you.\n"+
"A foul stench consumes the air as rotting flesh clings to emmerged\n"+
"bones from the ground.  A magical fence blocks exits to the west and\n"+
"south but far to the north a faint path can be seen.\n";

items = ({
  "clouds","They are dark grey and cast strange shadows on the ground",
  "tombstones","They reach like fingers through the ground",
  "bones","They are covered with rotting flesh",
  "flesh","It covers the emmerged bones",
  "grass","Its a dull green, looking almost undead",
  "fence","It glows a "+BLU+"strange dark blue"+NORM+" as it prevents things from entering or leaving",
  "path","A faint path can be made out in the distance",
});


dest_dir = ({
    PATH+"gr8.c","north",
    PATH+"gr10.c","east",
});

listens = ({
    "default","Strange silence fills the room",
    "wind","It wails as the breeze passes by you",
});
smells = ({
    "default","A horrible stench is coming from the ground",
    "stench","It is a foul stench from the rotting flesh of the dead",
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
