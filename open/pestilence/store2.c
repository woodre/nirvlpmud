#include "ansi.h"
inherit "room/room";

reset(arg) {
    if (arg) return;

    short_desc = HIC+"Media Madness"+NORM;
    long_desc =
"   Bright lights shine down from the cathedral ceiling.  The floor\n\
is a beautiful patterned ceramic tile.  There are four areas one can\n\
go to in the store.  For those who love games, there is Games Galore\n\
Those who love to read can go to Readers Heaven.  Music lovers can go\n\
to Musica Festivus and movie lovers can go to Movie Mania.\n";
    set_light(1);
    items = ({
        "lights","Track lighting that shines down brightly",
        "ceiling","This is a cathedral ceiling and it is beautiful",
        "floor","Beautiful blue patterned ceramic tile",
        "tile","The tile is white with a blue pattern",
        "games","This area is for those who love board games",
        "galore","This area is for those who love board games",
        "play","This area is for those who love board games",
        "readers","This area is for the book lover in you",
        "heaven","This area is for the book lover in you",
        "read","This area is for the book lover in you",
        "musica","This area is for those who love music",
        "festivus","This area is for those who love music",
        "listen","This area is for those who love music",
        "movie","This area is for the movie lover in us all",
        "mania","This area is for the movie lover in us all",
        "watch","This area is for the movie lover in us all",
        "area","Which area fool?"});
    dest_dir = ({
                  "/players/martha/games.c", "play",
                  "/room/south/sforst3.c", "out",
});
}

init() {
   ::init() ;
    add_action("move_read"); add_verb("read");
    add_action("move_listen"); add_verb("listen");
    add_action("move_watch"); add_verb("watch"); 
}

move_read(str) {
  say(capitalize(this_player()->query_name())+
    " tries to enter an area that is under construction.\n");
  this_player()->move_player( 
    "This area appears to be under construction#/players/martha/books.c");
  say(capitalize(this_player()->query_name())+" arrives.\n");
  return 1;
}

move_listen(str) {
  say(capitalize(this_player()->query_name())+
        " tries to enter an area that is under construction.\n");
  this_player()->move_player(
        "This area appears to be under construction#/players/martha/music.c");
  say(capitalize(this_player()->query_name())+" arrives.\n");
  return 1;
}

move_watch(str) {
  say(capitalize(this_player()->query_name())+ 
        " tries to enter an area that is under construction.\n");
  this_player()->move_player(
        "This area appears to be under construction#/players/martha/movies.c");
  say(capitalize(this_player()->query_name())+" arrives.\n");   
  return 1;
}  
