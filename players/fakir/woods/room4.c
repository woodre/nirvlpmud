#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";


reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Whispering Woods";
long_desc =
"Trees and bushes surround you as the path leads into a small copse of\n"+
"close growing vegetation.  A canopy of green covers the sky and the air\n"+
"has a thick moist feel to it.\n";

items = ({
"trees",    "Tall and growing close together like old friends, their branches intertwine",
"bushes",   "Mostly short and squatty here, with large thick leaves",
"path",     "You are not really on a path, it is just the random way of the woods",
"copse",    "A grove of trees and bushes, which shelter you from view in all directions",
"vegetation","Trees, bushes, grass in some places...and a flower or two as well",
"sky",       "It is not visible from this location",
"canopy",    "A sort of roof created by all the branches of the surrounding trees",

});

dest_dir = ({
   "/players/fakir/woods/room3.c", "southwest",
   "/players/fakir/woods/room5.c", "northwest",
});
}


