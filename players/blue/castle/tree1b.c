inherit "room/room";

reset(arg) {
   object wiz, coins;

if(!arg) {

     set_light(1);
     short_desc = "Up a tree";
     long_desc = 
"You climb into a dark room; only a few beans of light push through the dens"+
"e\nbranches that enclose this space.\n"+
"   As your eyes adjust, you make out a small table and chairs, a litt"+
"le bed,\nand all the things that might tell you that you've stumbled into a"+
" very\nshort person's home.\n";

dest_dir = ({
   "players/blue/castle/tree1","down"
     });

   if(!wiz) {
   wiz = clone_object("obj/monster");
   wiz->set_level(20);
   wiz->set_gender("male");
   wiz->set_name ( "gnome");
   wiz->set_wc(25);
   wiz->set_ac (18);
   wiz->set_hp(600);
   wiz->set_short("A little gnome");
   wiz->set_long("At first glance, he appears harmless...but as he looks int"+
                 "o your eyes, you \nthink that he may be stronger than he "+
                 "looks.\n");
   move_object(wiz, this_object());
   coins = clone_object("obj/money");
   coins->set_money(1500);
   move_object(coins, wiz);
   }
   }
}
