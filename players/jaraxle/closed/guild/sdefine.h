#define POWER "/players/jaraxle/closed/guild/power/"

#define GUILDNAME "geomancer"

#define SAVE_PATH "players/jaraxle/closed/guild/members/"
#define SAVE_PATH2 "players/jaraxle/closed/guild/members/backup/"
#define USER player
#define ENV environment(USER)
#define UN USER->query_name()
#define ATT USER->query_attack()
#define ATTN ATT->query_name()
#define PO previous_object()
#define NAME USER->query_real_name()
#define QN query_name()
#define POS query_possessive()   /*  his her  */
#define UP USER->POS
#define PRO query_pronoun()    /*  he she  */
#define UPR USER->PRO
#define OBJ query_objective()    /*  him her  */
#define MHP USER->query_mhp()
#define HP USER->query_hp()
#define SP USER->query_sp()
#define MSP USER->query_msp()
#define GOB gob
#define LEVEL USER->query_level()
#define XLEVEL USER->query_extra_level()
#define UO USER->OBJ
#define TOU tell_object(User,
#define TRU tell_room(environment(User),
