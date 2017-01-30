/*
 *
 */
#include "../paths.h"
#include "/players/languilen/langdefs.h"
#include "/players/languilen/closed/ansi.h"
inherit "room/room";

reset(arg) {
     if(arg) return;
     set_light(1);

     short_desc = "The Atrium";
     long_desc =
"    This room is open to the sky, but overgrown with various\n\
plantlife that softens the elements well.  A wrought iron table\n\
sits, covered by a big umbrella, with a few chairs surrounding it.\n";

     items = ({
     "book","An impressive volume bound in white leather, read it",
     });

     dest_dir = ({
     ROOM + "hall","south",
});

}
