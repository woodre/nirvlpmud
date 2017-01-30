#define ROOT "/players/daranath/qualtor/newstuff/"
#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";
   int a;

reset(int arg){
a = random(4);
if(!present("gsite_ob")){
move_object(clone_object("/players/daranath/guild/obj/misc/gsite_ob.c"),this_object());
}
if(!present("storm")) {
move_object(clone_object(ROOT+"mon/gravestorm.c"),this_object()); 
}
if(a == 0) {
move_object(clone_object(ROOT+"mon/morgue_toad.c"),this_object());
}
if(a == 1) {
move_object(clone_object(ROOT+"mon/frightcrawler.c"),this_object());
}
if(a == 2) {
move_object(clone_object(ROOT+"mon/morgue_toad.c"),this_object());
move_object(clone_object(ROOT+"mon/frightcrawler.c"),this_object());
}
  if(!arg){

    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+BLK+BOLD+"Dark Graveyard"+NORM+")");
    long_desc=
     "Tombstones and open graves litter the ground here, marking the\n"+
     "many heroes that once defended the great city of Qual'tor. Many\n"+
     "of the graves have been opened, the bodies within taken from\n"+
     "their eternal slumber. A dark doorway leads north from the old\n"+
     "graveyard, the smell of death seeping out from its opening.\n"+
     "The only exit is back down the pathway.\n";

    items=({
     "doorway","The doorway leads into a very dark area.\n"+
           "perhaps you could <enter> it",
     "tomb","The various tombs are in disarray",
     "tombs","The various tombs are in disarray",
     "graves","Several of the graves have been dug up and opened,\n"+
         "you cannot fathom why",
     "graveyard","The graveyard is all about you, many of its graves\n"+
         "and tombs lying open",
     "bodies","No bodies are currently lying about the area",
     "pathway","The pathway heads west from the graveyard, skimming\n"+
          "alongside the ruined keep",
    });

    dest_dir=({
"/players/daranath/qualtor/necro_path5.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    add_action("enter","enter");
    }

search(){
write("Many small bits of skin and bone lie scattered about the area,\n"+
      "none of which are large enough to amount to anything.\n"+
      "Nothing else of interest is within the graveyard.\n");
say(tp +" searches the area.\n");
 return 1;
}

enter() {
  /* added by wocket to close necro guild hall entrance 5/27/02 */
    write("The doorway has collapsed blocking any entrance through it.\n");
    write("(The necroguild hall entrance has moved to the dryant graveyard)\n");
    return 1;
  if(!present("necro_ob",this_player())) {
write("You do not have the proper control over the powers of darkness.\n"+
      "The doorway is not for you....\n");
return 1; } else {
this_player()->move_player("through the dark doorway#/players/daranath/qualtor/necro_entry.c");
write("You enter the sacred necromantic stronghold.\n");
return 1; }
}

gravesite() {return "yes"; }

