#include "/players/feldegast/defines.h"

inherit "obj/treasure";

object sword;

void reset(int arg)
{
  if(arg)return;
  no_clean = 1;
  set_id("sheath");
  set_short("A black leather sheath");
  set_long(
"This is a simple black leather belt attached to a\n"+
"swordsheath.  You may sheathe or unsheathe.\n"
  );
  set_weight(1);
  set_value(500);
  no_clean = 1; /* Due to a report of a sheathed weapon disappearing. */
}

void long(string str) {
  ::long(str);
  if(sword)
    write("It contains:\n"+
          (string)sword->short()+".\n");
}

void init()
{
  add_action("cmd_sheath","sheathe");
  add_action("cmd_unsheath","unsheathe");
}

int cmd_sheath(string str)
{
  object ob;
  notify_fail("Sheathe what?\n");
  if(!str) return 0;
  ob=present(str,this_player());
  notify_fail("You do not have that.\n");
  if(!ob) return 0;
  if(!(ob->id("sword")))
  {
    notify_fail("That is not a sword.\n");
    return 0;
  }
  if(sword)
  {
    notify_fail("There is already a weapon in your sheath.\n");
    return 0;
  }
  sword=ob;
  if((int)sword->query_wielded())
    command("unwield "+str,this_player());
  move_object(ob,this_object());
  this_player()->add_weight(-((int)ob->query_weight()));
  local_weight=((int)ob->query_weight() > 3)?3:(int)ob->query_weight();
  this_player()->recalc_carry();
  write("You sheathe "+(string)ob->short()+".\n");
  say((string)this_player()->query_name()+" sheathes "+(string)ob->short()+".\n");
  return 1;
}

int cmd_unsheath(string str)
{
  if(!sword || (str && !((int)sword->id(str))))
  {
    notify_fail("There is no "+str+" in your sheath.\n");
    return 0;
  }
  if(!((int)this_player()->add_weight((int)sword->query_weight())))
  {
    notify_fail("That is too heavy for you.\n");
    return 0;
  }
  move_object(sword,this_player());
  write("You unsheathe "+(string)sword->short()+".\n");
  say((string)this_player()->query_name()+" unsheathes "+(string)sword->short()+".\n");
  sword=0;
  local_weight=1;
  this_player()->recalc_carry();
  return 1;
}
