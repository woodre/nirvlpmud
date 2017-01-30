#include "/players/illarion/ansi.h"
#define HROOM "/players/illarion/high/room/"
#define HMON "/players/illarion/high/mon/"
#define HOBJ "/players/illarion/high/obj/"
#define TP this_player()
#define TPN this_player()->query_name()
#define FAIL(x) { notify_fail(x); return 0; }
#define BLD(x) BOLD+x+NORM
#define IBUG(x) tell_object(find_player("illarion"),x)
#define CLF "/players/illarion/closed/colorformat.c"
