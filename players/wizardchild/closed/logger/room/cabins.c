/* cabins.c: where cabins go */
#define ROOM_DIR "/players/wizardchild/closed/logger/room/"
inherit "room/room";
reset(arg) {
  if(arg) return 0;
  set_light(1);
  short_desc = "A beatiful forested valley";
  long_desc = "You are surrounded by trees in this natural wonder. As you walk along,\n"
             +"the sunlight glimmers through the trees. Around here lie many wood\n"
             +"cabins that belong to various people.\n";
  dest_dir  =
  ({
  "/players/wizardchild/closed/logger/room/cabinrm.c", "back"
  });
}
init() {
    if(!(ROOM_DIR+"checkok")->query_ok(this_player())) {
    write("You shouldn't be here!\n");
    move_object(this_player(), "room/church");
  }
}
