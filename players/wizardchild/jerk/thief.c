/* thief.c: tidy way to prevent low levels from having good stuff */
#define ME this_player()
status move_set;
short() {
  return "A petty thief";
}
long() {
  write("A thief with a sharp eye and selective tastes...\n");
  if((ME->query_level() < 10 && ME->query_wc() > 17) ||
    ((ME->query_level()+10) < ME->query_wc())) 
    write("He seems to be eyeing that weapon of yours...\n");
  return 1;
}
id(str) { return str == "thief" || str == "petty thief"; }
init() {
  status picked;
  int x;
  object ob, ob2;
  picked = 0;
  x = random(100);
  add_action("kill", "kill");
  if(!picked && ME->query_level() < 10 && x > 60) {
    ob = first_inventory(ME);
    while(ob) {
      if(ob->weapon_class() > 16 || (ME->query_level()+10 < ob->weapon_class())) 
        ob2 = ob;
      ob = next_inventory(ob);
      if(ob2 && enivronment(ob2) != this_object()) {
        picked = 1;
        if(!ob2->drop()) 
          continue;
        command("drop "+ob2->query_name(), ME);
        move_object(ob2, this_object());
        say("The thief promptly picks up the weapon.\n");
        destruct(ob2);
      }
    }
  }      
  if(!move_set) {
    call_out("move", 20);
    move_set = 1;
  }
}                      
move() {
  object ob;
  string s;
  int i;
  ob = environment(this_object());
  s = ob->query_dest_dir();
  if(!s) {
    move_object(this_object(), "/room/church");    
    say("Someone new has arrived.\n");
  } else {
    i = random(sizeof(s));
    move_object(this_object(), s[i]);
    say("Someone new has arrived.\n");
  }
  move_set = 0;
}
