inherit"/room/room";
int i;
id(str) {return str == "room";}
short() { return "Tunnel [w,e]";}
long() {write("Here you can begin to hear sounds.  Sounds almost like singing?  You can\n"+
              "see nothing out of the ordinary.  This would be a great place for an ambush.\n"+
              "Maybe you sould move on instead of standing here listening.\n"+
              "    There are two obvious exits:  west and east\n");}

reset(arg) {
monster();
  set_light(1);
} 

monster() {
int count;
object monster;
if(!present("priestess"))
move_object(clone_object("/players/mouzar/castle/under/mon/pdrow"),this_object());
if(!present("guard")) {
while(i<2) {
  monster = clone_object("/players/mouzar/castle/under/mon/gdrow");
  move_object(monster, this_object());
i++;
}
i=0;
}
}
init() {
  add_action("west","west");
  add_action("east","east");
::init();
}

east() {
  this_player()->move_player("east#/players/mouzar/castle/under/under33");
  return 1;
}

west() {
  if(!present("drow")) {
    this_player()->move_player("west#/players/mouzar/castle/under/under31");
    return 1;
  } 
  write("The drow maneuvers to block your path!\n");
  say("A drow maneuvers to block "+capitalize(this_player()->query_name())+"'s path!\n");
  return 1;
} 

