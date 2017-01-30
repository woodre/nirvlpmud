
reset(arg) {
/*
   "players/sado/shop/shop"->short();
   if(!present("qdisp", find_object("players/sado/shop/shop"))) move_object(clone_object("players/quicksilver/nicker"), find_object("players/sado/shop/shop"));
*/
   if(arg) return;
   "players/quicksilver/workroom"->short();
   "players/quicksilver/closed/qtell"->id();
   "players/quicksilver/closed/qchan"->id();
   "players/quicksilver/closed/jtell"->id();  
   "players/quicksilver/closed/esoteric"->id();  
   "players/quicksilver/closed/wedding_band"->id();  
   return 1;
}

init() {
   if(environment(this_object())) {
       write("Freshening your Pooper!\n");
       reclone();
   }

}

get() { return 1; }
drop() { return 1; }
id(str) { return str=="qchatold"; }

reclone() {
     object poop;
     
     poop=clone_object("players/quicksilver/closed/qchan");
     if(poop) {
          move_object(poop, environment(this_object()));
          write("You're back on 'the throne' again.\n");
          destruct(this_object());
          return 1;
     }
     write("Something is rotten in the state of Denmark.\n");
     return 1;
}
