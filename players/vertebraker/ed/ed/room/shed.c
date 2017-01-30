okay_follow() { return 1; }

#include "/players/vertebraker/define.h"
#include "/players/vertebraker/ed/paths.h"
inherit ROOM;
int took_hatchet,pried_cabinet,oops;
reset(arg) {
    if(arg) return;
    set_light(1);
    short_desc = "Inside an old shed";
    long_desc =
"    You stand inside what appears to be an old tool shed, obviously a\n"+
"complement to the cabin next door.  A myriad assortment of shelves,\n"+
"cupboards, and boxes dominate the area.  There is a large table on\n"+
"the right-hand side, covered with what appear to be strong, unyielding\n"+
"iron chains and fasteners.  There is an assortment of axes, knives, and\n"+
"general chopping-tools mounted on the left-hand wall.  There is a cord\n"+
"dangling from the center of the ceiling.\n";
items = ({
  "shelves","There are several wooden shelves built into a large cabinet",
  "cabinet","The large wood-grain cabinet is well-built and contains many shelves",
  "cupboards","Most of the cupboards are open.  There is one that you may be able to 'pry' open",
  "boxes","Opened cardboard boxes lie on the ground, detailing an assortment of old, rusty tools",
  "chains","Corroded iron chains cling to the table",
  "fasteners","The chains are tied onto the table with strong steel fasteners",
  "chopping-tools","Axes, knives, and other blades are mounted on the wall",
  "axes","Most of the axes look old and useless.  There is a particularly sharp one on the wall, however",
  "axe","There is a sharp hatchet on the wall you may be able to 'grab' off of the mount",
  "cord","The pull-cord is connected to an unshielded light bulb on the ceiling",
  "ceiling","The cracked ceiling reveals poor architecture.  There is a small light bulb in the center",
  "bulb","The light bulb on the ceiling gives off a faint glow",
  "table","The long iron table is covered with chains and fasteners.  You wonder what its purpose is",
"tools","An assortment of tools lie in the boxes",
});
if(!present("ash",TO)) MOCO(ED1MOB+"ash"),TO);
dest_dir = ({
ED1ROOM+"o2","out",
});
}

init() {
    ::init();
    add_action("light_room","pull");
    add_action("grab_hatchet","grab");
    add_action("pry_cabinet","pry");
    add_action("search","search");
    add_action("wall","wall");
}

light_room(arg) {
    if(arg == "cord") {
        if(!oops) {
            write("You tug the cord, and it breaks off.  Way to go.\n");
            say(TPN+" tugs on the lightbulb's cord and it breaks off!\n");
            MOCO(ED1OBJ+"shed_cord"),TO);
            oops = 1;
            return 1; }
        if(oops) {
            write("What?\n");
            return 1; }
        return 1; }
    return 1; }

grab_hatchet(arg) {
    if(arg == "hatchet") {
        if(!took_hatchet) {
  if(present("ash",TO)) { write("Ash says: 'I don't think so baby...'\n"); return 1; }
            write("You snatch the hatchet off of its holster on the wall.\n");
            say(TPN+" grabs a hatchet from the wall.\n");
            MOCO(ED1OBJ+"hatchet"),TP);
            took_hatchet = 1;
            return 1; }
        if(took_hatchet) {
            write("Ugh!  The one you have seen can't be taken after all!\n");
            return 1; }
        return 1; } 
    }

pry_cabinet(arg) {
        if(arg == "cupboard") {
        if(!pried_cabinet) {
if(present("ash",TO)) { write("Ash says: 'I don't think so baby.'\n"); return 1; }
            write("You burst open the cabinet and dump the contents on the floor.\n");
            say(TPN+" opens the cabinet.\n");
            MOCO(ED1OBJ+"gas_can"),TO);
            MOCO(ED1OBJ+"receipt"),TO);
            pried_cabinet = 1;
            return 1; }
        if(pried_cabinet) {
            write("You burst open the cabinet but find nothing.\n");
            say(TPN+" opens the cabinet.\n");
            return 1; }
    return 1; }
}

wall() {
  if(present("ash",TO)) {
    write("What?\n"); return 1; }
  TP->move_player("behind the wall#/players/vertebraker/ed/ed/room/portal");
  return 1; }
realm() { return "NT"; }

search(arg) {
    if(!arg) { write("Your general search of the area turns up nothing.\n"); return 1; }
    if(arg) { write("You search "+arg+", but find nothing.\n"); return 1; }
    return 1; }

get_outta_here() {
  dest_dir = ({
ED1ROOM+"o2","out",
ED1ROOM+"portal","wall",
});
  }
