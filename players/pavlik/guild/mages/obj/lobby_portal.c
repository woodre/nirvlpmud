#define ME capitalize(this_player()->query_real_name())
#define PMS "players/pavlik/guild/mages/rooms/PROOMS/"
#define tp this_player()
reset(arg){
  if(arg) return;
}

short(){
  return "A Magic Portal";
}

long(){
  write(
  "This portal leads to the private quarters of the Mage's.\n"+
  "If you have a room, just type in your name to enter.\n"+
  "If you do not have a room, you must talk to the guild Registrar.\n"+
  "Goto Tamuli and type 'roomme'.\n"+
  "The portal glows with magical power.\n");
  return;
}

id(str){ return str == "portal"; }
get(){ return 0; }
drop(){ return 1; }

init(){
  add_action("enter_portal", tp->query_real_name());
}

enter_portal(){
  object obj;
  if(!restore_object(PMS+tp->query_real_name())){
    write("You do not have a private quarter here.\n"+
    "If you think you should have one talk to the Registrar.\n");
    say(ME+" walks into the portal.\n");
    say(ME+" bounces off the portal with a loud 'SMACK!'\n");
    return 1;
  }
  write("You enter the portal.\n");
  say(ME+" enters the portal.\n");
  move_object(tp, PMS+"master-room");
  obj=present(tp->query_real_name()+"'s mage_room", environment(tp));
  if(!obj){
    obj = clone_object("players/pavlik/guild/mages/room/personal_room");
    move_object(obj, PMS+"master-room");
    obj->set_owner(tp->query_real_name());
    obj->renew();
    }
  move_object(tp, obj);
  command("look", tp);
  return 1;
}

