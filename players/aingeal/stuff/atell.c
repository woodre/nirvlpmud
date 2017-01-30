/*  Aingeal's Wiztell  */

#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
inherit "obj/treasure";

reset(arg)
{
  if(arg) return;
  set_id("halo");
  set_alias("teller");
  set_short(""+HIY+"Glowing Halo"+NORM+"");
  set_long("This is a special halo sent directly from Aingeal.\n\
You can use this halo to talk with her, if she is here.\n\
Use 'halo' to send a tell, and 'haloe' to send an emote.\n");
  set_weight(0);
  set_value(0);
}

drop()
{
  write("You may not drop your halo.\n");
  return 1;
}
  

init()
{
  ::init();
  add_action("cmd_tell","halo");
  add_action("cmd_emote","haloe");
}


cmd_tell(str)
{
  object atell;
  atell=find_player("aingeal");
  if(!atell)
  {
    notify_fail("Aingeal is nowhere to be found.\n");
    return 0;
  }
  if(in_editor(atell))
  {
    notify_fail("Aingeal is busy.  Please try again later.\n");
    return 0;
  }
  if(atell->query_invis())
  {
    notify_fail("You don't see Aingeal anywhere.\n");
    return 0;
  }
  write(""+YEL+"You tell Aingeal: "+str+NORM+"\n");
  tell_object(atell,""+YEL+":::::"+this_player()->query_name()+" : " 
    +str+NORM+"\n");
  return 1;
}

cmd_emote(str)
{
  object atelle;
  atelle=find_player("aingeal");
  if(!atelle)
  {
    notify_fail("Aingeal is nowhere to be found.\n");
    return 0;
  }
  if(in_editor(atelle))
  {
    notify_fail("Aingeal is busy.  Please try again later.\n");
    return 0;
  }
  if(atelle->query_invis())
  {
    notify_fail("You don't see Aingeal anywhere.\n");
    return 0;
  }
  write(""+YEL+"You emote to Aingeal: "+str+NORM+"\n");
  tell_object(atelle,""+YEL+":::::"+this_player()->query_name()+" " 
    +str+NORM+"\n");
  return 1;
}
