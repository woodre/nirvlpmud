#include "/players/softly/closed/ansi.h"
inherit "/obj/weapon.c";

void reset(int arg) {
    ::reset(arg);
    if (arg) return;
    set_name("cluestick");
    set_alias("stick");
    set_short(BOLD+"Cluestick"+NORM);
    set_long("\
A long cylindrical heavy metal club has rounded\n\
protrusions on one weighted end.  The other end\n\
thins and curves into a black dull area tha looks\n\
like it was designed to create a handhold.\n");
    set_type("polearm");
    set_class(18);
    set_weight(2);
    set_value(1100);
    set_hit_func(this_object());

  message_hit=({
    "annihilated","",
    "pummeled","",
    "smashed","",
    "battered","",
    "pounded","",
    "hit","",
    "thumped","",   
  });
  return;
}

mixed weapon_hit(object attacker)
{
    int x;
    string att;
 
    x = random(3);
    if(x == 2)
    {
      att = (string)attacker->query_name();
      switch(random(2))
      {
        case 0:
          say("The stick makes a sickening thunk in"  + att + "'s skull.\n", attacker);
          tell_object(attacker,"\nThere is a sickening thunk as you feel the stick\n\
smash into your skull. Your vision temporarily fades.\n");
          write("The stick makes a sickening thunk in "  + att + "'s skull.\n");
          break;

        case 1:
          say("   The silvery metal contacts " + att + "'s body...\n", attacker);
          tell_object(attacker,"\
   The silvery metal contacts your body.\n\
                 THWAK!\n\
                               Pain radiates.  You try to clear your head.\n");
          write("   The silvery metal contacts " + att + "'s body...\n");
          break;
      }
    return 4;
    }
}

