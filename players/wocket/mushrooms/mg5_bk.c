inherit "room/room";
#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/mushrooms/"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()

reset(arg) {
  int i;
  i = random(2);
  if(i == 1){
    for(i=0 ; i < random(2)+1 ; i++){
      move_object(clone_object("/players/wocket/mushrooms/nonge.c"),this_object());
    } 
  }
  if(arg) return;
  set_light(1);

  short_desc = HIR+"The Mushroom Grove"+NORM;
  long_desc =
"   \
Tall mushrooms give cover overhead, as birds sing and crickets\n\
chirp from the underbrush.  Small tufts of grass grow from the\n\
dirt pathway as the breeze gently blows.  To the east a split\n\
looks like it is formed and to the southwest the mushrooms grow\n\
denser and a dead end is formed.\n";

  items = ({
    "underbrush","You can see squirrels moving through it",
    "squirrels","They move through the underbrush",
    "grass","Small tufts grow along the edge of the dirt pathway",
    "mushrooms","They are oversized and very colorful",
    "pathway","It is well worn from use",
  });

  dest_dir = ({
    PATH+"mg4.c","east",
    PATH+"mg6.c","southwest",
  });

}

init(){
    ::init();
    add_action("listen","listen");
}

int listen(string str){
  if(str == "birds"){
    write("You can hear the birds singing.\n");
    return 1;
  }
  if(str == "crickets"){ 
    write("You can hear the crickets chirping.\n");
    return 1;
  }
  write("You can hear the birds singing and the crickets chirping.\n");
  return 1;
}
