#include "/players/pathfinder/closed/esc.h"
#define BOLD ESC + "[1m"
#define NOSTYLE ESC + "[0m"
#define TP this_player()
#define ENVTP environment(this_player())
#define QRN query_real_name()
#define QN query_name()
#define TO this_object()
#define ENV environment
#define CAP capitalize
#define DOBOLD(x) BOLD + x + NOSTYLE
#define BNAME BOLD + CAP(TP->QRN) + NOSTYLE

id(str) 
{
  return str == "wiztool" ||
         str == "tatoo" ||
         str == "pathtool";
}

short() 
{
  return "An Anti-Swastika Tatoo";
}

long() 
{
  write("You are looking at an Anti-Swastika Tatoo.\n");
  write("It looks like it could hold some tremendous powers.\n");
  write("cmdlist for a list of powers\n");
  return 1;
}

get() 
{ 
  return 1; 
}
drop() 
{ 
  return 1; 
}


init() 
{
  if(this_player()->query_level() < 60) destruct(this_object());

  add_action("no_fight", "no");
  add_action("check_light", "ckl");
  add_action("power_get", "get!");
  add_action("power_drop", "drop!");
  add_action("goin", "goin");
  add_action("money", "money");
  add_action("bring_player", "bringem");
  add_action("dungeon_player", "dun");
  add_action("church_player", "chr");
  add_action("force", "for");
  add_action("fix_weight", "fixw");
  add_action("inv_who", "I");
  add_action("inv_room", "Irm");
  add_action("heal", "heal");
  add_action("hand", "hand");
  add_action("remote_dest", "rdest");
  add_action("check_creator", "fcreator");
  add_action("tell_someone", "tells");
  add_action("show_wizzes", "wizwho");
  add_action("do_exp_change", "chxp");
  add_action("fix_em", "fix_shadow");
  add_action("nuke_em", "nukeem");
  add_action("patch", "patch");
  add_action("steal_object", "steal");
  add_action("list_comm", "cmdlist");
  add_action("check_weap_armor", "weap");
  add_action("all_weap_armor", "aweap");
  add_action("log_all_stuff", "alog");
  add_action("log_all_stuff_per", "perlog");
}


no_fight() 
{
 object who;
 who = first_inventory(environment(this_player()));
   while (who) 
   {
     if(living(who)) 
     {
       if(who->query_attack()) 
       {
         who->stop_fight();
         who->stop_fight();
       }
     }
     who = next_inventory(who);
   }
  write("You say: STOP FIGHTING!\n");
  say(capitalize(QN) + " says: STOP FIGHTING!\n");
  return 1;
}

 
power_get(str) 
{
  object what, tp;
  
  tp = this_player();

  if(!str) return 0;
  what = present(str, environment(tp));
  if(!what) 
  {
    write ("No " + str + " here.\n");
    return 1;
  }
  write("You take: " + what->short() + ".\n");
  say(capitalize(tp->QN) + " takes a " + what->short() + ".\n");
  move_object(what, tp);
  return 1;
}


power_drop(str) 
{
  object what, tp;

  tp = this_player();  

  if(!str) 
  {
    return 0;
  }
  if(!present(str, tp)) 
  {
    write("Hey!  You don't have that!\n");
    return 1;
  }
  what = present(str, tp);
  transfer(what, environment(tp));
  write("You have dropped the " + what->query_short() + ".\n");
  say(capitalize(tp->QN) + " drops a " + what->query_short() + ".\n");
  return 1;
}
 
  
goin(str) 
{
  object who;
  who = find_player(str);
  if (!who) return 0;
  move_object(this_player(), who);
  return 1;
}   

  
money(int amt) 
{
  write("You are rich now!\n");
  this_player()->add_money(amt);
  return 1;
}
   
bring_player(str) 
{
  object who, where;

  if(!str) return 0;

  who = find_player(str);
  if(!who) who = find_living(str);
  if(!who) 
  {
    write (capitalize(str) + "is not online at this time.\n");
    return 1;
  }

  where = environment(who);

  tell_object(who,
    "Your mind suddenly goes blank, all you see is white.\n" +
    "You then materialize somewhere else.\n");
    
  move_object(who, environment(this_player()));

  tell_room(where, "You suddendly see " + capitalize(str) + " dissolve before" +
    " your eyes.\n");

  say(capitalize(str) + " materializes suddenly.\n");
  write (capitalize(str) + " answers your summons.\n");
  command("glance", who);
  return 1;
}

dungeon_player(str) 
{
  object who, there;
 
  if(!str) return 0;
  who = find_player(str);
  if(!who) who = find_living(str);
  if(!who) 
  {
    write (capitalize(str) + "is not online at this time.\n");
    return 1;
  }
  there = ENV(who);
  tell_object(who, "You have been imprisoned.\n");
  move_object(who, "room/prison");
  tell_room(there, capitalize(str) + " is taken away to the slammer.\n");
  write("You have imprisoned " + capitalize(str) + ".\n");
  return 1;
} 
 
church_player(str) 
{
  object who, there;
  
  if(!str) return 0;

  who = find_player(str);
  if(!who) who=find_living(str);
  if(!who) 
  {
    write (capitalize(str) + "is not online at this time.\n");
    return 1;
  }
  there = environment(who);
  tell_object(who, "You have been escorted to the church.\n");
  move_object(who, "room/church");
  tell_room(there, capitalize(str) + " is escorted to the church.\n");
  write("You had " + capitalize(str) + " escorted to the church.\n");
  command("glance", who);
  return 1;
}

force(str) 
{
  object player;
  string name, cmd;
  if (!str) return 0;
  if ((!sscanf (str, "%s %s", name, cmd)) == 2) return 0;
  player = find_living(name);
  if (!player) 
  { 
    write (capitalize(name) + "is not online. \n"); 
    return 1;
  }
  command(cmd, player);
  write("You forced " + capitalize(name) + " to " + cmd + ".\n");
  return 1;
}  

inv_who(str) 
{
  object who, obj, tmp;
  int x;
  string one, two, three;
  if(!find_living(str)) 
  {
    write("I could not find "+str+" in the MUD.\n");
    return 1;
  }
  who = find_living(str);
  obj = first_inventory(who);
  tmp = 0;
  while(obj) 
  {
    if(tmp != 0) 
    {
      write("\t\t***  DESTRUCTED  ***\n");
      destruct(tmp);
      tmp = 0;  
    }
    write(obj);
    write(" : ");
    x = 0;
    if(obj->short()) 
    { 
      write(obj->short()); 
      x = 1; 
    }
    if(obj->query_name() && x == 0) 
    { 
      write(obj->query_name()); 
      x = 1; 
    }
    if(obj->query_id() && x == 0) 
    { 
      write(obj->query_id()); 
      x = 1; 
    }
    if(x == 0) 
    { 
      write("* INVISIBLE *"); 
    }
    write("\n");
    if(sscanf(obj, "%s/closed/%s#%s", one, two, three) == 3 && two == "goof") 
    {
      tmp = obj;
    }
    obj = next_inventory(obj);
  }
  write("Done.\n");
  return 1;
}

check_light()
{
  if(set_light(0) == 0)
  {
    write("The Room Has light!\n");
    return 1;
  }
  else
  {
    write("The Room is dark.\n");
    return 1;
  }
}
inv_room() 
{
  object who, obj, tmp;
  int x;  
  string one, two, three;
  obj = first_inventory(environment(this_player()));
  tmp = 0;
  while(obj) 
  {
    if(tmp != 0) 
    {
      write("\t\t***  DESTRUCTED  ***\n");
      destruct(tmp);
      tmp = 0;
    }   
    write(obj);
    write(" : ");
    x = 0;
    if(obj->short()) 
    { 
      write(obj->short()); 
      x = 1; 
    }
    if(obj->query_name() && x == 0) 
    { 
      write(obj->query_name()); 
      x = 1; 
    }
    if(obj->query_id() && x == 0) 
    { 
      write(obj->query_id()); 
      x = 1; 
    }
    if(x == 0) 
    { 
      write("* INVISIBLE *"); 
    }
    write("\n");
    if(sscanf(obj, "%s/closed/%s#%s", one, two, three) == 3 && two == "goof") 
    {
      tmp = obj;
    }
    obj = next_inventory(obj);
  }
  write("Done.\n");
  return 1; 
}

heal(str) 
{
  object who;
  string person;
  int amt;
    
  if(!str) 
  {
    this_player()->heal_self(1000);
    write("You feel more invigorated now!\n");
    return 1;
  }
  if(!sscanf(str,"%s %d", person, amt) == 2) return 0;
  who = find_player(person);
  if(!who) return 0;
  who->heal_self(amt);
  tell_object(who, "You feel more invigorated now!\n");
  write("You have healed " + capitalize(person) + ".\n");
  return 1;
}
      
hand(str) 
{
  object who, item;
  string what, player;
  if(!sscanf(str,"%s %s", player, what) == 2) 
  {
    write("Usage: hand <player> <item>\n");
    return 1;
  }
  who = find_player(player);
  if(!who) { 
    write("`" + capitalize(player) + "' is not on!\n");
    return 1;
  } 
  item = clone_object(what);
  if(!item) 
  {
    write("What do you want to hand?\n");
    return 1;
  }
  transfer(item, who);
  write("Ok, you gave a " + item->short() + " to " + capitalize(player) + ".\n");
  return 1;
}

remote_dest(str) 
{
  object who, what;
  string player, item;
  int weight;

  if(!str) return 0;
  if(!sscanf(str,"%s %s", player, item) == 2) return 0;
  
  who = find_player(player);
  if(!who) 
  { 
    write("I could not find " + capitalize(player) + " anywhere!\n");
    return 1;
  }
  what = present(item, who);
  if(!what) 
  {
    write(capitalize(player) + " doesn't have a " + item + ".\n");
    return 1;
  }
    
  move_object(what, "/room/prison"); /* move the object to the prison */
  weight = what->query_weight(); /* find the weight */
  who->add_weight((-1 * weight)); /* fix the players weight */
  destruct(what); /* destruct the object in question */
  write("Ok, you dested " + capitalize(player) + "'s " + item + ".\n");
  return 1;
} 

check_creator(str) 
{
  object who, what;   
  string per, item, create;

  if(!str) return;  
  
  if(!sscanf(str, "%s %s", per, item) == 2) return;
  
  who = find_player(per);
  if(!who) who = find_living(per);
  if(!who) return;
   
  what = present(item, who);
  if(!what) return;
    
  if(creator(what)) 
  {
    create = capitalize(creator(what));
  } 

  write("The Creator of " + capitalize(per) + "'s " + what->short() + " is: " +
        create + ".\n");
  return 1;
}
  
  
tell_someone(str) 
{
  object who;
  string per, mesg; 
  
  if(!str) return;
  if(!sscanf(str, "%s %s", per, mesg) == 2) return;

  who = find_player(per);
  if(!who) 
  {
    write(capitalize(per) + " is not online.\n");
    return 1;
  }
  
  tell_object(who, capitalize(this_player()->QRN) + " tells you: " +mesg + "\n");
  write("You told " + capitalize(per) + ": " + mesg + "\n");
  return 1;
}   
  

show_wizzes() 
{
  object list;
  int i, level, invis, size;
  string name, ed, tab;
  list = users();
  
write("\n");
write("Name\t\tLevel\tInvis\tEdit.\n");

write("=====================================================================\n");

  size = sizeof(list);
 
  for(i = 0; i < size; i++) 
  {
    name = capitalize(list[i]->query_real_name());
    level = list[i]->query_level();
    invis = list[i]->query_invis();
    if(invis > 999) invis = 999; 
 
    ed="";
    if(in_editor(list[i])) ed = "Ed";
 
   tab = "\t";
   if(strlen(name) < 8) tab = "\t\t";
 
   if(level > 19)
     write(name + tab + level + "\t" + invis + "\t" + ed + "\n");
 }
 return 1;
}

do_exp_change(str) 
{
  object who;
  string per;
  int amt;

  if(!str) 
  { 
    write("Usage: chxp <who> <amt>\n");
    return 1;
  }

  if(!sscanf(str, "%s %d", per, amt) == 2) 
  {
    write("Usage: chxp <who> <amt>\n");
    return 1;
  }
  who = find_player(per);
  who->add_exp(amt);
  write("You have given " + capitalize(per) + " " + amt + " experience for a \n");
  write("total of " + who->query_exp() + ".\n");
  return 1;
}
 
check_for_illegals(str)
{
  object all, who, obj;
  int i, j;
  string what1, what2;
  all = users();
  
  write("\nPeople and paths of items from a certain dir: \n");
  for(i = 0; i < sizeof(all); i++) {
    obj = first_inventory(all[i]);
    while(obj) {
      if(str == "open") {
        if(sscanf(obj, "/open/%s", what1)) {
          write(capitalize(all[i]->QRN) + " has " + obj + " : " + obj->short() + ".\n");
        }
      else
        if(sscanf(obj, "%s/"+str+"/%s", what1, what2)) {
          write(capitalize(all[i]->QRN) + " has " + obj + " : " + obj->short() + ".\n");
        }
      }
      obj = next_inventory(all[i]);  
    }
  }
}        
 
fix_weight(str)
{
  object who;

  if (!str)
  {
    write ("Usage: fixw <who>\n");
    return 1;
  }
  who = find_player(str);
  if (!who)
  {
    write ("Usage: fixw <who>\n");
    return 1;
  }

  who->recalc_carry();

  write (capitalize (str) + " has been fixed.\n");
  tell_object (who, "You have been fixed.\n");
  return 1;
}


fix_em() 
{
  object people, mark;
  int i, size;
  int lev, newlev, tprnk;
  int gxp, newgxp, tpgxp;

  people = users();
  size = sizeof(people);

  for(i = 0; i < size; i++) 
  {
    mark = present("shadow-mark", people[i]);
    if(mark) 
    {
      if(mark->query_shlev()) 
      {
        lev = mark->query_shlev();
        gxp = mark->query_shxp();
        tprnk = people[i]->query_guild_rank();
        tpgxp = people[i]->query_guild_exp();
        people[i]->add_guild_rank(-tprnk);
        people[i]->add_guild_exp(-tpgxp);
        people[i]->add_guild_rank(lev);
        people[i]->add_guild_exp(gxp);
        write(capitalize(people[i]->query_name()) + " fixed.\n");
      } 
      else 
      {
        write(capitalize(people[i]->query_name()) + " not fixed.\n");
      }
    }
  }
  write("Fixing Complete.\n");
  return 1;
}


nuke_em(str) 
{
  object who;
  who = find_living(str);
  if(!who) 
  {
    write("Could not find " + capitalize(str) + " anywhere!\n");
    return 1;
  }
  if(who->query_level() >= this_player()->query_level()) 
  {
    write("I would think twice about doing that!\n");
    return 1;
  }
  tell_object(who, "You hear a small explosion, then are hurled far away.\n");
  destruct(who);
  write("Ok, you nuked " + capitalize(str) + ".\n");
  return 1;
}

/*
 
patch_someone(str) 
{
  object who;
  string per, what;
  string other;
  
  if(!str) 
  {   
    write("Usage: patch <who> <func> <amt>\n");
    return 1;
  }
 
  if(!sscanf(str, "%s %s %s", per, what, other) == 3) 
  {
    write("Wrong Syntax!\n");
    return 1;
  }  
 
  who = find_living(per);
 
  if(!who) 
  { 
    write("I could not find " + capitalize(per) + " anywhere.\n");
    return 1;
  }
 
  call_other(who, what, other);
 
  write("Patch Successful.\n");
  write("Results:\n");
  write("---------------------\n");
  write("Who:\t" + capitalize(per) + "\n");
  write("What:\t" + what + "\n");
  write("Other:\t" + other + "\n");
  write("---------------------\n");
  return 1;

}

patch_someone2(str) 
{
  object who;
  string per, what, other2;
  int other;

  if(!str) 
  {
    write("Usage: patch <who> <func> <amt>\n");
    return 1;
  }

  if(!sscanf(str, "%s %s %d", per, what, other) == 3)
  {
    write("Usage: patch <who> <func> <amt>\n");
    return 1;
  }

  who = find_living(per);


  if(!who) 
  {
    write("I could not find " + capitalize(per) + " anywhere.\n");
    return 1;
  }

  call_other(who, what, other);

  write("Patch Successful.\n");
  write("Results:\n");
  write("---------------------\n");
  write("Who:\t" + capitalize(per) + "\n");
  write("What:\t" + what + "\n");
  write("Other:\t" + other + "\n");
  write("---------------------\n");
  return 1;
}

*/

steal_object(str)
{
  object who, what;
  string per, item;
  
  if(!str) return;
  
  if(!sscanf(str, "%s %s", per, item) == 2)
  {
    write("Usage: steal <who> <what>\n");
    return 1;
  }
  
  who = find_player(per);
  if(!who)
  {
    who = find_living(per);
  }
  if(!who)
  {
    write(capitalize(per) + " is not around.\n");
    return 1;
  }
  
  what = present(item, who);
  if(!what)
  {
    write(capitalize(per) + " does not have a " + item + ".\n");
    return 1;
  }
  
  tell_object(who, "A shadowy figure appears from the darkness.\n");
  tell_object(who, "It approaches you and takes your " + what->short() + "\n");
  tell_object(who, "Then returns to the darkness.\n");
  
  write("You command a shadow to go to " + capitalize(who->QRN) + "\n");
  write("and steal their " + what->query_short() + ".\n");
  write("The shadow appears from the darkness and hands you their " + 
        what->short() + ".\n");
  move_object(what, this_player());
  who->add_weight((-1 * what->query_weight()));
  return 1;
}

list_comm()
{
  write("\nList of Commands--\n");
  write("no                     - stop fighting in a room\n");
  write("ckl                    - check light in a room\n");
  write("get! <what>            - power get\n");
  write("drop! <what>           - power drop\n");
  write("goin <who>             - go in a players inv\n");
  write("money <amt>            - give yourself $$$\n");
  write("bringem <who>          - bring a player to you\n");
  write("dun <who>              - dungeon a player\n");
  write("chr <who>              - put a player in the church\n");
  write("for <who> <what>       - force a player to do x\n");
  write("fixw <who>             - register a player\n");
  write("I <who>                - inventory a player\n");
  write("Irm                    - Inventory a room\n");
  write("heal [<who>] [<amt>]   - heal a player x\n");
  write("hand <who> <path>      - give a player something\n");
  write("rdest <who> <what>     - nuke a players what\n");
  write("fcreator <who> <what>  - find the creator of something\n");
  write("tells <who> <what>     - tell something to someone\n");
  write("wizwho                 - list of wizards online\n");
  write("chxp <who> <amt>       - change someones exp\n");
  write("fix_shadow             - fix shadows online\n");
  write("nukeem <who>           - nuke a player\n");
  write("patch <who> <what> <str> - patch string\n");
/*  write("patch2 <who> <what> <amt> - patch amt\n"); */
  write("steal <who> <what>     - steal what from who\n");
  write("weap <who>             - all weapons and armor on\n");
  write("aweap                  - display all weapons online\n");
  write("alog                   - log all weapons online\n");
  write("perlog                 - log all equip on a player\n");
  write("\n");
  return 1;
}

patch(str)
{
  string who, what, other;
  int wh;
  object ob, tp, envtp;
  
  tp = this_player();
  envtp = environment(tp);  

  if (!str)
    return 0;
  if (sscanf(str, "%s %s %d", who, what, other) == 3)
    wh = 1;
  else if (sscanf(str, "%s %s %s", who, what, other) != 3) 
  {
    if (sscanf(str, "%s %s", who, what) == 2)
      wh = 0;
    else
      return 0;
  }

  if (who == "here")
    ob = envtp;
  else
    ob = present(who, envtp);
    
  if (other == "me")
    other = tp;
    
  if (!ob)
    ob = find_living(who);
    
  if (!ob) 
  {
    write("No such object here.\n");
    return 1;
  }
  
  call_other(ob, what, other);
  write("Report on patch:\n");
  write("Who: "+who+"\n");        
  write("What: "+what+"\n");
  write("Other: "+other+"\n");
  write("Patch succesfull.\n");
  return 1;
}

check_weap_armor(str)
{
  object item, whom, tmp;
  string per, what;
  string one, two, three;
  int x;
  
  if(!str) return;
  
  whom = find_living(str);
  
  if(!whom) 
  {
    write(capitalize(str) + " is not on!\n");
    return 1;
  }  

  item = first_inventory(whom); /* first item */
  tmp = 0;
    
  while(item)
  {
    if((call_other(item, "weapon_class", 0)) ||  /* check if weapon */
       (call_other(item, "armor_class", 0)))     /* check if armor */
    {
      if(tmp != 0) 
      {
        write("\t\t***  DESTRUCTED  ***\n");
        destruct(tmp);
        tmp = 0;  
      }
      write(item);
      write(" : ");
      x = 0;
      if(item->short()) 
      { 
        write(item->short()); 
        x = 1; 
      }
      if(item->query_name() && x == 0) 
      { 
        write(item->query_name()); 
        x = 1; 
      }
      if(item->query_id() && x == 0) 
      { 
        write(item->query_id()); 
        x = 1; 
      }
      if(x == 0) 
      { 
        write("* INVISIBLE *"); 
      }
      write("\n");
      if(sscanf(item, "%s/closed/%s#%s", one, two, three) == 3 && two == "goof") 
      {
        tmp = item;
      }
    } 
    item = next_inventory(item); /* next item */
  }  
  write("Done checking " + capitalize(str) + ".\n");
  return 1;
}    

all_weap_armor()
{
  object ppl;
  int sizeppl, i;
  string name;
  
  ppl = users();
  sizeppl = sizeof(ppl);

  for(i = 0; i < sizeppl; i++)
  {
    name = ppl[i]->query_real_name();
    check_weap_armor(name);
  }
  
  write("Done Checking!\n"); 
  return 1;
}

log_all_stuff_per(str)
{
  object item, whom, tmp;
  string per, what;
  string one, two, three;
  int x;
  
  if(!str) return;
  
  whom = find_living(str);
  
  if(!whom) 
  {
    write(capitalize(str) + " is not on!\n");
    return 1;
  }  

  item = first_inventory(whom); /* first item */
  tmp = 0;
    
  while(item)
  {
    if(tmp != 0) 
    {
      write("\t\t***  DESTRUCTED  ***\n");
      destruct(tmp);
      tmp = 0;  
    }
    writel(file_name(item));
    writel(" : ");
    x = 0;
    if(item->short()) 
    { 
      writel(item->short()); 
      x = 1; 
    }
    if(item->query_name() && x == 0) 
    { 
      writel(item->query_name()); 
      x = 1; 
    }
    if(item->query_id() && x == 0) 
    { 
      writel(item->query_id()); 
      x = 1; 
    }
    if(x == 0) 
    { 
      writel("* INVISIBLE *"); 
    }
    writel("\n");
    if(sscanf(item, "%s/closed/%s#%s", one, two, three) == 3 && two == "goof") 
    {
      tmp = item;
    }
   
    item = next_inventory(item); /* next item */
  }
  
  writel("Done checking " + capitalize(str) + ".\n");
  return 1;
}    

log_all_stuff()
{
  object ppl;
  int sizeppl, i;
  string name;
  
  writel(ctime() + "\n");
  
  ppl = users();
  sizeppl = sizeof(ppl);

  for(i = 0; i < sizeppl; i++)
  {
    name = ppl[i]->query_real_name();
    log_all_stuff_per(name);
  }
  
  write("Done Checking!\n"); 
  return 1;
}

writel(what)
{
  write_file("/players/pathfinder/closed/all_check.log", what);
}
