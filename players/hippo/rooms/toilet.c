#include "room.h"
#include "/players/hippo/bs.h"
object book;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
book = clone_object("/players/hippo/objects/wizbook.c");
move_object(book, this_object());
}
ONE_EXIT("/players/hippo/workroom","thinking",
         "TOILET",
         "You are in the toilet. You smell something strange. It's"+BS+
         "not just the toilet air, this is something special. Should"+BS+
         "this be the smell of a wise man?"+BS+
         "Now you know why he's sitting that much at the toilet.."+BS,
         1)
