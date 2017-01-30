/*
 *  The initial Bardsword for the Storm Bards of Ryllian.
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

#include "/players/saber/closed/esc2.h"
#include "/players/saber/closed/ansi.h"

inherit "obj/weapon.c";

#define TO this_object()
#define tp this_player()->query_name()
#define ENV environment(this_player())

string LONG_START;
int WHICH;

reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("bardsword");
    set_alias("sword");
    set_short("A "+BOLD+"Storm-Crystal"+NORM+" Bardsword");
    set_long();
    set_read("The blade was forged for the Bards Guild of Ryllian.\n");
    set_class(16);
    set_weight(2);
    set_value(1000);
    set_hit_func("/players/saber/closed/bard/itm/w/type1.c");
        }


long()  {
        write(LONG_START+".\n"+
        "It's weight is like the wind, and it has an edge like lightning.\n"+
        "On the hilt are both the "+BOLD+"Rune of Crysea"+NORM+" and the "+
        BOLD+"Bardic Rune"+NORM+".\n"+
        "You can < Tune > your bardsword.\n");
        }


init()  {
  ::init();
  if(present("instrument", this_player())); add_action("tune_sword","Tune");
        }


tune_sword(str)  {

  if(!str)  {
    write("\nYou can tune your Bardsword to:\n\n");
    write("\tA\t\tStorm Crystal Bardsword\n");
    write("\tB\t\tClassic Bardsword\n");
    write("\tC\t\tXmas Bardsword\n");
    write("\tD\t\tDark Crystal Bardsword\n");
    write("\nTo tune your Bardsword, type: Tune <Note>\n\n");
    return 1;
        }

  str = capitalize(str);

switch(str)  {

  case "A" : 
          TO->set_short("A "+BOLD+"Storm-Crystal"+NORM+" Bardsword");
          LONG_START = "A translucent grey longsword of gleaming storm crystal";
          TO->set_hit_func("/players/saber/closed/bard/itm/w/type1.c");
          write("\nYou sing a stormy tune in the key of A.\n");
          say("\n"+tp+" sings a stormy tune in the key of A.\n");
          tell_room(ENV, TO->short()+" "+HIY+"gleams"+NORM+" in the light.\n\n");
          break;

  case "B" : 
          TO->set_short("A "+BOLD+"Pure-Crystal"+NORM+" Bardsword");
          LONG_START = "A translucent white longsword of gleaming crystal";
         TO->set_hit_func("/players/saber/closed/bard/itm/w/type2.c");
          write("\nYou sing a airy tune in the key of B.\n");
          say("\n"+tp+" sings a stormy tune in the key of B.\n");
          tell_room(ENV, TO->short()+" "+HIY+"gleams"+NORM+" in the light.\n\n");
          break;

  case "C" : TO->
          set_short("An "+HIR+"X"+HIG+"m"+HIR+"a"+HIG+"s"+NORM+
                    " Crystal Bardsword");
          LONG_START = "An "+HIR+"X"+HIG+"m"+HIR+"a"+HIG+"s"+NORM+
              " longsword of gleaming "+
              HIR+"red"+NORM+" and "+HIG+"green"+NORM+" crystal";
         TO->set_hit_func("/players/saber/closed/bard/itm/w/type3.c");
          write("\nYou sing a merry tune in the key of C.\n");
          say("\n"+tp+" sings a stormy tune in the key of C.\n");
          tell_room(ENV, TO->short()+" "+HIY+"gleams"+NORM+" in the light.\n\n");
          break;

  case "D" : 
          TO->set_short("A "+BOLD+"Dark Crystal"+NORM+" Bardsword");
          LONG_START = 
          "An "+BOLD+"ebony black"+NORM+" longsword of gleaming crystal.\n"+
          "The crystal "+HIY+"glows"+NORM+" with an inner "+HIR+
          "crimson fire"+NORM+".\n"+
         TO->set_hit_func("/players/saber/closed/bard/itm/w/type4.c");
          write("\nYou sing a firey tune in the key of D.\n");
          say("\n"+tp+" sings a stormy tune in the key of D.\n");
          tell_room(ENV, TO->short()+" "+HIY+"gleams"+NORM+" in the light.\n\n");
          break;
  
  default: write("\nWhat note do you wish to tune your Bardsword to?\n"+
                 "Syntax: Tune < note > or Tune for tuning options.\n\n");
        }

  return 1;
        
        }
