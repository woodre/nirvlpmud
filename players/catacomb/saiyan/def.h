#include "/players/catacomb/misc/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
#define TPRN this_player()->query_real_name()
#define ENV environment()
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
#define HP  this_player()->query_hp()
#define SP  this_player()->query_sp()
#define MHP this_player()->query_mhp()
#define MSP this_player()->query_msp()
#define STUFF this_player()->query_stuffed()
#define SOAK this_player()->query_soaked()
#define TOX this_player()->query_intoxication()
#define LVL this_player()->query_level()
#define XLVL this_player()->query_extra_level()
#define CASH this_player()->query_money()
#define XP this_player()->query_exp()
#define WOO "/players/catacomb/saiyan/home.c"


