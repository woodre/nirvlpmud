#include "/players/jenny/ansi.h"
#define TP this_player()
#define POS TP->query_possessive()
#define TPRN this_player()->query_real_name()
#define TPN this_player()->query_name()
#define MOCO move_object(clone_object
#define TPL this_player()->query_level()
#define TO this_object()
#define TI this_interactive()
#define PO previous_object()
#define ENV(x) environment(x)
#define ENVTP environment(this_player())
#define ENVTO environment(this_object())
#define CAP(x) capitalize(x)
#define LOWER(x) lower_case(x)
object gold;
