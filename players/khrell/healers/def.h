#include <ansi.h>

#define ROOT       "players/khrell/healers/"
#define HOME_H     "/"+ROOT+"room/hall.c"
#define POWER      "/"+ROOT+"guilddaem"
#define SHADE      ROOT+"shade.c"
#define MEM        ROOT+"member/"

#define FLAGCOUNT  10
#define FLAGRND    7

#define TO         this_object()
#define TP         this_player()
#define ENV        environment(TO)
#define QN         query_name()
#define RN         query_real_name()
#define POS        query_possessive()
#define ATT        ENV->query_attack()
#define LVL        query_level()
#define EXLVL      query_extra_level()
#define EXP        query_exp()
#define SP         query_sp()
#define HP         query_hp()
#define MHP        query_mhp()
#define MSP        query_msp()
#define PIE        query_attrib("pie")
#define GHOST      query_ghost()


#define RO         restore_object(MEM+TP->RN)
#define SO         save_object(MEM+TP->RN)
#define SOE        save_object(MEM+ENV->RN);
#define GOB        present("mythos_healer", TP)
