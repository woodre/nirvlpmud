inherit "/obj/monster";
#include <ansi.h>
/******************************************************************************
 * Program: caurib.c
 * Path: /players/dragnar/SevenSpires/mons
 * Type: Mob
 * Created: March 16th, 2015 by Dragnar
 *
 * Purpose: A high level monster in the Seven Spires area. She powers Fenris
 *          The Feared's tattoos which heal him in battle. 
 *    NOTE: This mob is not loaded by the room, but by the fenris mob.
 * Specials:
 *   1. Will cause anything present to attack each player: pets, other players etc.
 *   2. Causes player to attack themselves with their own weapon.
 *   3. Mist spell is severe for this level.
 * History:
 *          03/16/2015 - Dragnar
 *            Created
 ******************************************************************************/
 int mist;
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  SetMultipleIds( ({ "caurib the sorceress", "fenris_witch", "sorceress", }) );
  set_name("caurib");
  set_race("human");
  set_heal( 30, 3 );
  set_short(HIW+"Caurib the Sorceress"+NORM);
set_long(
"A very tall, thin woman, Caurib is practitioner of the Art. She is\n\
very pale and ill-looking. Her cold, narrow, slanted eyes have a far\n\
away look like she is concentrating on something. She has an aura of\n\
power about her despite her looks, she will be dangerous if her focus\n\
is directed at someone threatening her.\n");

  set_gender("female");
  set_level(24);
  set_hp(1200+random(100));
  set_al(-800);
  set_wc(70);
  set_ac(30);
  /** For golden voice extra damage **/
  set_wc_bonus(25);
  set_heal(30,3);
  
  add_spell("summon_mist",
    "\n\n\t#MN# chants an ancient verse and a $HW$mist$N$ envelops the room.\n\n\n",
    "\n\n\t#MN# chants an ancient verse and a $HW$mist$N$ envelops the room.\n\n\n",
    20,"20-40","other|water", 3, "summon_mist" );
    
  add_spell("golden_voice",
    "\n\n\t$Y$#MN# whispers some sweet words into your ear$N$.\n\n\n",
    "\n\n\t$Y$#MN# whispers something into #TN#'s ear$N$.\n\n\n",
    15, 0, 0, 5, "golden_voice" );
}

int room_targets(object ob) {
  return (int)(ob->is_npc() || ob->is_player());
}

void summon_mist( object target, object room, int damage ) {
  mist = 10+random(10);
  add_spell("mist_damage",
    "The mist condenses on your skin and $HB$C O L D N E S S$N$ ravages your body!\n",
    0,
    30, 80-100, "other|water", 3 );
  remove_spell( "summon_mist" );
}

void golden_voice( object target, object room, int damage ) {
  int siz;
  string wepshort;
  object randtarget;
  object *targets;
  
  if( !target || !room )
    return;
  
#ifndef __LDMUD__
  targets = filter_array(all_inventory(environment()),"room_targets",this_object());
#else
  targets = filter(all_inventory(environment()), "room_targets", this_object());
#endif

  targets -= ({ target, this_object() });
  siz = sizeof(targets);
  wepshort = ((object)target->query_weapon() ? (string)target->query_weapon()->short() : 0);
  if( siz > 0 ) {
    randtarget = targets[random(siz)];
    tell_room( room, target->query_name()+" attacks "+randtarget->short()+HIR+" viciously"+NORM+(wepshort ? (" with their "+wepshort) : "" )+"!\n");  
    target->attack_object( randtarget ); 
  }
  else {
    /****************************************************************
     * Borrowed from Samurai iaijitsu command, credit to Vertebraker
     ****************************************************************/
    int dam;
    string *msg;
    object *weps;
    mapping weaps;
    int    s;

     if(target->query_weapon()) {
      weaps = (mapping) target->QueryWeapons();
      weps = keys( weaps );

      s = sizeof(weps);

      while(s--) {
        if(!target || target->query_ghost())
          continue;

        dam += (int) weps[s]->weapon_class();
        msg = (string *) weps[s]->query_message_hit(dam);
        write("You "+msg[1]+" "+target->query_name()+msg[0]+".\n");
        say(target->query_name()+" "+msg[1]+" "+target->query_name()+msg[0]+".\n");

        target->hit_player(dam*2, "physical");

      }
    }
    else {
      tell_room( room, target->query_name()+" turns "+target->query_possessive()+" powers upon "+target->query_objective()+"self.\n");
      target->hit_player(80, "physical");
    }
  }
}

init() {
  ::init();
}

heart_beat() {
  ::heart_beat();
  if( mist ) {
    mist--;
    if( mist <= 0 ) {
      remove_spell( "mist_damage" );
      add_spell("summon_mist",
        "\n\n\t#MN# chants an ancient verse and a $HW$mist$N$ envelops the room.\n\n\n",
        "\n\n\t#MN# chants an ancient verse and a $HW$mist$N$ envelops the room.\n\n\n",
        10,20-40,"other|water", 3, "summon_mist" );
        
      if( environment() )
        tell_room( environment(), HIW+"\n\n\tThe mist dissipates and the room slowly clears.\n\n\n"+NORM );
    }
  }
}
