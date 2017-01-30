inherit "/obj/monster";

#include <ansi.h>
/******************************************************************************
 * Program: ragnorak.c
 * Path: /players/dragnar/SevenSpires/mons
 * Type: Mob
 * Created: March 18th, 2015 by Dragnar
 *
 * Purpose: A high level monster in the Seven Spires area. He has a huge spell
 *          that will be certain death for a player unless they have gotten
 *          a blessing by a cleric mob that protects them from the spell
 *          dtype.
 * Specials:
 *    1. Must get approval from a cleric and get the blessing to protect them
 *       from the Energy spell.
 *    2. Multicast, with mage phant obj which does damage over time.
 * History:
 *          03/16/2015 - Dragnar
 *            Created
 ******************************************************************************/
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  SetMultipleIds( ({ "ragnorak the shadowmage", "shadowmage", "mage", }) );
  set_name("ragnorak");
  set_race("human");
  set_short("Ragnorak the "+HIK+"ShadowMage (Rogue)"+NORM);

  set_long(
"A younger man around his thirtieth year, he is very tall and lean.\n\
Although thin, he seems to be all muscle and sinew. His dirty blond\n\
hair hangs down into his eyes and adds to his dangerous appearance.\n\
His very dark, almost black eyes do nothing to soften his look. A man\n\
his age should not look so burdened.\n\
Ragnorak has 3 thick black rings tattooed on his left wrist.\n");

  set_gender("male");
  set_level(25);
  set_al(-500);
  set_hp(1200+random(400));
  set_wc(70);
  set_ac(35);
  /** Phant bonus for dmg done by cloned obj **/
  set_wc_bonus( 20 );
  set_multi_cast(1);
  
  add_spell("leg_sweep",
    "#MN# suddenly executes a leg sweep and follows it up with a vicious Elbow strike!\n",
    "#MN# sweeps #TN#'s legs from under them and follows it up with a vicious Elbow strike!\n",
    30, 70 );
  
  add_spell("phant",
    "#MN# weaves the $HK$illusion$N$ of $M$Phantasmagoria$N$ into the mind of #TN#.\n",
    "#MN# weaves the $HK$illusion$N$ of $M$Phantasmagoria$N$ into the mind of #TN#.\n",
    15, "70-100", "other|evil", 6, "phant_spell");
  
  add_spell("cure_spell",
    "#MN# casts a $B$Cure$N$ spell and his body is covered with an $B$aura$N$.\n",
    "#MN# casts a $B$Cure$N$ spell and his body is covered with an $B$aura$N$.\n",
    60, 0, 0, 0, "cure_spell");
    
  add_spell("energy_flare",
    "\n\n#MN# raises his hands to the sky and an enormous $HC$E N E R G Y   F L A R E$N$ flashes!\n\n",
    0,
    40,0, 0, 3, "energy_flare_spell" );
    
}

heart_beat() {
  ::heart_beat();
}

void cure_spell( object target, object room, int damage ) {
  this_object()->heal_self(50);
  set_hp_bonus( hp_bonus + 50 );
}

void phant_spell( object target, object room, int damage ) {
  object phant;
  
  if( present("phantasm", target ) )
    return;
  
  phant = clone_object("/players/pavlik/guild/mages/objects/phantasm.c");
  phant->set_target( target );
  phant->set_owner( this_object() );
  move_object( phant, target );
  phant->set_damage( 125 );
}

void energy_flare_spell( object target, object room, int damage ) {
  /** This is only done so dmg is not included in xp calc **/
  if( target )
    target->hit_player( 200+random(600), "other|spire_nrg" );
}
