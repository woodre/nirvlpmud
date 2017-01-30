#define DEST "/room/eastroad2"
#define DEST2 "/room/south/sshore1"

#include <ansi.h>

object templar_castle;

int id(string str) { return str == "tree" || str == "oak"; }

string short() { return "A large " +GRN + "oak tree" + NORM; }

void long() {
  write(
  "A large, looming tree towers above you.  The bark is rough and\n" +
  "dark looking.  There is moss that entwines itself on the many\n" +
  "thick branches which reach out into the forest. There is a large\n" +
  "hole at the bottom of this oak that you could " + HIW + "enter" + NORM +
  ".\n");
}

void init() { add_action("enter", "enter"); }

int enter(string arg) {
  if (arg == "hole" ||
      arg == "opening" ||
      arg == "oak" ||
      arg == "oak tree" ||
      arg == "tree") {
    write("You enter the large opening of the oak tree.\n");
/* Don't think we need this anymore... - Rumplemintz
    write_file("/players/jaraxle/3rd/warrior/enter.log",
               ctime() + " " + HIR + this_player()->query_name() + NORM +
               " entered the tree.\n");
*/
    this_player()->move_player("into the oak#/players/jaraxle/3rd/warrior/rooms/entrance");
    write("\nDo not forget to read the signpost for updates!\n");
    return 1; }
}

void reset(status arg) {
  if (arg) return;

  move_object(this_object(), DEST);

  "room/south/sshore1"->short();
  if (!present("tower", find_object("/room/south/sshore1"))) {
  /*NEEDED for multiple towers appearing -Bp*/
    templar_castle = clone_object("/players/jaraxle/templar/rooms/hope.c");
    move_object(templar_castle, DEST2);
  }
}

status is_castle() { return 1; }
