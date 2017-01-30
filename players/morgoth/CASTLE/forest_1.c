inherit "room/room";

reset(arg){
int i;
object spid;

if(!present("spider")) {
  while(i < 6) {
   spid = clone_object("/players/morgoth/MONSTERS/spider.c");
   move_object(spid,this_object());
   i += 1;
 }
}

if(arg) return;

  set_light(1);
  short_desc="Forest path";

  long_desc=
    " \n" +
    "The bizarre trees seem to crowd together.  Their long, twisted\n" +
    "branches reaching out to grab intruders.\n" +
    " \n" +
    "Something in the branches is making a scittering sound..\n" +
    " \n";

dest_dir=({
 "/players/morgoth/CASTLE/entrance1.c","west",
 "/players/morgoth/CASTLE/forest_2.c","east" });
}

