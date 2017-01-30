#include "/players/nikki/ansi.h"
inherit "room/room";

reset(arg) {
   if(!arg) {
set_light(1);
short_desc = HIB+"Blasting Zone!"+NORM;
long_desc = CLR+HIR+

" _____    _    _______    _     __     __  _______   __    __  __\n"+
"|%%%%/   /%\\  /%%%%%%|   /%\\   |%/    |%/ /%%%%%%|   \\%\\  /%/ |%/\n"+
"|%|____ /%_%\\  ^^|%|^   /%_%\\  |%|    |%|  ^^|%|^     \\%\\/%/  |%|\n"+
"|%%%%%//%/_\\%\\   |%|   /%/_\\%\\ |%|    |%|    |%|       \\/%/   |%|\n"+
"|%|    |%| |%|   |%|   |%| |%| |%|    |%|    |%|       /%/    |%|\n"+
"|%|    |%| |%|   |%|   |%| |%| |%|___ |%|    |%|      /%/     /_|\n"+
"|%|    |/  |/    |%|   |/  |/  |%%%%/ |/     |%|     /%/      ___\n"+
"|/               |/             ^^^^         |/     /%/       |%/\n"+
"                                                    \\/         ^ \n"+NORM;

dest_dir = ( {
    "players/nikki/Museum/Duke/Rooms/room1", "right",
});
} }

realm() { return "NT"; }

