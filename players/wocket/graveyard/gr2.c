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
"   Clouds darken with rain softly falling upon the narrow\n"+
"path that leads both east and west.  Grass gives way to\n"+
"stone markers upon the gentle hills of earthbound catacombs.\n"+
"To the north, tall mushrooms obstruct your view of further\n"+
"terrain, only to cast dark shadows upon the shallow graves.\n"
;

items = ({
    "clouds","They are dark grey and cast strange shadows on the ground",
     "path","Its a narrow path that leads through the graveyard",
    "grass","It is a dull green, looking almost undead",
    "hills","Soft rolling hills covered with graves",
    "tombstones","They look like fingers reaching for the sky",
    "mushrooms","They are giant in size and number",
    "markers","They mark the resting places of passed dryants",
    "graves","Strange shadows are cast upon the shallow graves",
    "shadows","They are cast upon the shallow grave",
  });
dest_dir = ({
    PATH+"gr1.c","east",
    PATH+"gr3.c","west",
    PATH+"gr5.c","south",
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
