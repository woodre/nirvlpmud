inherit "obj/monster.c";
#include "/players/tristian/lib/supermaxdefine.h"
id(str) { return (::id(str) || str == "convict" || str == "con" || str == "panther" ); }

reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("Black Panther");
  set_alt_name("convict");
  set_race("human");
  set_alias("panther");
  set_gender("male");
  set_short("A member of the Black Panthers");
  set_long(
    "xxx\n"+
    "xxx\n"+
	"xxx\n"+
	"xxx\n"+
	"xxx\n"+
	"xxx\n\n");
  set_level(25);
  set_ac(5+random(10));
  set_wc(35+random(10));
  set_hp((1000)+random(200));
  set_al(-1);
  set_aggressive(1);
  set_heart_beat(1);
  set_wander(1);
  set_wander_interval(5);
  set_wander_realm("/players/tristian/realms/supermax/rooms/");
  add_money(3500+random(1500));
  set_chat_chance(10);
  load_chat(
    "The black panther raises a clenched fist and states: 'Panther Power!'\n");
  set_a_chat_chance(10);
  load_a_chat(
    "The black panther hollars for help from his nearby gang.\n");

  move_object(clone_object("/players/tristian/realms/supermax/obj/teeshirt.c"),this_object());
    init_command("wear shirt");
  move_object(clone_object("/players/tristian/realms/supermax/obj/dungarees.c"),this_object());
    init_command("wear pants");

  set_dead_ob(this_object());
 
    add_spell("shiv","#MN# stabs you with a sharpened toothbrush called a $HR$shiv$N$.\n",
                     "#MN# stabs #TN# with a $HR$shiv$N$.\n",
                     20,40-60,"physical");
	add_spell("jawpunch","#MN# punches you in the $HY$jaw$N$ so hard your $HY$eyes$N$ water.\n",
                     "#MN# slams #TN# in the $HR$jaw$N$ so hard #TN#'s $HY$eyes$N$ start to water.\n",
                     40,55-75,"physical");
}

heart_beat() {
  int i;
  object *inv;
  ::heart_beat();
  
  if( attacker_ob ) {
    set_wander_interval( 999999 );
    inv = all_inventory( environment() );
    for( i=0; i < sizeof(inv); i++ ) {
      if( inv[i]->is_npc() && inv[i]->query_alias() == alias )
        inv[i]->attacked_by( attacker_ob );
    }
  }
  else
    set_wander_interval( 5 );
}
