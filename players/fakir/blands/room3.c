#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Borderlands";
long_desc =
   "A salt encrusted dry lake forces you to skirt its shoreline on the\n"+
   "west, while to your east a deep ravine drops off into utter blackness.\n"+
   "A solitary crow regards your passing from the branches of a dead tree\n"+
   "rising at an angle from the lakebed.  There are some letters carved\n"+
   "into the bare skin of the tree.  The path wanders north.\n";

items = ({
   "lake","Bone dry and without life of any kind",
   "shoreline","White crusty film clings to the rocks and rubble",
   "ravine","Its canyon-like walls allow no entry nor escape",
   "blackness","Beginning near the top as shades of grey, it\n"+
               "gradually grows to pitch black near the bottom\n"+
               "You sense evil magic at work here",
   "crow","As black as the bottom of the ravine, it watches your\n"+
          "every movement. It's eyes never blink",
   "tree","The bark long ago stripped from its trunk, it stands\n"+
          "like a ghost with arms outstretched",
   "path","Dry, dusty grit and sand are mixed with small sharp rocks",
   "branches","Long and spindly they barely move in the wind",
   "letters","Maybe you should try reading the letters",
   "skin","The missing bark makes the hide of the tree look like dried skin",
   "lakebed","Shallow at the edges, it grows deeper toward the middle",

});

dest_dir = ({
   "/players/fakir/blands/room4.c", "north",
   "/players/fakir/blands/room2.c","south"
});

}
