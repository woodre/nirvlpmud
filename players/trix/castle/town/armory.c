inherit "room/room";
 
reset(arg) {
  if(!present("seller"))
    move_object(clone_object("/players/trix/castle/town/monst/weaponseller"));
  if(arg) return;
  set_light(1);
  long_desc = 
"  You are in Trixtown armory.  You can see a huge amount of weapons and all\n"+
"kinds of items that have anything to do with them.\n";
  short_desc = "Trixtown Armory";
  dest_dir = ({ "/players/trix/castle/town/1str3n.c","west"});
}
