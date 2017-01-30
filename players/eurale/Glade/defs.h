#include "/players/eurale/closed/ansi.h"

/* player information */
#define TP this_player()
#define TPN this_player()->query_name()
#define TPRN this_player()->query_real_name()
#define TPL this_player()->query_level()
#define TPXL  this_player()->query_extra_level()
#define TPAC this_player()->query_ac()
#define TPWC this_player()->query_wc()
#define TPHP this_player()->query_hp()
#define TPSP this_player()->query_spell_point()
#define TPSTR this_player()->query_attrib("str")
#define TPSTA this_player()->query_attrib("sta")
#define TPWIL this_player()->query_attrib("wil")
#define TPMAG this_player()->query_attrib("mag")
#define TPPIE this_player()->query_attrib("pie")
#define TPSTE this_player()->query_attrib("ste")
#define TPLUC this_player()->query_attrib("luc")
#define TPINT this_player()->query_attrib("int")
#define TPGEXP this_player()->query_guild_exp()

/* object information */
#define TO this_object()
#define ROOM environment(this_player())
