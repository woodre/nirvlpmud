#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
 if(!arg){

set_light(1);
short_desc = "The Church of Larn";
long_desc=
 "You stand in the chamber of knowledge.  It is\n"+
 "here that the priests of Larn come to research\n"+
 "new spells and preserve knowledge.  If you are\n"+
 "of the priesthood, you can <ask> about scrolls\n"+
 "which can be found here.\n";

items=({
 "chamber","You are in the chamber of knowledge",
 "scrolls","Scrolls are stacked high in the shelves which line the walls",
 "ground","The ground is carved from smooth stone",
 });

dest_dir=({
 "/players/saber/closed/quest/larn/larn8.c","east",
 "/players/saber/closed/quest/larn/larn4.c","south",
           });
  }   }

init(){
 ::init();
  add_action("search","search");
  add_action("ask","ask");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

ask()  {
write("This function not yet added.\n");
return 1;
        }

realm()  { return "NT"; }
