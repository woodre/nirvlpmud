/******************************************************************************
 * examples.h
 * Rumplemintz@Nirvana
******************************************************************************/

// The following precompiler check is useful to prevent accidental reincluding
// of this include file.  We simply check for a nonambiguous identifier, and
// if it isn't defined yet, we'll define it and do our includes and other
// defines.

#ifndef _examples_h_
#define _examples_h_

///////////////////////////////////////////////////////////////////////////////
// The INCLUDE SECTION.  We include this stuff here, so that we don't have   //
// to include all of this in each single file.                               //
///////////////////////////////////////////////////////////////////////////////

#include <grammar.h>             // This is for parser rule defines.
#include <describe.h>            // This provides macros for describe().
#include <message.h>             // All the message tokens are defined here.
#include <event.h>               // Event tokens can be found here.
#include <wizlevels.h>           // Macros for wizard levels go here.

#include <prop/room.h>           // This is for room properties.
#include <prop/item.h>           // And this for item properties.
#include <light.h>               // Lightlevels, we perhaps need.

///////////////////////////////////////////////////////////////////////////////
// The DEFINE SECTION.  Although defines make it harder to understand or     //
// debug code from someone else, few are quite useful.  Such useful defines  //
// are path and class macros.                                                //
///////////////////////////////////////////////////////////////////////////////

#define EXAMPLES_HOME "/players/examples/"    // Our home path.

#define EXAMPLES_CLASS EXAMPLES_HOME"class/"  // The class directory.
#define EXAMPLES_DOC   EXAMPLES_HOME"doc/"    // The documentation directory.
#define EXAMPLES_ETC   EXAMPLES_HOME"etc/"    // Miscellaneous stuff.
#define EXAMPLES_LIB   EXAMPLES_HOME"lib/"    // The library directory.
#define EXAMPLES_LOG   EXAMPLES_HOME"log/"    // Logfiles go here.
#define EXAMPLES_NPCS  EXAMPLES_HOME"npc/"    // NPCs reside in this directory.
#define EXAMPLES_OBJ   EXAMPLES_HOME"obj/"    // All items reside here.
#define EXAMPLES_ROOMS EXAMPLES_HOME"room/"   // Rooms can be found here.

#define EXAMPLES_ROOM  EXAMPLES_CLASS"room"   // The room class.
#define EXAMPLES_NPC   EXAMPLES_CLASS"npc"    // The NPC class.

// It's not recommended to define macros which abbreviate functions, like
//
// #define TP this_player()
// #define TPQVN this_player()->query_vis_name()
// #define WEBIER(a,b,c) write(extract(break_string(implode(explode(...)))))
//
// These make it almost impossible to read and debug code, especially if it
// isn't your own.  So please refrain from doing that.

#endif /* _examples_h_ */

