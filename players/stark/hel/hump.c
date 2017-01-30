inherit "/players/vertebraker/closed/std/room";
#include "/players/stark/defs.h"
reset(arg){


if(arg) return;
    set_light(1);
    add_listen("You hear nothing of interest.\n");
    add_smell("You smell nothing of interest.");
    short_desc=HIK+"Humpbacked Bridge"+NORM;
    long_desc=
/*
 1234567891123456789212345678931234567894123456789512345678961234567897*/
"You stand on a crude and simple humpbacked bridge.  The thick wood has \n"+
"weakened and becomed maligned over time but still connects together.  \n"+
"A slow moving river sludges below the creeping wood bridge.  Eastward \n"+
"a village plays out while the west yields only wilderness.\n";

items=({
"bridge","You're standing on it.",
"river","Algae filled waters slowly flow southward below the bridge.",
"village","A dark and dreary village is visable to east"
});

dest_dir=({
"/players/stark/hel/vill_green", "east",
"/players/stark/hel/wild1", "west"
});
}
