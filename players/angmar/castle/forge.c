inherit "room/room";

void
reset(status arg) {
  if (arg)
    return;
  set_light(1);
  set_light(1);
  short_desc = "The forge";
  long_desc = 
    "You are in Angmar's forge.  Angmar's smith stands here, doomed to\n" +
    "serve him forever.  The smith will value armors and weapons\n" +
    "for a reasonable fee.\n" +
    "'cost item' shows what the smith would take to value the item.\n" +
    "'show item' shows the item to the smith.\n";
  dest_dir = ({
    "players/angmar/castle/inside", "east",
  });
  items = ({
    "forge", "There is little left of the forge, except a very tired smith",
    "smith", "The smith sighs.  He is locked into the service of Angmar, unto death",
  });
}

query_inorout() { return 1; }

status 
smith_thank(string str) {
  if (!str)
    return 0;
  if (str == "smith") {
    tell_object(this_player(), "The smith smiles wearily at you and goes back to his work.\n");
    say(this_player()->query_name() + " thanks the smith.\n");
    say("The smith smiles wearily at " + this_player()->query_name() +
      " and goes back to his work.\n");
    return 1;
  }
  return 0;
}

void
init() {
  room::init();
  add_action("show","show");
  add_action("smith_thank", "thank");
  add_action("cost","cost");
}

status
cost(object item) {
  object itemob;
  int val;

  if (!item)
    return 0;
  itemob = present(item,this_player());
  if (!itemob) {
    write("No such item here.\n");
    return 1;
  }
  val = (int)itemob->query_value();
  val = val / 5;
  if (val<30)
    val=30;
  if (val>800)
    val=800;
  write("The smith would take "+val+" coins to value "+itemob->short()+".\n");
  return 1;
}

status
show(object item) {
  object itemob;
  int ac,wc,val,cost;

  if (!item)
    return 0;
  itemob = present(item,this_player());
  if (!itemob) {
    write("No such item here.\n");
    return 1;
  }
  ac = (int)itemob->armor_class();
  if(!ac)
    ac=0;
  wc = (int)itemob->weapon_class();
  if (!wc)
    wc=0;
  val = ac*4;
  if (wc > val) {
    val = wc;
    ac = 0;
  }
  else
    wc = 0;
  cost = (int)itemob->query_value();
  cost = cost / 5;
  if (cost < 30)
    cost = 30;
  if (cost > 800)
    cost = 800;
  if (val == 0) {
    write("The smith is not interested in such items.\n");
    return 1;
  }
  if (cost > this_player()->query_money()) {
    write("You don't have enough money to pay the smith.\n");
    return 1;
  }
  if (itemob->id("doomsgiver")) {
    write("The smith nods. He says: 'I recognise this weapon. It was\n");
    write("made by Angmar himself.'  The smith seems to fall in deep\n");
    write("thougts and shudders at some memory. After a while he looks up\n");
    write("and says: 'Anyway, it is the most powerful weapon I know of,\n");
    write("but it can only be used by evil persons.'\n");
  }
  else if (val > 20) {
    write("The smith gasps. He says: 'where did you get this?\n");
    write("The knowledge to make such fine handicraft is long\n");
    write("forgotten in this world, I'm sorry to say.\n");
    if (wc > 0)
      write("It is an extremely powerful weapon! Use it with care.'\n");
    else
      write("It is an extremely good armor! Don't loose it!'\n");
  }
  else if (val > 17) {
    write("The smith rises his eyebrows. He says: I'm impressed!\n");
    write("It would be hard to find a better ");
    if (wc > 0)
      write("weapon than this one.\n");
    else
      write("armor than this one.\n");
    write("It should serve you well in your future battles.\n");
  }
  else if (val > 13) {
    write("The smith nods appreciatively. He says: a very fine ");
    if (wc > 0)
      write("weapon.\n");
    else
      write("armor.\n");
    write("It has been used in many battles, I can see, but it is\n");
    write("still fully functional.\n");
  }
  else if(val > 9) {
    write("The smith examines "+itemob->short()+".\n");
    write("It's good enough. He says finally.\n");
    write("It's not of the very best quality though, I wouldn't try\n");
    write("to do battle with any great warrior with it if I were you.\n");
  }
  else if (val > 5) {
    write("The smith frowns. He says: Hmm... I hope you didn't pay\n");
    write("much for this? You should get yourself a better one.\n");
    write("You could easily get killed, if you should happen to\n");
    write("run into any big monsters, you know.\n");
  }
  else {
    write("The smith sighs and shakes his head. 'Cheap crap.' He says.\n");  
    write("Hardly worth anything. ");
    if (wc > 0)
      write("  I doubt you could even kill an orc with it.\n");
    else
      write("It probably couldn't even stop\nthe blow from a small knife.\n");
  }
  this_player()->add_money(-cost);
  write("You give the smith "+cost+" coins.\n");
  return 1;
}
