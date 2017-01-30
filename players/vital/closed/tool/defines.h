#include "/players/quicksilver/closed/color.h"
#define for_all_users int i; for(i=0;i<sizeof(users());i++)
#define for_all_in(what) int i; for(i=0;i<sizeof(all_inventory(what));i++)
#define each_user users()[i]
#define each_in(what) all_inventory(what)[i]
#define ai(who) all_inventory(who)
#define co(x) clone_object(x)
#define mo(x,y) move_object(x,y)
#define fp(x) find_player(lower_case(x))
#define tp this_player()
#define tpname this_player()->query_name()
#define env_name(obj) environment(obj)->query_name()
#define fo(x) find_object(x)
#define env(obj) environment(obj)
#define fl(x) find_living(x)
