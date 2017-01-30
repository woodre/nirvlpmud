/*****************************************************************************
 *      File:                   mob_funcs.c
 *      Function:               BWO mob special functions
 *      Author(s):              Sparrow@Nirvana
 *      Copyright:              Copyright (c) 2006 Sparrow 
 *                              All Rights Reserved.
 *      Source:                 03/14/2006
 *      Notes:                  Thanks to Fred, Earwax, and Pavlik for helping
 *                              with these functions.
 *      Change History:         03/15/06 Sparrow: Began adding standardized
 *                              headers for file and functions.
 *                              03/18/06 Sparrow: Removed random from funcs
 *                              to be used with mob spells.
 *                              03/20/06 Sparrow: Added true_darkness function
 *                              03/21/06 Sparrow: Added check for ranger guild
 *                              on disarm and weapon_break. Due to the nature
 *                              of the ranger weapon, it would actually remove
 *                              their guild object and place on ground. fixed
 *                              03/22/06 Sparrow: Added check for fallen to
 *                              determine if they are wielding a weapon (which
 *                              means disarmable) or bare hands (guild object
 *                              not disarmable)
 *                              03/22/06 Sparrow: Removed guild check all-
 *                              together for weapon_break and disarm. Now
 *                              checking tomake sure that weapon is drop(0)
 *                              3/23/06 Sparrow: Heh, removed drop(0) and 
 *                              replaced it with id("GI")
  ****************************************************************************/
 
#include <ansi.h>
#define MOVE_INTERVAL 100
object Target;
/* Function name: disarm()
 * Description:   This function checks for an attacker, if the attacker
 *                is wielding a weapon. Disarm unwields the weapon and 
 *                places it in room (67%) or steals it (33%). 
 * Arguments:     att - object
 * Returns:       integer
 */
 
disarm(object att){
  object att_wep;
  string guildname, wepname;
  /* percentage determined by spell */
  if(att && att->query_guild_name() == "rangers") return ;
  if(att){
    if(att && att->query_weapon()){
      att_wep = att->query_weapon();
      wepname = att_wep->query_name();
     if(!att_wep->id("GI") || !att_wep->is_weapon()) {
        call_other(att, "stop_wielding");
        att_wep->deShadow();
        if(random(10) > 2) {
          move_object(att_wep, environment(att));
          tell_object(att,HIM+"\n ~ "+HIR+"Shredder knocks your "+wepname+HIR+" out of your hands!\n\n"+NORM);
          log_file("sparrow.bwm","Log Entry: "+ctime()+" Obj: "+file_name(this_object())+"\n   Shredder disarmed ["+wepname+"] on ["+capitalize(att->query_name())+"]\n");       
        }
        else {
          move_object(att_wep, this_object());
          tell_object(att,HIM+"\n ~ "+HIR+"Shredder RIPS your "+wepname+HIR+" out of your hands!\n\n"+NORM);
          log_file("sparrow.bwm","Log Entry: "+ctime()+" Obj: "+file_name(this_object())+"\n   Shredder stole ["+wepname+"] from ["+capitalize(att->query_name())+"]\n");
        }
        return;
      }
    }
  }
  return;
}

/* Function name: heatmetal()  
 * Description:   This function checks for an attacker, if the attacker
 *                is wielding a weapon. Heatmetal unwields the weapon and 
 *                places it in room. 
 * Arguments:     att - object
 * Returns:       integer
 */
 
heatmetal(object att){
  object att_wep;
  string guildname, wepname;
  /* percentage determined by spell */
  if(att && att->query_guild_name() == "rangers") return ;
  if(att){
    if(att && att->query_weapon()){
      att_wep = att->query_weapon();
      wepname = att_wep->query_name();
      if(!att_wep->id("GI")){      
        call_other(att, "stop_wielding");
        move_object(att_wep, environment(att));
        tell_object(att,HIR+"\n*****"+RED+"Your weapon begins burning your hands and you drop it!"+HIR+"*****"+NORM);       
      }
      return;
    }
  }
  return;
}
/* 
 * Function name: Smoke_bomb
 * Description:   This function will clone cloud of smoke
 *                to the mob.
 * Arguments:     None
 * Returns:       void
 */
void
smoke_bomb(){
  object globe,ob;
  globe = present("smoke_bomb",environment(this_object()));
  if (!globe) {
      tell_room(environment(this_object()),
        HIR+"*****"+RED+"Shredder slams down a smoke Bomb"+HIR+"*****"+NORM);
      ob = clone_object("/players/wicket/ninja_turtles/obj/smoke_bomb.c");
      move_object(ob, environment(this_object()));
      return;
  }
  return;
}

