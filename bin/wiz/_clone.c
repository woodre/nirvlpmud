/*
 *      File:                   /wiz/bin/_clone.c
 *      Function:               Clone
 *      Author(s):              
 *      Copyright:              Copyright (c) 
 *                                      All Rights Reserved.
 *      Source:                 
 *      Notes:                  
 *      Change History:
 */

#include <ansi.h>
#include <security.h>

/* 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */

int cmd_clone(string str)
{
 string err, pwd;
 object ob, soul;

 if((int)this_player()->query_level() < CREATE)
  return 0;

 if(!str)
 {
  write("Usage: 'clone <file_name>'\n");
  return 1;
 }

  soul = this_player();
 
 if(((pwd = (string)this_player()->get_path()) &&
     pwd[0..3] == "open") || str[0..4] == "/open")
  log_file("OPEN", (string)this_player()->query_real_name()
                  +" cloned "+str+" at "+ctime()+".\n");

 str = resolve_path(str);
 str = (string)this_player()->valid_read(str);

 if(str == "player.c" || str == "/obj/player.c")
 {
  write("That is not allowed.\n");
  this_player()->illegal_patch("cloned player.c");
  return 1;
 }

 if(!soul->query_errormsgs())
 {
  if(err = catch(ob = clone_object(str)))
  {
   write(err+"\n");
   return 1;
  }
 else ob = clone_object(str);
 }
 else ob = clone_object(str);

 this_player()->checked_say(
  (string)this_player()->query_name()+" fetches something from "+
  "another dimension.\n");

 if(ob->get())
 {
  this_player()->add_weight((int)ob->query_weight());
  move_object(ob, this_player());
 }
 else
  move_object(ob, environment(this_player()));

 write("Ok.\n");
 if(ob->short())
  write("Cloned "+(string)ob->short()+".\n");
 else write("Cloned an invisible object.\n");
 return 1;
}

