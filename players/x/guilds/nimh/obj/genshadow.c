#include "../x.h"

object shadowee;

void reset(status x)
{
 if(x) return;
}

void start_shadow(object ob)
{
 tell_object(ob, "SHADOW ENGAGING...\n");
 shadowee = ob;
 shadow(ob, 1);
}

void end_shadow()
{
 shadow(shadowee, 0);
 destruct(TO);
}

object query_nimh_genshadow()
{
 return TO;
}

#define MAX_LIST 20

int test_dark()
{
 if(shadowee->query_glowing_eyes())
  return 0;
 else
  return (int)shadowee->test_dark();
}

int look(string str, int remote)
{
 object ob, gob;
 int max, lit;

 if((gob=present(OBJID, shadowee)) && gob->query_glowing_eyes())
 {
  lit = 1;
  gob->light_up(3);
 }
 else if(str) return (shadowee->look(str), 1);

 if(test_dark())
 {
  if(lit) gob->light_up(-3);
  return 1;
 }

 if(!str)
 {
  if(remote) write((string)ENV(shadowee)->short()+"\n");
  else
  {
   if((int)shadowee->query_brief() == 2)
   {
    string sdec;
    int sdecl, lkcol;
    sdec = (string)ENV(shadowee)->short();
    sdecl = strlen(sdec);
    sdecl = 40-(sdecl/2);
    if(lkcol = (int)shadowee->get_ansi_pref("roomtitle"))
     write(pad(" ",sdecl-1)+lkcol+sdec+NORM+"\n");
    else
     write(pad(" ",sdecl-1)+sdec+"\n");
   }
   ENV(shadowee)->long();
  }
  ob = first_inventory(ENV(shadowee));
  max = MAX_LIST;
  while(ob && max > 0)
  {
   if(ob != shadowee)
   {
    string short_str, ex_str;
    short_str = (string)ob->short();
    ex_str = "";
    if(short_str)
    {
     max -= 1;
     if(living(ob) && MASTER->is_feline(ob))
      ex_str = HIR+"[FELINE]"+NORM;
     write(ex_str + " "+short_str+".\n");
    }
   }
   ob = next_inventory(ob);
  }
 }
 else
  shadowee->look(str, remote);
 if(lit) gob->light_up(-3);
 return 1;
}

int quit()
{
 shadow(shadowee, 0);
 shadowee->quit();
 return 1;
}

void move_player(string str)
{
 object gob;
 if((gob=present(OBJID,shadowee)) && gob->query_glowing_eyes())
 {
  gob->light_up(3);
  shadowee->move_player(str);
  gob->light_up(-3);
 }
 else
  shadowee->move_player(str);
}
