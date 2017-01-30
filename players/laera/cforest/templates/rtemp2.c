#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "/players/laera/cforest/hroom.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = "Domed Forest";
   long_desc =
"Daisies and violets peek up through the tender grass.  The trees are\n"+
"spaced far enough apart to walk between, but there doesn't seem to be\n"+
"a path to follow.  Soft chirping can be heard in the distance.\n";
   
   items = ({
         "tree", "Tall, green trees, growing in an odd pattern",
"trees","Tall, green trees, growing in an odd pattern",
"grass","Tender green grass grows at your feet",
"wildflowers","Several different wildflowers dot the forest",
"flowers","Several different wildflowers dot the forest",
"daisies","Bunches of white daisies, waiting to be picked",
"violets","Fragrant violets peek up out of the grass",
});
   
set_listen("You hear the soft sound of birds chirping.");
set_smell("The fragrance of wildflowers is in the air.");
   dest_dir = ({
         "/players/laera/cforest/cf02.c","northwest",
});

}
