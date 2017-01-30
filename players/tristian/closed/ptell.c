/* Puppy's ptell (Thanks Vert and Forbin) */
/*  Copied from V date:  jul 2002 | Last mod:  jul 2002   */

#include "/players/puppy/define.h"

status
id(string str)
{
   return str == "ptell";
}

string
short()
{
   object a, e;
   
   if((a = this_player()) && (e = environment()) &&
         (e == a))
   return "A ptell ["+HIG+"invis"+NORM+"]";
}

void
init()
{
   add_action("cmd_ptell", "me");
   add_action("cmd_ptell", "me1");
   add_action("cmd_tell", "tell");
}

status
cmd_tell(string arg)
{
   string who, what, a;
   object c;
   
   if(!stringp(arg) || sscanf(arg, "%s %s", who, what) < 2)
      {
      write("Um what?\n");
      return 1;
   }
   
   if(who != "puppy" && who != "f" && who != "me")
      return 0;
   
   if(!(c = find_player("puppy")))
      {
      write(""+HIB+"Puppy is not here."+NORM+"\n");
      return 1;
   }
   
   write(""+HIB+""+NORM+"\n");
   if(!environment(c) || !interactive(c))
      {
      write("Puppy is disconnected.\n");
      return 1;
   }
   if(query_idle(c) > 120)
      write("Puppy is idle.\n");
   
   write("["+HIG+"ptell"+NORM+"] "+what+"\n");
   
   tell_object(c, HIB +""+HIB+"["+NORM+""+CYN+"ptell"+NORM+""+HIB+"]"+NORM+""+HIB+" "+ 
      (a = (string)this_player()->query_name()) +
" tells you: " + HIB + what + NORM + "\n");
   c->add_tellhistory(CYN + a + " told you: " + NORM + what);
   c->Replyer((string)this_player()->query_real_name());
   
   return 1;
}

status
get() { return 1; }
status
drop() { return 1; }

status
cmd_ptell(string arg)
{
   command("pup "+arg, this_player());
   return 1;
}

