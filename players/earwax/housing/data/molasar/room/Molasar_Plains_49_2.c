#include "/players/earwax/housing/defs.h"

inherit HROOM;
void reset(status arg) {
::reset(arg);
  if (arg) return;

  Light = 1;
  LightToggle = (Light ? 1 : 0);
  set_light(Light);
  Short1 = "Carnage's Palace[2;37;0m[2;37;0m";
  Short2 = ": [1;34mLibrary[0m[2;37;0m[2;37;0m[2;37;0m[2;37;0m";
  long_desc = "[2;37;0mThis is the library.  The walls are covered with book shelves[2;37;0m[2;37;0m\n[2;37;0mfrom floor to ceiling.  In the center sits a large oak[2;37;0m[2;37;0m\n[2;37;0mtable with 6 chairs around it.  It appears that not a lot[2;37;0m[2;37;0m\n[2;37;0mof time is spent in here.[2;37;0m[2;37;0m[2;37;0m[2;37;0m\n";
  FileName = "/players/earwax/housing/data/molasar/room/Molasar_Plains_49_2.c";
  RoomNum = 2;
  BaseFilename = "/players/earwax/housing/data/molasar/room/Molasar_Plains_49_";
  Entrance = "/players/molasar/PLAINS/plain8.c";
  get_master();
  items = ({ "shelves", "The book shelves are full with hard back and paper back books.[2;37;0m[2;37;0m",
"book shelves", "The book shelves are full with hard back and paper back books.[2;37;0m[2;37;0m",
"books", "The books look like they are in alphabetical order, starting with \
Asses, and what they are good for.^[[2;37;0m^[[2;37;0m ",
"book", "This book is on the table and appears to be opened to page 45, and \
it's titled Tantra Positions.^[[2;37;0m^[[2;37;0m ",
"table", "A large oak table with the grain going length wise.[2;37;0m[2;37;0m",
"chairs", "6 nicely padded oak chairs that go perfectly with the table.[2;37;0m[2;37;0m",
"chair", "A nicely padded oak chairs that go perfectly with the table.[2;37;0m[2;37;0m" });
  dest_dir = ({ "/players/earwax/housing/data/molasar/room/Molasar_Plains_49_0.c", "back" });
}
