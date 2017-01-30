inherit "obj/treasure";
#include "/players/zeus/closed/all.h"
int stype, ws, spec, held;
string *gnames, *spec1, *spec2, *spec3;

reset(arg){
  if (arg) return;

  stype = 0;
  spec = 0; /* which group if special */
  ws = 0;   /* which index in group if special */
 
  set_weight(1);
  set_save_flag(1);  /* unstorable - except in gem case */
  set_value(12000);

  gnames =({ "crystal gem", "ruby gem", "emerald gem", "sapphire gem", 
    "diamond gem", "onyx gem", "topaz gem", "amethyst gem", 
  });

  spec1 =({ "crystal gem", "minor gem of agility", "minor gem of might", 
    "minor gem of accuracy", "minor gem of vigor", "minor gem of wisdom",
    "minor gem of faith", "prismatic gem", "gem of decay", "chaos gem",
    "gem of purity", "gem of hatred", "minor gem of performance",
    "gem of beauty", "gem of fury", "gem of eternity", "vortex gem",
    "lightning gem", "gem of unholy death rites", "gem of fortitude",
    "gem of moss", "gem of rain", "gem of idiocy", "gem of emotion",
    "minor gold gem", "minor gem of regeneration", 
    "minor gem of rejuvenation", "minor gem of restoration",
    "gem of instability", "faerie gem", "gem of pk", "gem of winter",
    "minor gem of cleansing", "gem of combat skills",
  });

  spec2 =({ "crystal gem", "gem of agility", "gem of might",
    "gem of accuracy", "gem of vigor", "gem of wisdom", "gem of faith",
    "soul gem", "gem of speed", "gem of performance", "blood gem",
    "sand gem", "ryo gem", "xetra gem", "gold gem", "angelic gem",
    "demonic gem", "gem of regeneration", "gem of rejuvenation",
    "gem of restoration", "gem of provoked aggression", "gem of the dragon",
    "gem of cleansing",
  });

  spec3 =({ "crystal gem", "major gem of agility", "major gem of might", 
    "major gem of accuracy", "major gem of vigor", "major gem of wisdom",
    "major gem of faith", "major gem of performance", "major gold gem",
    "gem of zeus", "holy angelic gem", "unholy demonic gem",
    "major gem of regeneration", "major gem of rejuvenation",
    "major gem of restoration", "minds eye gem", "gem of inescapable horror",
    "major gem of cleansing", "gem of battle rites", "sage gem",
    "timeless gem",
  });

}

short(){ 
  if(stype == 1) return RED+"A ruby gem"+NORM;
  else if(stype == 2) return HIG+"An emerald gem"+NORM;
  else if(stype == 3) return BLU+"A sapphire gem"+NORM;
  else if(stype == 4) return HIW+"A diamond gem"+NORM;
  else if(stype == 5) return BOLD+BLK+"An onyx gem"+NORM;
  else if(stype == 6) return HIY+"A topaz gem"+NORM;
  else if(stype == 7) return "An amethyst gem";

  else if(spec == 1) return "A "+spec1[ws];
  else if(spec == 2) return HIW+"A "+spec2[ws]+NORM;
  else if(spec == 3) return BOLD+BLK+"A "+spec3[ws]+NORM;

  else return "A crystal gem";
}

id(x){
       if(stype == 0) return x == "crystal" || x == "gem"
         || x == "fred_bloodfist_gem";
  else if(stype == 1) return x == gnames[stype] || x == "gem"
    || x == "fred_bloodfist_gem" || x == "ruby";
  else if(stype == 2) return x == gnames[stype] || x == "gem"
    || x == "fred_bloodfist_gem" || x == "emerald";
  else if(stype == 3) return x == gnames[stype] || x == "gem"
    || x == "fred_bloodfist_gem" || x == "sapphire";
  else if(stype == 4) return x == gnames[stype] || x == "gem"
    || x == "fred_bloodfist_gem" || x == "diamond";
  else if(stype == 5) return x == gnames[stype] || x == "gem"
    || x == "fred_bloodfist_gem" || x == "onyx";
  else if(stype == 6) return x == gnames[stype] || x == "gem"
    || x == "fred_bloodfist_gem" || x == "topaz";
  else if(stype == 7) return x == gnames[stype] || x == "gem"
    || x == "fred_bloodfist_gem" || x == "amethyst";
  else return x == "gem" || x == "fred_bloodfist_gem";
}

long(){
  string gem_name;

  if(spec == 1) gem_name = spec1[ws];
  else if(spec == 2) gem_name = spec2[ws];
  else if(spec == 3) gem_name = spec3[ws];
  else gem_name = gnames[stype];

  write("This is a beautiful "+gem_name+".  It shines with an\n"+
    "inner light that seems quite magical and has a subtle\n"+
    "warmth to it.  This gem could be socketed into a weapon\n"+
    "that was forged correctly to add magical properties to it.\n");
  if(stype == 0 && spec == 0)
    write("Hold this gem to uncover its true potential.\n");
  if(spec)
    write("This is a level "+query_spec()+" gem.\n");
}

void set_stype(int x){  stype = x; } /* set type from NPC gem_seller.c */
void set_ws(int x){     ws = x;    } /* used in gem storage */
void set_spec(int x){   spec = x;  } /* used in gem storage */
void set_held(int x){   held = x;  } /* used when held */
int query_stype(){      return stype; } /* which type if normal */
int query_ws(){         return ws;    } /* which index in group if special */
int query_spec(){       return spec;  } /* which group if special */
int query_held(){       return held;  } /* has the gem been held yet? */
string query_gname(){   return gnames[stype]; } /* what is the gname */
int query_is_bf_gem(){  return 1; } /* is this a bf gem */


void init(){
  ::init();
  add_action("socket", "socket");
  add_action("hold", "hold");
  add_action("wizgemset", "wizgemset");
  add_action("wizgemlist", "wizgemlist");
}

int wizgemset(string a){
  int which;
  if(this_player()->query_level() < 70 && 
     (string)this_player()->query_real_name() != "fred" &&
     (string)this_player()->query_real_name() != "forbin") return 0;
  if(!present(this_object(), this_player())) return 0;
  if(!a){
    notify_fail("What type of gem do you want to set this to?\n");
    return 0;
  }
  if((which = index(gnames, a)) > -1){
    stype = which;
    write("You set the gem to: "+gnames[stype]+".\n");
    this_object()->set_held(1);    
  }
  else if((which = index(spec1, a)) > -1){
    stype = 0;
    ws = which;
    spec = 1;
    write("You set the gem to: "+spec1[ws]+".\n");
    this_object()->set_held(1);        
  }
  else if((which = index(spec2, a)) > -1){
    stype = 0;
    ws = which;
    spec = 2;
    write("You set the gem to: "+spec2[ws]+".\n");
    this_object()->set_held(1);        
  }
  else if((which = index(spec3, a)) > -1){
    stype = 0;
    ws = which;
    spec = 3;
    write("You set the gem to: "+spec3[ws]+".\n");
    this_object()->set_held(1);        
  }
  return 1;
}

int wizgemlist(){
  int a, size;
  if(this_player()->query_level() < 60  && 
    (string)this_player()->query_real_name() != "fred" &&
    (string)this_player()->query_real_name() != "forbin") return 0;
  if(!present(this_object(), this_player())) return 0;
  write(BOLD+BLK+"Main: "+NORM);
  size = sizeof(gnames);
  for(a = 1; a < size; a++)
    write(gnames[a]+", ");
  size = sizeof(spec1);
  write(BOLD+BLK+"\n\nSpecial Group 1 ("+(size - 1)+"): "+NORM);
  for(a = 1; a < size; a++)
    write(spec1[a]+", ");

  size = sizeof(spec2);
  write(BOLD+BLK+"\n\nSpecial Group 2 ("+(size - 1)+"): "+NORM);
  for(a = 1; a < size; a++)
    write(spec2[a]+", ");

  size = sizeof(spec3);
  write(BOLD+BLK+"\n\nSpecial Group 3 ("+(size - 1)+"): "+NORM);
  for(a = 1; a < size; a++)
    write(spec3[a]+", ");
  write("\n");
  return 1;
}

int hold(string a){
  int r;
  if(a != "gem") return 0;
  if(!present(this_object(), this_player())) 
  {
    write("You must have a gem first.\n");
    return 1;
  }
  if(stype || spec || ws) return 0;
  r = random(100);
  if(r < 50){
    spec = 1;
    ws = 1 + random(sizeof(spec1) - 1);
  }
  else if(r < 85){
    spec = 2;
    ws = 1 + random(sizeof(spec2) - 1);
  }
  else if(r < 100){
    spec = 3;
    ws = 1 + random(sizeof(spec3) - 1);
  }
  write("You hold the crystal gem between your hands.\n"+
    "It slowly grows warm, revealing its true nature.\n");
  if(spec == 1)
    write("The gem has become a "+spec1[ws]+".\n");
  else if(spec == 2)
    write("The gem has become a "+spec2[ws]+".\n");
  else if(spec == 3)
    write("The gem has become a "+spec3[ws]+".\n");
  say(this_player()->query_name()+" holds a crystal gem between "+
    this_player()->POS+" hands.\n");
  this_object()->set_held(1); 
  return 1;
}

void randomize_special(){
  int r;
  if(spec || ws) return 0;
  r = random(100);
  if(r < 50){
    spec = 1;
    ws = 1 + random(sizeof(spec1) - 1);
  }
  else if(r < 85){
    spec = 2;
    ws = 1 + random(sizeof(spec2) - 1);
  }
  else if(r < 100){
    spec = 3;
    ws = 1 + random(sizeof(spec3) - 1);
  }
}

int socket(string a){
  object wep, c, gob;
  if(!present(this_object(), this_player())) return 0;
  if(!a) return 0;
  if(!query_held())
  {
    write("You must hold the gem first.\n");
    return 1;
  }
  if(a == "gem" || a == "wep" || a == "weapon" || id(a))
  {
    object *all;
    int sa,b;
    all = all_inventory(this_player());
    sa = sizeof(all);
    while(b < sa && !wep)
    {
      if(all[b]->query_bloodfist_wep_shadow())
        wep = all[b];
      b++;
    }
  }
  else if((c = present(a, this_player())))
  {
    if(c->query_bloodfist_wep_shadow())
      wep = c;
  }
  gob = present("bloodfist_gob", this_player());
  if(!gob)
  {
    write("You must be a Bloodfist to socket a weapon.\n");
    return 1;
  }
  else if(!gob->level_check(4))
  {
    write("You must be at least guild level 4 to socket a weapon.\n");
    return 1;
  }
  if(!wep){
    write("What weapon do you want to socket the gem into?\n");
    return 1;
  }
  if(wep && wep->query_socketed())
    write("That weapon has already been socketed with a gem.\n");
  else if(wep && !wep->query_socket() && this_player()->query_level() < 21)
    write("That weapon can not be socketed with a gem.\n");
  else if(wep && wep->query_wielded())
    write("You can not socket a wielded weapon.\n");
  else {
    write("You socket "+wep->short()+" with "+short()+".\n");
    wep->socket(gnames[stype], spec, ws);
    wep->set_socketed();
    destruct(this_object());
  }
  return 1;
}



