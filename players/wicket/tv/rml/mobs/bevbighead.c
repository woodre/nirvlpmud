inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/wicket/tv/rml/armor/bevnecklace.c"), this_object()); 
  command("wear necklace", this_object());
  move_object(clone_object("/players/wicket/tv/rml/armor/bevdress.c"), this_object()); 
  command("wear dress", this_object());
  set_name("bev");
  set_alt_name("bighead");
  set_race("toon");
  set_alias("toon bev");
  set_short(GRN+"Bev Bighead"+NORM+"" );
  set_long("\
   A neighnor of Rocko and the wife of Ed, she is very grumpy amd old. \n\
  she likes her personal space to relax and have some down time and quiet\n\
  time to herself.\n");
  add_spell("tonguesmack","#MN# $HK$lashes out his $HR$tongue$N$ smacking you across the face $R$tearing flesh$N$.\n",
                        "#MN# $HK$kasses$N$ out his $HR$tongue$N$ smacking #TN# across the face $R$tearing flesh$N$.\n",
                        40,30,0,0);
  set_level(19);
  set_hp(560+ random(40));
  set_ac(15+ random(3));
  set_wc(22+ random(5));
  set_al(0);
  add_money(random(2500)+1000);
  }