#include "/players/pestilence/define.h"
#define IPTP   present("destroyer_ob", TP)

object lcp,player;
string name;
int dmg, amt, time;

/*
set_name(str) { name = str;}
*/

set_time(num){
  time = 150;
 call_out("quit_lich", time); }
 
liched(){ return 1; }

do_shadow(ob) {
  lcp = ob;
shadow(ob,1);
}
look(str)
{
  object gob;
  gob = present("destroyer_ob", lcp);
  if (lcp->query_level() < 21)
  {
    gob->do_light(2); 
    lcp->look(str);
    gob->do_light(-2);
  }
  else
  {
    lcp->look(str);
  }
  return 1;
}

move_player(str)
{
  object gob;
  if (!str) return;
  gob = present("destroyer_ob", lcp);
  if (!gob) lcp->move_player(str);
  if (lcp->query_level() > 19)
  {
    lcp->move_player(str);
  }
  else
  {
    gob->do_light(2);

   if(gob->query_shadows()) 
    {
      lcp->move_player(str);
    }
    else
    {
      lcp->move_player(str);
    }
    gob->do_light(-2);
  }
}

/*
id(str) {return str == "Predator" || str == name || str == "predator_obj"; } 
*/

/*
query_name(){
  if(lcp->query_ghost())
    return "some mist";
  return "Predator";
 }
*/

check_shadows()
{
  object gob;
  gob = present("destroyer_ob", lcp);
  if (!gob) return 0;
  return gob->query_shadows();
}


short()
{
  int clvl,cste,cint,mylvl,myste,myint;
  if (check_shadows())
  {
    if(TP){
      clvl = TP->query_total_level(); mylvl=lcp->query_total_level();
      cste = TP->query_attrib("ste"); myste=lcp->query_attrib("ste");
      cint = TP->query_attrib("int"); myint=lcp->query_attrib("int");
    if (TP && TP->query_level() > 21)
       lcp->short()+" (camouflaged)";
    else 
    if (clvl > mylvl && random(myste+myint)*3/2 < random(cste+cint)) 
       return lcp->short()+" (camouflaged)";
    else
      return;
    }
  /* must be visiable to more powerful players! -Bp */
  }
  return lcp->short();
}


long()
{
  if (!TP ||
      (TP && !IPTP && check_shadows())) shadows_spotted();
  lcp->long();
}


shadows_spotted()
{
  object gob;
  tell_object(lcp,"You are no longer hidden.\n");
  if (TP) tell_object(TP, "You spot "+lcp->query_name()+" camouflaged.\n");
 gob = present("destroyer_ob", lcp);
  if (gob)
  {
    gob->set_shadows(0);
    gob->save_me();
  }
  return 1;
}

void room_tell(string rmsg)
{
  object *allroom;
  int i;
  allroom = all_inventory(environment(lcp));
  for (i=0; i < sizeof(allroom); i++)
  {
    if (allroom[i] != lcp) tell_object(allroom[i], rmsg);
  }
}

void show_move(int num, object lcp, object room)
{
  string pmsg, rmsg, me;
  me = lcp->query_name()+" ";

  switch(num)
  {
    case 0:
      pmsg = "You flinch.";
      rmsg = me+"flinches.";
      break;

    case 1..4:
      pmsg = "You sidestep to the right.";
      rmsg = me+"sidesteps to the right.";
      break;

    case 5..8:
      pmsg = "You dive to the ground deflecting some damage!";
      rmsg = me+"dives to the ground deflection some damage!";
      break;

    case 9..12:
      pmsg = "You deflect the blow with a kick.";
      rmsg = me+"deflects the blow with a kick.";
      break;

    case 13:
      pmsg = "You flinch.";
      rmsg = me+"flinches.";
      break;

    case 14..22: return;

  }

  tell_object(lcp, YEL+pmsg+NORM+"\n");
  room_tell(rmsg+"\n");
}

/*
long(){ 
  if(TP->query_level() < 21 && !present("destroyer_ob", TP)){
    write(short()+".\n");
    write("You become very intimidated and lower your weapon.\n");
    TP->stop_wielding();
    return 1;
    }
  write(short()+".\n");
  if(lcp->query_hp() < (lcp->query_mhp()/10)) {
    write("Predator is in very bad shape.\n"); return; }
  if(lcp->query_hp() < (lcp->query_mhp()/5)) {
    write("Predator is in bad shape.\n"); return; }
  if(lcp->query_hp() < (lcp->query_mhp()/2)) {
    write("Predator is somewhat hurt.\n"); return; }
  if(lcp->query_hp() < (lcp->query_mhp() - 20)){
    write("Predator is slightly hurt.\n"); return;}
    write("Predator is in good shape.\n");
    return 1;
  }
*/
/*
hit_player(arg){
 dmg = arg;
amt = (dmg);
 lcp->hit_player(amt);
 return amt;
}
*/
/* DAMAGE REDUCTION CODE */
hit_player(dam1, type1, dam2, type2)
{
   return do_damage(({dam1,dam2}),({type1,type2}));
}
do_damage(int *damage, string *method)
{
  object gob;
  string type, cat, subcat;
  int i, dam, total, modenum;

  gob = present("destroyer_ob", lcp);
  if (!gob) destruct(this_object());

  /***********************************/
  /*  Handle Beck's Defense Types    */
  /***********************************/
  if (!damage) return 0;
  for(i=0; i < sizeof(damage); i++)
  {
    /* Get damage type information. */
    subcat = 0;
    if (!damage[i]) continue;
    dam = damage[i];
    if (!method) type = "physical";
    else if (!method[i]) type = "physical";
    else
    {
      type = method[i];
      if (type != "physical" && type != "magical")
      {
        if (sscanf(type, "%s|%s", cat, subcat) !=2)
        {
          type = "physical";
        }
        else if (cat != "other") type = "physical";
        else                     type = "other";
      }
    }

    dam = calcDamage(dam, type, subcat, gob);

    total += dam;
  }

  if (total <= 0) total = 0;

  return total;
}


/* DAMAGE REDUCTION GUIDE
   defnum:    the % resistance to the damage
   basered:   the ac against the damage, random(basered) is deducted
   MAX_REDUX: the max damage points that can be deducted
              this may rise for certain damage types
*/
int calcDamage(int dam, string type, string subcat, object gob)
{ 
  int alev, modenum, defnum, basered, tmp_dam, 
      MAX_REDUX, mode2Max, mode1Max, mode0Max, maxDef, maxBase;
  string myname;
  status dodge, leaderBonus;
  object attacker;

  myname = capitalize((string)lcp->query_name());
  alev = (int)gob->query_combat();
  defnum   = 0;
  basered  = 0;
  MAX_REDUX = 15;    /* MAX HP REDUCTION */

  dodge = 0; /* never dodge */

/* DAMAGE TYPE MODIFIERS */
  if (type == "magical")
  {
    /* complete vulnerability to magical attacks */
       defnum -= 15;
    basered = 0;
    tell_room(environment(lcp), HIM+myname+
      " crumbles under a magical attack!"+NORM+"\n");
  }
  if (type == "physical")
  {
    /* slightly enhanced defense vs. physical attacks */
    defnum  +=  0 + random(5);
    basered +=  2;
    maxDef  +=  4;
  }
  if (type == "other")
  {
    subcat = lower_case(subcat);
    if (subcat == "good"  || subcat == "evil")
    {
      /* enhanced vulnerability to these types */
      defnum -= 15;
      maxDef -= 15;
      basered = 0;
      if (subcat == "good") subcat = "holy";
      else                  subcat = "unholy";
      tell_room(environment(lcp), YEL+
        "The "+subcat+" attack rips through "+myname+"'s flesh!"+NORM+"\n");
    }
    if(subcat == "ice"    || subcat == "electric" ||
         subcat == "mental" || subcat == "poison")
    {
      /* enhanced defense vs. these types */
      defnum += 7;
      maxDef += 7;
      basered += 3;
      tell_room(environment(lcp), HIY+myname+
        "'s body shakes under the "+subcat+" attack!"+NORM+"\n");
      MAX_REDUX += 7;
    }
    if (subcat == "water")
    {
      /* extreme vulnerability versus water damage */
      defnum -= 25;
      maxDef -= 25;
      basered = 0;
      tell_room(environment(lcp), HIC+myname+
        "'s flesh repells the water!"+NORM+"\n");
    }
    if (subcat == "laser")
    {
      /* extreme defense versus futuristic damage */
      defnum   = 90;
      maxDef   = 90;
      basered += 15;
      tell_room(environment(lcp), HIB+myname+
        " is devastated from the laser!"+NORM+"\n");
      MAX_REDUX += 20;
    }
  }

  if (defnum < 0)   defnum = 0;
  if (maxDef < 0)   maxDef = 0;
  if (defnum > 100) defnum = 100;
  if (maxDef > 100) maxDef = 100;
  if (basered < 0)  basered = 0;


  maxBase = basered;
  basered = random(basered)+1;  /* ac range of 1 to basered */

attacker = this_player();
  if(attacker)
  if(attacker->is_player()) defnum = 7*defnum / 12;
  tmp_dam = ((100-defnum)*dam)/100;
  tmp_dam -= basered;
  if (tmp_dam < 0) tmp_dam = 0;
  if (dam - tmp_dam > MAX_REDUX) tmp_dam = dam - MAX_REDUX;
   modenum = dam-tmp_dam;

  /* Make sure we don't interfere with objects or spells that damage ourself. */
  if (this_player() && this_player() == lcp)
  {
    dodge   = 0;
    defnum  = 0;
    maxDef  = 0;
    basered = 0;
    tmp_dam = dam;
  }

/* DO DAMAGE */
  if (!dodge)
  {
    if (myname == "Pestilence" || myname == "Pestyjr")
    {
      tell_object(lcp,
HIG+"DAMAGE ["+modenum+"]"+NORM+"\n");
    }
    lcp->hit_player(tmp_dam);
  }
  if (defnum > 0 && defnum <= 15)
    show_move(random(5), lcp, environment(this_object()));
  if (defnum > 15 && defnum <= 40) 
    show_move((random(10)+4), lcp, environment(this_object()));
  if (defnum > 40 && defnum < 100)
    show_move(random(18)+4, lcp, environment(this_object()));
  if (defnum == 100)
    show_move(22, lcp, environment(this_object()));

  return tmp_dam;
}

quit_lich() {
/*
 write(BOLD+BLK+"Your Lich grows weak and you turn back into your original form.\n"+NORM); 
*/
 write(BOLD+HIY+"You are no longer in Predator mode.\n\n"+NORM);
say(BOLD+BLK+"Enhanced Predator lets "+TPN+" return back into "+TP->query_possessive()+" original form.\n"+NORM);
 destruct(TO);
 return 1;
}
