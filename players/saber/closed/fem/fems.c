#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
if(!present("victoria"))  {
move_object(clone_object("/players/saber/closed/fem/vic.c"),this_object());  }
if(!present("diary"))  {
move_object(clone_object("/players/saber/closed/fem/fem_news.c"),this_object());  }
if(!present("couch"))  {
move_object(clone_object("/players/saber/fur/couch.c"),this_object());  }
if(!present("fireplace"))  {
move_object(clone_object("/players/saber/fur/fireplace.c"),this_object());  }
 if(!arg){
  set_light(1);
 short_desc = "Victoria's Secret Room";
long_desc=
 "You stand in a large, comfortable chamber, lit by both the warm glow of a\n"+
 "worked stone fireplace and the dim, sparkling rainbow colors of a crystal\n"+
 "teardrop chandelier.  The room has been tastefully decorated in a cream and\n"+
 "forest scheme of satin and lace, with curtains and tapestries covering the\n"+
 "walls and windows.  To the far side of the chamber is a large wooden door.\n";

items=({
 "floor","The floor is made from a beautiful mahogany wood",
 "chamber","You are in Victoria's Secret Room",
 "glow","The chandelier glows with a soft, rainbow light",
 "chandelier","The chandelier glows with a soft, rainbow light",
 "lace","Satin and lace curtains and tapestries fill the room",
 "satin","Satin and lace curtains and tapestries fill the room",
 "door","A door leading back to Nirvana",
 });

  dest_dir=({
 "/players/saber/ryllian/portal.c","door",
           });
  }   }
init(){
 ::init();
  if(this_player()->query_gender() != "female")  {
  if(this_player()->query_level() < 100)  {
  if(!this_player()->is_pet())  {
  write("You get the brief image of a blue circle before\n"+
     "\n"+
    " * * * * *  B O O M  * * * * *\n"+
    "\nYour body flies through space.\nYou find yourself somewhere new.\n");
  say(tp+" bounces off the Circle of Warding.\n");
  move_object(this_player(),"/room/church");
  tell_room(environment(this_player()), tp+" falls screaming from the sky.\n"+
      "THUD.\n");
  return 1;
        }
        }
        }
  add_action("search","search");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

realm()  { return "NT"; }
