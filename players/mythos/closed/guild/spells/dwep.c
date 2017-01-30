/* 
   Revised version of the empowered weapon
   original is dweapon.c
   - Mythos <8-6-96>
*/

/* revised again to fit new rules of wc and ac reductions 
   - Mythos <2-17-97> */

#include "/players/mythos/closed/guild/def.h"

inherit "/obj/weapon";

static int n, once;
static int orgatac, orgatwc;
static object orgatob;
int storage;            /*amount of sp used to create this*/
string owner;           /*making weapon have owner- creator */
int slay, vampire, life, soul_steal, sharp, berserk;
int speed, wounding, spell, norm, ego;
static int bount;
string type_s, path;
static object prev;
static int prevwep;

reset(arg) {
    if (arg)
     return;
     prev = 0;
     prevwep = 0;
    wielded = 0; value = 0; slay = 0; vampire = 0; life = 0; soul_steal = 0;
    sharp = 0; berserk = 0; speed = 0; wounding = 0; spell = 0;
    norm = 0; once = 0; n = 0; ego = 0; long_desc = ""; bount = 0;
    orgatwc = 0; orgatac = 0; orgatob = 0; type_s = ({});
    call_out("wliving",100); 
}

long() {
   int wear;
    write(call_other(clone_object("/"+path+".c"),"long",0));
    write(long_desc);
    write("It is like new.\n");
   if(this_player()->query_level() > 100) { write("Wear = Does not wear down.\n");
    write("Hits = "+hits+"    Misses = "+misses+"\n");
   }
}

init() {
  if(living(ep) && epn != name_of_weapon && epn != owner) { 
     write("When you touch the weapon, the air seems to turn cold...\n");
     write("You feel "+HIB+"COLD DEATH"+NORM+" pass by....\n");
     tp->heal_self(-3);
     say(capitalize(tpn)+" drops "+short_desc+"!\n");
     write("You quickly drop the weapon!\n");
     move_object(this_object(),environment(tp)); 
   return 1;}
   ::init();
    add_action("dgive","give");
}

dgive(str) {
string what, who;
  if(sscanf(str,"%s to %s",what,who) && id(what)) {
    write("You may not do that.\n"); return 1;}
}


read(str) {
    if (!id(str))
        return 0;
    write(call_other(clone_object("/"+path+".c"),"read",alias_name));
    write(read_msg);
return 1;}

save_thing(str){
     save_object(str);
return 1;}
  
restore_thing(str){
      restore_object(str);
return 1;}
   


set_bounty() { bount = 1; }

query_bounty_weapon() { return bount; }

set_storage(s) {storage = s;}

set_owner(str) { owner=str;}

set_slaying(str) { slay = 1; type_s += ({str}); norm = 1;
                long_desc = long_desc + HIR+"Slayer of "+capitalize(str)+NORM+"\n";}

set_vampire() { vampire = 1; norm = 1;
                long_desc = long_desc + BOLD+"Vampiric\n"+NORM;}

set_steal() { soul_steal = 1; norm = 1;
                long_desc = long_desc + HIR+"Soul Stealer\n"+NORM;}

set_life(li) { life = 1; norm = 1; ego = li;}

set_sharp() { sharp = 1; norm = 1;
                long_desc = long_desc + BOLD+"Sharpness\n"+NORM;}

set_berserk() { berserk = 1; norm = 1;
                long_desc = long_desc + BOLD+"Berserker\n"+NORM;}

set_speed() { speed = 1; norm = 1;
                long_desc = long_desc + BOLD+"Speed\n"+NORM;}

set_wound() { wounding = 1; norm = 1;
                long_desc = long_desc + BOLD+"Paralyzing\n"+NORM;}

set_spell() { spell = 1; norm = 1;
                long_desc = long_desc + BOLD+"Spell Cleaver\n"+NORM;}

set_path(str) { path = str; }

query_path() { return path; }

query_wear() { return 1;}

query_gsave() { return 1;}

query_value() { return 0;}

namer() { return "cold";}

weapon_class() { return class_of_weapon;} 

hit(attacker) {
  if(!attacker) return 0;

  if(!norm && random(3)==0)
  { 
    tell_object(attacker,CYN+"        *****   COLD FIRE   *****\n"+NORM);
    write("Your weapon flares!\n");
    tell_room(environment(this_player()),"Cold Fire engulfs the ENEMY!\n");
    return (qtf/3);
  }   
  if(soul_steal && attacker)
  { 
    if(attacker->query_hp() < qtf+1)
    {
      int much;
      much = attacker->query_level();
      tell_room(environment(tp),capitalize(tpn)+" summons "+
        HIC+"lightning"+NORM+" from the sky!\n");
      if(random(5) == 0)
      {
        tp->heal_self(much * 3);
        {
          object ac_mod;
          ac_mod = clone_object("/players/mythos/closed/guild/spells/ac_modifier");
          move_object(ac_mod, attacker);
          ac_mod->start_it(attacker->query_ac() / 3, 1000);
          write(BOLD+"You feed upon the soul of your enemy!\n"+NORM);
        }
        return 30;
      }
    }
  }
                  
  if(slay && attacker && random(3)==0)
  { 
    int P;
    for(P=0;P<sizeof(type_s);P++)
    {
      if(type_s[P])
      {
       if(attacker->id(type_s[P]))
       {
         write("The weapon quivers as you hit its foe!\n");
         tell_room(environment(this_player()),BLU+
         "\n            F  L  A  R  E\n\n"+NORM);
         if(attacker->query_hp() > qtf/2)
            attacker->hit_player(qtf/2, "other|dark");
       }
      }
    }
  }
  if(vampire && attacker && random(3)==0)
  { 
    if(attacker->query_hp() > qtf/4)
    {
      if(!(attacker->query_soul()))
        attacker->heal_self(-qtf/4);
    }
    tp->heal_self(qtf/4);
    tell_room(environment(this_player()),
    "There is a sudden wrenching in the space of reality!\n");
    write("You feel invigorated as the essence of the attacker becomes yours!\n");
  }
  if(berserk && attacker && random(3)==0)
  { 
    if(tp->query_hp() < (tp->query_mhp())/3 && tp->query_wc() < qtf+5)
    {
      tp->set_wc(tp->query_wc() + 1); 
      write("You feel stronger as "+HIR+"RAGE"+NORM+" fills you!\n");
      tell_room(environment(tp),capitalize(tpn)+" goes berserk!  Motions are ablur!\n");
    } 
    if(tp->query_hp() > (tp->query_mhp())*5/12 && 
        tp->query_wc() > class_of_weapon)
    {
      write(BLU+"Your berserk rage cools...\n"+NORM);
      tp->set_wc(class_of_weapon); 
    }
  }
  if(wounding && attacker && random(5)==0)
  { 
    attacker->set_heal(2,666);
    write("You feel a sharp pain as your weapon draws power from\n"+
          "you to stop the attacker's healing process!\n");
    tp->heal_self(-random(10));
  }
  if(spell && attacker && random(3)==0)
  { 
    write("The enemy's magic is diminished!\n");
    say(BOLD+"\nDARKNESS floods the room!\n\n"+NORM);
    if(attacker->query_hp() > qtf)
    {
      if(!(attacker->query_soul()))
        attacker->hit_player(qtf/2,"other|dark");
    }
  }
  if(speed && attacker && random(3)==0 && n == 0)
  { 
    if(attacker->query_hp() > 20)
    {
      switch(random(3))
      {
        case 0:  n = 1;
           tell_room(environment(tp),"The "+short()+" flares!\nThe motions of "+
            capitalize(tpn)+" are ablur!\n");
            if(!attacker || attacker->query_hp() < 20) { n = 0; return 0; break; }
             hit(attacker); 
             if(!attacker || attacker->query_hp() < 20) { n = 0; return 0; break; }
             tp->attack(); 
             if(!attacker || attacker->query_hp() < 20) { n = 0; return 0; break; }
        case 1: n = 1; 
           tell_room(environment(tp),"The "+short()+" flares!\nThe motions of "+
            capitalize(tpn)+" are ablur!\n");
            if(!attacker || attacker->query_hp() < 20) { n = 0; return 0; break; }
            hit(attacker); 
            if(!attacker || attacker->query_hp() < 20) { n = 0; return 0; break; }
            tp->attack();
            if(!attacker || attacker->query_hp() < 20) { n = 0; return 0; break; }
        case 2: n = 1; 
            tell_room(environment(tp),
            "The "+short()+" flares!\nThe motions of "+
             capitalize(tpn)+" are ablur!\n");
             if(!attacker || attacker->query_hp() < 20) { 
             n = 0; return 0; break; }
             hit(attacker); 
             if(!attacker || attacker->query_hp() < 20) { 
             n = 0; return 0; break; }
             tp->attack();
           n = 0; break;
      }
    }
  }
  if(sharp && attacker && random(10)==0)
  { 
    if(attacker->query_wc() > 13 && !(attacker->query_soul()))
    { 
      object wc_modifier;
      wc_modifier = clone_object("/players/mythos/closed/guild/spells/wc_modifier");
      move_object(wc_modifier, attacker);
      wc_modifier->start_it(attacker->query_wc() / 4, 1000);
    }
    write("You slice through the enemy's weapons!\n");
  }
  return 0;
}

weapon_breaks(){
object ob, cm;
int burst;
burst=storage/50;
if(random(3) > 0) { tell_object(ep,"The "+short_desc+" almost breaks!\n"); return 1;}
if(living(ep)) { cm = environment(ep); 
                 tell_object(ep,"Your WEAPON SHATTERS!!!!!\n");
                 ep->heal_self(-burst);}
else { cm = environment(this_object()); }
    tell_room(cm,BOLD+"\nSUDDENLY,\n\n"+NORM+HIC+
              "\tThere is a brilliant flash!\n\n\t\tCOLD FIRE is everywhere!\n\n"+NORM);
     ob=first_inventory(cm);
  while(ob) {
    if(living(ob) && (0==random(2))) {
      ob->heal_self(-random(burst));
      }
      ob = next_inventory(ob);}
      destruct(this_object());
return 1;} 

wliving() {
if(life && ep) {
  if(living(ep) && ep->query_real_name() == owner && 
     ego > ep->query_attrib("wil")) { weapon_breaks(); return 1;}
   if(living(ep)) {
   tell_object(ep,"Deep in your soul you feel a sudden chill....\n");
   ep->add_spell_point(-3-random(10));
   if(random(2)) ep->set_ac(ep->query_ac() - 1);
   }
  }
  call_out("wliving",500+random(1000));
return 1;}

cleanup() { fix_weapon(); misses = 0; hits = 0; }

fix_weapon() { return 1;}

add_wear(x) { return; }

count_misses() { return 1; }
count_hit_made() { return 1; }
