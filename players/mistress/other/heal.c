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
int jj;
     object ob, spell;
    if(str == "disk to scientist") {
       if(!present("disk",this_player())) {
       write("\nPlease give me the correct item or leave!\n\n");
          return 1; }
        write("\nThe scientist exams the disk closely and inserts it in a\n");
        write("strange metal box... Looking back up at you he says:\n");
        write("\n`Thank you.  I have need of this disk.  In return for your\n");
        write("kindness in bringing this to me,  allow me to present you with\n");
        write("a small token of my gratitude.  Use it wisely`.\n");
        write("\n");
        write("The scientist presents you with a heal spell.\n");
        destruct(present("disk",this_player()));

/* placed this so that players wouldnt get free heals - mythos <9-11-97> */
  if(this_player()->query_quests("disk_quest")) {
 jj = 0;
    write("You have already done this quest!\n");
  if(present("disk",this_player())) {
   jj = 1; }
  if(present("bag",this_player())) if(present("disk",present("bag",this_player()))) jj = 1;
    if(jj == 1) {
    write_file("/players/mistress/other/BUGCATCH",ctime(time())+" "+this_player()->query_real_name()+"\n");
    write("HOW DARE YOU EXPLOIT A BUG THIS LONG\n"+
       "WITHOUT SAYING A THING TO A WIZ!!!!!!!!!!!!\n");
      this_player()->zap_object(this_player());
      this_player()->zap_object(this_player());
      this_player()->zap_object(this_player());
     this_player()->zap_object(this_player());
       this_player()->zap_object(this_player());
     }
   return 1;
    }
/* end of mythos change */
        spell = clone_object("obj/heal.c");
        move_object(spell, this_player());
        write("\n\n");
        write("The scientists tells you in an offhand way:\n");
        write("'By the way, you finished your quest.'\n");
        write("He smiles as he turns away.\n");
        write("\n");
        call_other(this_player(),"set_quest","disk_quest");
       return 1;
    }
}

ONE_EXIT("players/mistress/sci_fi/star_wars/c3po.c","out",
   "Heal room",
   "You look around the lab in amazement.  Electronic gadgets seem to clutter\n" +
   "up every available space.  If you see the scientist,  you may try giving\n" +
   "him your disk....\n",1)

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
call_other(scientist, "set_long", "He appears to very kind and very wise.\n");
call_other(scientist, "set_race", "scientist");
call_other(scientist, "set_aggressive", 0);
call_other(scientist, "set_level", 19);
move_object(scientist, this_object() );

}
}
