inherit "room/room";
 
reset(arg) {
  object ungwe;
  if(!present("ungweliante"))
    move_object(clone_object("/players/trix/castle/town/monst/ungwe"),this_object());
  if(arg) return;
  set_light(1);
  long_desc = 
"  This is Ungweliante's cove.  There are webs everywhere on the walls dug in\n"+
"the naked rock.  The warm air around you is narcotic and makes you feel tired\n"+
"and weak.  You wonder why the hell you dared to come here.\n";
  short_desc = "Ungweliante's cove";
  dest_dir = ({ "/players/trix/castle/town/coven.c","west"});
}
