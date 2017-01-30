#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("receptionist")) {
  move_object(clone_object("/players/francesco/univ/mob/receptionist2.c"),
	this_object()); }
set_light(1);

short_desc = "University info center";
long_desc =
     "    In this room you see a counter where a receptionist can stand\n"+
   "in order to supply the visitors with the info they might need.\n"+
   "A lateral shelf holds some papers and flyers in well ordered lines\n"+
   "above it.  If you need any info you can either get any of them or\n"+
   "ask the receptionist when she is present (Work time 9am-5pm).\n";
items = ({
   "flyers","These flyers are relative to the various areas of the\n"+
            "University and can show you the locations of the\n"+
            "Departments, of the classrooms and of the main facilities",
   "shelf","The shelf is made by light metal and is very resistant",
   "papers","Each of them shows the details of every single area\n"+
            "reported in the fliers",
   "counter","About 3 feet tall and 10 feet wide, made of gray plastic",

});




dest_dir = ({
  "/players/francesco/univ/rooms/booth","east",
});

}

init(){
      ::init();
       add_action("ask","ask");
      }

ask(str) {
         if(str!="receptionist") 
            { 
            write ("Ask whom?\n");
            return 1;
            }
         if(!present("receptionist",this_object()))
            {
            write("The receptionist is not present.\n");
            return 1;
            } 
         write ("The receptionist says: Here it is a rough map of the University.\n"+
                "                           \n"+
                "   YOU ARE HERE         Department of Mechanical Engineering\n"+
                "        X                               |\n"+
                "    info center        classroom        |\n"+
                "        |                  |            |\n"+
                "   main entrance --------------------------- commons\n"+
                "        |                  |            |  \n"+
                "        |              classroom    restrooms \n"+
                "      exit\n"+
		"				 (last updated: 20.11.1999)\n\n");
         return 1;
         }

