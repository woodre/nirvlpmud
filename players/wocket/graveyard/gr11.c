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
"   The path swerves to the northeast as well as continuing to the\n"+
"south.  The clouds loom above as they cast shadows upon the ground.\n"+
"The tombstones rise like fingers upon the hills of the graveyard\n"+
"and all is strangely quiet.\n";

items = ({
  "clouds","They are dark grey and cast strange shadows on the ground",
  "path","It is very narrow and leads through the graveyard",
  "tombstones","They rise like fingers upon the hills",
  "hills","They are soft gently rolling hills covered in grass",
  "grass","Its a dull green, almost looking undead",
  "shadows","They are dark shadows from the overhead clouds.  They create\nstrange patterns on the ground",
});
dest_dir = ({
    PATH+"gr12.c","east",
    PATH+"gr14.c","south",
    PATH+"gr6.c","northwest",
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
