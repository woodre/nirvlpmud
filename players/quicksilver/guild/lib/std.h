/* paths */

#define DAEMON 	"players/quicksilver/guild/gdaemon"

#define BASE_DIR 	"players/quicksilver/guild/"

#define CRE_DIR 	"players/quicksilver/guild/cre/"
#define DOC_DIR 	"players/quicksilver/guild/doc/"
#define SAVE_DIR 	"players/quicksilver/guild/members/"
#define LIB_DIR 	"players/quicksilver/guild/lib/"
#define LOG_DIR 	"players/quicksilver/guild/log/"
#define OBJ_DIR 	"players/quicksilver/guild/obj/"
#define ARMOR_DIR 	"players/quicksilver/guild/obj/armor/"
#define WEAPON_DIR 	"players/quicksilver/guild/obj/weapon/"
#define HEAL_DIR 	"players/quicksilver/guild/obj/heal/"
#define ROOM_DIR 	"players/quicksilver/guild/r/"

#define ROOM 		"players/quicksilver/guild/lib/room_ext"
#define MONSTER 	"players/quicksilver/guild/lib/monster_ext"
#define WEAPON 	"players/quicksilver/guild/lib/weapon_ext"
#define ARMOR       "obj/armor"

/* Commonly used defines */

#define NAME query_name()
#define TP this_player()
#define CN capitalize(this_player()->query_name())
#define TN this_player()->query_name()
#define RN this_player()->query_real_name()
#define TO this_object()
#define ENVTO environment(this_object())
#define ENVTP environment(this_player())
#define RANK query_guild_rank()
#define SET_RANK(x) set_guild_rank(x)
#define SET_RANK(ob,x) ob->add_guild_rank(-1 * ob->query_guild_rank() + x)
#define ADD_RANK(x) add_guild_rank(x)
#define GEXP query_guild_exp()
#define SET_GEXP(ob,x) ob->add_guild_exp(-1 * ob->query_guild_exp() + x)
#define ADD_GEXP(x) add_guild_exp(x)
