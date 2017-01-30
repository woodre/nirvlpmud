/*
        Heal Cost Calculator (c) Fred 2009

        [1] HP amount per charge:       50
        [2] SP amount per charge:       50
        [3] Number of charges:          3
        [4] Soak amount per charge:     7
        [5] Stuff amount per charge:    7
        [6] Intox amount per charge:    0
        [7] Random HP's per charge:     0
        [8] Random SP's per charge:     0
        [c] Calculate
        [x] Exit

        [1,2,3,4,5,6,7,8,c,x] 

        The cost for this heal would be: 1800 coins.
selling for 2000 for add -10 align
*/



inherit "/obj/generic_heal.c";
#include "/players/pestilence/ansi.h"

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("a large"+WHT+" Chrono-Blast"+NORM+"");
  add_alias("chrono-blast");
  add_alias("chrono blast");
  add_alias("blast");
  set_short("a large"+WHT+" Chrono Blast"+NORM+"");
  set_long("This is a large"+WHT+" Chrono Blast"+NORM+".\n"+
           "It is like a milkshake but a bit more evil and could be very refreshing to drink.\n");    
  set_type("sips");
  set_msg("You take a big gulp of the "+WHT+"Chrono Blast"+NORM+".\n");
  set_msg2(" takes a big gulp of the "+WHT+"Chrono Blast"+NORM+".\n");
  add_cmd("drink");
  add_cmd("gulp");
  add_cmd("sip");
  set_heal(50,50);
  set_charges(3);
  set_stuff(7);
  set_soak(7);
  set_value(600);
}

post_charge_hook() {
   call_other(this_player(), "add_alignment", -10);
   write("You slam down a Chrono Blast, and appear to be more evil!\n");
   say(this_player()->query_name()+" slams down a Chrono Blast, and appears to be more evil!\n");
}
query_save_flag() { return 1; }
