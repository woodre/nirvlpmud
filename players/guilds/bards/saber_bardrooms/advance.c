#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
if(!present("water"))  {
move_object(clone_object("/players/saber/closed/bards/fountain.c"),this_object());  }
if(!present("star"))  {
move_object(clone_object("/players/saber/closed/bards/star.c"),this_object());
        }
 if(!arg){
  set_light(1);
short_desc="Bard Training Chamber";
long_desc=
 "This is an empty room.  You think it could use a little work.\n";

items=({
 "floor","The floor is made from a beautiful mahogany wood",
 });

  dest_dir=({
 "/players/saber/closed/bards/bardrooms/teleport.c","east",
 "/players/saber/closed/bards/bardrooms/lore.c","south",
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
