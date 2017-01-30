#include "ansi.h"
inherit "room/room";

    void reset(status arg) {
    if (arg) return;
    set_light(1);
    short_desc = HIC+"Media Madness"+NORM;
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
        
    long_desc =
"   Bright lights shine down from the cathedral ceiling.  The floor\n\
is a beautiful patterned ceramic tile.  There are four areas one can\n\
go to in the store.  For those who love games, there is Games Galore\n\
Those who love to read can go to Readers Heaven.  Music lovers can go\n\
to Musica Festivus and movie lovers can go to Movie Mania.\n";
    dest_dir = ({"players/martha/games", "play",
                 "players/martha/books", "read",
                 "players/martha/music", "listen",
                 "players/martha/movies", "watch",
                 "/room/south/sforst3", "out"});
}