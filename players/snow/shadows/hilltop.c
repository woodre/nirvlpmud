/*  10/09/06 - Rumplemintz: moved inherit above #include statement  */

inherit "/players/snow/shadows/base.c";
#include "shaddefs.h"
realm() { return "NT"; }


reset(arg){

    if(!present("shadow gem")) {
	move_object(clone_object("/players/snow/shadows/stuff/sgem"), this_object() ); }

    if(!arg){

	set_light(0);
	short_desc="ShadowPlane";
	long_desc=
	"You stand upon a hill in a dark realm. Dizzying sights confound your mind.\n"+
	"Shadows flit around the corners of your vision. What seems clear one moment\n"+
	"disappears the next. Vague shadow bushes appear here and there- sometimes\n"+
	"you think you might even see a tree. Shapes of animals suddenly appear... \n"+
	"and as suddenly leave. The landscape appears to somehow flow around your\n"+
	"solidity here. To move from place to place, you must make a huge effort. \n"+
	"\n";

	items=({
	  "bushes", "Bushes of shadowstuff. When you touch them, your hand meets little\n"+
	  "resistance and passes through without noticable effect",
	  "tree","You think you see a shadow tree but it fades away as you draw near",
	  "animals","Vague animal shapes seem to peer at you, then fade away..",
	  "landscape","Features of the land pass before your eyes",
	  "hill","The hill you stand upon appears to be a solid point of reference\n"+
	  "...perhaps.\n",
	});

    }   }
query_srealm() { return "shad"; }
