#include "/players/llew/closed/ansi.h"
#include "/players/llew/closed/lsong/line.h"

#define CHANNEL "players/llew/closed/lsong/line"


reset (arg)
{
}

init() {
   CHANNEL->listener("lsong", this_player()->query_real_name(), ADD_MEMBER);
   add_action("lsg","lsg");
   add_action("lse","lse");
   add_action("deafen","deafen");
}

drop() { return 1; }
get() { return 0; }
id(nom) { return nom == "lsong"; }

long() { 
   int x, size;
   string *names;
   write(RED+"\t@"+GRN+"}-,--`--                              --,--`-{"+RED+"@\n\n");
   write(NORM+"\t   A song drifts through your mind carrying your thoughts to\n\t   "+
         "others with the song.  You can lsg to think or lse to send actions.\n\t   "+
         "Deafen will remove the song from your mind. \n\n\t\tThe song drifts to:\n\t "+
         "    "+BOLD+"-------------------------\n\n"+NORM);

   names = CHANNEL->get_list_listeners("lsong");
   write(format("\t" + implode(names,"\t"),60)+"\n");
   return 1;
}

/*
query_auto_load() { return "/players/llew/closed/lsong/lsg.c:"; }
*/

lsg(mess) {
   if (!mess)
   {
      write("Please say something more eloquent than nothing.\n");
      return 1;
   }
   mess = GRN+"-,-{"+RED+"@ "+HIW+this_player()->query_name()+" "+NORM+RED+"@"+GRN+"}-`- "+NORM+format(mess, 60);
   CHANNEL->broadcast("lsong", mess);
   return 1;
}

lse(mess) {
   if (!mess)
   {
      write("Please do something more eloquent than nothing.\n");
      return 1;
   }
   mess = GRN+"-,-`-{"+RED+"@ "+HIW+this_player()->query_name()+NORM+" " + format(mess, 60);
   CHANNEL->broadcast("lsong", mess);
   return 1;
}


deafen() {
   write("\n"+BOLD+pad("",70,'~')+"\n\n"+RED+"\tYou stop listening to the beautiful song.\n\t"+
         "Your heart longs to flow with the lost melodies of life.\n\tYour deaf ears "+
         "will never hear the same.\n\n"+NORM+BOLD+pad("",70,'~')+"\n\n"+NORM);

   CHANNEL->listener("lsong", this_player()->query_real_name(), SUB_MEMBER);
   destruct(this_object());
   return 1;
}
