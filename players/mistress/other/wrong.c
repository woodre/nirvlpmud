#include "std.h"
#include "living.h"
object scientist;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

extra_init() {
     add_action("give","give");
     }

give(str) {
     object ob, spell;
    if(str == "disk to scientist") {
       if(!present("disk",this_player())) {
       write("\nPlease give me the correct item or leave!\n\n");
          return 1; }
        write("\nThe scientist exams the disk closely and inserts it in a\n");
        write("strange metal box... Looking back up at you he cackles with glee!:\n");
        write("\n`Thank you.  I have been waiting for this disk.  \n");
        write("But you know... you REALLY should have taken more CARE\n");
        write("in following the instructions encoded here.\n");
        write("\n");
        write("The scientist laughs evilly as he destroys your disk.\n");
        write("\n");
        destruct(present("disk",this_player()));
       return 1;
    }
}

ONE_EXIT("players/mistress/sci_fi/star_wars/zc3po.c","out",
   "A mad scientist`s room",
   "The room is cluttered with electronic junk.  You wonder if half the stuff\n" +
   "around here even works.  But,  if the scientist has been looking for the\n" +
   "disk,  then it must be valuable to him.  It is up to you whether you choose\n" +
   "to give the disk to him...\n",1)

extra_reset()
{
if (!scientist || !living(scientist) )
{

scientist = clone_object("obj/monster");
call_other(scientist, "set_name", "A scientist");
call_other(scientist, "set_ac", 9);
call_other(scientist, "set_wc", 19);
call_other(scientist, "set_hp", 900);
call_other(scientist, "set_al", 600);
call_other(scientist, "set_short", "A scientist");
call_other(scientist, "set_alias", "scientist");
call_other(scientist, "set_long", "He appears to very evil and very clever.\n");
call_other(scientist, "set_race", "scientist");
call_other(scientist, "set_aggressive", 0);
call_other(scientist, "set_level", 19);
move_object(scientist, this_object() );

}
}
