#define NAME "Rumplemintz"
#define DEST "room/mount_top2"

int  id(string str) {  return str == "cloud" ; }
string short() {  return "A fluffy cloud waiting for a rider"; }

void long() {
  write("A mode of transportation to get to where you want to go.\n");
  write("Type 'ride' to go to Town Central!!\n");
}

void init() {  add_action("ride", "ride"); }

int ride() {
  say(this_player()->query_name() + " floats away on a cloud.\n");
  move_object(this_player(), "players/rumplemintz/room/central");
  say("A cloud floats peacefully into the room.\n" +
      "It drops off " + this_player()->query_name() +
      " and then floats away.\n");
  command("look", this_player());
  if (find_player("rumplemintz")) {
    tell_object(find_player("rumplemintz"),
                "CASTLE:: " + capitalize(this_player()->query_real_name()) +
                " just entered.\n");
    return 1;
  }
  return 1;
}

int reset(int arg) {
  if (arg)
    return;
  move_object(this_object(), DEST ) ;
  call_out("cloud_fluff",10);
}

int cloud_fluff() {
  say("The cloud fluffs itself.....\n");
  call_out("cloud_fluff2",10);
  return 1;
}

cloud_fluff2() {
  say("The cloud looks anxious for a rider...\n");
  call_out("cloud_fluff",10);
  return 1;
}

int is_castle() { return 1; }
