#include "room.h"

object mac, hawkeye;
realm() {return "NT";}
#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    object money;
    if (!mac || !living(mac)) {
	mac = clone_object("obj/monster_lars");
	call_other(mac, "set_name", "macarthur");
	call_other(mac, "set_level", 100);
	call_other(mac, "set_hp", 99999);
	call_other(mac, "set_wc", 35);
	call_other(mac, "set_al", 99);
       call_other(mac, "set_ac", 50);
	call_other(mac, "set_short", "General MacArthur");
	call_other(mac, "set_long",
                       "General MacArthur *without the pipe* \n" +
                      "What do you usually do to a General?\n");
	move_object(mac, this_object());
    }
}

ONE_EXIT("players/hawkeye/room/entrance.c", "leave",
      "General MacArthur",
"As you enter the office a the great army general you are in awe.\n" +
"Looking around you see many awards and plaques, and in the corner\n" +
"under a pile of papers, you see a picture of President Truman.\n",1)

init() {
  ::init();
  add_action("salute","salute");
}

salute() {
object pipe;
if(present("cpipe",this_player())) {
write("Snapping a perfect military salute, you hand General MacArthur the pipe.\n");
write("Looking down at you, Big Mac smiles and says: Thanks .\n" +
"I Don't know what i would have done with out you.\n\n\n" +
"Big Mac places the pipe in his mouth.\n" +
"Congratulations, You have Completed this Quest.\n" );
pipe = present("cpipe",this_player());
destruct(pipe);
this_player()->set_quest("M*A*S*H");
return 1;
}
else {
write("You do not have the pipe i want you little PUKE!.\n");
move_object(this_player(),"players/hawkeye/room/entrance.c");
return 1;
}
}
