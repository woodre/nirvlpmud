#define PATH "/players/wocket/graveyard/"
#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/graveyard/groom.c";

int num;
reset(arg){
int i;
    ::reset();
if(!present("dryant 4"))
{
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
    "   The clouds create a grey overcast along the narrow path that\n"+
    "leads through the graveyard.  A dull green grass lines the gentle\n"+
    "hills where huge tombstones reach through the earth like fingers\n"+
    "reaching for the sky.  Large bones protrude through the ground\n"+
    "only lending to the eerie feeling this place invokes.\n";

items = ({
    "clouds","The are a dark grey and cast strange shadows on the ground",
    "grass","It is a dull green, looking almost undead",
    "hills","Soft rolling hills covered with graves",
    "tombstones","The look like fingers reaching for the sky",
    "graves","Large bones petrude from them",
    "bones","Brilliantly white even after being buried.  They are giant",
    "path","Its a narrow path that leads through the graveyard",
});
dest_dir = ({
    "room/south/sforst45.c","northeast",
    PATH+"gr2.c","west",
});

listens = ({
    "default","A strange silence fills the area",
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
    this_player()->set_fight_area();
}

exit(){
    if(this_player()) this_player()->clear_fight_area();
return 1;
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
