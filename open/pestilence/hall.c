#include "/players/pestilence/ansi.h"
#define TP this_player()
inherit "room/room";
object item;

reset(arg) {
if(arg) return;

if (!present("stone")) {
  move_object(clone_object("/players/pestilence/stone.c"),
        this_object()); }

if (!present("board")) {
  move_object(clone_object("/players/pestilence/amity/obj/board.c"),
        this_object()); }

long_desc =
  "This is the Hall of Images.  Many different images can be seen\n"+
  "from here.  Some of these images can possibly be entered.  In\n"+
  "every direction there is a different image to be looked at.\n"+
  "These images go from a very gentle picture to some very harsh\n"+
  "images.  Most generally the harsher the vision the higher level\n"+
  "one should be to enter that image.  Being vice versa for the\n"+
  "softer more loveable image would be for a lower level character.\n";
set_light(1);

items = ({
  "images","The images are blurry.  You can hardly see them",
  "east","It appears to be an image of the popular children television show Blue's Clues",
  "up","no image yet",
  "northeast","A large open snow covered field, with a large castle in the background",
  "north","This is an image of a town being invaded by giant ants",
  "northwest","A sand covered beach, with water flowing from a sea onto the sand",
  "west","This is the empty parking lot to the well known strip club called Pesty's Place",
  "southwest","An image of a medium sized sparring arena.",
  "south","no image yet",
  "southeast","no image yet",
  "down","no image yet",
});

dest_dir = ({
"/room/south/sforst7","back",
  "/players/pestilence/amity/room/nmain1.c","north",
  "/players/pestilence/Cahara/room/blah.c","northwest",
  "/players/pestilence/blah","northeast",
  "/players/pestilence/club2/room/parking.c","west",
  "/players/pestilence/arena/room/entry.c","southwest",
  "/players/pestilence/blue/rooms/front.c","east",
  "/players/pestilence/blah","south",
});
}
short() {
    return ""+HIR+"Hall of Images"+NORM+"";
}
init () {
   ::init() ;
     add_action ("board","read");
     add_action ("block","northwest");
     add_action ("block","nw");
     add_action ("block","northeast");
     add_action ("block","ne");
     add_action ("enter","s");
     add_action ("enter","south");
     add_action ("guild_restore","guild_restore");
     add_action ("destroyer_restore","army_restore");
/*
     add_action ("block","west");
     add_action ("block","northeast");
     add_action ("blocked","north");
*/
     }

block(str) {
     write("This area is currently under construction.\n");
     return 1;}
blocked(str) {
     write("There has recently been a fire in Amity, so the town is shut down.\n");
     return 1;}

board(str){
  if(str != "board") return 0;
  write("The board lists those victorious over the Queen ant.\n\n");
  tail("/players/pestilence/amity/log");
  write("\n");
  return 1;
}

guild_restore() {
  if (this_player()->query_guild_name() == "Dark Order") {
  if(present("dknight_ob",this_player())) {
    write("You already have your guild object.\n");
    return 1; }
  item = clone_object("/players/pestilence/closed/dark/dark.c");
   move_object(item,this_player());
    write("Your guild object has been restored.\n");
return 1;
 }
}

destroyer_restore() {
  if (this_player()->query_guild_name() == ">A.o.P<") {
  if(present("destroyer_ob",this_player())) {
    write("You already have your guild object.\n");
    return 1; }
  item = clone_object("/players/pestilence/closed/destroyer/gob.c");
   move_object(item,this_player());
    write("Your guild object has been restored.\n");
return 1;
 }
}

enter(arg) {
   if(arg) { notify_fail("You must be a member of the Destroyers to go south.\n");
       return 0;}
  if(!arg){
  if (this_player()->query_guild_name() == ">A.o.P<") {
     write("You enter the Destroyer Guild Hall.\n");
     TP->move_player("leaves south#/players/pestilence/closed/destroyer/room/hall.c");
     return 1; }
        else
            write("You must be part of the Destroyers to go south.\n");
        return 1;
    }
}
