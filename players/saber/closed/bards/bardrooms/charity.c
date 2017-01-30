#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  set_light(1);
short_desc="Bard Charity Room";
long_desc=
 "This is the charity room of the Bards, where you may leave items for those\n"+
 "in need.  Please do not take stuff from here unless you really need it.\n";

items=({
 "floor","The floor is made from a beautiful mahogany wood",
 });

  dest_dir=({
 "/players/saber/closed/bards/bardrooms/common.c","west",
           });
  }   }
init(){
 ::init();
if(!present("instrument",this_player()) &&
   this_player()->is_player())  {
  write("You get the brief image of a blue circle before\n"+
     "\n"+
    " * * * * *  B O O M  * * * * *\n"+
    "\nYour body flies through space.\nYou find yourself somewhere new.\n");
  say(tp+" bounces off the Circle of Warding.\n");
  move_object(this_player(),"/room/void");
  tell_room(environment(this_player()), tp+" falls screaming from the sky.\n"+
      "THUD.\n");
  return 1;
        }
  add_action("search","search");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }


realm()  { return "NT"; }
