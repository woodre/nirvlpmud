/* Wound object for Shardak guild - (tm) Dragnar/John
 * Wound object is (c) Balowski/Rasmus, January 24th 1995.
 * Last change: Jan 28th '95 - Bal (extra_look(), init() + command())
 */

/* This object is put into the wounded monster
 * Only one wound is allowed at a time per player
 * Uses "room/room" convert_number()
 */

#define DAMAGE 10       /* maximum dmg done by 1 wound per round */

mapping wounders;       /* list of assassins & wound depth */
object victim;          /* environment() until death */
string extra;           /* gash is invisible, but has extra_look */

/*
 * Applied lfuns
 */

id(str) { return str == "shardakgash";}

reset( arg) {
  if (arg) return;
}

/* getable */
get() { return 1;}

/* wound is not dropable and will therefore destruct when victim dies */
drop() { return 1;}     

short() { return 0;}
long() { write( "Gashes inflicted by a servant of Shardak.\n");}
extra_look() { return extra;}

/* victim is commanded to gash_me by this object */
init() { add_action( "gash_me", "gash_me");}

/*
 * Various lfuns
 */

set_victim( object monster) {
  victim= monster;
}

set_short(amt) {
  if (amt == 0)
    extra= 0;
  else {
    extra= victim->query_name() + " is marked with " +
        call_other( "room/room", "convert_number", amt);
    if (amt > 1)
      extra+= " gory gashes";
    else
      extra+= " gory gash";
  }
}


/* I don't really know if this is a bad idea to use objects */
/* what if somebody quits? */
/* query_name() is a nice thing to use. It's not unique though */

add_wound( string who, int depth) {
  if (!wounders) {
    wounders= ([ who:depth ]);
    set_short( 1);
    call_out( "hb", 2, 0);
  }

  if (wounders[ who]) {
    wounders[who]= depth;
  }
  else {
    wounders+= ([ who:depth ]);
    set_short( sizeof( wounders));
  }
}

reduce_wound( string who, int less) {
  int damage;

  damage= wounders[ who];
  if (damage <= less) {
    if (who)
      say( "The gash inflicted to " + victim->query_name() + " by " +
          who + " has almost healed up.\n");
    deletem( wounders, who);
    set_short( sizeof( wounders));
    return damage;
  }
  else {
    wounders[ who] -= less;
    return less;
  }
}


inflict( int damage) {
  string msg, name;

  /* hit_player may change alt_attacker ? */
  /* another possibility is to command the wounded */

  if (victim->query_attack()) {
    damage= victim->hit_player( damage);
  }

  /* if victim survived give message */
  if (victim) {
    name= victim->query_name();

    /* not too pretty, but who cares ;-) */
    /* says gashes/wounds, even if only one gash.. */
    if (damage > 25)
      msg= name + "'s lifeforce pours out through the bleeding gashes.\n";
    else if (damage > 12)
      msg= "The gashes make " + name + " stumble around, blind with pain.\n";
    else if (damage > 5)
      msg= name + " slashes wildly at you, frenzied by " + possesive( victim) + " wounds.\n";
    else
      msg= name + " is slightly annoyed by " + possessive( victim) + " wounds.\n";

    say( msg);
  }
}


hb() {
  /* I assume this is executed instantly */
  command( "gash_me", victim);

  if (sizeof( wounders))
    call_out( "hb", 2, 0);
}


gash_me() {
  string *who;
  int i;
  int damage;
  object at;

  /* find total amount of damage inflicted by wounds */
  /* this is walk_mapping.. all keys are iterated through */

  who= keys( wounders);
  for ( i= sizeof( who) - 1; i >= 0; i--) {
    at= who[ i];
    if (at &&
        at->query_attack() == victim &&
        environment(at) == environment( victim))
      damage+= reduce_wound( who[ i], DAMAGE);
    else {
      /* heal if no foe/foe absent */
      say( "One o gashes heals quickly.\n");
      reduce_wound( at, DAMAGE);
    }
  }

  /* punish the victim, hehe */
  inflict( damage);

  /* keep object even if no wounds are left */
  /*
  if (sizeof( wounders))
    call_out( "hb", 2, 0);
  */
}
