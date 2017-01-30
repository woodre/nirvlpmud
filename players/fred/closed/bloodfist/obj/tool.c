#include "/players/fred/closed/bloodfist/defs.h"

id(str){ return str == "bfo"; }
short(){ if(this_player()->query_level() > 20) return "bfo"; }
long()
{
  write("bfs - stat <who>\n"+
    "bfw - who\n"+
    "bfa - attrib who what amt\n"+
    "bfu - update obj\n");
}

void init(){
  if(this_player() && (string)this_player()->query_real_name() != "fred" &&
    (string)this_player()->query_real_name() != "forbin" &&
    (int)this_player()->query_level() < 100)
    destruct(this_object());
  add_action("bfattrib", "bfa");
  add_action("bfstat", "bfs");
  add_action("bfwho", "bfw");
  add_action("bfupdate", "bfu");
}

status bfupdate(){
  write("Updating...\n");
  move_object(clone_object(DIR+"obj/tool.c"), this_player());
  destruct(this_object());
  return 1;
}

/* AGL MIT ACC VIG WIS FAI */
status bfattrib(string str)
{
  string *types, who, what;
  object gob, y;
  int z, amt;
  types =({ "agl", "mit", "acc", "vig", "wis", "fai", });
  sscanf(str, "%s %s %d", who, what, amt);
  if(!(y = find_player(who)))
    return (notify_fail(capitalize(who)+" is not logged on.\n"), 0);
  if(!(gob = present("bloodfist_gob", y)))
    return (notify_fail(capitalize(who)+" is not a Bloodfist.\n"), 0);
  write("You give "+capitalize(who)+" "+amt+" "+types[z]+".\n");
  tell_object(y, "You have received "+amt+" "+types[z]+".\n");
  if((z = index(types, what)) >= 0)
  {
    if(amt > 0)
      gob->add_free_attrib(amt);
    gob->add_attrib(z, amt);
    if(amt < 0)
      gob->add_free_attrib(amt);
  }
  else
    return (notify_fail("That is not a valid type.\n"), 0);
  return 1;
}

status bfstat(string who)
{
  object gob, y, z;
  string line;
  mixed i,f,s,t,e;
  if(!who) return (notify_fail("You must specify a player.\n"), 0);
  if(!(y = find_player(who)))
    return (notify_fail(capitalize(who)+" is not logged on.\n"), 0);
  if(!(gob = present("bloodfist_gob", y)))
    return (notify_fail(capitalize(who)+" is not a Bloodfist.\n"), 0);

  i = HIC+(int)y->query_intoxination()*100 / ((int)y->query_level()+3)+NORM;
  f = HIC+(int)y->query_stuffed()*100 / ((int)y->query_level()*8)+NORM;
  s = HIC+(int)y->query_soaked()*100 / ((int)y->query_level()*8)+NORM;
  t = (int)y->query_infuse()*100 / (((int)y->query_level()*9)/2);

  if(gob->is_testchar())
    tell_object(this_player(), BOLD+BLK+"TestChar "+NORM);
  tell_object(this_player(), capitalize((string)y->query_real_name())+
    " is at "+environment(y)->short()+"\n");
  tell_object(this_player(), " Glvl: "+gob->query_glevel()+       /* line 1 */
    "  Gxp: "+pad((string)gob->query_gexp(),9)+
    "AGL MIT ACC VIG WIS FAI FRE | STR STA MAG STE LUC\n");
  tell_object(this_player(),
    " Alvl: "+pad((string)gob->query_attrib_lvl(), 3)+           /* line 2 */
    "Axp: "+pad((string)gob->query_attrib_exp(), 9)+
    pad((string)gob->query_attrib(0),4)+pad((string)gob->query_attrib(1),4)+
    pad((string)gob->query_attrib(2),4)+pad((string)gob->query_attrib(3),4)+
    pad((string)gob->query_attrib(4),4)+pad((string)gob->query_attrib(5),4)+
    pad((string)gob->query_free_attribs(), 4)+
    "| "+pad((string)y->query_attrib("str"),4)+
    pad((string)y->query_attrib("sta"),4)+
    pad((string)y->query_attrib("mag"),4)+
    pad((string)y->query_attrib("ste"),4)+
    pad((string)y->query_attrib("luc"),4)+"\n");
  tell_object(this_player(),
    " Deth: "+pad((string)gob->query_total_deaths(),3)+           /* line 3 */
    "HnP: "+pad((string)gob->query_honor_potential(), 9)+
    pad((string)gob->query_attribb(0),4)+pad((string)gob->query_attribb(1),4)+
    pad((string)gob->query_attribb(2),4)+pad((string)gob->query_attribb(3),4)+
    pad((string)gob->query_attribb(4),4)+pad((string)gob->query_attribb(5),4)+
    "\n");
  tell_object(this_player(),
    " Hnor: "+pad((string)HONOR_DAEMON->query_honor(y->query_real_name()),7)+
    "Gold: "+pad((string)y->query_money(),6)+
    "\n");
  if((e = (int)gob->query_chosen_exp(0)))
    tell_object(this_player(), HIR+" Wep1: "+NORM+gob->query_chosen_lvl(0)+
    "  "+pad(e,8)+gob->query_chosen(0)+"\n");
  if((e = (int)gob->query_chosen_exp(1)))
    tell_object(this_player(), HIR+" Wep2: "+NORM+gob->query_chosen_lvl(1)+
    "  "+pad(e,8)+gob->query_chosen(1)+"\n");
  if((e = (int)gob->query_chosen_exp(2)))
    tell_object(this_player(), HIR+" Wep3: "+NORM+gob->query_chosen_lvl(2)+
    "  "+pad(e,8)+gob->query_chosen(2)+"\n");
  if((e = (int)gob->query_chosen_exp(3)))
    tell_object(this_player(), HIR+" Wep4: "+NORM+gob->query_chosen_lvl(3)+
    "  "+pad(e,8)+gob->query_chosen(3)+"\n");
  tell_object(this_player(),
    " En: "+HIG+colour_pad((string)gob->query_endurance()+NORM+   /* line 4 */
    "/"+gob->query_max_endurance(),9)+
    " Act: "+pad((string)gob->query_activity(),7)+
    "Chsn: "+gob->query_chosen_current()+"/"+gob->query_chosen_max()+"  "+
    "Stnc: "+gob->query_stance(2)+"  Gems: "+gob->query_stored_gems()+"s "+
    gob->query_free_gems()+"f\n");
  tell_object(this_player(),   /* line 5 */
    " HP: "+HIG+colour_pad((string)y->query_hp()+NORM+"/"+y->query_mhp(),10)+
    "Lvl: "+pad((string)y->query_level()+"+"+y->query_extra_level(),7)+
    "Exp: "+pad((string)y->query_exp(),11)+"Idle: "+query_idle(y)+"\n"+
    " SP: "+HIG+colour_pad((string)y->query_spell_point()+NORM+"/"+
    y->query_msp(),10)+
    "AC:  "+pad((string)y->query_ac(),7)+"WC: "+pad((string)y->query_wc(),4)+
    "I: "+colour_pad(i,5)+"F: "+colour_pad(f,5)+"S: "+
    colour_pad(s,5)+"T: "+t+"\n\n");
    if((z = (object)y->query_attack()))
      tell_object(this_player(),
      "Fighting: "+pad((string)z->short(),40)+" HP: "+z->query_hp()+"/"+
      z->query_mhp()+" Lvl: "+z->query_level()+"\n"+
      "          "+environment(z)->short()+"\n\n");
  return 1;
}

/*
Vertebraker  8  1000  Idle PK Location
  Fighting:  blah  hp/mhp  lvl  ac  wc
*/
status bfwho()
{
  object *all, gob, nmy;
  int a,b,c;
  all = users();
  a = sizeof(all);
  c = 1;
  write(BOLD+BLK+"Blood"+NORM+HIR+"Fist"+NORM+BOLD+BLK+" Players\n"+NORM+
    "   Name      Glvl Honor  Idle  PK Location\n");
  for(b = 0; b < a; b++) /* loop through players */
  {
    if((gob = present("bloodfist_gob", all[b]))) /* if in the guild */
    {
      tell_object(this_player(), c+". "+
        pad(capitalize((string)all[b]->query_real_name()),12)+
        gob->query_glevel()+"  "+
        pad((string)HONOR_DAEMON->query_honor(all[b]->query_real_name()),9)+
        pad(query_idle(all[b]),4)+all[b]->query_pl_k()+"  ");
      if(environment(all[b]))
        tell_object(this_player(), environment(all[b])->short()+"\n");
      else
        tell_object(this_player(), "\n");
      if((nmy = (object)all[b]->query_attack()))
        tell_object(this_player(),
        HIM+"  Nmy: "+NORM+pad((string)nmy->query_name(),12)+
        pad((string)nmy->query_hp()+"/"+nmy->query_mhp(),11)+"lvl "+
        nmy->query_level()+" ac "+nmy->query_ac()+" wc "+nmy->query_wc()+"\n");
      c++;
    }
  }
  return 1;
}

