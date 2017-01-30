inherit "room/room";
#define tp this_player()->query_name()

reset(arg){

    if(!arg){
move_object(clone_object("/players/daranath/guild/obj/misc/grave_obj.c"),this_object());
    set_light(1);
    short_desc="Kobold Graveyard";
    long_desc=
  "Set in a large clearing within the DarkenWood, the kobold village\n"+
  "extends south and west from here. Small mud and straw huts dot the\n"+
  "clearing, the bulk of which are much too small for you to enter. A\n"+
  "large stockade wall rises up above the huts, a large wooden gate set\n"+
  "into its front.\n";

items=({
  "shadows", "The shadows move as the wind moves the trees.\n",
  "gate", "The gate within the stockade wall leads into the keep",
  "wall", "A large stockade fence stands to the west",
  "huts", "The crude huts are not what you would consider luxury",
  "mud", "The mud is common to this area",
  "straw", "Its straw, you know.....   straw",
  "village", "The kobold village is a staging point for kobold invasions\n"+
             "all about Nirvana",
 });


dest_dir=({
 "/players/daranath/clearing/kobold3.c","south",
           });
        }
        }

init(){
  ::init();
  add_action("search","search");
}

search() {
write("You find nothing about the kobold village.\n");
say (tp +" searches the area.\n");
  return 1;
}

