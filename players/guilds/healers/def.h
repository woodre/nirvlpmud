#include <ansi.h>

#define root     "players/guilds/healers/"
#define POWER    "/"+root+"guilddaem"
#define SHADE    root+"shade.c"
#define MEM      root+"member/"

#define TO       this_object()
#define tp       this_player()
#define ep       environment(TO)
#define tpn      tp->query_real_name()
#define etp      environment(tp)
#define eep      environment(ep)
#define epn      ep->query_real_name()
#define att      ep->query_attack()
#define attname  att->query_name() 
#define tl       tp->query_level()
#define tx       tp->query_extra_level()
#define epl      ep->query_level()
#define epxl     ep->query_extra_level()
#define txp      tp->query_exp()
#define tsp      tp->query_sp()
#define thp      tp->query_hp()
#define tmhp     tp->query_mhp()
#define tmsp     tp->query_msp()
#define tpie     tp->query_attrib("pie")


#define RO       restore_object(MEM+tpn)
#define SO       save_object(MEM+tpn)
#define SOE      save_object(MEM+epn); 
#define hob      present("mythos_healer",tp)
