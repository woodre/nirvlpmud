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
{ object cloak;
if(str!="mirror") { write("Enter what?!?\n"); return 1; }
   cloak=present("trixcloak",this_player());
   if(!cloak) { write("You have not the proper protection to pass through the mirror in the inverse\nway.\n");
                return 1; }
   if(!call_other(cloak,"query_worn")) { 
   if(this_player()->query_guild_name()=="monk")
    { write("Monks can enter the mirror without wearing the cloak!\n"+
          "You enter the mirror and feel a tremendous power that could have burnt you\n"+
          "without the protection of the cloak.\n");
   this_player()->move_player("mirror#"+"players/trix/castle/quest/dod1");
   return 1;  
    }    
   write("You don't wear the proper protection to pass through the mirror in the inverse\nway.\n"); 
                                          return 1;}
   write("You enter the mirror and feel a tremendous power that could have burnt you\n"+
        "without the protection of the cloak.\n");
   this_player()->move_player("mirror#"+"players/trix/castle/quest/dod1");
   return 1;  
}
realm(){return "NT";}
