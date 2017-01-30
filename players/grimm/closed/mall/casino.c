inherit "/room/room";
reset(arg) {
  if(!present("pokermachine",this_object())) {
    move_object(clone_object("/players/grimm/closed/obj/poker"),this_object());
  }
  if(arg) return;
  set_light(1);
  short_desc="Fred's Casino";
  long_desc="This is Fred's Casino.  Although Fred if very new to the business"+
  "\nhe is constantly trying to get new casino games in for your enjoyment.\n"+
  "The workers are bustling around the room hard at work.\n";
  dest_dir=({ "/players/grimm/closed/mall/hall4", "east", });
}
