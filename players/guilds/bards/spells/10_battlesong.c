/* battlesong.c
 * grants a gen_wc_bonus to all partymembers
 *
 * duration is wis*(1+level)/2 + xlevel*3
 * (max is 600 seconds, or 10 minutes)
 *
 * The bonus is based on the number of other
 * party members present
 *
 */

#include "/players/guilds/bards/def.h"
#define BLESSINGOB "/players/guilds/bards/obj/blessing_ob.c"
#define BLESSINGNAME "bard_battle_blessing_object"
#define COST 200

status main(string str) {
  object *obs,pob,bob,room;
  string pname;
  int x;
  int duration;
  if(spell(-50, 10, COST) == -1)
    return 0;
  pob=present("party_object",TP);
  if(!pob)
    FAIL("You must be in a party to play the song of battle.\n");
  room=environment(TP);
  if(!room)
    return 0;
  duration=((int)TP->query_level()+1)*((int)TP->query_attrib("wil"))/2;
  duration+=((int)TP->query_extra_level())*3;
  pname=(string)pob->QPartyName();
  obs=all_inventory(room);
  tell_room(room,NAME(TP)+" plays the Song of Battle on "+POSS(TP)+" "+INST+"!\n",({TP}));
  tell_object(TP,"You play the Song of Battle!\n");
  for(x=0;x<sizeof(obs);x++) {
    if(!living(obs[x])) continue;
    pob=present("party_object",obs[x]);
    if(!pob || (string)pob->QPartyName() !=pname) continue;
    bob=present(BLESSINGNAME,obs[x]);
    if(!bob) {
      bob=clone_object(BLESSINGOB);
      move_object(bob,obs[x]);
    }
    bob->start_blessing(obs[x],pname,duration);
  }
  TP->add_spell_point(-COST);
  return 1;
}
