#ifndef HIB
#include "/players/snow/closed/color.h"
#endif
#ifndef TP
#define TP this_player()
#define TO this_object()
#define ENV environment
#define GOB "/players/snow/dervish/master.c"
#define ENVTO ENV(TO)
#define NOTME TP != ENVTO
#define RN query_real_name()
#define LOG "/players/snow/dervish/logs/"
#define TPRN TP->RN
#define TPN TP->query_name()
#define TE tell_object
#define GID "dervish_tattoo"
#define CHATOB "/players/snow/dervish/objects/chatob.c"
#define WHIRLWIND "derv_whirlwind"
#define SANDSTORM "derv_sandstorm"

#define DWIZ ({"snow","vertebraker","fred","shinshi"})
#define DERVWIZ(x) (member_array((string)x->query_real_name(),DWIZ)>-1)
#endif
