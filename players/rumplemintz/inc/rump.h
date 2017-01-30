/*
 * rump.h
 * Rumplemintz@Nirvana
 */

// The following precompiler check is useful to prevent accidental reincluding
// of this include file.  We simply check for a nonambiguous identifier, and
// if it isn't defined yet, we'll define it and do our includes and other
// defines

#ifndef _rump_h_
#define _rump_h_

//
// The Include section
// We include this stuff here, so that we don't have to include all of this
// in each single file

#include <grammar.h>          // This is for parser rule defines
#include <describe.h>         // This provides macros for describe()
#include <message.h>          // All the message tokens are defined here
#include <event.h>            // Event tokens can be found here
#include <wizlevels.h>        // Macros for wizard levels
#include <prop/room.h>        // Room properties
#include <prop/item.h>        // Item properties
#include <light.h>            // Lightlevels we perhaps need

//
// The Define section
// Although defines make it harder to understand or debug code from someone
// else, few are quite useful.  Such useful defines are path and class macros

#define RUMP_HOME  "/players/rumplemintz/"      // Our home path
#define RUMP_CLASS RUMP_HOME"class/"            // The class directory
#define RUMP_DOC   RUMP_HOME"doc/"              // Documentation
#define RUMP_ETC   RUMP_HOME"etc/"              // Miscellaneous stuff
#define RUMP_LIB   RUMP_HOME"lib/"              // The library directory
#define RUMP_LOG   RUMP_HOME"log/"              // Logfiles go here
#define RUMP_NPCS  RUMP_HOME"npc/"              // NPCs reside here
#define RUMP_OBJ   RUMP_HOME"obj/"              // All items reside here
#define RUMP_ROOMS RUMP_HOME"room/"             // Rooms can be found here

#define RUMP_ROOM  RUMP_CLASS"room"             // The room class
#define RUMP_NPC   RUMP_CLASS"npc"              // The NPC class

#endif
