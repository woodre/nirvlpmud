#include "/players/mythos/closed/ansi.h"
#define MAX      20
#define MEM      "players/mythos/myth/member/"
#define BASE     "/players/mythos/myth/base.c"
#define POWER    "/players/mythos/myth/power.h"
#define tp       this_player()
#define tpn      tp->query_real_name()
#define ep       environment(this_object())
#define etp      environment(tp)
#define eep      environment(ep)
#define epn      ep->query_real_name()
#define att      ep->query_attack()
#define attname  att->query_name() 
#define tl       tp->query_level()
#define tx       tp->query_extra_level()
#define epl      ep->query_level()
#define epx      ep->query_extra_level()
#define txp      tp->query_exp()
#define tsp      tp->query_sp()
#define thp      tp->query_hp()
#define RO       restore_object(MEM+tpn)
#define SO       save_object(MEM+tpn)
#define ROE      restore_object(MEM+epn);
#define SOE      save_object(MEM+epn); 
#define MYOB     present("MYTHOSSYSOBJ",ep)
#define MYXP     MYOB->add_cxp(1)