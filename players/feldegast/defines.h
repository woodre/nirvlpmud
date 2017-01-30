#ifndef _FELD_DEFS
#define _FELD_DEFS
#include <ansi.h>

/* Shortcuts */
#define TP this_player()
#define TPN (string)this_player()->query_name()
#define TPRN capitalize((string)this_player()->query_real_name())
#define AT attacker_ob
#define AN attacker_ob->query_name()
#define ENV environment(this_player())
#define ENVO environment(this_object())
#define TON this_object()->query_name()
#define QN query_name()
#define TPG1 (string)this_player()->query_pronoun()
#define TPG2 (string)this_player()->query_possessive()

/* Generic objects */
#define ROOM "/players/feldegast/std/room"
#define MONSTER "/players/feldegast/std/monster.c"
#define DOOR "/players/feldegast/std/door.c"
#define CHANNEL "/players/feldegast/std/channel"

/* Paths */
#define ROOT "/players/feldegast/"
#define HEAL_PATH "/players/feldegast/heals/"
#define MON_PATH "/players/feldegast/mon/"
#define WEP_PATH "/players/feldegast/wep/"
#define ARM_PATH "/players/feldegast/equip/"
#define OBJ_PATH "/players/feldegast/obj/"
#define LOG_PATH "/players/feldegast/log/"

/* Debugging */
#define FTELL(x) if(find_player("feldegast")) tell_object(find_player("feldegast"),x);

#endif
