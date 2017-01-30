/* 
// [2006.06.20] Forbin
//   -Revamped the multitude of eweapons into a single inheritable
//   -Changed flawed AC lowering code to use RegisterArmor (based on
//    ~snow/WEAPONS/hon_sword.c - Thanks, Illarion).
//   -Lowered the wear rate on the weapons.
//   -Overcoded weapon_breaks() to prevent permanent breakage
*/
 
inherit "/obj/weapon.c";
#include "/players/snow/closed/color.h"

#define SHORT RED+"~ "+OFF+BLUE+"Ele"+OFF+GREEN+"men"+OFF+BOLD+"tal We"+OFF+GREEN+"ap"+OFF+ BLUE+"on"+OFF+RED+" ~"+OFF

mapping weakened_def;

reset(arg) 
{
  ::reset(arg);
  if(arg) return;
  set_type("weapon");  
}

weapon_hit(object ob) 
{
  int r;
  int dam;
  r = random(16);
  
  if(!environment() || !this_player() || this_player() != environment()) return;

  if(!random(20) && !ob->is_player() && ob->query_ac() > 5) 
  {
    tell_room(environment(ob),
      REV_RED+BOLD+"*** "+ob->query_name()+OFF+REV_RED+BOLD+"'s defenses are weakened! ***\n"+OFF);
    if(!weakened_def) weakened_def = ([ ]);
    if(weakened_def[ob]) 
      weakened_def[ob]--;
    else 
      weakened_def[ob] = -1;
    ob->RegisterArmor(this_object(), ({"physical", weakened_def[ob], 0, 0}));
    return 3; 
  }
  if(!r) 
  {
    earth(ob);
    dam = (int)ob->hit_player(random(5) + 3, "other|earth");
    if(ob)
    if((int)ob->query_spell_point() > 0)
      ob->add_spell_point(-dam);
    return 3;
  }
  if(r == 1) 
  {
    water(ob);
    dam = (int)ob->hit_player(random(8) + 1, "other|water");
    if(ob)
    if((int)ob->query_spell_point() > 0) ob->add_spell_point(-dam);
    return 3;
  }
  if(r == 2) 
  {
    flame(ob);
    dam = (int)ob->hit_player(5 + random(5), "other|fire");
    if(ob)
    if((int)ob->query_spell_point() > 0) ob->add_spell_point(-dam);
    return 3;
  }
  call_out("extra_hit", 3, ob);
  return; 
}

earth(object ob) 
{
  if(!ob) return;
  tell_room(environment(ob),
    BROWN+"\n\t* * THE EARTH SHAKES!\n\n\t"+ob->query_name()+" FALLS TO THE GROUND!\n"+OFF);
  tell_object(ob, 
    BROWN+" * * * * THE EARTH RISES TO CRUSH YOU! * * * * \n"+OFF);
  return 1; 
}

water(object ob) 
{
  if(!ob) return;
  tell_room(environment(ob),
    BLUE+"\n\tTHE SKY GROWS DARK!\n\n\t ,', ,', HAIL CRASHES DOWN FROM THE SKY! ,', ,',\n"+
    "\n\t"+ob->query_name()+" IS PUMMELED BY THE ICE!\n"+OFF);
  tell_object(ob, 
    BLUE+",', ,', THE HAIL SMASHES YOU DOWN! ,', ,',\n"+OFF);
  return 1; 
}

flame(object ob) 
{
  if(!ob) return;
  tell_room(environment(ob),
    RED+"\n\tCRACKS OPEN IN THE EARTH!\n\n\tLAVA SPRAYS FORTH!\n\n\t"+
    ob->query_name()+" SCREAMS IN BURNED AGONY!\n"+OFF);
  tell_object(ob, 
    RED+"\nHOT PAIN RIPS THROUGH YOU!\n");
  return 1; 
}

extra_hit(object ob) 
{
  if(!ob) return;
  
  if(!environment()) return;
  
  if(environment(environment()) != environment(ob)) return;
  
  if(environment()->query_attack() != ob) return;
  
  if(ob->query_hp() < 80) return;
  
  tell_object(environment(),
    BOLD+"You blur in a burst of speed!\n"+OFF+"\n"+
    "You strike "+ob->query_name()+" with your "+SHORT+"\n");
  tell_room(environment(ob),
    BOLD+environment(this_object())->query_name()+" blurs in a burst of speed!\n"+OFF+"\n"+
        environment(this_object())->query_name()+" strikes "+ob->query_name()+
        " with "+environment(this_object())->query_possessive()+" "+SHORT+"\n", ({ environment() }));
  ob->hit_player(random(21));
  return 1; 
}

wield(str) 
{
  if(this_object()->id(str)) 
  {
    if(!present("elemental aura", this_player())) 
    {
      write("The "+SHORT+" burns you with its power!\n");
      return 1; 
    }
  }
  return ::wield(str); 
}

offwield_function() 
{
  if(!present("elemental aura", this_player())) 
  {
    write("The "+SHORT+" burns you with its power!\n");
    return 2; 
  }
  return 0; 
}

int query_wear()
{
  int wear;
  wear = (((3 * misses) / 6) + ((3 * hits) / 10));
  return wear;
}

weapon_breaks()
{
  if(broke) return 1;
  tell_object(environment(this_object()), 
    "Your WEAPON BREAKS!!!!\n");
  set_class(class_of_weapon/3);
  broke = 1;
  if(wielded) 
  {
    if(!offwielded) 
    {
      command("unwield "+name_of_weapon,environment(this_object()));
      command("wield "+name_of_weapon,environment(this_object()));
    } 
    else 
    {
      wielded_by->RemoveWeapon(this_object());
      this_object()->offwield(wielded_by);
    }
  }
  return 1;
}
/*
// [2005.06.22] Forbin
//  -Prevents weapons from affecting exp when modifying AC
*/
no_exp_effect() { return 1; }