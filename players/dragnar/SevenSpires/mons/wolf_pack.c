inherit "/obj/monster";
#include <ansi.h>
/******************************************************************************
 * Program: wolf_pack.c
 * Path: /players/dragnar/SevenSpires/mons
 * Type: Mob
 * Created: October 22nd, 2014 by Dragnar
 *
 * Purpose: A mid level monster in the Seven Spires area. 
 * History:
 *          10/22/2014 - Dragnar
 *            Created
 ******************************************************************************/
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  SetMultipleIds( ({ "wolf pack" }) );
  set_name("pack");
  set_race("wolf");
  set_short(HIBLK+"A Wolf Pack"+NORM);
set_long(
"A pack of hungry wolves with members of various colors. This\n\
pack is not starving, so they probably won't attack unless they\n\
are provoked. The alpha is a huge grey beast that has "+RED+"blood"+NORM+"\n\
stains around his muzzle. The rest of his pack looks more than\n\
willing to do his bidding.\n");

  set_gender("creature");
  set_level(21);
  set_hp(1400+random(200));
  set_wc(60);
  set_ac(25);
  set_al(-50);
  
  add_spell("alpha_strike",
    "The Alpha Male leaps and his $HW$Fangs $HR$spray your blood$N$ all over the ground!\n",
    "#TN#'s $HR$blood sprays all over the ground$N$ as the Alpha male's $HW$Fangs$N$ flash.\n",
    25,"20-60","physical" );
}

init() {
  ::init();
}

heart_beat() {
    ::heart_beat();
}
