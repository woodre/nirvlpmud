#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("silent")) {move_object(clone_object("/players/francesco/masterquest/silent.c"),this_object()); }
if (!present("mastermind")) {move_object(clone_object("/players/francesco/masterquest/mastermind4quest.c"),this_object()); }

set_light(1);

long_desc =
 "   The machining lab is a rectangular area of about 50 by 30 feet.\n"+
 "There are a lathe, a milling machine, an EDM machine and a drill\n"+
 "press.  Several students run back and forth and with the aid of \n"+
 "technicians work for their thesis and finals.  On a side table there\n"+
 "is a mastermind game.  It helps people to keep their brain trained \n"+
 "and in good efficiency. Some metallic shelves lie along the walls.\n",

items = ({
     "shelves","The metallic shelves are very simple and robust to hold several tools",
     "tools","Twist drills, toolholders for turning, mills, grinding wheels,\n"+
             "all catalogues and in well order",
     "twist drills","The tools used for making holes",
     "press","The machine used to make holes",
     "drill press","The machine used to make holes",
     "drills","The tools used for making holes",
     "wheels","Abrasive wheels, made by a cement and abrasive grains",
     "mills","The tools used for planing and for contouring",
     "students","They seem very busy and concentrated on their work",
     "technicians","They are wearing overalls",
     "table","A small desk with a chair in front of it",
     "chair","The chair seems confortable",
     "overalls","Blue dresses, ample and comfortable",
   "lathe","Horizonthal lathe for machining mainly axysimmetric items",
  "milling","It can produce differently shaped surfaces by interaction of a rotating\n"+
            "tool with the material",
  "milling machine","It can produce differently shaped surfaces by interaction of a rotating\n"+
            "tool with the material",
  "grinder","It works with grinding wheels rotating at high speed. By means of\n"+
            "suitable abrasives it is possible to attain very low roughness",
  "edm","Electrical Discharge Machine, the sparks between the tool and the work\n"+
        "remove the material. It can machine very hard materials",
  "EDM","Electrical Discharge Machine, the sparks between the tool and the work\n"+
        "remove the material. It can machine very hard materials",
  "walls","They seem to be painted recently",
});


dest_dir = ({
    "/players/francesco/masterquest/lab.c","exit" 
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

short() {return ""+"Machining lab";}  

