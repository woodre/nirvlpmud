/* Seniors or Zeus can use this                  */
/* also gave permission for Vertebraker or 2 testchars to use */
/* If you need to add_xp, set percent to 0 first */

#include "/players/zeus/closed/all.h"
inherit "obj/treasure";

id(str){ return str == "tool" || str == "ctool"; }

reset (arg){
  if(!arg){

  set_long("Usage:\n"+
    "   cval   <addgxp/rmgxp/percent/regular>  <who> <amount>\n"+
    "   cskill <add / rm / title>              <who> <what>\n"+
    "   cstat <who>\n"+
    "   cwho\n");
  }
}

void init(){
  ::init();

  if(environment() && 
(string)environment()->query_real_name() != "zeus" &&
(string)environment()->query_real_name() != "zeustest" &&
(string)environment()->query_real_name() != "ztest" &&
(string)environment()->query_real_name() != "vertebraker" &&
    environment()->query_level() < 100)
    destruct(this_object());

  add_action("circle_val", "cval");
  add_action("circle_skills", "cskill");
  add_action("cwho", "cwho");
  add_action("cstat", "cstat");
}

drop(){  return 1;  }
can_put_and_get(){  return 1;  }

no_find(str, x){
  if(x == 1)
    write("There is no player "+str+".\n");
  else if(x == 2)
    write("That player has no gob.\n");
  return 1;
}

cstat(str){
  object x, c, nme;
  int i,f,s,t;
  if(!str) return 0;
  x = find_player(str);
  if(!x) return 0;
  c = present("circle_object", x);
  if(!c) return 0;
  nme = (object)x->query_attack();
  i = (int)x->query_intoxination()*100 / ((int)x->query_level()+3);
  f = (int)x->query_stuffed()*100 / ((int)x->query_level()*8);
  s = (int)x->query_soaked()*100 / ((int)x->query_level()*8);
  t = (int)x->query_infuse()*100 / (((int)x->query_level()*9)/2);
  write("\n"+x->short()+"\n\n");
  if(x->query_extra_level())
    write(pad("Lvl:  "+x->query_level()+"+"+x->query_extra_level(), 17));
  else
    write(pad("Lvl:  "+x->query_level(), 17));
  write(pad("Exp:   "+(int)x->query_exp(), 18)+
    pad("AC:  "+x->query_ac(), 10)+
    "WC:  "+x->query_wc()+"\n"+
    pad("Hp:   "+(int)x->query_hp()+"/"+(int)x->query_mhp(), 17)+
    pad("Sp:    "+(int)x->query_spell_point()+"/"+(int)x->query_msp(), 18)+
    "I: "+i+" F: "+f+" S: "+s+" T: "+t+"\n"+
    pad("Gxp:  "+(int)c->query_guild_exp(), 17)+
    pad("End:   "+(int)c->query_endurance()+"/"+
    (int)c->query_max_endurance(), 18)+
    "XP%:  "+(int)c->query_percent(1)+"\n"+
    pad("Qps:  "+(int)x->query_quest_point(),17)+
    pad("Money: "+(int)x->query_money(), 18)+
    "Idle: ");
  if(query_idle(x) <= 60)
    write(query_idle(x)+"s\n");
  else if(query_idle(x) > 60)
    write(query_idle(x) / 60+"m "+query_idle(x) % 60+"s\n");
  write("\nSkills: ");
  c->tell_skills(1);
  if(nme)
  {
    write(nme->QN+":  HP "+nme->query_hp()+"/"+nme->query_mhp()+"  L: "+
      nme->query_level()+"  WC: "+nme->query_wc()+"  AC: "+
      nme->query_ac()+"  A: "+nme->query_alignment()+"\n");
  }
  if(environment(x))
    write("Room: "+environment(x)->short()+"\n");
  write("\n");
    return 1;
}

circle_val(str){
  string who, type;
  int amount;
  object gob, found;
  if(!str) return 0;
  if(!sscanf(str, "%s %s %d", type, who, amount) == 3) return 0;
  if(!find_player(who))
  {
    no_find(who, 1);
    return 1;
  }
  else
    found = find_player(who);
  gob = present("circle_object", found);
  if(!gob)
  {
    no_find(who, 2);
    return 1;
  }
  if(type == "rmgxp")
    gob->rm_guild_exp(amount);
  else if(type == "addgxp")
    gob->add_guild_exp(amount);
  else if(type == "percent")
    gob->set_perc(amount);
  else if(type == "regular")
    found->add_exp(amount);
  gob->save_circle(1);
  write_file("/players/zeus/circle/log/TOOL", ctime(time())+
    "   "+capitalize((string)TP->QRN)+" - "+type+" "+who+" "+amount+".\n");
  write("Okay.\n");
  return 1;
}

circle_skills(str){
  string who, type, what;
  object gob, found;
  if(!str) return 0;
  if(!sscanf(str, "%s %s %s", type, who, what) == 3) return 0;
  if(!what) return 0;
  if(!find_player(who))
  {
    no_find(who, 1);
    return 1;
  }
  else
    found = find_player(who);
  gob = present("circle_object", found);
  if(!gob)
  {
    no_find(who, 2);
    return 1;
  }
  if(type == "add")
    gob->set_skills(what);
  else if(type == "rm")
    gob->remove_skills(what);
  else if(type == "title")
    gob->set_special_title(what);
  gob->save_circle(1);
  write_file("/players/zeus/circle/log/TOOL", ctime(time())+
    "   "+capitalize((string)TP->QRN)+" - "+type+" "+who+" "+what+".\n");
  write("Okay.\n");
  return 1;
}

cwho(){
  object* ppl, circle;
  int i, s;
  ppl = users();
  s = sizeof(ppl);
  write(BOLD+BLK+"\n     the Circle of Shadows >--------\n"+NORM);
  for(i = 0; i < s; i++)
  {
    circle = present("circle_object", ppl[i]);
    if(circle)
    {
      if(ppl[i]->query_idle() < 60)
        write(ppl[i]->query_idle()+"s - ");
      else
        write((ppl[i]->query_idle() / 60)+"m - ");
      write(pad(capitalize((string)ppl[i]->query_real_name()), 12));
      write(pad(circle->query_guild_exp(), 9));
      if(environment(ppl[i]))
        write(file_name(environment(ppl[i]))+"   ");
      if(ppl[i]->query_attack())
      {
        write(ppl[i]->query_attack()->query_name()+" "+
          ppl[i]->query_attack()->query_hp()+"/"+
          ppl[i]->query_attack()->query_mhp()+"\n");
      }
      else
        write("\n");
    }
  }
  return 1;
}
      
