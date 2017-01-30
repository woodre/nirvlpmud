#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#define TP this_player()
#define TO this_object()
#define ENV environment
#define GOB "/players/anshar/newsage/master.c"
#define ENVTO ENV(TO)
#define NOTME TP != ENVTO
#define RN query_real_name()
#define LOG "/players/anshar/newsage/logs/"
#define TPRN TP->RN
#define TPN TP->query_name()
#define TE tell_object
#define GID "sage_book"
#define CHATOB "/players/anshar/newsage/objects/chatob.c"
