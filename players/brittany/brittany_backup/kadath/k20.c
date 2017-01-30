/* Objects in this room will be used in a quest object in the future  */

#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

/*  status pentagram;  */
/*  status opening;   */
int dummy;

reset(arg) {
   if(arg) return;
 /*  opening = 1; */
 /*  pentagram = 1; */
   set_light(1);
   
   short_desc = CYN+"Enchanted Woods"+NORM;
   long_desc =
    "     The vast trunks grow thicker in this area.  A large clearing can\n"+
    "be seen in between some trees.  A mighty slab of stone is resting on\n"+
    "the ground.  The woods continues south of here.\n";
   
   items = ({
"trees","Permanent woody plants, with supported trunks and groping boughs", 
         "trunks","The huge main stems of the gigantic trees",
 "boughs","Long limbs extending 15-20 feet from the tree trunk",
         "stone","A slab of stone with a huge iron ring attached, maybe you can 'pull' it",
         "iron ring","A huge iron ring made of metal is attached to a slab of stones",
         "ring","A huge iron ring made of metal is attached to a slab of stones",
         "slab","The slab is in the shape of a rectangle, resembling a door",
         "stone","The stone is flat and in the shape of a rectangle",
         "ground","There is a slab of stones resting on the ground",
         "oaks","The oak trees in the Enchanted woods",
         "clearing","A large open space in between some trees",
         "tree","The bough has a strange symbol lodged into it",
         "symbol","The symbol is shaped like a pentagram",
         "bough","It has something lodged into it, maybe you can 'twist' it off",
   /*      "pentagram","The pentagram looks like it could be moved on the bough",  */
         "woods","The oak twine groping boughs",
         "village","The village of the elder dwellers.",
          });

   dest_dir = ({
          "/players/brittany/kadath/k18.c","north",
          "/players/brittany/kadath/k21.c","south",
          });
   
}
init() {
    ::init();
    add_action("pull_ring","pull");
   add_action("search","search");
  /*  add_action("twist_pentagram","twist"); */
  /*  add_action("search","search"); */
  /* add_action("look","look");   */
    }
 
pull_ring(str) {
    if(!str || str != "ring") {
        write("Pull what?\n");
        return 1; }
   write("You pull the ring, but nothing happens.\n");
    return 1;
}
/*   twist_pentagram(str){
    if(!str || str != "pentagram") {
       write("What do you want to twist?\n");
        return 0; }
   if(pentagram) {
    write("You twist the pentagram and find an opening inside the tree.\n");
     pentagram = 0;
   }
   else write("The pentagram has already been twisted.\n");
   return 1; }
*/
/*  look(str){
 if(str == "opening"){
   return 0; }

  if(opening){
  pentagram = 1;
   write("What opening?");
   pentagram = 0;
   }
   else write("You find an opening inside the tree, maybe you should 'search' it.\n");
   return 1; }
*/
/*  search(str) {
   if(!str || str != "opening") {
   write("Search what?\n");
   return 0;}
*/
  /*  if(opening){
   write("You retrieve a scroll from the opening.\n");
  move_object(clone_object("/players/brittany/kadath/OBJ/scroll.c"),this_player());
   opening = 0;
   }
   else write("You search the opening and find nothing.\n");
          return 1;
}   */

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}
