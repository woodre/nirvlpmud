/*  Coldwind's Wiztell  */

#include "/players/coldwind/ansi.h"
inherit "obj/treasure";

reset(arg)
{
  if(arg) return;
  set_id("nunchaku");
  set_alias("teller");
  set_short(""+HIB+"Nunchaku <vortex-forged> (wielded)"+NORM+"\n");
  set_long("A powerful CyberNinja Guild weapon, the Nunchaku is \n+" 
"a pair of short blunt sticks connected to each other \n+"
"by a shorter metal chain. Though simple in design, \n+"
"Nunchaku's can be extremely deadly when wielded by a\n+"
"skilled ninja. Each purplish-black handle is encrusted \n+"
"with the golden emblem of a magnificent dragon. \n+"
""+HIB+"You can use this nunchaku to talk with Coldwind, if he is here.\n+"
"Use 'cw' to send a tell, and 'cwe' to send an emote."+NORM+"\n");
  set_weight(0);
  set_value(0);
}

drop()
{
  write("You may not drop the nunchaku.\n");
  return 1;
}
  

init()
{
  ::init();
  add_action("cmd_tell","cw");
  add_action("cmd_emote","cwe");
}


cmd_tell(str)
{
  object nunchaku;
  nunchaku=find_player("coldwind");
  if(!nunchaku)
  {
    notify_fail("Coldwind has stepped into another realm.\n");
    return 0;
  }
  if(in_editor(nunchaku))
  {
    notify_fail("Coldwind is busy.  Please try again later.\n");
    return 0;
  }
  
  write(""+HIB+"You tell Coldwind: "+str+NORM+"\n");
  tell_object(nunchaku,""+HIR+"****"+HIB+">>>"+this_player()->query_name()+" : " 
    +str+NORM+"\n");
  return 1;
}

cmd_emote(str)
{
  object nunchaku;
  nunchaku=find_player("coldwind");
  if(!nunchaku)
  {
    notify_fail("Coldwind is nowhere to be found.\n");
    return 0;
  }
  if(in_editor(nunchaku))
  {
    notify_fail("Coldwind is busy.  Please try again later.\n");
    return 0;
  
  write(""+HIB+"You emote to Coldwind: "+str+NORM+"\n");
  tell_object(nunchaku,""+HIR+"****"+HIB+">>>"+this_player()->query_name()+" " 
    +str+NORM+"\n");
  return 1;
}
