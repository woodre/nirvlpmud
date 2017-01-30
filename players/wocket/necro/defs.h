/*  12/12/2006 - Rumplemintz - Changed paths to players/guilds/necro  */
#include <ansi.h>
#if 0 /* Rumplemintz */
#define COLOR "/players/wocket/closed/ansi.h"
#else
#define COLOR "/sys/ansi.h"
#endif

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

#define PATH       "/players/guilds/necro"
#define SAVE      "players/guilds/necro/members/"
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

#define GUILD_ID   "necro_ob"
#define TOOL_ID   "necro_tool"
#define TOOL     present(TOOL_ID,tp)
#define GHOULSHIELD "necro_spirit_armor"
#define OWNER      "Rumplemintz"
#define OWNERRN    "rumplemintz"
#define ALTSPIRITS ""
#define ROD        "<"+HIR+"RoD"+OFF+"> "
#define NECRO      "<"+HIR+"NeCRo"+OFF+"> "

#define GOB         present(GUILD_ID,this_player())
#define GRAVESITE   present("gsite_ob",environment(tp)) || environment(tp)->gravesite()
#define BLOODMOON   present("bloodmoon",environment(tp))

#define CHAT_D      "/players/guilds/necro/daemons/channel_d.c"
#define SPELL_D     "/players/guilds/necro/daemons/spell_d.c"
#define DEATH_D     "/players/guilds/necro/daemons/deathcall_d.c"
#define CONVERTMSG_D "/players/guilds/necro/daemons/say_d.c"
#define ROOM        "/players/wocket/std/tvroom.c"


#define BLOODCOST   5
#define SKINCOST    7
#define EYECOST    10
#define SPINECOST  15
#define HEARTCOST  15
#define SOULCOST   20
#define TYPES  ({ "sword","dagger","knife","axe","blade","katana","blades","swords" }) 
