inherit "/obj/treasure.c";

void reset(int arg) {
  set_id("dispenser");
  set_short("A party object dispenser");
  set_long("This is a short box made out of metal, and painted a dull\n"+
           "yellow with vibrant purple polkadots.  A red button with the\n"+
           "label 'push me' is right above a slot.\n");
  set_weight(999);
}

void init() {
  add_action("push","push");
  add_action("push","press");
}

int push(string str) {
  if(!str || str!="button") {
    notify_fail("Push what?\n");
    return 0;
  }
  write("The machine spits out a party object which richochets off of\n"+
       "your face before falling to the ground.\n");
  say((string)this_player()->query_name()+" uses the dispenser.\n");
  if(!present("party",environment()))
    move_object(clone_object("/obj/partyob.c"),environment());
  return 1;
}

get() { return 0; }
