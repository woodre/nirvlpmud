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
long_desc= ""+
"   Tombstones surround you like a giant hand reaching through the\n"+
"earth to grab you.  They push through the dull grass that covers\n"+
"the ground as the grave markers reach for the clouded sky.  To the\n"+
"north and west a narrow dirt path can faintly be seen through\n"+
"a moderate downpour.\n";
items = ({
    "clouds","They are dark grey and cast strange shadows on the ground",
    "grass","It is a dull green, looking almost undead",
    "hills","Soft rolling hills covered with graves",
    "path","Its a narrow path that leads through the graveyard",
    "tombstones","Grey stones surround you like giant hands",
    "markers","They mark the resting place of passed dryants",
  "sky","It is dark and clouded over",
  "ground","It is covered with a dull colored grass and many tombstones",
});

dest_dir = ({
    PATH+"gr2.c","north",
    PATH+"gr4.c","west",
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
