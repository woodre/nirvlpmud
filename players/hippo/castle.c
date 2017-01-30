#define NAME "Hippo"
#define DEST "/room/jetty2"

#include "/players/hippo/bs.h"
id(str) { return str == "hand"; }

short() {
  return "Hippo's enormous hand!  [The moving fingers look changed...]"; /*added by wocket */
   return format("\
Hippo's enormous hand! \
[The moving fingers look changed...]",70);
}

long() {
write("The fingers at Hippo's impressive, \
massive hand slowly bend and stretch, \
each at a time. On the palm of the hand is \
written: \n\
** Hippo's body is under reconstruction **\n\
** but most of it is still available. ** \n\
** Just shake the hand and find out! **\n\
");
}
init() {
  add_action("stand", "shake");
}

stand(str) {
    if (!id(str))
   return 0;
write("\
You bend over to shake the hand. \
However, the hand doesn't take you \
by the hand, but grabs \
your clothes and lifts you up! \
\nA moment later you enter a dark hole \
where the hand gently places you on your \
feet again. \
The smell and the vague shapes you \
become aware of remind you of..... \
\nof a.... \
\na MOUTH!??! \
\n\n\n");
/*  Changed over to new rooms format by Eurale 6/03
move_object(this_player(),"/players/hippo/rooms/mouth");
*/
move_object(this_player(),"players/eurale/Hippo/mouth");
command("look",this_player());
   return 1;
}

reset(arg) {
object questob;
    if (arg)
	return;
   move_object(this_object(), DEST);
  if(!present("brain_quest",find_object("room/quest_room.c")))
  {
  questob=clone_object("obj/quest_obj");
  call_other(questob,"set_name","brain_quest");
  call_other(questob,"set_hint","Find Hippo's brains and try to reorganise them.\n");
  move_object(questob,"room/quest_room");
  }
}
is_castle(){return 1;}
