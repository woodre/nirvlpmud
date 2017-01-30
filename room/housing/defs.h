#include <ansi.h>
#include "upgrades.h"

/* Settings */
#define SMALL  19
#define MEDIUM 30
#define LARGE  75

/* Inherits */
#define LAND  "/room/housing/land.c"
#define HROOM "/room/housing/house_room.c"

/* Daemons */
#define LANDD       "/room/housing/land_daemon.c"
#define WAXFUNS     "/obj/user/waxfuns.c"
#define MISCD       "/room/housing/sort_daemon.c"
#define UTILITYD    "/room/housing/sort_daemon.c"
#define HOUSED      "/room/housing/house_daemon.c"
#define ANSI_PARSER "/obj/user/color_parser.c"

/* Objects */
#define HOUSE_OB "/room/housing/house_object.c"

/* ID's and Misc */
#define HOUSING_OBJECT_ID "EARWAXIAN_HOUSING_OBJECT_ID_GOES_HERE"

#define BANK     "/room/bank/bank.c"
#define HAH      "/room/housing/room_storage_room.c"
#define TEMPLATE "/room/housing/room_template.c"
#define UPGRADES "/room/housing/upgrades.txt"

/* Paths */
#define DATA        "/room/housing/data/"
#define BIN         "/room/housing/bin/"
#define HELPDIR     "/room/housing/help/"

/* Data Files */
#define LANDDATA    "/room/housing/land_data.o"
#define LANDSAVE    "room/housing/land_data"
#define LANDRESTORE "room/housing/land_data"

/* Logs */
#define BUG           "/room/housing/log/BUG"
#define BUG_CLONE_LOG "/room/housing/log/BUG_CLONE_LOG"
#define REGISTER      "/room/housing/log/REGISTER"
#define HOUSE_CLONE   "/room/housing/log/HOUSE_CLONE"
#define NOREGISTER    "/room/housing/log/NOREGISTER"
#define REGISTERED    "/room/housing/log/REGISTERED"
#define DIRS          "/room/housing/log/DIRS"
#define BOUGHT        "/room/housing/log/BOUGHT"
#define SELL          "/room/housing/log/SELL"

/* Backups */
#define LANDBAK1 "/room/housing/bak/landbak1"
#define LANDBAK2 "/room/housing/bak/landbak2"
#define LANDBAK3 "/room/housing/bak/landbak3"
