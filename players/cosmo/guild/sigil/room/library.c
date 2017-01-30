#include "/players/cosmo/closed/ansi.h" 
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc=this_player()->query_name()+"'s Library";
  no_castle_flag = 0;
  long_desc="\n\n\n\t\t\tA SIGILIST'S LIBRARY [work in progress]\n"+
            "Items: workbench, bookcase\n",

  items=
  ({
    "workbench","A sturdy wooden workbench for practicing spells",
    "bookcase","A large wooden bookcase containing several spell books",
  });

}

is_library() { return 1; }

init() {
  ::init();
}
