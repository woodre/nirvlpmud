#include "/players/pavlik/closed/colors.h"

int hits;
int max_hits;
string color;

int get() { return 0; }
int drop() { return 1; }

void reset(int x)
{
  if(x) return;
}

int id(string str) { return (str=="energy_shield_obj"); }
void start_me(int evo, int pow)
{
  max_hits=evo;
  environment()->RegisterArmor(this_object(),({"physical",0,pow/5,"do_special"}));
  this_object()->pick_color();
  call_out("tell_em", 40 + random(40));
}

void pick_color()
{
  switch(random(6))
  {
    case 0: color=HIB; break;
    case 1: color=HIC; break;
    case 2: color=HIR; break;
    case 3: color=HIG; break;
    case 4: color=HIM; break;
    case 5: color=HIY; break;
  }
}

void tell_em()
{
  object room;
  tell_object(environment(), "Your "+color+"Energy Shield"+NORM+" shifts spectrums.\n");
  pick_color();
}
  

int do_special(object owner)
{
  object room;
  tell_object(environment(), "The "+color+"Energy Shield"+NORM+" flashes!\n");
  if(room=environment(environment()))
  {
    tell_room(room, "The "+color+"Energy Shield"+NORM+" surrounding "+
      (string)environment()->query_name()+" flashes!\n",
      ({environment()}));
  }
  if(++ hits >= max_hits)
  {
    destruct(this_object());
  }
}

void extra_look()
{
  if(environment()==this_player())
    write("You are protected by an "+color+"Energy Shield"+NORM+"...\n");
  else
    write((string)environment()->query_name()
      +" is protected by an "+color+"Energy Shield"+NORM+"...\n");
}

void remove_object()
{
  if(environment())
  {
    object room;
    tell_object(environment(), color+"Your Energy Shield disappears.\n"+NORM);
    if(room=environment(environment()))
    {
      tell_room(room,
        color+"The Energy Shield surrounding "+
        (string)environment()->query_name()+
        " disappears.\n"+NORM, ({environment()}));
    }
  }
} 
