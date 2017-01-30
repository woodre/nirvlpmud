#include "/obj/ansi.h"

#define tp this_player()
#define to this_object()
#define qn query_name()
#define rn query_real_name()
#define fp find_player
#define fl find_living
#define tl_ob tell_object
#define tl_rm tell_room
#define env(x) (x?environment(x):environment())
#define user env
#define qa query_attack()
#define cap capitalize
#define ql query_level()
#define hp query_hp()
#define sp query_sp()
#define mo move_object
#define co clone_object
#define mp move_player
#define low lower_case
#define po previous_object()
#define tpn (string)tp->qn

