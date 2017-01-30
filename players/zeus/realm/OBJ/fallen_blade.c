/* Fallen Blade 2
 weight 4, wc 19, multiple specials, dual hits
 only available once every 7.5-15 days at most
 found on /players/zeus/realm/NPC/mist_creature.c
 non-storable, hurts wielder.
            VS AC 17:   Damage:  3362
                        Rounds:  450
                        Average: 7.471       */

inherit "/obj/weapon.c";
#include "/players/zeus/closed/all.h"
#define Y tell_object(environment()
#define Z tell_room(environment(environment())
#define NM environment()->query_name()
#define MN meat->query_name()
#define HE environment()->query_pronoun()
#define HIS environment()->query_possessive()
string *atk2;

reset(arg) {
   ::reset(arg);
   if (arg) return;

  set_name("fallen blade");
  set_alias("blade");
  set_type("sword");
  set_short("The Blade of the Fallen");
  set_long(
"This is the legendary Blade of the Fallen.  The hilt is black, with\n"+
"sharp points at the base.  The blade is narrow and has carvings of\n"+
"ghosts all along it.  There is an inscription at the base of the hilt.\n");
  set_value(1800);
  set_weight(4);
  set_class(19);
  set_read("The inscription reads:\n"+
    "   This is the sword of the Knight Patrick Jacobs.\n"+
    "   My endless tool of destruction, you are dead.\n");
  set_hit_func(this_object());
  message_hit=({
    HIR+"ripped open"+NORM," with a bloody vengeance",
    BOLD+BLK+"slashed into"+NORM," with fearsome strength",
    "tore open"," leaving a gaping wound",
    "tore into"," with a wicked cut",
    "slit"," with bloody precision",
    "grazed","",
    "grazed","",
  });
}

fix_weapon()
{ 
  if(!broke) return 0;
  if(broke)
  {
    broke = 0;
    misses = 0;
    class_of_weapon = 18;  /* -1 wc */
    hits = 0;
    write("The weapon has been fixed.\n");
    long_desc =
      "This is the legendary Blade of the Fallen.  The hilt is black, with\n"+
      "sharp points at the base.  The blade is narrow and has carvings of\n"+
      "ghosts all along it.  There is an inscription at the base of the hilt.\n";
    return 1;
  }
}

weapon_breaks()
{
  if(broke) return 1;
  Y, "\nThere is a sudden flash of "+HIY+"LIGHT"+NORM+"...\n"+
     "Your Blade of the Fallen has broken.\n\n");
  class_of_weapon = 6;
  broke = 1;
  command("unwield "+name_of_weapon,environment(this_object()));
  command("wield "+name_of_weapon,environment(this_object()));
  long_desc =
"This is the legendary Blade of the Fallen.  The hilt is black, with\n"+
"sharp points at the base.  The blade is narrow and has carvings of\n"+
"ghosts all along it.  There is an inscription at the base of the hilt.\n"+
"The blade is cracked down the middle and has a faint blue tint.\n";
  return 1;
}

string second(int a)  /* dual hit messages */
{
  if(a >= 30)
    atk2 = ({message_hit[0],message_hit[1]});
  else if(a > 26)
    atk2 = ({message_hit[2],message_hit[3]});
  else if(a > 20)
    atk2 = ({message_hit[4],message_hit[5]});
  else if(a > 14)
    atk2 = ({message_hit[6],message_hit[7]});
  else if(a > 8)
    atk2 = ({message_hit[8],message_hit[9]});
  else if(a > 4)
    atk2 = ({message_hit[10],message_hit[11]});
  else
    atk2 = ({message_hit[12],message_hit[13]});
}


int weapon_hit(object meat)
{
  int c, a, b;
  c--;
  if(broke) return 0;
  if(0 == random(3) && c <= 0)  /* dual hit */
  {
    a = random(30);
    second(a);
    b = 2+random(a / 3);
    if(environment()->query_level() > 21)
      Y, HIR+"A:  "+a+", B:  "+b+"\n"+NORM);
    Y, "You "+atk2[0]+" "+MN+atk2[1]+".\n");
    Z, NM+" "+atk2[0]+" "+MN+atk2[1]+".\n", ({ environment() }));
    if(meat->is_player())
      meat->add_hit_point(-b);
    else
      meat->heal_self(-b);
  }

  if(0 == random(20) && c <= 0)
  {
    Y, RED+"You are filled with bloodlust.\n"+NORM);
    Z, RED+NM+" is filled with bloodlust.\n"+NORM, ({ environment() }));
    environment()->add_hit_point(-15);  /* hurt wielder */
    if(!meat->query_ghost() && c <= 0)  /* dual hit */
    {
      a = random(40);
      second(a);
      b = 2+random(a / 3);
      if(environment()->query_level() > 21)
        Y, HIR+"A:  "+a+", B:  "+b+"\n"+NORM);
      Y, "You "+atk2[0]+" "+MN+atk2[1]+".\n");
      Z, NM+" "+atk2[0]+" "+MN+atk2[1]+".\n", ({ environment() }));
      if(meat->is_player())
        meat->add_hit_point(-b);
      else
        meat->heal_self(-b);
      c = 3;
      return 8;
    }
  }
  else if(0 == random(15))
  {
    Y, "The Blade of the Fallen blurs as you swing into "+MN+"!\n");
    Z, NM+"'s blade blurs as "+HE+" swings into "+MN+"!\n", 
      ({ environment() }));
    meat->heal_self(-10);
    if(meat->is_player())
      meat->add_spell_point(10);
    return 4;
  }
  else if(0 == random(7))
  {
    Y, "Your movements blur as you rip into "+MN+".\n");
    Z, NM+"'s movements blur as "+HE+" rips into "+MN+".\n", 
      ({ environment() }));
    if(!meat->query_ghost() && c <= 0)  /* dual hit */
    {
      a = random(33);
      second(a);
      b = 2+random(a / 3);
      if(environment()->query_level() > 21)
        Y, HIR+"A:  "+a+", B:  "+b+"\n"+NORM);
      Y, "You "+atk2[0]+" "+MN+atk2[1]+".\n");
      Z, NM+" "+atk2[0]+" "+MN+atk2[1]+".\n", ({ environment() }));
      if(meat->is_player())
        meat->add_hit_point(-b);
      else
        meat->heal_self(-b);
      c = 3;
    }
    return 4;
  }
  else if(c < -10)
  {
    Y, "You plunge your blade deep into "+MN+"!\n");
    Z, NM+" plunges "+HIS+" blade deep into "+MN+"!\n", ({ environment() }));
    c = 0;
    meat->heal_self(-12);
    return 12;
  }
  else if(0 == random(20))
  {
    Y, RED+"\n\n ** "+NORM+
       "You cleave "+MN+" with the Blade of the Fallen.\n"+
       RED+" ************************ "+NORM+
       "Bloody Gore erupts forth!\n\n\n");
    Z, RED+"\n\n ** "+NORM+
       NM+" cleaves "+MN+" with "+HIS+" Blade of the Fallen.\n"+
       RED+" ************************ "+NORM+
       "Bloody Gore erupts forth!\n\n\n", ({ environment() }));
    meat->heal_self(-4);
    return 4;
  }
  else if(0 == random(20))
  {
    Y, "\n\tYour blade glints as you descend upon "+MN+"\n\n"+
      RED+"\t\tBlood rushes forth!\n\n"+NORM);
    Z, "\n\t"+NM+"'s blade glints as "+HE+" descends upon "+MN+"\n\n"+
      RED+"\t\tBlood rushes forth!\n\n"+NORM, ({ environment() }));
    meat->heal_self(-6);
    return 4;
  }
  if(0 == random(1250))
  {
    Y, HIW+"\nA white hot vortex of light consumes your blade.\n\n"+NORM);
    Z, HIW+NM+"'s blade emits a white hot vortex of light.\n"+NORM,
      ({ environment() }));
    broke = 0;
    misses = 0;
    class_of_weapon = 19;
    hits = 0;
    environment()->hit_player(20);  /* hurt wielder */
    return 4;
  }
}
