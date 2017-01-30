tele_officer() {
  if(tsp < 40) { write("You do not have enough sp!\n"); return 1; }
  if(etp->realm() == "NT") { write("You can go to the grounds from here.\n"); return 1; }
  if(formtype == "tech") { write("\n"); say("\n"); }
  else { write("\n"); say("\n"); }
  move_object(tp,"/players/mythos/bounty/bounty.c");
  tp->add_spell_pont(-40);
return 1; }
