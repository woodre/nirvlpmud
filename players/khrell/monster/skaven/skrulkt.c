#include "/players/khrell/define.h"
#include <ansi.h>

inherit "/players/vertebraker/closed/std/monster.c";

reset(arg) {
object gold;
  ::reset(arg);
  if(arg) return;
  set_name(HIW+"Master Warlock Skrulkt"+NORM);
  set_alt_name("warlock");
  set_alias("skrulkt");
  set_short(HIW+"Master Warlock Skrulkt"+NORM);
  set_long(
"  Master Warlock Skrulkt is a fearsome and imposing skaven.  Most of\n"+
"his body has been replaced with machinery.  Great hissing pistons\n"+
"grant him strength in his limbs he could never otherwise attain.  A\n"+
"pair of brutal claws adorn his paw-hands, and a small occasional\n"+
"spark of electricity flickers over their surface.  His one remaining\n"+
"eye glares out at you with unfathomable hatred.\n");
  set_gender("male");
  set_race("skaven");
  set_level(27);
  set_wc(50);
move_object(clone_object("/players/khrell/armors/skaven/skrulkarmr.c"));
init_command("wear armor");  
  set_ac(45);
  set_ac_bonus(10);
  set_hp(1500);
  set_heal(50,3);
  set_al(-1000);
  set_aggressive(5);  


  set_chat_chance(10);
load_chat("Your hair stands on end.\n");
load_chat("Skrulkt glares at you!\n");
load_chat("Hot steam scalds your skin!\n");
  
  set_multi_cast(1);
  
  add_spell("claw slam",
"#MN# grips you in one of his claws....\n"+
"                    lifts you high into the air.....\n"+
"       then......\n"+
"             $HR$S L A M S$N$ you on the ground!\n",
"#MN# grips #TN# in one of his claws and slams them on the ground!\n",
10,100,"physical");

  add_spell("warp flame",
"#MN# releases a torrent of $G$warp flame$N$, burning everything!\n",0,
10,180,({"other|fire","other|evil"}),1);  


gold = clone_object("obj/money");
gold->set_money(random(7000));
move_object(gold,this_object());
}

monster_died() {
  tell_room(environment(this_object()),
  "\n"+HIW+"Master Warlock Skrulkt"+NORM+" squeaks in agony then collapses to the ground!\n");
    return 0;
}    
