#include <ansi.h>

#define GUILDNAME "fallen"
#define CMDDIR "/players/guilds/fallen/circle/power/"
#define SAVE_PATH "players/guilds/fallen/circle_member/"
#define SAVE_PATH2 "/players/guilds/fallen/circle_member/backup/"
#define UPDATE_PATH "/players/guilds/fallen/misc/UPDATE"
#define USER environment(this_object())
#define attack USER->query_attack()
#define Attack User->query_attack()
#define GOB present("circle_object", this_player())
#define PO (caller() ? caller() : this_object())
#define User ((previous_object()?environment(previous_object()) : environment()))
#define NAME USER->query_real_name()
#define Name User->query_real_name()
#define QN query_name()
#define TR tell_room
#define POS query_possessive()    /*  his her  */
#define PRO query_pronoun()       /*  he she  */
#define OBJ query_objective()     /*  him her  */
#define TOU tell_object(User,
#define TRU tell_room(environment(User),
#define MAX 15                    /* Used in chan history */
#define GUILD_FILE "players/guilds/fallen/circle"
#define MASTER "players/guilds/fallen/obj/master"

