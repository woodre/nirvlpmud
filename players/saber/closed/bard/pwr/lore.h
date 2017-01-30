/*
 *  Help files for the Bards of Ryllian.
 *  v3.0 by Saber / Geoffrey Z.
 *
 */


lore(str)  {
string nme, path;

  if(!str)  {
    write("\n");
    cat("/players/saber/closed/bard/doc/lore");
    write("\n");
    return 1;
        }
  
  str = lower_case(str);
   
  path = "/players/saber/closed/bard/doc/"+str;   
   
  if(!path)  {
    write("\nThere is no lore on that topic.\n\n");
    return 1;
        }
  
   write("\n");
   cat(path);
   write("\n");
   
   return 1;
        }
