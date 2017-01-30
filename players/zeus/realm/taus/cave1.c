inherit "room/room";    /*  cave1.c  */
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

int teleport;

reset(arg){
        teleport = 0;  if(random(TFL_TLP)) teleport = 1;
 if(arg) return;

 long_desc=
"The forest is extremely thick here, blocking out the sun.  The evergreen\n"+
"trees are creating a thick canopy above.  The opening to a very dark\n"+
"cave stands before you, the tunnel leading down into the ground.  A\n"+
"small trail leads away to the west.\n";
 set_light(0);
 items=({
   "trees",
"The mighty evergreen trees loom high above your head, their branches\n"+
"reaching out across the forest",
   "branches",
"The branches of the mighty evergreen trees criss cross, making a fairly\n"+
"dense canopy which blocks out all of the blue sky",
   "canopy",
"The canopy of trees is incredibly thick, blocking out the blue sky",
        "sun",
"The sun is not visible through the trees above",
        "opening",
"The opening of the cave is gaping, like an agonized mouth.  You could\n"+
"easily 'enter' the cave",
        "cave",
"The cave is just jutting out of the ground, the tunnel leading down\n"+
"beneath the ground.  You could easily 'enter' the cave",
        "tunnel",
"The tunnel is gaping wide, leading down into the ground.  Cold air\n"+
"can be felt blowing out of it",
        "trail",
"A small dirt trail leads out of the darkness to the west",
 });
 dest_dir=({});
}

short(){ return "The Fallen Lands"; }

void init(){
  ::init();
  add_action("w_dir2", "west");
  add_action("enter_cmd", "enter");
}

exit(){    if(TP) TP->clear_fight_area();     }
realm() { if(teleport) return "NT"; }
okay_follow() { return 1; }

w_dir2(){
        write("You walk west along the trail...\n\n");
        if(w_dir()) return 1;
        TP->MP("west#players/zeus/realm/taus/guth5.c");
        return 1;
}

status enter_cmd(string str){
        if(!str) return 0;
        if(str == "cave" || str == "tunnel"){
                write("You enter the dark cavern...\n\n");
                TP->MP("into the cave#/players/zeus/realm/taus/cave2.c");
                return 1;
        }
        else return 0;
}

