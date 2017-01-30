inherit "room/room";
 
reset(arg) {
   object jeweller;
  if(!present("jeweller"))
    move_object(clone_object("/players/trix/castle/town/monst/jeweller"),this_object());
  if(arg) return;
  set_light(1);
  long_desc = 
"  This is the Trixtown local jewelry, a well lit shop full of precious stones\n"+
"that you can see through the many security glasses.  My, how much money in the\n"+
"same room!\n";
  short_desc = "Trixtown jewelry";
  dest_dir = ({ "/players/trix/castle/town/1str2n.c","east"});
}
