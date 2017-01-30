/* blessing_master.c
 * Calculates and holds the damage bonus for each room so it
 * only needs to be calculated once per hb per room
 * the amount of extra damage depends on the number of
 * party members in the room at the time and the initial
 * strength of the blessing (blessing strength will run
 * from around 200-600)
 *
 * The damage bonus works out to between 1.1-1.5 damage times
 * the number of party members present. 
 * (5 members = 5.5-7.5 extra)
 *
 */
 
#include "/players/guilds/bards/def.h"
#define BLESSINGNAME "bard_battle_blessing_object"
 
mixed *bonuses;

status local_pmembers(object ob,string pname) {
  object pob;
  pob=present("party object",ob);
  if(!pob)
    return 0;
  if((string)pob->QPartyName() != pname)
    return 0;
  return 1;
}

void get_bonus(string pname, object room, int duration) {
  object *folks;
  int s;
  object bob;
  int bonus;
  if(!pname || !room || !duration)
    return 0;
  folks=filter_array(all_inventory(room),"local_pmembers",TO,pname);
  s=sizeof(folks);
  bonus=s*(900+duration)/1000;
  while(s--)
    if((bob=present(BLESSINGNAME,folks[s])))
      if(bob) bob->set_bonus(bonus);
}

