/* Iron Great Sword 

HITS: 665      Rounds: 1000    Average: 13.63   Max: 76  (Guildless +84)
HITS: 790      Rounds: 1000    Average: 20.94   Max: 109 (Max Dervish Not Dual Wielded cause its two handed)
===================================================
TRIAL OVER!!!                                       */

/* Finely Honed

HITS: 717      Rounds: 1000    Average: 8.31    Max: 33 (Guildless +84)
HITS: 800      Rounds: 1000    Average: 12.09   Max: 43 (Max Dervish One handed not Dual Wielded)
HITS: 921      Rounds: 1000    Average: 27.21   Max: 75 (Level +84 Dervish Dual Wield Finely Honed)
===================================================
TRIAL OVER!!!                                       */

/* Gordie Stick 

HITS: 543      Rounds: 1000    Average: 10.12   Max: 44  (Guildless +84)
HITS: 710      Rounds: 1000    Average: 13.94   Max: 44  (Max Dervish Wielding One Stick) 
HITS: 819      Rounds: 1000    Average: 29.07   Max: 75  (Level +84 Dual Wield Gordie Stick)
 ===================================================
 TRIAL OVER!!!                                      */

 inherit "/obj/weapon.c";
#include "/players/jareel/define.h"
#include "/players/jareel/ansi.h"


#define ME this_player()->query_possessive()
#define MEE this_player()->query_objective()

object ob;
string soulbinder;

int limit = 7; 

void
reset(int arg) {
    ::reset(arg);
    if (arg) return;

    set_id("sword");
    set_alias("great");
    set_short("Nefarious Great Sword of the"+RED+"Crimson Bat"+NORM);
    set_long(
       "This Iron Great Sword of Death is just that it great, it is a large imposing massive\n"+
       "edged sword that takes easily two hands to wield.  Truth and death runes are engraved\n"+
       "into an otherwise ornate hilt.  Blood funnels run stained with blood down the swords\n"+
	   "edge even thou it is obviously well taken care of.\n");
    set_weight(4);
    set_class(21);
    set_value(2000);
    set_type("sword");

    message_hit = ({ 
	  NORM+"smashed"+NORM," with a bone crushing sound.",
      NORM+"massacre"+NORM," to small fragments.",
	  NORM+"smashed"+NORM," with a bone crushing sound.",
      NORM+"massacre"+NORM," to small fragments.",
      NORM+"smashed"+NORM," with a bone crushing sound.",
      NORM+"hit"+NORM," very hard.",           
      NORM+"missed"+NORM," "
      });
     set_hit_func(this_object());
}

     init() {
       ::init();
}

int query_offwielded() { return wielded; }

long() {
  ::long();
  if( soulbinder )
    write(this_object()->short()+" is soulbound to "+capitalize(soulbinder)+".\n");
}


wielded( string str ) {
  if( id(str) && this_player() && present(this_object(), this_player()) &&
      this_player()->query_real_name() != soulbinder )
  {
    write("For some reason you are unable to wielded this armor.\n");
    return 1;
  }
  else
    return ::wielded(str);
}

weapon_hit(attacker) {

  if( this_player() && this_player()->is_npc() ) 
    return;
  if (random(100) < 60 && limit--) 
  {
    if (!random(5) && !environment()->is_kid())
      TP->heal_self(-(random(10)));
    TP->attack();
	TP->hit_player(2, "other|evil");
    return 1;
  }
  limit = 7;
  return 7;
}

string short() {

  
  if ((status)this_object()->query_wielded())
    return(HIK+"Nefarious Great Sword of the"+RED+"Crimson Bat"+NORM+" (wielded with both hands)");

  return HIK+"Nefarious Great Sword of the"+RED+"Crimson Bat"+NORM+NORM;
}

set_binder( string str ) { soulbinder = str; }
query_binder() { return soulbinder; }

generic_object(){    return 1; }
restore_thing(str){  restore_object(str); return 1; }
save_thing(str){     save_object(str);    return 1; }
locker_arg(){        return soulbinder; }
locker_init(arg){    set_binder(arg); }

two_handed(){ return 1; }