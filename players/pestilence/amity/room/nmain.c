#include "/players/pestilence/define.h"
#include "/players/pestilence/ansi.h"
inherit "/players/vertebraker/closed/std/room";
int OPEN;

reset(arg) {
  if(arg) return;
    OPEN = 0;

short_desc = ""+BLU+"North Main Street"+NORM+"";
long_desc =
"    This is a long paved street extending from north to south.  There\n"+
"are buildings on each side of the street.  There are a few broken\n"+
"parking meters on each side of the road.  There has been some kind of\n"+
"scuffle in the street.  The streets are now abandoned but there are\n"+
"people still in the buildings.  There is a small manhole cover on the east\n"+
"side of the street.\n";
set_light(1);

items = ({
"street","A paved street with curbs on each side extending north to south",
"road","A paved street with curbs on each side extending north to south",
"manhole cover","A small circular cover leading into the sewer system of Amity",
"cover","A small circular cover leading into the sewer system of Amity",
"people","Citizens of Amity are browsing in the local businesses",
"meters","A few parking meters have been smashed on each side of the street",
"parking meters","A few parking meters have been smashed on each side of the street",
"buildings","There are a couple buildings on the east and west of the street, containing a few businesses",
"manhole","A small circular cover leading into the sewer system of Amity",
"curbs","Cement curbs that run along the length of the streets",
});

dest_dir = ({
  "/players/pestilence/amity/room/coc.c","east",
  "/players/pestilence/blah","back",
  "/players/pestilence/amity/room/taxi.c","west",
  "/players/pestilence/amity/room/nmain2.c","north",
});
}
init() {
  ::init();
add_action("club","back");
add_action("open","open");
add_action("enter","enter");
}
club() {
  TP->move_player("hall#/players/pestilence/hall.c");
/*
write_file("/players/pestilence/amity/log2",""+TP->query_real_name()+" "+TP->query_level()+"+"+TP->query_extra_level()+" has left Amity -> "+ctime(time())+"\n");
*/
  return 1; }
open(arg){

 if(arg == "manhole cover"  || arg == "cover"  || arg == "manhole"){
    write("You open the manhole.\n");
    say(TPN+" opens the manhole!\n");
OPEN +=1;
return 1; }
    write("Open what?\n");
return 1; }


enter(arg){
  if(OPEN == 0){ write("Maybe you should open the manhole first?\n"); return 1; }
  if((arg == "manhole") && (OPEN == 1)){
    write("You leave down the manhole ladder.\n");
 move_object(this_player(), "/players/pestilence/club/room/ssewer3.c");  
  command("look",this_player());
return 1; }
}
