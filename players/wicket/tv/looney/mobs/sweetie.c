inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>
reset(arg)
{
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/wicket/tv/looney/armor/purpbow.c"), this_object()); 
  command("wear hairbow", this_object());
  set_name("sweetie");
  set_alt_name("pie");
  set_race("toon");
  set_alias("toon sweetie");
  set_short(HIM+"Sweetie Pie"+NORM);
  set_long("\
   A cute little pink bird with pretty blue eyes. She wears a small purple\n\
  bow on top of her little head. She has a very small body and her head takes\n\
  up most of it. Her feet are also very big and are a yellow color. Her smile\n\
  that flows from her beak makes her look cute and innocent\n");
  add_spell("clawscratch","#MN# $HK$rakes$N$ her$HY$ talons$N$ across your $HW$eyes$N$.\n",
                       "#MN# $HK$rakes$N$ her$HY$ talons$N$ across #TN# \'s $HW$eyes$N$.\n",
                       40,40,0,0);
  set_level(19);
  set_hp(550+ random(50));
  set_ac(16+ random(3));
  set_wc(24+ random(8));
  set_al(0);
  add_money(random(1500)+2000);
  }