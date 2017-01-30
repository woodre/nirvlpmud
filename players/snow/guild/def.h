#include "/players/snow/closed/color.h"
#define TP this_player()
#define TO this_object()
#define ENV environment
#define GOB "/players/snow/guild/master.c"
#define ENVTO ENV(TO)
#define NOTME TP != ENVTO
#define RN query_real_name()
#define LOG "/players/snow/guild/logs/"
#define TPRN TP->RN
#define TPN TP->query_name()
#define TE tell_object
#define GID "cyborg_slave"
