inherit "/obj/monster";

#include <ansi.h>
/******************************************************************************
 * Program: fenris.c
 * Path: /players/dragnar/SevenSpires/mons
 * Type: Mob
 * Created: March 16th, 2015 by Dragnar
 *
 * Purpose: A high level monster in the Seven Spires area. He is healed by
 *          a mob hidden in a room nearby. If that mob is not killed first
 *          Fenris is not killable.
 * Specials:
 *    1. Must find and kill caurib the witch before he can be killed, a
 *       powerful mob. If not, Fenris is not killable.
 *    2. Makes players run away and unable to move for a period of time.
 *    3. 
 * History:
 *          03/16/2015 - Dragnar
 *            Created
 ******************************************************************************/
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  SetMultipleIds( ({ "fenris the feared" }) );
  set_name("fenris");
  set_race("human");
  set_short("Fenris "+BLU+"The Feared"+NORM);
  set_heal( 50, 3 );
  set_long("A giant of a man, Fenris appears as if he was built on scale apart\n\
from normal men. The left side of his body is a deep "+BLU+"blue"+NORM+". When\n\
looking closely it appears the blue is actually words tattooed onto\n\
his body. His right side is covered in armor that is made from black\n\
plates that fit together. His head is bald and the blue symbols are\n\
scrawled over the left side of his face including his lips and eyelids.\n\
His mouth is in a constant sneer and evil grin. The vision of him sends\n\
fear into the hearts of the bravest of men.\n");

  set_gender("male");
  set_level(28);
  set_hp(2000+random(500));
  set_wc(125);
  set_ac(50);
  set_al(-1000);
  
  add_spell("stomp",
    "#MN# pulls up his huge $G$foot$N$ and S C R E A M S as he $G$S T O M P S$N$ on you!\n",
    "#MN# pulls up his huge $G$foot$N$ and S C R E A M S as he $G$S T O M P S$N$ on #TN#!\n",
    25,"80-180","physical" );
    
  if( !find_living("fenris_witch") )
    move_object( clone_object( "/players/dragnar/SevenSpires/mons/caurib.c"), "/players/dragnar/workroom" );
}

heart_beat() {
  ::heart_beat();
}

do_damage(int *damage, string *method){
  int i, dam;
  object shield;
  
  shield = find_living("fenris_witch");
  
  if( shield ) {
    tell_room( environment(), BLU+"\n\tThe symbols on Fenris' body glow with power.\n\n"+NORM);
    for( i=0; i < sizeof(damage); i++) {
      dam += damage[i];
    }
    set_hp_bonus( hp_bonus + dam );
  }
  else {
    return ::do_damage( damage, method);
  }
}

