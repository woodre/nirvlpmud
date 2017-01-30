#include "/players/feldegast/closed/ansi.h"
inherit "obj/weapon";

reset(arg)
{
  if (arg) return;
  ::reset(arg);
  set_name("blue sword");
  set_alias("sword");
  set_short("The "+HIB+"Blue"+NORM+" Sword");
  set_long("The Sword of Water is well balanced.  It dynamically\n"+
           "changes it's shape  to fit any hand that wields it.\n"+
           "The legendary Blue Sword is heavy, but very effective.\n");
  set_value(1200); /* Upped from 250. */
  set_type("sword");
  set_weight(3);
  set_class(18); /* Upped from 10.  Given the difficulty of this monster's guardian, it should be worth something. -Feldegast 10-6-00 */
  set_hit_func(this_object());
}

weapon_hit(attacker)
{
/* This random emote replaces the constant return of 5.  -Feldegast 10-6-00 */
  if(this_player()->query_attrib("luc") > random(70)) {
    write("You strike "+this_player()->query_attack()->query_name()+" with the elemental "+HIW+"S"+HIB+"word of "+HIW+"W"+HIB+"ater"+NORM+"!\n");
    say(this_player()->query_name()+" strikes "+this_player()->query_attack()->query_name()+" with the elemental "+HIW+"S"+HIB+"word of "+HIW+"W"+HIB+"ater"+NORM+"!\n");
    return 6;
  }
}
