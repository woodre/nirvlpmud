inherit "players/illarion/room";
#include "/players/illarion/dfns.h"
void reset(int arg) {
  if(arg) return;
  set_light(1);
  set_short("The refurbished hold of a barge");
  set_long(
"The inside of a cargo barge has been extensively refitted, by someone with "+
"good, if rather antique taste.  On the north end of a room, a bookcase "+
"stands next to a slight step up to the door.  Along either wall, some "+
"smallish portholes alternate with some smallish painting and drawings, "+
"just above some shorter bookcases and a couple of antique chests.  About " +
"midway through the barge, a couch forms a division between this part of "+
"of the barge, and the rest, further south.");
  add_item("chests","Old, carved chest, closed and locked, but giving off"
                   +"a definate sense of age.");
  add_item("bookshelves","A variety of antique bookshelves, neatly arranged "
                        +"with books and other small, valuable objects.");
  add_item("books","A variety of history and the classics.  A lot of the "
                  +"titles seem to have something to do with Scotland.");
  add_item("knick-knacks","Paperweights, bookends, and a variety of other "
                         +"small, beautiful, and old objects, including the "
                         +"occasional dagger.");
  add_item("couch","A wide couch, upolstered in soft leather, but mounted on "
                  +"an antique frame.  Beyond it you see bedroom "
                  +"furnishings.");
  add_item("portholes","On the western side of the barge, the portholes "
                      +"show only stone, but on the eastern side the look "
                      +"out over a river.");
  add_item("paintings","Paintings of everything from Scottish mountains to "
                      +"a Japanese flower.");
  add_item("drawings","A number of hand drawings, including one of a "
                     +"smiling, remarkably attractive woman.  A caption at "
                     +"the bottom reads simply, \"Tessa\".  You feel an "
                     +"urge to "+BLD("study")+" the drawing.");

  add_exit("up",HROOM+"bargetop");
  add_exit("south",HROOM+"inbarge2");
}
void init() {
  ::init();
  add_action("cmd_study","study");
}
int cmd_study(string str) {
  if(!str || str != "drawing")
    FAIL("Study what?\n");
  write("You study the picture intently, and a brief series of images\n"+
        "flashes through your head, but before you can make any sense\n"+
        "of them, they're gone.\n");
  say(TPN+" stares intently at one of the drawings for a moment.\n");
  return 1;
}
