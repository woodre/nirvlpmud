/* mist.h */

mist_dir(){
  write("You walk into the mist...\n\n");
  this_player()->move_player("into the mist#/players/zeus/realm/taus/circle9.c");
  return 1;
}

exit(){    if(this_player()) this_player()->clear_fight_area(); }
okay_follow() { return 1; }
realm(){   if(teleport) return "NT";  }

set_nt(x){ teleport = x; }
