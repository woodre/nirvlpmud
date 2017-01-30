#ifndef  _DEF_H_
#define  _DEF_H_

#include "COLOR.h"


/* General */
#define PATH       "/players/dune/closed/pavilion/"
#define CMDDIR     (PATH+"cmds/")
#define LOGDIR     (PATH+"logs/")
#define GUILD_ID   "_cockpit_"
#define OVERHEAT_ID "_system_cooldown_"

/* Daemon Objects */
#define DAEMDIR      (PATH+"daemons/")
#define ACTIOND      (DAEMDIR+"actions.c")
#define MORED        (DAEMDIR+"_more.c")
#define ROBOD        (DAEMDIR+"robo.c")

/* Macros */
#define TP     this_player()
#define ETO    environment(this_object())
#define ETP    environment(this_player())
#define IPTP   present(GUILD_ID, ETP)
#define IPOB   present(GUILD_ID, environment(ob))
#define ETN    capitalize((string)ETO->query_name())
#define TPN    capitalize((string)TP->query_name())
#define OPN    capitalize((string)ob->query_name())
#define TRN    capitalize((string)TP->query_real_name())
#define ORN    capitalize((string)ob->query_real_name())
#define POS    query_possessive()
#define MEAT   (TP->query_attack())
#define MEAN   capitalize((string)(MEAT->query_name()))
#define ROOM   environment(ETP)

#endif
