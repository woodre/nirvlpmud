/* shop.c: guild shop */
#define BACK_ROOM "/players/wizardchild/closed/logger/room/bkroom.c"
#define ME this_player()
#define THERE(ob) present("logger pack", ob)
inherit "room/room";
reset(arg) {
  if(arg) return 0;
  set_light(1);
  short_desc = "Logger's Guild shop";
  long_desc  = "This room is apparently where deals are made. In here, you can buy and sell\n"
              +"items like in a normal shop, or you can exchange them for guild ability.\n"
              +"To the north, there lies a door surrounded by a shimmering blue light.\n"
              +"Commands are: buy <item>, sell <item|all>, trade <item>, list, value <item>\n";
  dest_dir =
  ({
  "/players/wizardchild/closed/logger/room/g_hall.c", "down"
  });
}
init() {
  if(!present("logger pack", ME)) {
    write_file("/players/wizardchild/closed/logger/room/ILLEGAL_ENTRY",
    "<"+ctime(time())+"> "+ME->query_real_name()+" in shop.\n");
    move_object(ME, "room/plane12");
  } else {
    add_action("buy", "buy");
    add_action("sell", "sell");
    add_action("value", "value");
    add_action("trade", "trade");
    add_action("north", "north");
    add_action("north", "n");
    add_action("list", "list");
  }
  ::init();
}
north() {
  if(this_player()->query_level() < 21) {
    write("You walk into the blue light and are struck back!\n");
    say(ME->query_name()+" tried to go north but failed.\n");
    return 1;
  }
  write("You slip into the doorway.\n");
  say(ME->query_name()+" leaves north.\n");
  move_object(ME, BACK_ROOM);
  say(ME->query_name()+" arrives.\n");
  return 1;
}
list() {
  object ob;
  string out_str;
  ob = first_inventory(BACK_ROOM);
  while(ob) {
    if(ob->short()) {
      out_str = extract(ob->short()+"                ",0,30);
      write(out_str);
    }
    out_str = extract(": "+ob->query_value()+"       ",0,6);
    write(out_str+"\n");
    ob = next_inventory(ob);
  }
  return 1;
}
buy(str) {
  object ob;
  ob = BACK_ROOM->has_item(str);
  if(!ob) {
    write("Sorry, we do not have that in stock.\n");
    return 1;
  }
  if(ob->query_value() > ME->query_money()) {
    write("You do not have enough money to buy that.\n");
    return 1;
  }
  if(ME->add_weight(ob->query_weight())) {
    ME->add_money(-(ob->query_value()));
    move_object(ob, ME);
    say(ME->query_name()+" buys "+ob->short()+"\n");
    write("You buy "+ob->short()+".\n");
    return 1;
  }
  write("You cannot carry any more.\n");
  return 1;
}
sell(str) {
  object dump, ob, nob;
  status up;
  int cash;
  if(str == "all") {
    ob = first_inventory(ME);
    if(!THERE(ME)) return 1;
    while(ob) {
      nob = next_inventory(ob);
      if(!ob->short()) up = 1; else {
      write(ob->short()+": ");
      cash = ob->query_value();
      if(!cash) {
        write("no value\n");
        up = 1;
      }
      }
      if(cash > (THERE(ME)->query_grank()*100)+1000)
        cash = (THERE(ME)->query_grank()*100)+1000;
      if(!up && (ob->drop() || !ob)) {
        write("cannot be dropped\n");
        up = 1;
      }
      if(!up && !ME->add_weight(-(ob->query_weight()))) 
        write("too light\n");
      else if(!up) {
        move_object(ob, BACK_ROOM);
        say(ME->query_name()+" sells "+ob->short()+"\n");
        write("the shop gives you "+cash+" coins.\n");
        if(ob->query_dest_flag()) {
          write("The valuable item is hidden away.\n");
          dump = ob;
        }
        ME->add_money(cash);
        if(dump) destruct(dump);
      }
      ob = nob;
      up = 0;
    }
    return 1;
  }                
  ob = present(str, ME);
  if(!ob) {
    write("You do not have that.\n");
    return 1;
  }
  cash = ob->query_value();
  if(!cash) {
    write("That item has no value.\n");
    return 1;
  }
  if(cash > (THERE(ME)->query_grank()*100)+1000)
    cash = (THERE(ME)->query_grank()*100)+1000;
  if(ob->drop()) {
    write("You cannot drop that.\n");
    return 1;
  }
  if(!ME->add_weight(-(ob->query_weight()))) {
    write("You cannot drop that at this time.\n");
    return 1;
  }
  say(ME->query_name()+" sells "+ob->short()+"\n");
  write("The shop gives you "+cash+" coins.\n");
  this_player()->add_money(cash);
  move_object(ob, BACK_ROOM);
  if(ob->query_dest_flag()) {
    write("The valuable item is hidden away.\n");
    destruct(ob);
  }
  return 1;
}
value(str) {
  object ob;
  ob = present(str, ME);
  if(!ob) {
    write("You do not have that.\n");
    return 1;
  }
  if(ob->drop()) {
    write("You can't sell it anyways, why do you care?\n");
    return 1;
  }
  if(!ob->query_value()) {
    write("That item has no value.\n");
    return 1;
  }
  write("You would get: "+ob->query_value()+" coins.\n");
  return 1;
}
trade(str) {
  object ob;
  int val;  
  ob = present(str, ME);  
  if(!ob) {
    write("You do not have that item.\n");
    return 1;
  }
  if(ob->drop()) {
    write("You cannot drop that item.\n");
    return 1;
  }
  val = ob->query_value();
  if(!val) {
    write("That item has no value.\n");
    return 1;
  }
  if(val > 10000) val = 10000;
  write("You trade in "+ob->short()+" for "+(val/50)+" ability points.\n");
  move_object(ob, BACK_ROOM);
  destruct(ob);
  present("logger pack", this_player())->add_gpoints(val/50);
  return 1;
}
