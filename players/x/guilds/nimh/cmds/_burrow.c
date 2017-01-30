#include "../x.h"

inherit N_EFUN;

int cmd_burrow(string str)
{
 int cs, x, y;
 string *cmds, *dx, loc, tmp, dest, cmd, ec, sc;
 object hole;
 if(!ENVTP->query_nimh_hole())
 {
  write("You must be in a hole dug by a NIMH Rat\n"+
        "to be able to burrow.\n");
  return 1;
 }
 if(!(loc=(string)ENVTP->query_location()) || 
   catch(loc->load_me()))
 {
  write("Bad location for this hole.\nCannot burrow further.\n");
  return 1;
 }
 if(!str)
 {
  write("Usage: 'burrow <dir1,dir2,etc.>'\n");
  return 1;
 }

 write("\n");

 cmds = explode(str,",");
 cs = sizeof(cmds);

 if(cs > 0)
  for(x=0; x < cs; x++)
  {
   cmd = cmds[x];
   loc = (string)ENVTP->query_location();
   ec = elongate_exit(cmd);
   sc = shorten_exit(cmd);
   if(x >= 5)
   {
    write("You cannot burrow in more than five directions at once.\n");
    return 1;
   }

/*
   if(member_array(sc,
    ({"n","e","s","w","ne","nw","se","sw","u","d"})) == -1)
   {
    write("You may not burrow in a non-standard direction.\n"+
          "Type 'nhelp burrow' for more info.\n");
    return 1;
   }
*/

   if(tmp = (string)ENVTP->query_exit(ec))
   {
    write(HIK+"    Moving "+ec+"...\n"+NORM);
    command(sc, TP);
    continue;
   }

   else
   {
    if(!(dx = (string*)loc->query_dest_dir()) || !sizeof(dx))
    {
     if(tmp = (string)loc->query_std_dest1())
     {
      dx = ({ tmp, loc->query_std_dir1() });
     if(tmp = (string)loc->query_std_dest2())
      dx += ({ tmp, loc->query_std_dir2() });
     if(tmp = (string)loc->query_std_dest3())
      dx += ({ tmp, loc->query_std_dir3() });
     if(tmp = (string)loc->query_std_dest4())
      dx += ({ tmp, loc->query_std_dir4()});
    }
    else
    {
     write("Without obvious exits, you may not burrow.\n");
     return 1;
    }
   }
  }

  if((y=member_array(sc, dx)) == -1
   && (y=member_array(ec,dx)) == -1)
  {
   write("You may not burrow "+ec+".\n");
   return 1;
  }
   
  if(!find_object(dest=dx[y-1]))
   dest->load_me();

  if(!(hole=present(HOLE_ID, find_object(dest))))
  {
   write(YEL+"   Burrowing "+ec+"...\n"+NORM);
   hole = CO(N_OBJ+"hole");
   hole->set_creator((string)TP->RN);
   hole->set_location(dest);
   MO(hole, dest);
  }

  else
   write(HIK+"   Moving "+ec+"...\n"+NORM);

  if(tmp = elongate_exit(reverse_exit(cmds[x])))
   if(!hole->query_exit(tmp))
    hole->add_exit(tmp, FN(ENVTP));

  if(!ENVTP->query_exit(tmp=elongate_exit(cmds[x])))
   ENVTP->add_exit(tmp, FN(hole));

  command(sc, TP);

  TR(dest, "The ground beneath your feet trembles slightly.\n");
 }

 write("Burrow done.\n");
 return 1;
}
