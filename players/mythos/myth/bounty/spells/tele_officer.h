tele_officer() {
  if(tsp < 40) { write("You do not have enough sp!\n"); return 1; }
  if(etp->realm() == "NT") { write("You can not go to the grounds from here.\n"); return 1; }
  write("\n"); say("\n"); 
  move_object(tp,"/players/mythos/myth/bounty/bounty.c");
  tp->add_spell_pont(-40);
return 1; }
