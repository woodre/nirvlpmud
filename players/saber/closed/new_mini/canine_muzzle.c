/*  an object to quiet annoying players  */

#include "/players/puppy/ansi.h"

id(str) { return str == "muzzle"; }

reset()
{
   remove_call_out("DESTME");
   call_out("DESTME",200);
   return 1;
}

extra_look()  {
   object ex_look;
   ex_look = environment(this_object())->query_name();
   write(ex_look+" "+RED+"Has been muzzled!!!"+NORM+".\n");
}

init() 
{
#ifndef __LDMUD__
add_action("HELLNO"); add_xverb("brag");
add_action("HELLNO"); add_xverb("brage");
add_action("HELLNO"); add_xverb("recite");
add_action("HELLNO"); add_xverb("recitee");
add_action("HELLNO"); add_xverb("meow");
add_action("HELLNO"); add_xverb("meowe");
add_action("HELLNO"); add_xverb("story");
add_action("HELLNO"); add_xverb("storye");
add_action("HELLNO"); add_xverb("chat");
add_action("HELLNO"); add_xverb("chate");
add_action("HELLNO"); add_xverb("tempt");
add_action("HELLNO"); add_xverb("tempte");
add_action("HELLNO"); add_xverb("tale");
add_action("HELLNO"); add_xverb("talee");
add_action("HELLNO"); add_xverb("gossip");
add_action("HELLNO"); add_xverb("equip");
add_action("HELLNO"); add_xverb("shout");
add_action("HELLNO"); add_xverb("risque");
add_action("HELLNO"); add_xverb("babble");
add_action("HELLNO"); add_xverb("newbie");
add_action("HELLNO"); add_xverb("junk");
add_action("HELLNO"); add_xverb("pk");
add_action("HELLNO"); add_xverb("tell");
add_action("HELLNO"); add_xverb("say");
add_action("HELLNO"); add_xverb("'");
add_action("HELLNO"); add_xverb("emote");
add_action("HELLNO"); add_xverb("reply");
add_action("HELLNO"); add_xverb("page");
add_action("HELLNO"); add_xverb("talk");
add_action("HELLNO"); add_xverb("yoda");
add_action("HELLNO"); add_xverb("whisper");
add_action("HELLNO"); add_xverb("converse");

#else
add_action("HELLNO","brag",3);
add_action("HELLNO","brage",3);
add_action("HELLNO","recite",3);
add_action("HELLNO","recitee",3);
add_action("HELLNO","meow",3);
add_action("HELLNO","meowe",3);
add_action("HELLNO","story",3);
add_action("HELLNO","storye",3);
add_action("HELLNO","chat",3);
add_action("HELLNO","chate",3);
add_action("HELLNO","tempt",3);
add_action("HELLNO","tempte",3);
add_action("HELLNO","tale",3);
add_action("HELLNO","talee",3);
add_action("HELLNO","gossip",3);
add_action("HELLNO","equip",3);
add_action("HELLNO","shout",3);
add_action("HELLNO","risque",3);
add_action("HELLNO","babble",3);
add_action("HELLNO","newbie",3);
add_action("HELLNO","junk",3);
add_action("HELLNO","pk",3);
add_action("HELLNO","tell",3);
add_action("HELLNO","say",3);
add_action("HELLNO","'",3);
add_action("HELLNO","emote",3);
add_action("HELLNO","reply",3);
add_action("HELLNO","page",3);
add_action("HELLNO","talk",3);
add_action("HELLNO","yoda",3);
add_action("HELLNO","whisper",3);
add_action("HELLNO","converse",3);
#endif
}

HELLNO(str) 
{
   if(!environment(this_object())) 
      {
      destruct(this_object()); 
   }
   
   if(!this_player()) return;
   if(this_player() != environment(this_object())) return;
   write("You have been muzzled by a canine and can not do that!\n");
   return 1; 
}

DESTME()
{
   say("You break free of the muzzle!\n");
   destruct(this_object());
   return 1;
}

get() { return 1; }
drop() { return 1; }
