#pragma strict_types
#include <ansi.h>
#include "../RangerDefs.h"

string *Rangers;

int
QMax() { return 1; }

status
RangerPower()
{
  if(!Rangers) Rangers = ({});
  if(!(previous_object()->QMorphed()) || previous_object()->QNinja())
  {
    if(member_array(this_player()->query_real_name(), Rangers) != -1)
      Rangers -= ({ this_player()->query_real_name() });
    notify_fail("You can only use the Osmosis Mask when Morphed.\n");
    return 0;
  }
  if(member_array(this_player()->query_real_name(), Rangers) < 0)
  {
    write(BOLD+BLUE+"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"+OFF+"\n");
    write(BOLD+RED+"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"+OFF+"\n");
    write(BOLD+RED+"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"+OFF+"\n");
    write(BOLD+BLUE+"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"+OFF+"\n");
    previous_object()->AID("o_mask");
    Rangers += ({this_player()->query_real_name()});
    return 1;
  }
  write("You turn Off your Osmosis Mask.\n");
  previous_object()->RID("o_mask");
  Rangers -= ({ this_player()->query_real_name() });
  return 1;
}

status
QRangerInfo() { return 1; }

status
RangerInfo()
{
  write("  Similar to a respirator, the osmosis mask was designed\n\
to help protect explorers in the distant region of the Flame\n\
Forest. It attaches securly to a Power Ranger Helmet.\n\
A filtering cartridge is attached around\n\
the mouth and nose area.  Wide fabric bands are used to\n\
attach the mask into place.\n\
The mask does impare a rangers view somewhat though, so you may not\n\
be able to see enemy attacks as easily.\n");
   return 1;
}


int
DefSkill(int level)
{
  if(!Rangers) Rangers = ({});
  if(member_array(environment(previous_object())->query_real_name(),
    Rangers) >= 0)
  {
    return -2;
  }   
  else
    return 0;
}