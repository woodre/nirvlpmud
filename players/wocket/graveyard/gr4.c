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
"   The path continues to the north and south.  A mild sprinkle\n"+
"falls from the darkness above onto the dull green of the grass.\n"+
"Unearthed bones and graves continue to litter the hillsides as\n"+
"giant mushrooms block any passage in the west direction.\n";

items = ({
  "clouds","They are dark grey and cast strange shadows on the ground",
  "path","Its a narrow path that leads through the graveyard",
  "bones","They are a gentle reminder of mortality",
   "graves","They litter the hillside, as they serve as reminders of mortality",
  "hills","They are littered with graves of dead dryants",
  "grass","It is a dull green, almost looking undead",
  "mushrooms","They are giant in size and number",
});


dest_dir = ({
   PATH+"gr3.c","north",
    PATH+"gr5.c","east",
    PATH+"gr6.c","south",
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
