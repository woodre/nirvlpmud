#pragma strict_types
#include <ansi.h>
#include <security.h>
#include "../RangerDefs.h"

status
RangerPower(string msg, string channel)
{
  object *rangers;
  object person;
  string type;
  int i;
  rangers = (array) CHANNEL->on_channel(channel);
  write("\n");
  write("============================ The "+channel+"s ======================================\n");
  write("\n");
  write(pad("Level",7)+
        pad("M",2)+
        pad("Name",17)+
        pad("Color",15)+
        pad("Type",15)+
        pad("Btl?",5)+
        pad("Place",45));
  write("\n");
  write("\n");
  for( i = 0; i<sizeof(rangers); i++)
  {
    person = 0;
    if(rangers[i])
      if(rangers[i]->id("ranger_locator") || rangers[i]->id("ranger_camera"))
        person = rangers[i];
      else
        person = environment(rangers[i]);
    if(person)
    {
      if(person->query_npc() && !environment(person)) continue;
      if(person->query_invis() < SOMEONE)
      {
        write(pad(person->is_player() ? (string) person->query_level() :
              "?? ",3));
        if(person->query_extra_level() > 0)
          write(pad(person->is_player() ? "+"+
                person->query_extra_level() : "  ",4));
        else
          write(pad("  ",4));
        if(previous_object())
          write(pad(rangers[i]->QMuffles() ? "*" : " ",2));
        else
          write(pad(" ",2));
        write(pad( (string) person->query_name(),17));
        if(previous_object())
          write(rangers[i]->QRangerAnsi());
        if(previous_object())
          write(pad(rangers[i]->COLOR+OFF,19));
        write(OFF);
        if(previous_object())
        {
          write(pad( (string) rangers[i]->query_ranger_type(),15));
          write(OFF);
        }
        else
          write(pad("Enemy",15));
        write(pad(person->query_attack() ? "Yes" : "No",5));
        if(previous_object())
        {
          if(previous_object()->QuerySkillLevel("communication") > 2 ||
             environment(previous_object())->query_level() > EXPLORE)
          {
            if(!person->query_invis()  ||
                person->query_total_level() <=
                  environment(previous_object())->query_total_level() ||
                person->query_level() < SOMEONE)
            {
               if(environment(person))
               /* check added 6.11.01 by verte, else statement also written */
               {
                  write(environment(person)->short());
                  write(OFF);
               }
               else
                write("Logging In\n");
               write("\n");
            }
            else
               write("Unknown\n");
          }
        }
      }
    }
  }
  write("\n");
  write("======================================================\
===============================\n");
  return 1;
}

status
QRangerInfo() { return 1; }

status
RangerInfo()
{
  write(format("\
  The Power Ranger Guild has a special shared guild channel that is used by \
both Power Rangers and the Honorary Power Rangers. The 'rwho' command allows \
Power Rangers and Honorary Power Rangers to see who is on the channel and some \
of the information about them. If Power Rangers have their Communication skill \
trained to 3 or higher, they can also view information about where members of \
the channel are located. If players are invisible, they will still show up on \
the channel but their location will be unknown unless you are of a greater \
level."));
  return 1;
}
