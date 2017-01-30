#define TP  this_player()
#define TO  this_object()
#define ENV environment
#define TPN capitalize(TP->query_name())
#define TE  tell_object
#define TR  tell_room
#define STR capitalize(str)

int local_weight, foll, folldelay;
string follname, droidid;

id(str) { return str == "droid" || str == droidid; }

short() { return "A slave droid";}

long() {
  write(
"This is moving safe storeage for a player.\n"+
"The code will be in a seperate file\n"+
"Usage:\n"+
"droidlink'...........................droid follows you\n"+
"droidunlink'.........................turn follow off\n"+
"put <what> in droid'.................load up your droid\n"+
"get <what> from droid'...............get something from it\n"+
"ddrop <object>.......................droid drops object\n"+
"dsell <object> ......................droid sells <object>\n"+
"dallsell.............................droid sells its inventory\n"+
"dswoop...............................droid picks up objects in room\n"+
"trade <this> with <whom> for <that>..make a trade\n");
  if (first_inventory(TO)) write("There is something in it.\n");
  else write("You can put things in it.\n");
}

init() {
  if(present("CyberNinja Implants",this_player())) {
add_action("follow","droidlink");
add_action("trade","trade");
add_action("followoff", "droidunlink");
add_action("droid_drop", "ddrop");
add_action("droid_sell","dsell");
add_action("droid_all_sell","dallsell");
add_action("droid_swoop","dswoop");
  }
}

set_follname(str) { follname = str; }
query_follname() { return follname; }
set_droidid(str) { droidid = str; }
query_foll() { return foll; }

reset(arg) {
    if (arg) return;
    droidid = "opendroid";
    local_weight = 0; }

query_save_flag() { return 1; }

string gen(object ob) {
  return ((string)ob->query_possessive());
}

add_weight(w) {
    int max;
    max = present("implants", TP)->guild_lev();
    max = max * 3;
    if (local_weight + w > max)
        return 0;
    local_weight += w;
    return 1;
}

query_weight() { return 1; }
query_value() { return 0; }
can_put_and_get() { return 1; }
get() { return 1; }

prevent_insert() {
    if (local_weight > 0) {
        write("You can't when there are things in the droid.\n");
        return 1;
    }
    return 0;
}

follow() {
    if(follname && TP->query_real_name() != follname &&
    find_player(follname)) return 0;
  foll = 1;
  follname = TP->query_real_name();
  droidid = TP->query_real_name()+"droid";
  call_out("fake_beat",5);
  write("You activate your droid follow.\n");
  say(TPN+" activates "+gen(TP)+" droid.\n");
  return 1;
}

followoff() {
    if(follname && TP->query_real_name() != follname &&
    find_player(follname)) return 0;
  foll = 0;
  write("You deactivate your droid follow.\n");
  say(TPN+" deactivates "+gen(TP)+" droid.\n");
  return 1;
}

fake_beat() {
  if(foll == 1) {
  call_out("fake_beat",5);
  follow_move(follname);
   }
  return 1;
}

follow_move(string str) {
  if(!find_player(follname)) {
    foll = 0; follname = 0; return; }
  if(!present(follname,ENV(TO))) {
    move_object(TO, ENV(find_player(follname)));
   tell_object(find_player(follname), "Your droid flies in.\n");
    }
return 1;
}

droid_drop(str) {
  object ob;
  if(!str) { write("Usage: ddrop <object>.\n"); return 1; }
  ob = present(str, this_object() );
  if(!ob) { write(capitalize(str)+" is not on droid.\n"); return 1; }
  transfer(ob, environment(this_object()) );
  write("Your droid drops [ "+ob->short()+" ].\n");
  return 1;
}

trade(string str) {
  string this, that, whom, name;
  object this_ob, that_ob, who, trade;
    if(follname && TP->query_real_name() != follname &&
    find_player(follname)) return 0;
  if(!str) {
    write("Usage: trade <this> with <whom> for <that>\n");
    return 1; }
  if(!sscanf(str, "%s with %s for %s", this, whom, that)) {
    write("Usage: trade <this> with <whom> for <that>\n");
    return 1; }
  if(!present(this, TP)) {
    write("You do not have a "+this+".\n");
    return 1; }
  this_ob = present(this, TP);
  if(!find_player(whom)) {
    write(whom+" is not on Nirvana.\n");
    return 1; }
if(find_player(whom)->query_invis()) { write(whom+" is not on Nirvana.\n"); return 1; }
  if(environment(find_player(whom))->realm() == "NT" || 
     environment(this_player())->realm() == "NT") {
       write("Either you or the target is in a restricted zone.\n"+
             "The object can not be sent.\n");
  return 1; }
  who = find_player(whom);
  if(who == TP) {
    write("Your droid measures up your I.Q.\n");
    return 1; }
  name = capitalize(who->query_real_name());
  if(!present(that, who)) {
    write(name+" does not have a "+that+".\n");
    return 1; }
  that_ob = present(that, who);
  if(this_ob->drop() == 1 || that_ob->drop() == 1) {
    write("You cannot trade in that manner.\n");
    return 1;
  }
  trade = clone_object
    ("/players/snow/closed/cyber/trade.c");
  move_object(trade, who);
  trade->activate(who, TP, this_ob, that_ob, this, that);
  write("Your droid zips away with the goods.\n");
  write("Your trade: "+name+"'s "+that+" for your "+this+".\n");
  write("Waiting for "+name+" to accept the trade...\n");
  return 1; }

droid_sell(arg) {
  object tosell;
  int price;
    if(follname && TP->query_real_name() != follname &&
    find_player(follname)) return 0;
  if(!arg) { notify_fail("Dsell what object?\n"); return 0; }
  tosell = present(arg,TO);
  if(!tosell) tosell = present(arg,TP);
  if(!tosell) tosell = present(arg,ENV(TP));
  if(!tosell) { write("There is no "+capitalize(arg)+" to sell.\n"); return 1; }
  price = tosell->query_value();
  if(price < 1) { write("You cannot sell "+capitalize(arg)+".\n"); return 1; }
  transfer(tosell,"/room/store.c");
  tell_room(ENV(TP),TP->query_name()+"'s droid sells ["+tosell->short()+
           "]\n");
  if(price > 1000) price = 1000;
  TP->add_money(price);
  write("You receive ["+price+"] coins.\n");
  write("You now have ["+TP->query_money()+"] coins.\n");
  return 1;
}

droid_all_sell() {
  object this;
  int i;
    if(follname && TP->query_real_name() != follname &&
    find_player(follname)) return 0;
  this = all_inventory(this_object());
  for(i = 0; i < sizeof(this); i++) {
    if(this[i]->query_value() > 0) droid_other_sell(this[i]);
  }
  return 1;
}

droid_other_sell(object ob) {
  int price;
    if(follname && TP->query_real_name() != follname &&
    find_player(follname)) return 0;
  price = ob->query_value();
  if(price > 1000) price = 1000;
  transfer(ob,"/room/store");
  tell_room(environment(TP),
    TP->query_name()+"'s droid sells ["+ob->short()+"]\n");
  write("Your droid gives you ["+price+"] coins.\n");
  TP->add_money(price);
  write("You now have ["+TP->query_money()+"] coins.\n");
  return 1;
}

droid_swoop() {
  object room, contents;
  int i;
    if(follname && TP->query_real_name() != follname &&
    find_player(follname)) return 0;
  room = environment(TP);
  contents = all_inventory(room);
  for(i = 0; i < sizeof(contents); i++) {
  if(contents[i]->get() && contents[i]->query_weight() < 10 &&
    contents[i]->query_weight() && !contents[i]->id("money") &&
    contents[i] != this_object()) {
      tell_room(environment(TP),
        TP->query_name()+"'s droid picks up ["+contents[i]->short()+"]\n");
      move_object(contents[i],TO);
    }
  }
  return 1;
}
