#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  set_light(1);
short_desc="City of Ryllian";
long_desc=
 "*The Torchlit Highway  (North/South)\n"+
 "*Avenue of Colors      (West/East)\n"+
 "You stand in the city of Ryllian.  Glancing about, you see that the city\n"+
 "streets are illuminated by chaotically flickering torches that dance to the\n"+
 "tune of the the cold sea breezes winding from the ocean to the south.  The\n"+
 "Torchlit Highway runs south to Market Square, where the sounds of an active\n"+
 "city night life can be heard.  To the west the Avenue of Colors runs towards\n"+
 "the Mages tower, the Church of Larn and the Embassy House.  To the east the\n"+
 "Avenue of Colors runs to the Library and the Tower of Heros.  North is Orin's\n"+
 "Inn and the Gladiator Arena.\n";

items=({
 "torch","A magical torch of eternal fire\n"+
      "It is flickering in the sea breeze",
 "street","The streets are made from dark stone",
 "arena","An imposing looking structure of colossal proportions",
 "inn","A two story building, most likely an Inn",
  "city","The city of Ryllian",
 "streets","The city streets are made from dark stone",
 "ocean","You cannot see that from here",
 "tower","The Mages tower rises to the west.\n"+
   "The Tower of Heros rises to the east",
  "church","The Church of Larn lies to the west",
 "house","The Embassy House lies to the west",
 "library","The library lies to the east",
 });

  dest_dir=({
 "/players/saber/ryllian/ryllian2.c","north",
 "/players/saber/ryllian/ryll6.c","east",
 "/players/saber/ryllian/ms2.c","south",
 "/players/saber/ryllian/ryll4.c","west",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }
