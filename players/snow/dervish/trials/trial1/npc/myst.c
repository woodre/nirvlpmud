/*
 * Blocks entrance to beginning of quest.  Low WC, high AC mob, most
 * damage comes from spell and special attacks.  Mob heals 300 hps
 * 5 times, and the lower its hps, the higher it's AC.
 */

regen = 5;


hb stuff
ac_check();
if(regen && hit_point <= 150) regen_check();

ac_check() {
  if(!present(attacker_ob, environment())) return;
  if(hit_point <= 450) armor_class = 33;
  if(hit_point <= 400) armor_class = 36;
  if(hit_point <= 350) armor_class = 39;
  if(hit_point <= 300) armor_class = 42;
  if(hit_point <= 250) armor_class = 45;
  if(hit_point <= 200) armor_class = 48;
  if(hit_point <= 175) armor_class = 51;
  if(hit_point <= 150) armor_class = 54;
  if(hit_point <= 125) armor_class = 57;
  if(hit_point <= 100) armor_class = 60;
  if(hit_point <=  75) armor_class = 63;
  if(hit_point <=  50) armor_class = 66;
  if(hit_point <=  25) armor_class = 69;
  else armor_class = 30;
}

regen_check() {
  if(!present(attacker_object, environment())) return;
  tell_room(environment(), HIM+"\t\nMyst swirls out from a gaping hole in the gound!\n\n"+NORM);
  hit_point += 300;
  regen--;
}