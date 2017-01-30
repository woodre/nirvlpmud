inherit "room/room";
#include <ansi.h>
#define tp this_player()->query_name()

reset(arg){
move_object(clone_object("/players/daranath/mons/otyugh.c"),this_object());
    if(!arg){

    set_light(1);
short_desc= (BOLD+"DarkenWood"+NORM+" (Kobold Village)");
    long_desc=
  "The kobold trash dump spreads out before you in a display of filth\n"+
  "and disease. Piles of trash and waste product are all about, eminating\n"+
  "a strong stench and fills the area.\n";

items=({
  "woods", "The Darkenwood is a place of horrors and humanoids, both of\n"+
           "which give it its reputation for nightmares.\n",
 });


dest_dir=({
 "/players/daranath/clearing/kobold5.c","village",
           });
        }
        }

init(){
  ::init();
  add_action("search","search");
}

search() {
write("Would you really like to search the trash from the kobold village???.\n");
say (tp +" searches the area.\n");
  return 1;
}

