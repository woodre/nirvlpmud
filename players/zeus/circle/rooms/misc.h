/* misc.h  -  read / uncover / touch  */
/* part of ghall.c                    */

status read_cmd(string str)
{
  if(!uncovered) return 0;
  if(str == "writing")
  {
    write(
      "Within this circle we inscrible our ways...\n"+
      "our strengths and our weaknesses....\n"+
      "who we are...\n"+
      "\n"+
      "You may 'seek' more 'information'...\n"+
      "If you wish to follow this path,\n"+
      "you need only trace the symbols.\n");
    return 1;
  }
  return 0;
}


status uncover_cmd(string str)
{
  if(!str) return 0;
  if(str == "rock" || str == "stone" || str == "circle" || str == "rock face")
  {
    if(uncovered)
    {
      write("The "+str+" is already uncovered.\n");
      return 1;
    }
    if(!uncovered)
    {
      write(
"You reach up and move the branches and plants away from the rock...\n"+
"You reveal a large circle carved into the face of the rock.\n");
      say(TP->QN+" moves the plants aside.\n");
      uncovered = 1;
      return 1;
    }
    return 1;
  }
  else return 0;
  return 1;
}

status touch_cmd(string str)
{ 
  if(!str) return 0;
  if(!uncovered) return 0;
  if(str == "circle" || str == "the circle")
  {
    if(query_touched(TP))
    {
      write("You are already touching the circle.\n");
      return 1;
    }
    write("You place your hand on the circle.\n");
    load_spells(TP);
    say(TP->QN+" places "+TP->POS+" hand on the circle.\n");
    add_touched(TP);
  }
  else if(str == "1" || str == "symbol 1" && GUILD)
  {
    cat("/players/zeus/circle/misc/symbol1");
    say(TP->QN+" touches a symbol on the circle.\n");
  }
  else if(str == "2" || str == "symbol 2" && GUILD)
  {
    cat("/players/zeus/circle/misc/symbol2");
    say(TP->QN+" touches a symbol on the circle.\n");
  }
  else if(str == "3" || str == "symbol 3" && GUILD)
  {
    cat("/players/zeus/circle/misc/symbol3");
    say(TP->QN+" touches a symbol on the circle.\n");
  }
  else if(str == "4" || str == "symbol 4" && GUILD)
  {
    cat("/players/zeus/circle/misc/symbol4");
    say(TP->QN+" touches a symbol on the circle.\n");
  }
  else if(str == "5" || str == "symbol 5" && GUILD)
  {
    cat("/players/zeus/circle/misc/symbol5");
    say(TP->QN+" touches a symbol on the circle.\n");
  }
  else if(str == "6" || str == "symbol 6" && GUILD)
  {
    cat("/players/zeus/circle/misc/symbol6");
    say(TP->QN+" touches a symbol on the circle.\n");
  }
  else if(str == "7" || str == "symbol 7" && GUILD)
  {
    cat("/players/zeus/circle/misc/symbol7");
    say(TP->QN+" touches a symbol on the circle.\n");
  }
  else return 0;
  return 1;
}

