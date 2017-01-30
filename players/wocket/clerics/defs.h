#include "/players/wocket/closed/ansi.h"
#define COLOR "/players/wocket/closed/ansi.h"

#define tp         this_player()
#define tpn        tp->query_name()
#define tprn       tp->query_real_name()
#define tpl        tp->query_level()
#define tpxl       tp->query_extra_level()
#define tpp        tp->query_possessive()
#define ep         environment(this_object())
#define epn        ep->query_real_name()
#define MV         call_other(this_player(),"move_player" 
#define tl         tp->query_level()
#define tx         tp->query_extra_level()
#define epl        ep->query_level()
#define epx        ep->query_extra_level()
#define egl        ep->query_guild_rank()
#define tgl        tp->query_guild_rank()
#define to         this_object()

#define PATH       "/players/wocket/clerics"
#define SAVE      "players/wocket/clerics/members/"
#define ADMIN      PATH+"/power_admin"
#define SPELLS     PATH+"/spells"
#define CMDS       PATH+"/cmds"
#define EMOTES     PATH+"/emotes"
#define DAEMONS    PATH+"/daemons"
#define DOCS       PATH+"/docs"
#define LOG        PATH+"/log"
#define MISC       PATH+"/misc"
#define MON        PATH+"/mon"
#define OBJ        PATH+"/obj"
#define BODYPARTS  OBJ+"/bodyparts"
#define POWER      PATH+"/power"

#define GUILD_ID   "cleric_ob"
#define OWNER      "Wocket"
#define OWNERRN    "wocket"

#define CHAT_D      "/players/wocket/clerics/daemons/channel_d.c"
#define SPELL_D     "/players/wocket/clerics/daemons/spell_d.c"
#define DEATH_D     "/players/wocket/clerics/daemons/deathcall_d.c"
#define CONVERTMSG_D "/players/wocket/clerics/daemons/say_d.c"
#define ROOM        "/room/room.c"
