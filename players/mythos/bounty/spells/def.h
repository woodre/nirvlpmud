#include "/players/mythos/closed/ansi.h"
#define tpR this_player()
#define tpN tpR->query_real_name()
#define bbG present("bgo",tpR) 
#define atT attacker
#define ahS atT->heal_self
#define ahP atT->hit_player
#define thS tpR->heal_self
#define thP tpR->hit_player
#define tahP tpR->add_hit_point
#define tasP tpR->add_spell_point
#define bbL bbG->query_level()
#define etP environment(tpR)
#define tpsP tpR->query_sp()