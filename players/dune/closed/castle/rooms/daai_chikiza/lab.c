inherit "room/room";
#include "definitions.h"

int i = 1;
int j = 1;
int k = 0;

init () {
add_action("eat","eat");
::init();
}

reset(arg) {

        i = 1;
        j = 1;
        k = 1;

if (!present("wraith")) {
      move_object(clone_object(CASTLEMONSTER+"/wraith.c"),this_object());
   }

        if(!arg) {
        set_light(0);
        short_desc=("Laboratory");
        long_desc=
"     You enter what obviously is an alchemist's lab of some sort.\n"+
"Vials align shelves, filters and beakers are laced and intertwined upon\n"+
"a large central table.  A small metal pot emanates fumes that make your\n"+
"stomach turn.  In the far corner, a rather odd looking group of mushrooms\n"+
"grow in a box of dirt.\n";

   dest_dir=({
        CASTLEROOM+"/hall4.c","south"  ,
            });

   items=({
        "table","     The table looks quite ordinary",
        "shelves","     The shelves contain vials of herbs",
        "vials",
"     Small weeds lie in the vials.  You can't imagine what they are for.\n"+
"They are in small amounts though, so they don't seem worthy of attention",
        "filters","     The filters contain water",
        "beakers","     The beakers are all empty at the moment",
        "mushrooms",
"     The mushrooms grow in a rectangular metal dish about 6' by 7' in size.\n"+
"There are clumps of red, white, and green mushrooms.  Hmm, wonder if they\n"+
"are edible?  Is it wise to trust mushrooms grown in a laboratory?",
   });
   }   }

int eat (string str) {
if (str == "mushroom") {write("Which mushroom?\n"); return 1;}
else if (str == "mushrooms") {write("Which mushroom?\n"); return 1;}
else if (str == "red mushroom") {
        if (i <= 3) {
                write(
"     You eat the red mushroom.  Soon you feel a little nauseous.\n"+
"You are not sure what happened.\n");
                i += 1;
                }
        else write("There are no more red mushrooms.\n");
        return 1;
        }
else if (str == "green mushroom") {
        if (i <= 3) {
                write(
"     You eat the green mushroom.  Suddenly you feel very sick.\n"+
"You puke on the floor, and over some of the mushrooms.\n"+
"Yuck, you feel sick.\n");
                TP->hit_player(25);
                j += 1;
                }
        else write("There are no more green mushrooms.\n");
        return 1;
        }
else if (str == "white mushroom") {
        if (i <= 3) {
                write(
"     You eat the red mushroom.  Instantly a warm comforting\n"+
"feeling overwhelms your body and you feel healed.\n");
                k += 1;
                TP->heal_self(15);
                }
        else write("There are no more white mushrooms.\n");
        return 1;
        }
}
