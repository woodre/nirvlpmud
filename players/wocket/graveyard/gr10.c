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
"   A gentle rain falls from the dark looming clouds abve.  Graves\n"+
"cover the hills all around as enormous bones stick through their\n"+
"light covering.  A faint path can be seen to the north while passage\n"+
"to the east and south is blocked by an iron fence.\n";

items = ({
  "clouds","They are dark grey and cast strange shadows on the ground",
  "fence","It glows a "+BLU+"strange dark blue"+NORM+" as it prevents things from entering or leaving",
  "graves","They cover the area",
  "bones","They are billantly white for being buried so long",
  "shadows","They are dark and move slowly along the ground as the clouds above\nare blown by the gentle breeze",
});
  "path","A faint path can be seen in the distance",

dest_dir = ({
    PATH+"gr7.c","north",
    PATH+"gr9.c","west",
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
