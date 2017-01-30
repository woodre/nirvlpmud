summon_tool() {
  if(tp->query_sp() < 50) { write("You do not have the availble magic.\n"); return 1; }
  if(present("harvesting tool",tp)) { write("You have already got one.\n"); return 1; }
  tp->add_spell_point(-50);
  move_object(clone_object(OBJ+"/wep/harvester.c"),tp);
  write("You summon a harvesting tool.\n");
  say("Darkness swirls around the hand of "+tp->query_name()+" and a Harvesting Tool forms.\n");
return 1; }
