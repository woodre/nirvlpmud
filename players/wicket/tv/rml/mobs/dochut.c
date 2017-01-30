inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/wicket/tv/rml/armor/docapp.c"), this_object()); 
  command("wear aapron", this_object());
  move_object(clone_object("/players/wicket/tv/rml/armor/docsweat.c"), this_object()); 
  command("wear sweater", this_object());
  set_name("hutchinson");
  set_alt_name("doctor");
  set_race("toon");
  set_alias("toon hutchinson");
  set_short(HIW+"Doctor Hutchinson"+NORM+"" );
  set_long("\
   A psychotic feline that works as a dentist, she has a hook that replaces. \n\
  where her right hand use to be and she is one very bizzare person. Her blank\n\
  expression alone gives off the look of crazy.\n");
  add_spell("hookslash","#MN# $HK$slashes$N$ You $HR$violently with her hook hand causing $HR$MASSIVE DAMAGE!$N$.\n",
                        "#MN# $HK$slashes$N$ #TN# $HR$violently with her hook hand causing $HR$MASSIVE DAMAGE!$N$.\n",
                        30,30,0,0);
  set_level(19);
  set_hp(560+ random(40));
  set_ac(15+ random(3));
  set_wc(22+ random(5));
  set_al(0);
  add_money(random(2500)+500);
  }