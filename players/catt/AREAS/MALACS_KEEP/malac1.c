#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
object malac;
if(!present("malac")) {
   malac = clone_object(NPC+"MK_malac");
   move_object(malac, this_object());
      }
}
TWO_EXIT(VALLEY+"valley21","bridge",
         MALACS_KEEP+"malac2","east",
         "malac's keep",
         "This is the main court in the keep. This is where all business\n" +
         "of the day is performed. Malac is not forgiving to foreigners.\n" +
         "so watch what you do. His warhammer is widely known.\n", 1)
