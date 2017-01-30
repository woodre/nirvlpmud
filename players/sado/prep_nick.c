#include "/players/sado/defines.h"

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

make_real_nick(object old_nick)
{
  object who;
  object new_nick;
  int i;

  who = environment(old_nick);

  new_nick = clone_object("/players/sado/nick.c");
  move_object(new_nick, who);
  for(i=0; i<24; i++)
    {
      if(list_ab[i] && list_ab[i] != "")
	{
	  new_nick->nick(list_ab[i] + " " + list_cmd[i]);
	}
    }

  destruct(old_nick);
}

init()
{
  init_alias_list();
  
  call_out("make_real_nick", 10, this_object());
}

init_arg(arg)
{
  int temp;
  int count, place;
  string      ab, cmd;
  string      the_rest;

  if(arg)
    {
      the_rest = "";
      if(sscanf(arg, "%d;%s", count, the_rest) == 2)
	{
	  init_alias_list();

	  while(the_rest && the_rest != "" && place < sizeof(list_ab))
            {
	      arg = the_rest;
	      if(sscanf(arg, "%s %s;.X.Z;%s", ab, cmd, the_rest) >= 2)
		{
		  if(ab && ab != "" && cmd && cmd != "")
		    {
		      list_ab[place] = ab;
		      list_cmd[place] = cmd;
		      place++;
                    }
                }
            }
        }
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
  temp =  "/players/sado/prep_nick.c:"  + count + ";";
  i = 0;
  while(i < sizeof(list_ab)) {
    if(list_ab[i] && list_cmd[i]) {
      temp += list_ab[i] + " " + list_cmd[i] + ";.X.Z;";
    }
    i += 1;
  }
    
  return temp;        
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
  write("           help nick           --  get more thorough help\n");
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
  write("Look at it to get help.\n");
  return 1;
}
