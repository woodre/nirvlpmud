#define tp this_player()->query_name()
#define tg this_player()->query_gender()

inherit "obj/treasure";

reset(arg) {
  if(arg) return;

  set_id("tail");
  set_short("The tail of the Orochi");
  set_long("The tail of the Orochi.  Something seems\n"+
  	        "to be hidden within- you may want to 'split'\n"+
  	        "it open.\n");
  set_weight(15);
  set_value(3000);
}

init() {
  ::init();
  add_action("gget","get");
  add_action("gget","take");
  add_action("split","split");
  }
  
gget(str) {
  if(environment(this_object())->query_name() != this_player()->query_name()) {
  if(str=="tail" || str== "all") {
    if(call_other(this_player(),"query_attrib","str") < random(25)) {
     tell_object(this_player(),"You strain to pick up the tail, but fail.\n");
      say(capitalize(this_player()->query_name())+" strains but fails to "+
          "pick up the tail.\n");
      return 1;} }  }}
      
split() {
  tell_object(this_player(),"You split the tail with a sharp knife and "+
      "from inside you pull out a sword of great beauty!\n");
  say( capitalize(this_player()->query_name())+" splits open the tail and "+
      "pulls out a sword!\n");
  move_object(clone_object("/players/mythos/awep/forest/ken.c"),this_player());
  destruct(this_object());
  return 1;}
