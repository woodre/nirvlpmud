inherit "room/room";
reset(arg) {
   int abc;
   object rat;
   if(arg) return;
   set_light(1);
   long_desc =
  "You are following the flow of waste waters through the sewer of\n"+
  "Trixtown.  The tunnel runs east and west and a hole leads off\n"+
  "to the northeast.  There is a large catch basin down below\n"+
  "where the water flows out.\n";
    short_desc = "A dirty sewer";
    dest_dir = ({
                  "/players/trix/castle/quest/seg7","west",
	"players/trix/castle/quest/Esee10","down",
                  "/players/trix/castle/quest/seg9","east",
                  "/players/trix/castle/quest/sef9","northeast"
                                                        });
    abc = 0;
    if (!present("rat")) 
     {
      while(abc<random(4)) /* Was 7 instead of random(4) -Feld */
       {
        abc += 1;
        rat=clone_object("players/trix/castle/quest/monst/rat");
        move_object(rat,this_object());
       }
     }
}
realm(){return "NT";}

init() {
  ::init();
  add_action("down","down");
}

down() {
if(present("rat")) {
  write("The rat snarls and blocks your way...\n");
  return 1; }
else {
  this_player()->move_player("down#players/trix/castle/quest/Esee10.c");
  return 1; }
}
