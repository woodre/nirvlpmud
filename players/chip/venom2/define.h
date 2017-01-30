#define SKEELLS "/players/chip/venom2/power/"

#define GUILDNAME "neo symbiote"
#define GUILDFILE "/players/chip/venom2/neo_venom.c"

#define SAVE_PATH "players/chip/closed/save/"
#define SAVE_PATH2 "players/chip/venom2/member/"
#define USER environment(this_object())
#define ENVU environment(USER)
#define UN USER->query_name()
#define attack USER->query_attack()
#define Attack User->query_attack()
#define ATT USER->query_attack()
#define ATTN ATT->query_name()
#define PO previous_object()
#define User environment(previous_object())
#define CAP capitalize
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
#define TOM tell_object(USER,
#define TRU tell_room(environment(User),
#define COLOR query_color()
#define GOB present("new_venom_object", USER)
