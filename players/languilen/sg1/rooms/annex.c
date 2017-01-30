/*
 *
 */
#include "../paths.h"
#include "/players/languilen/langdefs.h"
#include "/players/languilen/closed/ansi.h"
inherit "room/room";

static int gate;

reset(arg) {
     if(arg) return;
     set_light(1);

     gate = 0;

     short_desc = "Apophis's Annex";
     long_desc =
"    .\n";

     items = ({
     "walls","If you're starring at the walls you're looking the wrong direction",
     "room","The command room looks out over this room but there's no way in from here",
     "ramp","The wide ramp is firmly affixed to the platform",
     "platform","It solidly supports the immense stargate",
     "symbols","You cannot decipher there meaning",
     });

     dest_dir = ({
     ROOM+"guardrm1.c","north",
     ROOM+"guardrm2.c","south",
     ROOM+"gate2.c","west",
     });
}

