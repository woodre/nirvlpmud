inherit "obj/treasure";
 
int ppc,value,charges;
 
id(str) { return str == "bag" || str == "marijuana"; }
 
short() {
  return "Bag of Marijuana";
  }
  
long() {
  write("A bag of marijuana.  It looks awful tempting to reach in and roll\n"+
        "yourself a joint and 'smoke marijuana'.\n");
}
 
reset(arg) {
  if(arg) return;
    charges = 10;
    ppc=300;
}
 
query_value() { return charges * ppc; }
 
query_save_flag() { return 1; }

query_weight() { return 2; }
 
init() {
  add_action("smoke_it","smoke");
  add_action("smoke_it","roll");
}
 
smoke_it(str){
  object tp;
  tp = this_player();
	if(!str || (str != "pot" && str != "marijuana")) {
    write("What are you trying to smoke?\n");
    return 1;
    }
  if(!tp->drink_alcohol(12)) { /* changed from 11 by wizardchild */
    return 1;
    }
  tp->heal_self(25);
  tell_object(tp,"You roll yourself a join and smoke it.\n");
  tell_room(environment(tp),capitalize(tp->query_name())+" rolls a joint and smokes it.\n");
  charges -= 1;
  if (charges==0) {
    tell_object(tp,"You finish off the last joint and the bag disappears out of your hand.\n");
    destruct(this_object());
    return 1;
    }
  return 1;
}
 
