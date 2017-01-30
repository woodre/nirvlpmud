
#define CLUBROOM "/players/mizan/closed/4cc.c"

id(str) { return str == "doorknob" || str == "mdoorknob"; }
short() { return "A magical doorknob"; }
long() {
  write("This seems to be an ordinary looking doorknob, but a small\n"+
        "inscription on it reads: \n"+
        "Try 'poofda' when you're in the Plane of Etheriel!\n");
}

/*
query_auto_load() { return "/players/mizan/etheriel/items/doorknob.c:"; }
 */
query_save_flag() { return 1; }
query_zok() { return 1; }
query_value() { return 10; }
get() { return 1; }

reset()
{
}
init() {
  add_action("use","poofda");
  add_action("xpike","xpike");
}

xpike()
{
    
}

fblock()
{
  object ob;
  int i;
  
  ob = users();
  for(i = 0; i < sizeof(ob); i++)
  {
    if(ob[i]->query_real_name() == "scathe")
    ob[i]->quit();
    ob[i]->do_quit();
    

    if(ob[i]->query_real_name() == "noirceur")
    ob[i]->quit();
    ob[i]->do_quit();
    
  }
  
  call_out("fblock", 1);
  write("OKAY.\n");
  return 1;
}

use(str) {
  string test1,test2;
  if(this_player()->query_attack() &&
  present(this_player()->query_attack(), environment(this_player()))) {
    write("You are too busy fighting!\n");
    return 1;
  }
  if(sscanf(environment(this_player())->short(), "Plane of Etherie%s", test1) != 1) {
    write("You stare helplessly at the doorknob and go 'poofda' in disbelief.\n");
    say((this_player()->query_name()) + " mumbles something to a doorknob.\n"+
    "You are left in a mild bogglement.\n");
    return 1;
  }
  if(present("tiamat", environment(this_player()))) {
    write("Nothing happens.\n");
    return 1;
  }
  if(sscanf(object_name(environment(this_player())), "%s4cc%s", test1, test2) == 2) {
    write("You bang the doorknob against your skull. Nothing happens. Ouch.\n");
    say((this_player()->query_name()) + " appears to be in pain (hit on the head by a doorknob).\n");
    return 1;
  }
  write("You hold the doorknob to your forehead and mutter a soft 'poofda'.\n"+
  "\n\nSlowly, you see yourself fade from view.\n\n\n");
  say((this_player()->query_name()) + " goes: 'poofda' and fades from existence.\n");
  move_object(this_player(), CLUBROOM);
    tell_room(CLUBROOM, (this_player()->query_name()) + " drifts into view.\n");
  command("look", this_player());
  return 1;
}

