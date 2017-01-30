setup(){
  spelllist = ({ });
  if(!restore_member()){
    write("Welcome to the Sigils guild!\n");
    save_member();
  }
  if(!powerlevel) powerlevel = 3;
  if(TP->query_level() < 20){
    TP->set_guild_name(GNAME);
    if(!TPGR) TP->set_guild_rank(1);
  }
  switch(major_type) {
    case "fire": major_map = FIRE; break;
    case "ice": major_map = ICE; break;
    case "electricity": major_map = ELECTRIC; break;
    default: major_map = ([]);
  }
  switch(TPGR) {
    case 1: statpt=0; max_lessers=0; max_instants=0; break;
    case 2: statpt+=5; max_lessers=1; max_instants=1; break;
    case 3: max_lessers=2; max_instants=2; break;
    case 4: max_lessers=3; max_instants=3; break;
    case 5: max_lessers=3; max_instants=3; break;
    case 6: statpt+=2; max_lessers=4; max_instants=5; break;
    case 7: statpt+=1; max_lessers=4; max_instants=5; break;
    case 8: max_lessers=5; max_instants=7; break;
    case 9: statpt+=1; max_lessers=5; max_instants=9; break;
    case 10: statpt+=1; max_lessers=6; max_instants=11; break;
    default: statpt=0; max_lessers=0; max_instants=0;
  }
}

save_member(){
string path;
  path = GSAVE+TPRN;
  save_object(path);
  write("Saving guild stats.\n");
  return 1;
}

restore_member(){
string path;
  if(!USER){ return 1; }
  path = GSAVE+TPRN;
  if(!restore_object(path)) return 0;
  else write("Restoring guild stats.\n");
  return 1;
}

leave_guild(){
  write("You feel a burning sensation on your "+location+"...\n"+
        "The Sigil fades away.\n");
  destruct(this_object());
  return 1;
}
