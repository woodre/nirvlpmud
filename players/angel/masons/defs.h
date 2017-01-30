/* Definitions file for Masons Mini-Guild */

/* Includes */
#include <ansi.h>

/* Paths */
#define MASONSDIR "/players/angel/masons/"
#define BIN "/players/angel/masons/bin/"
#define RPATH "/players/angel/masons/room/"
#define DOCPATH "/players/angel/masons/doc/"
#define MONPATH "/players/angel/masons/npc/"
#define NPCPATH "/players/angel/masons/npc/"
#define OBJPATH "/players/angel/masons/obj/"
#define LOGPATH "/players/angel/masons/log/"
#define DATAPATH "players/angel/masons/data/"

/* Files and Objects */
#define MGOB "/players/angel/masons/mgob.c"
#define DATA "players/angel/masons/members"
#define AUTOLOAD "/players/angel/masons/mgob.c:"
#define NEWS "/players/angel/masons/doc/NEWS"
#define LOG_ADVANCE "/players/angel/masons/log/ADVANCE"
#define LOG_BANISH "/players/angel/masons/log/BANISH"
#define LOG_LOANS "/players/angel/masons/log/LOANS"
#define LOG_JOIN "/players/angel/masons/log/JOIN"
#define LOG_LEAVE "/players/angel/masons/log/LEAVE"
#define OLD_BOARD "/players/angel/masons/obj/old_board.c"
#define NEW_BOARD "/players/angel/masons/obj/new_board.c"
#define DATA_OLD_BOARD "players/angel/masons/obj/old_board"
#define DATA_NEW_BOARD "players/angel/masons/obj/new_board"
#define DATA_TREASURY "players/angel/masons/room/treasury"
#define EXIT_TO_REALM "/players/angel/area/town/room/wmain_02.c"
#define TREASURY "/players/angel/masons/room/guild_lodge.c"
#define CHANNELD "/obj/daemons/channeld.c"
#define LIGHT_OBJ "/players/angel/masons/obj/light_obj.c"

/* Misc Definitions */
#define MGOBID "masonic_seal"
#define MGOB_ID "masonic_seal"
#define CHAN "Masons"

/* Skill/Command/Etc Definitions */

/* Munch - a decorpse, costs sp, heals hp */
#define MUNCH_COST 2
#define MUNCH_HEAL 10

/* Treat - heal spell, costs 50 sp, heals hp */
#define TREAT_COST 50
#define TREAT_HEAL 20+random(20)

/* Spy - shows environment of target */
#define SPY_COST 10

/* Cast - casts a light */
#define CAST_COST 5
#define CAST_DURATION 180