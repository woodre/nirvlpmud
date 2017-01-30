/* blessing_ob.c - used for the Bard Battle blessing, which grants
 * a WC bonus to party members.  This object actually administers
 * the bonus
 *
 */
 
#include "/players/guilds/bards/def.h"
#define BLESSINGNAME "bard_battle_blessing_object"
#define BMASTER "/players/guilds/bards/obj/blessing_master"

int start_time;
string pname;
object victim;
int duration;
int bonus;
int recheck;
  
status id(string str) {
   return str=="generic_wc_bonus" || str == BLESSINGNAME;
}

string extra_look() {
  if(victim && environment() && environment()==victim)
    if(TP==victim)
      return "You have been blessed by the Song of Battle";
    else
      return NAME(victim)+" has been blessed by the Song of Battle";
}

status get() { return 1; }
status drop() { return 1; }

void start_blessing(object ob, string str, int dur) {
  start_time=time();
  victim=ob;
  pname=str;
  duration=dur;
  recheck=-1;
  tell_object(victim,"The Song of Battle empowers you!\n");
}

void set_bonus(int bon) {
  /* all party members in the room are set by this
     prevents the daemon from being called too much */
  tell_object(victim,"The energy of the Song of Battle courses through you!\n");
  recheck=5;
  bonus=bon;
}

int gen_wc_bonus() {
  object pob;
  int dam;
  if(!victim || !environment() || victim !=environment()) {
    destruct(TO);
    return 0;
  }
  pob=present("party_object",victim);
  if(!pob || (string)pob->QPartyName() != pname || time() > start_time+duration) {
    tell_object(victim,"\n\nThe blessing of the Song of Battle has faded.\n\n");
    destruct(TO);
    return 0;
  }
  /* double check for party members every so often */
  recheck--;
  if(recheck<0)
    BMASTER->get_bonus(pname,environment(victim),duration);
  if(bonus>0) {
    dam=bonus;
    if(victim->is_testchar()) tell_object(victim,"WC bonus: "+dam+"\n");
    return dam;
  }
  return 0;
}
