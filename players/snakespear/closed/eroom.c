#include "/players/snakespear/closed/ansi.h"
inherit "room/room";

reset(arg) {
 if(arg) return;
set_light(1);
short_desc= HIB+"Snakespear's Ledge"+NORM;
long_desc=
  "  This is a 12 oz can of Mountain Dew.  This is the beverage of\n"+
  "champions and one could only hope to drown in such a wonderful\n"+
  "beverage.  The green fluid is all around.. sloshing and bubbling.\n"+
  "There is a small rose floating about in the warm fluid.\n\n"+
  "          Possible exits from the can:\n\n"+
  "       leap    -->    Snakespear's Workroom\n"+
  "       fly     -->    Zultayne's Foyer\n"+
  "       run     -->    Village Church\n\n";

items=({
     "rose","Big red rose that says 'SMOOCH' on it",
     "fluid","It's Mountain Dew, of course, dumbass!",
     "beverage","Dumbass, can you not taste the Mountain Dew?",
     "can","An object made of tin that is just right for Mountain Dew!",
});

dest_dir=({
     "/players/snakespear/zultayne/rooms/foyer.c","fly",
     "/room/church.c","run",
     "/players/snakespear/workroom.c","leap",
});
}
