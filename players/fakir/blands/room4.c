#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Borderlands";
long_desc =
   "Skull Mountain rises like a tower before your eyes.  It's sheer\n"+
   "walls and jagged rocks allow you no purchase nor handhold to climb.\n"+
   "You must retreat or go around the base of the rock fortress. A pile\n"+
   "of sun bleached bones, devoid of any flesh lie intermixed with rusty\n"+
   "armor.  The breastplate is dented and charred black as well.  The\n"+
   "path rises slightly to the northwest, and the crow circles overhead\n";
items = ({
   "mountain","It seems to reject the sunlight hitting upon it, or\n"+
              "perhaps rather it simply swallows it up. You cannot\n"+
              "tell which",
   "walls","Black obsidion rock with sheer angles and wicked edges",
   "rocks","Sharp serrated edges gleem in the sunlight",
   "fortress","A heavy grey fog obscures your vision of the topmost\n"+
              "portion of the mountain, but it almost appears as if\n"+
              "there are towers rising from its peak",
   "pile","Mixed bones and ancient armor, some almost rusted through",
   "bones","Elven by the look of them. The skull is nowhere to be seen",
   "armor","Elven chainmail rusted almost beyond recognition",
   "crow","Its wings beat matching the rhythm of your heart, and\n"+
          "it continues to observe your movements",
   "breastplate","To the trained eye, it is obvious whoever wore this\n"+
                 "armor took massive amounts of damage before he perished",
   "path","Weaving its way through the rocks, it skirts the base of Skull Mountain",
});

dest_dir = ({
   "/players/fakir/blands/room3.c", "south",
   "/players/fakir/blands/room5.c", "northwest",
   "/players/fakir/blands/room18.c", "northeast",
});

}
