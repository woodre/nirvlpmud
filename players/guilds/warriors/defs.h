#include <ansi.h>
#define SKEELLS "/players/guilds/warriors/power/"

#define PATH "/players/guilds/warriors/"
#define DOC_DIR "/players/guilds/warriors/doc/"
#define SAVE_PATH "players/guilds/warriors/member/"
#define USER environment(this_object())
#define USERRN USER->query_real_name()
#define USERN USER->query_name()
#define ENVU environment(USER)
#define UN USER->query_name()
#define TO this_object()
#define POW main(str, TO, USER)
#define attack USER->query_attack()
#define Attack User->query_attack()
#define ATT USER->query_attack()
#define ATTN ATT->query_name()
#define PO previous_object()
#define User environment(previous_object())
#define NAME USER->query_real_name()
#define Name User->query_real_name()
#define QN query_name()
#define POS query_possessive()   /*  his her  */
#define UP USER->POS
#define PRO query_pronoun()    /*  he she  */
#define UPR USER->PRO
#define OBJ query_objective()    /*  him her  */
#define UO USER->OBJ
#define TOU tell_object(User,
#define TRU tell_room(environment(User),
#define WEP USER->query_weapon()
#define WEPN WEP->query_name()
#define WEPSH WEP->short()
