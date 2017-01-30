#include "/obj/ansi.h"

#define ROOT "players/illarion/cathedral/"
#define ROOM ROOT+"room/"
#define MON ROOT+"mon/"
#define OBJ ROOT+"obj/"

#define TO this_object()
#define ETO environment(this_object())
#define TP this_player()
#define TPN (string)this_player()->query_name()
#define TPRN (string)this_player()->query_real_name()
#define FAIL(x) { notify_fail(x); return 0; }
#define BLD(x) "\""+BOLD+x+NORM+"\""
#define IBUG(x) if(find_player("illarion")) tell_object(find_player("illarion"),x)
#define CLF "/players/illarion/closed/colorformat.c"
#define VILLA "/players/illarion/closed/villa/"
#define GUIDE "/players/illarion/poke/mon/monster_guide"
#define NAME(x) (string)x->query_name()
#define ENV(x) environment(x)
#define ansi_pad(x,y) (string)call_other("/players/illarion/obj/ansi_pad.c","ansi_pad",x,y)
#define ansi_format(x,y) (string)call_other("/players/illarion/obj/ansi_pad.c","ansi_format",x,y)