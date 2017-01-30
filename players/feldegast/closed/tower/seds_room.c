#include "/players/feldegast/defines.h"

inherit ROOM;

void reset(int arg) {
  if(arg) return;
  short_desc=HIR+"Bedroom"+NORM;
  long_desc=
"   As you enter this magnificent room, you are awe struck by the sheer\n\
richness of your surroundings. The majority of the room is taken by the\n\
huge waterbed, which, apparently, is intended for more than two people.\n\
Looking to your left, you see a whirlpool, its motor quietly turning and\n\
gently waves flowing along the surface of the water. To your right, a\n\
pair of solid glass french doors open to a spacious balcony, with a view\n\
of the town, and in the distance the many lands and castles of Nirvana.\n\
And, of course, in front of you is the bed, with a huge aquarium acting\n\
as a headrest, and little tropical fish swimming around, to create a\n\
somewhat 'wet' environment. To the left of the bed, you notice, is a\n\
tall wooden cabinet. Since you know Seductress, you decide you'd rather\n\
not look in there.\n";
  set_light(1);
  dest_dir=({
    "/players/feldegast/closed/tower/tower2","south",
  });
}
