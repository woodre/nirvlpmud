/* Boardwalk, outside The Wharf/Dock, Created <5/2/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The boardwalk";
  long_desc=
    "  A cabin stands to the north of the boardwalk, connected by a narrow\n"+
    "plank. The building is made of brick and wood, and smoke comes from a\n"+
    "red brick chimney atop the roof. Two front windows border the door,\n"+
    "curtained and closed tightly against the wind. A pier extends south\n"+
    "into the wather, held up by massive wooden pilings.\n";
  items=({
    "pilings",
    "The thick, wooden posts hold the pier up from the waters",
    "door",
    "A wooden door, with a window in the center. The door handle is silver in color",
    "plants",
    "Small weeds that grow around the base of the building and the frame of the door",
    "chimney",
    "The upper portion of the brick chimney has become blackened by soot, and a\n"+
    "small curl of smoke comes from the chimney",
    "windows",
    "The windows each hold four panes and are curtained with darkly colored cloths",
    "cabin",
    "The cabin is old and somewhat worn down. Small plants have taken root beneath\n"+
    "the frame of the door",
    "plank",
    "A narrow, wooden plank. It extends from the boardwalk, up the beach, and to\n"+
    "the doorway of the cabin",
    "pier",
    "A wooden pier, built of wooden planks and posts" });
  dest_dir=({
    PATH+"walk0","east",
    PATH+"walk3","west",
    PATH+"dock1","south",
    PATH+"wharf1","enter" });
}
