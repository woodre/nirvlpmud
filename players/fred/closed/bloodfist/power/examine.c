#include "/players/fred/closed/bloodfist/defs.h"

void get_weight(object it, object User)
{
  int weight;
  weight = (int)it->query_weight();
  if(weight > 5)      TOU "   Weight:\tvery heavy\n");
  else if(weight > 3) TOU "   Weight:\theavy\n");
  else if(weight > 2) TOU "   Weight:\tmoderate\n");
  else if(weight > 1) TOU "   Weight:\tlight\n");
  else if(weight > 0) TOU "   Weight:\tvery light\n");
  else if(weight < 1) TOU "   Weight:\tweightless\n");
}

/*
room:  room properties
wep:   short, weight, class, value, 1/2 handed, storable
armor: short, weight, ac, value, type, storable
npc:   short, lvl, hp, wc, ac, xp val
misc:  short, weight, value, storable
*/

status main(string str, object PO, object User)
{
  object it;
  int wc,ac,hp,wt,al,cost;
  if(User->query_ghost()) return 0;
  if(!PO->level_check(3)) return 0;
  if(!str)
  {
    TOU"What do you want to examine?\n");
    return 1;
  }
  if(str == "room" || str == "environment" || str == "area")
  {
    string *area;
    area =({ });
    it = environment(User);
    TOU "You look around and examine the "+str+" closely...\n\n");
    command("look", User);
    if(it->query_property("no_follow"))
      area += ({ HIG+"No follow"+NORM, });
    else
      area += ({ "Follow", });
    if(it->query_property("no_teleport") || it->realm("NT"))
      area += ({ HIC+"No teleport"+NORM, });
    else
      area += ({ "Teleport", });
    if(it->query_property("no_magic") || it->realm("NM"))
      area += ({ MAG+"No magic"+NORM, });
    else
      area += ({ "Magic", });
    if(it->query_property("no_fight")
      || (int)environment(User)->query_no_fight())
      area += ({ HIY+"No fight"+NORM, });
    else
      area += ({ "Fight", });
    if(it->query_property("spar_area"))
      area += ({ HIW+"Spar area"+NORM, });
    else
      area += ({ "Non spar area", });
    if(it->query_property("fight_area") || User->check_fight_area())
      area += ({ RED+"PK area"+NORM, });
    else
      area += ({ "Non PK area", });
    TOU "\n   ");
    for(cost = 0; cost < 6; cost++)
    {
      TOU colour_pad(area[cost],20));
      if(cost == 2)
        TOU "\n   ");
    }
    TOU"\n");
    TRU Name+" looks around the "+str+" closely.\n", ({ User }));
    return 1;
  }
  if(!(it = present(str, User)) && !(it = present(str, environment(User))))
  {
    TOU"What do you want to examine?\n");
    return 1;
  }
  cost = 28 - (WIS / 25 + FAI / 25);
  if(User->query_sp() < cost)
  {
    TOU "You are too weak to do this now.\n");
    return 1;
  }
  if((string)environment(User)->realm() == "NM")
  {
    TOU"Your energy is being drained here.\n");
    return 1;
  }
  TOU "You examine "+it->short()+"...\n");
  TRU Name+" examines "+it->query_name()+" closely.\n", ({ User }));
  if((wc = (int)it->weapon_class()))
  {
    if(wc > 20)      TOU "   Damage:\tvery powerful\n");
    else if(wc > 18) TOU "   Damage:\tpowerful\n");
    else if(wc > 16) TOU "   Damage:\tmoderate\n");
    else if(wc > 12) TOU "   Damage:\tokay\n");
    else if(wc < 13) TOU "   Damage:\tlow\n");
    get_weight(it, User);
    TOU "   Value:\t"+it->query_value()+"\n");
    if(it->two_handed())
      TOU "   Two handed:\tyes\n");
    else
      TOU "   Two handed:\tno\n");
    if(it->query_save_flag()) /* non-storable */
      TOU "   Storable:\tno\n");
    else
      TOU "   Storable:\tyes\n");
    TOU"\n");
  }
  else if((ac = (int)it->armor_class()))
  {
    if(ac >= 5)      TOU "   Defense:\texcellent\n");
    else if(ac == 4) TOU "   Defense:\tgreat\n");
    else if(ac == 3) TOU "   Defense:\tvery good\n");
    else if(ac == 2) TOU "   Defense:\tmoderate\n");
    else if(ac <= 1) TOU "   Defense:\tlight\n");
    get_weight(it, User);
    TOU "   Value:\t"+it->query_value()+"\n");
    TOU "   Type:\t"+it->query_type()+"\n");
    if(it->query_save_flag()) /* non-storable */
      TOU "   Storable:\tno\n");
    else
      TOU "   Storable:\tyes\n");
    TOU"\n");
  }
  else if(living(it))
  {
    ac = (int)it->query_ac();
    wc = (int)it->query_wc();
    hp = (int)it->query_hp();
    al = (int)it->query_alignment();

    TOU "   Level:\t"+it->query_level()+"\n");
    if(hp >= 6000)      TOU "   Health:\tinsane\n");
    else if(hp >= 3500) TOU "   Health:\tvery strong\n");
    else if(hp >= 2200) TOU "   Health:\tstrong\n");
    else if(hp >= 1500) TOU "   Health:\tvery tough\n");
    else if(hp >= 800)  TOU "   Health:\ttough\n");
    else if(hp >= 400)  TOU "   Health:\tmoderate\n");
    else if(hp >= 200)  TOU "   Health:\tlight\n");
    else if(hp >= 0)    TOU "   Health:\tlow\n");
    else                TOU "   Health:\t-----\n");
    if(wc > 80)         TOU "   Damage:\tinsane\n");
    else if(wc > 65)    TOU "   Damage:\tvery powerful\n");
    else if(wc > 50)    TOU "   Damage:\tpowerful\n");
    else if(wc > 40)    TOU "   Damage:\tstrong\n");
    else if(wc > 30)    TOU "   Damage:\taverage\n");
    else if(wc > 20)    TOU "   Damage:\tmoderate\n");
    else if(wc > 10)    TOU "   Damage:\tlight\n");
    else if(wc >= 0)    TOU "   Damage:\tlow\n");
    else                TOU "   Damage:\t-----\n");
    if(ac > 34)         TOU "   Defense:\tinsane\n");
    else if(ac > 28)    TOU "   Defense:\tvery strong\n");
    else if(ac > 23)    TOU "   Defense:\tstrong\n");
    else if(ac > 18)    TOU "   Defense:\ttough\n");
    else if(ac > 14)    TOU "   Defense:\tmoderate\n");
    else if(ac > 8)     TOU "   Defense:\tlight\n");
    else if(ac >= 0)    TOU "   Defense:\tlow\n");
    else                TOU "   Defense:\t-----\n");
    if(al > 1000)       TOU "   Align:\textremely good\n");
    else if(al > 600)   TOU "   Align:\tvery good\n");
    else if(al > 200)   TOU "   Align:\tgood\n");
    else if(al > 0)     TOU "   Align:\tslightly good\n");
    else if(al == 0)    TOU "   Align:\tneutral\n");
    else if(al > -200)  TOU "   Align:\tslightly evil\n");
    else if(al > -600)  TOU "   Align:\tevil\n");
    else if(al > -1000) TOU "   Align:\tvery evil\n");
    else if(al < -1001) TOU "   Align:\textremely evil\n");
    else                TOU "   Align:\t-----\n");
    TOU "   Exp Value:\t"+it->calculate_evaluated_worth(User)+"\n");
    TOU"\n");
  }
  else {
    get_weight(it, User);
    TOU "   Value:\t"+it->query_value()+"\n");
    if(it->query_save_flag()) /* non-storable */
      TOU "   Storable:\tno\n");
    else
      TOU "   Storable:\tyes\n");
    TOU"\n");
  }
  User->add_sp(-cost);
  return 1;
}

