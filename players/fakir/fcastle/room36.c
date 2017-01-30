inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Apothecary Shop";
long_desc =
"   Dried herbs in bundles, and skins from unknown animals hang from\n"+
"the low rafters of the healer's ceiling.  A low counter covered with\n"+
"bottles stands along the far wall.  Dust covers almost every surface\n"+
"in the dingy room.  A doorway leads to a backroom.\n";

items = ({
"herbs",   "Healing plants from around the realm, some with names lost in time",
"bundles", "Herbs tied in bunches with a thin cotton string",
"skins",   "Hides from strange and magical animals",
"rafters", "Blah. They keep the roof from falling in",
"counter", "A wooden counter with two drawers",
"bottles", "Glass bottles filled with colored liguids",
"wall",    "Its just a plain old wall",
"dust",    "Your everyday average kind",
"doorway", "It has no door. Its really just an opening",
"backroom","A room adjoining the apothecary used mostly for storage",

});
if(!present("quagmire",this_object()))
 move_object(clone_object("/players/fakir/fcastle/NPC/tclerk.c"),this_object());

dest_dir = ({
   "/players/fakir/fcastle/room32.c", "out",
   "/players/fakir/fcastle/room43.c", "backroom",
   
});
}


