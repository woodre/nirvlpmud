/* This Code is directly adapted from the Power Ranger Guild Weapon.
   Special Thanks to Beck for supplying it. */
   
static status wielded;
static object wielded_by;
static int broke;
static int eff_wc;
static int misses,hits;
static int save_flag,class_of_weapon;
static object hit_func;
static string hit_func_fn;
static string type;
static string *message_hit;
static int dmg;

weapon_class(){ return class_of_weapon; }

hit(attacker)
{
  if(hit_func)
    return call_other(hit_func,"weapon_hit",attacker);
  return 0;
}

set_class(c){ class_of_weapon = c; }

weapon_breaks()
{
  if(broke) return 1;
  return 1;
}

count_misses()
{
  misses += 1;
  return 1;
}

count_hit_made(w)
{
  hits += 1;
  eff_wc=((hits-1)*eff_wc + w)/hits;
  return 1;
}

query_broke(){  return broke; }
query_pro_weapon(){ return 1; }
query_wear(){   return 0; }

add_wear(arg)
{
  misses = 0;
  hits = 0;
}

fix_weapon()
{
  if(!broke) 
  {
    return 0;
  }
  broke = 0;
  return 1;
}

re_break()
{ 
  broke = 1;
  return 1;
}

set_hit_func(ob)
{
  string junka,junkk;
  hit_func = ob;
  if(sscanf(file_name(ob),"%s#%s",junka,junkk) == 2)
    hit_func_fn = "/"+junka;
  else
    hit_func_fn = "/"+file_name(ob);
}

query_hit_func(){ return hit_func; }

proficiency_hit(ob)
{
  string mess1,mess11,mess2,mess22;
  int base, hyper;
  int dam1, dam2, dam3, dam4;
  int rand1, rand2, rand3, rand4;

  dam1 = 0;
  dam2 = 0;
  dam3 = 0;
  dam4 = 0;
  hyper = 0;
  base = 0;
  rand1 = random(100);
  rand2 = random(100);
  rand3 = random(100);
  rand4 = random(100);

  base = random(USER->query_attrib("str"));

  if(base < 15) base = 15;
  if(base > 19) base = 19;

  if((int)GOB->query_bitestat() > 100 && random(1000) < 5)
  {
    GOB->add_bitestat(-1);
  }
  if((int)GOB->query_slamstat() > 100 && random(100) < 5)
  {
    GOB->add_slamstat(-1);
  }
  if((int)GOB->query_hardened())
  {
    base -= 4;
    if(USER->QL > 19 || USER->QRN == "toy")
      TOM HIG+"Symb bonus is "+base+" when hardened!"+NORM+"\n"); 
    return base;
  }
  if((int)GOB->query_shaped() && (string)GOB->query_shapetype() != "shield")
  {
    if((string)GOB->query_shapetype() == "sword")
    {
      switch(random(10))
      {
        case 7..100:
          mess1 = "slash";
          mess11 = "slashes";
          break;
        case 4..6:
          mess1 = "stab";
          mess11 = "stabs";
          break;
        case 1..3:
          mess1 = "slice";
          mess11 = "slices";
          break;
        default:
          mess1 = "stab";
          mess11 = "stabs";
          break;
      } 
    }
    else if((string)GOB->query_shapetype() == "maul")
    {
      switch(random(10))
      {
        case 7..100:
          mess1 = "smash";
          mess11 = "smashes";
          break;
        case 4..6:
          mess1 = "slam";
          mess11 = "slams";
          break;
        case 1..3:
          mess1 = "hit";
          mess11 = "hits";
          break;
        default:
          mess1 = "hit";
          mess11 = "hits";
          break;
      } 
    }
    else if((string)GOB->query_shapetype() == "spear")
    {
      switch(random(10))
      {
        case 7..100:
          mess1 = "stab";
          mess11 = "stabs";
          break;
        case 4..6:
          mess1 = "impale";
          mess11 = "impales";
          break;
        case 1..3:
          mess1 = "thrust";
          mess11 = "impales";
          break;
        default:
          mess1 = "impale";
          mess11 = "impales";
          break;
      } 
    }
    else if((string)GOB->query_shapetype() == "axe")
    {
      switch(random(10))
      {
        case 7..100:
          mess1 = "chop";
          mess11 = "chops";
          break;
        case 4..6:
          mess1 = "cleave";
          mess11 = "cleaves";
          break;
        case 1..3:
          mess1 = "slash";
          mess11 = "slashes";
          break;
        default:
          mess1 = "slash";
          mess11 = "slashes";
          break;
      } 
    }
    switch(random(10))
    {
      case 7..100:
        mess2 = "chest";
        break;
      case 4..6:
        mess2 = "arm";
        break;
      case 1..3:
        mess2 = "leg";
        break;
      default:
        mess2 = "arm";
        break;
    } 
    if(mess1 && mess2 && USER->query_attack())
    {
      TOM ""+HIR+"<"+HIW+(string)GOB->query_shapetype()+NORM+HIR+">"+NORM+" You "+mess1+" "+ATT->QN+" in the "+mess2+"!\n");
      TRM USER->QN+" "+mess11+" "+ATT->QN+" in the "+mess2+" with his "+(string)GOB->query_shapetype()+" arm!\n", ({ USER }));
    }
    base += random(USER->query_attrib("str") / 4) + 6;
  }
  if(rand1 < (1 + USER->QL))
  {
    dam1 = slamtwo();
  }
  else if(rand1 < (30 + USER->QL))
  {
    dam1 = bitetwo();
  }
  else if(rand1 < (40 + USER->QL))
  {
    dam1 = kicktwo();
  }
  else if(rand1 < (50 + USER->QL))
  {
    dam1 = clawstwo();
  }
  if(USER->QL > 9)
  {
    if(rand2 < (30 + USER->QL))
    {
      dam2 = bitetwo();
    }
    else if(rand2 < (40 + USER->QL))
    {
      dam2 = kicktwo();
    }
    else if(rand2 < (55 + USER->QL))
    {
      dam2 = clawstwo();
    }
  } 
  else
  { 
    dam2 = 0; 
  }
  if((int)GOB->query_hyper_mode())
  {
    if(rand3 < (20 + USER->QL))
    {
      dam3 = slamtwo();
    }
    else if(rand3 < (40 + USER->QL))
    {
      dam3 = bitetwo();
    }
    else if(rand3 < (60 + USER->QL))
    {
      dam3 = kicktwo();
    }
    else if(rand3 < (75 + USER->QL))
    {
      dam3 = clawstwo();
    }	  
    if(rand4 < (20 + USER->QL))
    {
      dam4 = slamtwo();
    }
    else if(rand4 < (40 + USER->QL))
    {
      dam4 = clawstwo();
    }	
    else if(rand4 < (60 + USER->QL))
    {
      dam4 = bitetwo();
    }
    else if(rand4 < (75 + USER->QL))
    {
      dam4 = kicktwo();
    }
    if(!USER->query_pl_k())
      hyper += 5 + random(10);
    else
      hyper += 15; 
  } 		

  damage_bonus = dam1 + dam2 + dam3 + dam4; 

  if(damage_bonus > 0)
  {
    base += damage_bonus + hyper;
  }
  if(ATT && ATT->webbed())
  {
    base += random(USER->QL/2);
  }
  dmg = base / 2;
  if(USER->QL > 19 || USER->QRN == "toy")
    TOM HIR+"Symb bonus is "+base+"!\n"+
        "Hyper bonus is "+hyper+"!\n"+
        "Dmg bonus is "+dmg+NORM+"!\n");
  return base;	
}

query_message_hit(int tmp) 
{
  string *mess;
  tmp = 0;
  tmp += dmg;
  if(USER->QRN == "toy")
    TOM HIG+"Tmp this round equals "+tmp+NORM+"!\n");
  mess = ({" with a frenzy of attacks", HIR+"D E S T R O Y E D"+NORM });
  if(tmp < 37) { mess = ({"'s body into bloody ribbons", RED+"Mutilated"+NORM }); }
  if(tmp < 34) { mess = ({" with an onslaught of blows", HIW+"Destroyed"+NORM }); }
  if(tmp < 29) { mess = ({" into small fragments", HIW+"Massacred"+NORM }); }
  if(tmp < 25) { mess = ({" into the ground with bone shattering force", RED+"Slammed"+NORM }); }
  if(tmp < 20) { mess = ({" with a bone crushing sound", HIW+"Smashed"+NORM }); }
  if(tmp < 16) { mess = ({" very hard", HIW+"Hit"+NORM }); }
  if(tmp < 12) { mess = ({" hard", HIW+"Hit"+NORM }); }
  if(tmp <  9) { mess = ({"", HIW+"Hit"+NORM }); }
  if(tmp <  5) { mess = ({"", HIW+"Grazed"+NORM }); }
  if(tmp <  2) { mess = ({" in the stomach", HIW+"Tickled"+NORM }); }
  return mess;
}
