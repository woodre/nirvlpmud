do_pyre(str) {
  object corpse;
  string blah;
  if(!str) {
    corpse=present("corpse",environment(TP));
  }
  else
  corpse=present(str,environment(TP));
  if(!corpse) {
    write("There is no corpse here.\n");
    return 1;
  }
  if(sscanf(file_name(corpse),"obj/corpse%s",blah)!=1) {
    write("You cannot pyre that.\n");
    return 1;
  }
  write("You release the remaining order in the corpse.\n"+
        "It crumbles into dust within seconds.\n");
  say("The corpse crumbles into dust at "+TPN+"'s touch.\n");
  TP->add_sp(2*corpse->heal_value());
  destruct(corpse);
  return 1;
}
