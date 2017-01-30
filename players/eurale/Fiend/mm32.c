#include "DEFS.h"
inherit "room/room";
int g;  /*  floor drain grating  0-off, 1-on  */
int h;

reset(arg) {
g = 1;
h = 1;
if(!present("jekyll")) {
  move_object(clone_object("players/eurale/Fiend/NPC/jekyll"),TO); }
  if(arg) return;
set_light(1);

short_desc = "Fiendsville";
long_desc =
	"  This is the operating room of the lab.  In the center is a\n"+
	"stainless steel table with bright lights overhead.  Tables on\n"+
	"wheels carry the surgical instruments.  More monitoring equip-\n"+
	"ment is visible around the room and there is a grate covering\n"+
	"a hole in the floor.\n";

items = ({
	"table","A stainless table with small sides and drain holes in\n"+
		"each corner to allow blood run-off",
	"instruments","Saws, clamps, needles and scalpels",
	"equipment","A heart monitor and blood pump along with blood\n"+
		"pressure indicators",
	"grate","A small chrome grate covering the floor drain to stop\n"+
		"items from going in the drain when the room is hosed \n"+
		"down after some messy surgery.  It looks like you might\n"+
		"be able to remove it",
	"hole","The floor drain",
});

dest_dir = ({
	"players/eurale/Fiend/mm31.c","north",
});

}

init() {
  ::init();
  add_action("remove","remove");
  add_action("search","search");
  TP->set_fight_area();
}

remove(str) {
if(!str) { write("What are you trying to remove?\n"); return 1; }
if(str == "grate") {
if(present("jekyll")) {
  write("Dr. Jekyll says: What the devil are you doing?\n");
  return 1; }

if(g == 0 && !present("jekyll")) {
  write("The grate has already been removed.\n"); return 1; }
if(g == 1 && !present("jekyll")) {
  write("You remove the grate covering the floor drain.\n");
  g = 0;
  return 1; }
 return 1; }
}

search(str) {
if(str == "floor") {
  write("The floor is clean, keep looking!\n"); return 1; }
if(str == "grate") {
  write("The grate is loose, I'm sure you could remove it.\n"); return 1; }
if(!str) { write("What would you like to search?\n"); return 1; }
if(str == "drain") {
if(present ("jekyll")) {
  write("Dr. Jekyll remarks: Quit fooling around in here!\n");
  return 1; }
if(g == 1 && !present("jekyll")) {
  write("Sorry, the drain is covered by the grate.  You'll have to\n");
  write("remove it first..\n");
  return 1; }
if(g == 0 && h == 0 && !present("jekyll")) {
  write("You search through the dead tissue and muck and find nothing.\n");
  return 1; }
if(g == 0 && !present("jekyll") && h == 1) {
  write("You search through the disgusting muck and find a hand.\n");
  move_object(clone_object("players/eurale/Fiend/OBJ/hand"),TP);
  h = 0;
  return 1; }
 return 1; }
}
