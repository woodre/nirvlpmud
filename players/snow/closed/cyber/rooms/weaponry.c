#define TP  this_player()
#define TPN capitalize(TP->query_name())
#define EO  environment(ob)
#define ET  environment(TP)
#define FP  find_player
#define TE  tell_object
#define TR  tell_room
#define WHO capitalize(who)
#define RN  TP->query_real_name()
#define log "/players/snow/closed/cyber/log/"

inherit "room/room";

init() {
 add_action("register","register");
 add_action("select_weapon","select_weapon");
 add_action("change_weapon","change_weapon");
 add_action("show_weapons","show_weapons");
add_action("links","links");
add_action("buy_link","buy_link");
 ::init();
}

reset(arg){
if(!present("weaponmaster")) {
   move_object(clone_object("/players/snow/closed/cyber/rooms/WeaponmasteR.c"),
   this_object());}

 if(!arg){
 set_light(1);
 short_desc="CyberNinja Weapons Shop";
 long_desc=
"     An impressive assembly both familiar and mysterious weapons\n"+
"hang upon the walls around you.  Some you have never seen before,\n"+
"and others you've seen all to many times.  A large desk and a small\n"+
"training area lie in the center of the room.\n"+
"Please type 'register' to list the services available to you.\n";

items=({
 "weapons", "Hundreds of weapons hang on bolts attached to the walls",
 "walls","The walls are covered with hundreds of different weapons",
 "desk","This is the central service desk",
 "area","The training area is for your use any time of the day",
 "training area","The training area is for your use any time of the day",
 });

  dest_dir=({
 "/players/snow/closed/cyber/rooms/shop.c","west",
      });
  }   }

register() {
  string gender, gen;
  gender = TP->query_gender();
  if(gender == "male") gen = "his";
  if(gender == "female") gen = "her";
  if(gender == "creature") gen = "its";
  TE(TP,
  "Services available:\n\n"+
  "select_weapon <weapon>....buy a brand new ninja weapon\n"+
  "                          --costs vary as per weapon type\n"+
  "change_weapon <weapon>....change your ninja weapon to another\n"+
  "                          --costs xp and coins\n"+
  "show_weapons..............shows available weapons\n"+
  "links.....................Describes SmartWeapon links\n");
  TR(TP, TP->query_name()+" registers "+gen+" name.\n");
  return 1;
}

object IP(object ob) {
/* This function is similar to a #define, it just
 * returns the guild object on the player specified.
 */
   object guild_object;
   guild_object = present("implants", ob);
   return guild_object;
}

select_weapon(string str) {
  int credits, cost, temp;
  string wep, currentwep;
  if(!present("weaponmaster")) {
    TE(TP, "The weaponmaster is gone.\n");
    TE(TP, "Looks like you'll have to try again later.\n");
    return 1;}
  if(!str) {
    TE(TP, "Usage: select_weapon <weapon>.\n");
    return 1; }
  if(!isAweapon(str)) {
    TE(TP, "There is no such weapon as a "+str+".\n");
    return 1; }
  wep = findGoodNameForWeapon(str);
  currentwep = IP(TP)->query_weapon();
  credits = IP(TP)->balance();
  cost = costOfWeapon(wep);
  if(currentwep == wep) {
    TE(TP, "You are already training in this weapon.\n");
    return 1;}
  if(!currentwep) {
    if(credits < cost) {
      temp = cost - credits;
      TE(TP, "You do not have enough credits to buy a "+wep+".\n");
      TE(TP, "You are "+temp+" @'s short.\n");
      return 1; }
    IP(TP)->set_weapon(wep);
    IP(TP)->addToBalance(-cost);
    IP(TP)->save_me();
    write_file(log+"WEAPONRY", TP->query_real_name()+
               " selected the "+wep+" weapon. ("+ctime()+")\n");
    TE(TP, "You have chosen to train in the "+wep+".\n");
    say(TPN+" has chosen to train in the "+wep+".\n");
    return 1; }
  TE(TP, "You are already training in the "+currentwep+".\n");
  TE(TP, "Use 'change_weapon' to choose a different weapon.\n");
  TE(TP, "Note: it costs xp to change_weapon.\n");
  return 1;
}

change_weapon(string str) {
  string wep, currentwep;
  int level, xp, lowxp, freexp, temp;
  int old_cost, new_cost, diffcost, credits, shortcost;
  if(!present("weaponmaster")) {
    TE(TP, "The weaponmaster is gone.\n");
    TE(TP, "Looks like you'll have to try again later.\n");
    return 1;}
  if(!str) {
    TE(TP, "Usage: change_weapon <weapon>.\n");
    return 1; }
  if(!isAweapon(str)) {
    TE(TP, "There is no such weapon as a "+str+".\n");
    return 1; }
  wep = findGoodNameForWeapon(str);
  currentwep = IP(TP)->query_weapon();
  if(currentwep == wep) {
    TE(TP, "You are already training in this weapon.\n");
    return 1;}
  if(!currentwep) {
    TE(TP, "You must select a weapon first.\n");
    return 1;}
  old_cost = costOfWeapon(currentwep);
  new_cost = costOfWeapon(wep);
  diffcost = new_cost - old_cost;
  diffcost += 1000; /* extra handling fee */
  credits = IP(TP)->balance();
  level = IP(TP)->guild_lev();
  xp = IP(TP)->guild_exp();
  lowxp = IP(TP)->low_exp(level);
  freexp = xp - lowxp;
  if(freexp < 50000) {
    TE(TP, "You do not have enough free guild experience.\n");
    temp = 50000 - freexp;
    TE(TP, "You need "+temp+
           " more experience to change your weapon.\n");
    return 1; }
  if(diffcost > credits) {
    shortcost = diffcost - credits;
    TE(TP, "You do not have enough credits to change weapons.\n");
    TE(TP, "You are short "+shortcost+" @'s.\n");
    return 1; }
  if(diffcost < 0) {
    diffcost = -diffcost;
    TE(TP, "You get a refund of "+
           diffcost+" @'s for you weapon switch.\n");
    diffcost = -diffcost;
    }
  write_file(log+"WEAPONRY", TP->query_real_name()+
             " changed from "+currentwep+" to "+wep+". ("+ctime()+")\n");
  TE(TP, "You change weapons from a "+currentwep+
         " to a "+wep+".\n");
  say(TPN+" changes weapons.\n");
  IP(TP)->set_weapon(wep);
  IP(TP)->addToBalance(-diffcost);
  IP(TP)->add_xp(-50000);
  IP(TP)->save_me();
  IP(TP)->update_implants();
  return 1;
}

int costOfWeapon(string wep) {
  int cost, level;
  level = ((int)IP(TP)->query_art_level());
  level = level * 1000;
  cost = level;
  switch(wep) {
    case "ninja_to":         cost += 3000; break;
    case "naginata":         cost += 2000; break;
    case "kusari_gama":      cost += 1000; break;
    case "ton-fa":           cost += 1000; break;
    case "unarmed":          cost += 0; break;
    }
  return cost;
}

int isAweapon(string wep) {
  switch(wep) {
    case "ninja-to":        return 1; break;
    case "ninja_to":        return 1; break;
    case "ninjato":         return 1; break;
    case "to":              return 1; break;
    case "kusari_gama":     return 1; break;
    case "kusari-gama":     return 1; break;
    case "kusarigama":      return 1; break;
    case "kusari":          return 1; break;
    case "gama":            return 1; break;
    case "naginata":        return 1; break;
    case "nag":             return 1; break;
    case "ton-fa":          return 1; break;
    case "tonfa":           return 1; break;
    case "unarmed":         return 1; break;
    }
  return 0;
}

string findGoodNameForWeapon(string wep) {
  string name;
  switch(wep) {
    case "ninja_to":        name = "ninja_to"; break;
    case "ninja-to":        name = "ninja_to"; break;
    case "ninjato":         name = "ninja_to"; break;
    case "to":              name = "ninja_to"; break;
    case "kusari_gama":     name = "kusari_gama"; break;
    case "kusari-gama":     name = "kusari_gama"; break;
    case "kusarigama":      name = "kusari_gama"; break;
    case "kusari":          name = "kusari_gama"; break;
    case "gama":            name = "kusari_gama"; break;
    case "naginata":        name = "naginata"; break;
    case "nag":             name = "naginata"; break;
    case "ton-fa":          name = "ton-fa"; break;
    case "tonfa":           name = "ton-fa"; break;
    case "unarmed":         name = "unarmed"; break;
    }
  return name;
}

get_weapon(string wep) {
 string file;
 object wepob;
 file = "/players/snow/closed/cyber/";
 switch(wep) {
  case "ninja_to":
       wepob = clone_object("/players/ulath/closed/ninjaweps/ninjato.c");
       break;
  case "kusari_gama":
       wepob = clone_object(file+"kusarigama.c");
       break;
  case "naginata":
       wepob = clone_object(file+"naginata.c");
       break;
  case "unarmed":
       wepob = clone_object(file+"hands.c");
       break;
  case "ton-fa":
       wepob = clone_object("/players/ulath/closed/ninjaweps/ton-fa.c");
       break;
  }
 move_object(wepob, this_player());
}

show_weapons() {
  write(
"________________________________________________________\n"+
"WEAPONS CURRENTLY AVAILABLE                  COST\n"+
"________________________________________________________\n"+
"\n"+
" Ninja-To <ninja sword>..................."+
  costOfWeapon("ninja_to")+" @'s\n"+
" Naginata <ninja spear>..................."+
  costOfWeapon("naginata")+" @'s\n"+
" Kusari-Gama <ninja scythe>..............."+
  costOfWeapon("kusari_gama")+" @'s\n"+
" Ton-Fa <ninja short staff>..............."+
  costOfWeapon("ton-fa")+" @'s\n"+
" Unarmed <no weapon>......................"+
  costOfWeapon("unarmed")+"@'s\n"+
"________________________________________________________\n");
return 1;
}

links() {
  write("<><><><><><><><><><><><><><><><><><><><><><>\n"+
        "<>Smartweapon Link current prices:\n"+
        "<>\n"+
        "<>First Link...............@100000\n"+
        "<>Subsequent Links (4).....@50000\n"+
        "<><><><><><><><><><><><><><><><><><><><><><>\n");
  write("--To order a SmartWeapon link, buy_link--\n");
  return 1;
}

buy_link() {
  int cost;
  if(!present("weaponmaster")) {
    write("The WeaponMaster is gone.\n"+
          "Looks like you'll have to try again later.\n");
    return 1;
  }
  if(IP(TP)->item_weplink() > 0) cost = 50000;
  if(IP(TP)->item_weplink() == 0) cost = 100000;
  if(!cost) return 1;
  if(IP(TP)->item_weplink() > 4) {
    write("Your SmartWeapon Link is as juiced as it can get.\n");
    return 1;
  }
  if(IP(TP)->balance() < cost) {
    write("You do not have enough credits to buy a SmartWeapon Link.\n");
    return 1;
  }
  if(cost == 100000) {
    write("The WeaponMaster inserts SmartWeapon mnemonic fibers up through\n"+
          "your hands and arms into your implants. It is slightly painful.\n");
    IP(TP)->addToBalance(-cost);
    IP(TP)->set_weplink(1);
    IP(TP)->save_me();
    IP(TP)->update_implants();
    return 1;
  }
  if(cost == 50000) {
    write("The WeaponMaster installs a booster link and fibers through your\n"+
          "muscles and skeletal structure.\n");
  }
  IP(TP)->addToBalance(-cost);
  IP(TP)->add_weplink(1);
  IP(TP)->save_me();
    IP(TP)->update_implants();
  return 1;
}

feel() { return "no"; }