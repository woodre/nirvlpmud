/* ansi colors copied from open/ansi.h */
#include "/players/eurale/closed/ansi.h"

/* player information */
#define ETP environment(this_player())
#define TP this_player()
#define TPRN this_player()->query_real_name()
#define CTPRN capitalize(this_player()->query_real_name())
#define TPPOS this_player()->query_possessive()  /*  his/her  */
#define TPPRO this_player()->query_pronoun()     /*  he/she   */
#define TPOBJ this_player()->query_objective()   /*  him/her  */
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
#define ETO environment(this_object())
#define TO this_object()
#define ETP environment(this_player())
