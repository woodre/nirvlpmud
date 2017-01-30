#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
if(!present("fire"))  {
move_object(clone_object("/players/mythos/closed/guild/fire.c"),this_object());}
 if(!arg){
  set_light(1);
short_desc="Bard Teleportation Chamber- Ruins";
long_desc=
 "An enourmous column of flame commands your attention.  Living, consuming\n"+
 "everything and nothing, it feeds upon itself, hissing and roaring.  The\n"+
 "heat from the terrible blaze sears the breath from your lungs.  The light\n"+
 "burns your eyes.  This blaze hungers, burning eternally.  Nothing else in\n"+
 "this room matters.\n" ;

  dest_dir=({
 "/players/saber/closed/old_bard/room/com.c","south",
 "/players/saber/closed/old_bard/room/adv.c","west",
           });
  }   }
