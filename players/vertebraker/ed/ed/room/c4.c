okay_follow() { return 1; }
#include "/players/vertebraker/define.h"
#include "/players/vertebraker/ed/paths.h"
inherit ROOM;
int undone,opened;
reset(arg) {
    if(arg) return;
    set_light(1);
    short_desc = "Sitting room";
    long_desc =
"     A large, warming fireplace has been built into the side of the wall,\n"+
"providing the household with adequate-enough heat for the surrounding \n"+
"area.  A small trapdoor lies in the middle of the floor, linked to this\n"+
"floor through a series of small metal chains tied to it.  A variety of\n"+
"paintings can be viewed on the walls, as well as a few windows on the\n"+
"western wall on the sides of the fireplace.\n";
  items = ({
"chains","These chains appear like they can be 'undo'ne to allow entrance to the\n"+
"catacombs beneath...",
"fireplace","A large, stone-hewn fireplace stands alongside the wall.\n"+
"A blaze rages within",
"blaze","The blaze seems to yearn for you to 'burn' something....",
"wall","The wooden wall stands in contrast to the fireplace housed on the side of the wall",
"trapdoor","The trapdoor can be 'open'ed and 'enter'ed through, it appears...",
"paintings","Sumerian war pastels and photos of Condarian ruins have been framed and hung here",
"windows","You can see the dark forests outside",
"forests","It is too dark to make out anything",
});
dest_dir = ({
ED1ROOM+"c1","north",
ED1ROOM+"c5","east",
ED1ROOM+"c7","south",
});
    }
init() {
  ::init();
  add_action("open","open");
  add_action("enter","enter");
  add_action("undo","undo");
  add_action("search","search");
}

open(arg) {
  if(!arg) { write("Open what?\n"); return 1; }
  if(arg == "trapdoor") {
    if(undone == 0) { write("You need to undo the chains first!\n"); return 1; }

    write("You open the trapdoor.\n");
    say(TPN+" opens up the trapdoor.\n");
    opened = 1;
    return 1; }
}

enter(arg) {
  if(!arg) { write("Enter what?\n"); return 1; }
  if(arg == "trapdoor") {
    if(!opened) { write("You need to open the trapdoor first!\n"); return 1; }
    write("You descend into the basement....\n");
    say(TPN+" descends into the basement....\n");
    TP->move_player("beneath the trapdoor#"+ED1ROOM+"b1");
    return 1; }
  }

undo(arg) {
  if(!arg) { write("Undo what?\n"); return 1; }
  if(arg == "chains") {
    write("You undo the chains on the trapdoor....\n");
    say(TPN+" unties the chains on the trapdoor....\n");
    undone = 1;
    return 1; }
  }

search(arg) {
    if(!arg) { write("Your general search of the area turns up nothing.\n"); return 1; }
    if(arg) { write("You search "+arg+", but you turn up nothing.\n"); return 1;
 }
    return 1; }

realm() { return "NT"; }
