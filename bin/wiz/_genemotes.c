#define SCREEN_WIDTH 65
#define PRINTOUT1    "/doc/helpdir/emotes"
#define PRINTOUT2    "/doc/helpdir/emotions"
#define TP this_player()

int cmd_genemotes()
{
  string *d, fullText;
  int    x, y, spc, sl;
  
  if(!present("e-create", TP)) return 0;
  fullText = "\n\t\t[ :::Emotions Available::: ]\n\n ";
  d = get_dir("/bin/soul/");
  y = sizeof(d);
  for(x=0;x<y;x++)
    if(sscanf(d[x],"_%s.c",d[x]))
    {
      sl = strlen(d[x]);
      if((spc + sl) > (SCREEN_WIDTH+1))
      {
        spc = 0;
        fullText += "\n ";
      }
      fullText += (d[x]+" ");
      spc += (sl+1);
    }
/*
  rm(PRINTOUT1);
*/
  rm(PRINTOUT2);
/*
  write_file(PRINTOUT1, fullText + "\n\n");
*/
  write_file(PRINTOUT2, fullText +"\n\n");
  write("Okay, done.\n");
  return 1;
}
