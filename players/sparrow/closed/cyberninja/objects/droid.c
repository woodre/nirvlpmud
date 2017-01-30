#include "../DEFS.h"


int local_weight, folldelay;
string follname, droidid;
status foll;

status id(string str) { 
  return str == "droid" || str == droidid; 
}

short() { return "A slave droid"; }

long() {
  if(IPTP) {
  write(
  "This is moving safe storeage for a player.\n"+
  "The code will be in a seperate file\n"+
  "Usage:\n"+
  "droidlink'....................droid follows you\n"+
  "droidunlink'..................turn follow off\n"+
  "put <what> in droid'..........load up your droid\n"+
  "get <what> from droid'........get something from it\n"+
  "ddrop <object>................droid drops object\n"+
  "dsell <object> ...............droid sells <object>\n"+
  "dallsell......................droid sells its inventory\n"+
  "dswoop........................droid picks up objects in room\n"+
  "trade <this> with <whom> for <that>..make a trade\n");
  if (first_inventory(this_object())) write("There is something in it.\n");
  else write("You can put things in it.\n");
  } else write("A droid.\n");
}

init() {
  if(IPTP) {
    add_action("follow",      "droidlink");
    add_action("trade",       "trade");
    add_action("followoff",   "droidunlink");
    add_action("droid_drop",  "ddrop");
    add_action("droid_sell",  "dsell");
    add_action("droid_all_sell","dallsell");
    add_action("droid_swoop", "dswoop");
  }
}

set_follname(string str) { follname = str;  }
string query_follname()  { return follname; }
set_droidid(string str)  { droidid = str;   }
status query_foll()      { return foll;     }

reset(arg) {
  if (arg) return;
  droidid = "opendroid";
  local_weight = 0;
}

status add_weight(int w) {
  int max;
  if(!IPTP) return 0;
  max = (int)IPTP->guild_lev();
  max = max * 3;
  if (local_weight + w > max) return 0;
  local_weight += w;
  return 1;
}

status query_save_flag() { return 1; }
int query_weight()       { return 1; }
int query_value()        { return 0; }
status can_put_and_get() {
  if(follname && (string)TP->query_real_name() != follname) return 0;
  else return 1; }
status get()             { return 0; }


prevent_insert() {
  if (local_weight > 0) {
    write("You can't when there are things in the droid.\n");
    return 1;
  }
  return 0;
}

status follow() {
  if(follname && (string)TP->query_real_name() != follname &&
    find_player(follname)) 
    return 0;
  foll = 1;
  follname = (string)TP->query_real_name();
  droidid = (string)TP->query_real_name()+"droid";
  call_out("fake_beat",5);
  write("You activate your droid follow.\n");
  say(TPN+" activates "+TP->POS+" droid.\n");
  return 1;
}

status followoff() {
  if(follname && (string)TP->query_real_name() != follname) return 0;
  foll = 0;
  write("You deactivate your droid follow.\n");
  say(TPN+" deactivates "+TP->POS+" droid.\n");
  write("Droid will self-destruct in 25 seconds.\n");
  return 1;
}

self_destruct() {
  if(!foll) {
    tell_room(environment(this_object()), "A droid self-destructs.\n");
    destruct(this_object()); }
return; }

void follow_move(string str) {
  if(!find_player(follname) || find_player(follname)->query_ghost()) {
    foll = 0; 
    follname = 0; 
    return; 
  }
  if(!present(follname, environment(this_object()))) {
    move_object(this_object(), environment(find_player(follname)));
    tell_object(find_player(follname), "Your droid flies in.\n");
  }
}

status fake_beat() {
  if(!foll) call_out("self_destruct", 25);
  if(foll == 1) {
    call_out("fake_beat",5);
    follow_move(follname);
  }
  return 1;
}

status droid_drop(string str) {
  object ob;
  if(follname && (string)TP->query_real_name() != follname) return 0;
  if(find_player(follname)->query_ghost()) return 0;
  if(!str) { 
    write("Usage: ddrop <object>.\n"); 
    return 1; 
  }
  ob = present(str, this_object() );
  if(!ob) { write(capitalize(str)+" is not on droid.\n"); return 1; }
  transfer(ob, environment(this_object()) );
  write("Your droid drops [ "+ob->short()+" ].\n");
  return 1;
}

status trade(string str) {
  string this, that, whom, name;
  object this_ob, that_ob, who, trade;
  if(follname && (string)TP->query_real_name() != follname) return 0;
  if(find_player(follname)->query_ghost()) return 0;
  if(!str || !sscanf(str, "%s with %s for %s", this, whom, that)) {
    write("Usage: trade <this> with <whom> for <that>\n");
    return 1; }
  if(!present(this, TP)) {
    write("You do not have a "+this+".\n");
    return 1; }
  this_ob = present(this, TP);
  if(!find_player(whom) || find_player(whom)->query_invis()) { 
    write(whom+" is not on Nirvana.\n"); 
    return 1; }
  if((string)environment(find_player(whom))->realm() == "NT" || 
     (string)environment(this_player())->realm()     == "NT") {
      write("Either you or the target is in a restricted zone.\n"+
            "The object can not be sent.\n");
    return 1; }
  who = find_player(whom);
  if(who == TP) {
    write("Your droid measures up your I.Q.\n");
    return 1; }
  name = capitalize((string)who->query_real_name());
  if(!present(that, who)) {
    write(name+" does not have a "+that+".\n");
    return 1; }
  that_ob = present(that, who);
  if((status)this_ob->drop() == 1 || (status)that_ob->drop() == 1) {
    write("You cannot trade in that manner.\n");
    return 1;
  }
  trade = clone_object(OBJDIR + "/trade.c");
  move_object(trade, who);
  trade->activate(who, TP, this_ob, that_ob, this, that);
  write("Your droid zips away with the goods.\n");
  write("Your trade: "+name+"'s "+that+" for your "+this+".\n");
  write("Waiting for "+name+" to accept the trade...\n");
  return 1; 
}

status droid_sell(string arg) {
  object tosell;
  int price;
  if(follname && (string)TP->query_real_name() != follname) return 0;
  if(find_player(follname)->query_ghost()) return 0;
  if(!arg) { 
    notify_fail("Dsell what object?\n"); 
    return 0; }
  tosell = present(arg,this_object());
  if(!tosell) tosell = present(arg,TP);
  if(!tosell) tosell = present(arg,environment(TP));
  if(!tosell) { 
    write("There is no "+capitalize(arg)+" to sell.\n"); 
    return 1; }
  price = (int)tosell->query_value();
  if(price < 1) { write("You cannot sell "+capitalize(arg)+".\n"); return 1; }
  tell_room(environment(TP),(string)TP->query_name()+"'s droid sells ["+
    tosell->short()+"]\n");
  destruct(tosell);
  if(price > 1000) price = 1000;
  TP->add_money(price);
  write("You receive ["+price+"] coins.\n");
  write("You now have ["+(int)TP->query_money()+"] coins.\n");
  return 1;
}

status droid_other_sell(object ob) {
  int price;
  if(follname && (string)TP->query_real_name() != follname) return 0;
  if(find_player(follname)->query_ghost()) return 0;
  price = (int)ob->query_value();
  if(price > 1000) price = 1000;
  tell_room(environment(TP),
    (string)TP->query_name()+"'s droid sells ["+ob->short()+"]\n");
  destruct(ob);
  write("Your droid gives you ["+price+"] coins.\n");
  TP->add_money(price);
  write("You now have ["+(int)TP->query_money()+"] coins.\n");
  return 1;
}

status droid_all_sell() {
  object *this;
  int i;
  if(follname && (string)TP->query_real_name() != follname &&
    find_player(follname)) 
    return 0;
  if(find_player(follname)->query_ghost()) return 0;
  this = all_inventory(this_object());
  for(i = 0; i < sizeof(this); i++) {
    if(this[i]->query_value() > 0) droid_other_sell(this[i]);
  }
  return 1;
}

status droid_swoop() {
  object room;
  object * contents;
  int i;
  if(follname && (string)TP->query_real_name() != follname) return 0;
  if(find_player(follname)->query_ghost()) return 0;
  room = environment(TP);
  contents = all_inventory(room);
  for(i = 0; i < sizeof(contents); i++) {
  if(contents[i]->get() && contents[i]->query_weight() < 10 &&
    contents[i]->query_weight() && !contents[i]->id("money") &&
    contents[i] != this_object()) {
    tell_room(environment(TP),
      (string)TP->query_name()+"'s droid picks up ["+contents[i]->short()+"]\n");
    move_object(contents[i],this_object());
    }
  }
  return 1;
}
