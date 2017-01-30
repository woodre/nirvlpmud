#include "/players/feldegast/closed/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
#define TPRN capitalize(this_player()->query_real_name())
#define AT attacker_ob
#define AN attacker_ob->query_name()
#define ENV environment(this_player())
#define ENVO environment(this_object())
#define ROOM "/players/feldegast/std/room"
#define TON this_object()->query_name()
#define QN query_name()

#define INNER "/players/feldegast/arena/rooms/inner2"

#define FTELL(x) if(find_player("feldegast")) tell_object(find_player("feldegast"),x);
