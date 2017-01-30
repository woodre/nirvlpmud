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
"   The path has now become completely stone with small patches\n"+
"of the undead grass seeping through.  To the south it leads on to\n"+
"what may be a temple of some sort, while to the east it leads to the rest\n"+
"of the graveyard.  A small fence runs along both sides of the stone path\n"+
"preventing the dryants' final resting from being disturbed.\n"+
"";
items = ({
  "clouds","They are dark grey and cast strange shadows on the ground",
  "path","A stone path that leads to a temple",
  "temple","A small temple covered in ivy to the south",
  "grass","Undead looking, its color is of a dull green",
  "fence","It glows a "+BLU+"strange dark blue"+NORM+" as to prevent things from entering or leaving",
});

dest_dir = ({
    PATH+"gr15.c","east",
    PATH+"gr17.c","south",
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
