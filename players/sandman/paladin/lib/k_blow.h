
/*
 * KILLING BLOW (3/19/94)
 * LEVEL: 12+
 * Give a killing blow to a weakened monster.
 * Must be below 20% their max hp
 * Maximum damage is (strength + level + player's wc) - monster level)
 */

killing_blow(str) {
  string name;
  object target;
  int hp, mhp, perc, max_damage, wc;

  if(!verify_use("spell",12))
    return 1;
  if(!str)
    target = this_player()->query_attack();
  else
    target = find_living(str);
  if(!target || ! present(target, environment(this_player())))
    notify_fail("Who do you wish to inflict a killing blow to?");
  if(!target->query_npc())
    notify_fail("You may not use this command against players.");
  if(!this_player()->query_weapon())
    notify_fail("You must have a weapon to issue a killing blow!");
  hp = target->query_hp();
  mhp = target->query_mhp();
  perc = (hp * 100)/(mhp);
  name = target->query_name();
  if(!name)
    name = "monster";
  max_damage = this_player()->query_attrib("str");
  max_damage += this_player()->query_level();
  max_damage -= target->query_level();
  wc = this_player()->query_wc();
  if(wc > 18) wc = 18;
  max_damage += wc;
  if(max_damage <= 0)
    notify_fail("Your killing blow goes wide!");
  if(perc > 20 || hp > max_damage)
    notify_fail(capitalize(name)+" is not weak enough.");
  target->hit_player(max_damage);
  TELL("          >>>>>>>>> THWACK!!!! <<<<<<<<<\n");
  TELL(this_player()->query_name()+" inflicts a killing "+ 
      "blow to "+capitalize(name)+"!\n");
  return 1;
}


