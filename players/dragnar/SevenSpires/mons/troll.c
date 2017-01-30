inherit "/obj/monster";
#include <ansi.h>
/******************************************************************************
 * Program: troll.c
 * Path: /players/dragnar/SevenSpires/mons
 * Type: Mob
 * Created: October 22nd, 2014 by Dragnar
 *
 * Purpose: A mid level monster in the Seven Spires area.  Has a much higher
 *          than normal AC/hps, since he is a troll with armor like skin.
 * History:
 *          10/22/2014 - Dragnar
 *            Created
 ******************************************************************************/
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  SetMultipleIds( ({ "mountain troll" }) );
  set_name("troll");
  set_race("troll");
  set_short(GRN+"A Mountain Troll"+NORM);
set_long(
"A mountain troll with "+GRN+"sickly green"+NORM+" skin with brown splotches which\n\
make it easy to hide in the mountain ranges where his race roams.\n\
This is obviously a male because of his height and the length of\n\
his tusks that protrude from his lower jaw. His hair is a mane of\n\
long dark hair that falls to the middle of his back. His hair does\n\
not hide his long pointed ears however. Trolls are known for their\n\
size and strength, and this one looks as dangerous as the stories\n\
you have read.\n");

  set_gender("male");
  set_level(22);
  set_hp(900+random(100));
  set_ac(100);
  set_wc(35);
  set_al(-300);
  /* Skin resists magic but electric does more dmg
   * small brains means susceptible to those attacks */
  set_armor_params("other|electric",0,-50,0);
  set_armor_params("other|mental",0,-100,0);
  set_armor_params("magical",0,50,0);
  
  add_spell("stomp",
    "#MN# pulls up his huge $G$foot$N$ and S C R E A M S as he $G$S T O M P S$N$ on you!\n",
    "#MN# pulls up his huge $G$foot$N$ and S C R E A M S as he $G$S T O M P S$N$ on #TN#!\n",
    25,"10-50","physical" );
}

init() {
  ::init();
}

heart_beat() {
    ::heart_beat();
}
