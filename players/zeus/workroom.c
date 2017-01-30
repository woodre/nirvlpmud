inherit "room/room";
#include "/players/zeus/closed/all.h"
string *nms, *wiz, *full;
string mask_short, mask_long; /* wiz name */
object mask_room_short, mask_room_long, mask_short_player;

reset(arg){
  if(arg) return;

  nms = ({ });
  wiz = ({ });

/* 8-20-05 wiz name array (derived from /player directories)  /lpmud.log
omits:  zeus, wocket, bastion, bern, numberone, dakeyras, reflex, aquila
        deathmonger, sado, stark, galbasi, vital, humble, kazer, lexi
*/
full=({ "aingeal","airwoman","aislinn","anshar","arrina","asmithrune",
        "astaroth","azane","bagera","balowski","beck","beren",
        "blackadder","blue","boltar","bop","braxana","brittany",
        "caelin","cal","cassandra","catacomb","catt","catwoman",
        "cobain","coldwind","cosmo","cream","cyrex","daranath","data",
        "rich","rumplemintz","saber","dersharp","deus","dodger","dragnar",
        "dreamspeakr","dune","dusan","earwax","emerson","eurale","fakir",
        "feldegast","forbin","francesco","fred","gemini","gorgan","greg",
        "gowron","hagbard","hair","haji","hawkeye","heroin","hippo",
        "hogath","hurtbrain","illarion","ireland","jack","jamila","jara",
        "jaraxle","jareel","jaryn","jenny","kain","katya","kevlar",
        "khrell","kirkion","ladyfinger","laera","lan","languilen",
        "leatherneck","lew","linus","lishe","llew","maledicta","martha",
        "mathiast","mishtar","mistress","mizan","molasar","morgar",
        "morgoth","mosobp","mouzar","mythos","nightshade","nikki",
        "nooneelse","novowels","oderus","omega","pain","pathfinder",
        "paulasx","pavlik","persephone","pestilence","plasma","predator",
        "puppy","quantos","quicksilver","samhain","sampson","sandman",
        "scathe","shadowhawk","slava","snakespear","snow","softly",
        "sparkle","stardream","static","syn","tallos","traff","trent",
        "tristian","trix","grimm","ulath","ultramagnus","unsane",
        "vertebraker","virus","vulture","wamphyri","wizardchild",
        "wrathchild","wren","x","yaeger","zeotide","zone",
});

  set_light(1);
  short_desc = "default";
  long_desc = HIY+"cmd:"+NORM+
    " grab <on|array|wiz|room who|room on>, omit <who|all>, list\n"+
    HIY+"cmd:"+NORM+" mask <short wiz|long wiz|who>, full, cmds\n";
  dest_dir=({   "/room/vill_green.c", "green",    });
}

void init(){
  ::init();
  add_action("grab_short", "grab");
  add_action("print_list", "list");
  add_action("remove_cmd", "omit");
  add_action("mask_room", "mask");
  add_action("show_cmds", "cmds");
  add_action("print_full", "full");
}

print_full()
{
  int x, y, sofull;
  sofull = sizeof(full);
  write(HIG+"\nFull array:\nwho: "+NORM);
  for(x = 0, y = 0; x < sofull; x++, y++)
  {
    write(full[x]);
    if((x + 1) < sofull)
      write(", ");
    else
      write(" ");
    if(y == 6 && ((x+1) < sofull))
    {
      write(HIG+"\nwho: "+NORM);
      y = -1;
    }
  }
  write("\n");
  return 1;
}

show_cmds()
{
  write("\n");
  if(mask_short)
    write("Workroom short masked to \""+HIR+
      mask_short+NORM+"\" style.\n");
  else if(mask_short_player)
    write("Workroom short masked to \""+HIR+
      mask_short_player->query_real_name()+NORM+"\" style.\n");
  if(mask_long)
    write("Workroom long masked to \""+HIR+
      mask_long+NORM+"\" style.\n");
  print_nms();
  write(long_desc);
  return 1;
}

mask_room(string str)
{
  string a, b;
  object ob;
  if(!lvlchk(this_player()) || !str) return 0;
  if(str == "short")
  {
    mask_short = 0;
    mask_room_short = 0;
    mask_short_player = 0;
    write("Mask short reset.\n");
  }
  else if(str == "long")
  {
    mask_long = 0;
    mask_room_long = 0;
    write("Mask long reset.\n");
  }
  else if(sscanf(str, "short %s", a))
  {
    if(index(full, a) == -1)
      return(notify_fail("Wizard \""+HIR+a+NORM+
        "\" invalid: not in 'full' array.\n"), 0);
    b = "players/"+a+"/workroom";
    if(!catch(mask_room_short = clone_object(b)))
    {
      mask_short = a;
      mask_short_player = 0;
      write("Room short masked to \""+HIR+a+NORM+"\" style.\n");
    }
    else
      return(notify_fail("Room \""+HIR+a+NORM+
       "\" invalid: bad workroom.c file\n"), 0);
  }
  else if(sscanf(str, "long %s", a))
  {
    if(index(full, a) == -1)
      return(notify_fail("Wizard \""+HIR+a+NORM+
        "\" invalid: not in 'full' array.\n"), 0);
    b = "players/"+a+"/workroom";
    if(!catch(mask_room_long = clone_object(b)))
    {
      mask_long = a;
      write("Room long masked to \""+HIR+a+NORM+"\" style.\n");
    }
    else
      return(notify_fail("Room \""+HIR+a+NORM+
       "\" invalid: bad workroom.c file\n"), 0);
  }
  else if(find_player(str) && str != "zeus")
  {
    mask_short = 0;
    mask_short_player = find_player(str);
    write("Room short masked to \""+HIR+str+NORM+"\" style.\n");
  }
  else
    return(notify_fail("Input \""+HIR+str+NORM+
        "\" invalid: failed all possible cases.\n"), 0);
  return 1;
}

remove_cmd(string str)
{
  int x, sox;
  if(!lvlchk(this_player())) return 0;
  sox = sizeof(wiz);
  if(str == "all")
  {
    nms = ({ });
    wiz = ({ });
    write(sox+" wizards removed from array.\n");
    return 1;
  }
  if(!query_wiz(str))
    return(notify_fail("That wizard is not in the array.\n"), 0);
  while(wiz[x] != str && x < sox)
    x++;
  wiz -= ({ str });
  nms -= ({ nms[x] });
  write("Removed "+str+" from array.\n");
  return 1;
}

print_list(){
  int x, z, sonms;
  if(!lvlchk(this_player())) return 0;
  sonms = sizeof(nms);
  if(!sonms)
    return(notify_fail("Size of array is 0.\n"), 0);
  write(HIG+"nms: \n"+NORM);
  for(x = 0; x < sonms; x++)
  {
    if(x < 9)
      z = 14;
    else if(x < 99)
      z = 13;
    else
      z = 12;
    write(HIG+(x+1)+NORM+". "+pad(wiz[x],z)+nms[x]+"\n");
  }
  write("\n");
  return 1;
}

print_nms(){
  int x, y, sonms;
  if(!lvlchk(this_player())) return 0;
  sonms = sizeof(wiz);
  if(!sonms)
    return(notify_fail("Sizeof wiz is 0.\n"), 0);
  write(HIG+"who: "+NORM);
  for(x = 0, y = 0; x < sonms; x++, y++)
  {
    write(wiz[x]);
    if((x + 1) < sonms)
      write(", ");
    else
      write(" ");
    if(y == 6 && ((x+1) < sonms))
    {
      write(HIG+"\nwho: "+NORM);
      y = -1;
    }
  }
  write("\n");
  return 1;
}

short(){
  if(mask_short)
    return(mask_room_short->short());
  else if(mask_short_player)
  {
    if(environment(mask_short_player))
      return (environment(mask_short_player)->short());
    else mask_short_player = 0;
  }
  else if(sizeof(nms) > 0)
  {
    return nms[random(sizeof(nms))];
  }
  else
    return short_desc;
}

long(){
  if(mask_long)
    mask_room_long->long();
  else {
    write("\n");
    if(mask_short)
      write("Workroom short masked to \""+HIR+
        mask_short+NORM+"\" style.\n");
    else if(mask_short_player)
      write("Workroom short masked to \""+HIR+
        mask_short_player->query_real_name()+NORM+"\" style.\n");
    print_nms();
    ::long();
  }
}

lvlchk(object me){ if(me->query_level() < 21) return 0; return 1; }

query_wiz(string str){
  if(!wiz || !sizeof(wiz)) return 0;
  if(index(wiz, str) > -1) return str;
  return 0;
}

grab_short(string str){
  int x, z, sox, sof;
  object *u, ob;
  string a, b, ur_name;
  z = 0;
  u = users();
  sox = sizeof(u);
  if(!lvlchk(this_player())) return 0;
  if(str == "zeus")
  {
    z = 1;
    nms += ({ HIW+"Greater Antarctica"+NORM });
    wiz += ({ "zeus" });
  }
  else if(str == "array")
  {
    sof = sizeof(full);
    for(x = 0, z = 0; x < sof; x++)
    {
      a = "players/"+full[x]+"/workroom";
      if(!catch(ob = clone_object(a)) && !catch(ob->short()))
      {
        z++;
        nms += ({ ob->short() });
        wiz += ({ full[x] });
        destruct(ob);
      }
      else
        write_file("/players/zeus/log/player_notes", ctime(time())+" - "+
          HIY+full[x]+" invalid workroom.c\n"+NORM);
    }
  }
  else if(str == "on")
  {
    for(x = 0, z = 0; x < sox; x++)
    {
      ur_name = u[x]->query_real_name();
      if(u[x]->query_level() > 20 && !query_wiz(ur_name) && ur_name != "zeus")
      {
        a = "players/"+ur_name+"/workroom";
        if(!catch(ob = clone_object(a)) && !catch(ob->short()))
        {
          z++;
          nms += ({ ob->short() });
          wiz += ({ ur_name });
          destruct(ob);
        }
      }
    }
  }
  else if(sscanf(str, "room %s", b))
  {
    if(b == "on")
    {
      for(x = 0, z = 0; x < sox; x++)
      {
        ur_name = u[x]->query_real_name();
        if(!query_wiz(ur_name) && ur_name != "zeus")
        {
          if((ob = environment(u[x])))
          {
            a = ob->short();
            if(index(nms, a) == -1)
            {
              z++;
              nms += ({ a });
              wiz += ({ ur_name });
            }
          }
        }
      }
    }
    else
    {
      if(!(ob = find_player(b)) || !environment(ob))
        return(notify_fail("Player \""+HIR+b+NORM+"\" invalid.\n"), 0);
      nms += ({ (a = environment(ob)->short()) });
      wiz += ({ b });
      write("Added "+a+"\n");
      return 1;
    }
  }
  else
  {
    if(query_wiz(str))
      return(notify_fail("That wiz is already in the array.\n"), 0);
    else if(index(full, str) == -1)
      return(notify_fail("Wizard \""+HIR+str+NORM+
        "\" invalid: not in 'full' array.\n"), 0);
    a = "players/"+str+"/workroom";
    if(!catch(ob = clone_object(a)) && !catch(ob->short()))
    {
      b = ob->short();
      nms += ({ b });
      wiz += ({ str });
      write("Added: "+b+"\n");
      destruct(ob);
    }
    else
      write("Wizard \""+HIR+str+NORM+
        "\" invalid: bad workroom.c file\n");
  }
  if(z > 1 || z == 0)
    write(z+" new entries added to array.\n");
  else if(z == 1)
    write(z+" new entry added to array.\n");
  return 1;
}


