inherit "room/room";
object gargoyle,cloak;
reset(arg) {
  monst();
  if(arg) return;
  short_desc="Gargoyle Lair";
  long_desc=
    "You have entered the lair of the Gargoyle, protector of the cloak.\n"+
    "Many years ago the great vampire Malachi conjured up this cloak\n"+
    "for one of his most trusted vampires, but during a great battle\n"+
    "the vampire was captured and burned.  The cloak, being of the\n"+
    "great evil it was, remained in the ashes.  So that no other would\n"+
    "ever possess the cloak, Malachi created a horrible gargoyle to\n"+
    "guard it and hid it here!\n";
  items=
    ({"vegetation","It is a great mass of thorns with red and black leaves\n"+
      "that seem to be drawn by the blood in your body!"});
  dest_dir=({"players/grimm/frst/forest6","east"});
  set_light(1);
}
monst() {
  if(!present("gargoyle",this_object())) {
    gargoyle = clone_object("players/grimm/monster/gargoyle2");
    move_object(gargoyle,this_object());
    cloak = clone_object("players/grimm/armor/malachi_cloak");
    move_object(cloak,gargoyle);
  }
}
