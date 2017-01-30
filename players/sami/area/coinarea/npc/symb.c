inherit "obj/monster";
#include <ansi.h>

#define ABSORB "/players/fred/closed/venom/power/absorb"
#define BITE "/players/fred/closed/venom/power/bite"
#define FATAL "/players/fred/closed/venom/power/fatal"
#define HYPER "/players/fred/closed/venom/power/hypermode"
#define LINK "/players/fred/closed/venom/power/link"
#define WEBSLAM "/players/fred/closed/venom/power/webslam"
#define WEB "/players/fred/closed/venom/power/web"

int player_flag;
object gob, gold;

reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name(""+BOLD+"Venom"+NORM+"   (  "+HIR+"Symbiote"+NORM+"  )");
  set_race("symb");
  set_alias("venom");
	set_short(""+BOLD+"Venom"+NORM+"   (  "+HIR+"Symbiote"+NORM+"  )");
	set_long("Black Oozing semi-liquid makes up this beast's entirety. A huge\n"+
" menacing mouth and glaring white eyes, its shape constantly fluctuating, changing\n"+
" shape right before your eyes.\n");
  set_level(21);
  set_hp(1200+random(500));
  set_hp_bonus(500);
  set_heal(25, 5);
  set_al(-1000);
  set_ac(30);
   move_object(clone_object("/players/sami/area/coinarea/obj/barter/projector.c"),this_object());
  max_spell = 1000;
  spell_points = 1000;
  
  enable_commands();
  set_dead_ob( this_object() );
  
  set_wc(30);
  set_wc_bonus(50);
  set_can_kill(1);
  
}

monster_died() {
  if( gob )
    destruct( gob );
}

heart_beat() {
  max_spell = 1000;
  spell_points = 1000;
  if( !gob ) {
    gob = clone_object("/players/fred/closed/venom/venom.c");
    move_object(gob, this_object());
    gob->set_symbiote("venom");
    gob->set_uncovered( 0 );
    gob->set_hyper_mode( 5000 );
    gob->add_hyperstat(10000 );
    gob->set_slamstat(10000);
    gob->set_changestat(10000);
    gob->set_mp( 1000 );
    gob->set_bitestat( 10000 );
  }
  gob->set_bite_delay( 0 );
  gob->set_hyper_mode( 5000 );
  if( !gob->query_venomed() ) {
    gob->changeform();
    LINK->main( "axe", gob, this_object() );
  }
  if( attacker_ob ) {
    HYPER->main( "", gob, this_player() );
    
    if( !random(2) )
      WEBSLAM->main("40", gob, this_player() );
    else
      BITE->main("", gob, this_player() );
      
    /*WEB->main("", gob, this_player() );*/
    if( attacker_ob->query_hp() < 50 )
      FATAL->main( "", gob, this_player() );
  }
  if( !random(10) )
    gob->new_say("Welcome to your death!!");
  
  if( present("corpse", environment() ) )
    ABSORB->main( "", gob, this_player() );
    
  ::heart_beat();
}

/** For testing 
init() {
  ::init();
  add_action("test","test");
}

test(string str) {
  string action, arg;
  sscanf( str, "%s %s", action, arg );
 
  command( str );
  return 1;
}

catch_tell(string str) {
  tell_object( find_player("dragnar"), "%"+str );
}
**/

is_player() { 
  if( previous_object() && gob && previous_object() == gob )
    return 1;
  return 0; 
}

query_sp() { return 1000; }

query_attrib(string str) { return 30; }

query_extra_level() { return 100; }
