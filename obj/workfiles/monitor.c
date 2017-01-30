#include <ansi.h>

string monitor_string;

string
replace_ansi(string word)
{
    string z;

    switch(word)
    {
      case "H":  z = BOLD; break;
      case "K":  z = BLK; break;
      case "R":  z = RED; break;
      case "G":  z = GRN; break;
      case "Y":  z = YEL; break;
      case "B":  z = BLU; break;
      case "M":  z = MAG; break;
      case "C":  z = CYN; break;
      case "W":  z = WHT; break;
      case "N":  z = NORM; break;
      case "HK": z = HIK; break;
      case "HR": z = HIR; break;
      case "HG": z = HIG; break;
      case "HY": z = HIY; break;
      case "HB": z = HIB; break;
      case "HM": z = HIM; break;
      case "HC": z = HIC; break;
      case "HW": z = HIW; break;
    }
    
    if(!z) return word;
    return z;
}

void tell_peeps (object where, string what)
{
  int i;
  object *obs;

  i = sizeof(obs = all_inventory(where));

  while(i--)
    tell_object(obs[i], what+NORM+"\n");
}


string
replace_read(string reading)
{
    int amhp, l, inf, n;
    string z;
    object a;
    object gob;

    l = (int)this_object()->query_level();
    a = (object)this_object()->query_attack();

    inf = ((int)this_object()->query_max_infuse());

    switch(reading)
    {
      case "hps": 
        z = "" + (int)this_object()->query_hp() + ""; 
        break;
      case "sps": 
        z = "" + (int)this_object()->query_spell_point() + ""; 
        break;
      case "msp": 
        z = "" + (int)this_object()->query_msp() + "";
        break;
      case "mhp": 
        z = "" + (int)this_object()->query_mhp() + ""; 
        break;
      case "sd":
        if(gob = present("dervish_tattoo", this_object()))
        {
         z = ""+((int)gob->query_spell_delay());
         break;
        }
        else
         z = "sd";
         break;
      case "rc":
        if(gob = present("rogue_seal", this_object()))
        {
          z = ""+((int)gob->query_combo());
          break;
        }
        else
         z = "rc";
         break;
      case "bf":
        if(gob = present("bloodfist_gob", this_object()))
        {
          z = "" + "/players/fred/closed/bloodfist/daemon/honor_daemon"->query_honor(this_object()->query_real_name());
          break;
        }
        else
          z = "bf";
          break;
      case "intox":
        z = "" + (((int)this_object()->query_intoxination() * 100) / ((int)this_object()->query_max_intox())) +
       "";
        break;
      case "soa": 
        z = "" + (((int)this_object()->query_soaked()) * 100 / ((int)this_object()->query_max_soak())) + "";
        break;
      case "stu": 
        z = "" + (((int)this_object()->query_stuffed()) * 100 / ((int)this_object()->query_max_stuff())) + "";
        break;
      case "inf": 
        z = "" + (((int)this_object()->query_infuse() * 100) / inf) + "";
        break;
      case "wep" :
        if (gob = (object)this_object()->query_weapon())
          n = ((int)gob->query_wear() * 100) / 500;
        else
          n = 0;
        z = ""+n;
        break;
      case "nexp":
        if(n=(int)call_other("/bin/play/_xpnext", "query_next_xp", 0, this_object()))
          z= ""+n+"";
        else
          z="NOW!";
        break;
      case "ahp":
        if(a)
        {
          amhp = (int)a->query_mhp();
          if(!amhp) amhp = 1000000;
          z = "AHP: " + (((int)a->query_hp() * 10) / amhp) + "/10";
          break;
        }
        else
        z = "";
        break;

      case "coins":
        z = "" + (int)this_object()->query_money() + "";
        break;
      case "exp":
        z = "" + (int)this_object()->query_exp() + "";
        break;
      case "str":
        z = "" + (int)this_object()->query_attrib("str") + "";
        break;
      case "mag":
        z = "" + (int)this_object()->query_attrib("mag") + "";
        break;
      case "wil":
        z = "" + (int)this_object()->query_attrib("wil") + "";
        break;
      case "sta":
        z = "" + (int)this_object()->query_attrib("sta") + "";
        break;
      case "pie":
        z = "" + (int)this_object()->query_attrib("pie") + "";
        break;
      case "ste":
        z = "" + (int)this_object()->query_attrib("ste") + "";
        break;
      case "luc":
        z = "" + (int)this_object()->query_attrib("luc") + "";
        break;
      case "int":
        z = "" + (int)this_object()->query_attrib("int") + "";
        break;
      case "time":
        z = "" + ctime()[11..15] + "";
        break;
      case "al":
        z = "" + (string)this_object()->query_al_title() + "";
        break;
      case "ret":
        z = "\n";
        break;
    }
    if(!z) return reading;
    return z;
}

string
m_decode(string str, object monob)
{
   int s; 
   string *words;
   string tmpstr;

   words = explode(str, "#");
   s = sizeof(words);

   while(s--)
     if((tmpstr=replace_read(words[s])))
       words[s] = tmpstr;

   str = (implode(words, ""));

   words = explode(str, "$");
   s = sizeof(words);

   while(s--)
     if((tmpstr=replace_ansi(words[s])))
       words[s] = tmpstr;
   if(monob) {
     str = implode(words,"");
     words = explode(str,"&");
     s=sizeof(words);
     while(s--)
       if((tmpstr=(string)monob->monitor_code(words[s])))
         words[s]=tmpstr;
   }
   str = (implode(words, "")) + NORM;
   return str;
}

varargs void
print_monitor(object who)
{
    int att_mhp, l, inf;
    object o, a;
    string temp;

    if(o = present("guild_monitor", this_object()))
      if(o->guild_monitor_only())
      { 
        if (who) 
          write("Guild monitor in use, cannot display.\n");
        else
          o->print_monitor();
        return;
      }
      
    if(a = (object)this_object()->query_attack())
    {
      att_mhp = (int)a->query_mhp();
      if(!att_mhp) att_mhp = 1000000;
    }
    if(!monitor_string)
    {
       l = (int)this_object()->query_level();
       inf = ((int)this_object()->query_max_infuse());
      temp = 
      (((int)this_object()->query_mon() == 2) ? (RED) : "") + 
        "<<<<  HP "+(int)this_object()->query_hp()+"/"+(int)this_object()->query_mhp()+" SP "+
        (int)this_object()->query_spell_point()+"/"+(int)this_object()->query_msp()+" I "+
        (int)this_object()->query_intoxination()*100/(((int)this_object()->query_max_intox()))+"% F "+
      ((int)this_object()->query_stuffed()) * 100 / ((int)this_object()->query_max_stuff())+"% "+
        "S "+(((int)this_object()->query_soaked()) * 100 / ((int)this_object()->query_max_soak()))+"% "+
        "T "+(int)this_object()->query_infuse()*100/(inf)+"% " + (att_mhp ?
        "AHP "+ ((int)a->query_hp()*10)/(att_mhp)+"/10" : "") + 
        " >>>>\n" + NORM;
      if (who) tell_room(who, temp);
      else tell_object(this_object(), temp);
      if(o) o->print_monitor();
      return;
    }

    if (who) tell_peeps(who, m_decode(monitor_string,o)+"\n");
    else tell_object(this_object(), m_decode(monitor_string,o)+"\n");
    if(o) o->print_monitor();
}
     
query_monitor_string()
    {
        return monitor_string;
    }

set_monitor_string(heh)
    {
        monitor_string = heh;
    }
