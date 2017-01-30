#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("receptionist")) {
  move_object(clone_object("/players/francesco/univ/mob/receptionist.c"),
	this_object()); }
set_light(1);

short_desc = "Academic info center";
long_desc =
   "    In this room you see a counter where a receptionist can stand\n"+
   "in order to supply the visitors with the info they might need.\n"+
   "A lateral shelf holds some papers and flyers in well ordered lines\n"+
   "above it.  If you need any info you can either get any of them or\n"+
   "ask the receptionist when she is present (Work time 9am-5pm).\n";

items = ({
   "flyers","These flyers are relative to the various classes you \n"+
            "might take and the various degrees you can obtain from\n"+
            "this University",
   "shelf","The shelf is made by light metal and is very resistant",
   "papers","Each of them shows the details of every single course\n"+
            "reported in the fliers",
   "counter","About 3 feet tall and 10 feet wide, made of gray plastic",
});


dest_dir = ({
  "/players/francesco/univ/rooms/booth.c","west",
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
            write("The receptionist is not present\n");
            return 1;
            } 
     write ("The receptionist says: we actually offer courses in Mechanical\n"+
            "Engineering, at all levels:  Bachelor, Master and PhD as well.\n"+
            "Our research activities are in the following fields:  Design\n"+
            "of Machines,  Engines,  Manufacturing and Fluid dynamics.  Our\n"+
            "staff consists of four professors, seven technicians, four\n"+
            "administrative clerks and a number of Master and PhD students.\n"+
            "For more info about the courses, you might want to go to the\n"+
            "study plans office.  Thank you.\n");
     return 1;
         }

