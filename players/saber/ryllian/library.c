#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  set_light(1);
short_desc="Library of Ryllian";
long_desc=
 "You stand within the great hall of the Library of Ryllian, an institution\n"+
 "renown for its unparalleled collection of books and scrolls.  The library\n"+
 "walls and floor have been constructed from a fine polished white marble.  Dim\n"+
 "magical flameless lanterns hang upon all the walls, and there are scattered\n"+
 "chairs and couches and tables set out for the use of library patrons.\n";

items=({
 "hall","You stand in the great hall of the Library of Ryllian",
 "books","The walls are filled with shelves upon shelves of books",
 "scrolls","The walls are filled with shelves upon shelves of scrolls",
 "walls","The walls have been constructed from a fine polished white marble",
 "wall","The walls have been constructed from a fine polished white marble",
 "floor","The floor has been constructed from a fine polished white marble",
 "lantern","There are many magical flameless lanterns upon the walls",
 "chairs","There are many chairs here.  Perhaps you could <sit chair>",
 "chair","There are many chairs here.  Perhaps you could <sit chair>",
 "tables","There are many tables here for public use",
 "thable","There are many tables here for public use",
 "patrons","There are a few people here looking at various books",
 });

  dest_dir=({
 "/players/saber/ryllian/ryll7.c","out",
 "/players/saber/ryllian/library2.c","east",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
   add_action("sit","sit");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

sit(str)  {
  if(!str)  {
    write("Sit where?\n");
    return 1;
        }
  if(str == "chair")  {
    write("You sit down in a very comfortable chair.\n");
    say(tp+" sits down in one of the library chairs.\n");
    return 1;
        }
  if(str == "floor")  {
    write("You sit down on the floor.\n");
    say(tp+" sits down upon the floor.\n");
    return 1;
        }
  if(str == "table")  {
    write("You sit down upon the table.\n"+
      "The librarian arches an eyebrow at you.\n");
    say(tp+" sits down upon one of the tables.\n");
    return 1;
        }
  write("Sit down where?\n");
  say(tp+" looks around for a place to sit.\n");
  return 1;
        }
