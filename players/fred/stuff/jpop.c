
#include "/players/fred/ansi.h"
inherit "/obj/weapon.c";
#define NEW 4000
#define ENV environment
#define EN environment()->query_name()
#define QN query_name()
#define AO attacker_ob
#define POS query_possessive()
#define TO this_object()
#define TP this_player()
int left, y;
string *msg, *msg1, *msg2, TYPE, COLOR;

reset(arg){
  ::reset(arg);
  if(arg) return;

  left = NEW;
  y = random(4);
  switch(y){
   case 0: TYPE = "Chocolate"; break;
   case 1: TYPE = "Vanilla"; break;
   case 2: TYPE = "Strawberry"; break;
   case 3: TYPE = "Banana"; break;
  }
  get_color();
  set_name("pudding");
  set_short("A "+COLOR+TYPE+NORM+" Pudding Pop");
  set_type("knife");
  set_class(18);
  set_weight(1);
  set_value(5092);
  set_hit_func(TO);
  message_hit = ({
   "suffocates", " with "+COLOR+TYPE+NORM,
   "smear "+COLOR+TYPE+NORM+" all over", "",
   "stab", "",
   "fling some of the "+COLOR+TYPE+NORM+" on", "",
   "splatter "+COLOR+TYPE+NORM+" on", "",
   "drop globs of "+COLOR+TYPE+NORM+" on top of", "",
   "miss","",
  });
}

get_color()
{
  if(TYPE == "Chocolate")
    COLOR = YEL;
  if(TYPE == "Vanilla")
    COLOR = BOLD+WHT;
  if(TYPE == "Strawberry")
    COLOR = BOLD+RED;
  if(TYPE == "Banana")
    COLOR = BOLD+YEL;
}

form_emotes(){
  msg = allocate(7);
  msg1 = allocate(7);
  msg2 = allocate(4);
  msg[0] = ""+COLOR+TYPE+NORM+" flies through the air...\n";
  msg[1] = "Your "+COLOR+TYPE+NORM+" Pudding Pop wiggles madly...\n";
  msg[2] = "Your Pudding pop explodes sending "+COLOR+TYPE+NORM+" everywhere...\n";
  msg[3] = "You hunger for more "+COLOR+TYPE+NORM+"...\n";
  msg[4] = "Your mind is filled with thoughts of Bill Cosby...\n";
  msg[5] = "         J - E - L - L - O...\n";
  msg[6] = "You sing, \"There's always room for J e l l o!\"\n";
  
  msg1[0] = ""+COLOR+TYPE+NORM+" flies through the air from "+EN+"'s Pudding pop...\n";
  msg1[1] = EN+"'s "+COLOR+TYPE+NORM+" pudding pop wiggles madly...\n";
  msg1[2] = EN+"'s pudding pop explodes sending "+COLOR+TYPE+NORM+" everywhere...\n";
  msg1[3] = EN+" hungers for more "+COLOR+TYPE+NORM+"...\n";
  msg1[4] = EN+"'s mid is filled with thoughts of bill Cosby...\n";
  msg1[5] = "        J - E - L - L - O...\n";
  msg1[6] = EN+" sings, \"There's always from for J e l l o!\"\n";

  msg2[0] = "\n\tYour "+COLOR+TYPE+NORM+" pudding pop seems to come alive!\n\n";
  msg2[1] = "\n\tYou are consumed by thoughts of "+COLOR+TYPE+NORM+"!\n\n";
  msg2[2] = "\n\tYou must worship your "+COLOR+TYPE+NORM+" pudding pop!!\n\n";
  msg2[3] = "\n\tYou start to drool uncontrollably!!\n\n";
}

wield(string str)
{
  ::wield(str);
   if(id(str))
   {
     if(TP->query_npc()) return 0;
     form_emotes();
     return 1;
   }
 else return 0;
 return 1;
}

offwield_function()
{
  form_emotes();
}

weapon_class()
{
  if(left <= 500)
    return 14;
  if(left <= 1500)
    return 16;
  if(left <= 2500)
    return 18;
  if(left > 2500)
    return 20;
}

weapon_hit(object attacker)
{
  int a,b,c,d,e,f;
  object stick;
  a = random(10);
  b = random(15);
  c = random(10);
  d = random(5);
  TO->set_hits(0);
  TO->set_misses(0);
  if(!ENV()) return;
  if(ENV()->is_npc()) return;
  if(left <= 0)
  {
    TO->drop();
    wielded = 0;
    wielded_by = 0;
    tell_object(ENV(),
      "\nYour "+TYPE+" pudding pop melts away....\n\n");
    stick = clone_object("/players/fred/forest/Obj/tractus.c");
    move_object(stick, ENV());
    destruct(TO);
    return 0;
  }
  if(!random(5))
  {
    tell_object(ENV(),
      "You're "+COLOR+TYPE+NORM+" pudding pop radiates with power!!\n");
    ENV()->heal_self(1);
    if(!random(3))
    {
      tell_object(ENV(), msg[random(sizeof(msg))]);
      ENV()->add_spell_point(-1);
      left -= random(2);
    }
   } 
   else if(!a)
   {
     e = 1; 
     tell_object(ENV(), msg[random(sizeof(msg))]);
     tell_room(ENV(ENV()), BOLD+BLK+msg1[random(sizeof(msg1))]+NORM, ({ ENV() }));
     ENV()->heal_self(-random(3));
     left -= random(5);
    }
    if(!b)
    {
       tell_object(ENV(), msg[random(sizeof(msg))]);
       tell_room(ENV(ENV()), 
          BOLD+BLU+msg1[random(sizeof(msg1))]+NORM, ({ ENV() }));
       ENV()->add_hit_point(-random(5));
       left -= 2;
       if(!random(2))
       {
         tell_object(ENV(), msg2[random(sizeof(msg2))]);
         ENV()->add_spell_point(-random(3));
       }
     }
     if(!c)
     {
        e = 1;
        f = random(3);
        switch(f)
        {
          case 0:
            tell_object(ENV(),
               "\nYou master the power of the "+COLOR+TYPE+NORM+" pudding pop....\n\n"+
               COLOR+"      *****  ****  *     *     *****   \n"+NORM+
               COLOR+"        *    *     *     *     *   *   \n"+NORM+
               COLOR+"        *    ***   *     *     *   *   \n"+NORM+
               COLOR+"     *  *    *     *     *     *   *   \n"+NORM+
               COLOR+"     ****    ****  ****  ****  *****   \n\n"+NORM+ 
               "A wave of "+TYPE+" rushes over you...\n\n");
            tell_room(ENV(ENV()),
               EN+" masters the power of the "+COLOR+TYPE+NORM+" pudding pop....\n\n"+
               COLOR+"      *****  ****  *     *     *****   \n"+NORM+
               COLOR+"        *    *     *     *     *   *   \n"+NORM+
               COLOR+"        *    ***   *     *     *   *   \n"+NORM+
               COLOR+"     *  *    *     *     *     *   *   \n"+NORM+
               COLOR+"     ****    ****  ****  ****  *****   \n\n"+NORM+               
               "A wave of "+TYPE+" rushes over "+EN+"...\n\n", ({ ENV() }));
            attacker->heal_self(-random(5));
            break;
   
          case 1:
            tell_object(ENV(),
               "\nYou master the power of the "+COLOR+TYPE+NORM+" pudding pop...\n\n"+
               COLOR+"\t\t"+TYPE+" engulfs you...\n\n"+NORM);
            tell_room(ENV(ENV()),
               EN+" masters the power of the "+COLOR+TYPE+NORM+" pudding pop...\n\n"+
               COLOR+"\t\t"+TYPE+" engulfs "+EN+"...\n\n"+NORM, ({ ENV() }));
            attacker->heal_self(-random(3));
            break;
          
          case 2:
            tell_object(ENV(),
               "\nYou write in the power of the "+COLOR+TYPE+NORM+" pudding pop...\n\n");
            tell_room(ENV(ENV()), 
               EN+" writes in the power of the "+COLOR+TYPE+NORM+" pudding pop...\n\n", ({ ENV() }));
            ENV()->heal_self(3);
            break;
          
          }
         left -= 5+random(3);
         return 1; 
        } 
      return random(4);
    }
           