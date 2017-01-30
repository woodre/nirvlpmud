inherit "/room/room";
reset(arg) {
  if(!present("guard")) {
    move_object(clone_object("/players/grimm/closed/mall/guard"),this_object());
  }
  if(arg) return;
  short_desc="Mall Entrance";
  long_desc="This is the entrance to Nirvana's newest shopping mall.\n"+
"Inside you'll find stores like: Paco's Tatoo Shop,  Daemon's Monster\n"+
"Truck Ralley,  Ziggy's Arcade,  and a few others.  Please enjoy and as\n"+
"always, comments are welcome, just mail Grimm.\n";
  dest_dir=({
         "/players/grimm/closed/mall/hall1", "north",
         "/room/vill_shore2", "down",
            });
  set_light(1);
}
