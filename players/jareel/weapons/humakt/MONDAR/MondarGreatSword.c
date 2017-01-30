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

int limit = 7; 

  reset(arg) {
    ::reset(arg);
    if(arg) return;

    set_id("sword");
    set_alias("great");
    set_short("Iron Great Sword of "+HIK+"Death"+NORM);
    set_long(
       "This Iron Great Sword of Death is just that it great, it is a large imposing massive\n"+
       "edged sword that takes easily two hands to wield.  Truth and death runes are engraved\n"+
       "into an otherwise ornate hilt.  Blood funnels run stained with blood down the swords\n"+
	   "edge even tho it is obviously well taken care of.\n");
    set_weight(4);
    set_class(21);
    set_value(1000);
    set_type("sword");

    message_hit = ({ 
      NORM+"smashed"+NORM," with a bone crushing sound.",
      NORM+"massacre"+NORM," to small fragments.",
      NORM+"hit"+NORM," very hard.",           
      NORM+"missed"+NORM," "
      });
     set_hit_func(this_object());
}

     init() {
       ::init();
}

int query_offwielded() { return wielded; }

status wield(string str) {
  object *inv;
  int x,s;
  if(!id(str))
    return 0;
  if(environment() != this_player())
    return 0;
  if(present("notweapon", this_player())) {
    write("For some reason you are unable to wield this weapon.\n");
    return 1;
  }
  
  if(wielded) {
    write("You already wield it!\n");
    return 1;
  }
  inv = all_inventory(this_player());
  s = sizeof(inv);
  for(x=0; x<s; x++) {
    if((string)inv[x]->query_type() == "shield" && inv[x]->query_worn()) {
      write("You need both hands free for this weapon.\n");
      return 1;
    }
  }
  wielded_by = this_player();
  call_other(this_player(), "wield", this_object(), silentwield);
  wielded = 1;
  return 1; 
}

weapon_hit(attacker) {

  if (TPRN == "mondar" || (this_player() != environment(this_object())))
    return;
  if (random(100) < 60 && limit--) 
  {
    if (!random(5) && !environment()->is_kid())
      TP->heal_self(-(random(10)));
    TP->attack();
	TP->hit_player(5);
    return 1;
  }
  limit = 7;
  return 7;
}

string short() {

  
  if ((status)this_object()->query_wielded())
    return("Iron Great Sword of "+HIK+"Death"+NORM+" (wielded with both hands)");

  return "Iron Great Sword of "+HIK+"Death"+NORM+NORM;
}

two_handed(){ return 1; }