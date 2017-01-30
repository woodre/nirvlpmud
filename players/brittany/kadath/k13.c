#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = CYN+"Enchanted Woods"+NORM;
   long_desc =
   "     Huge, groping boughs hang down the old tree.  They glow with\n"+
   "a strange phosphorescence.  A huge mound of dirt is piled at its\n"+
   "base and there is an arrow carved in its trunk.\n";
   
   items = ({
         "trees","Permanent woody plants, with supported trunks and groping boughs",
         "boughs","Long limbs extending 15-20 feet from the tree trunk",
         "tree","A permanent woody plant, with a self supported trunk and groping branches",
         "base","The base of the huge tree",
         "branches","Long limbs extending 15-20 feet from the tree trunk",
         "fungi","A phosphorescent spongy abnormal growth",
         "mound","A fresh mound, like someone just dug it",
         "mounds","Fresh dirt piles all over, like someone just dug them",
         "arrow","An arrow carved into the tree points 'north', some\n"+
         "markings are scribe below it",
         "markings","Markings scribe below the arrow, maybe you should 'read' it",
         "ground","The solid surface of the land is covered with some dirt mounds, maybe you could 'dig' through",
          "pile","A fresh pile of dirt, like someone just dug it",
         "piles","Piles of dirt into mounds",
         "dirt piles","Loose soil piled into mounds",
         "dirt","Loose soil piled into mounds, like someone just dug them",
"trunk","The huge main stem of the gigantic trees",
         "enchanted woods","The Enchanted woods, where the trees are covered with\n"+
         "a phosphorescent glow",
         "woods","The Enchanted woods, where the trees are covered with\n"+
         "a phosphorescent glow",
         "glow","A phosphorescent glow covering the trees",
          });

   dest_dir = ({
         "/players/brittany/kadath/k10.c","north",
         "/players/brittany/kadath/k17.c","west",
          });
}
init(){
::init();
add_action("read","read");
add_action("search","search");
add_action("dig_mound","dig");
add_action("dig_pile","dig");
add_action("dig_dirt","dig"); }


dig_pile(str){
if(!str || str!="pile"){
  notify_fail("What do you want to dig?\n");
  return 0; }

  write("You dig through the pile, OOOPS...the ground where you\n"+
         "are standing caves in and you  S L I I D E E   through\n"+
         "a tunnel.\n");
    say(tpn+"  S L I I D E E S  into a tunnel.\n");
    tp->move_player("into the unknown#/players/brittany/kadath/k14.c");
return 1; }

dig_mound(str){
if(!str || str!="mound"){
  notify_fail("What do you want to dig?\n");
  return 0; }
 
  write("You dig through the mound, OOOPS...the ground where you\n"+
         "are standing caves in and you  S L I I D E E   through\n"+
         "a tunnel.\n");
    say(tpn+"  S L I I D E E S  into a tunnel.\n");
    tp->move_player("into the unknown#/players/brittany/kadath/k14.c");
return 1; }

dig_dirt(str){
if(!str || str!="dirt"){
  notify_fail("What do you want to dig?\n");
  return 0; }
 
  write("You dig through the dirt, OOOPS...the ground where you\n"+
         "are standing caves in and you  S L I I D E E   through\n"+
         "a tunnel.\n");
    say(tpn+"  S L I I D E E S  into a tunnel.\n");
    tp->move_player("into the unknown#/players/brittany/kadath/k14.c");
return 1; }

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}

read(str) {
    if(!str || str != "markings") {
        notify_fail("What do you want to read?\n");
        return 0; }

    write(
     "North of here is the entrance to the Enchanted Woods.\n\n");
     return 1;
}
