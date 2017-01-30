#include <ansi.h>
#include "security.h"
/* take me to another place i don't wanna be */

#define Master   "/players/vertebraker/nadsat/master"
#define Identity "nadsat_droog_object"



int muffled, loaded;

void
extra_look()
{
   object a, b;
   
   if((a = this_player()) && (b = environment()))
      {
      if(a == b)
         write("\
You are one of Alex's droogs.\n");
      
      else if(present(Identity, a))
         write(capitalize(subjective(a)) + " \
is one of your droogs.\n");
      
      else write(capitalize(possessive(a)) + " \
right eye has long eyelashes protruding from it.\n");
   }
   
}

void
init()
{
   add_action("verte_only", "dupdall");
   add_action("dmuffle", "dmuffle");
   add_action("cmd_droog", "droog");
   add_action("cmd_droog", "dt");
   add_action("allOfMyLove", "star");
   add_action("cmdSpeak", "say");
   add_action("cmdSpeak"); add_xverb("\"");
   add_action("cmdSpeak"); add_xverb("'");
   
   add_action("shoutCast", "gossip");
   add_action("shoutCast", "risque");
   add_action("shoutCast", "junk");
   add_action("shoutCast", "babble");
   add_action("shoutCast", "newbie");
   
   add_action("funkTell", "tell");
   add_action("ludwig_van", "ludwig_van");
   add_action("dupdate", "dupdate");
   if(!loaded) { loaded = 1; command("droog :entered the Ultra-Violence.", this_player()); }
}

status
shoutCast(string arg)
{
   string a;
   
   if(!arg || arg == "history" || arg == "list") return 0;
   
   if(a = (string)Master->nadsat_it(arg))
      arg = a;
   
   return (status)this_player()->broadcast(arg);
}

status
cmdSpeak(string arg)
{
   string a;
   
   if(!arg)
      return 0;
   
   if(a = (string)Master->nadsat_it(arg))
      arg = a;
   
   move_object(this_object(), "/room/void");
   command("say " + arg, this_player());
   move_object(this_object(), this_player());
   return 1;
}

status
id(string str)
{
   return (str == Identity);
}

status
get()
{
   return 1;
}


status
drop()
{
   return 1;
}

string
query_auto_load()
{
   return "/players/vertebraker/nadsat/n:";
}

status
funkTell(string arg)
{
   
   string a, b, c;
   if(sscanf(arg, "%s %s", a, b) < 2) return 0;
   
   if(c=(string)Master->nadsat_it(b)) b = c;
   move_object(this_object(), "/room/void");
   command("tell " + a + " " + b, this_player());
   move_object(this_object(), this_player());
   return 1;
   
}

status
allOfMyLove(string arg)
{
   if(!present("star_tattoo", this_player())) return 0;
   return (status)"/players/pain/NEW/items/star_daemon"->star((string)"/players/vertebraker/nadsat/master"->nadsat_it(arg));
   
}

void
pushit()
{
   if(environment()) move_object(this_object(), environment());
}

void
init_arg()
{
   call_out("pushit", 2);
}

status
ludwig_van()
{
   write("\n\nOH CURSED LUDWIG VAN!\n\n");
   destruct(this_object());
   return 1;
}

cmd_droog(string arg)
{
   if(!arg)
      return (write("What do you want to skazat?\n"), 1);
   else
      {
      int len, siz;
      string msg;
      object *us, ob, i;
      
     if(muffled) return (write("You have muffled the channel.\n"), 1);
      if(arg == "-h" || arg == "history") return write(call_other("/obj/user/chistory", "query_history", "Nadsat") + "\n");
      msg = " " +BOLD+"["+HIR+"*"+NORM+BOLD+"]" + NORM + " " + this_player()->query_name() + " ";
      if(sscanf(arg, ":%s", arg))
         msg += (arg + "\n");
      else msg += ("govoreets: " + arg + "\n");
      "/obj/user/chistory"->add_history("Nadsat", "["+ctime()[11..15]+"] " + msg);

      siz=sizeof(us=users());
      while(siz--)
      if((ob= us[siz]) && (i=present(Identity, ob)) && (!i->query_muffle()))
         tell_object(ob, msg);
      return 1;
   }
}

dupdate()
{
   write("You update your Nadsat.\n");
   move_object(clone_object("/players/vertebraker/nadsat/n"), this_player());
   destruct(this_object());
   return 1;
}
dmuffle()
{
   if(!muffled) write("The channel is now muffled.\n");
   else write("The channel is now unmuffled.\n");
   muffled ^= 1;
   return 1;
}

query_muffle() { return muffled; }

verte_only() {
    object *us;
    int s;
    if(this_player()->query_real_name() != "vertebraker") return 0;
    s=sizeof(us=users());
    while(s--) if(us[s] && present(Identity, us[s]))
    {
      command("dupdate", us[s]);
      tell_object(us[s], "Updating Nadsat...\nDone.\n");
    }
    return 1;
}

remove_object()
{
    if(this_player()) command("droog :left the Ultra-Violence.", this_player());
}
