/*Here is a hidden passage leading into another part of the ruins. Use is 'push lever'
  and character is transported to r17.c    */
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#include "/players/maledicta/ansi.h"
inherit "room/room";

reset(arg) {
  if(!present("mane")){
  move_object(clone_object("/players/maledicta/ruins/mobs/shadowmane.c"), this_object()); }
    if(!present("archangel")){
  move_object(clone_object("/players/maledicta/ruins/mobs/iceangel6.c"), this_object()); }
  if(arg) return;
set_light(1);

short_desc = "The "+BOLD+""+BLK+"Ruins"+NORM+"";
long_desc =
"   Here the hallway abruptly ends. Small niches line the crumbled\n"+
"walls.  A large hole can be seen in the ceiling, the skies dark clouds\n"+
"rushing by overhead as you peer out.  A large anhk stands against the\n"+
"south wall, its huge mass broken in half.  The hallway leads back to\n"+
"the north.\n";

items = ({
  "niches",
  "You look closely and see that they used to hold fine\n"+
  "works of art and various other treasures, but now are\n"+
  "empty and blasted by flame",
  "hole",
  "A gaping hole in the ceiling, it looks as though the\n"+
  "stone was torn loose by something huge and thrown to\n"+
  "the side",
  "anhk",
  "A large symbol carved from marble, you guess that before it\n"+
  "was broken it must have weighed close to 2 tons. The top half\n"+
  "is missing, but you see a metallic object hidden among the\n"+
  "broken stones on the wall where it would have stood. Small\n"+
  "holes also appear across the symbols surface",
  "holy symbol",
  "A large symbol carved from marble, you guess that before it\n"+
  "was broke it must have weighed close to 2 tons. The top half\n"+
  "is missing, but you see a metallic object hidden among the\n"+
  "broken stones on the wall where it would have stood. Small\n"+
  "holes also appear across the symbols surface",
  "walls",
  "You look closely and see that they were torn away by something\n"+
  "powerful and strewn about",
  "object",
  "Upon closer inspection it appears to be some type of lever,\n"+
  "obviously the symbol was mutilated in order to find it. You\n"+
  "might be able to 'push' it",
  "holes",
  "You look closely and see that they probably held small gems\n"+
  "or some such decorative stones",
  "ceiling",
  "You look at what is left of it and notice that it has a huge\n"+
  "hole torn into it",
  "skies",
  "Dark and foreboding, they are unnaturally dark."
});

dest_dir = ({
  "/players/maledicta/ruins/rooms/r8.c","north",
});

}

init(){
    ::init();
    
    add_action("secret_way", "push");
}


secret_way(string str){
      if(!str){ write("push what?\n"); return 1; }	
      if(str == "lever"){
       write("You push the small lever and watch as a small passage opens in the wall.\n");
       write("You enter.\n");
       say(tpn+" leaves secret.\n");
          move_object(tp, "/players/maledicta/ruins/rooms/r17.c");
          tell_room(environment(tp), tpn+" arrives.\n", ({tp}));
          command("look", tp);
          return 1;
        }
        write("That didn't seem to work.\n");
        return 1;
        }