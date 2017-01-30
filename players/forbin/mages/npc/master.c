#include "../def.h"

inherit "/players/vertebraker/closed/std/monster.c";

int Busy;

void set_busy(int x) { Busy = x; }

/* Prototype Declarations */
string m_name();
string m_school();
string m_school_proper();
string m_attribute();
string m_attribute_proper();
string m_list_heading();

status train_school(string str, object gob, object player);
status raise_attribute(string str, object gob, object player);

status cmd_master_help(string arg)
{
	object gob;
  if(!arg|| arg != "help") 
    return 0;

  if((string)this_player()->query_guild_name() == "Mages" && 
     (gob = present("forbin_mage_object", this_player())))
  {  
  tell_object(this_player(),
    "\n\tThe Masters of the Mages Guild respond to talking.  You may\n"+
    "\teither say or tell them things in order to get a response.\n"+
    "\t  Valid things to say/tell are:\n"+
    "\t    1] "+SGC+"'"+PGC+"list spells"+SGC+"'"+NORM+" or "+
    SGC+"'"+PGC+"list "+TGC+"<"+PGC+"school"+TGC+">"+SGC+"'"+NORM+"\n"+
    "\t         -The Master will list all the spells\n"+
    "\t          you may learn from him or her.\n"+
    "\t    2] "+SGC+"'"+PGC+"info "+TGC+"<"+PGC+"spell"+TGC+">"+SGC+"'"+NORM+"\n"+
    "\t         -The Master will tell you more about\n"+
    "\t          a certain <spell>.\n"+
    "\t    3] "+SGC+"'"+PGC+"teach "+TGC+"<"+PGC+"spell"+TGC+">"+SGC+"'"+NORM+"\n"+
    "\t         -The Master will attempt to teach you\n"+
    "\t          a certain <spell>.\n"+
    "\t    4] "+SGC+"'"+PGC+"train "+TGC+"<"+PGC+"school"+TGC+">"+SGC+"'"+NORM+"\n"+
    "\t         -The Master will attempt to advance a\n"+
    "\t           certain <school>.\n"+
    "\t    5] "+SGC+"'"+PGC+"raise "+TGC+"<"+PGC+"attribute"+TGC+">"+SGC+"'"+NORM+"\n"+
    "\t         -The Master will attempt to raise you\n"+
    "\t          in a certain <attribute>.\n"+
    "\n\t  Please keep in mind that not all options are available at all\n"+
    "\tguild Masters, and that Masters may only teach you spells or\n"+
    "\tadvance schools in their chosen speciality.\n\n");
  return 1;
  }
}

void init() 
{
  ::init();
	add_action("cmd_master_help", "master");
	add_action("info_spell2","info");
	add_action("teach_spell2","teach");
}
	
mixed catch_tell(string text)
{
  string str;
  string t1, t2, t3;
  object player, gob;
  
  str = lower_case(implode(explode(text,"\n"),""));
  
  if(!(player = this_player())) return;
  
  gob = present("forbin_mage_object", player);
  
  if(sscanf(str, "%sbows%syou.", t1, t2) == 2)
  {  
    if(player->is_player() && !player->query_attack())
      call_out("bow_back", 1, player);
  }
  else if(sscanf(str, "%s: list spells%s", t1, t2) == 2)
  { 
    if(player->is_player() && !player->query_attack() && !Busy && m_school())
    {
      Busy = 1;
      return (int)SPELL_DAEMON->list_spells(m_school(), gob, player, this_object());
    }
  }  
  else if(sscanf(str, "%s: list %s %s", t1, t2, t3) == 3)
  {
    if(player->is_player() && !player->query_attack() && !Busy && m_school())
    {
      Busy = 1;
      return (int)SPELL_DAEMON->list_spell(t2[0..3], gob, player, this_object());
    }
  }
  else if(sscanf(str, "%s: list %s", t1, t2) == 2)
  {
    if(player->is_player() && !player->query_attack() && !Busy && m_school())
    {
      Busy = 1;
      return (int)SPELL_DAEMON->list_spells(t2[0..3], gob, player, this_object());
    }
  }        
  else if(sscanf(str, "%s: info %s", t1, t2) == 2)
  {
    if(player->is_player() && !player->query_attack() && !Busy && m_school())
    {
      Busy = 1;
      return (int)SPELL_DAEMON->info_spell(t2, m_school(), gob, player, this_object());
    }
  }
  else if(sscanf(str, "%s: teach %s", t1, t2) == 2)
  {
    if(player->is_player() && !player->query_attack() && !Busy && m_school())
    {
      Busy = 1;
      return (int)SPELL_DAEMON->learn_spell(t2, m_school(), gob, player, this_object());
    }
  } 
  else if(sscanf(str, "%s: train %s", t1, t2) == 2)
  {
    if(player->is_player() && !player->query_attack() && !Busy && m_school())
    {
      Busy = 1;
      return train_school(t2, gob, player);
    }
  }  
  else if(sscanf(str, "%s: raise %s", t1, t2) == 2)
  {
    if(player->is_player() && !player->query_attack() && !Busy && m_attribute())
    {
      Busy = 1;
      return raise_attribute(t2, gob, player);
    }
  }     
  else if(sscanf(str, "%s arrives.%s\n", t1, t2) == 2)
  {
    if(!random(3))
    {
      Busy = 1;
      call_out("arrives", 2, find_player(t1));
    }
  }
}

void arrives(object who) 
{
  if(who && present(who, environment())) 
  {
    switch(random(8)) 
    {
      case 0..2:
        tell_room(environment(), 
          m_name()+" says: Greetings "+(string)who->query_name()+".\n");
        break;
      case 3..5:
        tell_room(environment(), 
          m_name()+" says: Hello "+(string)who->query_name()+".\n");
        break;
      case 6:
        tell_room(environment(), 
          m_name()+" says: Hiya "+(string)who->query_name()+".\n");
        break;
      case 7:
        tell_room(environment(), 
          m_name()+" says: Heya "+(string)who->query_name()+".\n");
        break;
    }
  }
  Busy = 0;
}

void bow_back(object who)
{
  if(who && present(who, environment()))
  {
    switch(random(4))
    {
      case 0..2:  
        tell_object(who, 
          m_name()+" bows to you.\n");
        tell_room(environment(), 
          m_name()+" bows to "+(string)who->query_name()+".\n", ({ who }));
        break;
      case 3:  
        tell_object(who, 
      	  m_name()+" glances at you.\n");
        tell_room(environment(), 
          m_name()+" glances at "+(string)who->query_name()+".\n", ({ who }));
        break;
    }
  }
}

status train_school(string str, object gob, object player)
{
  string school;
  int amt;
 
   str = lower_case(str);
  
  if(sscanf(str, "%s %d", school, amt) == 2) { }
  else
  {
  	school = str;
  	amt = 1;
  }  	
  
  if(amt < 1)
  {
    tell_object(player, 
      m_name()+" says: You have to use a positive amount, "+
      (string)player->query_name()+"?\n");
    tell_room(environment(),
      m_name()+" says something to "+(string)player->query_name()+".\n", ({ player }));
    set_busy(0);
    return 1;
  }
  
  
  if(!school || school == "school" || school == "schools")
  {
    tell_object(player, 
      m_name()+" says: What school of magic would you like to raise, "+
      (string)player->query_name()+"?\n");
    tell_room(environment(),
      m_name()+" says something to "+(string)player->query_name()+".\n", ({ player }));
    set_busy(0);
    return 1;
  }
  
  if(member_array(school, VALIDSCHOOLS) < 0)
  {
    tell_object(player, 
      m_name()+" says: That is not a school of magic, "+
      (string)player->query_name()+".\n");
    tell_room(environment(),
      m_name()+" says something to "+(string)player->query_name()+".\n", ({ player }));
    set_busy(0);
    return 1;
  }
  
  if(school[0..3] != m_school())
  {
    tell_object(player, 
      m_name()+" says: I can not train you in that school of magic, "+
      (string)player->query_name()+".\n");
    tell_room(environment(),
      m_name()+" says something to "+(string)player->query_name()+".\n", ({ player }));
    set_busy(0);
    return 1;
  }  
  
  if(!gob->query_school_pts())
  {
    tell_object(player, 
      m_name()+" says: You do not have any points to spend on schools, "+
      (string)player->query_name()+".\n");
    tell_room(environment(),
      m_name()+" says something to "+(string)player->query_name()+".\n", ({ player }));
    set_busy(0);
    return 1;     
  }
  
  if(((int)gob->query_schools(school[0..3]) + amt) > 100)
  {
    tell_object(player, 
      m_name()+" says: You cannot raise "+m_school_proper()+" above 100, "+
      (string)player->query_name()+".\n");
    tell_room(environment(),
      m_name()+" says something to "+(string)player->query_name()+".\n", ({ player }));
    set_busy(0);
    return 1;     
  }

  if(gob->query_school_pts() < amt)
  {
    tell_object(player, 
      m_name()+" says: You do not have enough points to raise "+
      m_school_proper()+" by "+amt+", "+(string)player->query_name()+".\n");
    tell_room(environment(),
      m_name()+" says something to "+(string)player->query_name()+".\n", ({ player }));
    set_busy(0);
    return 1;     
  }
  
  tell_object(player,
    m_name()+" begins instructing you in the ways of "+m_school_proper()+".\n"+
    "You raise "+m_school_proper()+" from "+(int)gob->query_school(school[0..3])+" to "+
    ((int)gob->query_school(school[0..3]) + amt)+".\n");
  tell_room(environment(),
      m_name()+" says something to "+(string)player->query_name()+".\n", ({ player }));    
  gob->add_school(school[0..3], amt);
  gob->sub_school_pts(amt);
  gob->advance_checks();
  gob->save_gob();
  set_busy(0);
  return 1;
}

status raise_attribute(string str, object gob, object player)
{
  string attrib;
  int amt;
 
   str = lower_case(str);
  
  if(sscanf(str, "%s %d", attrib, amt) == 2) { }
  else
  {
  	attrib = str;
  	amt = 1;
  }  	
  
  if(amt < 1)
  {
    tell_object(player, 
      m_name()+" says: You have to use a positive amount, "+
      (string)player->query_name()+"?\n");
    tell_room(environment(),
      m_name()+" says something to "+(string)player->query_name()+".\n", ({ player }));
    set_busy(0);
    return 1;
  }
  
  
  if(!attrib || attrib == "attrib" || attrib == "attribute" ||
                attrib == "attribs" || attrib == "attributes")
  {
    tell_object(player, 
      m_name()+" says: What attribute would you like to raise, "+
      (string)player->query_name()+"?\n");
    tell_room(environment(),
      m_name()+" says something to "+(string)player->query_name()+".\n", ({ player }));
    set_busy(0);
    return 1;
  }
  
  if(member_array(attrib, VALIDATTRIBS) < 0)
  {
    tell_object(player, 
      m_name()+" says: That is not an atribute, "+
      (string)player->query_name()+".\n");
    tell_room(environment(),
      m_name()+" says something to "+(string)player->query_name()+".\n", ({ player }));
    set_busy(0);
    return 1;
  }
  
  if(attrib != m_attribute())
  {
    tell_object(player, 
      m_name()+" says: I am not able to raise that attribute for you, "+
      (string)player->query_name()+".\n");
    tell_room(environment(),
      m_name()+" says something to "+(string)player->query_name()+".\n", ({ player }));
    set_busy(0);
    return 1;
  }  
  
  if(!gob->query_attrib_pts())
  {
    tell_object(player, 
      m_name()+" says: You do not have any points to spend on attributes, "+
      (string)player->query_name()+".\n");
    tell_room(environment(),
      m_name()+" says something to "+(string)player->query_name()+".\n", ({ player }));
    set_busy(0);
    return 1;     
  }
  
  if(((int)gob->query_attrib(attrib) + amt) > 100)
  {
    tell_object(player, 
      m_name()+" says: You cannot raise "+m_attribute_proper()+" above 100, "+
      (string)player->query_name()+".\n");
    tell_room(environment(),
      m_name()+" says something to "+(string)player->query_name()+".\n", ({ player }));
    set_busy(0);
    return 1;     
  }

  if(gob->query_attrib_pts() < amt)
  {
    tell_object(player, 
      m_name()+" says: You do not have enough points to raise "+
      m_attribute_proper()+" by "+amt+", "+(string)player->query_name()+".\n");
    tell_room(environment(),
      m_name()+" says something to "+(string)player->query_name()+".\n", ({ player }));
    set_busy(0);
    return 1;     
  }
  
  tell_object(player,
    m_name()+" begins to train you, raising your "+m_attribute_proper()+" attribute.\n"+
    "You raise "+m_attribute_proper()+" from "+(int)gob->query_attrib(attrib)+" to "+
    ((int)gob->query_attrib(attrib) + amt)+".\n");
  tell_room(environment(),
      m_name()+" says something to "+(string)player->query_name()+".\n", ({ player }));    
  gob->add_attrib(attrib, amt);
  gob->sub_attrib_pts(amt);
  gob->advance_checks();
  gob->save_gob();
  set_busy(0);
  return 1;
}