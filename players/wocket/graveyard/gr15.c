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
"   The path leads on.  Grass begins to fill the void as it narrows\n"+
"until dirt gives way to stone.  Even then, the undead looking grass\n"+
"seems to meander it's way around.  Graves have become sparser in this\n"+
"section of the graveyard and the clouds seem to be breaking.\n";

items = ({
  "clouds","They are dark grey and cast strange shadows on the ground",
  "path","It is a narrow path that leads through the graveyard",
  "grass","It is of a dull green color making it look almost undead",
 "graves","They are sparce but their presence is still strong",
  "stone","It makes up the new path to the west",
});
dest_dir = ({
    PATH+"gr16.c","west",
    PATH+"gr14.c","northeast",
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
