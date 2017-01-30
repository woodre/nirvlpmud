/* disease.c: std's for players */
/* this basically takes control of the sex command */
/* this object is pinged in the 'answer' obj       */
short() { return 0; }
long()  { return 0; }
id(str) { return str == "disease"; }
get()   { return 1; }
drop()  { return 1; }
init()  {
  call_out("weaken", 40);
  add_action("sex", "sex");
}
weaken() {
  write("You feel weaker because of your disease.\n");
  if(this_player()->query_gender() == "male") {
    this_player()->raise_strength(-1);
  } else if(this_player()->query_gender() == "female") {

    this_player()->raise_intelligence(-1);
  } else { this_player()->raise_stealth(-1);
  } return 1;
}
sex(str) {
  object ob;
  if(!str || !find_living(str)) return 0;
  if(!present(str, environment(this_player()))) {
    write("That is not here.\n");
    return 1;
  }    
  ob = clone_object("/players/wizardchild/closed/ask.c");
  ob->set_asker(this_player()->query_real_name());
  move_object(ob, find_living(str));
  tell_object(find_living(str), this_player()->query_name()+" wishes to have sex with you, If you wish to have sex with "+this_player()->query_name()+"\n");
  tell_object(find_living(str), "Type 'sex yes'\n");
  return 1;
}      
