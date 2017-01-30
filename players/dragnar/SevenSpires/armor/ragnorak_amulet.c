inherit "obj/treasure";
#include <ansi.h>

void
reset(int arg) {
  if (arg) 
    return;

  set_id("amulet");
  set_short("An amulet of Protection");
  set_long( "TBD.\n");
  set_value(5000);
  set_weight(1);
  set_save_flag(1);
  set_dest_flag(1);
}

init() {
  object env;

  ::init();
  env = environment();
  if( !env || !env->is_player() )
    return;

  if( !env->QueryArmor( this_object() ) ) {
    env->RegisterArmor( this_object(), ({"other|spire_nrg",0,100,"amulet_effect"}) );
    tell_object( env, "You feel protection from the amulet wrap around you.\n" );
  }

}

amulet_effect() {
  object env;

  env = environment();

  if( env && env->is_player() ) {
    tell_object(env, "\n\tThe amulet "+HIC+"G L O W S "+NORM+"as it absorbs the energy!\n\n"+NORM);
  }
}

drop() {
  object who;

  who = environment();
  if( !who || !who->is_player() )
    return 0;

  if( who->QueryArmor( this_object() ) ) {
    who->RemoveArmor( this_object() );
    tell_object( who, "You drop the amulet and it's protection vanishes.\n");
  }
  return 0;
}
