inherit "room/room";
#include "definitions.h"

int note;

void init() {
add_action("pray","pray");
add_action("search","search");
::init();
}

reset(arg) {

        note=0;
        if(!present("lord"))
        move_object(clone_object(CASTLEMONSTER+"/smaeonte_lord.c"),this_object());
        if(!present("sithi")) {
        move_object(clone_object(CASTLEMONSTER+"/sithi_priest.c"),this_object());
        }

        if(!arg) {
        note=0;
        set_light(1);
        short_desc="Meditation room";
        long_desc=
"     You stand in a small egg-like chamber.  Black ebony is bent into\n"+
"a circular shape upon the floor.  It appears to be a place for commune\n"+
"with a greater being.  Candles line the walls.  Perhaps you could\n"+
"pray in it, if you are curious enough to find out what happens.\n"+
"A large pedestal lies behind the circle.\n";

   dest_dir=({
        CASTLEROOM+"/guardsportal.c","down"  ,
            });

   items=({
        "candles","     The huge candles burn like torches",
        "pedestal",
"     The pedestal is made of black ebony.  Devilish figures are carved\n"+
"into its sides.  The pedestal seems to be a podium to talk to\n"+
"masses of people, but this room cannot hold very many people\n"+
"at all.  There is a piece of paper upon the pedestal",
   });
   }   }

search(str) {
        if (!str) {
                write("What do you search?\n");
                return 1;}
        if (str == "pedestal") {
                write("The pedestal has a piece of paper on it.\n");
                return 1;}
        if (str == "paper") {
                if (note == 0) {
                write(
"     You read the following:\n\n"+
"Ha ha ha ha ha.  Now come adventurers, you must realize your folly.\n"+
"Why waste your power on little sithi creatures.  Come join me and\n"+
"together we will amass enough strength to topple the mightiest of\n"+
"wizards and the strongest of fighters.  Yes, come to my altar and\n"+
"kneel before it.  You can make your otherwise pathetic existance\n"+
"into one in which creatures fear and die before.\n"+
"Kneel,  kneel,  kneel  before me....................\n"+
"\n"+
"     The note is written in blood and vanishes as you finish reading it.\n");
                note=1;}
                else write(
"     The paper vanishes before your eyes.\n");
        return 1;}
}

int pray(string str) {
        write(
"     You kneel down in the circle of black ebony and pray.\n"+
"Suddenly, you hear a cracking of wood.  Tendrils of black shadow\n"+
"rise from the circle and shoot straight up into the ceiling.\n"+
"The ebony bursts into fire.  Everything goes to hell, and you\n"+
"are thrown from the circle.  A voice that sounds half strained and\n"+
"twice mad booms out:\n"+
"\n"+
"                D  A  M  N        Y  O  U\n");
        return 1;}
