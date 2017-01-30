#define io  this_object()->short()
#define ao  this_object()->query_alias()
#define tp  this_player()->query_name()
#define eo  environment(this_object())
inherit "players/mythos/amisc/treasure1";
reset(arg) {
  if(arg) return;
    set_id("darker");
    set_weight(100000);
    set_value(0);
    set_follow(1);
    set_mounted(0);
    set_noise(0);
}

init() {
  ::init();
  call_out("checker",1);
}

checker() {
int is_light;
  if(this_object()->query_follow()) {
  if(!present(this_object()->query_owner(),eo)) {
  if(!find_player(this_object()->query_owner())) { 
  destruct(this_object());
  return 1;}
  move_object(this_object(),environment(find_player(this_object()->query_owner())));
  }
  }
  call_out("checker",1); 
  return 1;}
  
  
