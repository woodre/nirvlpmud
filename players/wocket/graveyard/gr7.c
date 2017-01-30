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
"   The clouds darken the sky as the wind blows fiercely through\n"+
"the grave stricken hills.  The narrow path leads both east\n"+
"and west.  To the south tombstones line the horizon as bones\n"+
"pierce through the skin of the earth, breaking past the dull grass.\n";

items = ({
  "clouds","They are dark grey and cast strange shadows on the ground",
   "path","Its a narrow path that leads through the graveyard",
  "grass","It is a dull green, looking almost undead",
  "horizon","It is lines with tombstones",
  "tombstones","They look like fingers reaching from the ground",
  "graves","They are stone markers of dead dryants",
  "sky","It grows dark as clouds cover most of it",
  "bones","The white bones of past dryants stick out through the ground",
  "hills","They are littered with the tombstones of dead dryants",
});


dest_dir = ({
    PATH+"gr8.c","west",
    PATH+"gr6.c","east",
    PATH+"gr10.c","south",
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
