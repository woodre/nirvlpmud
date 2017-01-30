/* Main definition file for the Shadow Continent area */

/* Path Definitions */
#ifndef HOME
#define HOME "/players/sparrow"
#ifndef AREAS
#define AREAS HOME+"/areas"
#ifndef SC_HOME
#define SC_HOME AREAS+"/shadow_cont"
#ifndef SC_OBJ
#define SC_OBJ SC_HOME+"/objects"
#ifndef SC_NPC
#define SC_NPC SC_HOME+"/npcs"
#ifndef SC_HLS
#define SC_HLS SC_HOME+"/heals"
#ifndef SC_ARM
#define SC_ARM SC_HOME+"/armors"
#ifndef SC_WEP
#define SC_WEP SC_HOME+"/weapons"
#ifndef SC_RMS
#define SC_RMS SC_HOME+"/rooms"
#ifndef SC_INC
#define SC_INC SC_HOME+"/includes"

/* Map Definitions */
#ifndef MAPPATH
#define MAPPATH SC_INC+"/maps"

/* Map Key */
#ifndef KEY_SYMBOL
#define KEY_SYMBOL ({"*","@","~","^","M",":","E"})
#ifndef KEY_VALUES
#define KEY_VALUES ({WHITE+"*"+NORM,HIK+"@"+NORM,HIB+"~"+NORM,YELLOW+"^"+NORM,
  HIK+"M"+NORM})