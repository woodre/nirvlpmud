inherit "room/room";
 
reset(arg) {
   object condom;
   if(arg) return;
   set_light(1);
   long_desc = 
"  This is the local SexShop.  The room is full of strange items you never\n"+ 
"imagined could exist.  But they're kept behind glasses so you can't touch\n"+
"them.\n";
   short_desc = "Trixtown SexShop";
   dest_dir = ({ "/players/trix/castle/town/1str3n.c","east"});
   condom=clone_object("/players/trix/castle/town/monst/condom");
   move_object(condom,this_object());
}
