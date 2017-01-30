#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
if(!present("blade"))  {
move_object(clone_object("/players/saber/closed/new_mini/agents/blade.c"),this_object());
        }
if(!present("merchant"))  {
move_object(clone_object("/players/saber/food/gemshop.c"),this_object());
       }
 if(!arg){
  set_light(1);
short_desc="Market Square";
long_desc=
 "*Luna Vista       (North/South)\n"+
 "*Merchant Street  (West/East)\n"+
 "You stand amidst the noise and confusion of the market square.  Around you\n"+
 "sound the voices of merchants, street venders and wandering minstrels,\n"+
 "while in the background you hear the whispers of the people passing by.\n"+
 "The square is lit both by flickering torchlight and the luminous full moon\n"+
 "which looms above.\n";

items=({
 "street","The streets are made from dark stone",
  "city","The city of Ryllian",
 "streets","The city streets are made from dark stone",
 "ocean","You cannot see that from here",
 "tower","The Mages tower rises to the west.\n"+
   "The Tower of Heros rises to the east",
 "square","You stand in the area known as 'Market Square'",
 "moon","A luminous full moon looms above",
 });

  dest_dir=({
 "/players/saber/ryllian/ms4.c","north",
 "/players/saber/ryllian/ms8.c","east",
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
