/* master.c  -   master object for knights templar
   created by illarion
 */

#include "../def.h"
 
/* Used to check wether a spell can be cast.  Returns 1 for casting allowed,
   0 for not allowed.
   
  if no_deduct is 0, the cost of the spell is deducted automatically, asuming
  the player has enough.
*/
spell(object play, int glev_required, int pie_required, int sp_required, int no_deduct) {
  if(!play) return 0;
  if(play->query_ghost()==1)
    FAIL("The powers of the deities slip through your ghostly fingers.")
  if(GLEV(play) < glev_required)
    FAIL("You have not yet been granted this power.\n");
  if(ALIGN(play) < CUTOFF_ALIGN)
    FAIL("You find that the deities have forsaken you.  You have no special powers.\n"
        +"Perhaps if you change your evil ways, the deities will allow you to tap\n"
        +"their source of magic once again.\n");
  if(ATTRIB(play,"pie") < pie_required)
    FAIL("Your faith is not strong enough.\n");
  if(SP(play) < sp_required)
    FAIL("You lack the spell_points required.\n");
  if(!no_deduct)
    play->add_spell_point(-sp_required);
  return 1;
}

combat_spell(object play, object target, int glev_required, int pie_required, int sp_required, int no_deduct) {
  if(!play || !target) return 0;
  if(play==target) FAIL("You can't seem to get a good angle on yourself.\n");
  if(!living(target)) FAIL("You may not attack that!\n");
  if(!play->valid_attack(target)) return 0;
  return spell(play, glev_required, pie_required, sp_required, no_deduct);
}

string generate_short(object gob) {
  string name;
  status elite,worn;
  if(ENV(gob))
    name=NAME(ENV(gob));
  if(!name)
    name="Someone";
  elite=(int)gob->query_elite();
  worn=(int)gob->query_worn();
  return (elite?RED:"")+name+"'s "+(elite?NORM+BOLD:"")
         +"Cross of the Knights Templar"+(elite?NORM:"")
         +(worn?" (worn)":"");
}

void show_long(object gob,string str) {
  int award;
  object wep;
  switch(str) {
    case "cape":
      if(!gob->query_elite()) return;
      write("The burgundy half-cape that Elite Guards of the Knights Templar\n"
           +"wear over their right shoulder.");
      if(gob->query_awards()) {
        write("  Stitched to it are the awards\nyou have won for your deeds:\n");
        if((award=(int)gob->query_award(1)))
          write(award+HIC+" Crystalline Shield"+(award>1?"s":"")+NORM+"\n");
        if((award=(int)gob->query_award(2)))
          write(award+HIW+" Platinum Circlet"+(award>1?"s":"")+NORM+"\n");
        if((award=(int)gob->query_award(3)))
          write(award+HIY+" Golden Circlet"+(award>1?"s":"")+NORM+"\n");
        if((award=(int)gob->query_award(4)))
          write(award+HIG+" Emerald droplet"+(award>1?"s":"")+NORM+"\n");
      } else {
        write("\n");
      }
      return;
    case "sheath":
      write("A leather sheath worn on your back.  It has a variety of hooks\n"
           +"and fastenings for different weapon types.  You can use it to\n"
           +"'sheathe' your wielded weapon, 'unsheathe' or 'draw' a weapon\n"
           +"you have sheathed.\n");
      if((wep=(object)gob->query_sheathed()))
        write("It contains: "+(string)wep->short()+"\n");
      return;
    default:
      write("The "+RED+"Red"+NORM+" on "+HIW+"White"+NORM+" cross of The Knights Templar.\n"
           +"The guild help command is 'info'.\n");
      return;
  }
}

/* Code for guild commands and spells */

get_cmds() {
  return get_dir(POWER_DIR+"_*.c");
}

templar_cmd(string verb, string arg, object gob, object play) {
  object room;
  if(!verb || !gob || !play) return 0;
  room=ENV(play);
  if(!room) return 0;
  return call_other(POWER_DIR+"_"+verb,"main",arg,gob,play,room);
}

get_target(string arg, object play, object room) {
  object target;
  if(!arg) {
    notify_fail("Who do you want to attack?\n");
    target=play->query_attack();
  } else {
    notify_fail("Your don't see your target.\n");
    target=present(arg,room);
  }
  return target;
}
    