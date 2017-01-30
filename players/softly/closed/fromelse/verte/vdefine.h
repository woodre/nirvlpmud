
#include "/players/vertebraker/ansi.h"

#define DAE_DIR "players/vertebraker/daemons/"
#define ROOM "/players/vertebraker/closed/std/room";
#define WEAPON "obj/weapon";
#define TREASURE "obj/treasure";
#define MONSTER "obj/monster";
#define ARMOUR "obj/armor";
#define NPC "obj/monster";
#define TP this_player()
#define TO this_object()
#define ENV environment
#define TPN this_player()->query_name()
#define TPRN this_player()->query_real_name()
#define CAP capitalize
#define LOWER lower_case
#define POS TP->query_possessive()
#define MOCO move_object(clone_object
#define USER ENV(TO)
#define OBJ TP->query_objective()
#define QN query_name()
#define RN query_real_name()
#define LEV query_level()
#define HP query_hp()
#define SP query_sp()
#define MO move_object
#define CO clone_object
#define MP move_player
#define LVL TP->query_level()
#define STRENGTH TP->query_attrib("str")
#define STAMINA TP->query_attrib("sta")
#define STEALTH TP->query_attrib("ste")
#define MAGIC TP->query_attrib("mag")
#define WILLPOWER TP->query_attrib("wil")
#define PIETY TP->query_attrib("pie")
#define INTELLIGENCE TP->query_attrib("int")
#define LUCK TP->query_attrib("luc")
#define ALIGNMENT TP->query_alignment()
#define FAIL notify_fail
#define Q HIW+"\""+NORM
#define GUIDE "/players/vertebraker/closed/std/monster_guide.c"
#define GUIDE_HP GUIDE->get_value("hp")
#define PO previous_object()
#define TPL TP->query_level()
#define EUSER environment(USER)
#define GUIDE_WC GUIDE->get_value("wc")
#define GUIDE_AC GUIDE->get_value("ac")
#define CASINO "/players/vertebraker/casino/"