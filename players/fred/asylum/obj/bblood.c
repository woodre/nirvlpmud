inherit "/obj/generic_heal.c";
#include <ansi.h>

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("blood");
  set_short("Bat's blood");
  set_long(
     "  A small vein from a bat that still contains some blood.\n"+
     "You might be able to drink the small amount of blood that is\n"+
     "still contained in it.\n");
  set_type("drink");
  set_msg(
     "  You drink a few drops of the thick blood and feel it racing\n"+
     "through your veins. You hack and wheeze in disgust.\n");
  set_msg2(
     " drinks some bat's "+BOLD+RED+"blood"+NORM+".\n");
  add_cmd("drink");
  set_heal(50,50);
  set_charges(2);
  set_intox(6);
  set_value(1100);
}

short(){ return "Bat's "+BOLD+RED+"blood"+NORM+BOLD+" ["+BLK+charges+NORM+BOLD+"]"+NORM; }
