/* Recoded - was using some room inherit from Reflex dir that didn't exist
   -- Rumplemintz
*/

#include <ansi.h>
inherit "room/room";

void reset(status arg) {
  if (!present("monk_book", this_object())) {
    move_object(clone_object("/players/guilds/warriors/OBJ/trainer_monk"),
                this_object());
  }
  if (arg)
    return;
  set_light(1);
  set_no_clean(1);
  short_desc = BOLD + "A Library" + NORM;
  long_desc = BOLD +
"A library of the temple monks.\n" + NORM +
"The reading room is curcular and the shelves cover all the outer\n" +
"walls completely around the circumjference of the room. The\n" +
"shelves are filled with books and many are on the tables throughout\n" +
"the room. On a pedestal at the far end of the room rests a large book.\n" +
"The ceiling is domed, and is covered in a painting depicting\n" +
"the stars and the universe, while the floor is simple and made of\n" +
"wood. North is the arch leading back into the passageway.\n";
  items = ({
    "shelving", "These wooden shelves are full of books from top to bottom",
    "ceiling", "The ceiling shows the night sky in great detail",
    "tables", "Large wooden tables arranged randomly",
    "walls", "The walls are covered with shelving filled with books",
    "books", "Many ancient books are on the shelves filling them",
    "pedestal", "This is a large pedestal engraved with phrases written in Latin",
    "painting", "This painting depicts the night sky",
  });
  dest_dir = ({
    "/room/temple/1", "north",
  });
}
