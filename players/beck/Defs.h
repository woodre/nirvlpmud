#define CHANNEL "/players/beck/Daemons/ChannelDaemon.c"

/* Useful Shortcuts */
#define TP this_player()
#define TO this_object()
#define PO previous_object()
#define NAME query_name()
#define RNAME query_real_name()
#define CAPTPRNAME capitalize(this_player()->query_real_name())
#define TPNAME this_player()->query_name()
#define TPRNAME this_player()->query_real_name()
#define ENV environment
#define ENVTP environment(this_player())
#define ENVOB environment(this_object())
#define ENVPO environment(previous_object())
#define SP query_sp()
#define HP query_hp()
#define EXP query_exp()
#define GEXP query_guild_exp()
#define LEVEL query_level()
#define GLEVEL query_guild_rank()
justify(str, len) { return extract(str+"                     ",0,len-1);}
#include "/players/beck/esc.h"
