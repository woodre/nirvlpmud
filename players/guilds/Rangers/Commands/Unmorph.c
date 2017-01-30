#pragma strict_types
#include <ansi.h>
#include "../RangerDefs.h"

status
QRangerInfo() { return 1; }

status
RangerInfo()
{
  write(
"  The Unmorph command allows you to return back to your secret \n\
indentity and join the mud world as a normal player.\n");
  return 1;
}

int
RangerPower(string str, string type)
{
  int cost, i;
  string msg, title, pretitle;
  if(previous_object()->QMorphed() || previous_object()->QNinja())
  {
    title = "" + previous_object()->QOldTitle() + "";
    tell_object(this_player(), "Resetting your title to " + title + "\n");
    pretitle = "" + previous_object()->QOldPretitle() + "";
    tell_object(this_player(), "Resetting your pretitle to " + pretitle + "\n");
    if ( present("soul",this_player()) )
    {
      present("soul",this_player())->setmin("arrives");
      present("soul",this_player())->setmout("leaves");
    }
    if ("/players/guilds/Rangers/Commands/Pweapon.c"->QSkill(      this_player()->query_real_name()))
    {
      tell_object(this_player(), "Powering Down Weapon.\n");
      "/players/guilds/Rangers/Commands/Pweapon.c"->RangerPower();
    }
    if ("/players/guilds/Rangers/Commands/Marmor.c"->QSkill(this_player()->query_real_name()))
    {
      tell_object(this_player(), "Powering Down Armor.\n");
      "/players/guilds/Rangers/Commands/Marmor.c"->RangerPower();
    }
    if(previous_object()->QMorphed())
    {
      previous_object()->SMorphed();
      previous_object()->RID("player_short_obj");
      command("release", this_player());
    }
    if(previous_object()->QNinja())
    {
      previous_object()->SNinja();
      previous_object()->RID("dark_sight_obj");
      previous_object()->RID("silent_move_obj");
      previous_object()->RID("player_short_obj");
    }
    if (title)
      this_player()->set_title(title);
    if (pretitle)
      this_player()->set_pretitle(pretitle);
    previous_object()->SPlayerShort(pretitle + " " +
      this_player()->query_name() + " " + title);
    return 1;
  }
  tell_object(this_player(), "Zordon tells you: \"You are not Morphed.\"\n");
  return 1;
}
