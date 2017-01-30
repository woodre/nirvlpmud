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
"   The narrow path winds towards the south and east circling\n"+
"the hills of graves.  Bones protrude through the grass as a\n"+
"reminder of mortality.  Rain falls gently from the dark clouds\n"+
"over head.  The only protection seems to be to the west where\n"+
"giant mushrooms litter the area.  Shadows flicker in every\n"+
"direction.\n";

items = ({
  "clouds","They are dark grey and cast strange shadows on the ground",
  "path","Its a narrow path that leads through the graveyard",
  "grass","It is a dull green, looking almost undead",
  "hills","Soft rolling hills covered with graves",
  "mushrooms","They are giant in size and number",
  "bones","They are a gentle reminder of ones mortaility",
  "shadows","They flicker about the area",
   "graves","They mark the resting place of passed dryants",
});


dest_dir = ({
    PATH+"gr2.c","east",
    PATH+"gr4.c","south",
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
    add_action("mmove","move");
}

get_giant(int i){
if(!i) i = random(3);
switch(i){
case 0: move_object(clone_object("/players/wocket/graveyard/ggiant.c"),this_object()); break;
case 1: move_object(clone_object("/players/wocket/graveyard/sgiant.c"),this_object()); break;
case 2: move_object(clone_object("/players/wocket/graveyard/zgiant.c"),this_object()); break;
}
}

mmove(string str){
  if(str != "bushes"){
    notify_fail("What would you like to move?\n");
  return 0;
}
write("You search for the hidden trail but find nothing.\n");
return 1;
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
