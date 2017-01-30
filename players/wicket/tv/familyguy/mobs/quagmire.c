inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("glen");
  set_alt_name("quagmire");
  set_race("toon");
  set_alias("toon quagmire");
  set_short(HIR+"Glenn Quagmire"+NORM);
  set_long("\
   Glenn Quagmire is the Griffins next-door sex-addict neighbor and one\n\
  of Peters best friends.He is an airline pilot but is best known for his\n\
  extreme sexuality and always saying Giggity Giggity Goo or Heh Heh alright.\n\
  He is attracted to nearly every woman especially Lois Griffin. His sister\n\
  is Brenda Q. Quagmire. In one episode, he is revealed to have been Jack\n\
  The Ripper in a past life. He has a soft side for cats, and despises Brian\n\
  Griffin. His dad is Ida Quagmire\n.");
  add_spell("violation","#MN# $HW$Swiftly $HK$bends$N$ you over $HR$Sexually Violating$N$ YOU.\n",
                       "#MN# $HW$Swiftly $HK$bends$N$ #TN# over $HR$Sexually Violating$N$ them.\n",
                       40,40,0,0);
  set_level(19);
  set_hp(550+ random(50));
  set_ac(15+ random(4));
  set_wc(24+ random(8));
  set_al(0);
  add_money(random(1000)+4000);
  }