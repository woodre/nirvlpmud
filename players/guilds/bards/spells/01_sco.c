#include "/players/guilds/bards/def.h"
#include "/players/guilds/bards/lib/ansi_pad.h"

#define DIV HIM+"|"+NORM+BOLD

string short_age(object p) {
  int a;
  string str;
  str="";
  a=(int)p->query_age();
  str+= (a/43200)+"d ";
  a = a - (a / 43200) * 43200;
  str+= (a/1800)+"h ";
  a = a - (a / 1800) * 1800;
  str+=(a/30)+"m ";
  a = a - (a / 30) * 30;
  str+=(a*2)+"s";
  return str;
}

string mini_guilds(object p) {
  string str;
  object ng;
  if(ng=present("base_obj",p))
    str=""+ng->query_newguild();
  if(ng=present("base_obj 2",p))
    str+="/"+ng->query_newguild();
  if(ng=present("base_obj 3",p))
    str+="/"+ng->query_newguild();
  return (str?str:"none");
}

string weapon_rating(object p) {
  switch((int)p->query_wc()) {
    default: return "unarmed";
    case 4..9: return "lightly armed";
    case 10..15: return "moderately armed";
    case 16..19: return "well armed";
    case 20..30: return "heavily armed";
  }
}

string armor_rating(object p) {
  switch((int)p->query_ac()) {
    case 0: return "unarmored";
    case 1..4: return "lightly armored";
    case 5..8: return "moderately armored";
    case 9..12: return "well armored";
    default: return "heavily armored";
  }
}

string encumberance_rating(object p) {
  int cap;
  int lw;
  int enc;
  p->recalc_carry();
  cap=(int)p->query_level()+6+(int)p->query_attrib("str")/5;
  lw=(int)p->query_local_weight();
  if(cap==0) return "<error>";
  enc=lw*100/cap;
  switch(enc) {
    case 0: return "unencumbered";
    case 1..25: return "barely noticable";
    case 26..50: return "lightly burdened";
    case 51..75: return "moderately burdened";
    case 76..100: return "heavily burdened";
    default: return "overburdened";
  }
}


main() {
  string str;
  object gob;
  object player;
  int l;
  player=this_player();
  gob=present("bard_obj",player);
  if(!gob) return 0;
  l=player->query_level();

  write("\n");
  write(HIM+"/---------------------------------------------------------------------------\\\n");
  write(DIV+NORM+" "+ansi_pad(((str=TP->query_pretitle())?str+" ":"")+tp+" "+TP->query_title(),74)+DIV+"\n");
  write(HIM+"+-------------------------+--------------------+--------------+-------------+\n");
  write(DIV+" Guild Level:  "+NORM+pad(""+gob->query_bard_level(),-9)+" "
       +DIV+" Charisma:      "+NORM+pad(""+player->query_attrib("cha"),-3)+" "
       +DIV+" Intox:   "+NORM+pad(""+player->query_intoxination()*100/(l+3),-3)
       +" "+DIV+" Wimpy:  "+NORM+pad(""+player->query_wimpy()+"%",-3)+" "
       +DIV+"\n");
  write(DIV+" Game Level:   "+NORM+pad(""+l,-9)+" "
       +DIV+" Dexterity:     "+NORM+pad(""+player->query_attrib("dex"),-3)+" "
       +DIV+" Stuffed: "+NORM+pad(""+player->query_stuffed()*100/(l*8),-3)
       +" "+DIV+" Crime:  "+NORM+pad(""+(player->query_crime()?"yes":"no"),-3)+" "
       +DIV+"\n");
  write(DIV+" Extra Level:  "+NORM+pad(""+player->query_extra_level(),-9)+" "
       +DIV+" Intelligence:  "+NORM+pad(""+player->query_attrib("int"),-3)+" "
       +DIV+" Soaked:  "+NORM+pad(""+player->query_soaked()*100/(l*8),-3)
       +" "+DIV+" Hunted: "+NORM+pad(""+(player->query_hunter()?"yes":"no"),-3)+" "
       +DIV+"\n");
  write(DIV+" Hit Points:   "+NORM+pad(""+player->query_hp()+"/"+player->query_mhp(),-9)+" "
       +DIV+" Luck:          "+NORM+pad(""+player->query_attrib("luc"),-3)+" "
       +HIM+"+--------------+-------------+\n");
  write(DIV+" Mana:         "+NORM+pad(""+player->query_sp()+"/"+player->query_msp(),-9)+" "
       +DIV+" Magic:         "+NORM+pad(""+player->query_attrib("mag"),-3)+" "
       +DIV+" Weapon: "+NORM+pad(weapon_rating(player),19)
       +DIV+"\n");
  write(DIV+" Experience:"+NORM+pad(""+player->query_exp(),-12)+" "
       +DIV+" Piety:         "+NORM+pad(""+player->query_attrib("pie"),-3)+" "
       +DIV+" Armor:  "+NORM+pad(armor_rating(player),19)
       +DIV+"\n");
  write(DIV+" Golden Coins: "+NORM+pad(""+player->query_money(),-9)+" "
       +DIV+" Stamina:       "+NORM+pad(""+player->query_attrib("sta"),-3)+" "
       +DIV+" Load:   "+NORM+pad(encumberance_rating(player),19)
       +DIV+"\n");
  write(DIV+" Quest Points: "+NORM+pad(""+player->query_quest_point(),-9)+" "
       +DIV+" Stealth:       "+NORM+pad(""+player->query_attrib("ste"),-3)+" "
       +HIM+"+----------------------------+\n");
  write(DIV+" Gender:       "+NORM+pad(""+player->query_gender(),-9)+" "
       +DIV+" Strength:      "+NORM+pad(""+player->query_attrib("str"),-3)+" "
       +DIV+" Mini Guild Membership:     "
       +DIV+"\n");
  write(DIV+" Age: "+NORM+pad(short_age(player),-18)+" "
       +DIV+" Will Power:    "+NORM+pad(""+player->query_attrib("wil"),-3)+" "
       +DIV+NORM+" "+pad(mini_guilds(player),27)
       +DIV+"\n");
  write(HIM+"\\-------------------------+--------------------+----------------------------/\n"+NORM);
  return 1;
}

