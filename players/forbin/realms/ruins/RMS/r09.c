/*Here is a hidden passage leading into another part of the ruins. Use is 'push lever'
  and character is transported to r17.c    */
#include "/players/forbin/realms/ruins/ruinsdefine.h"
inherit "/players/forbin/closed/std/room.c";

reset(arg) {
  object angel;
  if(!present("archangel")) {
    angel = clone_object(NPC+"angel.c");
    angel->set_up(26, 15, "ice", "ice_fork.c", "fork");
    move_object(angel, this_object()); 
  }
  if(!present("mane")) {
    move_object(clone_object(NPC+"shadowmane.c"), this_object()); 
  }  
  if(arg) return;
set_light(1);

short_desc = RUINS;
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
  RMS+"r08.c","north",
});

}

query_ruinsroom() { return 1; }

short() { 
  int i;
  string sh;
  if(set_light(0) > 0) { 
    if(this_player()) {
      if(!environment(this_player())->query_ruinsroom() && this_player()->query_level() < 40) return HIW+RUINS+NORM; 
      else { 
        sh = HIW+short_desc+" ["+NORM;
        if(!dest_dir || no_exits) sh += "no exits";
        else {
          for(i=1; i<sizeof(dest_dir); i+=2) {
            sh += translate_exit(dest_dir[i]);
            if (i < sizeof(dest_dir)-2) sh += ",";
          }
        }
        sh += HIW+"]";
        return sh+NORM; 
      }
    }
    else return HIW+RUINS+NORM;   
  }
  else return "Dark room";     
}

init()
{
  ::init();
  add_action("secret_way", "push");
}


secret_way(string str)
{
  if(!str){ write("push what?\n"); return 1; }  
  if(str == "lever")
  {
    write("You push the small lever and watch as a small passage opens in the wall.\n");
    write("You enter.\n");
    say(TPN+" leaves secret.\n");
    move_object(TP, RMS+"r17.c");
    tell_room(environment(TP), TPN+" arrives.\n", ({TP}));
    command("look", TP);
      return 1;
  }
  write("That didn't seem to work.\n");
    return 1;
}