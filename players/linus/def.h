#if 0 /* Rumplemintz */
#include "/open/ansi.h"
#else
#include <ansi.h>
#endif

#define TP this_player()
#define MP move_player
#define TPN this_player()->query_name()
#define TPM this_player()->move_player
#define TPP this_player()->query_possessive() /* returns his/her */
#define TPG this_player()->query_gender() /* returns male/female */
#define TPO this_player()->query_objective() /* returns him/her */
#define TPR this_player()->query_pronoun() /* returns he/she */
#define TO this_object()
#define CO clone_object
#define MO move_object
#define FAIL notify_fail
#define ENV environment
#define NEWB "/players/linus/Newbie/room/"
#define PLAIN "/players/linus/Plains/room/"
#define PNPC "/players/linus/Plains/NPC/"
#define BB "/players/linus/Spongebob/room/"
