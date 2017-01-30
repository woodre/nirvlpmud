#include <ansi.h>

static int loaded;

void reset(status arg) {
  if(arg) return;
  if(root()) return;
  call_out("darken", 100);
}

void darken() {
  if(environment()) {
    environment()->add_alignment(-1600);
    call_out("darken", 100);
  }
}

void long()
{
  write(
"You wear around your neck the Symbol of Shardak.  It is made\n"+
"from an unknown red metal that glints eerily in the light. A\n"+
"power emanates from within it, and you feel its evil might.\n");
}

void extra_look()
{
  if(environment()==this_player())
    write("You wear a "+RED+"Symbol of Shardak"+NORM+".\n");
  else
    write((string)environment()->query_name()+
     " wears a "+RED+"Symbol of Shardak"+NORM+".\n");
}

int id(string str)
{
  return (str=="symbol" || str == "symbol of shardak" ||
          str=="generic_wc_bonus");
}

int drop(){ return 1; }
int get(){ return 1; }

string query_auto_load(){ return basename(this_object())+":0"; }

int gen_wc_bonus()
{
  object atk, wep, room;
  string msg, dtype;
  if(!(atk=(object)environment()->query_attack()) ||
     !(wep=(object)environment()->query_weapon()) ||
     !(room=environment(environment())))
  {
    return 0;
  }
  if(!random(6))
  {
    msg = HIR+"Flames"+NORM+" engulf";
    dtype="other|fire";
  }
  else if(!random(6))
  {
    msg = CYN+"Water"+NORM+" washes over";
    dtype = "other|water";
  }
  else if(!random(6))
  {
    msg = HIY+"Lightning"+NORM+" crackles through";
    dtype = "other|electric";
  }
  else if(!random(6))
  {
    msg = HIK+"Darkness"+NORM+" enshrouds";
    dtype = "other|dark";
  }
  if(msg)
  {
    tell_room(room,
      msg+" "+
      (string)environment()->query_name()+"'s "+
      (string)wep->query_name()+"!\n", ({ environment() }));
    tell_object(environment(),
      msg+" "+
      "your "+(string)wep->query_name()+"!\n");
    
    atk->add_hp(100);
  }
  if((int)this_player()->query_attrib("dex") > random(50))
   {
    tell_object(environment(),
        "Your Symbol of Shardak pulses "+HIK+"darkly"+NORM+".\n");
   tell_room(environment(environment()),
       "Worm's Symbol of Shardak pulses "+HIK+"darkly"+NORM+".\n",
    ({ environment() }));
    return 0 + random(1);
   }
  return 1;
}

void init()
{
  if(environment() && (string)environment()->query_real_name() != "worm")
    return destruct(this_object());
  else if(environment() && !loaded)
  {
    call_out("refresh_weps", 2);
    loaded = 1;
  }
}

void refresh_weps()
{
  object wep;
  if(!environment()) return destruct(this_object());
  
  if(wep=(object)environment()->query_weapon())
  {
    wep->set_hits(1);
    wep->set_misses(1);
    
    if(!random(100))
    {
      tell_object(environment(),
"You feel the power of "+HIR+"Vulcan"+NORM+" coursing through you.\n");
      environment()->heal_self(-10);
    }
  }
  
  if(wep=(object)environment()->query_second_weapon())
  {
    wep->set_hits(1);
    wep->set_misses(1);
  }
  
  call_out("refresh_weps", 2);
}
