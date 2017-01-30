#include "/players/snow/closed/color.h"
#define TP this_player()
#define TO this_object()
#define ENV environment
#define ENVTO ENV(TO)
#define NOTME TP != ENVTO
#define RN query_real_name()
#define LOG "/players/shinshi/dervish/logs"
#define TPRN TP->RN
#define TPN TP->query_name()
#define TE tell_object
#define GID "dervish_tattoo"
#define GUILDPATH "/players/shinshi/dervish"
#define CHATOB "/players/shinshi/dervish/objects/chatob.c"
#define GUILDSPELL "/players/shinshi/dervish/lib"
#define WHIRLWIND "derv_whirlwind"
#define SANDSTORM "derv_sandstorm"
#define HALLPATH "/players/shinshi/dervish/hall"
#define OBJECTPATH "/players/shinshi/dervish/objects"
#define BOARDPATH "players/shinshi/dervish/objects/"
#define MEMPATH "/players/shinshi/dervish/member"
#define PFILE "players/shinshi/dervish/member"
#define LOGPATH "/players/shinshi/dervish/logs"
#define HELPPATH "/players/shinshi/dervish/help"
#define CAN_DO ({ "n","s","e","w","ne","nw","se","sw","u","d" })