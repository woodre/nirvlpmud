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
"   The path continues on leading to the north and curving southwestardly.\n"+
"Its narrowness is increased as invading grass threatens its very existence.\n"+
"The hills and graves upon them, lend themselves easily to the impending\n"+
"sense of dread that befalls the area.\n";
items = ({
  "clouds","They are dark grey and cast strange shadows on the ground",
  "grass","It is a dull green, looking almost undead",
  "graves","These stone markers lay memorance to the passing dryants",
  "tombstones","They reach to the sky like fingers from a hand",
  "path","It becomes narrower to the southwest as it leads through the graveyard",
  "hills","They are gently rolling hills covered with graves",
});

dest_dir = ({
    PATH+"gr11.c","north",
    PATH+"gr13.c","east",
    PATH+"gr15.c","southwest",
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
