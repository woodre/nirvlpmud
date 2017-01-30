#include "/players/eurale/closed/ansi.h"
#define TPN this_player()->query_name()
#define TP this_player()
inherit "room/room";
int CLERK;

reset(arg) {
  if(arg) return;
set_light(1);
CLERK = 1;

short_desc =
  HIR+"Rain"+HIY+"bow"+NORM+
  " Inn Souvenir Shop";
long_desc =
  "The grey stone walls are lined with shelves.  Atop all the shelves\n"+
  "are boxes of various sizes.  Cobwebs hang from the corners of the\n"+
  "room and sway in the drafts that inhabit the area.  A long counter\n"+
  "stretches across the room and on the wall behind it hangs a hand-\n"+
  "lettered sign.\n";

items = ({
  "cobwebs","Large intricate designs with entombed prey attached",
  "shelves","Wooden shelves attached to the stone walls",
  "walls","Grey stone with small sparkling particles embedded",
  "sign","Written in red on a black background of polished wood.\n"+
         "Maybe you should 'read' it",
  "counter","A long beautiful wooden counter, hand rubbed with oil.\n"+
            "There is a small bell sitting on the end of the counter\n"+
            "with intricate engraving on it",
  "bell","A small, round bell used to get an employee's attention.\n"+
         "The intricate engraving encircles the bell and appears to\n"+
         "be lettering that you could read",
  "boxes","Large, medium and small boxes made of wood and cardboard",
});

dest_dir = ({
  "players/eurale/VAMPIRES/RMS/pieshop","north",
  "players/nooneelse/entryforest/e_forest0.c","east",
  "players/eurale/VAMPIRES/shop.c","west",
});

}

init() {
  ::init();
  add_action("read_sign","read");
  add_action("west","west");
  add_action("summon_clerk","ring");
}

read_sign(str) {
if(!str) { write("Read what?\n"); return 1; }
if(str == "sign") { write(RED+
" ::::::::::::::::::::: ~Souvenir Shop Policy~ :::::::::::::::::::::\n"+
" :                                                                :\n"+
" :   The Rainbow Inn Souvenir Shop is proud to offer a number of  :\n"+
" : unique gift ideas.  Please feel free to look around and if you :\n"+
" : have any questions, just 'ask' the attendant and he will be    :\n"+
" : more than happy to answer them.  We hope you find the items we :\n"+
" : sell to your liking and come back to see us again real soon.   :\n"+
" :                                                                :\n"+
" :       a rope...............................      40 coins      :\n"+
" :       fortune cookie.......................      50 coins      :\n"+
" :       Vampire Guild t-shirt................     325 coins      :\n"+
" :       Moonstone ring.......................     450 coins      :\n"+
" :       hamster cage with hamsters...........     600 coins      :\n"+
" :       oiled honing [stone]................     1000 coins      :\n"+
" :       RU784 Abortion Pill..................    1250 coins      :\n"+
" :       Maalox Tablets.......................    2800 coins      :\n"+
" :                                                                :\n"+
" : Thanks for your patronage.                                     :\n"+
" :                                       The Management           :\n"+
" :                                                                :\n"+
" ::::::::::::::::::::::::::::: ~o~ ::::::::::::::::::::::::::::::::\n"+
NORM+"\n\n");
return 1; }
if(str == "bell") {
  write("How does one read a bell?\n"); return 1; }
if(str == "engraving") {
  write("The engraving reads 'Ring bell for service'\n"); return 1; }
}

west() {
if(!present("vampire fangs",TP)) {
  write("A large black demon appears and blocks your way....\n"+
        "It hisses, 'Only vampires may use that exit!'\n\n");
  return 1; }
write("A large black demon appears to block your way....\n"+
      "but sees your fangs and fades into nothing to let you pass!\n\n");
TP->move_player("west#players/eurale/VAMPIRES/RMS/shop.c");
return 1; }

summon_clerk(str) {
if(!str) { write("Ring?\n"); return 1; }
if(str != "bell") {
  write("You ring the "+str+" but nothing happens.\n"); return 1; }
if(CLERK == 1 && str == "bell") {
  say(TPN+" softly rings the little bell.\n");
  write("You ring the little bell and a shrouded figure drifts "+
        "into the room.\n");
  move_object(clone_object("players/eurale/VAMPIRES/NPC/figure.c"),
      this_object());
  CLERK = 0;
  return 1; }
else {
  write("You softly ring the little bell.\n");
  say(TPN+" softly rings a little bell.\n");
  return 1; }
}
