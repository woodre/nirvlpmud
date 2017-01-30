#include "/players/mythos/dmon/def.h"
#include "/players/mythos/droom/drom.c"
reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light_switch(2);
    set_short(RED+"Sylan Desert"+NORM,0);
    set_long("It is "+RED+"HOT"+NORM+"\n"+
             "A heat so tortuous and powerful that the senses writhe in agony.\n"+
             "The angry sun beats down upon you and sounds are deadened.\n"+
             "The eye has no place to go for all is too bright and too intense.\n"+
             "Neverending sand stretches out before you.\n",0);
    set_grid(0,1);
  set_dir("~desertvr","n");
  set_dir("~desertvr","e");
  set_dir("~desert","s");
  set_dir("~desertvr","w");
} }

init() { 
  if(random(10) == 0) {
  if(!present("portal")) {
    move_object(clone_object("/players/mythos/dmisc/portal.c"),this_object());
  }
  }
  ::init();
  add_action("vr","north",1);
  add_action("vr","east",1);
  add_action("vr","west",1);
}

vr() { 
object plain;
  plain = clone_object("/players/mythos/droom/desertvr.c");
  if(query_verb() == "n" || query_verb() == "north" ||
      query_verb() == "e" || query_verb() == "east" ||
      query_verb() == "w" || query_verb() =="west") {
  if(query_verb() == "n" || query_verb() == "north") {
    plain->set_grid(0,2);
    plain->replace_dir("s","~desert2",66);
  }
  if( query_verb() == "e" || query_verb() == "east") {
    plain->set_grid(1,1);
  }
  if( query_verb() == "w" || query_verb() =="west") {
    plain->set_grid(-1,1);
  }
    move_object(this_player(),plain);
    if(!this_player()->query_invis()) {
      tell_room(this_object(),this_player()->query_name()+" leaves north.\n");
      tell_room(plain,this_player()->query_name()+" arrives.\n");
    }
    command("look",this_player());
  return 1; }
}