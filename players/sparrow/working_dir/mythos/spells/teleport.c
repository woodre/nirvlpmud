inherit "obj/treasure";
object ob, place;
reset(arg) {
  if(arg) return;
    set_id("teleportation_device");
    set_weight(0);
    set_value(0);
    place = 0;
}
query_save_flag() { return 1;}

init() {
  ::init();
  add_action("activate","activate");
  add_action("place","dset");
}

place() {
if( environment(this_player())->realm() == "NT") {
  write("You may not set the device to this place.\n"); return 1;}
  place = environment(this_player());
  write("The device is set.\n");
return 1;}

activate() {
  if( environment(this_player())->realm() == "NT") {
  write("You may not use the teleportation here.\n"); return 1;} 
  if(place) {
  say(capitalize(this_player()->query_real_name())+" crushes "+this_object()->short()+
  " and then vanishes!\n");
  move_object(this_player(),place);
  tell_room(environment(this_player()),
  capitalize(this_player()->query_real_name())+" appears!\n");
  destruct(this_object());
return 1;}
  write("The device is not set.\n");
return 1;}
  
  
  
