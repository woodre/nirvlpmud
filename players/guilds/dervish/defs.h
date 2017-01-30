#include "/players/snow/closed/color.h"
#define TP this_player()
#define TO this_object()
#define ENV environment
#define ENVTO ENV(TO)
#define NOTME TP != ENVTO
#define RN query_real_name()
#define LOG "/players/guilds/dervish/logs"
#define TPRN TP->RN
#define TPN TP->query_name()
#define TE tell_object
#define GID "dervish_tattoo"
#define CHAN_NAME "Dervish"
#define GUILDPATH "/players/guilds/dervish"
#define CHAND "/bin/channel_daemon.c"
#define CHATOB "/players/guilds/dervish/objects/chatob.c"
#define GUILDSPELL "/players/guilds/dervish/lib"
#define WHIRLWIND "derv_whirlwind"
#define SANDSTORM "derv_sandstorm"
#define HALLPATH "/players/guilds/dervish/hall"
#define OBJECTPATH "/players/guilds/dervish/objects"
#define BOARDPATH "players/guilds/dervish/objects/"
#define MEMPATH "/players/guilds/dervish/member"
#define PFILE "players/guilds/dervish/member"
#define LOGPATH "/players/guilds/dervish/logs"
#define HELPPATH "/players/guilds/dervish/help"
#define CAN_DO ({ "n","s","e","w","ne","nw","se","sw","u","d" })
#define DWIZ ({"snow", "vertebraker", "fred", "shinshi", "dragnar"})
#define DERVWIZ(x) (member_array((string)x->query_real_name(), DWIZ) > -1)
