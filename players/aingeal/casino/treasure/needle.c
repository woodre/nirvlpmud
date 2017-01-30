/* Teller's Needle */

#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

inherit "obj/treasure";

reset(arg)
{
  if(arg) return;
  set_id("needle");
  set_short("Sewing Needle");
  set_long("This long, sharp steel sewing needle is coated with sticky,\n\
dried "+RED+"blood"+NORM+" from being swallowed then vomited up by\n\
Teller during his last show.  It might be worth something as a\n\
souvenir...or perhaps it could be used to 'prick' someone.\n");
  set_weight(1);
  set_value(250);
}

init()
{
  ::init();
  add_action("prick","prick");
}

prick(str)
{
  object target,wiz_check;
  if(!str)
  {
    write("Prick who?\n");
    return 1;
  }
  target=find_living(str);
  if(!target)
  {
    write("That person is not here.\n");
    return 1;
   }
  if(target) wiz_check=target->query_level();
  if(wiz_check>=21)
  {
    notify_fail("Do you have a death wish, or something?!\n"+
                "You may NOT prick a wizard!!  Sheesh!!\n");
    return 0;
  }
  if(target->query_invis())
  {
    notify_fail("You don't see that person anywhere.\n");
    return 0;
  }
  write("You prick "+capitalize(str)+
        "painfully in the butt with the needle!\n\n");
  tell_object(target,this_player()->query_name()+
        " pricks you painfully in the butt with a huge needle!  Ouch!\n\n");
  tell_room(environment(target),this_player()->query_name()+
        " pricks "+capitalize(str)+
        " painfully in the butt with a huge needle!  Ouch!\n\n");
  return 1;
}
