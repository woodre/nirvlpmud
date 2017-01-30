#define tp this_player()->query_name()
#define ROOT "/players/daranath/outside/"
inherit "room/room";

reset(int arg){
/*
move_object(clone_object(ROOT+"mon/drifter.c"),this_object());
move_object(clone_object(ROOT+"mon/drifter.c"),this_object());
*/
  if(!arg){
    
set_light(1);
short_desc= "Abandoned Qual'tor Outpost";
long_desc=
"Light streams through a variety of gaps and small holes in the wooden walls of\n"+
"this long forgotten building. The interior of the building remains largely\n"+
"intact, with a thick layer of dust covering everything in sight. Tables and\n"+
"bookshelves fill more then half the outpost, while the remaining sections \n"+
"are occupyied by beds and living quarters. A thin wooden ladder leads to\n"+
"a second floor.\n";

items=({
"gap","Gaps and holes have appeared in the walls over the years from neglect",
"gaps","Gaps and holes have appeared in the walls over the years from neglect",
"hole","Gaps and holes have appeared in the walls over the years from neglect",
"holes","Gaps and holes have appeared in the walls over the years from neglect",
"walls","The wooden walls of the small building seem intact, despite the holes",
"wall","The wooden walls of the small building seem intact, despite the holes",
"dust","Yes, dust covers everything in abandoned buildings",
"tables","A variety of tables sit around the room, everything taken from them",
"bookshelves","There are more bookshelves here then you ever expected",
"beds","Enough beds are here for 6 or 8 soldiers to use",
"ladder","A small, wooden wrung ladder leads up to the second floor of the outpost",
    });

    dest_dir=({
  ROOT+"post_enter.c","exit",
  ROOT+"post2.c","up",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search(){
write("Nothing has been disturbed in here for years. Thick dust covers all.\n");
  say(tp +" searches the area.\n");
 return 1;
}

