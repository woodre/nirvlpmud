#include "/players/eurale/closed/ansi.h"

/* player information */
#define TP this_player()
#define TPRN this_player()->query_real_name()
#define TPL this_player()->query_level()

/* object information */
#define ETO environment(this_object())
#define TO this_object()
#define ROOM environment(this_player())
