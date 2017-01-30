#include "/players/pestilence/define.h"
inherit "obj/treasure";

id(str) { return (::id(str) || str == "help_maker"); }
reset(arg) 
{
  if(arg) return;
  set_short("Pesty's loser maker");
}
init() 
{
  add_action("make_loser","make_loser");
}

make_loser()
{
  write(""+HIW+""+BLINK+"HELP FILE MADE!"+NORM+"\n");
  write_file("/players/pestilence/closed/dark/help/losers.txt",
""+HIW+"~~~~~~~~~~~~~~~~~~~~~~~"+BLINK+"L O S E R S"+NORM+HIW+"~~~~~~~~~~~~~~~~~~~~~~~\n"+
"|                                                       |\n"+
"|  "+HIR+"LOSER 1.       "+HIY+"Grit"+HIW+"                                  |\n"+
"|  "+HIR+"LOSER 2.       "+HIY+"Hedren"+HIW+"                                |\n"+
"|  "+HIR+"LOSER 3.       "+HIY+"Mortarion"+HIW+"                             |\n"+
"|                                                       |\n"+
""+HIW+"~~~~~~~~~~~~~~~~~~~~~~~"+BLINK+"L O S E R S"+NORM+HIW+"~~~~~~~~~~~~~~~~~~~~~~~"+NORM+"\n");
    return 1;
}
