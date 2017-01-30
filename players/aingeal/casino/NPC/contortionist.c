/* Cirque du Soleil contortionists */

#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

inherit "/obj/monster.c";

reset(arg)
{
  ::reset(arg);
  if (!arg)
  {
    object gold,unitard;
    gold=clone_object("obj/money");
    gold->set_money(random(21)+80);
    move_object(gold,this_object());
    move_object(clone_object("/players/aingeal/casino/armor/unitard.c"));
  }
  set_name("contortionist");
  set_alt_name("entertainer");
  set_alias("cirque du soleil contortionist");
  set_short("Cirque du Soleil Contortionist");
  set_race("human");
  set_long("The lithe, diminuntive performer slinks across the stage\n\
with boneless grace that would shame a cat.  Her dramatic\n\
stylized makeup conceals all distinguishing features of\n\
her face, giving her a look that is something other than\n\
human.  She is dressed in a brightly-patterned unitard that\n\
covers her whole body, save her hands and head.   It fits\n\
like a second skin, allowing the sharp definition of each and\n\
every muscle in her body to show clearly as she moves.\n");
  set_level(9);
  set_ac(7);
  set_wc(13);
  set_hp(135);
  set_al(0);
  set_aggressive(0);
  set_chat_chance(10);
  set_a_chat_chance(30);
  /* Regular chats */
  load_chat("The contortionist braces her hands on the floor as she\n\
lifts both legs behind her back in a steady, controlled\n\
motion, eventually bending her back in half to tuck her\n\
ankles beneath her chin and frame her face between the\n\
curve of her bent legs.\n");
  load_chat("The contortionist slowly bends her body into a georgous,\n\
elaborate knot, drawing astonished gasps from the audience.\n");
  load_chat("The contortionist rests her chin and shoulders on the floor,\n\
bending her back in half so that her buttocks brush the back\n\
of her head and her legs stretch to their full length beyond.\n");
  load_chat("The contortionist falls gracefully into a handstand, then\n\
somehow bends her body into a backward question mark.\n");
  load_chat("The contortionist balances on one hand, the rest of her\n\
body bent into graceful, impossible curves centered atop it.\n");
  
  /* Combat chats */
  load_a_chat("The contortionist does a walk-over onto your back, then\n\
wraps her legs around your throat from behind!\n");
  load_a_chat("The contortionist bends in half, eluding your attack!\n");
  load_a_chat("The contortionist balances on her hands while battering\n\
your face repeatedly with quick, hard punches of her feet!\n");
}
