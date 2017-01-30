#pragma strict_types

#include <ansi.h>
#include "/players/darkfire/castle/circus/circus.h"
#include "_area.h"

/* Inherit the area's base room. */
inherit "/players/darkfire/castle/circus/rooms/midway/_base.c";

void
reset(int arg) {
	::reset();

	if(arg) return;

	set_col(4);
	set_row(4);

	set_long("The " + ASPHALT2 + " path continues west and east. "+grn("Vines")+" crawl from the undergrowth "
		+ "and cross the path, making the footing treacherous. To the south you can see the backs of "
		+ "the delapidated booths lining the midway. North of you, deep in the trees, you can see the "
		+ "skeletal remains of old circus tents, faded canvas flapping like shreds of flesh."
	);

	add_exits("e,w");
}

void
init() {
	::init();
}
