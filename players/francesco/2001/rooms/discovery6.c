#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

set_light(1);
if (!present("hal")) {
  move_object(clone_object("/players/francesco/2001/mobs/hal.c"),
	this_object());  }

short_desc = "Discovery" ;
long_desc =
       "   DISCOVERY SPACECRAFT,  1,000,000 MILES FROM EARTH\n"+
       "The computer room of the Discovery is very ample and well lighted.\n"+
       "It has a rectangular shape and contains some consoles. Over the\n"+
       "consoles there are some monitors with their respective keyboards, \n"+
       "and a a couple of printers.\n",

items = ({
   "consoles","They look some metallic desks, each about 3 feet tall and 5 feet wide",
   "monitors", "The monitors have old, small, 12 inch, black and white screens",
   "keyboards","They are used to input the data into the computers",
   "printers","They are used to write the data on a sheet of paper",
});

dest_dir = ({
  "/players/francesco/2001/rooms/discovery21.c","east",
  "/players/francesco/2001/rooms/discovery18.c","southwest",
});

}

init(){
      ::init();
      add_action("kill","kill");
      add_action("remove","remove");
      }

kill() {write("Ehh?  Kill a computer?\n");return 1;}

remove(str) {
   object ob;
   if(!str) {write("Remove what?\n"); return 1;}
   if (str!="card") {write("Remove What\n"); return 1;}
        ob = present("hal", environment(this_player())); 
       if(!ob) return 1; 
       write("You start removing the memory card off the computer.\n");
       ob->attack_object(this_player());
   return 1; }
