#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int x, play;
string dummy;

reset(arg) {
  if(arg) return;
if (!present("usher")) {
  move_object(clone_object("/players/francesco/2001/mobs/usher.c"),
	this_object());  }
if (!present("flier")) {
  move_object(clone_object("/players/francesco/2001/items/flier_2001.c"),this_object());}

set_light(1);

short_desc = "The lobby of the cinema" ;
long_desc =
     "   The lobby of the cinema is a round room with several passageways.\n"+
     "Each of them lead to a different show.  The walls are adorned with\n"+
     "red velvet curtains and the floor is covered by soft carpets.  An\n"+
     "enormous chandelier hangs down from the ceiling and softly lights\n"+
     "the lobby.  A sign is suspended on a stand.\n",

items = ({
   "lobby","The lobby is rather large", 
   "passageways","Made by curtains, they separate the lobby from the movie theaters",
   "walls","They are covered with red velvet curtains",
   "floor","Walking over it doesnt return any sound",
   "carpets","They are decorated with persian paintings",
   "curtains","They look very heavy and soft",
   "chandelier","It is made by about fifty weak bulbs, it returns a soft light",
   "ceiling","It is about twenty feet high",
   "sign","A large black board which you could read",
   "stand","It has three legs and holds a sign",
});

dest_dir = ({
  "/players/francesco/2001/rooms/lobby.c","enter",
  "/players/francesco/univ/rooms/bar2.c","exit",
});

}

init(){
      ::init();
      add_action("read","read");
      add_action("show","show");
      add_action("enter","enter");
      }

read(str){
   if(str=="board")
    {write("Today movies are:\n\n"+HIW+
           "                    2001 A Space Odyssey"+NORM+"    (show ticket for 2001)\n");
    return 1;}
  notify_fail("Read what?\n");
  return 0;
}

show(str){
   object item;
   if(str=="ticket for 2001")
     {if(!present("ticket",this_player())) {
       write("The usher tells you:  You must purchase the ticket in advance.\n");
       return 1;}
     write("The usher takes the ticket and examines it, then he cuts it\n"+
           "half away and with a smile returns it to you,  sliding the\n"+
           "curtain to let you enter the theater hall.\n");
     this_player()->move_player("into theater hall#players/francesco/2001/rooms/cinema1.c");
     write_file("/players/francesco/log/enter_cinema",
        ctime(time())+"  2001 Space Odyssey  "+tpn+
           " ["+tp->query_level()+"+"+tp->query_extra_level()+"]\n"); 
     destruct(present("ticket",this_player()));
     item = clone_object("players/francesco/2001/items/half_ticket.c");
     move_object(item,this_player());
     return 1;}
  write("Show what?\n");
  return 1;
} 


enter(str){
   object item;
   if(str=="theater")
     {if(!present("ticket",this_player())) {
       write("The usher tells you:  You must purchase the ticket in advance.\n");
       return 1;}
     write("The usher asks you:  May i see your ticket first, please?\n");
     return 1;}
  write("Enter what?\n");
  return 1;
} 


query_no_fight() {return 1;}
