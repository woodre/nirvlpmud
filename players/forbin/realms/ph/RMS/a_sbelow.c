/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Realm:        Phish - Fee Area
//  Function:     Room
//  Create Date:  2004.09.02
//  Last Edit:    2004.09.02 -Forbin
//  Notable Changes:
*/

#include "/players/forbin/realms/ph/phdefine.h"
inherit "/players/forbin/closed/std/room.c";

#define SHORT "The C.S.S. "+HIR+"Quebecois"

reset(arg) {
  if(arg) return;
  short_desc = SHORT;
  long_desc = 
    "A sprawling monastery stands on a mountain clearing.  Situated on\n"+
    "a rocky plain, the entire compound is surrounded by a high stone\n"+
    "wall except for a large entryway.  A wide expanse of steps dozens\n"+
    "of treads high leads up to a long stone platform, where thick\n"+
    "columns support a thatched roof and provide protection from the\n"+
    "elements for the massive set of double doors that lead inside.\n";
  set_light(1);
  add_item(({"monastery","compound"}),
    "The tops of buldings peek above the encircling stone wall.  Most of\n"+
    "architecture looks similar to the main entryway.  Flags and penants\n"+
    "flap noisily about in the breeze");
  add_item(({"flag","flags","penant","penants"}),
    "A multitude of colorful strips of fabric dance upon the rooftops in\n"+
    "the strong breeze, snapping and popping loudly"); 
/*  add_item(({"wall","stone wall"}),
    "");
  add_item(({"platform","stone platform"}),
    "");    
  add_item("stone",
    "");     
  add_item(({"step","steps","tread","treads"}),
    "");  */
  add_item(({"column","columns","thick column","thick columns"}),
    "Colossal columns three feet in diameter and 15 feet high carry a\n"+
    "thatched roof that spans the stone entryway.  One of the columns has\n"+
    "a cut-through that has a small gong hanging in it");
  add_item("gong",
    "A small, circular gong is tied within a small cut-through in one of\n"+
    "the large columns.  A batton one could strike it with rests nearby");
  add_item(({"roof","thatched roof"}),
    "A brown thatch roof that looks in superb conditioning, considering\n"+
    "the apline environment of the monastery");    
  add_item("mountain",
    "The horizon seems peculiarly close as the plain falls off down the\n"+
    "side of the mountain top.  As far as you can see, clouds shroud most\n"+
    "of the surrounding mountain peaks from view");
  add_item(({"cloud","clouds"}),
    "White, puffy clouds hang in the crystal blue sky, preventing you from\n"+
    "catching glimpses of the surrounding mountains");    
  add_item(({"plain","clearing","rocky plain","rock","rocks"}),
    "The ground about the rocky plain is fairly smooth, with most of the\n"+
    "small rocks and loose dirt carried away by the ever-present wind.\n"+
    "The rocks left in the area are mostly brown and oddly smooth");
  set_chance(3);
    add_msg("A strong wind rips across the area.");
    add_msg("Beautiful chimes bathe the monastery with a sweet sound");
    add_msg("Dirt and loose sand blow across the ground.");
  add_listen("main", 
    "Wind whips across the rocky plain.\n");
  add_listen("wind",
    "A roaring wind floats across the area from the southwest.\n");
  add_smell("main", 
    "The sweet smell of jasmine and vanilla hang in the air.\n"); 
  add_smell("jasmine",
    "You catch a strong whiff of jasmine.  It seems to be coming from\n"+
    "within the monastery.\n");
  add_smell("vanilla",
    "The scent of vanilla floats out from the monastery doors.\n");
  add_exit(RMS+"a_sdeck","deck");
  add_exit(RMS+"a_sclub","enter"); 
  add_property("NT");
}

okay_follow() { return 1; }

query_phroom() { return 1; }

query_ph_fee_room() { return 1; }

short() { 
  int i;
  string sh;
  if(set_light(0) > 0) { 
    if(this_player()) {
      if(!environment(this_player())->query_ph_fee_room() && this_player()->query_level() < 40) return HIW+SHORT+NORM; 
      else { 
        sh = HIW+short_desc+HIW+" ["+NORM;
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
    else return HIW+SHORT+NORM;   
  }
  else return "Dark room";     
}
