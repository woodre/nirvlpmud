inherit "/obj/treasure.c";
#include "/players/fred/ansi.h"
int chg, chgn;

reset(arg){

  chg = 400;
  set_id("scarab of maruf");
  set_alias("scarab");
  set_long(
"This is a beautiful crystal scarab.  Within the crystal exterior of the\n"+
"beetle is a beautiful red ruby.  The scarab grows with a gentle warmth\n"+
"in your hand, and seemingly begs for you to 'hold' it.  Of course, it\n"+
"will only grow warmer as the blood begins to flow, and only then can its\n"+
"true power be unleashed.\n");
  set_weight(1);
  set_value(12025+random(4123));
  set_heart_beat(1);
}

string gcol()
{
  if(chg < 300)       return NORM;
  else if(chg < 700)  return HIW;
  else if(chg < 1100) return RED;
  else if(chg < 1400) return HIR;
  else                return HIY;
}

short(){
  return gcol()+"The Scarab of Maruf"+NORM;
}

query_save_flag(){ return 1; }

void init(){
  ::init();
  add_action("use", "hold");
}

status use(string str)
{
  if(str != "scarab" && str != "scarab of maruf") return 0;
  if(!present(this_object(), this_player())) return 0;
  write(gcol()+"You hold the scarab of maruf in your hands.\n"+NORM);
  if(chg >= 300)
  {
    chg /= 2;
    write(gcol()+
      "You feel a warmth flow from the scarab into your body.\n"+NORM);
    this_player()->heal_self(chg / 6);
    if((int)this_player()->query_intoxination() > 0)
      this_player()->drink_alcohol(-(1+(chg / 500)));
    if((int)this_player()->query_soaked() > 0)
      this_player()->drink_soft(-(chg / 250));
    if((int)this_player()->query_stuffed() > 0)
      this_player()->eat_food(-(chg / 250));
  }
  else {
    write("You feel nothing as the scarab grows colder.\n");
    if(chg > 2)
    chg /= 2;
  }
  return 1;
}

heart_beat()
{
  if(!environment()) return;
  if(!environment()->is_player()) return;
  if(!environment()->query_attack()) return;
  chgn = (int)environment()->query_dam_taken_this_round();
  chg += chgn;
  if(chgn > 250)
    chg += 100;
  else if(chgn > 100)
    chg += 50;
  else if(chgn > 75)
    chg += 20;
  if(!random(5))
    tell_object(environment(), "The scarab grows warmer...\n");
}
