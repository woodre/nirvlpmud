#include <ansi.h>

int old_wc;
int rounds;
object wep;
object critter;
status shadowing;

void start_shadow(object w, int wc, int r, object c)
{
  wep    = w;
  old_wc = wc;
  rounds = r;
  critter = c;
  shadowing = 1;
  
  shadow(wep, 1);
  call_out("end_shadow", rounds * 2);
}

int get(){
  this_object()->end_shadow();
  /* next line probably is never hit */
  return (int)wep->get();
}

string short(){
  return (string)wep->short()+" ("+HIR+"disarmed"+NORM+")";
}

int wield(string str){
  if(shadowing){
    if(!str || !wep->id(str))
      return 0;
    else {
      if(critter)
      {
        tell_object(critter,"\
You are incapable of wielding "+(string)wep->short()
+".\n");
        tell_room(environment(critter),
        (string)critter->query_name()
        +" struggles with "+possessive(critter)
        +" "+(string)wep->query_name()+".\n", ({ critter }));
      }
    }
  }
  else {
    return (int)wep->wield(str);
  }  
}

void end_shadow()
{
  shadowing = 0;
  
  if(critter){
    tell_object(critter,
      BOLD+"You regain the ability to wield "
     +NORM+(string)wep->short()+BOLD+".\n"+NORM);
    if(environment(critter)){
      tell_room(environment(critter),
        BOLD+(string)critter->query_name()+
        " regains the ability to wield "
       +NORM+(string)wep->short()+BOLD+".\n"+NORM,
       ({critter}));
    }
    command("wield "+(string)wep->query_name(), critter);
    
    if(old_wc){
      critter->set_wc(old_wc);
      critter->calculate_worth();
    }
  }
  
  destruct(this_object());
}