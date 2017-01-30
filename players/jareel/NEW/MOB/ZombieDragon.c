/***********
This Mob and the Mob it comes from is not designed to be "Fair" or "Nice" or something that a player should
just be able to kill over an over again.  The Monster is designed with the idea that some players may want to
have a challenge and may want to see if it can be done.  Now as a player who is like this I may be the only 
player who is like this and may be the only one who ever really tries to kill this monster past the first
attempt or so.  That being said there is a place fore bigger than life mobs and such things should not be
put in a padded room just because they do not fit a mold.  No one is making people fight this mob it will be
in a very remote place in my realm and will probably sit there for a long time.
************/

inherit "/obj/monster";
#include "/players/jareel/define.h"
#define TO this_object()

#define d1  BOLD+GRN+"                          oHI"+NORM
#define d2  BOLD+GRN+"                        oMHMH                 XO"+NORM
#define d3  BOLD+GRN+"                        OHMMHo            oX!HMMo"+NORM
#define d4  BOLD+GRN+"                        -HMHM!            !MHMMX"+NORM
#define d5  BOLD+GRN+"                         HMHHHo            IMM!"+NORM
#define d6  BOLD+GRN+"                         XHHHHM!"+NORM
#define d7  BOLD+GRN+"   XMMM!o                IMHXHMMo                        OIo"+NORM
#define d8  BOLD+GRN+"   -HMHMMIo              OHHXXH-                      oAMHO"+NORM
#define d9  BOLD+GRN+"     -VMHHM!              HHXIHH                      OMHH-                    X"+NORM
#define d10 BOLD+GRN+"        -!HHHAo            XHIIIXo    oMX     oOHD    AHHV                  oX!HMMo"+NORM
#define d11 BOLD+GRN+"           -HHHAo          !HI!IXI    AM    AMHH-O OHHM!                   !MHMMX"+NORM
#define d12 BOLD+GRN+"             -XXHAo     o  -HI!OIX   oHH    AHHMV oIXHH-                    IMM!"+NORM
#define d13 BOLD+GRN+"              -!XIXOo  AMAOoH!OOIXo  !HX   AHHHV oIIHX"+NORM
#define d14 BOLD+GRN+"                -XIXXO OHHHHHIo  oHMMMXXHO !XIHHHIIHV-"+NORM
#define d15 BOLD+GRN+"                 -X!OIXIMHHXHIo  IHHH!HXo!IIXH!oIHV"+NORM
#define d16 BOLD+GRN+"                  -HOoO!IHHXIIO  oXH!!HMIOOX! OXHI"+NORM
#define d17 BOLD+GRN+"                   OMIo o!!II!O  OIIo!H!oOIOoIHVO"+NORM
#define d18 BOLD+GRN+"              OAMMHHII!Oo OOOOO   OOoIo oO OIHVo                           o!!O"+NORM
#define d19 BOLD+GRN+"                  oOoVMHIIOo i       ii   oIHHMI                    oOIHHMMMHMM!"+NORM
#define d20 BOLD+GRN+"     ooOOOooo      HHXIOo            OIXXHHMHo          oO!IXHHHHHMHHHX!-"+NORM
#define d21 BOLD+GRN+"AMMMMMMMMHHHHHHHXIIIII!!!OOOo            O!!IXHHHHHOooO!!XXXHHXI!O-"+NORM 

int calm_flag;
int zombie_flag;

reset(arg)  {
       ::reset(arg);
         if (arg) return;

     set_name("necrosan");
     set_alias("zombie");
     set_alt_name("zombie-dragon");
     set_race("dragon");
	 set_race("dark");
     set_al(-2000);
     set_level(50);
     set_aggressive(0);
     set_hp(6000);
     set_ac(105);
     set_wc(105);
     set_armor_params("other|light",0,-50,"prot_from_light"); 
     set_armor_params("other|dark",0,90,"prot_from_dark"); 
     set_armor_params("other|fire",0,-50,"prot_from_fire"); 
     set_armor_params("other|ice",0,50,"prot_from_ice"); 
     set_armor_params("other|evil",0,90,"prot_from_evil"); 
     set_armor_params("other|wind",0,50,"prot_from_wind"); 
     set_armor_params("other|electric",0,-50,"prot_from_electric"); 
     set_armor_params("other|good",0,-50,"prot_from_good"); 
     set_armor_params("other|water",0,-50,"prot_from_water"); 
     set_armor_params("other|earth",0,-50,"prot_from_earth"); 
     set_armor_params("other|laser",0,90,"prot_from_laser"); 
     set_armor_params("other|poison",0,90,"prot_from_poisen"); 
     set_armor_params("magical",0,75,"prot_from_magical");
     set_armor_params("other|sonic",0,75,"prot_from_sonic"); 
     set_armor_params("other|mental",0,75,0); 
    
     set_wc_bonus(168); /* +50 Heal Spell +8 spell2 , +8 spell 3 +Poison bonus + Zombie Bonus*/
     add_money(22);
     set_dead_ob(this_object());

     set_short(BOLD+
       "Necrosan - "+NORM+RED+"["+NORM+HIK+"Undead Legendary Dragon of the Red Moon"+NORM+RED+"] "+NORM+"(Absolute Evil Incarnate)");

     set_long(
       "A deathly, zombie-like dragon with torn, tattered skin covering his muscular\n"+
       "massive structure.  Necrosan towers over fetid, rotting, putrid corpses strewn\n"+
       "across the massive expanse of the cavern.  A green mucus fluid oozes from the\n"+
       "the orifices sinew of the rotting dragons muscles.  Necrosan disregards you much\n"+
	   "as you would disregard an ant crossing your path.\n");

    set_chat_chance(2);
    load_chat("Necrosan says:  Only the most worthy may gain access to the "+RED+"'Hero Realm'"+NORM+".\n");
    load_chat("Necrosan says:  The fight may not be a fair fight but the numbers will balance young warrior.\n"); 
    load_chat("Necrosan says:  Sometimes "+GRN+"failure"+NORM+" is the only way to move forward.\n");  

    add_spell( "acid hit","\n\ test this shit out",
       "Necrosan spews covers #TN# with "+HIG+"acid"+NORM+"!\n",    
       40,"8d6+20","other|acid");

    add_spell( "poison_attackers", "\n\
           "+d1+"\n"+d2+"\n"+d3+"\n"+d4+"\n"+d5+"\n"+d6+"\n"+d7+"\n"+d8+"\n"+d9+"\n"+d10+"\n"+d11+"\n"+d12+"\n"+d13+"\n"+d14+"\n"+d15+"\n"+d16+"\n"+d17+"\n"+d18+"\n"+d19+"\n"+d20+"\n"+d21+"\n", " test 2",
    25, 10, "other|poison", 3, "poison_all");
}

init() {
  ::init();
  if( this_player() && zombie_flag &&
      !this_player()->query_jareel_zombie() && 
      !check_undead_attacker( this_player() )
    )
    call_undead_on_target( this_player() );
}

heart_beat(){   /* Did not want to turn on Multi Cast in this mob but wanted this monster to be able to cast some of his
                   spells multiple times in a round or appear that he is doing so.  I have several spells in Heart Beat 
				   for this reason */
  int V;
  int mhp;

  if(!environment()) return;
  ::heart_beat();
  mhp = query_mhp();
  if( !mhp )
    mhp = 10000;

  if( query_hp() * 10 / mhp <= 7 && calm_flag && calm_flag < 3 && attacker_ob )
    calm();

  if( query_hp() * 10 / mhp <= 4 && !zombie_flag && attacker_ob ) 
    CallUndead();

  V = random(3);
  if(attacker_ob){
    if(V == 0) Dragon_Roar();
    if(V == 1) Dragon_heal();
    if(V == 2) God_Flame();
  }
}

poison_all( object target, object room, int damage ) {
   if( target )
     move_object(clone_object("players/jareel/NEW/HEAL/PoisenMe.c"), target);
   if( !calm_flag ) {
     calm_flag = 1;
   }
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
  if( calm_flag == 1 ) {
   TellRoom( 0 );
   call_out( "reset_calm_flag", 60 );
   calm_flag = 2;
  }
  else
    TellRoom( 2 );
  return 1;
}

call_undead_on_target( object target ) {
  object enemy;

  if( !target )
    return;

  enemy = clone_object("/players/jareel/NEW/MOB/Zombie.c");
  enemy->set_target( target );
  move_object( enemy, environment() );
  TellRoom( 4 );
}

CallUndead() {
  object *ob;   
  int x;

  ob = all_inventory(environment());
  x = 0;
  while(x < sizeof(ob)) {
    if( ob[x]->is_player() || ( ob[x]->is_npc() && !ob[x]->query_jareel_zombie() ) ) {
      call_undead_on_target( ob[x] );
    }
    x += 1;
  }
  zombie_flag = 1;
}

check_undead_attacker( object target ) {
  int i; 
  object *inv;

  inv = all_inventory( environment() );
  for( i=0; i < sizeof(inv); i++ ) {
    if( inv[i]->query_jareel_zombie() > 1 && inv[i]->query_target() == target )
      return 1;
  }
  return 0;
}

reset_calm_flag() { 
  TellRoom( 3 );
  calm_flag = 9; 
}

Dragon_heal() { /* 1 +150 30% of the time average 50 */
  tell_room(environment(TO),
    BOLD+GRN+
    "-----------------------------------------------\n"+
    NORM+"Necrosan casts an "+HIY+"aura"+NORM+" of healing over his body\n"+
    "Necrosan casts an "+HIY+"aura"+NORM+" of healing over his body\n");
    tell_room(environment(TO),
    "Necrosan casts an "+HIY+"aura"+NORM+" of healing over his body\n"+
    BOLD+GRN+"-----------------------------------------------\n"+NORM);
    heal_self(150);
    return;
}

Dragon_Roar()  {
  tell_room(environment(TO), /* 15 + 9 = 24 30% - +8 */
    "\n\n Necrosan lets out an earth shaking R O A R ! ! !\n\n");
    call_other(attacker_ob,"hit_player",random(30)+9);
    return;
}

God_Flame() {  /* 15 + 9 = 24 30% - +8 */
  tell_room(environment(TO), 
    "Necrosan calls upon the Red Goddess....\n"+
    "      "+BLINK+HIR+BLINK+" F   L   A   M   E   S "+NORM+" engulf his foe.\n");
    call_other(attacker_ob,"hit_player",random(30)+9);
    return;
 }

TellRoom( int arg ) {
  object env;
  env = environment();

  if( !env )
    return;
  switch( arg ) {
    case 0:
      /** Calm **/
      tell_room(env, "\n\nNecrosan booms: Peace.\n");
      call_out( "TellRoom", 5+random(4), 1 );
      break;
    case 1:
      /** Undead Warning **/
      tell_room(env, "\n\nNecrosan snarls: If you continue on this path I will call upon my Undead.\n\
                 You will not survive the wrath of my Minions!\n");
      break;
    case 2:
      /** Testing **/
      tell_room(env, "\n\nNecrosan waves his hand and all fighting ceases.\n");
      break;
    case 3:
      /** Calm **/
      tell_room(env, "\n\nNecrosan says: Continue on, if you dare.\n");
      break;
    case 4:
      /** Call Undead **/
      tell_room(env, "\n\n\n\n\n\nNecrosan screams: "+HIBLK+"U N D E A D,  A R I S E!!!!\n\n\n\n\n\n"+NORM);
      break;
  }
}

query_jareel_zombie() { return 1; }
