/**************************************************************************
 * The Power Ranger Communicator (Guild Object)                           *
 * Created by Beck/Russ Warren for Nirvana.                               *
 *  Updated by vital/keith for the Rangers                                *
 *  Last changed 2005.10.13                                               *
 **************************************************************************/
#pragma strict_types

#include <ansi.h>
#include "RangerDefs.h"

inherit "/players/guilds/Rangers/Communicator/Communicator.c";
inherit "/players/guilds/Rangers/Communicator/RangerArmor.c";
inherit "/players/guilds/Rangers/Communicator/RangerWeapon.c";
inherit "/players/guilds/Rangers/Communicator/SkillMapping.c";
inherit "/players/guilds/Rangers/Communicator/Train.c";

string RangerHome;
static string PlayerShortObject;
static mixed *TempVars;

string
query_name(){ return "Power Ranger Communicator"; }

string
query_player_short(){ return PlayerShort; }

int
query_combat_method(){ return 2; }

status
get(){ return 1;}

status
drop(){ return 1;}

string
short()
{
  string msg;
  msg = "";
  if(this_object()->QMorphed())
  {
    if(this_object()->QuerySkillLevel("armor"))
    {
      msg +=  "A " + RangerAnsi + RangerColor + OFF + " " + RangerAlign +
        " Suit. (worn)\n";
      msg +=  "A " + RangerAnsi + RangerColor + OFF + " " + RangerAlign +
        " Helmet. (worn)\n";
      msg =   msg + "" + RangerAnsi + RangerColor + OFF + " " + RangerAlign +
        " Boots. (worn)\n" + RangerAnsi + RangerColor + OFF + " " +
        RangerAlign + " Gloves. (worn)\n";
    }
    else
      msg = msg+"A "+RangerAlign+" Coin.\n"+"A "+RangerAlign+" Communicator";
  }
  else if(this_object()->QNinja())
  {
    msg = msg + "" + RangerAnsi + RangerColor + " Robes" + OFF + ". (worn)\n";
    msg = msg + "" + RangerAnsi + RangerColor + " Mask" + OFF + ". (worn)\n";
    msg = msg + "" + RangerAnsi + RangerColor + " Boots" + OFF + ". (worn)\n";
    msg = msg + "a " + RangerBelt + OFF + " belt. (worn)\n";
  }
  if(this_object()->QuerySkillLevel("morph"))
  {
    msg += "A " + RangerAlign + " Morpher.\n" +
      "A " + RangerAlign + " Communicator";
  }
  else
  {
    msg = "A " + RangerAlign + " Communicator";
  }
  return msg;
}


void
long()
{
  write(format("This communicator is made with a steel case, and has a fine quartz crystal. Looking closer you see little blinking lights all over the communicator. \nType 'ranger' for more information.\n"));
}


mixed
guild_login()
{
  int i;
  if(restore_object(SAVEDIR+(string)this_player()->query_real_name()))
  {
    write("Setting your Power Levels...\n");
  }
  else if (this_player()->is_kid())
  {
    if(restore_object(SAVEDIR+"kid_"+this_player()->query_name()))
    {
      write("Setting your Power Levels...\n");
    }
    else
      return destruct(this_object());
  }
  else
  {
    this_object()->SaveRanger();
  }

  if(this_player()->is_player() && this_player() == this_player() &&
    !this_player()->is_kid())
  {
    if(this_player()->query_level() < 20 ||
      (string) this_player()->query_real_name() == "vital")
    {
      if(!RangerAlign) RangerAlign = "Power Ranger";
      if(!RangerHome)
        RangerHome = "/players/guilds/Rangers/CommandCenter/CommandCenter.c";
      if(RangerAlign == "Power Ranger")
        this_player()->set_guild_name(GUILDNAME);
      if( (string) this_player()->query_guild_name() == GUILDNAME)
      {
        call_other(this_player(), "set_home",
          "/players/guilds/Rangers/CommandCenter/CommandCenter.c");
      }
      if( (string) this_player()->query_guild_name() == GUILDNAME &&
          (string) this_player()->query_guild_file() != GUILDOBJ )
      {
        call_other(this_player(), "set_guild_file", GUILDOBJ );
      }
      if(!HiddenSkills) HiddenSkills = ({});
      RestoreSkillsSaved();
      NotArmor = "notarmor";
      RandomNumber = random(500);
      if(!RangerAnsi) RangerAnsi = OFF;
      set_class(0);
      wielded_by = this_player();
      this_player()->wield(this_object(),1);
      wielded = 1;
      set_ac(0);
      set_weight(8);
      set_type("armor");
      call_other(this_player(), "wear", this_object(), 1, "armor",
        ({"physical",0,0,"shield_bonus"}
      ));
      worn_by = this_player();
      worn = 1;
    }
  }
  if(this_player()->is_kid())
  {
    if(!RangerAlign) RangerAlign = "Power Ranger";
    if(!HiddenSkills) HiddenSkills = ({}
    );
    RestoreSkillsSaved();
    add_action("FinishTrainRanger","train");
    NotArmor = "notarmor";
    PlayerShortObject = "not_player_short";
    RandomNumber = random(500);
    set_class(0);
    wielded_by = this_player();
    this_player()->wield(this_object(),1);
    wielded = 1;
    set_ac(0);
    set_weight(8);
    set_type("armor");
    call_other(this_player(), "wear", this_object(), 1, "armor",
      ({"physical",0,0,"shield_bonus"}
    ));
    worn_by = this_player();
    worn = 1;
  }
  if(this_player()->RangerNPC())
  {
    if(!HiddenSkills) HiddenSkills = ({}
    );
    RestoreSkillsSaved();
    if(!RangerAnsi) RangerAnsi = "";
    set_class(10);
    set_ac(3);
    set_weight(10);
    set_type("armor");
    call_other(this_player(), "wear", this_object(), 1, "armor",
      ({"physical",3,0,"shield_bonus"}
    ));
    worn_by = this_player();
    wielded_by = this_player();
    call_other(this_player(), "wield", this_object());
    worn = 1;
    wielded = 1;
  }
  this_object()->SaveRanger();
  return;
}


mixed
init_arg() { guild_login(); }

void
init()
{
  int i;
  if(environment(this_object()))
  {
    if(environment(this_object())->is_player() &&
      environment(this_object()) == this_player() && !this_player()->is_kid())
    {
      if((string)environment(this_object())->query_real_name() != "vital")
      {
        if((int)environment(this_object())->query_level() > 19 )
        {
          write("Wizards may not have this object!!!\n"+
            "Clone HonorRangerCommunicator instead\n");
          destruct(this_object());
        }
      }
      call_out("channel_me", 2);
      add_action("Spam","spam");
      add_action("TrainRanger1_5","rangertrainfinal");
      add_action("check_ranger_kill","kill");
      add_action("quit","quit");
      add_action("inactive","inactive");
      add_action("Muffles","rtm");
      for (i=0; i < sizeof(SKILLS); i++)
      {
        add_action("RangerPower",SKILLS[i]);
      }
      if( (string) this_player()->query_guild_name() == GUILDNAME &&
          (string) this_player()->query_guild_file() != GUILDOBJ )
      {
        call_other(this_player(), "set_guild_file", GUILDOBJ );
      }
    }
  }
}


void
SaveRanger()
{
  if(environment(this_object()))
  {
    if(environment(this_object())->is_player())
    {
      if( (string) this_player()->query_guild_name() == GUILDNAME &&
          (string) this_player()->query_guild_file() != GUILDOBJ )
      {
        call_other(this_player(), "set_guild_file", GUILDOBJ );
      }
      save_object(SAVEDIR+environment(this_object())->query_real_name());
      if(file_size(RANGERDIR+environment(this_object())->query_real_name() +
        ".save"))
      {
        rm(RANGERDIR+environment(this_object())->query_real_name() + ".save");
      }
      write_file(RANGERDIR +
        environment(this_object())->query_real_name() + ".save",
        capitalize((string)environment(this_object())->query_real_name()) +
        "\n" + this_object()->query_ranger_type() + "\n" +
        delete_colour(this_object()->query_ranger_belt()) + "\n" +
        RangerColor + "\n" + this_object()->query_date() + "\n" +
        this_object()->query_ranger_leadership() + "\n");
    }
    else if(environment(this_object())->is_kid())
      save_object(SAVEDIR+"kid_"+environment(this_object())->query_name());
    else
      return;
  }
  else
    return;
}


void
restore_ranger()
{
  if(environment(this_object()))
  {
    if(environment(this_object())->is_player())
      restore_object(SAVEDIR+environment(this_object())->query_real_name());
    else if(environment(this_object())->is_kid())
      restore_object(SAVEDIR+"kid_"+environment(this_object())->query_name());
    else
      return;
  }
  else
    return;
}


status
RangerPower(string str)
{
  string verb;
  int skill_level;
  string wizard_name;
  set_ac(0);
  verb = query_verb();
  skill_level = QuerySkillLevel(verb);
  wizard_name = "guilds";
  if(!wizard_name) wizard_name = "guilds";
  verb = capitalize(verb)+".c";
  if(verb = "/players/guilds/Rangers/Commands/" + capitalize(query_verb())+"")
    verb->RangerPower(str,RangerAlign);
  return 1;
}

void
quit()
{
  CHANNEL->remove_channel(RangerAlign,this_object());
  SaveSkillsSaved();
  SaveRanger();
  if(QNinja())
  {
    RID("silent_move_object");
    RID("dark_sight_object");
    environment(this_object())->unset_invis_sp();
  }
  return;
}

void
channel_me()
{
  CHANNEL->add_channel(RangerAlign,this_object());
}