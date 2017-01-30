#include "/players/dragnar/closed/color.h"
#define DEST "/players/dragnar/workroom"
#define user this_player()
#define capname capitalize(this_player()->query_real_name())
#define uhp this_player()->query_hp()
#define usp this_player()->query_sp()
#define att this_player()->query_attack()
#define attname att->query_real_name()
#define RN this_player()->query_real_name()
#define hp att->query_hp()
#define mhp att->query_mhp()
#define umhp this_player()->query_mhp()
#define umsp this_player()->query_msp()
#define RANK user->query_guild_rank()
#define LEV user->query_level()
#define guildobj present("shardak_mark", this_player())
#define MONITOR "[HPS: "+uhp+"/"+umhp+"] [SPS: "+usp+"/"+umsp+"] "
