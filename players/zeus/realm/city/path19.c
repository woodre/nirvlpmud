inherit "/room/room";

#include "/players/zeus/closed/fl_demon.h"

int searched, teleport;

reset(arg)
{
  ::reset(arg);
   searched = 0;
   if(!arg){
   teleport = 0;
   if (random(2))
      teleport = 1;
   set_light(1);
   short_desc = "The Fallen Lands";
   long_desc =
   "This is a slight clearing in the forest.  A few large pieces of stone \n"+
   "are laying on the path, covered in dirt and leaves.  A large rock is \n"+
   "sitting just north of the path.  To the northwest the path continues \n"+
   "into a darker part of the forest, and also breaks off to the east.  The \n"+
   "undergrowth around the clearing is very thick.\n";
   items = ({
         "trees",
         "The evergreen trees reach high into the sky around the clearing.  Their\n"+
         "branches are reaching out to each other, creating a slight canopy",
         "canopy",
         "The branches of the evergreen trees are blocking out a little of the\n"+
         "sky from view, but plenty of light is able to get through",
         "sky",
         "The beautiful blue sky can be seen through the trees above",
         "branches",
         "The branches of the evergreen trees are touching one another, doing\n"+
         "their best to block out the light from the forest floor",
         "dirt",
         "The dirt is very dry here.  There are a number of pieces of stone here,\n"+
         "which are almost entirely covered in dirt",
         "leaves", 
         "There are some dead brown leaves scattered across the clearing",
         "path",
         "The path is open here, consisting of dry dirt, a couple large pieces\n"+
         "of flat stone, and some dead brown leaves",
         "stone",
         "The flat pieces of stone are white and very dirty.  Long ago they\n"+
         "were part of a building, but now just decorate the path like garbage",
         "pieces", 
         "There are a number of flat pieces of white stone scattered around the\n"+
         "ground here.  They are covered in dirt and leaves",
         "clearing", 
         "The clearing is fairly open here, and because the trees aren't blocking\n"+
         "out all of the light, it is a warm little spot in the forest",
         "forest", 
         "The forest isn't extremely thick here, the evergreen trees are pushed\n"+
         "back, allowing a lot of light to reach the forest floor.  There are\n"+
         "some beautiful plants growing amongst the undergrowth.  The forest to\n"+
         "the northwest is much darker",
         "rock",
         "There is a large rock sitting just north of the path.  It is grey and\n"+
         "has green moss growing on it",
         "undergrowth",
         "The undergrowth is very thick around the clearing, especially to the\n"+
         "northeast.  There are a couple large ferns and bushes growing there.\n"+
         "Something seems to look peculiar about the undergrowth there",
         "ferns",
         "There are a few large green ferns growing to the northeast of the path.\n"+
         "A couple of them have been broken, as if someone has walked over them",
         "bushes",
         "There are a couple bushes to the northeast of the path.  One of them\n"+
         "has been cut to pieces as if to make travel in that direction easier",
  });
   dest_dir=({
         "/players/zeus/realm/city/path20.c", "east",
         "/players/zeus/realm/city/path15.c", "south",
         "/players/zeus/realm/city/path21.c", "northwest",
   });
   }
}

int searched() { return searched; }

init() {
   ::init();
  add_action("n_dir", "north");
  add_action("ne_dir", "northeast");
  add_action("ne_dir2", "northeast");
  add_action("e_dir", "east");
  add_action("se_dir", "southeast");
  add_action("s_dir", "south");
  add_action("sw_dir", "southwest");
  add_action("w_dir", "west");
  add_action("nw_dir", "northwest");
  add_action("search_cmd", "search");
}

exit(){    if(TP) TP->clear_fight_area();     }
okay_follow(){ return 1; }
realm() { if(teleport) return "NT"; }

status search_cmd(string str){
   if(!str){ 
      write("You search the clearing briefly and discover nothing.\n");
      return 1; }
   if(str == "undergrowth" || str == "plants" || str == "northeast" ||
         str == "ferns" || str == "bushes")
   {
      if(this_player()->query_attrib("int") < 19)
         {
         write(
            "You feel as though something is here, but you can't seem to find it.\n");
         say(this_player()->query_name()+" gets a funny look on "+
             this_player()->query_possessive()+" face.\n");
         return 1;
      }
      if(searched)
         {
         write("Someone has already uncovered the path to the northeast.\n");
         return 1;
      }
      write(
         "You search the undergrowth to the northeast carefully and discover a\n"+
         "very hidden path which leads to the northeast.  The undergrowth is so\n"+
         "thick that it is almost impossible to see the path.\n");
      say(this_player()->query_name()+
          " searches the area and uncovers a path to the northeast.\n");
      searched = 1;
      return 1; }
   else { 
      write("You search the clearing briefly and discover nothing.\n");
      return 1; }
   return 1; }

ne_dir2(){
  if(searched){
    write(
"You parth the undergrowth and slowly travel to the northeast...\n");
    this_player()->move_player("northeast#/players/zeus/realm/city/path24.c");
    return 1;
  }
  else {
    write("What?\n");
    return 1;
  }
  return 1;
}
