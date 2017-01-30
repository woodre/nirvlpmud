#include "/obj/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
#define TPRN this_player()->query_real_name()
#define EN environment()
#define ENN environment()->query_name()
#define TO this_object()
#define MO move_object
#define CO clone_object
#define POS this_player()->query_possessive()
#define HOSER this_object()->query_attack()
#define HOSERN this_object()->query_name()
#define ATN attacker()->query_name()
#define APOS attacker()->query_possessive()
#define CAP capitalize


