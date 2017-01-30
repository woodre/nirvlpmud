/*  the Fallen Lands - demon curse   
    Version:  4.1     Updated: 1.26.00
*/
#include "/players/zeus/closed/all.h"
#define xhp x->query_hp()
#define xmhp x->query_mhp()
#define SAVE_PATH "players/zeus/closed/fl_d"
string *empty;

reset(arg)
{
  if(arg) return;
 
  if(!restore_object(SAVE_PATH))
  {
     empty = ({ });
  }
  save_object(SAVE_PATH);
  call_out("scheck",1);
}

scheck()
{
  if(environment(this_object())) destruct(this_object());
  return 1; 
}

void init()
{
  if(!environment()) return;
}


add_e(string str){
  if(!str) return 0;
  if(!query_e(str))
  {
    empty += ({ str, });
    save_object(SAVE_PATH);
    return 1;
  }
  return 0;
}

sub_e(string str){
  if(!str) return 0;
  if(query_e(str))
  {
	empty -= ({ str, });
    save_object(SAVE_PATH);
    return 1;
  }
  return 0;
}

query_e(string str){
  if(!str) return 0;
  if(!empty || !sizeof(empty)) return 0;
  if(index(empty, str) > -1) return str;
  return 0;
}

percent_func(object x)
{
  int fl_dir;
  if(!x) return 0;
  if(x->query_level() > 21 || query_e(x->query_real_name()) || 
    (xhp >= (xmhp * 19 / 20)))
    fl_dir = 1; /* no chance for wiz, empty, >= 95%  */
  else if((xhp >= (xmhp * 9 / 10)))
    fl_dir = random(20);  /* >= 90% == 5% chance  */
  else if((xhp >= (xmhp * 7 / 10)))
    fl_dir = random(10);  /* >= 70% == 10% chance  */
  else if((xhp >= (xmhp * 5 / 10)))
    fl_dir = random(5);   /* >= 50% == 20% chance  */
  else if((xhp >= (xmhp * 3 / 10)))
    fl_dir = random(3);  /* >= 30% == 33% chance  */
  else if(xhp < (xmhp * 3 / 10))
     fl_dir = random(2); /* < 30% == 50% chance */
  return fl_dir;
}

call_demon(object x)
{
   object red_demon;
   if(!x) return 0;
   if(x->query_ghost()) return 0;
   if(present("tyborlek enchantment", x)) return 0;  /* added 5.27.01 */
   red_demon = CO("/players/zeus/realm/NPC/demon1.c");
   tell_object(x, "A "+BOLD+"VORTEX"+NORM+" opens before you...\n"+
     "A cursed demon steps out and lunges at you!\n\n");
   tell_room(environment(x),
     "A "+BOLD+"VORTEX"+NORM+" opens and a cursed demon steps out...\n",
     ({ x }));
   MO(red_demon, environment(x));
   red_demon -> attack_object(x);
   return 1;
}

check_block(object x)
{
  if(!x) return 0;
  if(x->query_ghost()) return 2;
  if((present("a cursed demon", environment(x))) && !random(5))
  {
    object *area;
    int cnt;
    if(present("tyborlek enchantment", x)) return 0;  /* added 6.02.01 */
    if(query_e(x->query_real_name())) return 0;       /* added 6.02.01 */
    area = all_inventory(environment(x));
    tell_object(x, "A demon blocks your exit!\n");
    if(!random(3))
    {
      tell_room(environment(x), 
        "A demon blocks "+x->QN+"'s exit!\n", ({ x }));
    }
    else if(!random(2))
    {
      tell_room(environment(x), 
        "A demon screams in rage at "+x->QN+"!\n", ({ x }));
    }
    else
    {
      tell_room(environment(x), 
        "A demons eyes burn with anger!\n", ({ x }));
    }
    present("a cursed demon", environment(x))->attack_object(x);
    for(cnt = 0; cnt < sizeof(area); cnt++)
    {
      if(area[cnt]->id("a cursed demon") && !area[cnt]->query_attack())
      {
        if(!random(2))
          area[cnt]->attack_object(x);
      }
    }
    return 1;  
  }
  return 0; 
}

check_demon(object x)
{
  int gc;
  if(!x) return 0;
  gc = check_block(x);
  if(1 == gc) return 1;
  else if(2 == gc) return 0;
  else if(!percent_func(x))
  {
    if(call_demon(x))
      return 1; 
  }
  return 0; 
}

