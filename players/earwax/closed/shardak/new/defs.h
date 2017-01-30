/* Includes */
#include "/players/earwax/lib/ansi.h"

/* Inheritables */
#define WAXFUNS "/players/earwax/lib/waxfuns"
#define CMDBASE "/players/earwax/closed/shardak/new/lib/cmdbase"

/* Daemons */
#define CHANNELD "/players/earwax/closed/shardak/new/daemons/channeld.c"
#define COMMANDSD "/players/earwax/closed/shardak/new/daemons/commands.c"

/* Paths */
#define BINDIR "/players/earwax/closed/shardak/new/bin/"
#define EMOTESDIR "/players/earwax/closed/shardak/new/bin/Emotes/"
#define SPELLSDIR "/players/earwax/closed/shardak/new/bin/Spells/"
#define MAGUSDIR "/players/earwax/closed/shardak/new/bin/Magus/"
#define MISCDIR "/players/earwax/closed/shardak/new/bin/Misc/"
#define LEADERDIR "/players/earwax/closed/shardak/new/bin/Leader"
#define STATSPATH "players/earwax/closed/shardak/new/save/"
#define LOGDIR "/players/earwax/closed/shardak/new/log/"
#define SAVEPATH "players/earwax/closed/shardak/new/data/"
#define DAEMONDATA "players/earwax/closed/shardak/new/daemons/data/"

/* Logs */
#define CHAT_LOG "/players/earwax/closed/shardak/new/log/gt"
#define BADCLONE "/players/earwax/closed/shardak/new/log/badclone"
#define BUGLOG "/players/earwax/closed/shardak/new/log/cbug"

/* Objects */
#define AUTOLOAD "/players/earwax/closed/shardak/new/gob/loader:0"
#define GOB "/players/earwax/closed/shardak/new/gob/gob.c"

/* Misc */
#define GOB_ID "Guild_Object_For_Shardak_Recode"
#define NEWS "/players/earwax/closed/shardak/new/notes/news"
#define BADCMD "/players/earwax/closed/shardak/new/bin/Misc/errormsg.c"

/* Channels - Temporary until I finish the channel daemon */
#define GT_FORMAT RED+"(+"+HIK+"Servants"+NORM+RED+"+) "+NORM+NORM
#define GD_FORMAT HIR+"[+"+HIK+"Daemon"+NORM+HIR+"+] "+NORM+NORM
#define GPT_FORMAT HIR+"(+"+HIK+"Servants"+NORM+HIR+"+) "+NORM+NORM

/* Guild Magi */
#define MAGI ({ "earwax", "linus", "forbin", "mosobp", "jaraxle"})
#define ALLOW_CLONE MAGI + ({ "wocket", "vital" })

#define TESTCHARS ({ "waxman", "linusjr", "fortest", "moso" })

/* Guild Levels and Ranks */
#define MAGUS 50
#define GUEST 45

/* Guild Stats */
#define NUM_STATS 12

#define ARCANA 0
#define MAGIK 1
#define CONFLAGRATION 2
#define RANCOR 3
#define FERVOR 4
#define DOMINATION 5
#define SUBJUGATION 6
#define WRATH 7
#define ARC 0
#define MGK 1
#define CON 2
#define RAN 3
#define FER 4
#define DOM 5
#define SUB 6
#define WRA 7
#define GLEVEL 8
#define GRANK 9
#define SAC_POOL 10
#define GEXP 11

/* Guild Task Definitions */
#define TASK_ID "ID"
