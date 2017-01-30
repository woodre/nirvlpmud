#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define TPN this_player()->query_name()
#define TP this_player()
inherit "room/room";


reset(arg) {
     if(arg) return;
     set_light(1);

     short_desc = "South Gate";
     long_desc =
"    Better known as travellers gate, this impressive bastion serves\n\
to regulate the traffic through the city and offer protection from any\n\
who would dare attack.  Inside the dark tunnel along both walls slots\n\
have been carved out and many small but noticeable holes pierce the\n\
stone cieling.  The sharp spikes of the raised portcullus hang down\n\
menacingly.\n";

     items = ({
     "tunnel","The smooth stone walls of the tunnel are dark and hard to see",
     "stone","The polished black stone could be marble or onyx, it's hard to tell",
     "walls","The walls have strange marble-like veins in them that seem to move and\n\
twist into symbols",
     "symbols","As soon as you focus on one of the intricate glyphs it changes",
     "slots","Narrow inside and wide outside, these cross shaped slots hide deadly archers\n\
offering them superior position against attackers",
     "holes","Used, undoubtedly, to pour boiling oil or other unhealthy substances\n\
upon invaders",
     "portcullus","This inner gate is dropped when the outer door is breached, allowing\n\
those inside the walls to attack unfourtunates trapped within the gatehouse tunnel.\n",
});

dest_dir = ({
	AREA+"101-150.c","north",
        AREA+"99-150.c","south",
});

}
