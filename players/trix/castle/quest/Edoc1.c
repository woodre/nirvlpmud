inherit "room/room";
reset(arg) {
   object cloak;
   if(arg) return;
   set_light(1);
   long_desc =
              "You are in a tiny cold room, it's humid in here and u feel the need to cover\n"+
              "yourself. An old metal mirror framed with gold hangs from a wall.\n";
    short_desc = "A humid room";
    items = ({ "mirror","As you look into the mirror it gets black and you feel like it gets deep\n"+
               "as it attracs you. Suddenly you can see the room you came from through the\ndistorsion "+
               "of the mirror"});
    cloak=clone_object("/players/trix/castle/quest/monst/cloak");
    move_object(cloak,this_object());
}
init(){
 ::init();
  add_action("enter","enter");
}
enter(str)
{ if(str!="mirror") { write("Enter what?!?\n"); return 1; }
   write("You enter the mirror and get a strange feeling through every molecle of yours.\n");
   this_player()->move_player("mirror#"+"players/trix/castle/quest/Edod1");
   return 1;
}
realm(){return "NT";}
