#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
if(!present("succubus"))  {
move_object(clone_object("/players/saber/closed/new_mini/agents/succubus.c"),this_object());  }
  set_light(1);
short_desc="City of Ryllian";
long_desc=
 "*The Torchlit Highway   (North/South)\n"+
 "*Cobblestone Lane       (West)\n"+
 "You stand in the city of Ryllian, at the intersection of The Torchlit Highway\n"+
 "and Cobblestone Lane.  To the north is Market Square.  South lies the\n"+
 "Waterfront and the docks.  To the west are the slums of Ryllian.  The streets\n"+
 "are illuminated by chaotically flickering torches that dance to the tune of\n"+
 "the the cold sea breezes winding from the ocean to the south.\n";

items=({
 "torch","A magical torch of eternal fire\n"+
      "It is flickering in the sea breeze",
 "street","The streets are made from dark stone",
  "city","The city of Ryllian",
 "streets","The city streets are made from dark stone",
 "ocean","The ocean lies to the south",
 "tower","The Mages tower rises to the northwest.\n"+
   "The Tower of Heros rises to the northeast",
 "slums","The slums lie to the west",
 "market square","Market Square lies to the north",
 "docks","The docks lie to the south.  You see two massive ships there",
 });

  dest_dir=({
 "/players/saber/ryllian/ms8.c","north",
 "/players/saber/ryllian/wf2.c","south",
 "/players/saber/ryllian/slums4.c","west",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
  add_action("south","south");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

south()  {
write("The waterfront is currently under construction.\n"+
    "We're sorry for the delay.\n");
  return 1;
        }
