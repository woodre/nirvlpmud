/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Realm:        Flame Forest
 *  Function:     Standard room inherit
 *  Create Date:  2002.01.31
 *  Last Edit:    2004.01.29 -Forbin
 *  Notes:        Totally rewritten
 *  Notable Changes:
 */ 

#pragma combine_strings

#include "/players/forbin/realms/flame_forest/ffdefine.h"
inherit "/players/forbin/closed/std/mod_vroom.c";

string pe; /* possible exits */
string rd; /* random description */

get_random_descrip() {
  switch(random(10)) {

    case 0: 
      rd = "  Scorched and burned, the forest floor bears the marks of a recent,\n"+
           "devastating fire.  A thin film of soot and ash blankets everything.\n"+
           "Slender shoots of delicate "+FWHP+" fight their way through to the\n"+
           "surface, struggling to compete against the many patches of "+PNX+".\n";
      add_item("floor",
               "The forest floor is covered in soot and ash");
      add_item("forest",
               "Burnt, skeletal trees tower tall above the forest floor");
      add_item("film",
               "A thin layer of ash and soot covers everything");
      add_item("soot",
               "Dark soot covers everything here");
      add_item("ash",
               "Grainy, black ash covers the forest floor");
      add_item(({"shoot","shoots","firewhip"}),
               "The thin plant called "+FWHP+" grows in places");
      add_item(({"patch","patches","phoenix"}),
               "Thick patches of "+PNX+" grass grow all about");
      break;

    case 1:
      rd = "  Ozone hangs in the air, its acrid smell strong enough to make eyes\n"+ 
           "water and lungs burn.  The ground here is littered with the charred\n"+ 
           "stumps and burned remains of plant life.  A small grove of prometheus\n"+   
           "grows in a tight cluster, while trees tower tall into the sky above.\n";
      add_item("ground",
               "The dark, sooty ground is covered with burned plants");
      add_item(({"stump","stumps"}),
               "Charred stumps point to a recent fire");
      add_item("remains",
               "Charred plant remains point to a recent fire");
      add_item(({"grove","prometheus"}),
               "Short and pasty-white, these round, bulbulous plants look like the only\n"+
               "thing not affected by the fire");
      add_item("sky",
               "Dark clouds float through the black as night sky");
      add_item(({"tree","trees"}),
               "Darkened trees stretch high around this area");
      add_smell("ozone",
                "The air here has a funny nostril-stinging odor.");
      break;

    case 2:
      rd = "  Particles of dust and ash float about on the wind.  The floor of the\n"+
           "forest is covered in a wash of black residue.  The smoke and smell of\n"+
           "smoldering wood wafts about.\n";  
      add_item(({"particle","particles"}),
               "The wind blows pieces of dust and ash around");
      add_item("dust",
               "Gray dust is suspended in the air");
      add_item("ash",
               "Dark ash flutters about with the wind");
      add_item("floor",
               "Covered in deep layers of ash, the forest floor is pitch black");
      add_item("forest",
               "The forest canopy stretches high into the air above you");
      add_item(({"wash","residue","black residue"}),
               "A layer of thin, black residue covers almost everything in this area");
      add_item("smoke",
               "Dark gray-white smoke wafts through the air"); 
      add_item("wood",
               "Several pieces of wood about the floor smolder smokily");
      break;

    case 3:
      rd = "  Here the earth is scalded black from intense heat.  Poking through\n"+ 
           "the ashen ground are several patches of dragonweed.  The area is dark,\n"+
           "bathed in shade by the ever-present trees.\n";
      add_item(({"earth","ground"}),
               "The ground is colored black from the heat of fires");
      add_item("ash",
               "Splotches of ash dot the ground");
      add_item(({"patch","patches","weed","dragonweed"}),
               "Tufts of "+DRWEED+" grow through the black earth");
      add_item("area",
               "The area around this part of the forest is constantly in shade");
      add_item("shade",
               "Shade blackens this part of the forest for most of the day");
      add_item(({"tree","trees"}),
               "Stretching high into the air, the trees have been scalded high up\n"+
               "them from the frequent fires here");
      break;

    case 4:
      rd = "  The forest opens up onto a wide, rocky plain.  Large boulders and\n"+ 
           "rocks, all of them covered in a light layer of pitch-black ash and\n"+
           "soot, lie throughout the area.  Nothing grows in this place except\n"+
           "the surrounding trees.\n";
      add_item("forest",
               "The forest is sparse, having a tough time growing in the rocky soil");
      add_item(({"plain","rocky plain"}),
               "The terrain here is very rocky");
      add_item(({"boulder","boulders","large boulder","large boulders"}),
               "Large boulders lay tossed about the area");
      add_item(({"rock","rocks"}),
               "Rocks of all shapes, sizes, and types are scatter on the plain");
      add_item("layer",
               "A layer of black ash and soot covers everything here");
      add_item("ash",
               "Dark ash covers everything here in a thin layer");
      add_item(({"soot","area"}),
               "Soot mixed with ash covers everything about this area");
      add_item(({"tree","trees"}),
               "Many tress tower high around you, encircling the rocky area");
      break;
       
    case 5:
      rd = "  Thick, almost impenetrable forest surrounds the area.  The soil lays\n"+
           "darkened by the soot, while thick mats of red grass run around the\n"+ 
           "forest floor.  High above, different trees and their limber trails of\n"+
           "branches dance with the breeze.\n";
      add_item(({"forest","area"}),
               "Closely packed trees tower upwards around this area");
      add_item("soil",
               "The soil here is darkened black by soot");
      add_item("soot",
               "The soot here has caused the soil to turn almost black");
      add_item(({"mat","mats","grass","floor","forest floor"}),
               "Thick "+BACKD+" grass grows all about the forest");
      add_item(({"tree","trees","different trees"}),
               "Several different kinds of trees grow here, their branches in the wind");
      add_item(({"branch","branches"}),
               "High above, thin branches hang and dance with the breeze");
      break;
       
    case 6:
      rd = "  The dark soil here lies hard-packed among the towering trees.  There\n"+
           "are many signs of numerous fires here - a charred stump here, a burned\n"+
           "shell of a tree there.  Several scorched rocks are oddly scattered\n"+
           "about the area.\n"; 
      add_item("soil",
               "The hard-pan soil is almost black");
      add_item(({"tree","trees"}),
               "Many different kinds of trees tower towards the sky");
      add_item("sky",
               "Dark clouds float through the black as night sky");
      add_item("stump",
               "Burned and charred stumps litter the area");
      add_item(({"rock","rocks"}),
               "The rocks in this area are blackened as if from fire"); 
      add_item("area",
               "The area here looks to have seen a recent fire");
      break;

    case 7:
      rd = "  This area of the forest is strangely void of any trees, though many\n"+
           "different plants grow here.  The red grass covering this place in the\n"+
           "forest is caked in soot, giving it a dull shade of red.  The grass is\n"+
           "matted down in places, and there are signs of digging around the area.\n";
      add_item("area",
               "Strangely, there are no trees growing in this place");
      add_item("forest",
               "The forest here is thick with plants and bushes, but not any trees");
      add_item(({"plant","plants"}),
               "Several different plants flourish in this area");
      add_item("grass",
               "The red grass here looks blackened and dirty from soot"); 
      add_item("soot",
               "Soot covers all of the plantlife here in a thin layer");
      break;

    case 8:
      rd = "  A small wildfire burns here, consuming most of the plant life in the\n"+
           "area.  The charred and ashed remains of its path lie everywhere around\n"+
           "the land, scattered about by the wind.\n";
      add_item(({"wildfire","fire"}),
               "A small line of fire burns in the area");
      add_item("area",
               "The area has been completely devastated by the "+FIRE+"");
      add_item("remains",
               "Burnt and ashen remains of plantlife litter the area");
      add_item("land",
               "The land here has been consumed by fire");
      break;

    case 9:
      rd = "  The slender beginnings of drakewood trees poke through the ash\n"+
           "covered surface here.  What looks like footprints trace a confused\n"+
           "path around the area before heading into the deeper forest.\n"+NORM;
      add_item(({"drakewood","tree","trees","drakewood tree","drakewood trees"}),
               "Thin, gnarly trees, almost like dogwoods, grow in abundance here");
      add_item("ash",
               "This area is covered in ash");
      add_item("surface",
               "Ash covers every inch of the surface here");
      if(!random(3))
        add_item(({"footprint","footprints"}),
                 "Several footprints, almost humanoid in shape, traverse the area");
      else 
        add_item(({"footprint","footprints"}),
                 "The footprints of some strange animal cross the area");
      add_item("path",
               "Footprints form a haphazard path before continuing into the forest");
      add_item("area",
               "Everything except the "+DWOOD+" trees in this area is covered in ash"); 
      add_item("forest",
               "The forest is thick and overgrown here");
      break;
  }

  if(!random(3))   
    add_smell("main",
              "The acrid smell of smoke and fire chokes you.");
  else if(!random(3))
    add_smell("main", 
              "You take a deep whiff of the pungent smokey air.");
  else
    add_smell("main",
              "You get a lungfull of choking smoke and ash.");

  if(!random(3))
    add_listen("main",
               "The forest is deathly silent");
  else if(!random(3))
    add_listen("main",
               "There is an eerie silence as soot and ash slowly drift to the ground.");
  else
    add_listen("main",
               "You hear cracks, snaps and hisses from the charred forest.");
}

