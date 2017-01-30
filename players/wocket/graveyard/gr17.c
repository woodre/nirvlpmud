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
"   The path leads up to the stairs of a small temple. Marble\n"+
"pillars stand alongside the steps, acting as a gate to the\n"+
"building covered in ivy.  The fence, lining the walkway, continues\n"+
"to glow and lightning begins to strike in the sky.\n";
items = ({
  "clouds","They are dark grey and cast strange shadows on the ground",
  "pillars","They stand tall along the steps and are intricately decorated",
  "temple","Its a small temple covered in ivy",
  "fence","It glows a "+BLU+"strange dark blue"+NORM+" as it prevents things from entering of leaving",
  "lighting","It streaks across they sky",
  "stairs","They are white marble slabs that lead into the temple",
  "ivy","The ivy covers the giant pillars interweaving with itself creating wonderful\npatterns",
  "path","The stone blocks of the path lead up to the marble stairs of the temple",
});


dest_dir = ({
    PATH+"gr16.c","north",
    PATH+"temple.c","enter",
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
