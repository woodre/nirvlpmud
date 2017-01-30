inherit "room/room";
 
reset(arg){
 
if(!present("snowflake")) {
move_object(clone_object("/players/snow/MONSTERS/snowflake.c"),this_object());
                 }
if(!present("snowflake 2")) {
move_object(clone_object("/players/snow/MONSTERS/snowflake.c"),this_object());
                }
 
 if(!arg){
 
set_light(1);
  short_desc="A field of snow";
 long_desc=
"You find yourself walking through a snow-covered field. The sun is shining\n"+
"brightly overhead and all seems peaceful. There are a few lively snowflakes\n"+
"fluttering around.\n";
 
items=({
 "field", "A field covered with a dusting of freshly fallen snow",
 "sun", "The sun is shining brightly overhead, lending an air of comfort\n"+
        "to the area. You feel comfortably warm even in the snow",
 "snowflakes", "Shining snowflakes drift in the breeze. Some seem to be \n"+
               "very lively",
           });
 
  dest_dir=({
  "/players/snow/newbie/newbie+1.c","east",
  "/players/snow/newbie/newbie+2.c","north",
  "/players/snow/newbie/newbie+3.c","west",
  "room/plane10","leave",
});
  }   }
 
init()  {
 ::init();
  add_action("search_room","search");
         }
 
search_room() {
  write("You search through the room but find nothing of value.\n");
say (this_player()->query_name() +" searches the field but finds nothing.\n");
  return 1;         }
