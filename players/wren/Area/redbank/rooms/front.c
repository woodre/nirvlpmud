	/* Out in front of QuickStop and RST Video. Usual hooligans. Jay and Bob  */
	/* Entry to heal shop and Dante and Randall. Should be entertaining place */
        /* to get heals. Hoping atmosphere will draw them over other shops of the */
        /* kind.*/

#include "/players/wren/ansi.h"; 
inherit "room/room";

reset(arg)  {
   if(arg) 
      return ;

   if(!present("jay_npc")) {
      move_object(clone_object("/players/wren/Area/redbank/npc/jay.c"),this_object()); }
   if(!present("bob_npc")) {
      move_object(clone_object("/players/wren/Area/redbank/npc/bob.c"),this_object()); }

   set_light(1);
   short_desc = "In front of the "+RED+"Quick"+NORM+GRN+"Stop"+NORM+" & "+HIK+"RST"+NORM+" Video ";
   long_desc = 
"                 "+RED+"Quick"+GRN+"Stop"+NORM+" and "+HIK+"RST"+NORM+" Video                  \n\
\n\
Well situated in the heart of beautiful Red Bank, New Jersey.   \n\
This must be a very busy place to work. You see customers       \n\
popping in and out every few minutes. The shutters over the     \n\
windows are stuck down and someone has hung a white sheet out   \n\
to show they are open for business. You notice people loitering \n\
in front of both stores. Those in front of the video store seem \n\
angry that its locked and according to the hours shouldn't be.  \n\
The two in front of the "+RED+"Quick"+GRN+"Stop"+NORM+" somehow \n\
look like it is where they are meant to be. While you are here  \n\
you might as well get a cup of coffee or something if you can   \n\
get past the customers.              \n";

  items=({		/*Remember two deep on noun descriptions*/
     "quickstop","A small convenience store without gas pumps and with stuck metal shutters",
     "rst video","Owned jointly with the Quickstop, RST occasionly serves the public if Randall feels like it",
     "shutters","You notice that somebody has stuck gum in the locks so they can't be opened",
     "shutter","Metal screens that are pulled down to protect the windows from vandals",
     "red bank","A small town in New Jersey the home of several interesting characters and shops",
     "customers","A wide variety of people stop to buy a wide variety of small things",
     "customer","An angry looking young lady stares in the window of the video shop",
     "windows","It is probably a safe bet there are windows under those metal shutters",
     "window","A small window on the door that allows some natural light in",
     "sheet","The letters spell out 'Yes, I Assure You We're OPEN' ",
     "letters","Is that shoe polish you smell",
     "people","Customers and other folk that have nothing to do",
     "two","Its Jay and Silent Bob, wonder what they are up to",
     "video store","The small video store next to QuickStop with less selection then BigChoice",
     "hours","9-5 Weekdays, 10-10 Weekends. No Holidays. Be kind rewind",
     "door","The single door leading into the QuickStop is covered in signs",
     "doors","The QuickStop is unlocked, RST Video clearly isn't",
     "signs","New Jersey Lottery, Marlboro sold here, Coffee, No Checks, store hours",
     "store","Which store are you looking at?"
             });

      dest_dir = ({
          "/players/wren/Area/redbank/rooms/inside.c","enter",
          "/players/wren/Area/entrance.c","megalith" 
                 }); 
}

init() {
  ::init();
  add_action("search_room","search");
    
if(present("jay")) {
    add_action("cmd_ask","ask");
    add_action("cmd_ask","list");
    add_action("cmd_buy","buy");
    add_action("cmd_buy","purchase");
                      }
          }

  search_room()  {
        write("You search but don't see anything worth taking.\n");
        say (this_player()->query_name() +" searches the area. \n");
        return 1;
                 }

cmd_ask(str) {
    if(str !="jay") {
          write("Ask who, what?\n");
          return 1;
             }
    if(!present("jay")) {
          write("You can't buy from someone who isn't here.\n");
          return 1;
             }    

    write(" \n");
    write("  Dante yells out: 'I thought I told you not to deal out here!'\n");
    write("  Jay says: 'I'm not.'\n");
    write("  You subtly ask Jay what he's dealing. \n");
    write("  Jay says: 'Watchou need?' \n");
    write(" \n");
    write("       Jay has some stuff for sale. He's got some ok weed he'll sell \n");
    write("       for 250 for a 'joint' or 750 for a 'big_joint'.  \n");
    return 1;
     }

cmd_buy(str) {
     object ob;
     string file;
     int value;

     if(!present("jay")) {
         write("Jay isn't here to sell anything, maybe he's at the mall. \n");
         return 1;
                 }
     if(!present("bob")) {
         write("Bob isn't here and he was carrying the stuff for Jay. Wonder where he is.\n");
         return 1;
                 }

     if(!str) {
         write("Jay says: 'I don't think I have that. What do you want?'\n");
         return 1;
              }
     switch(str) {
         case "joint":
             value=250;
             file="/players/wren/Area/redbank/items/joint.c";
             break;
         case "big_joint": 
             value=750;
             file="/players/wren/Area/redbank/items/big_joint.c";
             break;
                 }
     if(this_player()->query_money() < value)  {
            write("Jay says: 'I don't give credit, come back when you got the cash. Snoogins.'\n");
            return 1;
                   }
     if(file) {
          ob=clone_object(file);
          if(!this_player()->add_weight(ob->query_weight() )) {
             destruct(ob);
             return 1;
              }
          this_player()->add_money(-value);
          move_object(ob,this_player());
          write("You buy a "+ob->short()+" for "+value+" coins. \n");
          write("Jay punches Bob in the shoulder. Bob produces the weed from \n");
          write("within his coat and hands it to you. Bob squints at Jay. \n");
          write("Jay says: 'Naganootch, yo'\n");
          say(this_player()->query_name()+" buys "+ob->short()+".\n");
          return 1;
  }
}
