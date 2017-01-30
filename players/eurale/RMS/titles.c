/* fixed 4-11-01 by verte */

#define TPG this_player()->query_gender()
#include "/players/eurale/defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Nirvana Titles Room";
long_desc =
  "A large circle on the floor marks the spot where Nirvana players\n"+
  "can get their appropriate Nirvana title.  Curved, stone walls\n"+
  "surround you with arched doors leading out of the room to the south\n"+
  "and west.  A small sign is attached to the rear wall.\n";

items = ({
  "sign","A polished brass sign with fire red letters you can read",
  "circle","A red circle in smooth tile",
  "walls","Stones set in mortar, making a round room",
  "doors","Large, wide doors providing entry/exit from the room",
});

dest_dir = ({
  "players/eurale/RMS/warp","south",
  "players/eurale/RMS/barter","west",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("Fix_titles","fix_title");
  add_action("read","read");
}

Fix_titles() {
  int l, x;
  object foo;

write(
  "You whisper the words to change your title and a light blue mist\n"+
  "seeps up from the floor inside the circle, enveloping you.  There\n"+
  "is a strange but pleasant sensation... and then the mist clears.\n\n");
say(capitalize(TPN)+" is enveloped in a light blue mist...\n"+
    "And then as quickly as it appeared, it disappears.\n");

    l = (int)(foo = this_player())->query_level();
    x = (int)foo->query_extra_level();

    if(l > 4 && l < 20 && !x)
    {
      "/room/adv_guild"->get_level(l - 1);
      foo->set_title((string)"/room/adv_guild"->get_new_title(l - 1));
    }

    else if(l == 19 && x > 0)
      foo->set_title((string)"/room/exlv_guild"->get_new_title(x - 1, foo));

    else
      write("\
A voice whispers, 'you are too small to worry about your title,\n"+
   "go out and EXP and you will be bigger in a short while.'\n");

   return 1;
}

read(str) {
if(!str) { write("A voice whispers, 'Read what?'\n"); return 1; }
if(str == "sign") { write(
BOLD+"Nirvana Titles Room"+NORM+"\n\n"+
"There are times when a player finds themself stuck with a title\n"+
"that they either don't deserve or don't want.  Maybe they have just\n"+
"left a guild or retreated from a tough fight.  This magical room\n"+
"allows any player to change their title to the appropriate Nirvana\n"+
"title just by typing:  "+HIR+"fix_title"+NORM+".\n\n"+
"There is no cost to the player and the titles will not be custom in\n"+
"any way.\n");
return 1; }
}