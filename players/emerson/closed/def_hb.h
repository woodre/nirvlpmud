heart_beat() {
  object mon, att;
  ::heart_beat();
  if(!this_object() || !environment()) return;
  mon = present("hutboss", environment(this_object()));
  if(mon) att = mon->query_attack();
  if(!query_attack() && att) attack_object(att);
}
