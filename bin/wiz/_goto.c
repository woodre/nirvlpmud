#include <security.h>

int cmd_goto(string dest)
{
 object ob, old_env, soul;

 if((int)this_player()->query_level() < EXPLORE)
  return 0;

 if(!dest)
 {
  write("Usage: 'goto <name|file>'\n");
  return 1;
 }

  soul = this_player();

 if(!(ob = find_player(dest)) && !(ob = find_living(dest)))
 {
  dest = (string)this_player()->valid_read(dest);
  if(!dest)
  {
   write("Invalid monster or file name.\n");
   return 1;
  }
  if(!soul->query_errormsgs())
  {
   string err;
   if(err = catch(dest->load_me()))
   {
    write("file: "+dest+"\n");
    write(err+"\n");
    return 1;
   }
  }
  else
   dest->load_me();
  this_player()->move_player("X#"+dest);
  return 1;
 }
 if(!(ob = environment(ob)))
 {
  write(capitalize(dest)+" does not have an environment to goto.\n");
  return 1;
 }
 if((int)this_player()->query_invis() < INVIS_TELEPORT)
  this_player()->remote_say((string)this_player()->query_name()+
                 " "+(string)this_player()->query_mmsgout()+".\n");
 old_env = environment(this_player());
 move_object(this_player(), ob);
 if((int)this_player()->query_invis() < INVIS_TELEPORT)
  this_player()->remote_say((string)this_player()->query_name()+
                 " "+(string)this_player()->query_mmsgin()+".\n");
 write((string)ob->short()+".\n");
 return 1;
}

