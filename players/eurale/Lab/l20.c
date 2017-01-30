#include "DEFS.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "Labyrinth";
long_desc =
  "  In the ceiling above is a small hole leading up.  The walls here are\n"+
  "wet and give off a foul odor.  Rust-colored lines run vertically\n"+
  "from ceiling to floor on the black walls.  The smelly liquid runs\n"+
  "down the walls and then eastward along the stone floor until it\n"+
  "disappears into the darkness.\n";

items = ({
  "hole","Too high to reach, if one were lucky they might be able to\n"+
         "jump and reach it",
  "walls","Black and smooth, the rock seems only to have been affected\n"+
          "by the liquid running down it",
  "lines","Discoloration caused by some chemical on the rock",
  "liquid","It looks like a dark green but it's hard to tell in the\n"+
           "darkness surrounding you",
  "floor","Solid rock with a small gutter-type grove along its north "+
          "wall",
  "darkness","Pitch black with no discernable outlines",
});

dest_dir = ({
  "players/eurale/Lab/l21.c","east",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("East","east");
  add_action("Search","search");
  add_action("Jump","jump");
}

East() {
if(random(28) > TP->query_attrib("luc") && !present("hcl",TP)) {
  write("You carefully move eastward but brush the wall and feel\n"+
        "a sting as the foul smelling liquid touches your skin.\n\n");
  move_object(clone_object("/players/eurale/Lab/OBJ/acid"),TP);
  write_file("/players/eurale/Lab/LOGS/acid",ctime(time())+"  "+
    capitalize(TPRN)+" was burned by the wall acid.\n");
  TP->move_player("east#players/eurale/Lab/l21.c");
  return 1; }
else TP->move_player("east#players/eurale/Lab/l21.c");
return 1;
}

Search(str) {
if(!str) { write("What?\n"); return 1; }
write("You search the "+str+" but find nothing of interest.\n");
return 1;
}

Jump() {
if(random(28) > TP->query_attrib("luc")) {
  write("You jump with all your might but your fingers slip off...\n"+
        "and you fall back and hurt yourself.\n\n");
  TP->hit_player(-random(20));
  return 1; }
write("You jump with all your might and just catch hold of the edge\n"+
      "above... pulling yourself up from the darkness below.\n\n");
TP->move_player("up#players/eurale/Lab/l19.c");
return 1;
}
