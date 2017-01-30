#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "/players/laera/cforest/hroom.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = "Domed Forest";
   long_desc =
"In the center of the forest the trees seem to bend inward, providing\n"+
"cover above a small clearing.  Somehow though, ample sunlight shines\n"+
"through the leaves.  Tender grass carpets the clearing, growing in\n"+
"small tufts at the bottoms of the trees.\n";
   
   items = ({
         "tree", "Tall, green trees, growing in an odd pattern",
"trees","Tall, green trees, growing in an odd pattern",
"clearing","A larger clearing can be seen through the trees",
"grass","Tender green grass grows at your feet",
"leaves","Healthy green leaves seem block sight from above",
"sunlight","Warm, clean sunlight makes its way through the trees",
});
   
set_listen("You hear the soft sound of birds chirping.");
set_smell("The fragrance of wildflowers is in the air.");
   dest_dir = ({
         "/players/laera/cforest/cf02.c","northwest",
});

}
