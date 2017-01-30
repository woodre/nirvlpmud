inherit "room/room";

init() {
#ifndef __LDMUD__
    add_action("meetings"); add_xverb("");
#else
     add_action("meetings", "", 3);
#endif
 ::init();
}

reset(arg){

if(!present("meetingboard")) {
   move_object(clone_object
   ("/players/snow/closed/cyber/boards/meetingboard.c"),
   this_object());}

 if(!arg){
 set_light(1);
 short_desc="The CyberNinja Meeting Room";
 long_desc=
"     You are in the CyberNinja Meeting Room.\n"+
"Several comfortable chairs surround a large round table.\n"+
"Cameras rest upon wall mounts in the corners of the room.\n";

  dest_dir=({
 "/players/snow/closed/cyber/rooms/guildhall.c","up",
      });

  items=({
  "cameras","Surveillance cameras record every important decision",
      });
  }   }

meetings(string str) {
  write_file("/players/snow/closed/cyber/log/MEETING",
             this_player()->query_real_name()+": "+str+"\n");
}

