/* ask.c: reply to 'sex' question */
/* this checks if either party has a disease */
#define ME this_player()
#define IT(s) find_player(s)
string asker;
short() { return 0; }
long () { return 0; }
id(str) { return str == "ask"; }
get()   { return 1; }
drop()  { return 1; }
set_asker(str) { asker = str; return 1; }
init() { 
  add_action("sex", "sex");
}
sex(str) {
  object ob, ob2;
  if(str != "yes") {
    destruct(this_object());
    return 0;
  }
  ob = present("condom", ME);
  ob2 = this_object();
  if(ob && ob->query_is_worn()) destruct(ob2);
  else ob = present("condom", IT(asker));
  if(ob && ob->query_is_worn()) destruct(ob2);
  if(present("disease", ME)) {
    if(present("disease", IT(asker))) destruct(ob2);
    tell_object(find_player(asker), "You obtain a disease.\n"); 
    ob = clone_object("/players/wizardchild/closed/disease.c");
    move_object(ob, IT(asker));
    destruct(ob2);
  }
  if(present("disease", IT(asker))) {
    if(present("disease", ME)) destruct(ob2);
    write("You obtain a disease.\n");
    tell_object(find_player(asker), "You give your partner a disease.\n");
    ob = clone_object("/players/wizardchild/closed/disease.c");
    move_object(ob, ME);
    destruct(ob2);
    return 0;
  }
  return 0;
}    
