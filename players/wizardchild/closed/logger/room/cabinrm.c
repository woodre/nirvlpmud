/* cabinrm.c: room that throws people in cabins */
#define ROOT_DIR "players/wizardchild/closed/logger/"
inherit "room/room";
static string *been_cloned;
static object *cabins;
reset(arg) {
  if(arg) return 0;
  set_light(1);
  short_desc = "A nature pathway";
  long_desc = "This is the pathway to the Logger's guild log cabins.\n"
    +"To go to your cabin, simply type 'visit cabin'; 'hall' will take you\n"   
    +"back to the main hall.\n";
  dest_dir =
  ({
  ROOT_DIR+"room/g_hall.c", "hall",
  });
  cabins = allocate(0);
  been_cloned = allocate(0);
}
init() {
    if(!(ROOM_DIR+"checkok")->query_ok(this_player())) {
    write_file(ROOT_DIR+"room/ILLEGAL_ENTRY", "<"+ctime(time())+"> "+this_player()->query_real_name()+" cabinrm\n");
    move_object(this_player(), "room/plane12");
  } else {
    add_action("visit", "visit");
    if(this_player()->query_real_name() == "wizardchild") 
      add_action("query_been_cloned", "been_cloned");
  }
  ::init();
}
query_been_cloned() { return been_cloned; }
visit(str) {
  int i;
  string me;
  if(str != "cabin") return 0;
  me = this_player()->query_real_name();
  for(i = 0; i < sizeof(been_cloned); i++) {
    if(me == been_cloned[i]) {
      say(capitalize(me)+" leaves to his cabin.\n");
      move_object(this_player(), cabins[i]);      
      command("look", this_player());
      say(capitalize(me)+" arrives.\n");
      return 1;
    } 
  }
/* we get down here if the player's name is not in been_cloned */
/* reset the var, put it at the end of the line */
  i = 0;
  been_cloned += ({0});
  cabins += ({0});
  for(i = 0; i < sizeof(been_cloned) && been_cloned[i]; i++) ;
  been_cloned[i] = me;
  cabins[i] = clone_object(ROOT_DIR+"cabin/cabin.c");
  if(!cabins[i]->set_owner(me)) {
    write("Error! You are not a logger!\n");
    write_file(ROOT_DIR+"cabin/ERROR", "<"+ctime(time())+"> "+me+" was trying to get a cabin.\n");
    return 1;
  }    
  cabins[i]->set_owner(this_player()->query_real_name());
  move_object(cabins[i], ROOT_DIR+"room/cabins.c");
  say(capitalize(me)+" leaves to his cabin.\n");
  move_object(this_player(), cabins[i]);
  command("look", this_player());
  say(capitalize(me)+" arrives.\n");
  return 1;
}
