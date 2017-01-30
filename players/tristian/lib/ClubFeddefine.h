/* Ansi Colors */
#include "/players/tristian/lib/ansi.h"

/* Paths */
#define ROOT "/players/tristian/realms/ClubFed/"
#define NPC "/players/tristian/realms/ClubFed/mobs/"
#define OBJ "/players/tristian/realms/ClubFed/obj/"
#define RMS "/players/tristian/realms/ClubFed/rooms/"
#define NPC2 "/players/tristian/realms/ClubFed/mobs2/"

/* Standard Defines */
#define TP this_player()
#define TPRN this_player()->query_real_name()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
#define AA add_action
#define SUBJECT subjective() /*he/she*/
#define POSESS possessive() /*his/hers*/
#define OBJECTIVE objective() /*him/her*/

/* Monster Defines */
#define MOBS ({"bank_fraud","blackmail","counterfeiting","embezzlment","extortion","forgery","healthcare_fraud","insider_trading","kickback","money_laundering","tax_evasion","cell_phone"})
#define MOB_DAEMON "/players/tristian/realms/ClubFed/ClubFedMobs.c"

