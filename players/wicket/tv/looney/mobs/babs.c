inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/wicket/tv/looney/armor/smallbow.c"), this_object()); 
  command("wear bow", this_object());
  move_object(clone_object("/players/wicket/tv/looney/armor/cheerskirt.c"), this_object()); 
  command("wear skirt", this_object());
  move_object(clone_object("/players/wicket/tv/looney/armor/yellowshirt.c"), this_object()); 
  command("wear shirt", this_object());
  set_name("babs");
  set_alt_name("bunny");
  set_race("toon");
  set_alias("toon babs");
  set_short(MAG+"Babs Bunny"+NORM);
  set_long("\
   Buster Bunny's parter in crime, this is Babs bunny. She is wearing a\n\
  yellow t-shirt that covers her soft pink fur, A small cute purple \n\
  ribbon is tied to her right ear. She wears a fitting white skirt\n\
  that comes just above her knees, A smile comes across her face as\n\
  if she seems to be happy all the time and cheerful. She looks around\n\
  for Buster wondering what to do next.\n");
  add_spell("babskick","#MN# jumps up in the air and lands a $HK$MASSIVE $HM$Rabbit $HK$Kick$N$ to the side of YOUR head.\n",
                       "#MN# jumps up in the air and lands a $HK$MASSIVE $HM$Rabbit $HK$Kick$N$ to the side #TN#\'s head.\n",
                       40,40,0,0);
  set_level(19);
  set_hp(550+ random(50));
  set_ac(16+ random(3));
  set_wc(24+ random(8));
  set_al(0);
  add_money(random(1500)+2500);
  }