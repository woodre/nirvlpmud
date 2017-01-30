inherit "room/room";
int opened; 
reset(arg) {
  if(arg) return;
  set_light(1);
  long_desc = 
"  You are walking along the Main Road of Trixtown.  To the north and the\n"+
"south you can see TrixTown 1st Street which crosses Main Road right where\n"+
"you are at this moment.  To the west you can see a green and woody hill.\n"+
"A manhole.\n";
   short_desc = "Trixtown Main Road";
   dest_dir = ({ "/players/trix/castle/town/1str1n.c", "north",
                 "/players/trix/castle/town/1str1s.c", "south",
                 "/players/trix/castle/town/mainroad4.c", "west",
                 "/players/trix/castle/town/trixplaza.c", "east"});
    items = ({ "manhole", "This is a manhole, plugged with a heavy ironmade cover on which you can see\n"+
                          "the sign \"City of Trixtown-Sewer and Drainage system Department\"" });
    opened=0;
}
init(){
 ::init();
     add_action("open","open");
     add_action("enter","enter");
}
open(str)
{ object cover;
  if(str!="manhole") { write("Open what?\n"); return 1; }
  if(opened) { write("The manhole is already open!\n"); return 1;}
  cover=present("trixhook",this_player());
  if(!cover) { write("The cover is too heavy to be lifted up without the adequate tool!!!\n"); return 1; }
  opened=1;
  write("You open the manhole, lifting the heavy cover up with your hook.\n");
  items = ({ "manhole", "An open manhole right in the middle of the road, maybe you could enter it"}); 
  return 1;
}
enter(str)
{   if(str!="manhole") { write("Enter what?\n"); return 1; }
    if(!opened) { write("You can't enter the manhole, it's closed with a heavy iron cover.\n"); return 1; }
    write("You enter the manhole and go down into the semidark Trixtown Sewer.\n");
    this_player()->move_player("enter#"+"/players/trix/castle/quest/sed6");
    return 1;
}
