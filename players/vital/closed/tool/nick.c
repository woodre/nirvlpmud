#include "defines.h"

object  list_ab;
object  list_cmd;

init_alias_list()
{
   if(!list_ab)
      {
      list_ab = allocate(24);
   }
   if(!list_cmd)
      {
      list_cmd = allocate(24);
   }
}

add_nick_actions()
{
   add_action("nick", "nick");
   add_action("nick", "nickname");
   add_action("nick", "unnick");
   add_action("nick", "unnickname");
   add_action("help", "help");
   add_action("dtell", "tell");
   add_action("do_it"); add_xverb("");
   
   return 1;
}

init()
{
   init_alias_list();
   
   if(env(this_object()) == tp)
      {
      add_nick_actions();
   }
}

query_auto_load()
{
   string      temp;
   int i, count;
   
   i = 0;
   count = 0;
   while(i < sizeof(list_ab)) {
      if(list_ab[i] && list_cmd[i]) {
         count += 1;
         }
      i += 1;
   }
   temp =  "/players/vital/closed/tool/prep_nick.c:"  + count + ";";
   i = 0;
   while(i < sizeof(list_ab)) {
      if(list_ab[i] && list_cmd[i]) {
         temp += list_ab[i] + " " + list_cmd[i] + ";.X.Z;";
         }
      i += 1;
   }
   
   return temp;        
}

do_it(str)
{
   int i;
   int num;
   string      verb, obj, args;
   
   if((num = sscanf(str, "%s %s %s", verb, obj, args)) != 3)
      {
      if((num = sscanf(str, "%s %s", verb, obj)) != 2)
         {
         return 0;
      }
   }
   
   if(verb == "nick" || verb == "unnick" || verb == "nickname" || verb == "unnickname") return 0;
   
   i = sizeof(list_ab) - 1;
   while(i >= 0)
   {
      if(list_ab[i] == obj)
         {
         if(list_cmd[i] == 0)
            {
            list_ab[i] = 0;
         }
         else
            {
            if(num == 3)
               {
               command(verb + " " + list_cmd[i] + " " + args, this_player());
            }
            else
               {
               command(verb + " " + list_cmd[i], this_player());
            }
            return 1;
         }
         }
      i--;
   }
   /* not found */
   return 0;
}

nick(str)
{
   int i;
   string      ab, cmd;
   
   if(!str || str == "")
      {
      write("The nicknames in your nick-a-nizer are:\n");
      i = sizeof(list_ab) - 1;
      while(i >= 0)
      {
         if(list_ab[i])
            {
            write(extract(list_ab[i] + "         ", 0, 9) + list_cmd[i] + "\n");
            }
         i--;
      }
      return 1;
   }
   
   if(sscanf(str, "%s %s", ab, cmd) == 2)
      {
      if (ab == cmd)
         {
         write("That is not a valid nick/name pair (name = nick).\n");
         return 1;
      }
      i=sizeof(list_ab) - 1;
      while(i >= 0)
      {
         if (ab == list_cmd[i] || cmd == list_ab[i])
            {
            write("That's not a valid nick/name pair (name = existing nick).\n");
            return 1;
            }
         i--;
      }
      /* adding a new alias */
      i = sizeof(list_ab) - 1;
      while(i >= 0)
      {
         if(list_ab[i] == ab)
            {
            /* replace old definition */
            list_cmd[i] = cmd;
            write("Ok.\n");
            return 1;
            }
         i--;
      }
      i = sizeof(list_ab) - 1;
      while(i >= 0)
      {
         if(!list_ab[i])
            {
            list_ab[i] = ab;
            list_cmd[i] = cmd;
            write("Ok.\n");
            return 1;
            }
         i--;
      }
      write("Sorry the nick-a-nyzer is full!\n");
      return 1;
   }
   if(sscanf(str, "%s", ab) == 1)
      {
      /* removing a nick */
      i = sizeof(list_ab) - 1;
      while(i >= 0)
      {
         if(list_ab[i] && list_ab[i] == ab)
            {
            list_ab[i] = 0;
            list_cmd[i] = 0;
            write("Removed nickname " + ab + ".\n");
            return 1;
            }
         i--;
      }
      write(ab + " wasn't a nickname!\n");
      return 1;
   }
   write("This can't happen!\n");
   return 0;
}

dtell(str)
{
   string who;
   string msg;
   object tiznoy;
   
   tiznoy = present("tiznoy",env(this_object()));
   
   if(tiznoy) return tiznoy->dtell(str);
   
   if(!str || sscanf(str, "%s %s", who, msg) != 2) return 0;
   return this_player()->tell(who+" "+msg);
}

short()
{
   return query_name();
}

long()
{
   write("A nick-a-nyzer which stores nicknames for you.\n");
   write("It will automagically substitute the second argument of any command by looking\n");
   write("in its nicknames table, which you control.\n");
   write("Just like the quicktyper, except for the second word of a command, instead of the first.\n");
   write("Commands:  nick <nick> <name>  --  make new nick\n");
   write("           nick <nick> or\n");
   write("           unnick <nick>       --  remove a nick\n");
   write("           nick                --  list nicknames\n");
}

query_name()
{
   return "A handy nick-a-nyzer";
}

id(str)
{
   return str == "nick" || str == "nick-a-nyzer";
}

get()
{
   return 1;
}

drop()
{
   return 1;
}

help(str)
{
   if(!id(str)) return 0;
   write("Look at it to get help\n");
   return 1;
}
