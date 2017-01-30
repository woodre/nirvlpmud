/*
  telepathyfeel.h
*/

#include "/players/eurale/defs.h"
#define CHAN "/bin/channel_daemon"
#define CNAME "Vampire"

/* -------- Telepathy feelings (emote) - tell all vampires ---------- */
telepathyfeel(str) 
{
  int i;
  object stuff, curse_obj;
  string who, msg, player_list, junk1, junk2;
  string em, arg, file, verb;

  if(!str) 
  {
    write("What did you want to say?\n");
    return 1; 
  }

  if(TPBPTS < 1) 
  {
    write("You lack the blood energy to do that.\n");
    return 1; 
  }
  if(str=="history")
  {
    CHAN->channel_message(CNAME,str);
    return 1;
  }
  PFANGS->add_BLOODPTS(-1);
  verb = query_verb();
  
  if(verb=="tt") {
    CHAN->transmit_message(CNAME, HIR+":[ "+this_player()->query_name()+" . o O "+NORM+"("
      +str+")\n");
  } else {
    CHAN->channel_message(CNAME, ":"+str, HIR+":["+NORM);  
  }
    /*
 if(sscanf(str, "%s %s", em, arg) != 2) 
 {
   em = str;
 }
 
 em = implode(explode(em, "."), "");

 if(file_size(file="/bin/soul/_"+em+".c") > 0) 
 {
   return (int)file->guildcast("vampire", arg);
 }
    
  sscanf(str, "%s==>%s", junk1, junk2);
  
  if(junk1)
    str = RED+junk1+"==>"+NORM+junk2;

  player_list = users();
  
  for (i = 0; i < sizeof(player_list); i++) 
  {
    stuff=present("vampire fangs", player_list[i]);
    if(stuff) 
    {
      if(stuff->query_telepathy())
        if(TP->query_invis() > 0)
          if(query_verb()=="tf" || query_verb()=="telepathyfeel") 
          {
            tell_object(player_list[i],
              HIR+":[ Someone "+NORM+str+"\n");
          }
          else 
          {
            tell_object(player_list[i],
              HIR+":] Someone . o O "+NORM+"("+str+")\n");
          }
        else
          if(query_verb()=="tf" || query_verb()=="telepathyfeel") 
          {
            tell_object(player_list[i],
              HIR+":[ "+capitalize(TPRN)+NORM+" "+str+"\n");
          }
          else 
          {
            tell_object(player_list[i],
             HIR+":[ "+capitalize(TPRN)+" . o O "+NORM+"("+str+")\n");
          }
      }
  }

if(TP->query_invis() > 0)
  if(query_verb()=="tf" || query_verb()=="telepathyfeel") 
  {
    "/obj/user/chistory"->add_history("Vamps",
    HIR+":[ Someone "+NORM+str+"\n");
  }
  else 
  {
    "/obj/user/chistory"->add_history("Vamps",
    HIR+":] Someone . o O "+NORM+"("+str+")\n");
  }
else
  if(query_verb()=="tf" || query_verb()=="telepathyfeel") 
  {
    "/obj/user/chistory"->add_history("Vamps",
    HIR+":[ "+capitalize(TPRN)+NORM+" "+str+"\n");
  }
  else 
  {
    "/obj/user/chistory"->add_history("Vamps",
    HIR+":[ "+capitalize(TPRN)+" . o O "+NORM+"("+str+")\n");
  }
  */
return 1;
}
