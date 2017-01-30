#include "/players/tristian/lib/ClubFeddefine.h"
inherit "/obj/generic_heal.c";
int convulse;

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("heroin");
  add_alias("crank");
  add_alias("smack");
  set_short(RED+"Heroin"+NORM);
  set_long(
    "A plastic baggy full of Heroin.\n"+
    "You have the urge to "+RED+"'inject'"+NORM+" the "+GRN+"'crank'"+NORM+".\n");
  set_type("cranks");
  set_type_single("crank");
  set_msg(
    "You simmer the Heroin in a metal spoon, pull the\n"+
    "belt around your arm and inject the Heroin into your vein.\n");
  set_msg2(
    " injects some Heroin into their vein.\n");
  add_cmd("inject");
  set_msg_postcharges(NORM+GRN+" ]"+NORM);
  set_msg_precharges(GRN+"[ "+HIR);
  set_msg_stuffed(
    "Do you wanna overdose and kill yourself!?! Go easy, man.\n");
  set_heal(75,75);
  set_charges(3);
  set_stuff(10);
  set_value(100);
}

query_save_flag()
{
  return 1;
}

cmd_imbibe(string str)
{
  if(!str || !id(str)) return 0;
  if(convulsions() != 1) /* convulsion not experienced */
    return ::cmd_imbibe(str);
  else return 1;
}

convulsions()
{
  convulse = random(100);
  if (convulse <= 15) 
  {
    write(
      "You inject some bad Heroin and go into convulsions on the floor\n");
    say(
      this_player()->query_name()+" shoots some bad heroin and froths at the mouth!\n");
      this_player()->hit_player(30+random(20), "other|tristian");
    command("mon", this_player());
  if(--charges == 0) 
  {
    write(
      "You've used up the last inject of heroin.\n");
    destruct(this_object());
  }
  return 1;
  }
}
