/* Main definition file for the Shadow Continent area */

/* Path Definitions */
#ifndef HOME
#define HOME "/players/sparrow"
#endif
#ifndef AREAS
#define AREAS HOME+"/areas"
#endif
#ifndef SC_HOME
#define SC_HOME AREAS+"/shadow_cont"
#endif
#ifndef SC_OBJ
#define SC_OBJ SC_HOME+"/objects"
#endif
#ifndef SC_NPC
#define SC_NPC SC_HOME+"/npcs"
#endif
#ifndef SC_HLS
#define SC_HLS SC_HOME+"/heals"
#endif
#ifndef SC_ARM
#define SC_ARM SC_HOME+"/armors"
#endif
#ifndef SC_WEP
#define SC_WEP SC_HOME+"/weapons"
#endif
#ifndef SC_RMS
#define SC_RMS SC_HOME+"/rooms"
#endif
#ifndef SC_INC
#define SC_INC SC_HOME+"/includes"
#endif
#ifndef MAPPATH
#define MAPPATH SC_INC+"/maps"
#endif
#ifndef BLUEPRINT
#define BLUEPRINT SC_RMS+"/sc_room.c"
#endif

/* Map Dimensions */
#ifndef MAP_X
#define MAP_X 63
#endif
#ifndef MAP_Y
#define MAP_Y 41
#endif

/* Map Key */
#ifndef KEY_SYMBOL
#define KEY_SYMBOL ({"*","@","~","^","M",":"})
#endif
#ifndef KEY_VALUES
#define KEY_VALUES ({WHITE+"*"+NORM,HIK+"@"+NORM,HIB+"~"+NORM,YELLOW+"^"+NORM,HIK+"M"+NORM,HIG+":"+NORM})
#endif
#ifndef SHORT_SYMBOL
#define SHORT_SYMBOL KEY_SYMBOL
#endif
#ifndef SHORT_VALUES
#define SHORT_VALUES ({"Frozen Wastes of Vragoth","Black Willow Forest","Water","Foothills","Impassable Mountains","Vast Shadow Plains"})
#endif
#ifndef KEY_IMPASS
#define KEY_IMPASS ({"M","~"})
#endif