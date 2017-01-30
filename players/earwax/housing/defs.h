#include "/players/earwax/lib/ansi.h"

/* Settings */
#define SMALL 19
#define MEDIUM 30
#define LARGE 75
#include "upgrades.h"

/* Inherits */
#define LAND "/players/earwax/housing/land.c"
#define HROOM "/players/earwax/housing/house_room.c"

/* Daemons */
#define LANDD "/players/earwax/housing/land_daemon.c"
#define WAXFUNS "/players/earwax/lib/waxfuns.c"
#define MISCD "/players/earwax/housing/sort_daemon.c"
#define UTILITYD "/players/earwax/housing/sort_daemon.c"
#define HOUSED "/players/earwax/housing/house_daemon.c"
#define ANSI_PARSER "/players/earwax/lib/color_parser.c"

/* Objects */
#define HOUSE_OB "/players/earwax/housing/house_object.c"

/* ID's and Misc */
#define HOUSING_OBJECT_ID "EARWAXIAN_HOUSING_OBJECT_ID_GOES_HERE"
#define BANK "/players/earwax/bank/bank.c"
#define HAH "/players/earwax/housing/room_storage_room.c"
#define TEMPLATE "/players/earwax/housing/room_template.c"
#define UPGRADES "/players/earwax/housing/upgrades.txt"

/* Paths */
#define DATA "/players/earwax/housing/data/"
#define BIN "/players/earwax/housing/bin/"
#define HELPDIR "/players/earwax/housing/help/"

/* Data Files */
#define LANDDATA "/players/earwax/housing/land_data.o"
#define LANDSAVE "players/earwax/housing/land_data"
#define LANDRESTORE "players/earwax/housing/land_data"

/* Logs */
#define BUG "/players/earwax/housing/log/BUG"
#define BUG_CLONE_LOG "/players/earwax/housing/log/BUG_CLONE_LOG"
#define REGISTER "/players/earwax/housing/log/REGISTER"
#define HOUSE_CLONE "/players/earwax/housing/log/HOUSE_CLONE"
#define NOREGISTER "/players/earwax/housing/log/NOREGISTER"
#define REGISTERED "/players/earwax/housing/log/REGISTERED"
#define DIRS "/players/earwax/housing/log/DIRS"
#define BOUGHT "/players/earwax/housing/log/BOUGHT"
#define SELL "/players/earwax/housing/log/SELL"
#define INTEGRITY "/players/earwax/housing/log/INTEGRITY"

/* Backups */
#define LANDBAK1 "/players/earwax/housing/bak/landbak1"
#define LANDBAK2 "/players/earwax/housing/bak/landbak2"
#define LANDBAK3 "/players/earwax/housing/bak/landbak3"
