/*
File: magic.c
Creator: Feldegast
Date: 1/11/01
Description:
  This is a revamp of Morgar's magic shop as part of my urban renewal project.
Other wizzes should feel free to add new items to this shop, and I encourage
them to do so.
*/

#include "/players/feldegast/defines.h"
#define VERTE "/players/vertebraker/misc/mage/items/"

inherit "/players/feldegast/std/shop.c";

string *dam_types;

void reset(int arg) {
  ::reset(arg);
  if(!present("rosenthal"))
    move_object(clone_object("/players/feldegast/mon/rosenthal.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc=HIM+"The Magic Shop"+NORM;
  long_desc=
"  This is a small, but cluttered shop filled with assorted magical\n\
artifacts, smelly reagents, and yellowed scrolls.  Near the back of\n\
the shop is a wooden counter.\n";
  items=({
    "shop","reflexive",
    "artifacts", "You can obtain a list of the items that you can "+BOLD+"purchase\n"+NORM+
                 "with the "+BOLD+"list"+NORM+" command.\n"+
               "You may also have Rosenthal "+BOLD+"identify"+NORM+" a piece of equipment",
    "reagents", "You can obtain a list of the items that you can "+BOLD+"purchase\n"+NORM+
                "with the "+BOLD+"list"+NORM+" command.\n"+
               "You may also have Rosenthal "+BOLD+"identify"+NORM+" a piece of equipment",                
    "scrolls", "You can obtain a list of the items that you can "+BOLD+"purchase\n"+NORM+
               "with the "+BOLD+"list"+NORM+" command.\n"+
               "You may also have Rosenthal "+BOLD+"identify"+NORM+" a piece of equipment",

  });
  dest_dir=({
    "/room/northroad2","east"
  });

  dam_types=({
    "dark","light","water","fire","wind","earth","ice","electric",
    "laser","evil","good","poison","sonic","mental"});
  add_item("Glowing orb",OBJ_PATH+"gorb.c",1200,3+random(5),1);
  add_item("Majin potion",HEAL_PATH+"majin.c",1800,8+random(8),1);
  add_item("Healing potion",HEAL_PATH+"fullheal.c",10000,4+random(3),1);
  add_item("Crystal amulet",ARM_PATH+"amulet.c",200,8+random(4),1);
  add_item("Helm of Farseeing",ARM_PATH+"farhelm.c",5000,random(2),3);
  add_item("Scroll of Identify",VERTE+"id", 150, 5+random(5), 1);
  add_item("Dusky Flask",VERTE+"dark", 1000, 5+random(5), 1);
  add_item("Wand of Portals",VERTE+"wand", 1500, 5+random(5), 1);
  add_item("Swirling blue and white potion",VERTE+"tele", 600, 5+random(5), 1);
  add_item("Green potion",VERTE+"regen", 900, 5+random(5), 1);
  add_item("Magenta potion",VERTE+"defense", 1050, 5+random(5), 1);
  add_item("Clear potion",VERTE+"invis", 750, 5+random(5), 1);
  add_item("Cyan potion",VERTE+"cure", 750, 5+random(5), 1);
}

void init() {
  ::init();
  add_action("buy","buy");
  add_action("buy","purchase");
  add_action("list","list");
  add_action("cmd_identify", "identify");
}

int buy(string arg) {
  int x;
  if(!present("rosenthal")) return 0;
  if(!arg) return 0;
  x=invalid_purchase(arg);
  switch(x) {
    case 1: write("Rosenthal says: We do not have that item.\n");
            return 1;
            break;
    case 2: write("Rosenthal says: That would cost more money than you possess.\n");
            return 1;
            break;
    case 3: write("Rosenthal says: I am out of that.\n");
            return 1;
            break;
    case 4: write("Rosenthal says: You appear to be a little overburdened at the moment.\n");
            return 1;
            break;
  }
  write("You purchase "+(::purchase(arg))+".\n");
  say((string)this_player()->query_name()+" makes a purchase.\n");
  return 1;
}


string get_ac_string(int num)
{
  string prot;
      switch(num)
      {
        case -666..-1:
          prot = HIR+"TERRIBLE"+NORM;
          break;
        case 0:
          prot = RED+"nil"+NORM;
          break;
        case 1:
          prot = HIK+"light"+NORM;
          break;
        case 2:
          prot = YEL+"moderate"+NORM;
          break;
        case 3:
          prot = HIY+"Good"+NORM;
          break;
        case 4:
          prot = GRN+"Excellent"+NORM;
          break;
        case 5:
          prot = HIG+"Superior"+NORM;
          break;
        default:
          prot = HIW+"Godlike"+NORM;
          break;
      }
  return prot;
}

string get_res_string(int num)
{
  string prot;
  
  switch(num)
  {
    case -666..-1:
      prot = HIR+"TERRIBLE"+NORM;
      break;
    case 0:
      prot = RED+"nil"+NORM;
      break;
    case 1..10:
      prot = HIK+"miniscule"+NORM;
      break;
    case 11..20:
      prot = CYN+"Small"+NORM;
      break;
    case 21..30:
      prot = HIC+"Fair"+NORM;
      break;
    case 31..40:
      prot = YEL+"Moderate"+NORM;
      break;
    case 41..50:
      prot = HIY+"Good"+NORM;
      break;
    case 51..60:
      prot = GRN+"Very Good"+NORM;
      break;
    case 61..70:
      prot = HIG+"Excellent"+NORM;
      break;
    case 71..80:
      prot = HIW+"Most Excellent"+NORM;
      break;
    case 81..90:
      prot = BRED+HIW+"Incredible"+NORM;
      break;
    case 91..100:
      prot = BYEL+HIW+"Utterly Mind Boggling"+NORM;
      break;
    default:
      prot = BGRN+HIW+BLINK+"Just plain ILLEGAL"+NORM;
      break;
   }
   return prot;
}

string get_wc_string(int num)
{
  string prot;
  
  switch(num)
  {
    case -666..-1:
      prot = HIR+"TERRIBLE"+NORM;
      break;
    case 0:
      prot = RED+"nil"+NORM;
      break;
    case 1..2:
      prot = HIK+"pathetic"+NORM;
      break;
    case 3..4:
      prot = HIK+"miniscule"+NORM;
      break;
    case 5..6:
      prot = CYN+"very minor"+NORM;
      break;
    case 7..8:
      prot = CYN+"minor"+NORM;
      break;
    case 9..10:
      prot = HIC+"very light"+NORM;
      break;
    case 11..12:
      prot = HIC+"light"+NORM;
      break;
    case 13..14:
      prot = YEL+"moderate"+NORM;
      break;
    case 15..16:
      prot = HIY+"Fair"+NORM;
      break;
    case 17:
      prot = GRN+"Good"+NORM;
      break;
    case 18:
      prot = HIG+"Excellent"+NORM;
      break;
    case 19:
      prot = HIW+"Most Excellent"+NORM;
      break;
    case 20:
      prot = HBRED+HIW+"Incredible"+NORM;
      break;
    case 21:
      prot = BRED+HIW+"Inconceivable"+NORM;
      break;
    case 22:
      prot = BYEL+HIW+"AMAZING"+NORM;
      break;
    case 23:
      prot = HBYEL+HIW+"QUASI-LEGAL"+NORM;
      break;
    case 24:
      prot = BGRN+HIW+"GARGANTUAN to the nth"+NORM;
      break;
    default:
      prot = HBGRN+HIW+BLINK+"IT WOULD MAKE BOLTAR CRY"+NORM;
      break;
  }
  return prot;
}

string colorize_dtype(string str)
{
  switch(str)
  {
    case "dark":
      return HIK+"Dark"+NORM;
    case "light":
      return HIY+"Light"+NORM;
    case "water":
      return HIB+"Water"+NORM;
    case "fire":
      return RED+"Fire"+NORM;
    case "wind":
      return CYN+"Wind"+NORM;
    case "earth":
      return YEL+"Earth"+NORM;
    case "ice":
      return HIC+"Ice"+NORM;
    case "electric":
      return HIY+"Electric"+NORM;
    case "laser":
      return HIR+"Laser"+NORM;
    case "evil":
      return HIK+"Evil"+NORM;
    case "good":
      return HIW+"Good"+NORM;
    case "poison":
      return GRN+"Poison"+NORM;
    case "sonic":
      return HIC+"Sonic"+NORM;
    case "mental":
      return HIM+"Mental"+NORM;
    case "magical":
      return MAG+"Magical"+NORM;
    default:
      return capitalize(str);
  }
  return 0; /* Rumplemintz */
}

int cmd_identify(string str)
{ 
  if(!present("rosenthal"))
    return 0;
    
  if(!str)
  {
    notify_fail("Ask Rosenthal to identify what?\n");
    return 0;
  }
  else
  {
    object obj;
    string dam_type;
    mixed  *c_params, *d_params;
    string prot, nm;
    int    x, y;
    
    if(!(obj=present(str,this_player())))
    {
      notify_fail("You're not carrying \""+str+"\".\n");
      return 0;
    }
    
    if((int)this_player()->query_money() < 3000)
    {
      write("You need 3000 coins in order for Rosenthal"+
            " to identify an item.\n");
      return 1;
    }
    
    this_player()->add_money(-3000);
    
    write("You hand your "+((nm=(string)obj->query_name())?nm:str)+
     " over to Rosenthal.\n");
    say((string)this_player()->query_name()+
    " exchanges goods with Rosenthal.\n");
    
    write("\n");
#define BAR (GRN+pad("",69,'~')+NORM+"\n")
    write(BAR);
    write("\t\t"+(string)obj->short()+"\n");
    write(BAR);
    c_params = (mixed*)obj->query_params();
    d_params=allocate(y=sizeof(c_params));
    for(x=0;x<y;x++)
      d_params[x]= c_params[x]; /* WHEN DID THIS MUD 
                                   START BEING PASS BY REF 
                                   FOR ARRAYS MAYBE IT IS MIXED */
    if(obj->is_armor())
    {
      prot=get_ac_string((int)obj->armor_class());
      write("\n  It offers "+prot+" protection from Physical damage.\n");
      prot=get_res_string((int)obj->query_res());
      write("  It has "+prot+" innate resistance to Physical damage.\n");
      if(obj->query_special())
        write("  It has hidden abilities in regards to Physical damage.\n");
        
      y=sizeof(d_params);
      for(x=0;x<y;x+=4)
      {
        if(d_params[x] == "physical") continue; /* just in case */
        if(d_params[x] != "magical")
        {
          if(!sscanf(d_params[x], "other|%s", d_params[x]))
            continue;
          if(member_array(d_params[x], dam_types)==-1)
            continue;
        }
        d_params[x]=colorize_dtype(d_params[x]);
        prot=get_ac_string(d_params[x+1]);
        write("\n  It offers "+prot+" protection from "+d_params[x]+" damage.\n");
        prot=get_res_string(d_params[x+2]);
        write("  It has "+prot+" innate resistance to "+d_params[x]+" damage.\n");
        if(d_params[x+3])
          write("  It has hidden abilities in regards to "+d_params[x]+" damage.\n");
      }
    }
    else if(obj->is_weapon())
    {
      y = sizeof(d_params);
      for(x=0;x<y;x+=3)
      {
        if(d_params[x] != "magical" && d_params[x] != "physical")
        {
          if(!sscanf(d_params[x], "other|%s", d_params[x]))
            continue;
          if(member_array(d_params[x], dam_types)==-1)
            continue;
        }
        d_params[x]=colorize_dtype(d_params[x]);
        prot=get_wc_string(d_params[x+1]);
        write("\n  It can inflict "+prot+" "+d_params[x]+" damage.\n");
        if(d_params[x+2])
          write("  It has hidden abilities in regards to "+d_params[x]+" damage.\n");
      } 
    }
    if(obj->query_info())
    {
      write("\n  Special information:\n");
      write((string)obj->query_info()+"\n");
    }
    if(sizeof((mapping)obj->query_enchantments()))
    {
      write("\n  It has been "+HIG+"Enchanted"+NORM+".\n");
    }
    write(BAR);
    write("\n");
    return 1;
  }
}
