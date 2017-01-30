/*****************************************************************************
*  File:             _convert.c                                              *
*  Function:         BWO guild convert crowd spell                           *
*  Author:           Sparrow                                                 *
*  Copyright:        Sparrow@Nirvana                                         *
*  Source:           3/5/2011                                                *
*  Notes:                                                                    *
*  Changelog:                                                                *
*****************************************************************************/
#include <ansi.h>
cmd_convert(str)
{
  /* Variable Declarations */
  object crowd;
  int crowdSize, multiplier, converted, myCha, myPie, myLuc;
  /* Check to make sure crowd object is in the room */
  if(!present("BWOCROWDOBJ",environment(this_player()))) {
    /* No crowd object in room */
    write("You can only "+BOLD+"convert"+NORM+" when a crowd is present!\n");
    return 1;
  }
  crowd = present("BWOCROWDOBJ",environment(this_player()));
  crowdSize = crowd->queryCrowdSize();
  if(crowdSize == 0) crowdSize = 1;
  /*
     Chances to convert crowd
     10% chance to convert 100% of the crowd
     20% chance to convert 75% of the crowd
     40% chance to convert 50% of the crowd
     20% chance to convert 33% of the crowd
     10% chance to convert 25% of the crowd
  */
  switch(random(10)) {
    case 0:
      multiplier = 100;
      break;
    case 1..2:
      multiplier = 75;
      break;
    case 3..6:
      multiplier = 50;
      break;
    case 7..8:
      multiplier = 33;
      break;
    default:
      multiplier = 25;
  }
  if(!multiplier == 100) {
    myLuc = this_player()->query_attrib("luc");
    myCha = this_player()->query_attrib("cha");
    myPie = this_player()->query_attrib("pie");
    /* weight stats accordingly */
    myLuc = myLuc/6;
    myCha = myCha/4;
    myPie = myPie/3;
    multiplier = multiplier + myLuc + myCha + myPie;
  }
  /* Do calculation of converted */
  converted = (crowdSize*multiplier)/100;
  if(converted == 0) converted = 1;
  write("Congratulations!\nYou have converted "+HIR+converted+NORM+
        " people to your Parish.\n");
  /* Add to Parish */
  previous_object()->addParish(converted);
  write("You now have a total of "+HIC+previous_object()->queryParish()+
        NORM+" people in your Parish.\n");
  /* Destruct crowd */
  destruct(crowd);
  say(this_player()->query_name()+" has converted some of the crowd to "+
      BOLD+"The Order.\n"+NORM);
  return 1;
}