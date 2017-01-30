inherit "room/room";
#include "/players/persephone/rooms2.h"
reset (arg){
 set_light(1);
 short_desc="A moss covered path";
 long_desc="The moss covered path continues to your North you see a fence" + LF
           "and from behind the fence you can hear what seems to be noise" + LF
           "from an amusement park. To the south you see a tower wall while" + LF
           "the path continues west and back to the East from whence you came" + LZ
 dest_dir=({"players/nancy/rooms/pathc","west",
            "players/nancy/rooms/patha","east"});
}
