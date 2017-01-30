inherit "room/room";
init() {
  add_action("pray","pray");
  write_file("/players/grimm/closed/LOGS/stake",capitalize(this_player()->query_real_name())+" lvl "+this_player()->query_level()+" just got into the StakeRoomn\nThe time is: "+ctime(time())+"\n---------------------------------------\n");
  ::init();
}
reset(arg) {
  items();
    if (arg) return;

    set_light(1);
    short_desc = "Stake room";
    no_castle_flag = 0;
    long_desc = 
"This is the hiding place of the only item that can kill the evil vampire,\n"+
"Malachi.  Type \"pray\" to be reincarnated.  Then take everything and go\n"+
"kick his ass.\n";
    dest_dir =
        ({
         "/players/grimm/caverns/demonroom","up",
        });
}

query_light() {
    return 1;
}

pray() {
  if(!this_player()->query_ghost()) {
    write("You are not a ghost!\n");
    return 1;
  }
  if(this_player()->query_quests("sage")) {
    write("You have already finished the quest. Go do something else!\n");
    return 1;
  }
  pray2();
  this_player()->add_exp(((this_player()->query_exp()/10)*4));
  return 1;
}

pray2() { 
  return call_other(this_player(),"remove_ghost",0); }

items() {
  object stake, bane;
  object torch;
  if(!present("stake")) {
    stake = clone_object("/players/grimm/object/stake");
    move_object(stake,this_object());
  }
  if(!present("bane")) {
    bane = clone_object("/players/grimm/object/bane");
    move_object(bane,this_object());
  }
}
