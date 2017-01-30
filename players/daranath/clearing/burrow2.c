inherit "room/room";

reset(arg){
move_object(clone_object("/players/daranath/mons/jethro.c"),this_object());
    if(!arg){

    set_light(1);
    short_desc="Jethro's Burrow";
    long_desc=
  "This room within the burrow is much different then the other in the hill.\n"+
  "A warlike setting is about you, a large steel table centered in the room.\n"+
  "Maps and posting are hanging all about the wooden walls, marking various\n"+
  "territories and areas within the whole of Nirvana. The largest map of\n"+
  "them all is lying open upon the table, as if it was being examined last.\n"+
  "The only obvious way out from here is back to the cluttered room that you\n"+
  "just came from.\n";

items=({
  "table", "A large steel table that is centered within the room, this\n"+
           "looks as if it is used to plan intrusions upon the varied areas\n"+
           "of Nirvana. A large map is laid out upon the table",
  "map", "The map upon the table looks to be of a large underground area.\n"+
         "A scratchy writing upon the top of it proclaims that it is called\n"+
         "the UnderDark. You wonder what that is. Perhaps you should ask\n"+
         "someone",
  "walls", "The walls are wooden in nature and have large drawings and maps\n"+
           "of Nirvana hanging about them",
  "floor", "The floor is dirt and cold to the touch",
 });


dest_dir=({
 "/players/daranath/clearing/burrow1.c","back",
           });
        }
        }
