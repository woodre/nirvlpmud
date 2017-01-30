/* This is to make an assisting monster.  Just make a copy of this
   file in the same dir as the monster and add the line:
         #include "fake_hb.h"   in the monster with the 'monstername'
   whoever they are supposed to assist.
*/

heart_beat() {
  object mon, att;
  ::heart_beat();
  mon = present("sarern", environment(this_object()));
  if(mon) att = mon->query_attack();
  if(!query_attack() && att) attack_object(att);
}
