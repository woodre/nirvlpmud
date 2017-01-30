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
"   The grass surrounding the tombstones, upon the hill, is wet\n"+
"with the falling rain.  The clouds above are dark and menacing as\n"+
"they cast shadows upon the landscape.  To the west a path can\n"+
"faintly be made out past the graves.\n"+
"";
items = ({
  "clouds","They are dark grey and cast strange shadows on the ground",
  "grass","It is a dull green, looking almost undead",
  "tombstones","They reach out like fingers from the ground",
  "graves","They serve as gentle reminders of mortality",
  "shadows","They are dark and scatter along the ground",
  "path","A path can faintly be seen in the distance.  It leads through the graveyard",
});

dest_dir = ({
    PATH+"gr11.c","west",
    PATH+"gr13.c","south",
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
