inherit "players/illarion/room";
#include "/players/illarion/dfns.h"

void reset(int arg) {
  if(arg) return;
  
  set_light(1);
  set_short("The back room of Joe's Bar");
  set_long(
     "At first glance this would seem a typical storeroom, with its large "
    +"racks of materials for restaurant use, but the extreme back has more "
    +"of the look of an office or study.  A large desk set against the wall "
    +"is flanked on one side by a file cabinet, and on the other by a large "
    +"bookshelf.  Atop the desk sits a modern-looking computer.  The only "
    +"exit seems to be back into the bar, to the west.");
  
  add_item("racks","Huge steel and wood shelf constructions, with various "
                  +"boxes filled with materials for the bar.");
  add_item("desk","The desk is made of wood, with two colums of drawers "
                 +"supporting the top.  On each drawer is a keyhole.");
  add_item("cabinet","A typical metal file cabinet, with three drawers.  "
                    +"Although the drawers are unmarked, each is locked "
                    +"securely.");
  add_item("bookshelf","Strangely, the books on the bookshelf don't seem "
                      +"to have anything to do with the bar.  You don't "
                      +"understand the language of most of the titles, but "
                      +"closer inspection might reveal the names of a few.");
  add_item("titles","The most you can make out is that the titles are mostly "
                   +"in some sort of code.  Only one book seems not to be "
                   +"encrypted: \"An introduction to Immortals and "
                   +"Watchers\".  "+BLD("Read")+"ing it might give you some\n" 
                   +"more information about this place.\n");
  add_item("computer","This appears to be almost the latest in personal "
                      +"computers, with a modem and CD-ROM.");
                      
  add_exit("west",HROOM+"atbar");
}
void init() {
  ::init();
  add_action("cmd_read","read");
}
int cmd_read(string str) {
  if(!str || (str !="book" && str!="introduction"))
    FAIL("Read what?\n");
  write("You page through the book, skimming out the important parts.\n");
  write("It seems that the writers of this book believe that men and women\n"
       +"roam the earth that are all but immortal; not aging, and never\n"
       +"truly dying unless their heads are removed.  These immortals\n"
       +"all participate in what they call a Game, with several rules,\n");
  write("Inluding that all conflicts among them must be one on one, with\n"
       +"no interference from others, that none of them may kill on holy\n"
       +"ground, and that there can be only one.\n");
  write("When one of the immortals defeats another, and takes his or her\n"
       +"head off, usually with a sword, there is a power discharge called\n"
       +"the Quickening, when the surviving immortal takes the power of the\n"
       +"other.  The immortal that ends with the power of all the others\n"
       +"will wield an incredible power.\n");
  write("The author of the books claims that there's an orginization of\n"
       +"mortals that watches these immortals and records what they do, but\n"
       +"never reveals itself to them, and never interferes in their game.\n");
  write("The author's name is finally revealed at the end:  Joe Dawson.\n");
  say(TPN+" takes a book from the bookshelf and peruses it.\n");
  return 1;
}
