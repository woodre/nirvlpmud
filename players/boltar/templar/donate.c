reset(arg) {
  if (arg) return;
  set_light(1);
}

short() { return "Knights Templar Donation Room "; }
     
long() {
  write("You are in a rather ornate room. It is empty except for a large\n"+
        "shallow metal bowl in the center of the room.  The bowl appears\n"+
        "to be made of gold and is attached to a six foot by six foot by\n"+
        "one foot high stone altar allowing one to step up to the five\n"+
        "foot diameter bowl.  It is here you may make donations of items\n"+
        "and money to the Templars to provide for the maintenance of the\n"+
        "order.  The only exit is to the west.\n");
}
init() {
add_action("west","west");
         add_action("look", "look");
     add_action("look", "l");
     add_action("look", "examine");
     add_action("look", "search");
add_action("donate","donate");
}

west() {
  this_player()->move_player("west#players/boltar/templar/armory");
  return 1;
}






donate(arg) {
int mon;
object tcross;
object item;
tcross=present("KnightTemplar", this_player());
if(!tcross) { write("You do not have your Templar cross.\n"); return 1;}
 if(!arg) return 0;
 if(sscanf(arg,"%d coins",mon)==1) {
 if(!mon || mon < 0) return 0;
 if(this_player()->query_money() < mon) {
   write("You do not have than much money.\n");
   return 1;
  }
 this_player()->add_money(-mon);
 write("You toss your coins into the the bowl and watch as they magically\n"+
       "disappear into the coffers of the order.\n");
 write("You donate "+mon+" coins to the Templars to pay for overhead costs.\n");
 tcross->add_donation(mon);
 tcross->save_ob();
 return 1;
 }
item=present(arg,this_player());
if(!item) {
 write("You do not have a "+arg+"\n");
 return 1;
}
mon = item->query_value();
if (call_other(item, "drop", 0)) {
   write("You cannot toss that item into the bowl.\n");
   return 1;
}
if(mon < 40) {
  write("You attempt to toss your "+arg+" into the bowl.\n"+
        "A voice calls out: 'We have no need for useless objects with no value'.\n");
  return 1;
 }
if(mon > 1500) mon = 1500 + random(300);
write("You toss your "+arg+" into the bowl. It quickly vanishes.\n"+
      "You find that it was worth a donation of "+mon+" coins.\n");
 tcross->add_donation(mon);
 tcross->save_ob();
 this_player()->add_weight(-item->query_weight());
 destruct(item);
 return 1;
}
look(str) {
   if (!str) {
   return 0;
  }
  if (str == "at bowl" || str == "at altar") {
write("The bowl has a magical aura about it.\n");
write("The bowl is empty.\n");
return 1;
}
return 0;
}
