inherit "obj/monster.c";
#include <ansi.h>
#define attacked (this_object()->query_attack())
int called;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("gohan");
set_race("human");
set_short("Gohan, son of Goku");
set_long(
  "  Gohan stands before you warning you about testing him.  Being\n"+
  "half saiyan, this teen has extraordinary strength.  A mere 4 \n"+
  "feet tall, with long black hair, he is the symbol of all things\n"+
  "good in this world.  Beware of his use of the power of loss,\n"+
  "he becomes an unstoppable force if pushed into a corner.\n");
 
set_level(29);
set_hp(2000);
set_al(1000);
set_ac(28);
set_wc(55);
set_dead_ob(this_object());
set_aggressive(0);
set_chat_chance(5);
  load_chat("Gohan smiles at the birds in their nest.\n");
set_a_chat_chance(2);
  load_a_chat("Gohan tells you: Hi!!\n");
}
heart_beat()
{
  int q;
  q = random(100);
    ::heart_beat();
  if(!environment())
    return;
  if(!attacked)
    return;
  if(!called && (hit_point <= ((max_hp / 10) * 2)))
  {
    tell_room(environment(),
      "\n\n\nGohan's hair turns"+HIY+" golden "+NORM+"as power surges through him.\n\n\n");
    hit_point = max_hp;
    weapon_class += 5;
    called = 1;
  }
  if(q<15){
    fuck();
  }
  if(q>90){
    shit();
  }
  if(q>15 && q<65){
    DIE();
  } 
}

fuck(){
  say(
    "Gohan lets out a "+YEL+"SCREAM"+NORM+" and releases a burst\n"+
    "of energy at his enemy, knocking them to the ground.\n");
  write(
    "Gohan "+YEL+"SCREAMS"+NORM+" releasing a burst of energy at you.\n"+
    "You fall to the ground from the impact, wiping the"+RED+" blood"+NORM+"\n"+
    "from your mouth.\n");
    attacked->heal_self(-30);
    return 1;
  }

shit(){
  say(
    "Gohan brings his arms back, building up energy in his hands.\n"+
    "Gohan mutters:"+HIW+"        kaaaa meeee haaaa meeee"+NORM+"\n"+
    "\n"+
    "\n"+HIW+"         HAAAAAAAAAAAA!!!!!"+NORM+"\n");
  write(
    "Gohan brings his arms back.  A blue energy ball starts to form\n"+
    "in his hands while he mutters something under his breath.\n"+
    "As he brings his arms forward all you can hear is\n"+
    "\n"+HIW+"          HH  HH    AA    !! !!\n"+
    "          HHHHHH    A  A    !! !!\n"+
    "          HHHHHH   AAAAAA        \n"+
    "          HH  HH   AA  AA   OO OO"+NORM+"\n"+
    "\n\n"+
    "You stagger as the kameahmeah wave "+RED+"OBLITERATES"+NORM+" you.\n");
  attacked->heal_self(-50);
  return 1; 
 }
 
DIE(){
 say(
   "Gohan "+BLK+"disappears "+NORM+"from view, then reappears\n"+
   "seconds later behind his foe delivering a series of lightning\n"+
   "fast punches to his enemies torso.\n");
 write(
   "Gohan "+BLK+"dissappears"+NORM+" only to reappear"+BOLD+" BEHIND YOU"+NORM+"\n"+
   "You try to turn around in time but feel every "+HIR+"bone crunching"+NORM+"\n"+
   "punch utterly destroys you.\n");
   attacked->heal_self(-15);
  return 1;
}
 
monster_died()
{
  int i, s;
  object *inv; 

  if (!environment())
    return 0;

  inv = all_inventory(environment());
  s = sizeof(inv);
  tell_room(environment(), 
    "Gohan let's out a final"+RED+" SCREAM "+NORM+"releasing\n");
  tell_room(environment(),
    "all of his energy in one final wave of power sending you\n");
  tell_room(environment(),
    "into an oblivion of "+RED+"P"+YEL+"A"+HIR+"I"+HIY+"N"+NORM+".\n");

  for(i= 0; i < s; i++)
  {
    if (living(inv[i])) 
    {
      inv[i]->hit_player(150);
    }
  }
  return 0;
} 

   
