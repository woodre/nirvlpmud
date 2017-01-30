inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/wicket/tv/looney/armor/pinkshirt2.c"), this_object()); 
  command("wear shirt", this_object());
  move_object(clone_object("/players/wicket/tv/looney/armor/pinkbow.c"), this_object()); 
  command("wear bow", this_object());
  set_name("shirley");
  set_alt_name("loon");
  set_race("toon");
  set_alias("toon shirley");
  set_short(HIM+"Shirley McLoon"+NORM);
  set_long("\
   Long flowing blonde hair flows from the top of her head, a soft pink\n\
  bow is tied to the back. She has soft blue dreamy eyes with a dazzling\n\
  smile that flows off her beak.A fancy pink shirt just flows off of the\n\
  ducks arms and body. Her feet bright orange and webbed. She walks around\n\
  with the annoying valley girl accent that just flows fast from her beak.\n");
 add_spell("shirleybill","#MN# $HK$bites$N$ YOU really hard with $HM$her $Y$beak$N$.\n",
                       "#MN# $HK$bites$N$ #TN# really hard with $HM$her $Y$beak$N$.\n",
                       40,40,0,0);
  set_level(19);
  set_hp(550+ random(50));
  set_ac(16+ random(3));
  set_wc(24+ random(8));
  set_al(0);
  add_money(random(1000)+2000);
  }