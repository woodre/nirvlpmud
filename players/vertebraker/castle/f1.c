#include "/players/vertebraker/define.h"
inherit ROOM;
string quote;
reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "drowning";
  long_desc =
"     The pool resonates over your head, you see shapeless images\n\
of a Nirvana long gone, and the burning and torture of many a guild\n\
dance through your memories.  A tunnel seems to lead to a vast holy light.\n";
  if(!present("tape player",TO)) {
    if(present("rift",TO)) destruct(present("rift",TO));
    move_object(clone_object("/players/vertebraker/ed/ed/obj/tape_player"),TO);
    }
  items = ({
 });
  dest_dir = ({
"/room/church","the.light",
"/players/vertebraker/castle/entrance","the.dark", });
}
