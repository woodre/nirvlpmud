#define tp this_player()->query_name()
#define ROOT "/players/daranath/outside/"
inherit "room/room";

reset(int arg){
  if(!arg){
    
set_light(1);
short_desc= "Abandoned Qual'tor Outpost";
long_desc=
"The second floor of the outpost was once used as a small research station\n"+
"for Qual'tor. This level is almost prefectly intact when compared to the first\n"+
"floor. Row upon row of books lines the shelves here, while the ladder\n"+
"heads to the roof\n";

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
  ROOT+"post3.c","up",
  ROOT+"post1.c","down",
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

