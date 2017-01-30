#include "../defs.h"
#include "/players/forbin/closed/dm/inherits/color_string.h"

#define AUTOSAVE 570+random(61)  /* 10 minutes - autosave */
#define ADVANCE 1770+random(61)  /* 30 minutes - advancement check */
object *LocalUsers;
int x, s;

reset(arg)
{
  if(arg) return;
  
  call_out("called_daemoncheck",1); 
  call_out("called_autosave", AUTOSAVE);
  call_out("called_advancecheck", ADVANCE);
}

called_daemoncheck() 
{
  if(environment(this_object())) 
    destruct(this_object());
  return 1; 
}

called_autosave()
{
  LocalUsers = users();
  s = sizeof(LocalUsers);
  for(x = 0; x < s; x++)
  {
    if(LocalUsers[x]) 
    {
      if(present("forbin_dm_object", LocalUsers[x]) && 
         LocalUsers[x]->query_level() < 21)
      {
        present("forbin_dm_object", LocalUsers[x])->save_gob();
      }
    }
  }
  call_out("called_autosave", AUTOSAVE);
}

called_advancecheck() 
{
  int lvl, xlvl, glvl, fae;
  object dmobj;
  
  LocalUsers = users();
  s = sizeof(LocalUsers);

  call_out("called_advancecheck", ADVANCE);
  
  for(x = 0; x < s; x++)
  {
    if(LocalUsers[x]) 
    { 
      dmobj = present("forbin_dm_object", LocalUsers[x]);
      if(dmobj && LocalUsers[x]->query_level() < 21)
      {
        lvl =  (int)LocalUsers[x]->query_level();
        xlvl = (int)LocalUsers[x]->query_extra_level();
        glvl = (int)dmobj->query_glevel();
        fae = (int)dmobj->query_glevel();
        
        if(glvl == 0 && lvl > 11)
          tell_object(LocalUsers[x],"\n\t"+
            color_string("Find the stone before it is too late.")+"\n\n");

        if(glvl == 1 && dmobj->check_glevel() && lvl > 15 && fae > 1)
          tell_object(LocalUsers[x],"\n\t"+
            color_string("Do the second task.")+"\n\n");
            
        if(glvl == 2 && dmobj->check_glevel() && lvl == 19 && fae > 3)
          tell_object(LocalUsers[x],"\n\t"+
            color_string("Do the third task.")+"\n\n");

        if(glvl == 3 && dmobj->check_glevel() && lvl == 19 && xlvl > 4 && fae > 7)
          tell_object(LocalUsers[x],"\n\t"+
            color_string("Do the fourth task.")+"\n\n");
            
        if(glvl == 4 && dmobj->check_glevel() && lvl == 19 && xlvl > 12 && fae > 11)
          tell_object(LocalUsers[x],"\n\t"+
            color_string("Do the fifth task.")+"\n\n");

        if(glvl == 5 && dmobj->check_glevel() && lvl == 19 && xlvl > 16 && fae > 16)
          tell_object(LocalUsers[x],"\n\t"+
            color_string("Do the sixth task.")+"\n\n");

        if(glvl == 6 && dmobj->check_glevel() && lvl == 19 && xlvl > 20 && fae > 22)
          tell_object(LocalUsers[x],"\n\t"+
            color_string("Do the seventh task.")+"\n\n");                                                

        if(glvl == 7 && dmobj->check_glevel() && lvl == 19 && xlvl > 32 && fae == 30)
          tell_object(LocalUsers[x],"\n\t"+
            color_string("Do the final task.")+"\n\n");            
                                    
      }
    }
  }
}

