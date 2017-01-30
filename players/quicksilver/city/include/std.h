/* paths */
#define HOME_DIR		"players/quicksilver/"
#define CLOSED_DIR		HOME_DIR + "closed/"
#define BASE_DIR		HOME_DIR + "city/"

#define DOC_DIR			BASE_DIR + "doc/"
#define ETC_DIR			BASE_DIR + "etc/"
#define INC_DIR			BASE_DIR + "include/"
#define LOG_DIR			BASE_DIR + "log/"
#define CRE_DIR			BASE_DIR + "cre/"
#define ROOM_DIR		BASE_DIR + "r/"
#define OBJ_DIR			BASE_DIR + "obj/"
#define ARMOR_DIR		OBJ_DIR + "arm/"
#define WEAPON_DIR		OBJ_DIR + "weap/"
#define HEAL_DIR		OBJ_DIR + "heal/"


/* Standard Objects -- Inheritables */
#define ROOM			"room/room"
#define MONSTER			BASE_DIR + "include/monster_ext"
#define WEAPON			BASE_DIR + "include/weapon_ext"
#define ARMOR			"obj/armor"


/* Commonly used defines */
#define NAME query_name()
#define TP this_player()
#define TO this_object()
#define ENVTO environment(this_object())
#define ENVTP environment(this_player())