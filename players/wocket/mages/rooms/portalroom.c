#include "../defs.h"
#define PATH ROOMDIR
inherit ROOM;

string long1,long2;

string destination;
int portal;

void reset(int arg) {

  if(arg) return;
  set_light(1);
  is_pk = 1;
  add_property("no_teleport");
  short_desc=BOLD+CYN+"The Portal Annex"+NORM;
  long1=
"   Ancient echoes bounce off the sandstone walls of this vaulted\n\
chamber.  Glowing sigils and runes are embedded in the five pillars\n\
that lend additional support to the ceiling.  A dozen tiered steps\n\
lead up to a marble archway, standing alone and empty.  At the bottom\n\
of the steps is a sandstone tablet sitting atop a marble pedestal. An\n\
archway leads north, back to the great hall.\n";
  long2=
"   Ancient echoes bounce off the sandstone walls of this vaulted\n\
chamber.  Glowing sigils and runes are embedded in the five pillars\n\
that lend additional support to the ceiling.  A dozen tiered steps\n\
lead up to an "+BOLD+CYN+"azure portal"+NORM+".  At the bottom of the steps is a sand-\n\
stone tablet sitting atop a marble pedestal. An archway leads north,\n\
back to the great hall.\n";
  long_desc=long1;
  dest_dir=({
    PATH+"guildhall","north",
  });
  items=({
    "walls","Sandstone walls, standing proud and unadorned",
    "chamber",long_desc,
    "sigils","You believe the sigils and runes are designed to ward the\n"+
             "rest of the guildhall from any demonic invaders who might\n"+
             "seek to enter through here",
    "runes", "You believe the sigils and runes are designed to ward the\n"+
             "rest of the guildhall from any demonic invaders who might\n"+
             "seek to enter through here",
    "pillars","Huge sandstone pillars, easily a meter in diameter, and embedded\n"+
              "with elaborate runes and sigils",
    "ceiling","You spend a few moments staring at the ceiling, appreciating its\n"+
              "remarkable ability to not fall on you",
    "steps","The steps resemble a flattened pyramid, with a flat spot, three meters\n"+
            "square at the top",
    "tablet","It is a sandstone tablet with a few words of wisdom engraved upon it",
    "pedestal","A simple pedestal, made out of ivory white marble mottled with grey",
    "archway","The archway leads back to the guildhall",
  });
}
long(str) {
  if(str=="portal" || str=="azure portal")
    if(portal) write(
"This is a pulsing rectangle of azure light standing\n"+
"perpendicular to the ground, half a dozen paces wide\n"+
"and half again the height of a grown man.  You could\n"+
"enter it if you chose.\n");
    else write("There is no portal here.\n");
  else ::long(str);
}

int GUILD_PK() { return 1; }

void init() {
  ::init();
  add_action("cmd_read","read");
  add_action("cmd_intone","intone");
  add_action("cmd_enter","enter");
}
    

int cmd_read(string str) {
  notify_fail("What would you like to read?\n");
  if(!str || str!="tablet") return 0;
  write("\n\
The tablet offers the following advice:\n\n\
Know ye who reads this, that among the finest artifacts in the land\n\
is this chamber, through which ye may find yourself travelling through\n\
vast distances in an eyeblink.  Simply '"+BOLD+"intone"+NORM+"' one of the following\n\
incantations to summon an azure portal:\n\n\
\tVillage green\t mortan dani\n\
\tPost Office  \t tanlok tsi\n\
\tClock Tower  \t disa mina\n\
\tShrine       \t felda nola\n\
\tAngel Statue \t wocka ktar\n\
  \n\n");
  return 1;
}
int cmd_intone(string str) {
  string new_dest;
  notify_fail("What would you like to intone?\n");
  if(!str) return 0;
  switch(str) {
    case "mortan dani":
    case "morten dani":
      new_dest="/room/vill_green";
      break;
    case "tanlok tsi": 
    case "tanlek tsi": 
      new_dest="/room/post";
      break;
    case "disa mina":
    case "disa mine":
      new_dest="/room/vill_road3";
      break;
    case "felda nola":
    case "felde nola":
      new_dest="/players/feldegast/shrine";
      break;
    case "wocka ktar":
    case "wocka kter":
    case "wocka kar":
      new_dest="/room/south/sforst45";
      break;
    default: 
      while(!(new_dest=(string)call_other("obj/base_tele","teleport"))) ;
  }
  write("You carefully intone, \""+str+"\"\n");
  say(this_player()->query_name()+" carefully intones, \""+str+"\"\n");
  while(remove_call_out("open_portal")!=-1) ;
  while(remove_call_out("change_portal")!=-1) ;
  if(!destination) {
    destination=new_dest;
    if(this_player()->query_sp() < 10) {
      write("You do not have enough magical energy.\n");
      return 1;
    }
    else this_player()->add_spell_point(-10);
    call_out("open_portal",1);
    return 1;
  }
  if(destination!=new_dest) {
    if(this_player()->query_sp() < 10) {
      write("You do not have enough magical energy.\n");
      return 1;
    }
    else this_player()->add_spell_point(-10);
    call_out("change_portal",1,new_dest);
    return 1;
  }
  tell_room(this_object(),"Nothing happens.\n");
  return 1;
}
void open_portal() {
  tell_room(this_object(),
"An "+BOLD+CYN+"azure portal"+NORM+" rises up out of the ground.\n");
  portal=1;
  long_desc=long2;
}
void change_portal(string new_dest) {
  tell_room(this_object(),
"The "+BOLD+CYN+"azure portal"+NORM+" sinks back into the ground.\n");
  portal=0;
  destination=new_dest;
  long_desc=long1;
  call_out("open_portal",1);
}

cmd_enter(str) {
  notify_fail("What would you like to enter?\n");
  if(!str) return 0;
  if(str!="portal" && str!="azure portal") return 0;
  if(!portal) return 0;
  say(this_player()->query_name()+" steps into the "+BOLD+CYN+"azure"+NORM+" portal.\n");
  write("You step through the "+BOLD+CYN+"azure"+NORM+" portal.\n");
  move_object(this_player(),destination);
  say(this_player()->query_name()+" steps into the room through an "+BOLD+CYN+"azure"+NORM+" portal.\n");
  command("look",this_player());
  return 1;
}
