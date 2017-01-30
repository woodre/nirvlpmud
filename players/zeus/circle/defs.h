#include <ansi.h>

#define GUILDNAME "fallen"
#define CMDDIR "/players/zeus/circle/power/"
#define SAVE_PATH "players/zeus/closed/circle_member/"
#define SAVE_PATH2 "players/zeus/closed/circle_member/backup/"
#define UPDATE_PATH "/players/zeus/circle/misc/UPDATE"
#define USER environment(this_object())
#define attack USER->query_attack()
#define Attack User->query_attack()
#define PO previous_object()
#define User environment(previous_object())
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
#define GUILD_FILE "players/zeus/circle/circle"
#define MASTER "players/zeus/circle/obj/master"

