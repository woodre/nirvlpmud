/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Realm:        Flame Forest
 *  Function:     Room
 *  Create Date:  2004.06.03
 *  Last Edit:    2004.06.10 -Forbin
 *  Notable Changes:
 */

#pragma combine_strings

#include "/players/forbin/realms/flame_forest/ffdefine.h"
#include "/players/forbin/logging.h"
inherit "/players/forbin/closed/std/flame_forest_baseroom.c"; 

reset(arg) {
  if(!present("ff_mob") && !random(3)) add_object(NPC+"forestmob.c");
  if(!present("qei_t-uu_natas'h")) add_object(NPC+"qei.c");  
  if(arg) return;
  short_desc = FLAMEFOREST;
  long_desc = 
    "  The charred forest clears into a small opening as trees on both\n"+ 
    "sides grow thickly into a sheer cliff wall.  A wide set of stairs and\n"+
    "a waist high stone platform have been built against the cliff.  Set\n"+
    "atop the platform is a pair of huge pillars carved right from the very\n"+
    "stone of the cliff.  The ashen ground is void of any kind of growth.\n"+
    "The stars above cast a pale light across the area.\n";
  add_item("forest",
           "The forest, along with the cliff wall creates a safe, open area");
  add_item(({"tree","trees"}),
           "The trees grow right up closely to the cliff wall");
  add_item(({"cliff","wall","cliff wall"}),
           "Slick as glass, the cliff wall towers straight up into the sky\n"+
           "There are stairs leading up to a platform and some pillars");
  add_item("ground",
           "The ground is covered with a dark black ash");
  add_item("stars",
            "The stars shine brightly as small pinpoints of light");
  add_item("stairs",
           "Made of stone, they are deep and in good shape");
  add_item("platform",
           "Standing about waist high, it is made of stone and is huge");
  add_item(({"pillar","pillars"}),
           "These pillars are remarkable. They stand nearly as tall as eight men\n"+
           "and their girth is that of at least six men.  Looking carefully at\n"+
           "them you notice several runes covering the base of each.");
  add_item("runes",
           "You look carefully at them, and decide they might be readable");
  add_listen("main", 
             "A breeze whistles by your ear.\n");
  set_light(1);
  if(!random(3)) add_property("NT");
  add_exit(RMS+"ff06_09","east");
}

query_ffroom() { return 1; }

short() { 
  int i;
  string sh;
  if(set_light(0) > 0) { 
    if(this_player()) {
      if(!environment(this_player())->query_ffroom() && this_player()->query_level() < 40) return HBRED+HIW+FLAMEFOREST+NORM+NORM; 
      else { 
        sh = HBRED+HIW+short_desc+HBRED+HIW+" [";
        if(!dest_dir || no_exits) sh += "no exits";
        else {
          for(i=1; i<sizeof(dest_dir); i+=2) {
            sh += translate_exit(dest_dir[i]);
            if (i < sizeof(dest_dir)-2) sh += ",";
          }
        }
        sh += HBRED+HIW+"]";
        return sh+NORM+NORM; 
      }
    }
    else return HBRED+HIW+FLAMEFOREST+NORM+NORM;   
  }
  else return "Dark room";     
}

init() {
  ::init();
  add_action("cmd_read","read");
  add_action("cmd_invoke","invoke");
}

okay_follow() { return 1; }

cmd_read(string str) {
  if(!str || (str != "pillar" && str != "pillars" && str != "rune" && str != "runes")) { return 0; }
  write("You begin to try and translate the runes...\n");
  call_out("finish_read", 3, this_player()); 
  return 1;   
}

finish_read(object ob) {
  if(!present(ob)){ return 1; } 
  tell_object(ob, "You find that you can now 'invoke runes', using them as\n"+
                  "a portal of some sort.\n");
}

cmd_invoke(string str) {
  string who;
  string lev, xlev;
  if(!str) { write("invoke what?\n"); return 1; } 
  if(str == "runes")
  {
    write(" The pillars shimmer, energy begins to criss-cross between them....\n");
    write(HIW+"             _________             _________\n");
    write(HIW+"             |       |             |       |\n");
    write(HIW+"             |       |             |       |\n");
    write(HIW+"             '| ||| |'             '| ||| |'\n");
    write(HIW+"              | ||| |"+HIM+"///////////////"+HIW+"| ||| |\n"); 
    write(HIW+"              | ||| |"+HIM+"///////////////"+HIW+"| ||| |\n");
    write(HIW+"              | ||| |"+HIM+"///////////////"+HIW+"| ||| |\n");
    write(HIW+"              | ||| |"+HIM+"///////////////"+HIW+"| ||| |\n");
    write(HIW+"              | ||| |"+HIM+"///////////////"+HIW+"| ||| |\n");
    write(HIW+"              | ||| |"+HIM+"///////////////"+HIW+"| ||| |\n");
    write(HIW+"              | ||| |"+HIM+"///////////////"+HIW+"| ||| |\n");
    write(HIW+"              | ||| |"+HIM+"///////////////"+HIW+"| ||| |\n");
    write(HIW+"              | ||| |"+HIM+"///////////////"+HIW+"| ||| |\n");
    write(HIW+"              | ||| |"+HIM+"///////////////"+HIW+"| ||| |\n");
    write(HIW+"             _|_____|_............._|_____|_"+NORM+"\n\n");
    write("You step through and....\n\n");      
    write("      Find yourself elsewhere.....\n\n");
    say(TPN+" disappears suddenly.\n");
    move_object(TP, "/players/forbin/realms/ruins/RMS/r01.c");
    tell_room(environment(TP), TPN+" arrives.\n", ({TP}));
    command("look", TP);
/*
#ifdef RUINSLOG
  log_this(RUINSLOG, "entered The Ruins.");
#endif
*/
      return 1;
  }
  write("invoke what?\n");   
    return 1;
}
