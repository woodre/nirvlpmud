/*
 * The purpose of this object is to house basic functionality used by the smart monsters.
 * Contents personal copyright Mizan@Nirvana, 2003.
 * Exclusive rights also to Boltar@Nirvana.
 * Reproduction on other muds restricted, under penalty of personal retribution.
 *
 */

inherit "/players/mizan/core/object.c";
#include "/obj/ansi.h"

string my_color;

reset(arg)
{
   ::reset(arg);
   if(arg) return;

   set_get(0);
   set_weight(100000);

   set_short(HIW + "A large, well-lit sign" + NORM);
   set_name("sign");

   set_long("This is a large sign, well-lit and borderline obnoxious in size.\n"+
            "It points to a gigantic open lot to the west.\n"+
            "Perhaps you are able to 'read' it.\n");

   set_read("The following information can be read:\n"+
            "\n"+ HIW +
            "233 Lance Road - New Office Complex Construction - 1,560,000 sqft.\n"+
            "Future home and offices of the Monsters' Guild; Monster Inc.\n"+
            "Architect: Skidmore, Owings & Merrill LLP.\n"+
            "Contractors: Turner Construction Corporation, New York City.\n"+ NORM +
            "Financiers: Spuck Heavy Industries, JP Morgan Chase Manhattan.\n"
            );
   set_smell("The sign smells like... plywood.\n");
   set_taste("The sign tastes like... plywood.\n");

   move_object(this_object(), "room/lanceroad3");
}

init()
{
    ::init();
    add_action("on_west","west");
}

on_west()
{
    write("Unfortunately, you cannot go there yet.\n");
    return 1;
}