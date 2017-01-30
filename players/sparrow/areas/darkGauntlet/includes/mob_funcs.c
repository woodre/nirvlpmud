/*****************************************************************************
 *      File:                   mob_funcs.c
 *      Function:               Trial of the Black Willow mob special functions
 *      Author(s):              Sparrow@Nirvana
 *      Copyright:              Copyright (c) 2010 Sparrow
 *                              All Rights Reserved.
 *      Source:                 12/22/10
 *      Notes:
 *      Change History:
  ****************************************************************************/

#include <ansi.h>
#define MOVE_INTERVAL 100
object Target;


/*
 * Function name: gut_punch()
 * Description:   This function checks for a prego attacker, checks to
 *                see if the miscarriage bruise exists on attacker, if
 *                not, clones miscarriage to attacker.
 *                for a creature.
 * Arguments:     att - object
 * Returns:       integer
 */
gut_punch(object att){
  object ob;
  string obname, attname, bruises;
  if (att && att->query_pregnancy()) {
    bruises = present("bruise",att);
    if(!bruises){
      ob = clone_object("/players/sparrow/areas/darkGauntlet/obj/miscarriage.c");
      move_object(ob, att);
      obname = capitalize(this_object()->query_real_name());
      attname = capitalize(att->query_real_name());
      say("\n"+HIM+" ~ "+HIW+obname+" punches "+attname+ "hard in the stomach!\n"+
        HIM+" ~ "+HIK+"DARK ENERGY"+HIW+" pours out of "+obname+"'s body!\n\n"+NORM);
      tell_object(att,HIM+" ~ "+HIW+"\nYou are punched "+HIR+"HARD"+HIW+
        " in the stomach, you feel "+HIK+"dark energies"+HIW+
        " coursing through your womb!\n\n"+NORM);
      return 1;
    }
  }
  return 0;
}

/* Function name: disarm()
 * Description:   This function checks for an attacker, if the attacker
 *                is wielding a weapon. Disarm unwields the weapon and
 *                places it in room (80%) or steals it (20%).
 * Arguments:     att - object
 * Returns:       integer
 */

disarm(object att){
  object att_wep;
  string guildname, wepname;
  /* percentage determined by spell */
  if(att){
    if(att && att->query_weapon()){
      att_wep = att->query_weapon();
      wepname = att_wep->query_name();
      if(!att_wep->id("GI")){
        call_other(att, "stop_wielding");
        if(random(10) > 1) {
          move_object(att_wep, environment(att));
          tell_object(att,HIM+"\n ~ "+HIR+"The Monk knocks your "+wepname+HIR+" out of your hands!\n\n"+NORM);
        }
        else {
          move_object(att_wep, this_object());
          tell_object(att,HIM+"\n ~ "+HIR+"The Monk RIPS your "+wepname+HIR+" out of your hands!\n\n"+NORM);
        }
        return;
      }
    }
  }
  return;
}


/* Function name: weapon_breaker()
 * Description:   This function checks for an attacker, if the attacker
 *                is wielding a weapon this should break it
 * Arguments:     att - object
 * Returns:       integer
 */

weapon_breaker(object att) {
  string wepname, guildname;
  object att_wep;
  if(att){
    /* Percentage determined by spell */
    if(att && att->query_weapon()){
      att_wep = att->query_weapon();
      if(!(att_wep->id("GI"))){
        wepname = att_wep->query_name();
        tell_object(att, HIM+" ~ "+HIW+"The monk slams your "+HIR+wepname+HIW+" back in your face!\n"+
          HIM+" ~ "+HIW+"You hear a loud "+HIB+"CRACK!!!!\n"+NORM);
        call_other(att_wep, "weapon_breaks");
        return;
      }
    }
  }
  return;
}

/*
 * Function name: true_darkness()
 * Description:   This function will clone globe of true darkness
 *                to the mob.
 * Arguments:     None
 * Returns:       void
 */
void
true_darkness(){
  object globe,ob;
  globe = present("true_darkness",environment(this_object()));
  if (!globe) {
      tell_room(environment(this_object()),
        HIM+" ~ "+HIK+"The Monk kneels down and summons a Globe of "+
        HIK+"True Darkness"+HIW+"!\n"+NORM);
      ob = clone_object("/players/sparrow/areas/darkGauntlet/obj/true_darkness.c");
      move_object(ob, environment(this_object()));
      return;
  }
  return;
}

/*
 * Function name: new_target()
 * Description:   This function is used to change the focus of the
 *                attacking mob.
 * Arguments:     object att
 * Returns:       void
 */
void
new_target(object att){
  string *noswitch;
  string current_file;
  int change;
  if(!att) {
    return;
  }
  noswitch = ({"/players/zeus/museum/NPC/bug",
               "/players/mythos/amon/forest/snake",
               "/players/fred/forest/Mon/mferret"});
  current_file = explode(file_name(att), "#")[0];
  if(member(noswitch,current_file)) { change = 0; }
  else { change = 1; }
  if(!present(att, environment(this_object())) || (att->query_hp() < 1) || change == 0) {
    this_object()->attack_object(Target);
  }
  else {
    this_object()->attack_object(att);
    tell_object(att, HIM+" ~ "+HIR+"You realize that you are now the focus of the battle!\n"+NORM);
    tell_room(environment(att),
      HIM+" ~ "+HIR+capitalize((string)Target->query_real_name())+
      " is now the recipient of the monks wrath!\n"+NORM);
    Target = att;
  }
  return;
}

paralyze(object att)
{
  object paralyze;
  if(random(4)==0)
  {
    if(!att || (present("paralyze",att))) { return; }
    paralyze = clone_object("/players/sparrow/areas/darkGauntlet/obj/paralyze.c");
    move_object(paralyze,att);
  }
  return;
}