inherit "obj/monster.c";
#include "/players/tristian/lib/supermaxdefine.h"
id(str) { return (::id(str) || str == "convict" || str == "con"); }

reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("Skin Head");
  set_alt_name("convict");
  set_race("human");
  set_alias("skin head");
  set_gender("male");
  set_short("Skin Head");
  set_long(
    "A noephyte skin head.  He has a shaved head and tattoo's all over his body. He is\n"+
    "wearing prison dungarees and a white tee shirt with the sleeves rolled up to show off\n"+
	"a swastika tattoo on his left shoulder and a bust of Adolph Hitler on his right. This\n"+
	"member has spider web tattoo's on both elbows, signifying that he has killed a member\n"+
	"of a minority.  He committed some sort of racially motivated crime and is serving a\n"+
	"life sentence.\n\n");
  set_level(29);
  set_ac(50+random(10));
  set_wc(35+random(10));
  set_ac_bonus(10);
  set_wc_bonus(5);
  set_hp((1200)+random(200));
  set_al(-1);
  set_aggressive(0);
  set_heart_beat(1);
  set_wander(1);
  set_wander_interval(5);
  set_wander_realm("/players/tristian/realms/supermax/rooms/");
  add_money(3500+random(1500));
  set_chat_chance(10);
  load_chat(
    "The skinhead states:  'White Power!'\n");
  set_a_chat_chance(10);
  load_a_chat(
    "The skinhead hollars for help from his nearby gang.\n");


  set_dead_ob(this_object());
 
	add_spell("club","#MN# clubs you with with a bar of soap dropped in a tube sock.\n",
                     "#MN# clubs #TN# with a bar of soap dropped in a tube sock.\n",
                     80,40-80,"physical");
    add_spell("shiv","#MN# stabs you with a sharpened toothbrush called a $HR$shiv$N$.\n",
                     "#MN# stabs #TN# with a $HR$shiv$N$.\n",
                     40,60-100,"physical");
	add_spell("jawpunch","#MN# punches you in the $HY$jaw$N$ so hard your $HY$eyes$N$ water.\n",
                     "#MN# slams #TN# in the $HR$jaw$N$ so hard #TN#'s $HY$eyes$N$ start to water.\n",
                     10,100-140,"physical");

}

heart_beat() {
  int i;
  object *inv;
  ::heart_beat();

  if( attacker_ob ) {
    if( present("skinhead", attacker_ob ) ) {
     return 1;
    }
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
}
