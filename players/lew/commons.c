inherit "room/room";
int C;  /*  make sure only one meal card  */
reset(arg){
   object guard;
   if(!arg) {
C = 1;
      set_light(1);
      short_desc = "The Commons";
      long_desc =
"Welcome to the safest place on the IIT campus.  This is the commons\n"+
"area, where everything you need is available at an intensly inflated\n"+
"price.  You see about half the chicago police force sitting around eating\n"+
"doughnuts and drinking coffee.  North of here is the campus 7-11.\n"+
"West takes you to State street.\n";
      
      
      dest_dir = ( {
            "players/lew/newbie/enter","northwest",
            "players/lew/state_st", "southeast",
            });
   }
   
}

/*  added meal card to this room 3/29/97  Eurale  */
init() {
  ::init();
  add_action("search","search");
}

search(str) {
if(!str) { write("Search what?\n"); return 1; }
if(str == "commons" && C == 1) {
  write("You search under the tables and chairs of the commons area\n"+
	"and find a meal ticket.\n");
  move_object(clone_object("players/lew/card1.c"),this_player());
  C = 0;
  return 1; }
else {
  write("You search under the tables and chairs and find nothing.\n");
  return 1; }
}
