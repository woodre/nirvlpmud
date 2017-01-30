#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("silent")) {move_object(clone_object("/players/francesco/masterquest/silent.c"),this_object()); }
if (!present("mastermind")) {move_object(clone_object("/players/francesco/masterquest/mastermindcolquest.c"),this_object()); }

set_light(1);

long_desc =
 "   The foundry is a square area of about 40 by 40 feet.  On the\n"+
 "left side a furnace can be seen.  On the other side, some dies\n"+
 "are scattered about, in the middle of some scrap iron coming\n"+
 "from previous castings.  Some students run back and forth and \n"+
 "with the aid of technicians work for their thesis and finals.  \n"+
 "On a side table there is a mastermind game.  It helps people \n"+
 "to keep their brain trained and in good efficiency. Some metallic \n"+
 "shelves lie along the walls.\n",

items = ({
     "shelves","The metallic shelves are very simple and robust to hold several tools",
     "students","They seem very busy and concentrated on their work",
     "technicians","They are wearing overalls",
     "table","A small desk with a chair in front of it",
     "chair","The chair seems confortable",
     "overalls","Blue dresses, ample and comfortable",
     "furnace","A cubic box, 10 by 10 by 10 feet wide",
     "dies","The containers where the castings are poured",
     "castings","Melt metal, at high temperature",
     "scrap iron","The residuals of previous castings",
     "scrap","The residuals of previous castings",
     "iron","The residuals of previous castings",
     "walls","They seem to be painted recently",
});


dest_dir = ({
    "/players/francesco/masterquest/lab.c","exit",
});
}


init() {
  ::init();
  add_action("exit_to","exit");
}

exit_to() {
   if(!present("student_fran")) this_player()->move_player(".#players/francesco/masterquest/lab.c");
   else
   write("The student steps ahead of you and says:\n"+
         "'You stole Fran's computer userid, I wont let you go!\n");
return 1;}

realm(){ return "NT"; }

short() {return ""+"Foundry lab";}  

