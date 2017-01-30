#define ME capitalize(this_player()->query_name())
#define ENV environment(this_object())

string leader;
string tmp_leader;
string *follow;
int follow_delay;

reset(arg){
  if(arg) return;
  leader = 0;
  tmp_leader = 0;
  follow_delay = 0;
}

id(str) {
  return str == "ilstkarn_follow" || str == "follow" || str == "follow object";
}

long(){
  write(
  "This is an Ilstkarn follow object.  It allows you to follow\n"+
  "another player in the realms of Ilstkarn.\n"+
  "You can use the following commands:\n\n");
  write(
  "   folist              - list following players.\n"+
  "   folstop             - stop following the leader.\n"+
  "   folead             - become a follow leader (new group).\n"+
  "   foldel              - trash this object.\n\n");
  return;
}

short(){
  if(!leader) return "A follow object ()";
  return "A follow object ("+leader+")";
}

get() {
  return 1;
}

drop() {
  return 1;
}

query_weight() {
  return 0;
}

query_value() {
  return 0;
}

query_save_flag() {
  return 1;
}

set_leader(str) {
  leader = str;
}

query_leader() {
  object ob, obj;

  if(!leader) { return 0; }
  ob = find_player(leader);
  if(!ob) { leader = 0; return 0; }
  obj = present("ilstkarn_follow", ob);
  if(!obj) { leader = 0; return 0; }
  if(!obj->allowed_follow(ENV->query_real_name())) { leader = 0; return 0; }
  return leader;
}

set_follow_delay(i) {
  follow_delay = i;
}

query_follow_delay() {
  return follow_delay;
}

tick_follow_delay(){
  follow_delay--;
  if(follow_delay < 0) follow_delay = 0;
}

init() {
  add_action("folist", "folist");
  add_action("folstop", "folstop");
  add_action("folead","folead");
  add_action("foldel", "foldel");
  add_action("folyes", "folyes");
}

folist() {
  object obj;
  int i;

  if(!leader) {
    write("You are not following anyone.\n");
    return 1;
  }

  obj = find_player(leader);

  if(!obj) {
    write("Cannot find leader.\n");
    return 1;
  }

  if(!present("ilstkarn_follow", obj)) {
    write("You are not following anyone.\n");
    leader = 0;
    return 1;
  }

  follow = present("ilstkarn_follow", obj)->query_follow();

  write(
  "These people are currently following "+capitalize(leader)+":\n");
  for(i=0; i<sizeof(follow); i++) {
    write("\t"+follow[i]+"\n");
  }
  return 1;
}

folstop(sil) {
  object obj;

  if(!leader) {
    if(!sil) write("You are not following anyone.\n");
    return 1;
  }

  write("You stop following "+capitalize(leader)+".\n");

  if(find_player(leader)) {
    obj = present("ilstkarn_follow", find_player(leader));
    if(obj) {
      obj->remove_follower(this_player()->query_real_name());
    }
  }

  leader = 0;
  return 1;
}

ask_follow(str) {
  tell_object(ENV, "\n"+
  capitalize(str)+" asks you to follow.\n"+
  "To accept type 'folyes'.\n\n");
  tmp_leader = str;
  return 1;
}

folyes() {
  object obj;

  if(!tmp_leader) {
    write("Noone has asked you to follow them.\n");
    return 1;
  }

  obj = find_player(tmp_leader);

  if(!obj) {
    write("That person is no longer here.\n");
    return 1;
  }

  if(!present(obj, environment(this_player()))) {
    write("That person is not here.\n");
    return 1;
  }

  if(!present("ilstkarn_follow", obj)) {
    write(capitalize(tmp_leader)+" is no longer avaliable.\n");
    return 1;
  }

  write("You now follow "+capitalize(tmp_leader)+".\n");
  present("ilstkarn_follow", obj)->confirm_follow(this_player()->query_real_name());
  leader = tmp_leader;
  tmp_leader = 0;
  return 1;
}

foldel() {
  if(query_leader()) {
    command("folstop 1", this_player());
  }
  write("You trash the Ilstkarn follow object.\n");
  destruct(this_object());
  return 1;
}

folead() {
  if(query_leader()) {
    command("folstop 1", this_player());
  }
  write("You create your own leader object.\n");
  move_object(clone_object("players/pavlik/items/ilstkarn/ilstkarn_leader"),
  this_player());
  destruct(this_object());
  return 1;
}


