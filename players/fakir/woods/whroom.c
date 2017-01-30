#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
#include "/players/fakir/color.h"
inherit "room/room";
int found;

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = RED+"Way-Gates"+OFF;
long_desc =
RED+"You have entered the Wheel of Time, and now stand before way-gates\n\n"+
"leading to areas of exploration, adventure, and surprise.  You may seek\n\n"+
"out information on the various areas by looking at them.  To transport\n\n"+
"through a way-gate, simply 'touch' the area you wish to visit."+OFF+"\n\n\n"+
"      Winespring Inn "+CYAN+"(inn)"+OFF+"        Whispering Woods "+BROWN+"(woods)"+OFF+"\n\n\n";


items = ({
"inn",    "The Winespring Inn is a comfortable old style tavern.  It\n"+
          "is an area players of all levels can visit, though some of\n"+
          "the characters there will be too powerful for those of a\n"+
          "lower level",
"woods",  "The Whispering Woods is an area inhabited by fairy folk and\n"+
          "an occasional woodland or forest creature.  It is intended\n"+
          "for players of level one to ten.  Those of higher level will\n"+
          "not be allowed to enter.  Players who take the time to read\n"+
          "and explore will recieve the most benefit from the area",


});

dest_dir = ({
   "/room/eastroad5.c", "wheel",
   
});
}

init()  {
  ::init();
    add_action("touch_inn","touch");
}

touch_inn(str)  {

  if(str == "inn") {
    tell_room("players/fakir/inn/room1.c", this_player()->query_name()+" arrives.\n");
    move_object(this_player(),"/players/fakir/inn/room1.c");
    command("look",this_player());
    return 1;
  }
  if(str == "woods") {
    tell_room("players/fakir/woods/room1.c", this_player()->query_name()+" arrives.\n");
    move_object(this_player(),"/players/fakir/woods/room1.c");
    command("look",this_player());
    return 1;
  }
  notify_fail("That will get you nowhere fast!\n");
  return 0;
}
