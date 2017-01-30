inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>
reset(arg)
{
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/wicket/tv/looney/armor/pinkshirt2.c"), this_object()); 
  command("wear shirt", this_object());
  move_object(clone_object("/players/wicket/tv/looney/armor/yellowskirt.c"), this_object()); 
  command("wear skirt", this_object());
  move_object(clone_object("/players/wicket/tv/looney/armor/cottonsocks.c"), this_object()); 
  command("wear socks", this_object());
  move_object(clone_object("/players/wicket/tv/looney/armor/girlsneakers.c"), this_object()); 
  command("wear sneakers", this_object());
  set_name("mary");
  set_alt_name("melody");
  set_race("toon");
  set_alias("toon mary");
  set_short(HIM+"Mary"+MAG+" Melody"+NORM);
  set_long("\
   A young black girl short in height, She has long jet black hair that\n\
  is put up in a pony tail. She is wearing a dark magenta vneck cotton\n\
  shirt with a light yellow cotton skirt that flows.  Her sparkling hazel\n\
  eyes are enchanting and soft puffy lips accent her beautiful face and\n\
  soft skin. She wears a light purple pair of sneakers with cotton socks.\n");
  add_spell("melodyslap","#MN# $HM$slaps$N$ you across the face cause you to $HK$stumble$N$.\n",
                       "#MN# $HM$slaps$N$ #TN# across the face causing them to $HK$stumble$N$.\n",
                       40,40,0,0);
  set_level(19);
  set_hp(550+ random(50));
  set_ac(16+ random(3));
  set_wc(24+ random(8));
  set_al(0);
}