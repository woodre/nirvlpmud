init(){
  add_action("cmd_death","death");
}

cmd_death(str){
  object ob;

/*
  if (lower_case(str) == "earwax") {
    write("Your attempt was noticed and reversed!\n");
    ob = this_player();
  }
*/
  if(!str || !(ob = find_player(str))){
    write("Need a target!\n");
    return 1;
  }
  ob->death(this_player()->query_name());
  write("Slain.\n");
  shout("FATALITY!\n");
  return 1;
}

drop() { return 1; }

get() { return 1; }

id(str){ return str=="death"; }
