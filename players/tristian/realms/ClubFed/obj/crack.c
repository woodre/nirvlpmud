#include "/players/tristian/lib/ClubFeddefine.h"
inherit "/obj/generic_heal.c";
int convulse;

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("crack");
  add_alias("cocaine");
  set_short(HIG+"Crack Cocaine"+NORM);
  set_long(
    "A plastic baggy with a couple rocks of Crack Cocaine.\n"+
    "You have the urge to "+RED+"'smoke'"+NORM+" the "+GRN+"'crack'"+NORM+".\n");
  set_type("rocks");
  set_type_single("rock");
  set_msg(
    "You jam a rock in your crack pipe and take a \n"+
    "pull deep into your lungs, letting the feeling\n"+
    "wash over your entire body.\n");
  set_msg2(
    " jams a rock of crack into their pipe and takes a deep hit.\n");
  add_cmd("smoke");
  set_msg_postcharges(NORM+GRN+" ]"+NORM);
  set_msg_precharges(GRN+"[ "+HIR);
  set_msg_intoxed(
    "Do you wanna overdose and kill yourself!?! Go easy, man.\n");
  set_heal(75,75);
  set_charges(3);
  set_intox(10);
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
      "You smoke some bad Crack and go into convulsions on the floor\n");
    say(
      this_player()->query_name()+" takes a bad hit and froths at the mouth!\n");
      this_player()->hit_player(30+random(20), "other|tristian");
    command("mon", this_player());
  if(--charges == 0)
  {
    write("You've used up the last rock of cocaine.\n");
    destruct(this_object());
  }
  return 1;
  }
}
