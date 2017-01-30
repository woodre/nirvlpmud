inherit "/obj/monster";

#include <ansi.h>
/******************************************************************************
 * Program: xander.c
 * Path: /players/dragnar/SevenSpires/mons
 * Type: Mob
 * Created: March 18th, 2015 by Dragnar. Inspired by Karash's version of the
 *          thief he updated in Nightshade's area.
 *
 * Purpose: A high level monster in the Seven Spires area. 
 * Specials:
 *    1. Turns himself invis, calms flight, heals, then does a huge
 *       backstab spell that causes large damage.
 *    2. Multicast
 * History:
 *          03/18/2015 - Dragnar
 *            Created
 ******************************************************************************/
 int backstab;
 object backstab_target;
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  SetMultipleIds( ({ "xander the shadowmage", "shadowmage", "mage", }) );
  set_name("xander");
  set_race("human");
  set_short("Xander the "+HIK+"ShadowMage"+NORM);

  set_long(
"A man in the prime of his strength and wisdom, however it is difficult\n\
to determine his exact age. He is fit and muscular but also limber and\n\
flexible. He has short dark hair and olive skin. Parts of his face has\n\
serious scars from fire or acid burns which just seems to add to his\n\
aura of power and intimidation.\n\
Xander has 4 thick black rings tattooed on his left wrist.\n");

  set_gender("male");
  set_level(27);
  set_hp(1500+random(300));
  set_wc(74);
  set_ac(36);
  set_al(-200);
  /** Acid bonus & backstab bonus & healing while calmed **/
  set_ac_bonus( 30 );
  set_multi_cast( 1 );
  set_heal( 30, 3 );
  
  add_spell("knee_slam",
    "\n#MN# jumps up in the air and $HW$BRUTALLY$N$ slams his knee into your torso!\n\n",
    "\n#MN# jumps up in the air and $HW$BRUTALLY$N$ slams his knee into #TN#'s torso!\n\n",
    30, 110 );
  
  add_spell("acid",
    "#MN# $M$conjures$N$ an arrow of $Y$bubbling$N$ $G$acid$N$ and casts it into you.\n\
The arrow $HW$thuds$N$ into your body and $M$splatters$N$ it with $G$deadly acid$N$!\n",
    "#MN# $M$conjures$N$ an arrow of $Y$bubbling$N$ $G$acid$N$ and casts it into #TN#.\n\
The arrow $HW$thuds$N$ into #TN#'s body and $M$splatters$N$ it with $G$deadly acid$N$!\n",
    15, "70-100", "other|poison", 6, "acid_spell");
  
  add_spell("cure_spell",
    "#MN# casts a $B$Cure$N$ spell and his body is covered with an $B$aura$N$.\n",
    "#MN# casts a $B$Cure$N$ spell and his body is covered with an $B$aura$N$.\n",
    80, 0, 0, 0, "cure_spell");

  add_backstab_spell();
}

calm() {
  object enemy, ob;
  int x;

  ob = all_inventory(environment());
  x = 0;
  while(x < sizeof(ob)) {
    if(ob[x]->query_attack()) {
      enemy = ob[x]->query_attack();
      ob[x]->stop_fight();
      enemy->stop_fight();
    }
    x += 1;
  }
}

id(str) {
  if( backstab )
    return 0;
  else
    return ::id(str);    
}

heart_beat() {
  ::heart_beat();
  if( backstab && attacker_ob ) {
    while( remove_call_out( "TellRoom" ) != -1 )
      continue;
      
    TellRoom( 3 );
  }
}

void add_backstab_spell() {
  add_spell("backstab_spell",
    BWHT+"\n\n$HK$#MN# says in incantation and fades into the shadows$N$.\n\n",
    BWHT+"\n$HK$#MN# says in incantation and fades into the shadows$N$.\n",
    20, 0, 0, 0, "backstab_spell");
}
void cure_spell( object target, object room, int damage ) {
  this_object()->heal_self(50);
  set_hp_bonus( hp_bonus + 50 );
}

void backstab_spell( object target, object room, int damage ) {
  if( !target || !room || backstab )
    return;
  
  backstab = 1;
  backstab_target = target;
  set_short( 0 );
  calm();
  remove_spell( "backstab_spell" );
  room->set_light(-8);
  call_out( "TellRoom", 8+random(8), 1);
}

void acid_spell( object target, object room, int damage ) {
  object acid;
  
  if( present("acid_arrow", target ) )
    return;
  
  acid = clone_object("/players/pavlik/guild/mages/objects/acid_arrow.c");
  acid->set_target( target );
  acid->set_owner( this_object() );
  move_object( acid, target );
  acid->set_acid_damage( 125 );
}

TellRoom( int arg ) {
  object env;
  env = environment();
  if( !env )
    return;
  
  switch( arg ) {
    case 1:
      tell_room( env, "You hear a slight sound of movement in the darkness.\n");
      call_out("TellRoom", 7+random(5), 2 );
      break;
    case 2:
      tell_room( env, "A voice in the shadows says: 'Run now, while you still can.'\n");
      call_out("TellRoom", 7+random(7), 3);
      break;
    case 3:
      set_short("Xander the "+HIK+"ShadowMage"+NORM);
      if( backstab_target && env == environment( backstab_target ) ) {
        tell_room( env, HIK+"\n\nXander appears out of the shadows and "+HIR+"BACKSTABS "+
                        NORM+backstab_target->query_name()+"!\n\n");
        backstab_target->hit_player( 100 + random(200) );
        attacker_ob = backstab_target;
      }
      else
        tell_room( env, HIK+"Xander steps out of the shadows.\n"+NORM);
      backstab_target = 0;
      backstab = 0;
      env->set_light(0);
      call_out( "add_backstab_spell", 20 );
  }  
}
