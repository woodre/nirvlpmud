inherit "/obj/monster";
#include "/players/fred/closed/bloodfist/defs.h"
#define FORGE_PRICE 3000
#define SOCKET_PRICE 6000
#define ME "Draelok"
object armor,sword,boots,cap,gob,merch;
int *eqcs, a;

reset(arg){
  if(arg) return;
  ::reset(arg);

  eqcs =({ 0,2800,2800,2800,2800,3300,3300,1800,2500 });

  for(a = 0; a < 2; a++)
    move_object(clone_object(DIR+"obj/water.c"), this_object());

  cap = clone_object("/obj/armor.c");
  cap->set_type("helmet");
  cap->set_name("cap");
  cap->set_short("A leather cap");
  cap->set_long(
    "This is a simple looking leather cap with flaps on the side that\n"+
    "hang down over the wearers ears to keep them warm.  It has been\n"+
    "taken well care of since it was made.\n");
  cap->set_weight(1);
  cap->set_ac(1);
  cap->set_value(200);
  move_object(cap, this_object());
  init_command("wear cap");

  boots = clone_object("/obj/armor.c");
  boots->set_type("boots");
  boots->set_name("boots");
  boots->set_short("A pair of tough boots");
  boots->set_long(
    "This pair of boots are old and worn, yet look incredibly comfortable\n"+
    "inside.  They are made from a very tough leather that is quite thick.\n"+
    "They may not be stylish, but they are still quite nice boots.\n");
  boots->set_weight(2);
  boots->set_ac(1);
  boots->set_value(1400);
  move_object(boots, this_object());
  init_command("wear boots");

  armor = clone_object("/obj/armor.c");
  armor->set_name("chainmail");
  armor->set_type("armor");
  armor->set_short("A suit of light chainmail");
  armor->set_long(
    "This is a suit of light chainmail.  It is well crafted despite\n"+
    "its old age and lacks any ornamentation.  It looks like it would\n"+
    "provide good protection in combat.\n");
  armor->set_weight(1);
  armor->set_ac(4);
  move_object(armor, this_object());
  init_command("wear armor");

  sword = clone_object("/obj/weapon.c");
  sword->set_type("dagger");
  sword->set_alias("longknife");
  sword->set_weight(1);
  sword->set_class(18);
  sword->set_short("An etched longknife");
  sword->set_long(
    "This longknife was forged from steel and etched with a mystical\n"+
    "pattern along its blade.  The blade is jagged and sharp, appearing\n"+
    "as though it could tear through the toughest hides.\n");
  move_object(sword, this_object());
  init_command("wield dagger");

  set_name("draelok");
  set_alt_name("blacksmith");
  set_alias("smith");
  set_short(ME+" the Blacksmith");
  set_long(
ME+" is a gigantic man who seems to tower over you, his barrel chest\n"+
"protruding from beneath his cloth and chainmail.  His arms are like\n"+
"pistons, scarred and tough.  There is no question that this man knows\n"+
"his weapons and has seen his share of combat.\n");
  set_race("human");
  set_level(23);
  set_ac(17);
  set_ac_bonus(10);
  set_wc(70);
  set_wc_bonus(10);
  set_hp(4000);
  set_gender("male");
  set_chat_chance(1);
  set_a_chat_chance(6);
  load_chat(ME+" clutches at his longknife.\n");
  load_chat(ME+" adjusts his chainmail.\n");
  load_chat(ME+" looks up at the darkness.\n");
  load_chat(ME+" looks up at the sky.\n");
  load_chat(ME+" says, \"We will never give up.\"\n");
  load_chat(ME+" glances at you.\n");
  load_chat(ME+" looks you up and down.\n");
  load_chat(ME+" says, \"I will defend our home with my life.\"\n");
  load_chat(ME+" asks, \"Need anything sharpened or repaired?\"\n");
  load_a_chat(ME+" says, \"You will gain nothing from my death.\"\n");
  load_a_chat(ME+" dodges to the side.\n");
  load_a_chat(ME+" ducks quickly.\n");
  set_dead_ob(this_object());
}

void monster_died(){
  write_file("/players/fred/closed/bloodfist/log/NPC",
  ctime(time())+" - "+attacker_ob->query_name()+" [L "+
  attacker_ob->query_level()+
  "+"+attacker_ob->query_extra_level()+"] killed "+ME+".\n");
}

void drink_water()
{
  object tmp;
  if((tmp = present("zbf_water", this_object())))
  {
    tell_room(environment(),
      ME+" drinks from a canteen of water.\n");
    hit_point += 50;
    tmp->use_charge();
  }
}

void init(){
  ::init();
  add_action("forge_cmd", "forge");
  add_action("sharpen",   "sharpen");
  add_action("repair",    "repair");
  add_action("list",      "list");
  add_action("buy",       "buy");
  add_action("sell",       "sell");
}

void bow_back(object you){
  if(you && present(you, environment()))
  {
    if(gob = present("bloodfist_gob", you))
    {
      tell_object(you, ME+" bows to you.\n");
      tell_room(environment(), ME+" bows to "+you->query_name()+".\n",
        ({ you }));
    }
    else {
      tell_object(you, ME+" glances at you.\n");
      tell_room(environment(), ME+" glances at "+you->query_name()+".\n",
        ({ you }));
    }
  }
}

void arrives(object you)
{
  int g;
  if(you && present(you, environment()))
  {
    g = random(11);
    switch(g)
    {
    case 0..4:
      tell_object(you, ME+" glances at you.\n");
      tell_room(environment(), ME+" glances at "+you->query_name()+".\n",
        ({ you }));
      break;
    case 5:
      tell_room(environment(), 
        ME+" says, \"Greetings "+you->query_name()+".\"\n");
      break;
    case 6:
      tell_room(environment(),
        ME+" says, \"Hello "+you->query_name()+".\"\n");
      break;
    case 7:
      tell_object(you, ME+" smiles at you.\n");
      tell_room(environment(), ME+" smiles at "+you->query_name()+".\n",
        ({ you }));
      break;
    case 8..10:
      break;
    }
  }
}

status sharpen(string str)
{
  object it, gob;
  int cost;
  if(!str)
    return (notify_fail(ME+" says, \"What weapon needs sharpening?\"\n"),0);
  if(!(it = present(str, this_player())))
    return (notify_fail(ME+" says, \"What weapon needs sharpening?\"\n"),0);
  if(!(gob = present("bloodfist_gob", this_player())))
    return (notify_fail(ME+" says, \"You are no Bloodfist.\"\n"),0);
  if((int)it->query_broke() == 1)
    return (notify_fail(ME+" says, \"I can't sharpen a broken weapon.\"\n"),0);
  if((object)this_player()->query_weapon() == it)
    return (notify_fail(ME+" says, \"Please unwield it.\"\n"),0);
  cost = 1000 - 
    (int)HONOR_DAEMON->query_honor((string)this_player()->query_real_name());
  if(cost < 0)
    cost = 0;
  if(this_player()->query_money() < cost)
    return (notify_fail(ME+" says, \"You can't afford it.\"\n"),0);
  write(ME+" sharpens your "+it->short()+".\n");
  tell_room(environment(), ME+" sharpens "+this_player()->query_name()+
    "'s "+it->short()+".\n", ({ this_player() }));
  this_player()->add_money(-cost);
  it->set_hits(1);
  it->set_misses(1);
  return 1;
}

status repair(string str)
{
  object it, gob;
  int cost;
  if(!str)
    return(notify_fail(ME+" says, \"What weapon needs repairing?\"\n"),0);
  if(!(it = present(str, this_player())))
    return (notify_fail(ME+" says, \"What weapon needs repairing?\"\n"),0);
  if(!(gob = present("bloodfist_gob", this_player())))
    return (notify_fail(ME+" says, \"You are no Bloodfist.\"\n"),0);
  if((object)this_player()->query_weapon() == it)
    return (notify_fail(ME+" says, \"Please unwield it.\"\n"),0);
  if(!it->fix_weapon())
    return (notify_fail(ME+" says, \"That weapon isn't broken.\"\n"),0);
  cost = 1800 - 
    ((int)HONOR_DAEMON->query_honor((string)this_player()->query_real_name())
    * 2);
  if(cost < 0)
    cost = 0;
  if(this_player()->query_money() < cost)
  {
    it->re_break();
    return (notify_fail(ME+" says, \"You can't afford it.\"\n"),0);
  }
  write(ME+" repairs and sharpens your "+it->short()+".\n");
  tell_room(environment(), ME+" repairs and sharpens "+
    this_player()->query_name()+"'s "+it->short()+".\n", ({ this_player() }));
  it->set_hits(1);
  it->set_misses(1);
  return 1;
}

status forge_cmd(string str){
  object tmp, shad;
  int cur, max, x, num;
  string a;
  gob = present("bloodfist_gob", this_player());
  if(!gob)
  {
    tell_room(environment(), 
      ME+" says, \"Why are you here?  You are no Bloodfist.\"\n");
    return 1;
  }
  max = (int)gob->query_chosen_max();
  cur = (int)gob->query_chosen_current();
  if(!str || str == "help" || str == "info")
  {
    tell_room(environment(),
      ME+" says, \"If you have advanced one of your chosen weapons up to\"\n"+
      "              \"level 8 then I would be more than happy to forge it\"\n"+
      "              \"for you.  I can make it with or without a socket.  If\"\n");
    tell_room(environment(),
      "              \"it has a socket you can add a gem to it which will\"\n"+
      "              \"imbue it with magical properties.\"\n\n"+
      ME+" says, \"Type 'chosen' to see a list of your chosen weapons.\"\n");
    tell_room(environment(),
      "              \"Type 'forge <num>' to get a weapon forged for "+
      FORGE_PRICE+" gold.\"\n"+
      "              \"Type 'forge <num> socket' to get a socketed "+
      "weapon\"\n"+
      "              \"forged for only "+SOCKET_PRICE+" gold.\"\n"+
      "\n");
    return 1;
  }
  if(max && !cur)
  {
    tell_room(environment(), 
      ME+" says, \"You have not chosen any weapons yet.\"\n");
    return 1;
  }
  else if(max && cur)
  {
    if(str == "1" || str == "2" || str == "3" || str == "4") /* forge */
    {
      if(str == "1") num = 0;
      else if(str == "2") num = 1;
      else if(str == "3") num = 2;
      else if(str == "4") num = 3;
      if(num >= max)
      {
        tell_room(environment(), 
          ME+" says, \""+this_player()->query_name()+", you might want "+
          "to type 'chosen' again.\"\n");
        return 1;
      }

      a = "/"+gob->query_chosen(num)+".c";
      if(a == "/0.c")
      {
        write("That weapon can't be forged, error.\n");
        return 1;
      }
      tmp = clone_object(a);

      if(gob->query_chosen_lvl(num) < 8)
      {
        tell_room(environment(), 
          ME+" says, \"You must reach at least level 8 with a chosen weapon\"\n"+
          "              \"before I can forge it for you "+
          this_player()->query_name()+".\"\n");
        return 1;
      }
      if((int)this_player()->query_money() < FORGE_PRICE)
      {
        tell_room(environment(), 
          ME+" says, \"It doesn't look like you can afford it "+
          this_player()->query_name()+".\"\n");
        return 1;
      }
      else if(!this_player()->add_weight((int)tmp->query_weight()))
      {
        tell_room(environment(), 
          ME+" says, \"It doesn't look like you can carry it "+
          this_player()->query_name()+".\"\n");
        return 1;
      }

      this_player()->add_money(-FORGE_PRICE);
      move_object(tmp, this_player());
      shad = clone_object("/players/fred/closed/bloodfist/obj/wep_shadow.c");
      shad->set_bloodfist_wep_shadow(tmp);
      tmp->set_owner(this_player()->query_real_name());
      tmp->set_forged();

      tell_room(environment(),  /* will this work on a time delay */
        ME+" skillfully forges a weapon for "+
        this_player()->query_name()+".\n"+
        ME+" says, \"Here "+this_player()->query_name()+
        ", this is for you.\"\n");
      return 1;
    } /* end non-socket forge */
    else if(sscanf(str, "%d %s", num, a))  /* forge w/ socket */
    {
      if(a != "socket")
        return (notify_fail(ME+" looks at you peculiarly.\n"), 0);
      num--;
      if(num >= max)
      {
        tell_room(environment(), 
          ME+" says, \""+this_player()->query_name()+", you might want "+
          "to type 'chosen' again.\"\n");
        return 1;
      }

      a = "/"+gob->query_chosen(num)+".c";
      if(a == "/0.c")
      {
        write("That weapon can't be forged, error.\n");
        return 1;
      }
      tmp = clone_object(a);

      if(gob->query_chosen_lvl(num) < 8)
      {
        tell_room(environment(), 
          ME+" says, \"You must reach at least level 8 with a chosen weapon\"\n"+
          "              \"before I can forge it for you "+
          this_player()->query_name()+".\"\n");
        return 1;
      }
      if((int)this_player()->query_money() < SOCKET_PRICE)
      {
        tell_room(environment(), 
          ME+" says, \"It doesn't look like you can afford it "+
          this_player()->query_name()+".\"\n");
        return 1;
      }
      else if(!this_player()->add_weight((int)tmp->query_weight()))
      {
        tell_room(environment(), 
          ME+" says, \"It doesn't look like you can carry it "+
          this_player()->query_name()+".\"\n");
        return 1;
      }

      this_player()->add_money(-SOCKET_PRICE);
      move_object(tmp, this_player());
      shad = clone_object("/players/fred/closed/bloodfist/obj/wep_shadow.c");
      shad->set_bloodfist_wep_shadow(tmp);
      tmp->set_owner(this_player()->query_real_name());
      tmp->set_socket();      /* set the weapon to have empty socket */
      tmp->set_forged();

      tell_room(environment(),  /* will this work on a time delay */
        ME+" skillfully forges a socketed weapon for "+
        this_player()->query_name()+".\n"+
        ME+" says, \"Here "+this_player()->query_name()+
        ", this is for you.\"\n");
      return 1;
    } /* end socket forge */
  } /* end if max and cur */
  return 0;
}

status list(string str)
{
  tell_object(this_player(),
    ME+" says, \"Here is the equipment I have for sale.\"\n"+
    pad("  1.  Blood amulet of agility",48)+eqcs[1]+"g\n"+
    pad("  2.  Blood amulet of might",48)+eqcs[2]+"g\n"+
    pad("  3.  Blood amulet of accuracy",48)+eqcs[3]+"g\n"+
    pad("  4.  Blood amulet of vigor",48)+eqcs[4]+"g\n"+
    pad("  5.  Blood amulet of wisdom",48)+eqcs[5]+"g\n"+
    pad("  6.  Blood amulet of faith",48)+eqcs[6]+"g\n"+
    pad("  7.  Combat Boots",48)+eqcs[7]+"g\n"+
    pad("  8.  Bloodfist Ring",48)+eqcs[8]+"g\n"+
    "\n");
  tell_room(environment(this_player()),
    ME+" says something to "+this_player()->query_name()+".\n",
    ({ this_player() }));
  return 1;
}

buy_checks(int x)
{
  if(!x) return 0;
  if(this_player()->query_money() < eqcs[x])
  {
    tell_room(environment(),
      ME+" says, \"You can't afford it.\"\n");
    return 0;
  }
  if(x > 0 && x < 7)
    merch = clone_object(DIR+"eq/blood_amulet.c");
  else if(x == 7)
    merch = clone_object(DIR+"eq/combat_boots.c");
  else if(x == 8)
    merch = clone_object(DIR+"eq/bloodfist_ring.c");
  else
    return 0;
  if(!this_player()->add_weight(merch->query_weight()))
  {
    tell_room(environment(),
     ME+" says, \"You can't carry it.\"\n");
    return 0;
  }
  this_player()->add_money(-eqcs[x]);
  move_object(merch, this_player());
  return 1;
}

status buy(string str)
{
  if(str == "1" || str == "amulet of agility")
  {
    if(!buy_checks(1)) return 1;
    merch->set_bf_type("agl");
  }
  else if(str == "2" || str == "amulet of might")
  {
    if(!buy_checks(2)) return 1;
    merch->set_bf_type("mit");
  }
  else if(str == "3" || str == "amulet of accuracy")
  {
    if(!buy_checks(3)) return 1;
    merch->set_bf_type("acc");
  }
  else if(str == "4" || str == "amulet of vigor")
  {
    if(!buy_checks(4)) return 1;
    merch->set_bf_type("vig");
  }
  else if(str == "5" || str == "amulet of wisdom")
  {
    if(!buy_checks(5)) return 1;
    merch->set_bf_type("wis");
  }
  else if(str == "6" || str == "amulet of faith")
  {
    if(!buy_checks(6)) return 1;
    merch->set_bf_type("fai");
  }
  else if(str == "7" || str == "combat boots" || str == "boots")
  {
    if(!buy_checks(7)) return 1;
  }
  else if(str == "8" || str == "bloodfist ring" || str == "ring")
  {
    if(!buy_checks(8)) return 1;
  }
  else
    return (notify_fail(ME+" asks, \"What do you want to buy?\n"),0);
  tell_object(this_player(), ME+" hands you a piece of equipment.\n");
  tell_room(environment(this_player()),
    ME+" hands something to "+this_player()->query_name()+".\n",
    ({ this_player() }));
  return 1;
}

status sell(string str)
{
  int price;
  object ob;
  gob = present("bloodfist_gob", this_player());
  if(!gob)
  {
    tell_room(environment(this_player()), 
      ME+" says, \"Why are you here?  You are no Bloodfist.\"\n");
    return 1;
  }
  if(!str)
  {
    tell_object(this_player(), 
      ME+" says, \"What would you like to sell to me?\"\n");
    return 1;
  }
  ob = present(str, this_player());
  
  if(!ob)
      ob = present(str, this_object());
  if(!ob)
  {
    tell_object(this_player(), 
      ME+" says, \"It doesn't look like you have a "+str+" to sell.\"\n");
    return 1;
  }
  price = 500+random(500); 
  if(!ob->query_forged())
  {
    tell_object(this_player(), 
      ME+" says, \"This isn't one of my weapons I couldn't possibly take it back.\"\n");
    return 1;
  }
  if(ob->query_wielded())
  {
    tell_object(this_player(), 
      ME+" says, \"You'll have to unwield it first.\"\n");
    return 1;
  }
  price = 500+random(500);
  if(ob->query_socketed())
    price = 2000+random(500);
  tell_room(environment(),
   ME+" looks at the "+ob->short()+" and grins.\n");
  tell_object(this_player(),
    ME+" takes the "+ob->short()+" from you and hands you "+price+" coins.\n");
  tell_room(environment(),
   ME+" takes the "+ob->short()+" from "+this_player()->query_name()+" and hands "+this_player()->query_objective()+" "+price+" coins.\n",  ({ this_player() }));
  this_player()->add_money(price);
  destruct(ob);
  return 1;
}    

void catch_tell(string str)
{
  string t1, t2, t3;
  object me;
  if(sscanf(str, "%sbows%syou.", t1, t2) == 2)
  {
    me = this_player();
    if(me->is_player() && !me->query_attack())
      call_out("bow_back", 1, me);
  }
  else if(sscanf(str, "%s arrives.%s\n", t1, t2) == 2)
  {
    if(!random(5))
      call_out("arrives", 2, find_player(lower_case(t1)));
  }
}

heart_beat()
{
  ::heart_beat();
  if(!environment()) 
    return;
  if(!attacker_ob)
    return;
  if(hit_point < 1500 && !random(5))
    drink_water();
  if(alt_attacker_ob && attacker_ob != alt_attacker_ob && !random(3))
  {
    tell_room(environment(), "\n"+
      ME+" slashes "+alt_attacker_ob->query_name()+" with his "+
      "longknife!\n\n");
    alt_attacker_ob->hit_player(40);
  }
}

/*
Forging costs:
 * standard weapon:		3000
 * standard weapon + socket:	6000
 * gem purchase cost:		10000

*/

