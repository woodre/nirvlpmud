inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/wicket/tv/looney/heals/smallcarrot.c"), this_object());
  move_object(clone_object("/players/wicket/tv/looney/armor/redshirt.c"), this_object()); 
  command("wear shirt", this_object());
  set_name("buster");
  set_alt_name("bunny");
  set_race("toon");
  set_alias("toon buster");
  set_short(HIC+"Buster Bunny"+NORM);
  set_long("\
   Babs Bunny's parter in crime, this is Buster bunny. He is wearing a small\n\
  red t-shirt that covers her soft blue fur. His belly slightly sticks out\n\
  from his shirt as if the shirt is a little to small. He Carries a carrot\n\
  in his hand. He seems to always be munching on something and talking. A\n\
  smile comes across his face as if he seems to be happy all the time and\n\
  cheerful. He looks around for Babs wondering what to do next.\n");
  add_spell("busterkick","#MN# jumps up in the air and lands a $HK$MASSIVE $HC$Rabbit $HK$Kick$N$ to the side of YOUR head.\n",
                       "#MN# jumps up in the air and lands a $HK$MASSIVE $HC$Rabbit $HK$Kick$N$ to the side #TN#\'s head.\n",
                       40,40,0,0);
  set_level(19);
  set_hp(550+ random(50));
  set_ac(16+ random(3));
  set_wc(24+ random(8));
  set_al(0);
  add_money(random(2000)+2000);
  }