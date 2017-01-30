 inherit "room/room";
  reset(arg){
   if(!present("scribe")) {
 move_object(clone_object("/players/arrina/monsters/talker1.c"),this_object());
 }
    if(!arg){
 
    set_light(1);
    short_desc=("Crystal Garden");
    long_desc=
    "This botanical garden contains a wide array of colorful flowers,\n"
 +  "and is ringed by trees which provide shade.  Surrounding the \n"
 +  "garden on three sides is a glimmering lake.  In the center of\n"
 +  "the garden is a group of crystal rosebushes that sparkle in\n"
 +  "the sun like the surrounding water.  The roses are not to be\n"
 +  "found anywhere else in Nirvana.  A large clearing covered with\n"
 +  "pine needles appears to be a perfect spot for a wedding.\n"
 +  "A path to the north leads to Nirvana's churchyard.\n";
    items=
   ({
     "roses","The crystal roses belong in the hands of a cherished one",
     "garden","The garden transfixes your heart with it's rare beauty",
     "trees","The trees are damn tall",
     "lake","The lake encompasses the garden like the warm arms of a lover",
    });
    dest_dir=
    ({
    "/room/church.c","north",
     });
   }}
  init()  {
  ::init();
   add_action("search_room","search");
         }
  search_room() {
   write("You search through the room but find nothing.\n");
 say (this_player()->query_name() +" searches the room but finds nothing.\n");
   return 1;         }
