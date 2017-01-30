/** For TMNT **/
#define DON "/players/wicket/ninja_turtles/mobs/donatello"
#define LEO "/players/wicket/ninja_turtles/mobs/leonardo"
#define MIKE "/players/wicket/ninja_turtles/mobs/mikey"
#define RAPH "/players/wicket/ninja_turtles/mobs/raphael"

#define PESTY_DIR "/players/pestilence/club/room"
#define pesty ({ "nsewer", "sewer", "sewer2", "sewer3", "sewer4", "sewer5", "sewer6", "sewer7",\
                "ssewer", "ssewer2", "ssewer3", })
#define TRIX_DIR "/players/trix/castle/quest"
/** Errors sometimes ? **/
#define trix ({ "Esee10.c","Eseg8.c","sec4.c","sec5.c","sec6.c","sed6.c","sed6.c",\
                "sed7.c","sed8.c","sed9.c","see10.","see6.c","see6d.c","see7.c","see8.c","see9.c",\
                "sef7.c","sef8.c","sef9.c","seg7.c","seg8.c","seg9.c" })
#define VITAL_DIR "/players/vital/dest/spaceport/rooms"
#define vital ({ "sewer1", "sewer2", "sewer4a", "sewer4b", "sewer5" })
#define KHRELL_DIR "/players/khrell/area/skaven"
#define khrell ({ "under10","under11","under12","under13","under14","under15","under16",\
                  "under17","under18","under19","under1","under20","under21","under22",\
                  "under23","under24","under25","under26","under27","under28","under2",\
                  "under3","under4","under5","under6","under7","under8","under9" })
#define VERT_DIR "/players/vertebraker/swamp/ROOMS"
#define vert ({ "s10","s11","s12","s13","s14","s15","s16","s18","s19","s1","s20","s21",\
                "s22","s23","s24","s25","s26","s27","s28","s2","s34","s35","s36","s37",\
                "s38","s39","s3","s40","s41","s42","s43","s44","s45","s46","s4","s5",\
                "s6","s7","s8","s9" })
#define WOCKET_DIR "/players/wocket/turtleville"
#define wocket ({ "tvmarsh1.c","tvmarsh2.c","tvmarsh3.c","tvmarsh4.c","tvmarsh5.c",\
                 "tvmarsh6.c","tvmarsh72.c","tvmarsh7.c","tvmarsh8.c" })
#define AIR_DIR "/players/airwoman/sewage"
#define air ({ "room1", "room2", "room3", })
#define COSMO_DIR "/players/cosmo/apt/rooms/NEWBIE"
#define cosmo ({ "h1.c", "h2.c", "h3.c", "h4.c", "h5.c", "h6.c", "h7.c", "h8.c", "h9.c", "h10.c", })

id(str) { return str == "tmnt"; }

set_tmnt_location( object turtle ) {
  switch( random(8) ) {
    /** Pesty **/
    case 0:
      turtle->set_wander_realm( PESTY_DIR );
      move_object( turtle, PESTY_DIR+"/"+pesty[ random(sizeof(pesty)) ] );
      break;
    /** Trix **/
    case 1:
      turtle->set_wander_realm( TRIX_DIR );
      move_object( turtle, TRIX_DIR+"/"+trix[ random(sizeof(trix)) ] );
      break;
    /** Vital **/
    case 2:
      turtle->set_wander_realm( VITAL_DIR ); 
      move_object( turtle, VITAL_DIR+"/"+vital[ random(sizeof(vital)) ] );
      break;
    /** Vert **/
    case 3:
      turtle->set_wander_realm( VERT_DIR );
      move_object( turtle, VERT_DIR+"/"+vert[ random(sizeof(vert)) ] );
      break;
    /** Wocket **/
    case 4:
      turtle->set_wander_realm( WOCKET_DIR );
      move_object( turtle, WOCKET_DIR+"/"+wocket[ random(sizeof(wocket)) ] );
      break;
    /** Airwoman **/
    case 5:
      turtle->set_wander_realm( AIR_DIR );
      move_object( turtle, AIR_DIR+"/"+air[ random(sizeof(air)) ] );
      break;
    /** Cosmo **/
    case 6:
      turtle->set_wander_realm( COSMO_DIR );
      move_object( turtle, COSMO_DIR+"/"+cosmo[ random(sizeof(cosmo)) ] );
      break;
    /** khrell **/
    default:
      turtle->set_wander_realm( KHRELL_DIR );
      move_object( turtle, KHRELL_DIR+"/"+khrell[ random(sizeof(khrell)) ] );
      break;
  }
}

generate_tmnt() {
  object turtle, targ;
  targ = find_living( "raphael" );

  if( !targ ) {
    turtle = clone_object( RAPH );
    set_tmnt_location( turtle );
  }
  
  targ = find_living( "michelangelo" );

  if( !targ ) {
    turtle = clone_object( MIKE );
    set_tmnt_location( turtle );
  }
  
  targ = find_living( "leonardo" );

  if( !targ ) {
    turtle = clone_object( LEO );
    set_tmnt_location( turtle );
  }
  
  targ = find_living( "donatello" );

  if( !targ ) {
    turtle = clone_object( DON );
    set_tmnt_location( turtle );
  }
}

reset(arg) {
  object qob;

  generate_tmnt();
  
  if (arg)
	  return;
}
