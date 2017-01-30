#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(YEL+"Ruins of Khazad Naggrund"+NORM);
   set_long("\
At one time this was a fine kitchen, now all that remains of it is the \n\
faded outlines of the many stoves that once lined the wall.  The stoves\n\
were used as a makeshift barracade blocking the western doorway from the\n\
attackers.  Obviously it was a futile effort as the debris now litter the\n\
floor.  To the south there is a chiseled opening.\n");
   set_light(1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "outlines", "They mark the place were a great many stove or ovens once stood",
         "doorway", "Wide framed and now rusted hinges",
         "barracade", "It was destroyed ages ago by unknown means",
         "debris", "The shattered remains of the stoves litter the ground",
         "hinges", "These use to hold a great door in place, now they just collect rust",
         "hinge", "These use to hold a great door in place, now they just collect rust",
         "outline", "Faded from time but it clearly shows where the stoves and ovens once sat",
         "wall", "Covered in faded outlines of the stoves and ovens",
         "kitchen", "Once used to fix and prepare the meals for the dwarves now a ruin",
         "stoves", "Just a pilie of rubble now",
         "stove", "Just a pile of rubble now",
         "ovens", "Nothing remains but rubble",
         "oven", "Noting remains but rubble",
         "floor", "Debris lays littered about here",
         "remains", "Destroyed ovens and stoves",
         "ground", "Debris lays scattered about here",
         "opening", "Something large and strong must have smashed this open"});
   dest_dir = ({
         "players/khrell/area/underways/undermdh11.c", "west",
         "players/khrell/area/underways/undermdh14.c", "south"});
   move_object(clone_object("/players/khrell/monster/underways/golrnd.c"), this_object());
   return 1; }
