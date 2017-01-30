#include <ansi.h>
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

