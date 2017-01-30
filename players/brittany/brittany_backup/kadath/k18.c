#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
status fire;

reset(arg) {
  fire = 1;

    if(!present("creature")) {
    move_object(clone_object("/players/brittany/kadath/NPC/anzoogs.c"),this_object());
   }

   if(arg) return;
   set_light(1);
   
   short_desc = CYN+"Enchanted Woods"+NORM;
   long_desc =
   "     Huge trees circle the large open area.  Some large mossy stones\n"+
   "are placed in a circle in the middle.  Inside the circle is a burning\n"+
   "fire.  A tree with a strange symbol on it, stands above the rest.\n";

   items = ({
 "trees","Permanent woody plants, with supported trunks and groping boughs",
"trunks","The huge main stems of the gigantic trees",
 "boughs","Long limbs extending 15-20 feet from the tree trunk",
         "stones","The stones are the size of large boulders, a fire is blazing inside",
         "boulders","Large rounded stones, a fire is blazing inside of it",
         "fire","Blazing fire, inside something is floating in mid-air that\n"+
         "resembles a manual, maybe you could 'reach' inside",
         "woods","Huge groping boughs",
         "symbol","The symbol is in the shape of a pentagram",
         "circle","Some stones are placed in a circle",
         "opening","An opening leading inside of the huge tree",
 "trees","Permanent woody plants, with supported trunks and groping boughs",
         "tree","There is an opening leading inside, maybe you can 'enter'",
          });

   dest_dir = ({
          "/players/brittany/kadath/k17.c","east",
          "/players/brittany/kadath/k20.c","south",
          });
   
}
init() {
    ::init();
    add_action("enter","enter");
    add_action("reach","reach");
   add_action("search","search");
    }
 
enter(str) {
    if(present("creature",this_object())) {
        write("The zoog moves in front of the opening to block you from entering.\n");
        return 1;
    }
    if(!str || str != "opening") {
        notify_fail("Enter what?\n");
        return 0; }
   write("You enter a hollowed opening on the strange looking tree.\n\n");
    say(tpn+"  enters the opening.\n");
    tp->move_player("into the tree#/players/brittany/kadath/k19.c");
    return 1;
}

reach(str){
  if(present("creature",this_object())){
  notify_fail("The guard blocks you.\n");
  return 0; }
  if(!str || str != "fire"){
  notify_fail("Reach where?\n");
  return 0; }

  if(!present("britmedal",this_player())){
  notify_fail("You hear a "+RED+" SCORCHING "+NORM+"  sound..you pull your hand back\n"+
  "quickly.\n");
  this_player()->hit_player(8);
  return 0; }


  if(fire) {
write("You reach into the fire without burning and pull out the manual.\n");
  move_object(clone_object("/players/brittany/kadath/OBJ/manuscripts.c"),this_player());
  fire = 0;
}
   else write("The manual is not available at this time.\n");
  return 1; }

 
search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}
