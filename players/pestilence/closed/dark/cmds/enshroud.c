#include "/players/pestilence/ansi.h"
#define TP this_player()

main(string str) {
  object wep, shadow, offwep, mygob, target;
  int wepwc;
  mygob = present("dknight_ob", TP);

  if(this_player()->query_guild_rank() < 9) {
    write("You can't use ability yet.\n"); 
    return 1; 
  }

  if (this_player()->query_sp() < 30) {
    write("You do have the energy for this skill.\n");
    return 1;
  }

  wep = TP->query_weapon();
  offwep = mygob->query_offwep();

  if(!str) {
    if( wep && !wep->is_shrouded() ) {
      target = wep;
    }
    else if( offwep && !offwep->is_shrouded() ) {
      target = offwep;
    }
  }
  else {
    wep = present(str, TP);
    if(!wep) { 
      write("You don't have that!\n"); 
      return 1; 
    }
    if(!wep->is_weapon()) { 
      write("That is not a weapon!\n"); 
      return 1; 
    }
    if(wep->is_shrouded() ) {
      write("Your HATRED already enshrouds the "+wep->short()+".\n");
      return 1;
    }
    target = wep;
  }

  if( !target )
    return 0;
  
  write("You focus your "+HIR+"HATRED"+NORM+" into "+ target->short()+".\n"+NORM);
  tell_room( environment(TP), TP->query_name()+" enshrouds "+TP->query_possessive()+" "+
    target->query_short()+" with pure "+HIR+"HATRED"+NORM+".\n", ({TP}) );
  shadow = clone_object("/players/pestilence/closed/dark/obj/shroud_shadow.c");
  shadow->load_it(target);
  this_player()->add_spell_point(-30);
  return 1;
}
