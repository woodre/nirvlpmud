inherit "room/room";

init () {
   ::init() ;
     add_action ("climb_tree","climb");
     }

reset(arg) {
   
   if(!arg){
     set_light(1);
     short_desc = "A tree";
     long_desc = 
"This is the most beautiful place you've seen since last time you saw this\n"+
"place.  The grass is green and the birds chirp...it is setting your mind a"+
"t\nease.\n"+
"   Rising high above you is a tall oak tree, possibly the old"+
       "er than\n" + "nirvana itself.  The top branches are very dense and y"+
       "ou can't tell what could be up there.\n";

dest_dir = ({
   "players/blue/castle/courtnw.c","north",
   "players/blue/castle/courtyard","east"
           });
     }
}

climb_tree(str) {
   if(str != "tree") { write("climb what?\n");
       return 1;}
  
     write("You climb up to shadows in the tree...\n");
     this_player()->move_player("tree#players/blue/castle/tree1b");
     return 1;}
