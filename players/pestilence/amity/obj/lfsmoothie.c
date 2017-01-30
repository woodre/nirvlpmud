/*
        Heal Cost Calculator (c) Fred 2009

        [1] HP amount per charge:       0
        [2] SP amount per charge:       50
        [3] Number of charges:          5
        [4] Soak amount per charge:     3
        [5] Stuff amount per charge:    3
        [6] Intox amount per charge:    0
        [7] Random HP's per charge:     0
        [8] Random SP's per charge:     0
        [c] Calculate
        [x] Exit

        [1,2,3,4,5,6,7,8,c,x] 

        The cost for this heal would be: 2822 coins.


Looking to sell for 2700, has a 10% chance to lose 10 hp and 10 sp per
heal attempt
*/



inherit "/obj/generic_heal.c";
#include "/players/pestilence/ansi.h"

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("a "+HIM+"Lowfat Frozen Fruit Smoothie"+NORM+"");
  add_alias("fruit");
  add_alias("smoothie");
  add_alias("fruit smoothie");
  set_short("a "+HIM+"Lowfat Frozen Fruit Smoothie"+NORM+"");
  set_long("This is a "+HIM+"Lowfat Frozen Fruit Smoothie"+NORM+".\n"+
           "It is made of several different frozen fruit and provides a good boost to ones mana.\n");    
  set_type("sips");
  set_msg("You take a big gulp of the "+HIM+"Lowfat Frozen Fruit Smoothie"+NORM+".\n");
  set_msg2(" takes a big gulp of the "+HIM+"Lowfat Frozen Fruit Smoothie"+NORM+".\n");
  add_cmd("drink");
  add_cmd("gulp");
  add_cmd("sip");
  set_heal(0,50);
  set_charges(5);
  set_stuff(3);
  set_soak(3);
  set_value(900);
}

post_charge_hook() {
int m;
m = random(10);
if (m > 8) {
  this_player()->add_hit_point(-10);
  this_player()->add_spell_point(-10);
     write("You get massive brain freeze!\n");
   say(this_player()->query_name()+" gets massive brain freeze!\n");
return 1;
}

}
query_save_flag() { return 1; }
