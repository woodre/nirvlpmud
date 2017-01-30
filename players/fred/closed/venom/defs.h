#include "/obj/ansi.h"
#define GUILDNAME "symbiote"
#define GOB present("venom_object", USER)
#define SAVE_PATH "players/fred/closed/venom/member/"
#define SAVE_PATH2 "players/fred/closed/venom/member/backup/"
#define USER environment(this_object())
#define ATT USER->query_attack()
#define GHOST User->query_ghost()
#define NAME USER->query_real_name()
#define QN query_name()
#define QRN query_real_name()
#define POS query_possessive()   /*  his her  */
#define PRO query_pronoun()    /*  he she  */
#define OBJ query_objective()    /*  him her  */
#define TOU tell_object(User,
#define TRU tell_room(environment(User),
#define TOM tell_object(USER,
#define TRM tell_room(ENV(USER),
#define TP this_player()
#define TO this_object()
#define ENV environment
#define QL query_level()
#define QEL query_extra_level()
#define CAP capitalize
#define STR (int)User->query_attrib("str")
#define STA (int)User->query_attrib("sta")
#define INT (int)User->query_attrib("int")
#define DEX (int)User->query_attrib("dex")
#define WIL (int)User->query_attrib("wil")
#define MAGIC (int)User->query_attrib("mag")
#define LUC (int)User->query_attrib("luc")
#define CHA (int)User->query_attrib("cha")
#define PIE (int)User->query_attrib("pie")
#define STE (int)User->query_attrib("ste")

#define BETA ({ "ribbit", "keeper", "webslinger", "tembo", "madness", "toy" })

#define FIXES "/players/fred/closed/venom/logs/fixes"
