#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = GRN+"The Gourd"+NORM;
   long_desc =
   "     Large patches of hypnogourds are growing all over the land.\n"+
   "One of the gourds has an extra dimplelike hole on its upper\n"+
   "surface.  A pole with a sign attached to it, is lodged between\n"+
   "one area of the patch.  A path east of here branches off and\n"+
   "intersects other paths.\n";
   
   items = ({
         "gourds","It resembles a Mundane butternut squash",
         "hypnogourds","A harmless looking vegetable",
         "hole","A peephole in the shape of a dimple, maybe you could 'peep'\n"+
         "inside the gourd",
         "patches","A large area where patches of gourds are growing",
         "pole","A long metal pole about 3 feet high",
         "sign","A metal square with something written on it, maybe\n"+
         "you should 'read' it",
          });

   dest_dir = ({
         "/players/brittany/globe.c","out",
         "/players/brittany/xanth/gar3.c","east",
              });
}

init() {
::init();
   add_action("peep","peep");
   add_action("read","read");
  add_action("search","search");
}

read(str){
if(!str || str!="sign"){
return 1; }

  write("The sign reads...\n\n"+
   "  The land of Xanth is a peninsula, which moves around the face\n"+
   "of the Earth.  Xanth is unusual in many ways, the most important\n"+
   "being that it is rich in magic.  Species exist here that have\n"+
   "never been glimpsed or dreamed.  Xanth is a land for the smaller\n"+
   "traveller..if you are brave.  So tread lightly and fear not.\n");
return 1; }

peep(str){
if(!str || str!="hole"){
return 1; }

  write("You peep through the hole and hear a soft voice..\n\n"+
   "Seek out the blue tree with red leaves and 'climb'.  There you will\n"+
   "find the Five Forbidden Regions:  Air, Earth, Fire, Water, and The\n"+
   "Void.\n\n"+
   "The peephole closes..\n");
return 1; }

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}

out(str){
tp->move_player("out#/players/brittany/globe.c");
return 1; }
