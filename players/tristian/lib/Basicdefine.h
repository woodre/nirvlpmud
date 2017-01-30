/* Ansi Colors */
#include "/players/tristian/lib/ansi.h"

/* Paths */
#define LOG "/players/tristian/log/"
#define CLUB "/players/tristian/realms/ClubFed/"
#define CLUBM "/players/tristian/realms/ClubFed/mobs/"
#define CLUBO "/players/tristian/realms/ClubFed/obj/"
#define CLUBR "/players/tristian/realms/ClubFed/rooms/"
#define GOBLIN "/players/tristian/realms/goblin/"
#define GOBLINM "/players/tristian/realms/goblin/mobs/"
#define GOBLINO "/players/tristian/realms/goblin/obj/"
#define GOBLINR "/players/tristian/realms/goblin/rooms/"


/* Standard Defines */
#define TP this_player()
#define TPRN this_player()->query_real_name()
#define TPN this_player()->query_name()
#define TPL this_player()->query_level()
#define TPP this_player()->query_possessive()
#define AA add_action
#define SUBJECT subjective() /*he/she*/
#define POSESS possessive() /*his/hers*/
#define OBJECTIVE objective() /*him/her*/