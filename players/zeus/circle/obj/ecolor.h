
set_ecolor(str){
  int g, h;
  string *colors, temp, z;
  colors =({ "black", "red", "green", "yellow", "blue", "magenta", 
    "cyan", "white", "h_black", "h_red", "h_green", "h_yellow", "h_blue", 
    "h_magenta", "h_cyan", "h_white", });
  if(!str)
  {
    write(
      "Use this command to set the color of your endurance\n"+
      "monitor when it is positive and negative in combat.\n\n"+
      "Syntax:  'ecolor <pos/neg> <color>'\n"+
      "For a list of colors, type 'ecolor list'.\n\n");
    if(posendcol)
      write("Current positive color:  "+posendcol+"||||||||||"+NORM+"\n");
    if(negendcol)
      write("Current negative color:  "+negendcol+"||||||||||"+NORM+"\n");
    return 1;
  }
  if(str == "list")
  {
    write(HIW+"\nAvailable colors:\n  "+NORM);
    for(g = 0, h = 0; g < sizeof(colors); g++, h++)
    {
      write(pad(colors[g], 11));
      if(h == 5)
      {
        h = -1;
        write("\n  ");
      }
    }
    write("\n");
    return 1;
  }
  if(!sscanf(str, "pos %s", z) && !sscanf(str, "neg %s", z))
  {
    write("You must set color for 'pos' or 'neg' endurance.\n");
    return 1;
  }
  if(index(colors, z) == -1)
  {
    write("That is not a valid color.\n");
    return 1;
  }
  switch(index(colors, z))
  {
    case 0:    temp = BLK;       break;
    case 1:    temp = RED;       break;
    case 2:    temp = GRN;       break;
    case 3:    temp = YEL;       break;
    case 4:    temp = BLU;       break;
    case 5:    temp = MAG;       break;
    case 6:    temp = CYN;       break;
    case 7:    temp = WHT;       break;
    case 8:    temp = BOLD+BLK;  break;
    case 9:    temp = HIR;       break;
    case 10:   temp = HIG;       break;
    case 11:   temp = HIY;       break;
    case 12:   temp = HIB;       break;
    case 13:   temp = HIM;       break;
    case 14:   temp = HIC;       break;
    case 15:   temp = HIW;       break;
  }
  if(sscanf(str, "pos %s", z))
  {
    write("You set your positive endurance monitor to "+temp+
      "this color"+NORM+".\n");
    posendcol = temp;
  }
  else if(sscanf(str, "neg %s", z))
  {
    write("You set your negative endurance monitor to "+temp+
      "this color"+NORM+".\n");
    negendcol = temp;
  }
  save_object(SAVE_PATH+NAME);
  return 1;
}

