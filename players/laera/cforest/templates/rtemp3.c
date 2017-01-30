#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "/players/laera/cforest/hroom.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = "Domed Forest";
   long_desc =
"Small boulders and bushes fill some of the gaps between the trees.\n"+
"Soft dark moss grows at the base of the trees and gently covers \n"+
"the tops of the boulders.  Small red and purple berries can barely\n"+
"be seen growing on the bushes.\n";
   
   items = ({
         "tree", "Tall, green trees, growing in an odd pattern",
"trees","Tall, green trees, growing in an odd pattern",
"moss","Soft green moss clings to the boulders and trees",
"boulders","A few boulders, in many sizes, lay about the forest",
"rocks","They aren't rocks, they are boulders...",
"bushes","Small berries grow on these leafy bushes",
"bush","Small berries grow on these leafy bushes",
"berries","Not quite ripe yet, come back in a month or so",
"berry","Not quite ripe yet, come back in a month or so",
});
   
set_listen("You hear the soft sound of birds chirping.");
set_smell("The fragrance of wildflowers is in the air.");
   dest_dir = ({
         "/players/laera/cforest/cf02.c","northwest",
});

}
