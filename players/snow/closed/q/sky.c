inherit "room/room";
 

int block;
string blockname;
set_block(int b) { block = b; }
set_blockname(string bn) { blockname = bn; }

#define TP this_player()

reset(arg){
 
 if(!arg){
 
 set_light(1);
  short_desc="Sky";
 long_desc=
    "\nYou seem at first glance to be floating in the sky.\n"+
    "As you look around however, you notice no visible mass\n"+
    "anywhere within sight. This appears to be an infinite\n"+
    "space.\n\n";
 
  }   }
 
query_realm() { return "NT"; }

init() {
  ::init();
  if(block) {
      if(TP->query_real_name() != blockname &&
       TP->query_race() != "dragonlord") {
      tell_object(TP,"You are thrown from the sky!\n");
      move_object(TP,"/room/plane10");
    }
  }
}

delay_appear() {
  call_out("appear",200);
  return 1;
}

appear() {
  object dl;
  dl = clone_object("/players/snow/closed/q/dragonlord.c");
  move_object(dl,this_object());
  tell_room(this_object(),
    "\nTHE SKY TURNS TO SHIMMERING GOLD!\n\n"+
    "      A DRAGONLORD APPEARS\n\n");
  return 1;
}
