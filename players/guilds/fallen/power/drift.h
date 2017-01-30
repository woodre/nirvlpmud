
drift(str){
  int xx, yy;
  string good, cmds, t1,t2,t3,t4,t5,t6;
  good = allocate(22);
  cmds = ({ });
  good =({ "north", "east", "south", "west", "northeast", "southeast",
    "southwest", "northwest", "up", "down", "in", "out", "n", "e", "s",
    "w", "ne", "se", "sw", "nw", "u", "d", });
  if(!str)
  {
    TOU"Drift up to 5 common directions at once.\n"+
       "Usage:  'drift <dir1,dir2,etc>'\n");
    return 1;
  }
  if(sscanf(str, "%s,%s,%s,%s,%s", t1,t2,t3,t4,t5) == 5)
    cmds = ({ t1,t2,t3,t4,t5 });
  else if(sscanf(str, "%s,%s,%s,%s", t1,t2,t3,t4) == 4)
    cmds = ({ t1,t2,t3,t4 });
  else if(sscanf(str, "%s,%s,%s", t1,t2,t3) == 3)
    cmds = ({ t1,t2,t3 });
  else if(sscanf(str, "%s,%s", t1,t2) == 2)
    cmds = ({ t1,t2 });
  else if(sscanf(str, "%s", t1) == 1)
    cmds = ({ t1 });
  TOU BOLD+BLK+"You drift through the shadows...\n"+NORM);
  for(yy = 0; yy < sizeof(cmds); yy++)
  {
    for(xx = 0; xx < sizeof(good); xx++)
    {
      if(good[xx] == cmds[yy])
        command(cmds[yy], User);
    }
  }  
  return 1;
}
