#include "/obj/ansi.h"
#define GUILDNAME "neo symbiote"
#define GOB present("venom_object", USER)
#define SAVE_PATH "players/fred/closed/venom2/member/"
#define SAVE_PATH2 "players/fred/closed/venom2/member/backup/"
#define USER environment(this_object())
#define ATT USER->query_attack()
#define ATN User->query_attack()->query_name()
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

#define COLORS ({ "red", "bred", "blue", "bblue", "grey", "yellow", "byellow", "magenta", "bmagenta", "cyan", "bcyan", "green", "bgreen" })

#define CONTROL ({ "Cleanse", "Absorbi", "Burnoff", "Gtitle", "Heal", "Regeneration" })
#define COMBAT ({ "Wep", "Darts", "Fatal", "KO", "------", "Hypermode" })
#define CREATION ({ "ShapeArmor", "Alarm", "Camoflauge", "------", "CreateItem", "CreateBall" })

#define GLVLCOST ({ 3, 4, 5, 6, 7, 8, 9, 10 }) 
