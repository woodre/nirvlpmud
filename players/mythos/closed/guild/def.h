#include "/players/mythos/closed/ansi.h"
#include "/players/mythos/closed/guild/name.h"
#define answer   "Sacrifice"
#define pact     "oath"
#define GC       11
#define POWER    "/players/mythos/closed/guild/power"
#define POWER2   "/players/mythos/closed/guild/power2"
#define MEM      "players/mythos/closed/guild/member/"
#define tp       this_player()
#define tpn      tp->query_real_name()
#define ep       environment(this_object())
#define epn      ep->query_real_name()
#define MV       call_other(this_player(),"move_player" 
#define att      ep->query_attack()
#define attname  att->query_name() 
#define tl       tp->query_level()
#define tx       tp->query_extra_level()
#define epl      ep->query_level()
#define epx      ep->query_extra_level()
#define egl      ep->query_guild_rank()
#define tgl      tp->query_guild_rank()
#define pp       present(fear,tp)
#define qtf      pp->query_fae()
#define txp      tp->query_exp()
#define scrp     pp->query_sacrifice()
#define tsp      tp->query_sp()
#define thp      tp->query_hp()
#define dpp      pp->query_defence()
#define epp      present(fear,ep)->query_defence()

