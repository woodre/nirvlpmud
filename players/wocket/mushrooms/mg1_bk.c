inherit "room/room";
#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/mushrooms/"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()

reset(arg) {
  if(arg) return;

set_light(1);

short_desc = HIR+"The Mushroom Grove"+NORM;
long_desc =
    "   \
The trees of the dim forest begin to take shape into large\n\
oversized mushrooms. The pathway between them is clearly\n\
defined as if it has been well used.  Light filters through\n\
the domed tops and musky sent fills the air.\n";

items = ({
    "light","It filters through the mushrooms",
    "mushrooms","They are oversized and very colorful",
    "pathway","It is well worn from use",
});

dest_dir = ({
    PATH+"mg2.c","west",
    "room/south/sforst45.c","east",
});

}

init(){
    ::init();
    add_action("smell","smell");
}

int smell(){
write("You smell the musky odor.\n");
return 1;
}
