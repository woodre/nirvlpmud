/**********************************************************/
/* Must have mag 20 and evil align to wield.
/* low weight, slow wear, heal_self specials, hurts wielder.
/* Keeps wielder evil, can drain mag stat.
/* Not storable.
/* Changes from original:   wears much faster.
/*                          less likely to drain mag.
/*                          no heart beat
/*                          specials more effective
/*                          alignment change more drastic
/*                          took out the aura_spell entirely
/*                          wc 10,14,19,20 [level based]
/*                          more messages added.
/*                          drains hps frequently, can heal sps
/*         -Approved by:  Snow  [9.7.99]
/**********************************************************/

inherit "/obj/weapon.c";
#include "/players/zeus/closed/all.h"
#define EA +BOLD+"Dark Aura"+NORM+
/* 11/22/05 Earwax changed to environment(this_object()) - was bugging */
#define EV environment(this_object())
#define TQL  (int)environment()->query_level()
#define TQA  (int)environment()->query_alignment()
#define EQL  (int)environment()->query_level()
#define EQA  (int)environment()->query_alignment()
#define TQN  +target->query_name()+
#define TQO  +target->query_objective()+
#define TPN  +environment()->query_name()+
#define TPO  +environment()->query_objective()+
#define TPP  +environment()->query_possessive()+
#define MAX 3000                /*  max life of wep */
int strength, msg, one, two, total;
string *msg1, *msg2, *msg3;

reset(arg)
{
   ::reset(arg);
   if (arg) return;

  strength = MAX;
  set_name("aura");
  set_short(BOLD+"Dark Aura"+NORM);
  set_weight(1);
  set_class(19);
  set_value(6690);
  set_read(0);
  set_type("magic");
  /* change hit func to deal evil damage - ill
  set_hit_func(TO);
  */
  set_params("other|evil",0,"evil_hit");
  message_hit=({
    "unleashed the energy of the "EA" on","",
    "unleashed the energy of the "EA" on","",
    "unleashed the energy of the "EA" on","",
    "focused the energy of the "EA" on","",
    "focused the energy of the "EA" on","",
    "released the energy of the "EA" on","",
    "released the energy of the "EA" on","",
  });
}
query_dest_flag(){    return 1; }

define_arrays()
{
  msg1 = allocate(10);
  msg2 = allocate(10);
  msg3 = allocate(4);
  msg1[0]= "A ripple of darkness escapes from the "EA"...\n";
  msg1[1]= "Your "EA" releases a powerful wave of darkness...\n";
  msg1[2]= "Your "EA" pulses violently...\n";
  msg1[3]= "Your "EA" fills you with evil energy...\n";
  msg1[4]= "You give in to the power of the "EA"...\n";
  msg1[5]= "Your body is filled with darkness...\n";
  msg1[6]= "Dark flames dance across your glowing body...\n";
  msg1[7]= "Your "EA" explodes in a firey mass of darkness...\n";
  msg1[8]= "You struggle to keep your "EA" under control...\n";
  msg1[9]= "Strands of energy lash out of the "EA"...\n";

  msg2[0]= "A ripple of darkness escapes from "TPN"'s "EA"...\n";
  msg2[1]= EV->QN+"'s "EA" releases a powerful wave of darkness...\n";
  msg2[2]= EV->QN+"'s "EA" pulses violently...\n";
  msg2[3]= EV->QN+" is consumed with evil energy...\n";
  msg2[4]= EV->QN+" gives in to the power of "TPP" "EA"...\n";
  msg2[5]= EV->QN+"'s body is filled with darkness...\n";
  msg2[6]= "Flames of darkness dance across "+EV->QN+"'s body...\n";
  msg2[7]= EV->QN+"'s "EA" explodes in a firey mass of darkness...\n";
  msg2[8]= EV->QN+" struggles to keep "TPP" "EA" under control...\n";
  msg2[9]= "Strands of energy lash out of "+EV->QN+"'s "EA"...\n";

  msg3[0]= "\n\t\tYour Dark Aura surges with energy!\n\n";
  msg3[1]= "\n\t\tYour Dark Aura explodes with darkness!\n\n";
  msg3[2]= "\n\t\tDark energy consumes you!\n\n";
  msg3[3]= "\n\t\tYou are engulfed in dark chaos!\n\n";
}

long()
{
        write(
"The Dark Aura is what appears to be a cloud of darkness.  At the center\n"+
"the aura is pure darkness, and it gets lighter as it radiates out.  The\n"+
"aura is constantly writhing about, almost as though it is alive.  To be\n"+
"able to harness the power of the aura, one would need to be a master of\n"+
"magic, and of an incredibly evil nature.  The aura ");
    if(strength > MAX * 9 / 10) write("is very strong.\n");
    if(strength > MAX * 7 / 10 && strength <= MAX * 9 / 10)
      write("is strong.\n");
    if(strength > MAX * 5 / 10 && strength <= MAX * 7 / 10)
      write("is getting weak.\n");
    if(strength > MAX * 3 / 10 && strength <= MAX * 5 / 10)
      write("is weak.\n");
    if(strength > MAX / 10 && strength <= MAX * 3 / 10)
      write("is very weak.\n");
    if(strength <= MAX / 10)  write("is almost gone.\n");
}

extra_look()
{
  if(EV->is_player())
  {
    if(EV->query_weapon() == TO)
    {
    	if(EV == this_player())
    	   return "A "+BOLD+"Strange Darkness "+NORM+" swirls around your fist";
    	else
    	  return "A "+BOLD+"Strange Darkness "+NORM+" swirls around "+EV->QN+"'s fist";
    }
  }
}

wield(string str)
{
  this_object()->update_wc();
  ::wield(str);
  if(id(str))
  {
    if(TP->query_npc()) return 0;
    define_arrays();
    if(TP->query_real_name() == "ztest")
    {
      write("Welcome Ztest.  Alignment set to good.\n\n");
      TP->add_alignment(1600);
      return 1;
    }
    if(TP->query_attrib("mag") < 20)
    {
      write("You suddenly feel drained by the aura...\n");
      TP->add_hit_point(-15-random(50));
      call_other(TP,"stop_wielding");
      wielded = 0;
      wielded_by = 0;
      return 1;
    }
    if(TP->query_alignment() >= 0 && TP->query_level() < 20)
    {
      write("You suddenly feel drained by the aura...\n");
      TP->add_hit_point(-15-random(50));
      call_other(TP,"stop_wielding");
      wielded=0;
      wielded_by=0;
      return 1;
    }
    return 1;
  }
  else return 0;
  return 1;
}

offwield_function()
{
  this_object()->update_wc();
  if(TP->query_attrib("mag") < 20)
  {
    write("You suddenly feel drained by the aura...\n");
    TP->add_hit_point(-15-random(50));
    return 2;
  }
  if(TP->query_alignment() >= 0)
  {
    write("You suddenly feel drained by the aura...\n");
    TP->add_hit_point(-15-random(50));
    return 2;
  }
  define_arrays();
}

/* changes to weapon.c make this ineffective...
   changing to an update system on wield instead - illarion
weapon_class()
{
  if(EV->query_level() <= 6)
    return 10;
  if(EV->query_level() < 15 && EV->query_level() > 6)
    return 14;
  if(EV->query_extra_level() < 5 && EV->query_level() >=15)
    return 19;
  if(EV->query_extra_level() >= 5)
    return 20;
}
*/
update_wc() {
  if(!EV) return;
  switch(EV->query_total_level()) {
    case 1..6: return set_class(10);
    case 7..14: return set_class(14);
    case 15..23: return set_class(19);
    default: return set_class(20);
  }
}

alignment()   /*  Align changed by 100-200 */
{
  if(EQL != 30)
    EV->add_alignment(EQA * 2 / (30 - EQL) - (100+random(100)));
  else 
    tell_object(EV, HIR+"Alignment not changed, level 30!\n"+NORM); 
}

int evil_hit(object target)
{
  int extra_dam;
  int v, w, y, z, randmsg;
  v = random(4);
  w = random(9);
  y = random(20);
  z = random(500);
  this_object()->set_hits(0);
  this_object()->set_misses(0);
  if(!environment()) return 0;
  if(environment()->is_npc()) return 0;
  if(strength <= 0)
  {
    this_object()->drop();
    wielded=0;
    wielded_by=0;
    tell_object(environment(),
      "\nThe "EA" becomes so faint that it fades away...\n\n");
    destruct(this_object());
    return 0;
  }
  if(!random(4))
  {
    tell_object(EV, BOLD+BLK+
      "The aura pulses as it drains your strength.\n"+NORM);
    EV->add_hit_point(-1);
    if(!random(3))
    {
      tell_object(EV, msg1[random(sizeof(msg1))]);
      EV->add_spell_point(1);
    }
  }
  else if(!v)
  {
    w = 1; y = 1;
    tell_object(EV, msg1[random(sizeof(msg1))]);
    tell_room(environment(EV), msg2[random(sizeof(msg2))], ({ EV }));
    if(!random(3))
      tell_object(EV,BOLD+BLK+msg3[random(sizeof(msg3))]+NORM);
    alignment();
    strength -= 3;
  }
  if(!w)
  {
    y = 1;
    randmsg = random(5);
    switch(randmsg)
    {
    case 0:
      tell_object(EV,"\nYou harness the power of the "EA"...\n\n"+
        BOLD+"\t--\t---\t----------\t---\t--\n"+NORM+
        BOLD+"\t\t-----\t\t-----\t---\t\t-------\n"+NORM+
        BOLD+"\t--\t---\t----------\t---\t--\n\n"+NORM+
        "A funnel of dark energy rips through "TQN"...\n\n");
      tell_room(environment(EV),
        EV->QN+" harnesses the power of the "EA"...\n\n"+
        BOLD+"\t--\t---\t----------\t---\t--\n"+NORM+
        BOLD+"\t\t-----\t\t-----\t---\t\t-------\n"+NORM+
        BOLD+"\t--\t---\t----------\t---\t--\n\n"+NORM+
        "A funnel of dark energy rips through "TQN"...\n\n", ({ EV }));
      /* replace with return value -ill
      target->heal_self(-3-random(6));
      */
      extra_dam+=3+random(6);
      break;
        case 1:
      tell_object(EV,"\nYou harness the power of the "EA"...\n\n\n"+
        BOLD+"\t\tFLAMES OF DARKNESS"+NORM+" engulf "TQN" ...\n\n"+
        ""TQN" writhes in burning agony....\n");
      tell_room(environment(EV),
        EV->QN+" harnesses the power of the "EA"...\n\n\n"+
        BOLD+"\t\tFLAMES OF DARKNESS"+NORM+" engulf "TQN" ...\n\n"+
        ""TQN" writhes in burning agony....\n", ({ EV }));
      extra_dam+=3+random(6);
      /* replace with return value - ill
      target->heal_self(-3-random(6));
      */
      break;
        case 2:
      tell_object(EV,
        "\nThe "EA" wraps you in a cloak of darkness...\n"+
        "\t\tYou feel slightly healed...\n\n");
      tell_room(environment(EV),
        EV->QN+" is wrapped in a cloak of darkness...\n", ({ EV }));
      EV->heal_self(3+random(6));
      break;
    case 3:
      tell_object(EV,
        "\nThe "EA" explodes in a dark vortex of energy...\n"+
        "Lashes of evil energy tear into you and "TQN"!\n\n");
      tell_room(environment(EV),
        EV->QN+"'s "EA" explodes in a dark vortex of energy...\n"+
        "Lashes of evil energy tear into "TPN" and "TQN"!\n", ({ EV }));
      EV->hit_player(15);
      /* replace with return value -ill
      if(target->query_hp() > 4)
        target->hit_player(5);
      else
        target->hit_player(1);
        */
      extra_dam+=5;
      break;
        case 4:
      tell_object(EV,"\nYou harness the power of the "EA"...\n\n");
      tell_object(EV,BOLD+"\t\t       /\\/\\/\\/\\/\\/\\/\\/\\/\\/\\");
      tell_object(EV,"/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n");
      tell_object(EV,"\t\t/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\");
      tell_object(EV,"/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n");
      tell_object(EV,"\t\t       /\\/\\/\\/\\/\\/\\/\\/\\/\\/\\");
      tell_object(EV,"/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n\n"+NORM);
      tell_object(EV,"Waves of dark power devastate "TQN"!\n");
      tell_room(environment(EV),
        EV->QN+" harnesses the power of the "EA"...\n\n", ({ EV }));
      tell_room(environment(EV),
        BOLD+"\t\t       /\\/\\/\\/\\/\\/\\/\\/\\/\\/\\", ({ EV }));
      tell_room(environment(EV),
        "/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n", ({ EV }));
      tell_room(environment(EV),
        "\t\t/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\", ({ EV }));
      tell_room(environment(EV),
        "/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n", ({ EV }));
      tell_room(environment(EV),
        "\t\t       /\\/\\/\\/\\/\\/\\/\\/\\/\\/\\", ({ EV }));
      tell_room(environment(EV),
        "/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n\n"+NORM, ({ EV }));
      tell_room(environment(EV),
        "Waves of dark power devastate "TQN"!\n", ({ EV }));
      /* replace with return value -ill
      if((int)target->query_ac() > 20 && target->query_hp() > 20)
        target->hit_player(20);
      else if(target->query_hp() > (int)target->query_ac())
        target->hit_player((int)target->query_ac());
      else
        target->heal_self(-5);
      */
      if((int)target->query_ac() > 20) extra_dam+=20;
      else extra_dam+=(int)target->query_ac();
      break;
    }
    strength -=6;
    /* make extra dam a bit higher since it's auto-randomized */
    extra_dam=3*extra_dam/2;
    return 1+extra_dam;
  }
  if(!y)
  {
    int damage, bad, go;
    go = random(5);
    tell_object(EV,"An intense energy pulls at your soul...\n"+
      "A darkness invades your mind, then explodes outwards...\n");
    if(EV->query_extra_level() > 0 && go)
    {
      damage = (int)EV->query_extra_level();
      /* woah.  that could get a bit high */
      if(damage>30) damage=30; /* this becomes random(damage) when returned */
      tell_object(EV,
        "\n\t\t"+BOLD+"DARKNESS "+NORM+" rips into "TQN"!\n\n");
      tell_room(environment(EV),
        "\n\t\t"+BOLD+"DARKNESS "+NORM+" rips into "TQN"!\n\n", ({ EV }));
      /* replace with return val - ill
      if(target->query_hp() > damage)
        target->hit_player(damage);
      else
        target->heal_self(-damage);
        */
      return damage;  /* this should be plenty o damage for anyone */
    }
    else if(!go)
      return 7;
    if(EV->query_extra_level() == 0 && TQL <= 19)
    {
      bad = (int)EV->query_level();
      tell_object(EV,
        "\n\t\t"+BOLD+"DARKNESS "+NORM+" rips apart your mind!\n\n");
      tell_room(environment(EV),
        "\n\t\t"+BOLD+"DARKNESS "+NORM+" rips apart "TPN"'s mind!\n\n",
        ({ EV }));
      EV->hit_player(bad);
    }
    strength -= 5;
  }
  if(!z)
  {
    if(random(2))
    {
      tell_object(EV,
        "\nThere is a sudden wrenching as the "EA" flares...\n"+
        "\t\tThe evil darkness pulls at your soul...\n");
      EV->set_attrib("mag", (int)EV->query_attrib("mag") - 1);
      tell_object(EV,"\t\tYou magic is now at "+
        HIR+EV->query_attrib("mag")+NORM+"\n\n");
      tell_room(environment(EV),
        EV->QN+" staggers, looking weak and drained.\n", ({ EV }));
      EV->heal_self(-15);
      EV->save();
      EV->reset(1);
    }
  }
  return 5;
}

/*  [addition] -Forbin 2005.6.12 to support saving.  */
string locker_arg() { 
	
	return "&Strength&"+strength+"";	
}

void locker_init(string arg) { 
  int t1;
  sscanf(arg, "&Strength&%d", t1);
  strength = t1;
}

status restore_thing(string arg) { 
  restore_object(arg); 
  return 1; 
}

status save_thing(string arg) { 
  save_object(arg); 
  return 1; 
}

status generic_object() { 
  return 1; 
}
/*  [end addition] -Forbin 2005.06.02  */
