#include "/players/mythos/closed/ansi.h"
inherit "room/room";

reset(arg) {
  if(!present("conan")) { 
  move_object(clone_object("/players/mythos/lmon/conan.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "Library: "+HIR+"** PUNISHMENT **"+NORM;
    long_desc =
    "If you are here, you have been very very bad....\n"+
    "Conan, the Librarian is here to teach you a lesson.\n";
  items = ({
    "escape","The only way out",
  });

  dest_dir = ({
    "/players/mythos/lroom/hall.c","escape",
  });
} }
realm() {return "NT"; }
init() {
  ::init();
  rm("/players/mythos/lroom/enforcement/"+lower_case(this_player()->query_name()));
  call_other(this_player(),"set_home","/players/mythos/lroom/pun.c");
  add_action("zap","magic missle");
  add_action("zap","missle");
  add_action("zap","mi");
  add_action("zap","fireball");
  add_action("zap","fire ball");
  add_action("zap","fi");
  add_action("zap","shock");
  add_action("zap","sh");
  add_action("zap","sonic");
  add_action("zap","so");
  add_action("escape","escape");
}

zap() {
 write("CONAN laughs at you!\n");
  return 1;}

escape() {
  if(this_player()->query_ghost()) {
  call_other(this_player(),"set_home","/room/church.c");
    this_player()->move_player("/room/church");
  return 1;}
    if(present("conan")) {
     write("Conan bars your way!\n"); return 1;}
  call_other(this_player(),"set_home","/room/church.c");
  }
/* Added by Illarion 5 April 2005 so players who quit or use the tunnel after dying will
   after dying will be 'freed' */
exit() {
  if(this_player() && this_player()->query_ghost()) {
    tell_object(this_player(),"Conan's hold on you has been lifted.\n");
    this_player()->set_home("/room/church.c");
  }
}
