 
shadow_scream(str) {
  object monster;
  int dam;
  if(level_check(2)) return 0;
  if(!time_check()) { return 0; }
  if(!str && (!TP->query_attack())) {
    write("Who do you want to attack?\n");
    return 1;
    }
  else if(TP->query_attack() && !str) {
    str = (TP->query_attack())->query_real_name();
  }
  monster = present(str, ENVTP);
  if(!monster) {
    write(CAP(str)+" isn't present!\n");
    return 1;
  }
  if(!monster->query_npc()) {
    write("You cannot use this spell for player killing.\n");
    return 1;
  }
  dam = 5 + random(15);
  if(!less_pts(25)) { return 0; }
  TP->spell_object(monster,"shadow scream",dam,0);
  if(monster && !monster->query_attack()) monster->attack_object(TP);
  say("You cover your ears from the terrible sounds of the shadows\n" +
      "wailing in tremendous agony!\n");
  write("You begin to chant words that cause the shadowy figures hidden\n" +
        "in the room to scream in agonizing pain, causing " + monster->QN + "'s\n" +
        "ears to bleed profusely.\n");
  MARK->set_spell_time(time());
  return 1;
}
 

