#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "/players/laera/cforest/hroom.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = "Domed Forest";
   long_desc =
"Tall, leafy, trees grow abundantly in this oddly shaped forest.  The\n"+
"soft sounds of birds chirping playfully can be heard throughout the \n"+
"area.  Tender grass grows underfoot and wildflowers can be seen here\n"+
"and there, growing happily.\n";
   
   items = ({
         "tree", "Tall, green trees, growing in an odd pattern",
"trees","Tall, green trees, growing in an odd pattern",
"grass","Tender green grass grows at your feet",
"wildflowers","Several different wildflowers dot the forest",
"flowers","Several different wildflowers dot the forest",
});
   
set_listen("You hear the soft sound of birds chirping.");
set_smell("The fragrance of wildflowers is in the air.");
   dest_dir = ({
         "/players/laera/cforest/cf02.c","northwest",
});

}
