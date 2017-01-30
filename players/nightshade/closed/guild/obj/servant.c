inherit "obj/monster";
int max_weight, local_weight;
object next_ob;
object it;
  string who;
int check;
int warn;
reset(arg) {
::reset(arg);
if(arg) return;
  set_name("unseen servant");
  set_alias("servant");
  set_ac(50);
  set_wc(0);
  set_hp(5000);
  set_level(20);
  local_weight = 0;
}

init() {
::init();
  add_action("send_away","send");
  add_action("servant_command","servant");
  add_action("pre_name", "prename");
  add_action("end_name", "endname");
}

query_follower() { return 1; }

pre_name(str) {
  if(!str) {
    write("It will look like this: <name of servant>, Owner's unseen servant.\n");
    return 1;
  }
  if(this_player()->query_name() != who) {
    write("You do not own this servant.\n");
    return 1;
  }
  set_short(str + ", "+who+"'s unseen servant");
  write("The unseen servant has been named.\n");
  return 1;
}
end_name(str) {
  if(!str) {
    write("It will look like this: Owner's unseen servant named <name>.\n");
    return 1;
  }
  if(this_player()->query_name() != who) {
    write("You do not own this servant.\n");
    return 1;
  }
  set_short(who+"'s unseen servant named "+str);
  write("The unseen servant has been named.\n");
  return 1;
}
query_npc() { return 1; }
long() {
  write(
  "     An unseen servant. Clerics use it to carry some of\n"
+ "     their load. This is a faithful servant and will not allow\n"
+ "     anyone to take stuff from it, unless he or she is it's\n"
+ "     master. This unseen  servant belongs to: "+
        this_object()->query_who()+ "\n");
  if(first_inventory(this_object()))
        write("");
  else
    write("\tThe servant is not carrying anything.\n");
  return 1;
}
query_max_weight() { return max_weight; }
query_weight() { return local_weight; }
add_weight(w) {
  if(local_weight + w > max_weight)
    return 0;
  local_weight += w;
  return 1;
}
can_put_and_get() {
  if(this_player()->query_name() != this_object()->query_who()) return;
  else return 1;
}

prevent_insert() {
  write("You can't put the servant into a container!\n");
  return 1;
}

set_who(w) { who = w; }
query_who() { return who; }
set_max_weight(w) { max_weight = w; }

send_away(str) {
  if(str == "servant") {
    if(this_player()->query_name() != this_object()->query_who()) {
      write("You can not send this servant away. It is not yours.\n");
      return 1;
    }
    write("You send your servant away.\n");
    say(this_player()->query_name() + " sends the servant away.\n",
        this_player());
    command("drop all");
    destruct(this_object());
    return 1;
  }
  return 0;
}

heart_beat() {
object master;
::heart_beat();
  master = find_player(lower_case(this_object()->query_who()));
  if(!master) {
    say("The servant leaves, because its master is away.\n");
    command("drop all");
    destruct(this_object());
    return 1;
  }
  if(!present(master, environment(this_object())) &&
        environment(master)->query_property("NT")) {
    if(!warn) {
        tell_object(master,
      "The servant can not follow you into this room. It will wait.\n");
    }
    warn = 1;
    check = 1;
  }
  if(!present(master, environment(this_object())) &&
        !check) {
    say("The servant leaves in search of its master.\n");
    move_object(this_object(), environment(master));
    say("A servant arrives.\n");
    return 1;
  }
}

hit_player() {
  stop_fight();
  this_player()->stop_fight();
  write("You can not attack this servant.\n");
  return 0;
}

servant_command(str) {
object ob;
int money;
  if(this_player()->query_name() != this_object()->query_who()) {
    write("You do not own this servant.\n");
    return 1;
  }
  if(str == "follow") {
    if(!check) {
      write("The servant is already following you.\n");
      return 1;
    }
    write("The servant will now follow you.\n");
    check = 0;
    warn = 0;
    return 1;
  }
  if(str == "stay") {
    if(check) {
      write("The servant is not following you.\n");
      return 1;
    }
    write("The servant will now stay.\n");
    check = 1;
    return 1;
  }
  /*
  if(str == "get all") {
    write("The servant picks up as much as it can from the ground.\n");
    ob = first_inventory(environment(this_object()));
    while(ob) {
      pick_any_obj();
      if(pick_any_obj()) return 1;
      ob = next_inventory(ob);
    }
    return 1;
  }
  if(str == "get") {
    write("The servant will attempt to get an object from the ground.\n");
    pick_any_obj();
    return 1;
  }
  */
  if(str == "get all") {
   ob = first_inventory(environment(this_object()));
   while(ob) {
      string item;
      next_ob = next_inventory(ob);
      item = ob->short();
     if(item && ob->get() && (ob->query_name() != "coins")) {
         int weight;
         weight = ob->query_weight();
         if (add_weight(weight)) {
            write(item + ": Ok.\n");
            move_object(ob, this_object());
            say(cap_name + " takes: " + item + ".\n");
         } else {
            write(item + ": Too heavy.\n");
         }
         it = item;
      }
      ob = next_ob;
   }
  return 1;
  }
  if(str == "sell all") {
    command("sell all");
    write("The servant sells everything it had on it.\n");
    write("The sales person hands you all the money.\n");
    money = this_object()->query_money();
    this_player()->add_money(money);
    this_object()->add_money(-money);
    return 1;
  }
  write("Commands are: servant, prename, endname, and send.\n");
  write("servant <follow>,<stay>,<sell all>.\n");
  write("prename <name of servant>. Just type <prename> for more info.\n");
  write("endname <name of servant>. Just type <endname> for more info.\n");
  write("send servant: gets rid of the servant.\n");
  return 1;
}

servant_blah() {
  check = 0;
  warn = 0;
  tell_room(environment(this_object()),
        "A servant leaves for its master.\n");
  return 1;
}

