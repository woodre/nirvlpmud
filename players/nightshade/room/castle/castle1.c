inherit "players/nightshade/new_room";
reset(arg){
   if(arg) return;
        set_light(1);
        short_desc = "Castle wall";
     long_desc =
"Right now you are walking through an archway that supports the castle\n"+
"wall. There are stairs leading up to the top of the wall itself.\n";
      dest_dir = 
({ "/players/nightshade/room/castle/castle2", "up",
   "/players/nightshade/room/castle/castle28", "north",
});
}
