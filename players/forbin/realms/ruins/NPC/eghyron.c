#include "/players/forbin/realms/ruins/ruinsdefine.h"
#include "/players/forbin/logging.h"
#include "/players/forbin/closed/wiztool/cmds/date_time.h"
#pragma combine_strings
inherit "/players/vertebraker/closed/std/monster.c";

id(str) { return (::id(str) || str == "eghyron" || str == "hunter" || 
                               str == "man"); }

int Busy;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  move_object(clone_object(OBJ+"earmor.c"), this_object());
  move_object(clone_object(OBJ+"esword.c"), this_object());
  command("wear armor", this_object());
  command("wield sword", this_object());
  set_name("Eghyron the Hunter");
  set_alt_name("eghyron the hunter");
  set_race("human");
  set_gender("male");
  set_short("Eghyron the "+GRN+"Hunter"+NORM+" ["+GRN+"wounded"+NORM+"]");
  set_long(
    "  Standing before you is rugged looking man who looks as though he has\n"+
    "seen too much combat and killing in his long lifetime.  His armor is\n"+
    "in tatters, looking as though it was nearly ripped from his body by\n"+
    "huge claws.  His hair and dark beard are matted with blood, some his\n"+
    "own, some not.  He carries a huge two-handed sword, its once razor\n"+
    "sharp edge now dulled from use.  He looks at you expectantly, as\n"+
    "though waiting for you to say something.\n");
  set_level(5);
  set_hp(300);
  set_al(500);
  set_wc(16);
  set_ac(6);
  set_chat_chance(15);
    load_chat("Eghyron asks: \"Are you here to help?\"\n");
    load_chat("Eghyron says: \"Ask me what you will, I am too tired to do anything but\n"+
              "answer.\"\n");
    load_chat("Eghyron looks at you intently, as though measuring your ability.\n");
    load_chat("The hunter limps over to stand by the wall.\n");
    load_chat("Eghyron says: \"Just tell me your here to help, that is all I ask.\"\n");
  set_a_chat_chance(15);
    load_a_chat("Eghyron shouts, \"I should have known!!!\"\n");
    load_a_chat("The hunter swings his huge sword into a ready position.\n");
  add_spell("sword_attack",
  "Eghyron swings his massive sword, cutting deeply into your flesh!\n",
  "Eghyron swings his sword, cutting #CTN# deeply.\n",
  10, "15-20", "physical");
  Busy = 0;  
}

query_local_weight() { return 0; }

init() {
  ::init();
  if(hit_point > 150) hit_point = 50+random(50);
}

heart_beat() {
	local_weight = 0;
	if(Busy) chat_chance = 0;
	else chat_chance = 15;
	::heart_beat();
}

status collect_bounty(object who) 
{
  int num;
  string str1, str2, str3, str4, str5;
  object bountyob;

  if(!who || !present(who, environment())) 
  {
  	Busy = 0;
  	return 0;
  }
  
  bountyob = present("collectable_bounty_object", this_object());

  if(bountyob && bountyob->query_archangel_reward())
  {
    str1 = file_name(bountyob);
    sscanf(str1, "%s_%s", str2, str3);
    sscanf(str1, "%s#%s", str4, str5);    
    if(str2 != "players/forbin/realms/ruins/OBJ/ice" &&
       str2 != "players/forbin/realms/ruins/OBJ/flaming" &&
       str4 != "players/forbin/realms/ruins/OBJ/gloves" &&
       str4 != "players/forbin/realms/ruins/OBJ/swhip")
    {
      tell_object(who, 
        "\nEghyron says: \"That "+(string)bountyob->query_name()+
        " didn't come from one of the\n"+
        "archangels, "+capitalize((string)who->query_name())+
        ".  I cannot buy it.\"\n");
      tell_room(environment(),
        "Eghyron says something to "+
        capitalize((string)who->query_name())+".\n", ({ who}) );
      command("drop "+(string)bountyob->query_name(), this_object());
      this_object()->recalc_carry();
      Busy = 0;  
      return 1; 
    }
    num = (int)bountyob->query_value();
    if(str4 == "players/forbin/realms/ruins/OBJ/gloves")
    {
      tell_object(who,
        "\nEghyron takes the "+(string)bountyob->query_name()+
        " from you and examines it.\n\n"+
        "Eghyron says: \"Slaying the Archangel of Death is most impressive,\n"+
        capitalize((string)who->query_name())+
        ".  This will fetch a nice reward.\"\n");
      tell_object(who,
        "Eghyron gives you "+HIY+num+NORM+" coins.\n");      
      tell_room(environment(), "Eghyron gives "+
        capitalize((string)who->query_name())+
        " some coins.\n", ({ who }) );
    }
    else if(str4 == "players/forbin/realms/ruins/OBJ/swhip") 
    {
      tell_object(who,
        "\nEghyron takes the "+(string)bountyob->query_name()+
        " from you and examines it.\n\n"+
        "Eghyron says: \"Defeating the Archangel of Shadows is very remarkable,\n"+
        capitalize((string)who->query_name())+
        ".  This will fetch a nice reward.\"\n");
      tell_object(who,
        "Eghyron gives you "+HIY+num+NORM+" coins.\n");      
       tell_room(environment(), "Eghyron gives"+
        capitalize((string)who->query_name())+
        " some coins.\n", ({ who }) );
    }
    else 
    {
      tell_object(who,
        "\nEghyron takes the "+(string)bountyob->query_name()+
        " from you and examines it.\n\n"+
        "Eghyron says: \"Well done, "+
        capitalize((string)who->query_name())+
        ", this will fetch a nice reward.\"\n");
      tell_object(who,
        "Eghyron gives you "+HIY+num+NORM+" coins.\n");      
      tell_room(environment(), "Eghyron gives "+
        capitalize((string)who->query_name())+
        " some coins.\n", ({ who }) );
    }      
    who->add_money(num);
    move_object(bountyob, "/room/void");
    destruct(bountyob);
    this_object()->recalc_carry();
    Busy = 0;
    return 1;
  }
  else 
  {
    tell_object(who, 
        "\nEghyron says: \"That "+(string)bountyob->query_name()+
        " didn't come from one of the\n"+
        "archangels, "+capitalize((string)who->query_name())+
        ".  I cannot buy it.\"\n");
    tell_room(environment(),
      "Eghyron says something to "+
      capitalize((string)who->query_name())+".\n", ({ who }) );  
    Busy = 0;
    return 1; 
  }
}
void bow_back(object who) {
  if(who && present(who, environment())) {
    tell_object(who, "Eghyron bows to you.\n");
    tell_room(environment(), "Eghyron bows to "+who->query_name()+".\n", ({ who }));
  }
  Busy = 0;
}

void arrives(object who) {
  int g;
  if(who && present(who, environment())) {
    g = random(8);
    switch(g) {
      case 0..3:
        tell_room(environment(), "Eghyron says, \"Greetings "+who->query_name()+".\"\n");
        break;
      case 4..7:
        tell_room(environment(), "Eghyron says, \"Hello "+who->query_name()+".\"\n");
        break;
    }
  }
  Busy = 0;
}

void helping_info(object who) {
  if(!who || !present(who, environment())) { 
    Busy = 0;
    return;
  }
  tell_object(who,
    "\nEghyron looks at you closely, and nods.\n");
  tell_room(environment(), 
    "Eghyron looks closely at "+(string)who->query_name()+
    ", then nods at "+(string)who->query_objective()+".\n", ({who}) );
  call_out("helping2_info", 3, who);
}

void helping2_info(object who) {
  if(!who || !present(who, environment())) { 
    Busy = 0;
    return;
  }
  tell_object(who,
    "\nEghyron tells you:\n"+
    "  \"I was hoping you would say that.  I was injured trying to clean\n"+
    "  the evil from these once holy halls.  With my wounds so severe,\n"+
    "  I am afraid that I cannot continue to fight.\"\n");
  tell_room(environment(), 
    "Eghyron says something to "+(string)who->query_name()+".\n", ({who}) );
  call_out("helping3_info", 8, who);
}

void helping3_info(object who) {
  if(!who || !present(who, environment())) { 
    Busy = 0;
    return;
  }
  tell_object(who,
    "\nHe sighs, then continues:\n"+
    "  \"I understand that you may not want to adventure out into such\n"+
    "  danger without reward, so I am willing to offer you a sum of\n"+
    "  coins for each demon you vanquish here.\"\n");
  call_out("helping4_info", 9, who);
}

void helping4_info(object who) {
  if(!who || !present(who, environment())) { 
    Busy = 0;
    return;
  }
  tell_object(who,
    "\nSmiling, Eghyron adds:\n"+
    "  \"But I will need proof of the kill.\"\n");
  call_out("helping5_info", 6, who);
}

void helping5_info(object who) {
  if(!who || !present(who, environment())) { 
    Busy = 0;
    return;
  }
  tell_object(who,
    "\nEghyron stands and walks over to you, a visible limp making his\n"+
    "every move a struggle.\n");
 tell_room(environment(), 
    "Eghyron stands and limps over to "+(string)who->query_name()+".\n", ({who}) );
  call_out("helping6_info", 4, who);
}

void helping6_info(object who) {
  if(!who || !present(who, environment())) { 
    Busy = 0;
    return;
  }
  tell_object(who,
    "\nPlacing a hand upon your shoulder, Eghyron says:\n"+
    "  \"Each of these creatures will drop an item, proof of their\n"+
    "  demise.  Bring each item and give it to me and I shall give\n"+
    "  you a great number of coins for each.\"\n\n"+
    "  \"Some creatures aren't worth the reward though.  You should\n"+
    "  know which ones are not when you encounter them.\"\n");
  tell_room(environment(), 
    "Placing a hand on "+(string)who->query_possessive()+
    "shoulder, Eghyron speaks to "+(string)who->query_name()+".\n", ({who}) );
  call_out("helping7_info", 13, who);
}

void helping7_info(object who) {
  if(!who || !present(who, environment())) { 
    Busy = 0;
    return;
  }
  tell_object(who,
    "\nClasping your hand, Eghyron adds:\n"+
    "  \"Good luck, "+(string)who->query_name()+
    ", the realm and its gods are backing your effort.\"\n");
  tell_room(environment(), 
    "Eghyron clasps "+(string)who->query_name()+"'s hand.\n", ({who}) );
  call_out("helping8_info", 4, who);
}

void helping8_info(object who) {
  if(!who || !present(who, environment())) { 
    Busy = 0;
    return;
  }
  tell_object(who,
    "\nEghyron perks up for a second:\n"+
    "  \"Before I forget, you can also get past the entrance if you\n"+
    "  'circle' the 'ruins'.  That way you can avoid the guardian.\"\n");
  tell_room(environment(), 
    "Eghyron says something to "+(string)who->query_name()+".\n", ({who}) );
  call_out("helping9_info", 15, who);
}

void helping9_info(object who) {
  if(!who || !present(who, environment())) { 
    Busy = 0;
    return;
  }
  tell_object(who,
    "\nEghyron walks over and sits down, waving to you and again wishing\n"+
    "you good luck.\n");
 tell_room(environment(), 
   "Eghyron walks over and sits down, then waves to "+
    (string)who->query_name()+".\n", ({who}) );
  Busy = 0;    
}

void portal_info(object who) {
  if(!who || !present(who, environment())) { 
    Busy = 0;
    return;
  }
  tell_room(environment(), 
    "Eghyron says:  \"Portal.  What about a portal?\"\n");
  Busy = 0;
}

void spell_info(object who) {
  if(!who || !present(who, environment())) { 
    Busy = 0;
    return;
  }
  tell_room(environment(), 
    "Eghyron asks:  \"What kind of spell are you talking about, "+
    (string)who->query_name()+"?\"\n");
  Busy = 0;
}

void portal_spell_info(object who) {
  if(!who || !present(who, environment())) { 
    Busy = 0;
    return;
  }
  tell_room(environment(), 
    "\nEghyron says: \"Hmm... I used to know a spell that opened\n"+
    "dimensional portals.\n");
  tell_object(who,
    "Eghyron gets up and limps over to you.\n");
  tell_room(environment(),
    "Eghyron gets and limps over to "+
    (string)who->query_name()+".\n", ({who}) );
  call_out("portal_spell2_info", 3, who);    
}

void portal_spell2_info(object who) {
  if(!who || !present(who, environment())) { 
    Busy = 0;
    return;
  }
  tell_object(who,
    "\nEghyron whispers to you:\n"+
    "  \"I tell you what.  I have heard tales of two swords that are most\n"+
    "effective against demons.  If you bring me one of these weapons, I\n"+
    "will do what I can to help you with the portal spell.\n");
  tell_room(environment(), 
    "Eghyron whispers to "+(string)who->query_name()+".\n", ({who}) );
  Busy = 0;
}

void swords_info(object who) {
  if(!who || !present(who, environment())) { 
    Busy = 0;
    return;
  }
  tell_object(who,
    "\nEghyron ends with:\n"+
    "  \"I am not sure of their names, but I've been told that one is\n"+
    "  found with the destruction of darkness and the other is the\n"+
    "  joining of two weapons into one.  That's really all I know.\n");
  tell_room(environment(), 
    "Eghyron says something to "+(string)who->query_name()+".\n", ({who}) );
  Busy = 0;
}

void talisman_info(object who) {
  if(!who || !present(who, environment())) { 
    Busy = 0;
    return;
  }
  tell_object(who,
    "\nEghyron tells you:\n"+
    "  \"I once came across a scholarly monk who spoke of an ancient item\n"+
    "  that could banish a curse upon his land.  It was a talisman if I\n"+
    "  remember correctly.  Perhaps if you spoke with him, he could be of\n"+
    "  some assitance.\n");
  tell_room(environment(), 
    "Eghyron says something to "+(string)who->query_name()+".\n", ({who}) );
  Busy = 0;
}

void monk_info(object who) {
  if(!who || !present(who, environment())) { 
    Busy = 0;
    return;
  }
  tell_object(who,
    "\nEghyron ends with:\n"+
    "  \"I recall coming across him in a forest.  If my memory serves me,\n"+
    "  I passed beyond a dark doorway and through a black room to find\n"+
    "  him.  He  lived in a wild place where animals roamed freely and\n"+
    "  horned humanoids dwelled. Frankly, that is all I can remember of\n"+
    "  him\".\n");
  tell_room(environment(), 
    "Eghyron says something to "+(string)who->query_name()+".\n", ({who}) );
  Busy = 0;
}

void diamond_info(object who) {
  if(!who || !present(who, environment())) { 
    Busy = 0;
    return;
  }
  tell_object(who,
    "\nEghyron tells you:\n"+
    "  \"I've come across ancient texts that tell of a demon of the dark\n"+
    "  that hoards diamonds that are black as night.  I believe its name\n"+
    "  to be Cleoprites, if memory serves me.\"\n");
  tell_room(environment(), 
    "Eghyron says something to "+(string)who->query_name()+".\n", ({who}) );
  Busy = 0;
}

void cleoprites_info(object who) {
  if(!who || !present(who, environment())) { 
    Busy = 0;
    return;
  }
  tell_object(who,
    "\nEghyron ponders:\n"+
    "  \"Hmm... Cleoprites... Let me think...\"\n\n"+
    "  \"Ah, yes.  Cleoprites... It is also known as the Demon of Night.\n"+
    "  If my recollections are accurate, its lair was hidden deep below\n"+
    "  a world of shadow.\"\n");
  tell_room(environment(), 
    "Eghyron says something to "+(string)who->query_name()+".\n", ({who}) );
  Busy = 0;    
}

void shadow_info(object who) {
  if(!who || !present(who, environment())) { 
    Busy = 0;
    return;
  }
  tell_object(who,
    "\nEghyron tells you:\n"+
    "  \"Seek out the ShadowFortress deep within ShadowGate.  I once found\n"+
    "  myself lost in maze-like catacombs deep beneath.  Perhaps this is\n"+
    "  the location of the demon's domain.  It seem logical, at least.\"\n");
  tell_room(environment(), 
    "Eghyron says something to "+(string)who->query_name()+".\n", ({who}) );
  Busy = 0;
}

void gave_gsword(object who) {
  if(!who || !present(who, environment())) { 
    Busy = 0;
    return;
  }
  tell_room(environment(),
    "\nEghyron looks down the blade of the "+HIY+"Glowing Sword"+NORM+".  Whipping it\n"+
    "back and forth in front of him, it whistles through the air while\n"+
    "leaving a trail of light in its path.\n");
  call_out("gave_sword2", 3, who);
}

void gave_csword(object who) {
  if(!who || !present(who, environment())) { 
    Busy = 0;
    return;
  }
  tell_room(environment(),
    "\nEghyron looks down the blade of the "+HIC+"Crystal Longsword"+NORM+".  Whipping\n"+
    "it back and forth in front of him, it whistles through the air\n"+
    "while leaving a cloud of blue energy in its path.\n");
  call_out("gave_sword2", 8, who);
}

void gave_sword2(object who) {
  object sword;
  if(!who || !present(who, environment())) { 
    Busy = 0;
    return;
  }
  command("unwield sword", this_object());
  tell_object(who,  
    "\nEghyron sheathes the sword on his back and says:\n"+
    "  \"Good work, "+(string)who->query_name()+
    ". This sword should help me\n"+
    "  vanquish any demons that remain here.\"\n");
   tell_room(environment(), 
    "Eghyron sheathes a sword and says something to "+
    (string)who->query_name()+".\n", ({who}) );
  sword = present("sword", this_object());
  if(sword) {
    move_object(sword, "/room/void");
    destruct(sword);
  }
  this_object()->recalc_carry();
  command("wield sword", this_object());
  call_out("gave_sword3", 5, who);
}

void gave_sword3(object who) {
  if(!who || !present(who, environment())) { 
    Busy = 0;
    return;
  }
  tell_object(who,
    "\nEghyron says:\n"+
    "  \"Since you have helped me, I can give you a scroll that can\n"+
    "  open a portal.  With the right location and items, you can make\n"+
    "  a gate to another land.\"\n");
   tell_room(environment(), 
    "Eghyron says something to "+(string)who->query_name()+".\n", ({who}) );
  call_out("gave_sword4", 5, who);
}

void gave_sword4(object who) {
  if(!who || !present(who, environment())) { 
    Busy = 0;
    return;
  }
  tell_room(environment(),
    "\nEghyron takes out a piece of parchment and begins to write.\n");
  call_out("gave_sword5", 10, who);
}

void gave_sword5(object who) {
  if(!who || !present(who, environment())) { 
    Busy = 0;
    return;
  }
  tell_room(environment(),
    "\nEghyron rolls up the parchment into a neat little scroll.\n");
  call_out("gave_sword6", 2, who);
}

void gave_sword6(object who) {
  object scroll;
  if(!who || !present(who, environment())) { 
    Busy = 0;
    return;
  }
  tell_object(who,
    "\nEghyron sighs:\n"+
    "  \"It seems I have forgotten some of the incantation.  I've written\n"+
    "  down what I remember.  Maybe you can find someone else that knows\n"+
    "  the rest.\"\n\n"+
    "Eghyron hands you a scroll.\n");
  tell_room(environment(), 
    "Eghyron hands "+(string)who->query_name()+" a scroll.\n", ({who}) );
  scroll = clone_object("/players/forbin/realms/cave/OBJ/scroll.c");
  move_object(scroll, who);   
  call_out("gave_sword7", 3, who);
}

void gave_sword7(object who) {
  if(!who || !present(who, environment())) { 
    Busy = 0;
    return;
  }
  tell_object(who,
    "\nEghyron finishes:\n"+
    "  \"Oh, I almost forgot.  To complete the spell, you'll need an\n"+
    "  ancient talisman and a diamond black as night.  Those special\n"+
    "  items can be hard to find, so search well.\"\n");
   tell_room(environment(), 
    "Eghyron says something to "+(string)who->query_name()+".\n", ({who}) );
  call_out("gave_sword8", 10, who);
}

void gave_sword8(object who) {
  if(!who || !present(who, environment())) { 
    Busy = 0;
    return;
  }
  tell_room(environment(),
    "\nEghyron says: \"Good luck, "+(string)who->query_name()+".\n");
  Busy = 0;   
}


void catch_tell(string str) {
  string str1, str2, str3;
  string tmp1, tmp2, tmp3;
  object who, gsword, csword, bountyob;
  if(sscanf(str, "%s gives %s to Eghyron%s\n", tmp1, tmp2, tmp3) || 
     sscanf(str, "%s gives %s to Hunter%s\n", tmp1, tmp2, tmp3)) {
     /*
     if(find_player(lower_case(tmp1))) 
       who = find_player(lower_case(tmp1));
     */
     who = this_player();
    gsword = present("glowing sword", this_object());
    csword = present("crystal longsword", this_object());
    bountyob = present("collectable_bounty_object", this_object());
    if(gsword || csword) {
      str1 = file_name((gsword ? gsword : csword));
      sscanf(str1, "%s#%s", str2, str3);
      if(str2 == "players/snow/WEAPONS/glow_sword" ||
         str2 == "players/llew/closed/crystal/crystal_sword") {
        command("unwield broadsword", this_object());
        command("wield sword", this_object());
        if(gsword) {
        	Busy = 1;
          call_out("gave_gsword", 1, who);
          write_file(
            "/players/forbin/logs/sfp_miniquest.log",
            "["+date_time()+"] "+
            capitalize((string)who->query_real_name())+" ("+
            (string)who->query_level()+"+"+(string)who->query_extra_level()+
            ") gave Eghyron: Glowing Sword\n");
        }
        else {
        	Busy = 1;
          call_out("gave_csword", 1, who);        
          write_file(
            "/players/forbin/logs/sfp_miniquest.log",
            "["+date_time()+"] "+
            capitalize((string)who->query_real_name())+" ("+
            (string)who->query_level()+"+"+(string)who->query_extra_level()+
            ") gave Eghyron: Crystal Longsword\n");
        }
      }
    }
    else if(bountyob) {
    	Busy = 1;
      call_out("collect_bounty", 1, who);        
      write_file(
        "/players/forbin/logs/ruinbounty.log",
        "["+date_time()+"] "+
        capitalize((string)who->query_real_name())+" ("+
        (string)who->query_level()+"+"+(string)who->query_extra_level()+
        ") was rewarded by Eghyron for :"+(string)bountyob->query_name()+"\n");
    }    
    else {
      tell_room(environment(), 
        "Eghyron says: \"Thank you for the "+tmp2+", "+
        (string)who->query_name()+", but I do not need it.\"\n");
      command("drop "+tmp2, this_object());
    }      
  }
  else if(sscanf(str, "%sbows%syou.", tmp1, tmp2) == 2) {
    who = this_player();
    if(who->is_player() && !who->query_attack())
      Busy = 1;
      call_out("bow_back", 1, who);
  }
  else if(sscanf(str, "%s arrives.%s\n", tmp1, tmp2) == 2) {
     Busy = 1;
     call_out("arrives", 2, find_player(lower_case(tmp1)));
  }
  if((sscanf(str, "%s says: %s\n", tmp1, tmp2) == 2 ||
		  sscanf(str, "%s asks: %s\n", tmp1, tmp2) == 2 ||
		  sscanf(str, "%s exclaims: %s\n", tmp1, tmp2) == 2 ||
		  sscanf(str, "%s tells you: %s\n", tmp1, tmp2) == 2)) {
		if(lower_case(tmp1) == "eghyron") return;  
    tmp3 = lower_case(tmp2);
    if(sscanf(tmp3, "%shelp%s", tmp1, tmp2) == 2) {  
      who = this_player();
      if(who->is_player() && !who->query_attack() && who != this_object())
        Busy = 1;
        call_out("helping_info", 1, who);
    }  
    else if(sscanf(tmp3, "%sportal spell%s", tmp1, tmp2) == 2) {  
      who = this_player();
      if(who->is_player() && !who->query_attack() && who != this_object())
        Busy = 1;
        call_out("portal_spell_info", 1, who);
    }      
    else if(sscanf(tmp3, "%sportal%s", tmp1, tmp2) == 2) {  
      who = this_player();
      if(who->is_player() && !who->query_attack() && who != this_object())
        Busy = 1;
        call_out("portal_info", 1, who);
    }
    else if(sscanf(tmp3, "%sspell%s", tmp1, tmp2) == 2) {  
      who = this_player();
      if(who->is_player() && !who->query_attack() && who != this_object())
        Busy = 1;
        call_out("spell_info", 1, who);
    }    
    else if(sscanf(tmp3, "%stalisman%s", tmp1, tmp2) == 2) {  
      who = this_player();
      if(who->is_player() && !who->query_attack() && who != this_object())
        Busy = 1;
        call_out("talisman_info", 1, who);
    }
    else if(sscanf(tmp3, "%smonk%s", tmp1, tmp2) == 2) {  
      who = this_player();
      if(who->is_player() && !who->query_attack() && who != this_object())
        Busy = 1;
        call_out("monk_info", 1, who);
    }
    else if(sscanf(tmp3, "%sdiamond%s", tmp1, tmp2) == 2) {  
      who = this_player();
      if(who->is_player() && !who->query_attack() && who != this_object())
        Busy = 1;
        call_out("diamond_info", 1, who);
    }
    else if(sscanf(tmp3, "%scleoprites%s", tmp1, tmp2) == 2) {  
      who = this_player();
      if(who->is_player() && !who->query_attack() && who != this_object())
        Busy = 1;
        call_out("cleoprites_info", 1, who);
    }
    else if(sscanf(tmp3, "%sshadow%s", tmp1, tmp2) == 2) {  
      who = this_player();
      if(who->is_player() && !who->query_attack() && who != this_object())
        Busy = 1;
        call_out("shadow_info", 1, who);
    }
    else if(sscanf(tmp3, "%stwo sword%s", tmp1, tmp2) == 2) {  
      who = this_player();
      if(who->is_player() && !who->query_attack() && who != this_object())
        Busy = 1;
        call_out("sword_info", 1, who);
    }
    else if(sscanf(tmp3, "%ssowrd%s", tmp1, tmp2) == 2) {  
      who = this_player();
      if(who->is_player() && !who->query_attack() && who != this_object())
        Busy = 1;
        call_out("sword_info", 1, who);
    }
  }   
}

monster_died() {
#ifdef KILLLOG
  mon_log(KILLLOG);
#endif
  tell_room(environment(this_object()),
    "Eghyron slumps to the ground...finding peace at last.\n"); 
return 1; 
}
