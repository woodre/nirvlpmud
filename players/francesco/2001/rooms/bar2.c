#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("hope")) {
  move_object(clone_object("/players/francesco/univ/mob/bartendernew.c"),
	this_object()); }

if (!present("dispenser")) {
  move_object(clone_object("/players/francesco/univ/items/dispenser.c"),
	this_object());  }
set_light(1);


short_desc = "In Campus Cafeteria" ;
long_desc =
     "    The In Campus Cafeteria is mainly used by the professors and\n"+
     "the staff of the University during breaks from their job.  The \n"+
     "students also like to come here and gather in a relaxed atmosphere.\n"+
     "There arent many tables here to sit around, because the University\n"+
     "management tends to discourage people from lazing around instead\n"+
     "of working.  The bartender works behind the long counter, she is \n"+
     "intent upon serving the people that usually come here and run away \n"+
     "very fast.  She also prepares her own specialties by getting the \n"+
     "ingredients from the shelf which is behind her.  Beware, the bartender\n"+
     "does not work 24/7.\n",

items = ({
         "tables","There are six wood tables aligned one after the other",
         "counter","It is a counter made of wood and shining brass, like in the old style Far West pubs",
         "shelf","It is a tall, wide shelf and can hold dozens of bottles"
});

dest_dir = ({
  "/players/francesco/univ/rooms/corridor3.c","exit",
  "/players/francesco/2001/rooms/lobby.c","enter"
});

}


init() {
    add_action("enter"); add_verb("enter");
}

enter(str) {
    if (str=="cinema")
     {
     if(!present("ticket",this_player()))
       {write("A ticket may be purchased by Hope.\n");
        return 1;}
     write("Welcome, "+call_other(this_player(),"query_name")+".  Now you have the possibility of\n"+
           "watching several movies. Look at the sign for the currently\n"+
           "available ones.\n");
     this_player()->move_player("into the cinema#players/francesco/2001/rooms/lobby.c");
     write_file("/players/francesco/log/enter_cinema",
             ctime(time())+"  "+tpn+
             "    [Level  "+tp->query_level()+"+"+tp->query_extra_level()+"]\n");    
    return 1;    
    }
  notify_fail("Enter what?\n");
  return 0;
}