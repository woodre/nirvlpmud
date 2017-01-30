#include "/players/catt/AREAS/base_defines.c"
id(str) { return str == "path"; }
init() {
  add_action("north", "north");
     }
short() {
return "A small path to the north";
    }
long() {
   write("A path to the Demon Lords Domain.\n");
           }
north() {
call_other(this_player(), "move_player", "enters path#"+TEMPLE+"monkroom1");
/* 08/23/06 Earwax: this doesn't need to keep logging
  write_file("/players/catt/PORTAL_ENTER_LOG",
        this_player()->query_name()+" entered the monk portal!\n");
*/
   return 1;
         }

is_castle() { return 1; } /* Rumplemintz */
