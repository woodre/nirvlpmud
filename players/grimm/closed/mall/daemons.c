inherit "/room/room";
object truck, remote;
reset(arg) {
  if(arg) return;
  short_desc="Daemon's Monster Truck Ralley";
  set_light(1);
  dest_dir=({
             "/players/grimm/closed/mall/hall1", "west",
           });
}

long() {
  write("This is Daemon's Monster Truck Ralley.  Here you can race against\n"+
        "other players by renting a remote control for your monster truck\n"+
        "for a mere 200 coins for 10 minutes of play.  Once you have a truck\n"+
        "you'll be ready to rumble!  Just type \"rent truck\" to start!\n");
  return 1;
}

realm() { return "NT"; }

init() {
  add_action("restore","restore");
  add_action("store","store");
  add_action("unstore","unstore");
  add_action("rent","rent");
  ::init();
}

rent(str) {
  if(!str) {
    write("What do you want to rent?\n");
    return 1;
  }
  if(str!="truck") {
    write("What do you want to rent?\n");
    return 1;
  }
  if(present("monstertruckremote",this_player())) {
    write("Daemon says: You can only have one remote at a time.\n");
    return 1;
  }
  if(this_player()->query_money()<200) {
    write("You do not have enough coins for that.\n");
    return 1;
  }
  truck=clone_object("/players/grimm/closed/mall/truck/truck");
  remote=clone_object("/players/grimm/closed/mall/truck/remote");
  truck->set_cap_own(capitalize(this_player()->query_real_name()));
  truck->set_my_id(this_player()->query_real_name()+"truck");
  truck->set_nme(capitalize(this_player()->query_real_name())+"'s monster truck");
  truck->set_owner(this_player());
  truck->set_remote(remote);
  remote->set_owner(this_player());
  remote->set_truck(truck);
  remote->set_timeout(600);
  write("Daemon hands you a remote for your truck.  Type \"help truck\"\n"+
        "for a list of it's commands.\n");
  say(capitalize(this_player()->query_name())+" enters the race.\n");
  this_player()->add_money(-200);
  move_object(remote,this_player());
  move_object(truck,"/players/grimm/closed/mall/truck/start");
/*
  move_object(truck,environment(this_player()));
*/
  return 1;
}

im_daemons() { return 1; }

store() {
  string fn;
  if(!present("monstertruckremote",this_player())) {
    write("You do not currently have a truck rented.\n");
    return 1;
  }
  write("Storing Truck...\n");
  fn="players/grimm/truck/"+this_player()->query_real_name();
  if(file_size(fn+"r.o")==-1) {
    rm(fn+"r.o");
    rm(fn+"t.o");
  }
  present("monstertruckremote",this_player())->save_me(fn);
  if(file_size(fn+"r.o")!=-1) {
    write("ERROR!  Try again...\n");
    return 1;
  }
  write("Done.\n");
  return 1;
}

restore() {
  string fn;
  fn="players/grimm/truck/"+this_player()->query_real_name();
  if(file_size(fn+"r.o")!=-1) {
    write("There was an error in restoring your truck.\n"+
          "Try buying another.\n");
    return 1;
  }
  truck=clone_object("/players/grimm/closed/mall/truck/truck");
  remote=clone_object("/players/grimm/closed/mall/truck/remote");
/*
  rent("truck");
*/
  truck->restore_me(fn+"t.o");
  remote->restore_me(fn+"r.o");
  truck->set_remote(remote);
  remote->set_truck(truck);
  truck->set_owner(this_player());
  remote->set_owner(this_player());
  move_object(remote,this_player());
  move_object(truck,"/players/grimm/closed/mall/truck/start");
  write("Done.\n");
  return 1;
}
