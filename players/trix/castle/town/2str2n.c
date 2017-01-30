inherit "room/room";
 
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc = 
"  You're walking along Trixtown 2nd street, that runs from south to north.\n"+ 
"You can see Trixtown's Jail west of here, and Trixtown Municipal Infant House\n"+
"to the east.  It's closed, but there's a hole in the enclosure.  Maybe if\n"+
"you're small you can go east.\n";
   short_desc = "Trixtown 2nd street";
    dest_dir = ({ "/players/trix/castle/town/2str3n.c","north",
                  "/players/trix/castle/town/2str1n.c","south",
                  "/players/trix/castle/town/ingarden.c","east",
                  "/players/trix/castle/town/jailent.c","west"});
}
init(){
 ::init();
   add_action("east","east");
   add_action("west","west");
}
east(){
   if(call_other(this_player(),"query_level")>5)
     write("Hey!  You're not a newbie!  You would disturb that peaceful place!!!\n");
 else
 { write("You enter the quiet of Trixtown Municipal Infant House.\n");
   this_player()->move_player("east#players/trix/castle/town/ingarden");
 }
 return 1;
}
west(){ write("The jail is closed.\n"); return 1;}
