#include "/players/cosmo/closed/dfns.h"
#include "/players/cosmo/closed/ansi.h"
inherit "room/room";

reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc = MAG+"Key Bridge"+NORM;
    no_castle_flag = 0;
    long_desc = 
         "   High above you, lightposts line the sides of this Victorian\n"
        +"bridge.  The Potomac River below flows gently here, but the\n"
        +"cars on the bridge don't, as one driver nearly runs over\n"
        +"your foot.  Despite their high speeds, the traffic is fairly\n"
        +"dense here, as locals and tourists alike scramble to reach\n"
	+"the many sights and sounds of Georgetown on the other side.\n\n"
        +"THIS BRIDGE IS CURRENTLY UNDER CONSTRUCTION.\n\n";

    items = ({
        "river", "A filthy polluted river.  Who knows what's down there",
        "bridge", "A Victorian style bridge with 3 lanes of traffic in "
                + "each direction",
        "driver", "The driver extends his middle finger and shouts profanities\n"
                + "at you for being in the middle of the road",
        "lightposts", "They provide light for you to see your way",
    });

    dest_dir = ({
/*	DCDIR+"rooms/gt1", "city", */
        DCDIR+"rooms/entrance", "back",
    });
}
