#include <ansi.h>
#define TP this_player()
#define TPP TP->query_possessive()                   /* Gender */
#define TPRN this_player()->query_real_name()        /* Returns Name */
#define TPN this_player()->query_name()          /* Return current name */
#define MOCO move_object(clone_object
#define WW int_command("wield weapon")         /* wields weapon */
#define TPL this_player()->query_level()
#define TO this_object()
#define TI this_interactive()
#define PO previous_object()
#define ENV(x) environment(x)
#define ENVTP environment(this_player())
#define ENVTO environment(this_object())
#define CAP(x) capitalize(x)
#define LOWER(x) lower_case(x)
#define DIR /players/autumn
#ifndef __LDMUD__
object gold;
#endif