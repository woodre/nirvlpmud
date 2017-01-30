inherit "obj/monster";
#include <ansi.h>

#define EXPOSE "/players/shinshi/closed/rogue/spells/expose"
#define SSTRIKE "/players/shinshi/closed/rogue/spells/sstrike"
#define BACKSTAB "/players/shinshi/closed/rogue/spells/backstab"
#define EVISCERATE "/players/shinshi/closed/rogue/spells/evis"
#define AMBUSH "/players/shinshi/closed/rogue/spells/ambush"
#define GARROTE "/players/shinshi/closed/rogue/spells/garrote"
#define SAP "/players/shinshi/closed/rogue/spells/sap"
#define BLIND "/players/shinshi/closed/rogue/spells/blind"
#define SHADOWSTEP "/players/shinshi/closed/rogue/spells/shadowstep"
#define OFFHAND "/players/shinshi/closed/rogue/spells/offhand"

int player_flag;
object gob, gold;

reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name(""+BOLD+"Crystal"+NORM+" "+HIR+"M"+RED+"athews"+NORM+"");
  set_race("rogue");
  set_alias("crystal");
	set_short(""+BOLD+"Crystal"+NORM+" "+HIR+"M"+RED+"athews"+NORM+"");
	set_long("Black Oozing semi-liquid makes up this beast's entirety. A huge\n"+
" menacing mouth and glaring white eyes, its shape constantly fluctuating, changing\n"+
" shape right before your eyes.\n");
  set_level(21);
  set_hp(1200+random(500));
  set_hp_bonus(500);
  set_heal(25, 5);
  set_al(-1000);
  set_ac(30);
  max_spell = 1000;
  spell_points = 1000;
   move_object(clone_object("/players/sami/area/coinarea/obj/wep/msword.c"),this_object());
init_command("wield sword");
   move_object(clone_object("/players/sami/area/coinarea/obj/wep/msword.c"),this_object())->offwield(this_object());
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
    gob = clone_object("/players/shinshi/closed/rogue/gob2.c");
    move_object(gob, this_object());
  }
  
  if( attacker_ob ) {
    SHADOWSTEP->main( "", gob, this_object() );
    
    if( !random(2) )
      EVISCERATE->main("40", gob, this_object() );
    else
      SSTRIKE->main("", gob, this_object() );
      
	  if( !random(2) )
	  SAP->main("", gob, this_object() );
	else
	  BLIND->main("40", gob, this_object() );
  }
    
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
