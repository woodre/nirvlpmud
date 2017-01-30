
/***************************************************************
 * Daikatana Damage Shield (DDS) Testing
 *
 * Mob will activate a 500HP damage shield 3 times at
 * 98%, 58%, and 18% hitpoints
 *
 * Damage shield will prevent all damage from attackers until it has
 * prevented 500 damage while reverting half of that damage back to 
 * the attacker who initiated it
 *
 * Thanks to Dragnar for 
 * majority of coding for shield and damage meter 
 ***************************************************************/

inherit "/obj/monster";

#include <ansi.h>

#define MAXSHIELD 500

int shield;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  SetMultipleIds( ({ "lost girl", "ddstest" }) );
  shield = MAXSHIELD;
  
  set_name("girl");
  set_race("human");
  set_short("A Lost Girl");
set_long(
"A young girl, around 10 or 12 years old with dark brown hair.  She\n\
must have been out here for a few days by herself, her clothes are\n\
torn and filthy and she has scratches on her arms from a few falls\n\
she has taken. It is amazing that she has lasted this long on her\n\
own without any help. She has no chance to survive an encounter with\n\
a Walker without someone to protect her however.\n");

  set_gender("female");
  set_level(7);
  set_hp_bonus( MAXSHIELD );
  
  set_aggressive(0);
  set_al(500);
  
  /*
  set_chat_chance(10);
  load_chat("The lost girl looks at you as a tear rolls down her face.\n");
  load_chat("The lost girl says: 'I ran away as Walkers ate my Daddy.'\n\
The girl begins to sob into her hands.\n");
  load_chat("The lost girl says: 'They are everywhere, don't leave me here please!'\n");
  */
}

init() {
  ::init();
}

long() {
  int cols;
  string color;
  
  ::long();
  if( shield > 0 ) {
    cols = shield * 100 / MAXSHIELD;
    switch( cols ) {
      case 0..30:
        write(HIR);
        break;
      case 31..70:
        write(HIY);
        break;
      default:
        write(HIG);
        break;
    }

    /** Adjust to a line limit of 80 **/
    cols = cols * 80 / 100;

    if( cols == 0 )
      cols = 1;

    if( cols > 80 )
      cols = 80;

    write( pad("", cols, '#') );
    write( "\n" +NORM );
    write("The shield is at: "+shield+"\n");
  }
}

heart_beat() {
    ::heart_beat();
}

do_damage(int *damage, string *method){
  int i, dam;
  object target;
  
  int cols;
  string color;
  
  if( shield ) {
    tell_room( environment(), "\n\The girl laughs as damage bounces off her shield.\n");
    for( i=0; i < sizeof(damage); i++) {
      dam += damage[i];
    /* } moved bracket down */ 
    reduce_shield( dam );
    target = this_player();
    if( target ) {
      target->hit_player( dam );
      tell_room( environment(), "\n\n\The "+dam+" damage reflects off the shield back at "+target->query_name()+"!\n");
    }
    }  /** moved to here **/
	
    
	/** To display the shield meter to the room **/
  
    if( shield > 0 ) {
    cols = shield * 100 / MAXSHIELD;
    switch( cols ) {
      case 0..30:
        write(HIR);
        break;
      case 31..70:
        write(HIY);
        break;
      default:
        write(HIG);
        break;
    }

    /** Adjust to a line limit of 80 **/
    cols = cols * 80 / 100;

    if( cols == 0 )
      cols = 1;

    if( cols > 80 )
      cols = 80;
	
    tell_room(environment(), "\n\SHIELD STRENGTH\n"  );
	tell_room(environment(), pad("", cols, '#')) ;
    tell_room(environment(), "\n" +NORM );
    tell_room(environment(), "The shield is at: "+shield+"\n");
	}
  }
  else {
    return ::do_damage( damage, method);
  }
}


reduce_shield( int dam ) {
  if( shield > 0 ) {
    shield -= dam;
    if( shield < 0 )
      shield = 0;
  }
}