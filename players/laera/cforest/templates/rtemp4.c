#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "/players/laera/cforest/hroom.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = "Domed Forest";
   long_desc =
"Between the trees are tiny clearings and every once in a while a\n"+
"larger clearing can be glimpsed near the center of the forest.  The\n"+
"sounds of the birds seems to fade in and out teasingly.\n";
   
   items = ({
         "tree", "Tall, green trees, growing in an odd pattern",
"trees","Tall, green trees, growing in an odd pattern",
"clearing","A larger clearing can be seen through the trees",
});
   
set_listen("You hear the soft sound of birds chirping.");
set_smell("The fragrance of wildflowers is in the air.");
   dest_dir = ({
         "/players/laera/cforest/cf02.c","northwest",
});

}
