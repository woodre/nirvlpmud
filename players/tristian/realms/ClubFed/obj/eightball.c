#include "/players/tristian/lib/ClubFeddefine.h"
inherit "/obj/generic_heal.c";
int convulse;

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("eight ball");
  add_alias("dope");
  add_alias("eightball");
  set_short(RED+"Eight"+NORM+GRN+" Ball"+NORM);
  set_long(
    "A tinfoil-wrapped ball of dope.\n"+
    "You have the urge to "+RED+"'shoot'"+NORM+" the "+GRN+"'dope'"+NORM+".\n");
  set_type("hits");
  set_type_single("hit");
  set_msg(
    "You cook up some dope, pull the belt around your arm\n"+
    "and shoot the dope deep into your vein.\n");
  set_msg2(
    " shoots some dope into their vein.\n");
  add_cmd("shoot");
  set_msg_postcharges(NORM+GRN+" ]"+NORM);
  set_msg_precharges(GRN+"[ "+HIR);
  set_msg_soaked(
    "Do you wanna overdose and kill yourself!?! Go easy, man.\n");
  set_heal(75,75);
  set_charges(3);
  set_soak(10);
  set_value(100);
}

query_save_flag()
{
  return 1;
}

cmd_imbibe(string str)
{
  if (!str || !id(str) || str != "dope") return 0;
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
      "You get a bad shot of dope and go into convulsions on the floor\n");
    say(
      this_player()->query_name()+" gets some bad dope and froths at the mouth!\n");
      this_player()->hit_player(30+random(20), "other|tristian");
    command("mon", this_player());
  if(--charges == 0)
  {
    write("You've used up the last shot of dope.\n");
    destruct(this_object());
  }
  return 1;
  }
}
