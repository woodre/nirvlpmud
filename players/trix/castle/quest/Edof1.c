inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "This is a small room with a very low ceiling, the green light fills the room.\n"+
              "Next to a wall there's an old metal mirror framed with gold.\n";
    short_desc = "A low ceiling room";
    dest_dir = ({
                  "/players/trix/castle/quest/Edof2","east"
                                                        });
    items = ({ "mirror","As you look into the mirror it gets black and you feel like it gets deep\n"+
              "as it attracts you. Is there anything behind it? You should try to discover it"});
}
init(){
 ::init();
  add_action("enter","enter");
}
enter(str)
{ if(str!="mirror") { write("Enter what?!?\n"); return 1; }
   write("You enter the mirror and get a strange feeling through every molecle of yours.\n");
   this_player()->move_player("mirror#"+"players/trix/castle/quest/Edof");
   return 1;
}
realm(){return "NT";}
