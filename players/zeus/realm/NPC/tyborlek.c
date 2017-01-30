/*  Features:   buys horns, sets titles for killing demons */
/*				Gives info on the area */
/*              Lots of quest related shit */

inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
#define PATH "players/zeus/realm/doc/demon_kills/"
static object mee;
static string *titles;
static int *cost, dkills, kills, time;

reset(arg) {
   ::reset(arg);
   if (!arg) {

  object robe, staff, gold;

  robe = CO("/players/zeus/realm/OBJ/blackrobe.c");
  MO(robe, TO);
   init_command("wear robe");
  staff = CO("/players/zeus/realm/OBJ/wstaff.c");
  MO(staff, TO);
   init_command("wield staff");
  gold = CO("/obj/money.c");
   gold->set_money(random(777));
  MO(gold, TO);

  titles =({  "the Demon Hunter",
              "the Demon Slayer",
              "the Destroyer of Demons",
              "the Warrior of the Fallen Lands",
              "the Legendary Warrior of the Fallen Lands",  });

  cost =({ 15,30,60,90,120 });  /* title cost in kills */

  set_name("tyborlek");
  set_alias("monk");
  set_short("A monk");
  set_long(
"This man is wearing a large black robe which conceals his entire\n"+
"figure.  He is a skinny man, and only about 5 feet tall.  The hood\n"+
"of the robe casts a shadow across his face, hiding his expression.\n"+
"He gives an appearance of great wisdom, and has a strange magical\n"+
"aura around him, which makes his body radiate softly.  You might be\n"+
"able to 'sell' him something, if he wants it, or ask him to tell you\n"+
"the story of the Fallen Lands.\n");
  set_race("human");
  set_level(19);
  set_ac(20+random(3));
  set_wc(30+random(10));
  set_hp(1400);
  set_al(0);
  set_heal(10,1);
  set_aggressive(0);
  set_gender("male");
  set_chat_chance(6);
  set_a_chat_chance(4);
  load_chat("Tyborlek says: Bring me the horns of the gurthers...\n");
  load_chat("Tyborlek says: Kill every gurther you see, and bring me their horns.\n");
  load_chat("Tyborlek says: Watch out for the demons.\n");
  load_chat("Tyborlek says: I remember the story of how it happened.\n");
  load_chat("Tyborlek says: You can ask me to tell you the story...\n");
  load_chat("Tyborlek asks: What do you wish to know fare traveler?\n");
  load_chat("Tyborlek says: Once this was a thriving city...\n");
  load_chat("Tyborlek asks: Would you like to hear the story?\n");
  load_chat("Tyborlek says: I only wish something could be done...\n");
  load_chat("Tyborlek frowns in thought.\n");
  load_a_chat("Tyborlek says: Death is only a passing, I shall return...\n");
  load_a_chat("Tyborlek says: My knowledge shall not die with me...\n");
}   }


void init(){
  ::init();
  add_action("bow_cmd", "bow");
  add_action("sell_cmd", "sell");
  add_action("add_kills", "zadd");
}

add_kills(int x)
{
  if(!x) x = 1;
  if(this_player()->query_real_name() != "zeus") return 0;
  DD->add_kills2(this_player(), x);
  write(HIR+"You just killed "+x+" demons.\n"+NORM);
  return 1;
}

status sell_cmd(string str)
{
  int num;
  object ob;
  string str1,str2,str3;

  if(!str)
  {
    write("Tyborlek asks: What?\n");  
    return 1; 
  }
  if(str == "horn")            /*  gurther horn  */
  {
    ob = present("horn",TP);
    if(!ob)
    {
      write("Tyborlek says: You don't have a horn...\n");
      return 1; 
    }
    str1 = file_name(ob);
    sscanf(str1,"%s#%s",str2,str3);
    if(str2 != "players/zeus/realm/OBJ/ghorn")
    {
      write("Tyborlek says: You don't have a horn...\n");
      return 1; 
    }
    num = (int)ob->query_value();
    TR(environment(), "Tyborlek buys a gurther horn from "+
      capitalize((string)TP->QRN)+".\n", ({ TP }));
    write(
"Tyborlek grins at you as he takes the horn from your hands.  He reaches\n"+
"into a small pouch, pulls out "+num+" coins, and hands them to you.\n");
    TP->add_money(num);
    destruct(ob);
  }
  else
    write("Tyborlek shakes his head at you.\n");
  return 1; 
}


bow_cmd (string str)
{
  if(id(str))
  {
    mee = TP;
    call_out("bow_cmd2", 1);
    return 0; 
  } 
  return 0; 
}

void bow_cmd2()
{
  TR(environment(), "Tyborlek bows to "+mee->QN+".\n", ({ mee }));
  tell_object(mee, "Tyborlek bows to you.\n");
}


status title_info(object x)
{
  if(!x) return 0;
  tell_object(x,  "\nTyborlek tells you:\n"+
    "  When you slay demons, you are worthy of a title.\n");
  dkills = (int)DD->query_kills(x);
  if(0 == dkills)
    tell_object(x, "  You have not slain any demons.\n\n");
  else if(1 == dkills)
    tell_object(x, "  You have slain 1 demon.\n\n");
  else if(dkills > 1)
    tell_object(x, "  You have slain "+dkills+" demons.\n\n");
  TR(environment(), "Tyborlek says something to "+x->QN+".\n", ({x}));
  return 1;
}


status title_info_2(object x)
{
  int z, bah;
  if(!x) return 0;
  tell_object(x, "\n  The following titles are available to you:\n\n");
  for(z = 0; z < sizeof(cost); z++)
  {
    bah = z+1;
    if(dkills >= cost[z])
      tell_object(x, "\t"+bah+", for "+cost[z]+" kills:  "+titles[z]+"\n");
  }
  tell_object(x,
    "\n  If you would like a title, enter the number and color.  You\n"+
    "  may have the title in white, red or black.  Eg:  '1 red'\n"+
    "  Otherwise just hit return.\n\n> ");
}

title_set(string str)
{
  string color, title, e,f;
  int choice;
  if(!str) return 0;
  if(!sscanf(str, "%d %s", choice, color))
    tell_room(environment(), "Tyborlek nods solemnly.\n");
  else if(sscanf(str, "%d %s", choice, color) == 2)
  {
    if(!sscanf(color, "%sw%s", e, f) &&
      sscanf(color, "%sr%s", e, f) &&
      sscanf(color, "%sb%s", e, f))
    {
      tell_room(environment(), "Tyborlek hmms thoughtfully.\n");
      return;
    }
    if(choice == 1 && dkills >= cost[0])
    {
      title = titles[0];
      DD->sub15(this_player()); 
    }
    else if(2 == choice && dkills >= cost[1])
    {
      title = titles[1];
      DD->sub15(this_player());
      DD->sub15(this_player());
    }
    else if(3 == choice && dkills >= cost[2])
    {
      title = titles[2];
      DD->sub45(this_player());
      DD->sub15(this_player());
    }
    else if(4 == choice && dkills >= cost[3])
    {
      title = titles[3];
      DD->sub45(this_player());
      DD->sub45(this_player());
    }
    else if(5 == choice && dkills >= cost[4])
    {
      title = titles[4];
      DD->sub45(this_player());
      DD->sub45(this_player());
      DD->sub15(this_player());
      DD->sub15(this_player());
    }
    else
    {
      tell_room(environment(), "Tyborlek hmms thoughtfully.\n");
      return;
    }
    if(sscanf(color, "%sw%s", e, f))
      this_player()->set_title(WHT+title+NORM);
    else if(sscanf(color, "%sr%s", e, f))
      this_player()->set_title(RED+title+NORM);
    else if(sscanf(color, "%sb%s", e, f))
      this_player()->set_title(BOLD+BLK+title+NORM);
    else
    {
      tell_room(environment(), "Tyborlek hmms thoughtfully.\n");
      return;
    }
    write_file("/players/zeus/log/titles", ctime(time())+" -  "+
      capitalize((string)this_player()->query_real_name())+
      " had "+dkills+" kills and got title "+choice+" in "+color+".\n");
    this_player()->save();
    tell_object(this_player(), "\nTyborlek tells you:\n  "+
      "You are now "+capitalize((string)TP->QRN)+" "+TP->query_title()+".\n"+
      "  You have "+(int)DD->query_kills(this_player())+
      " kills remaining.\n\n");
  }
  else
    tell_object(this_player(), "\nTyborlek nods solemnly.\n");
  return;
}


tc(object x)
{
  object laf, pdr, tal, *uinv;
  int y,z;
  z = 0;
  if(!x) return 0;
  laf = present("zeus_talisman_piece", x);
  tal = present("zeus_quest_talisman", x);
  pdr = present("zeus_red_powder", x);
  if(laf)
  {
    uinv = all_inventory(x);
    for(y=0; y < sizeof(uinv); y++)
    {
      if((string)uinv[y]->id("zeus_talisman_piece")) z++;
    }
  }
  if(z >= 3){
    tell_object(x,
      "\nTyborlek tells you:  Great job "+x->QN+", give the pieces to me.\n\n");
    TR(environment(), "Tyborlek says something to "+x->QN+".\n", ({x}));
  }
  else if(z == 2 || z == 1)
  {
    tell_object(x,
      "\nTyborlek tells you:  "+
      "You must get me all three pieces of the talisman.\n\n");
  }
  if(pdr && tal)
  {
    if(tal->query_go()) return;
    tell_object(x,
      "\nTyborlek tells you:  Give me the red powder and the talisman.\n\n");
    TR(environment(), "Tyborlek says something to "+x->QN+".\n", ({x}));
  }
}

amount_query(x){
  int a;
  if(!x) return;
  a = (int)DD->query_kills(x);
  if(a)
  {
    if(a == 1)
    {
      tell_room(environment(), "Tyborlek says:  "+x->query_name()+","+
        " you have 1 kill.\n");
    }
    else
    {
      tell_room(environment(), "Tyborlek says:  "+x->query_name()+","+
        " you have "+a+" kills.\n");
    }
  }
  else
  {
    tell_room(environment(), "Tyborlek says:  "+x->query_name()+","+
      " you have no kills.\n");
  }
}


tell_story(object x)
{
  if(!x) return;
  tell_object(x,
"\nTyborlek tells you:\n"+
"  Long ago the Fallen Lands were cursed by the wizard Auseth.  His curse\n"+
"  drove all the Humans away, and allowed the Gurthers to steal our land.\n"+
"  You must be careful when venturing in the Fallen Lands.  Beware of the\n"+
"  demons that sense when you're weak and know when to strike.  You may\n"+
"  ask for more info on the demons, or offer to help save these lands.\n\n");
TR(environment(), "Tyborlek says something to "+x->QN+".\n", ({x}));
}

protect(object x)
{
  object g;
  if(!x) return;
  if(!environment() || !present(x, environment(this_object()))){
    tell_object(x,
      "Tyborlek tells you: You must be here for me to protect you.\n");
    return;
  }
  tell_room(environment(),
    "\nTyborlek closes his eyes and rubs his hands together...\n"+
    HIY+"His hands begin to glow softly...\n"+NORM);
  tell_room(environment(),
    "Tyborlek touches his hands to "+x->QN+"'s forehead.\n",  ({ x }));
  if(g = present("tyborlek enchantment", x)){
    tell_object(x,
      "Tyborlek places his hands to your forehead.\n\n"+
      "Tyborlek tells you: There, I have renewed the enchantment.\n");
    g->reset_timers();
  }
  else {
    g = clone_object("/players/zeus/realm/OBJ/tyb_ench.c");
    move_object(g, x);
    tell_object(x,
      "Tyborlek places his hands to your forehead.\n\n"+
      "Tyborlek tells you: There, I only wish that it could last longer.\n");
  }
}

demon_info(object x)
{
  if(!x) return;
  tell_object(x,
"\nTyborlek tells you:\n"+
"  When Auseth cast his curse upon these lands, demons came to aid him and\n"+
"  the Gurthers in their battle against the Humans.  Now that the battle\n"+
"  has ended, the demons exist only to hunt and kill the weak.  They are\n"+
"  a constant threat to us.  You must beware for they are able to sense\n"+
"  when you are weak and that is when they strike.  If you kill enough\n"+
"  demons, I will award you with a title, all you need do is ask.  If you\n"+
"  want, ask and I will protect you from"+
" the demon curse for a limited time.\n\n");
TR(environment(), "Tyborlek says something to "+x->QN+".\n", ({x}));
}

fallen_info(object x)
{
  if(!x) return;
  tell_object(x,
"\nTyborlek tells you:\n"+
"  Legends which have passed down through the generations speak of an\n"+
"  ancient circle in which the sum total of my ancestors knowledge was\n"+
"  inscribed.  I have heard that this circle of stone still exists\n"+
"  somewhere in the forest south of here, however I have yet to find it.\n"+
"\n");
TR(environment(), "Tyborlek says something to "+x->QN+".\n", ({x}));
}

mist_info(object x)
{
  if(!x) return;
  tell_object(x,
"\nTyborlek tells you:\n  I'm sorry, I know nothing of the mists.\n\n");
TR(environment(), "Tyborlek says something to "+x->QN+".\n", ({x}));
}

powder_talk(object x)
{
  if(!x) return;
  tell_object(x,
"\nTyborlek tells you:\n  I'm sorry, I do not know where the powder is.\n\n");
TR(environment(), "Tyborlek says something to "+x->QN+".\n", ({x}));
}

qi1(object x)
{
  if(!x) return;
  tell_object(x,
"\nTyborlek tells you:\n"+  
"  If you are serious, there may be something you can do.\n"+
"  When my ancestors arrived here so many centuries ago, they had a\n"+
"  talisman.  It was this talisman that Auseth used to cast the curse.\n"+
"  If it could be found, we could use it to try to banish the curse.\n"+
"  I believe I know where you could find the talisman as well.\n\n");
  TR(environment(), "Tyborlek says something to "+x->QN+".\n", ({x}));
}

qi2(object x)
{
  if(!x) return;
  tell_object(x,
"\nTyborlek tells you:\n"+
"  What I believe is that when the talisman was used, it was taken by\n"+
"  the demons and broken into three seperate pieces.  You should be\n"+
"  able to find each of these pieces somewhere in the demon plane.\n"+
"\n"+
"Tyborlek pauses...  then continues.\n\n"+
"  I don't know exactly how to get to the demon plane, but I believe\n"+
"  there would have to be some sort of portal or gateway near the\n"+
"  focal point of the curse, Auseth's tower.\n\n");
  TR(environment(), "Tyborlek says something to "+x->QN+".\n", ({x}));
}

qi3(object x)
{
  if(!x) return 0;
  tell_object(x,
"\nTyborlek tells you:\n"+
"  If you should find the talisman intact or in pieces, bring it to me.\n"+
"\n");
  TR(environment(), "Tyborlek says something to "+x->QN+".\n", ({x}));
}

pdam1()
{
  tell_room(environment(), "Tyborlek says:  Wonderful!\n");
}

pdam2()
{
  object pd;
  pd = present("zeus_red_powder", this_object());
  tell_room(environment(), 
    "Tyborlek opens the bag and pours the powder over the talisman.\n");
  destruct(pd);
}

pdam3()
{
    tell_room(environment(), 
      "Tyborlek rubs the talisman as he whispers softly.\n");
}

pdam4()
{
  tell_room(environment(), "Tyborlek grins at you...  it worked!\n");
}

pdam5(object x)
{
  object ta;
  if(!x) return 0;
  ta = present("zeus_quest_talisman", this_object());
  ta->set_go(1);
  tell_room(environment(), "\nTyborlek hands the talisman to "+x->QN+".\n",
    ({ x }));
  tell_object(x, 
"\nTyborlek hands the talisman to you.\n"+
"\n\nTyborlek tells you:\n"+
"  Now, what you need to do is take the talisman to the highest\n"+
"  point in the Fallen Lands, the place where Auseth originally\n"+
"  cast the curse so long ago, and 'banish' the 'curse'.\n"+
"  I can only pray that it will work.\n\n");
  TR(environment(), "Tyborlek says something to "+x->QN+".\n", ({x}));
  move_object(ta, x);
}

unite_talisman()
{
  tell_room(environment(),
    "\nTyborlek places the three pieces of the talisman together.\n"+
    "He clasps them in his hands as he whispers softly...\n"+
    "In a bright flash of light, the talisman magically unites.\n"+
    "The pieces form together to become the ancient talisman.\n");
}

next_step2(object x)
{
  if(!x) return 0;
  tell_object(x,
"\n\nTyborlek tells you:\n"+
"  It is just as I feared, the talisman has lost its strength.\n"+
"  There is only one thing I know to do now.  "+x->QN+", you must\n"+
"  go and seek out a mystical red powder.  My grandfather taught\n"+
"  me an ancient incantation which I might be able to use to empower\n"+
"  the talisman once again with the help of the red powder.  Go now,\n"+
"  and hurry.\n"+
"\n");
  TR(environment(), "Tyborlek says something to "+x->QN+".\n", ({x}));
}

give_talisman(object x)
{
  if(!x) return 0;
  tell_room(environment(),
    "\nTyborlek hands the talisman to "+x->QN+".\n", ({ x }));
  tell_object(x,
    "\nTyborlek hands the talisman to you.\n");
  move_object(present("talisman", this_object()), x);
}

void catch_tell(string str)
{
  string tmp1, tmp2, tmp3;
  object pd, ta, him, pc, *tinv, me2, *t;
  int c, cnt, q, r;
  him = 0; cnt = 0;
  if(!this_player()) return; /* added by verte 6.22.01 */
  if(sscanf(str, "%shelp%s\n", tmp1, tmp2) ||
    sscanf(str, "%ssave%s\n", tmp1, tmp2))
  {
    me = this_player();
    if(me->is_player() && !me->query_attack())
      call_out("qi1", 1, me);
  }
  if(sscanf(str, "%sprotect%s\n", tmp1, tmp2) ||
    sscanf(str, "%senchant%s\n", tmp1, tmp2))
  {
    me = this_player();
    if(me->is_player() && !me->query_attack())
      call_out("protect", 1, me);
  }
  if(sscanf(str, "%sstory%s\n", tmp1, tmp2))
  {
    me = this_player();
    if(me->is_player() && !me->query_attack())
      call_out("tell_story", 1, me);
  }
  if(sscanf(str, "%stitle%s\n", tmp1, tmp2, tmp3))
  {
    me = this_player();
    dkills = (int)DD->query_kills(me);
    call_out("title_info", 1, me);
    if(dkills >= 15)
    {
      call_out("title_info_2", 2, me);
      input_to("title_set");
    }
  }
  if(sscanf(str, "%show many%s\n", tmp1, tmp2))
  {
    if(this_player()->query_attack()) return;
    me = this_player();
    call_out("amount_query", 1, me);
  }
  if(sscanf(str, "%sdemon steps%s\n", tmp1, tmp2))
  {}
  else if(sscanf(str, "%sdemon%s\n", tmp1, tmp2))
  {
    me = this_player();
    if(me->is_player() && !me->query_attack())
      call_out("demon_info", 1, me);
  }
  if(sscanf(str, "%smist%s\n", tmp1, tmp2))
  {
    me = this_player();
    if(me->is_player() && !me->query_attack() && !me->query_ghost())
      call_out("mist_info", 1, me);
  }
  if(sscanf(str, "%sfallen%s\n", tmp1, tmp2) ||
    sscanf(str, "%sguild%s\n", tmp1, tmp2))
  {
    me = this_player();
    if(me->is_player() && !me->query_attack())
      call_out("fallen_info", 1, me);
  }
  if(sscanf(str, "%swhere is the powder%s\n", tmp1, tmp2))
  {
    me = this_player();
    if(me->is_player() && !me->query_attack())
    {
      call_out("powder_talk", 1, me);
    }
  }
  else if(sscanf(str, "%swhere is the red powder%s\n", tmp1, tmp2))
  {
    me = this_player();
    if(me->is_player() && !me->query_attack())
    {
      call_out("powder_talk", 1, me);
    }
  }
  else if(sscanf(str, "%swhere%s\n", tmp1, tmp2))
  {
    me = this_player();
    if(me->is_player() && !me->query_attack())
    {
      call_out("qi2", 1, me);
      call_out("qi3", 10, me);
    }
  }
  if(sscanf(str, "%s arrives.%s\n", tmp1, tmp2))
  {
    call_out("tc", 1, find_player(lower_case(tmp1)));
  }
  if(sscanf(str, "%s gives %s to Tyborlek%s\n", tmp1, tmp2, tmp3))
  {
    pd = present("zeus_red_powder", this_object());
    ta = present("zeus_quest_talisman", this_object());
    pc = present("zeus_talisman_piece", this_object());
    if(pc)
    {
      tinv = all_inventory(this_object());
      for(c = 0; c < sizeof(tinv); c++)
      {
      if((string)tinv[c]->id("zeus_talisman_piece"))
          cnt++;
      }
      if(cnt >= 3)
      {
        if(find_player(lower_case(tmp1)))
          me2 = find_player(lower_case(tmp1));
        if(!me2)
        {
          t = all_inventory(environment());
          q = sizeof(t);
          for(r=0; r<q, !me2; r++)
          {
            if(t[r]->is_player() && t[r]->query_invis())
            {
              me2 = t[r];
            }
          }
        }
        if(!me2)
        {
          t = all_inventory(environment());
          q = sizeof(t);
          for(r=0; r<q, !me2; r++)
          {
            if(t[r]->is_player())
            {
              me2 = t[r];
            }
          }
        }
        call_out("unite_talisman", 3);
        MO(CO("/players/zeus/realm/OBJ/talisman.c"), this_object());
        if(me2)
        {
          call_out("next_step2", 9, me2);
          call_out("give_talisman", 16, me2);
          write_file("/players/zeus/log/Q", ctime(time())+" -  "+
            capitalize((string)me2->QRN)+" united the talisman.\n");
        }
        else {
          tell_room(environment(),
          "Tyborlek looks around but does not see who gave him the pieces.\n"+
          "Tyborlek says:  God damn my eyes aren't what they used to be.\n"+
          "                Please contact Zeus, this is an error.\n");
        }
      }
    }
    
    if(pd && ta)
    {
      if(find_player(lower_case(tmp1)) && !him)
        him = find_player(lower_case(tmp1));
      if(!him)
      {
        t = all_inventory(environment());
        q = sizeof(t);
        for(r=0; r<q, !him; r++)
        {
          if(t[r]->is_player() && t[r]->query_invis())
          {
            him = t[r];
          }
        }
      }
      if(!him)
      {
        t = all_inventory(environment());
        q = sizeof(t);
        for(r=0; r<q, !him; r++)
        {
          if(t[r]->is_player())
          {
            him = t[r];
          }
        }
      }
      if(him)
      {
        call_out("pdam1", 2);
        call_out("pdam2", 5);
        call_out("pdam3", 7);
        call_out("pdam3", 9);
        call_out("pdam3", 11);
        call_out("pdam4", 13);
        call_out("pdam5", 15, him);
        write_file("/players/zeus/log/Q", ctime(time())+" -  "+
          capitalize((string)him->QRN)+" enchanted the talisman.\n");
      }
      else {
        tell_room(environment(),
        "Tyborlek looks around and gets a confused look on his face.\n"+
        "Tyborlek says:  God damn my eyes aren't what they used to be.\n"+
        "                Please contact Zeus, this is an error.\n");
      }
    }  /* end if pd and ta */
    else if(pd && !ta)
    {
      tell_room(environment(),
        "Tyborlek says:  Fantastic, now all I need is the talisman!\n");
    }
  }
  
}

heart_beat()
{
  ::heart_beat();
  if(!environment()) 
    return ;
  if(!AO) 
    return ;
  if(!random(6))
  {
    tell_object(AO,
    "\nTyborlek raises his staff into the air...\n"+
"A bright "+HIR+" F L A S H  of  F I R E "+NORM+" erupts around you...\n\n");
    TR(environment(TO), 
    "\nTyborlek raises his staff into the air...\n"+
"A "+HIR+" F L A S H  of  F I R E "+NORM+" erupts around "+AO->QN+".\n\n",
    ({ AO }));
    AO->hit_player(random(300), "other|fire");
    return ;
  }
  if(!random(6))
  {
    TR(environment(TO),
      "\nTyborlek raises his staff into the air...\n"+
      "A "+HIY+" glowing aura "+NORM+" encompases Tyborlek.\n\n");
    hit_point += 20+random(100);
    return ;
  }
}

