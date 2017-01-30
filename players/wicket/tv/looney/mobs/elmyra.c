inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/wicket/tv/looney/armor/buttonshoe.c"), this_object()); 
  command("wear shoes", this_object());
  move_object(clone_object("/players/wicket/tv/looney/armor/cheerskirt2.c"), this_object()); 
  command("wear skirt", this_object());
  move_object(clone_object("/players/wicket/tv/looney/armor/cottonsocks.c"), this_object()); 
  command("wear socks", this_object());
  move_object(clone_object("/players/wicket/tv/looney/armor/skullbow.c"), this_object()); 
  command("wear bow", this_object());
  move_object(clone_object("/players/wicket/tv/looney/armor/dressshirt.c"), this_object()); 
  command("wear shirt", this_object());
  set_name("elmyra");
  set_alt_name("duff");
  set_race("toon");
  set_alias("toon elmyra");
  set_short(HIC+"Elmyra"+HIW+" Duff"+NORM);
  set_long("\
   A cute little girl that looks very adorable. She has fire red hair that\n\
  seems to barely reach her shoulders. A Small Blue bow sits on top of \n\
  her head, in the center is a very tiny skull. Her cheeks are chunky and\n\
  she has the most innocent grin. She wears a blue shirt with sleeves that\n\
  are fluffy, the sleeves around the arm have a lace trim. A white skirt\n\
  starts at the bottom of her shirt right at her waist. The skirt goes down\n\
  just slightly past her knees. Her pale white legs stick out the bottom of the\n\
  skirt, soft cotton socks cover her ankles down to her pretty leather button\n\
  across shoes.\n");
  add_spell("deathug","#MN# $HK$squeezes$N$ you with a$HK$MASSIVE $M$HUG $HR$crushing $N$your $HW$bones$N$.\n",
                       "#MN# $HK$squeezes$N$ #TN# with a$HK$ MASSIVE $M$HUG $HR$crushing$N$ their $HW$bones$N$.\n",
                       40,40,0,0);
  set_level(19);
  set_hp(570+ random(30));
  set_ac(16+ random(3));
  set_wc(24+ random(8));
  set_al(0);
}
