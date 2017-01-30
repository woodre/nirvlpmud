inherit "room/room";
#include <ansi.h>
#define tp this_player()->query_name()

reset(arg){
/*
move_object(clone_object("/players/daranath/mons/giant2.c"),this_object());
move_object(clone_object("/players/daranath/mons/giant2.c"),this_object());
*/
    if(!arg){

    set_light(1);
short_desc= (BOLD+"DarkenWood"+NORM+" (Deep Forest)");
    long_desc=
"The darkness seems to lighten here, still deep within the Darkenwood.\n"+
"No light pierces through the trees overhead, but the forest itself thins out\n"+
"to the west where a small grassy clearing seems to stand. A curtain of\n"+
"vines hang to the east, blocking your view.\n";

items=({
  "woods", "The Darkenwood is a place of horrors and humanoids, both of\n"+
           "which give it its reputation for nightmares.\n",
  "trees", "The overgrown trees block all light from coming in.\n",
  "shadows", "The shadows move as the wind moves the trees.\n",
  "floor", "The forest floor is covered with a thick layer of leaves and\n"+
           "other such debris",
/* Added for Druid Guild Hall...   Aug 16th, 2002  -Dar    */
"vines","A curtain of vines hangs thickly from the trees. The vines are positioned\n"+
       "to block your view east, but they do allow you to "+GRN+"<"+HIG+"pass"+NORM+GRN+">"+NORM+" through",
"curtain","A curtain of vines hangs thickly from the trees. The vines are positioned\n"+
       "to block your view east, but they do allow you to "+GRN+"<"+HIG+"pass"+NORM+GRN+">"+NORM+" through",
"vine","A curtain of vines hangs thickly from the trees. The vines are positioned\n"+
       "to block your view east, but they do allow you to "+GRN+"<"+HIG+"pass"+NORM+GRN+">"+NORM+" through",
"clearing","A small grassy clearing sits to the west, and then seems to \n"+
            "run south from there",
"grass","Deep dark green grass grows abundantly within the clearing",
 });


dest_dir=({
 "/players/daranath/clearing/dwood20.c","north",
/*
 "/players/daranath/druid/room/south1.c","west",
*/
           });
        }
        }

init(){
  ::init();
  add_action("search","search");
add_action("enter_guildhall","pass");
}

search() {
/* Changed Aug 17th, 2002   - Dar */
write("A series of footprint, both humanoid and animal in nature, lead into and\n"+
      "back out from the curtain of vines.\n");
say (tp +" searches the area.\n");
  return 1;
}

enter_guildhall() {
object ob;

ob = present("druid_ob",this_player());

if(!ob){
write("The druid guildhall is not yet open...\nThanks   -Daranath\n");
return 1; }
this_player()->move_player("through the vines#players/daranath/druid/room/adv_hall.c");
return 1;
}
