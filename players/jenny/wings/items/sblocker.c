/* THIS IS ONE ILLEGAL PIECE OF SHIT
          verte 8.26.03 */
/* added 1/4 random chance, reduced return from 6 to 1 */
#include "/players/jenny/define.h"
inherit "/obj/armor.c";
reset(arg) {
   ::reset(arg);
   set_name("blocker");
   set_id("blocker");
   set_alias("glove");
   set_ac(2);
   set_value(1500);
   set_weight(1);
/*
   set_save_flag(1);
*/
   set_type("gloves");
   set_short("Blocker");
   set_long(
      "This is a goaltender's blocker.  It's a leather glove with a large\n"+
      "padded shield that protects the forearm.  It is used for deflecting\n"+
      "pucks.  This blocker is very old, and belongs to Terry Sawchuck.\n"+
      "He could always rely on it to help him make the big save\n"+ 
      "when he needed it most.\n");
}

do_special(owner)
{
   if(!random(4))
   if(owner->query_mhp() / 2 > owner->query_hp())
      {
      tell_object(owner,"\n"+
         "You hear a soft "+BOLD+"THUMP "+NORM+"against your blocker, but hardly feel a thing.\n");
   owner->add_hit_point(3);
      return 1;}
   return 0;}
