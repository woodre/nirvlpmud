#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  object scarecrow;

  if(!present("scarecrow")) {
    object boots;
    scarecrow = clone_object("obj/monster");
    scarecrow->set_name("scarecrow");
    scarecrow->set_level(5);
    scarecrow->set_hp(60 + random(30));
    scarecrow->set_wc(10);
    scarecrow->set_ac(4);
    scarecrow->set_short("A scarecrow");
    scarecrow->set_long(
"He is seeing to that nobody steals the corn...\n");
    scarecrow->set_al(-10);
    boots = clone_object("obj/armor");
    boots->set_name("boots");
    boots->set_short("A pair of rubber boots");
    boots->set_alias("rubber boots");
    boots->set_value(200);
    boots->set_ac(1);
    boots->set_type("boot");
    move_object(boots, scarecrow);
    move_object(scarecrow, this_object());
  }    
  if (!present("corncob"))
    move_object(clone_object("players/angmar/o/corncob"), this_object());
  if (arg)
    return;
  set_light(1);
  short_desc = "In a cornfield";
  long_desc = 
"You are in a large cornfield.  It is full of corn.\n";
  dest_dir = ({
    "players/angmar/fairyland/corn1", "south",
  });
  items = ({
    "corn", "Ears and ears of it...waiting to be picked",
    "ears", "The corn is not yet ripe, so do not try to pick it",
    "cornfield", "Acres of corn, as far as you can see",
  });
}

void
init(){
  room::init();
  add_action("get","get");
  add_action("get","take");
  add_action("pick", "pick");
}
status
get(string str) {
  if(!present("corncob") || 
     (str != "corncob" && 
      str != "cob" &&
      str != "all") ||
     !present("scarecrow"))
    return 0;
  write("The scarecrow notices your attempt to steal the corn and grabs "+
        "your hand!\n");
  say("The scarecrow notices "+ this_player()->query_name() +"'s attempt to\n"+
      "steal the corn and grabs his hand!\n");
  present("scarecrow")->attacked_by(this_player());
  return 1;
}  

string realm() { return ("fairyland"); }

status
pick(string str) {
  if (!str)
    return 0;
  if (str != "corn" && str != "ears")
    return 0;
  write("They are not yet ripe.\n");
  say(this_player()->query_name() + 
      " starts to pick corn, but realizes that it is not ripe yet.\n");
  return 1;
}
