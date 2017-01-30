rest_peace() {
int damage;
  if(!(tp->query_attack())) {write("You may only use this during combat.\n"); return 1;}
  if(!((tp->query_attack())->query_npc()) &&  !dpp) {
    write("You may not use this on players at this time.\n"); return 1;}
    if(qtf > 8) {
  damage = random(2 * qtf); }
    else { damage = random(8); }
  if((tp->query_attack())->query_hp() < damage) {
    say(capitalize(tpn)+"'s eyes glow with an dark red flame!\n");
    write("You whisper the frightening words your victim does not want to hear:\n");
    tell_room(environment(tp),"\n"                 REST IN PEACE            \n");
    tell_room(environment(tp),capitalize((tp->query_attack())->query_name())+
    " screams in terror and pain!\n");
    (tp->query_attack())->hit_player(damage*2);
    tp->heal_self(1);
    write("You feel slightly invigorated.\n");
  return 1;}
  write(capitalize((tp->query_attack())->query_name())+" is still too far from death's embrace.\n");
return 1;}

