#define DEST "room/plane3"
#define NAME "Arrina"
/*
log_enter(ob) {
  if(!ob->is_player()) return ;
  write_file("/players/arrina/ENTER", "["+ctime(time())+"] "+
  ob->query_real_name()+", level "+ob->query_level()+" entered.\n");
}
*/
 short() {
  return "Crystal of Darkness";
 }
 id(str) {
  return str == "crystal";
 }
 long()  {
  write("This is Arrina's Crystal...it is a dark and evil place.\n"
 +      "You are welcome to 'enter crystal' but do so with care.\n");
 }
 reset(arg) {
  if(arg)
    return ;
  move_object(this_object(),DEST);
 }
 init() {
  add_action("enter", "enter");
 }
 enter(str) {
  if(!id(str))
    return ;
/*
  log_enter(this_player());
*/
  write("You enter the castle.\n");
  call_other(this_player(), "move_player",
             "into the castle#players/arrina/newbie/newbie1a");
  if(find_player("arrina")) {
  tell_object(find_player("arrina"),this_player()->query_real_name()+" has entered the crystal.\n"); }
  return 1;
 }
 is_castle() { return 1; }
