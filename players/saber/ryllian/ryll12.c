#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  set_light(1);
short_desc="City of Ryllian";
long_desc=
 "*Avenue of Valor    (North)\n"+
 "You stand at the end of the Avenue of Valor.  To the north is the Avenue of\n"+
 "Colors, and to the west is the Tower of the Hero.  Both the Avenue and the\n"+
 "Tower appear to be in need repair.  The area is illuminated by a single torch.\n";

items=({
 "torch","A magical torch of eternal fire\n"+
      "It is flickering in the sea breeze",
 "street","The streets are made from dark stone",
  "city","The city of Ryllian",
 "streets","The city streets are made from dark stone",
 "ocean","You cannot see that from here",
 "tower","The Mages tower rises to the west.\n"+
  "The Tower of the Hero looms above you",
 });

  dest_dir=({
 "/players/saber/ryllian/ryll11.c","north",
 "/players/saber/ryllian/hero.c","enter",
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
