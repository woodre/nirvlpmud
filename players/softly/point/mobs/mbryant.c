#include "/players/softly/closed/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (arg) return;
   
move_object(clone_object("/players/softly/point/obj/rod.c"),this_object());  

   set_name("Mrs. Bryant");
   set_alt_name("bryant");   
   set_alias("ghost");
   set_long("An older woman with grey in her short hair sits\n\
on the edge of the bed.  She wears a green dress and holds an\n\
object in her hand.  If you ask, she will tell you her 'story'.\n");
   set_short(HIW+"Ghost"+NORM+" of Mrs. Bryant");
   set_race("ghost");
   set_level(12);
   set_wc(16);
   set_ac(9);
   set_hp(180);
   set_al(0);
   set_aggressive(0);
   set_a_chat_chance(10);
   load_a_chat("Mrs. Bryant whispers: I just want to find my daughter.\n");
   load_a_chat("Mrs. Bryant cries: Don't harm me!\n");

}
void catch_tell(string str)
{
    object me;
    string X;
    if(sscanf(str, "%sstory%s\n", X, X))
    { 
      me = this_player();
      if(me->is_player())    
        call_out("dstory", 2, me);
    }
}
void dstory(object asker)
{
    if(!asker) return;
    tell_object(asker, "\Erica was such a good happy child.  But after she went\n"+
                       "away to live with my sister while she was in school, she\n"+
                       "was never quite the same.  She didn't come home any more.\n\n"+
                       "But she promised me if I ever needed her, all I had to do\n"+
                       "was to go to the southern end of the beach by the sea, wave\n"+ 
                       "this rod, and say her name twice.  I never got a chance to\n"+
                       "try it though.  The ghosts came too quickly and my heart wasn't\n"+
                       "strong.  But I saved the rod ... they looked for it  but they\n"+
                       "didn't find it.\n\n");
    tell_room(environment(asker), "\
The ghost whispers something to " 
+ (string)asker->query_name() + ".\n", ({ asker }));
}







