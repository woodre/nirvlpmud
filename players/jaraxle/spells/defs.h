#define SAVE_PATH "players/maledicta/closed/member/"
#define USER environment(this_object())
#define ATTACK USER->query_attack()
#define ALTATT USER->query_alt_attack()
#define PO previous_object()
#define NAME USER->query_real_name()
#define QN query_name()
#define POS query_possessive()   /*  his her  */
#define PRO query_pronoun()    /*  he she  */
#define OBJ query_objective()    /*  him her  */
#define TOU tell_object(USER,
#define TRU tell_room(environment(USER),
#define TP this_player()