#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define DAEMON "/players/jaraxle/templar/gdaemon.c"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Donation Room of the Templars";
long_desc =
"  This is a small dimly lit room next to the church.  A large donation\n"+
"bowl sits in the middle of the room. You see very little else adorning\n"+
"this plain room.\n";

items = ({
"bowl",
"Here you may 'donate' any items or coins in order to help pay for the\n"+
"maintenance of the Templars.  You may also 'cdonate' an item or\n"+
"coins for the maintenance of the castle and city defenses. You may\n"+
"move donation from personal to castle by using 'transfer <amount> donation'",
});

dest_dir = ({
  "/players/jaraxle/templar/rooms/church","east",
});

}

init(){ 
 ::init();
 add_action("cdonate", "cdonate");
 add_action("donate", "donate");
 add_action("transfer", "transfer");
   this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }


transfer(arg){
int mon;
object tcross;
tcross=present("KnightInvite", this_player());
if(!tcross) { write("You are not an ally or knight.\n"); return 1;}
 if(!arg) return 0;
 if(sscanf(arg,"%d donation",mon)==1) {
 if(!mon || mon < 0) return 0;
 if(tcross->query_donation() < mon) {
   write("You do not have that much in donation.\n");
   return 1;
  }
 tcross->add_donation(-mon);
 DAEMON->add_castle_donation(mon);
 write("You transfer "+mon+" donation to the castle funds.\n");
 return 1;
}
write("transfer <amount> donation\n");
return 1;
}

cdonate(arg) {
write("Donations are no longer needed, thank you. :)\n"); return 1; }
/*
int mon;
object tcross;
object item;
tcross=present("KnightInvite", this_player());
if(!tcross) { write("You are not an ally or knight.\n"); return 1;}
 if(!arg) return 0;
 if(sscanf(arg,"%d coins",mon)==1) {
 if(!mon || mon < 0) return 0;
 if(this_player()->query_money() < mon) {
   write("You do not have that many coins.\n");
   return 1;
  }
 this_player()->add_money(-mon);
 write("You toss your coins into the the bowl and watch as they magically\n"+
       "disappear into the coffers of the order.\n");
 write("You donate "+mon+" coins to the city and castle defense fund.\n");
 DAEMON->add_castle_donation(mon);
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
        "You realize that an item such as that is useless.\n");
  return 1;
 }
if(mon > 1500) mon = 1500 + random(300);
write("You toss your "+arg+" into the bowl. It quickly vanishes.\n"+
      "You find that it was worth a donation of "+mon+" coins.\n");
 DAEMON->add_castle_donation(mon);
 this_player()->add_weight(-item->query_weight());
 destruct(item);
 return 1;
}
*/


donate(arg) {
write("Donations are no longer needed, thank you. :)\n"); return 1; }
/*
int mon;
object tcross;
object item;
tcross=present("KnightTemplar", this_player());
if(!tcross) { write("You do not have your Templar cross.\n"); return 1;}
 if(!arg) return 0;
 if(sscanf(arg,"%d coins",mon)==1) {
 if(!mon || mon < 0) return 0;
 if(this_player()->query_money() < mon) {
   write("You do not have that many coins.\n");
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


*/
