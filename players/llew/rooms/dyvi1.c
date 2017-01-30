inherit "room/room";

reset(arg) {
if(!arg) {
   set_light(1);
   short_desc="Caer Dyvi";
   long_desc="\tTall spires of wood mark the walls of this protected\n"+
      "village.  Small huts appear beside the paths which run through\n"+
      "the caer.  The people go about their business as normal, but seem\n"+
      "to have a sense of pervading fear.  They travel along paths which\n"+
      "run west to the market and southward towards the caer hall.\n";
   dest_dir=({
      "/players/llew/rooms/dyvi2.c","west",
      "/players/llew/rooms/dyvi4.c","south",
      "/players/llew/rooms/for_entrance.c","east",
   });
   items=({"spires","The spires are made of the trees of the Gwynedd forest.\n"+
           "They rise to points for better defense against the invading barbarians.",
      "spire","The spires are made of the trees of the Gwynedd forest.\n"+
         "They rise to points for better defense against the invading barbarians",
      "wood","Sturdy beams of wood rise as walls to protect the Caer",
      "village","A village of timber huts and halls.  The community\n"+
         "contains warriors, farmers, fishers, and other necessary jobs",
      "huts","Huts of wood and straw with tendrils of cooking smoke wriggling\n"+
          "to merge with the sky",
      "hut","Huts of wood and straw with tendrils of cooking smoke wriggling\n"+
         "to merge with the sky",
      "paths","Dirt paths run wide of the huts scattered about. The open eath\n"+
         "looks fertile and moist in this chill humid climate",
      "path","Dirt paths run wide of the huts scattered about.  The open earth\n"+
         "looks fertile and moist in this chill humid climate",
      "caer","A clan dwelling that provides protection.\n"+
         "Most of the inhabitants are somehow related",
      "people","Dressed in leather or wool, they pratice their daily lives",
      "market","Slow and mostly barter, more a storage of community goods than a market",
      "hall","A long hall of huge timber, taking up nearly a third the length of the caer.\n"+
         "A gethering place for warriors",
});
   }
}
