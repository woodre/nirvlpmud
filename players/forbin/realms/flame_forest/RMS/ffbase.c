/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Realm:        Flame Forest
//  Function:     Room
//  Create Date:  2004.06.03
//  Last Edit:    2004.07.27 -Forbin
//  Notable Changes:
//    2004.07.27 -fixed a color problem in case 9, rd (there was a
//                +NORM that wasn't supposed to be there)
*/

#pragma combine_strings

#include "/players/forbin/realms/flame_forest/ffdefine.h"
inherit "/players/forbin/closed/std/flame_forest_baseroom.c"; 

reset(arg) {
  if(arg) return;
  short_desc = FLAMEFOREST;
  long_desc = get_random_descrip(); 
  set_light(1);
}

short() { return FLAMEFOREST; }

init() {
  ::init();
}

okay_follow() { return 1; }

get_random_descrip() {
  string rd; 
  object room;
  room = previous_object();
  switch(random(10)) {

    case 0: 
      rd = "  Scorched and burned, the forest floor bears the marks of a recent,\n"+
           "devastating fire.  A thin film of soot and ash blankets everything.\n"+
           "Slender shoots of delicate "+FWHP+" fight their way through to the\n"+
           "surface, struggling to compete against the many patches of "+PNX+".\n";
      room->add_item(({"floor","forest floor"}),
                     "The forest floor is covered in soot and ash, blanketing everything in\n"+
                     "a sea of black");
      room->add_item("forest",
                     "Burnt, skeletal trees tower tall above the forest floor");
      room->add_item("film",
                     "A thin layer of dark ash and soot covers everything");
      room->add_item("soot",
                     "Dark, grainy soot covers everything here");
      room->add_item("ash",
                     "Pieces of wide, black ash cover the forest floor");
      room->add_item(({"shoot","shoots","firewhip"}),
                     "A thin plant called "+FWHP+" grows in places - its slender, reed-like\n"+
                     "shoot dancing with the heat and wind");
      room->add_item(({"patch","patches","phoenix"}),
                     "Thick patches of "+PNX+" grass grow thickly all about the forest.\n"+
                     "Their thin, bright-red blades tangle together in thick mats");
      break;

    case 1:
      rd = "  Ozone hangs in the air, its acrid smell strong enough to make eyes\n"+ 
           "water and lungs burn.  The ground here is littered with the charred\n"+ 
           "stumps and burned remains of plant life.  A small grove of "+PROMET+"\n"+   
           "grows in a tight cluster, while trees tower tall into the sky above.\n";
      room->add_item("ground",
                     "The dark, sooty ground is covered with burned plants");
      room->add_item(({"stump","stumps"}),
                     "Charred stumps point to a recent fire");
      room->add_item("remains",
                     "Charred plant remains indicate a recent fire");
      room->add_item(({"grove","prometheus"}),
                     "Short and pasty-white, these round, bulbulous plants look like the\n"+
                     "only thing not affected by the fire");
      room->add_item("sky",
                     "Through sparse open places, you see dark clouds float slowly across\n"+
                     "the black-as-night sky");
      room->add_item(({"tree","trees"}),
                     "Darkened trees stretch high about this area, blocking most of the view\n"+
                     "of the sky above");
      room->add_smell("ozone",
                      "The air here has a funny, nostril-stinging odor.");
      break;

    case 2:
      rd = "  Particles of dust and ash float about on the wind.  The floor of the\n"+
           "forest is covered in a wash of black residue.  The smoke and smell of\n"+
           "smoldering wood wafts about.\n";  
      room->add_item(({"particle","particles"}),
                     "The wind blows pieces of dust and ash around the area");
      room->add_item("dust",
                     "Gray dust is suspended in the air");
      room->add_item("ash",
                     "Dark ash flutters about with the wind");
      room->add_item("floor",
                     "Covered in deep layers of ash, the forest floor is pitch black");
      room->add_item("forest",
                     "The forest canopy stretches high into the air above you, blocking any\n"+
                     "view of the sky");
      room->add_item(({"wash","residue","black residue","forest","forest floor"}),
                     "A layer of thin, black residue covers almost everything in this area");
      room->add_item("smoke",
                     "Dark gray-white smoke wafts through the air"); 
      room->add_item("wood",
                     "Several pieces of wood among the forest floor smolder smokily");
      room->add_smell("wood",
                      "The smoking wood smells faintly of burning hickory.");
      break;

    case 3:
      rd = "  Here the earth is scalded black from intense heat.  Peeking through\n"+ 
           "the ashen ground are several patches of "+DRWEED+".  The area is dark,\n"+
           "bathed in shade by the ever-present trees that tower above.\n";
      room->add_item(({"earth","ground"}),
                     "The ground is colored black from the heat of fires");
      room->add_item("ash",
                     "Splotches of ash dot the ground");
      room->add_item(({"patch","patches","weed","dragonweed"}),
                     "Tufts of "+DRWEED+" grow through the black earth, their bright red\n"+
                     "tips dance about their reddish bodies in the breeze");
      room->add_item("area",
                     "The area around this part of the forest appears constantly in shade");
      room->add_item("shade",
                     "It seems shadows blacken this part of the forest for most of the day");
      room->add_item(({"tree","trees"}),
                     "Stretching tall into the air, the trees have been scalded high up\n"+
                     "their sides from the frequent fires here");
      break;

    case 4:
      rd = "  The forest opens up onto a wide, rocky plain.  Large boulders and\n"+ 
           "rocks, all of them covered in a light layer of pitch-black ash and\n"+
           "soot, lie throughout the area.  Nothing grows in this place except\n"+
           "the surrounding trees.\n";
      room->add_item("forest",
                     "The forest is sparse, having a tough time growing in the rocky soil");
      room->add_item(({"plain","rocky plain"}),
                     "The terrain here is very rocky");
      room->add_item(({"boulder","boulders","large boulder","large boulders"}),
                     "Large boulders lay tossed about the area");
      room->add_item(({"rock","rocks"}),
                     "Rocks of all shapes, sizes, and types are scattered on the plain");
      room->add_item("layer",
                     "A layer of black ash and soot covers everything here");
      room->add_item("ash",
                     "Dark ash covers everything here in a thin layer");
      room->add_item(({"soot","area"}),
                     "Soot mixed with ash covers everything about this area");
      room->add_item(({"tree","trees"}),
                     "Many tress tower high around you, encircling the rocky area");
      break;
       
    case 5:
      rd = "  Thick, almost impenetrable forest surrounds the area.  The soil lies\n"+
           "darkened by the soot, while thick mats of red grass run around the\n"+ 
           "forest floor.  High above, different trees and their limber trails of\n"+
           "branches dance with the breeze.\n";
      room->add_item(({"forest","area"}),
                     "Closely packed trees tower upwards around this area");
      room->add_item("soil",
                     "The soil here is darkened black by soot");
      room->add_item("soot",
                     "The soot here has caused the soil to turn almost black");
      room->add_item(({"mat","mats","grass","floor","forest floor"}),
                     "Thick "+BACKD+" grass grows all about the forest.  The wide blades of\n"+
                     "grass all run in the same direction");
      room->add_item(({"tree","trees","different trees"}),
                     "Several different kinds of trees grow here, their branches in the wind");
      room->add_item(({"branch","branches"}),
                     "High above, thin branches hang and dance with the breeze");
      break;
       
    case 6:
      rd = "  The dark soil here lies hard-packed among the towering trees.  There\n"+
           "are signs of numerous fires around - a charred stump here, a burned\n"+
           "shell of a tree there.  Several scorched rocks are oddly scattered\n"+
           "about the area.\n"; 
      room->add_item("soil",
                     "The hard-pan soil is a dark gray");
      room->add_item(({"tree","trees"}),
                     "Many different kinds of trees tower towards the sky");
      room->add_item("sky",
                     "Now and them you glimpse bright pinpoints of light as dark clouds\n"+
                     "float through the black sky");
      room->add_item(({"light","pinpoint","pinpoints"}),
                     "Every so often, stars shine out, glistening against the night sky"); 
      room->add_item("stump",
                     "Burned and charred stumps litter the area");
      room->add_item(({"rock","rocks"}),
                     "The rocks in this area are blackened from fire"); 
      room->add_item("area",
                     "The area here looks to have seen a recent fire");
      break;

    case 7:
      rd = "  This area of the forest is strangely void of any trees, though many\n"+
           "different plants grow here.  The red grass covering this place in the\n"+
           "forest is caked in soot, giving it a dull shade of red.  The grass is\n"+
           "matted down in places, and there are signs of digging around the area.\n";
      room->add_item("area",
                     "Strangely, there are no trees growing in this place");
      room->add_item("forest",
                     "The forest here is thick with plants and bushes, but not any trees");
      room->add_item(({"plant","plants"}),
                     "Several different plants flourish in this area");
      room->add_item("grass",
                     "The red grass here looks blackened and dirty from soot"); 
      room->add_item("soot",
                     "Soot covers all of the plant life here in a thin layer");
      break;

    case 8:
      rd = "  A small "+FIRE+" smolders here, having consumed most of the\n"+
           "plant life in the area.  The charred and ashen remains of its\n"+
           "path lie everywhere around the land, scattered about by wind.\n";
      room->add_item(({"wildfire","fire"}),
                     "A small line of "+FIRE+" burns in the area");
      room->add_item("area",
                     "The area has been completely devastated by the "+FIRE+"");
      room->add_item("remains",
                     "Burnt and ashen remains of plant life litter the area");
      room->add_item("land",
                     "The land here has been consumed by a "+FIRE+"");
      break;

    case 9:
      rd = "  The slender beginnings of "+DWOOD+" trees poke through the ash\n"+
           "covered surface here.  What looks like footprints trace a confused\n"+
           "path around the area before heading into the deeper forest.\n";
      room->add_item(({"drakewood","tree","trees","drakewood tree","drakewood trees"}),
                     "Thin, gnarly trees, almost like dogwoods, grow in abundance here");
      room->add_item("ash",
                     "This area is covered in ash");
      room->add_item("surface",
                     "Ash covers every inch of the surface here");
      if(!random(3))
        room->add_item(({"footprint","footprints"}),
                       "Several footprints, almost humanoid in shape, traverse the area");
      else 
        room->add_item(({"footprint","footprints"}),
                       "The footprints of some strange animal cross the area");
      room->add_item("path",
                     "Footprints form a haphazard path before continuing into the forest");
      room->add_item("area",
                     "Everything except the "+DWOOD+" trees in this area is covered in ash"); 
      room->add_item("forest",
                     "The forest is thick and overgrown here");
      break;
  }

  if(!random(3))   
    room->add_smell("main",
                    "The acrid smell of smoke and fire chokes you.");
  else if(!random(3))
    room->add_smell("main", 
                    "You take a deep whiff of the pungent smokey air.");
  else
    room->add_smell("main",
                    "You get a lung full of choking smoke and ash.");

  if(!random(3))
    room->add_listen("main",
                     "The forest is deathly silent");
  else if(!random(3))
    room->add_listen("main",
                     "There is an eerie silence as soot and ash slowly drift to the ground.");
  else
    room->add_listen("main",
                     "You hear cracks, snaps and hisses from the charred forest.");
  return rd;
}


