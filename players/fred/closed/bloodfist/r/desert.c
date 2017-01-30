inherit "room/room";
#include "/players/fred/closed/bloodfist/defs.h"
object npc, *all;
string *enpc;
int odds,j,a;

reset(arg){
  if(arg) return;

  j = 0;

  enpc = ({ 
    "/players/zeus/desert/NPC/digger.c",
    "/players/zeus/desert/NPC/fiend.c",
    "/players/zeus/desert/NPC/spirit.c",
    "/players/zeus/desert/NPC/scorpion.c",
    "/players/zeus/desert/NPC/desert_bat.c",
  });

  add_property("no_teleport");

  set_light(0);
  items =({
  "sky",
"The sky is a luminous mass of dark swirls.  The wind causes it to\n"+
"constantly writhe and shift above you",
  "wind",
"The wind is blowing all around you, blowing the sand which obscures\n"+
"your vision",
  "sand",
"Bits of sand writhe at your feet, as well as fly past your face.  The\n"+
"wind which never seems to stop makes the sand almost seem alive",
  "ground",
"The ground seems so lifeless and dead.  It is hard and flat, lined with\n"+
"dry cracks which run ever so deep.  Life does not seem to have existed\n"+
"here for ages",
  "rocks",
"Small rocks are littered across the ground, mingling with the sand",
  "ground",
"The ground is a mixture of both sand and dry, flat rock",
  "rock",
"The ground is a mixture of both sand and dry, flat rock",
  "mountains",
"It appears as though there are mountains far off to the east",
  });

}

short(){ return "inculta creperum"; }

long(str)
{
  int i;
  if ((set_light(0) <= 0) && !present("dark_sight_object", this_player()))
     return(notify_fail("It is dark.\n"), 0);
  if(!str)
  {
    switch(j)
    {
    case 0:
      long_desc =
"  You are somewhere out in the desert, although it is impossible to tell\n"+
"exactly where.  Sand stretches out for what seems like miles in every\n"+
"direction.  Your vision is obscured by the darkness and by the blowing\n"+
"sands which makes it even more difficult to see.  Off in the distance to\n"+
"the east you seem to be able to make out some mountains.\n";
      break;
    case 1:
      long_desc =
"  The warmth of the desert presses down on you here like a thick blanket.\n"+
"Darkness clouds the sky, making it difficult to see very far in any\n"+
"direction.  The wind is blowing strong, kicking sand into the air.  Off\n"+
"in the distance to the east the outline of mounatains is occasionally\n"+
"visible.\n";
      break;
    case 2:
      long_desc = 
"  From where you are sand seems to stretch on for miles in every\n"+
"direction.  It is difficult to tell because of the darkness and\n"+
"the blowing sands, but it looks as though there are mountains off\n"+
"in the distance to the east.\n";
      break;
    case 3:
      long_desc =
"  It is incredibly hot here in the desert.  The ground is a mixture of\n"+
"loose sand and dry, hard rock.  The wind is blowing strong, constantly\n"+
"kicking sand into the air.  Overhead the sky is a mass of swirling\n"+
"darkness.  It appears as though there are mountains to the east.\n";
      break;
    }
    long_desc +=
"    There are eight obvious exits: north, northeast, east, southeast,\n"+
"south, southwest, west and northwest\n";
    write(long_desc);
  }
  if(!items)
	  return;
  i = 0;
  while(i < sizeof(items))
  {
	  if(items[i] == str)
    {
	    write(items[i+1] + ".\n");
      return;
    }
	  i += 2;
  }
}

void init(){
  ::init();
  add_action("move_dir", "north");
  add_action("move_dir", "northeast");
  add_action("move_dir", "east");
  add_action("move_dir", "southeast");
  add_action("move_dir", "south");
  add_action("move_dir", "southwest");
  add_action("move_dir", "west");
  add_action("move_dir", "northwest");
}

int move_me(object who, string where)
{
  move_object(who, "/room/void.c");
  this_player()->move_player(where);
  return 1;
}

int move(object who, string dir)
{
  j = random(4);
  if(dir == "leave")
    return (move_me(who, "across the desert#"+DIR+"r/desert.c"));
  all = all_inventory(this_object());
  if(!who->query_ghost())
  {
    for(a = 0; a < sizeof(all); a++)
    {
      if((npc = all[a])->id("zeus_inculta_npc"))
      {
        tell_room(environment(who),
          "Your path is blocked by "+npc->short()+".\n");
        npc->attack_object(who);
        return 1;
      }
    }
  }
  tell_object(who, "You walk "+dir+" across the desert...\n");
  tell_room(environment(who), capitalize((string)who->query_real_name())+
    " walks "+dir+" across the desert...\n", ({ who }));
  odds = 2 + random(5);
  if((string)who->query_guild_name() == "bloodfist" ||
     (string)who->query_guild_name() == "dervish")
    odds -= 1;
  if(!who->query_ghost() && (int)who->query_level() < 20)
  {
    who->hit_player(odds, "other|zeus");
    if(!random(5))
    {
      npc = clone_object(enpc[random(sizeof(enpc))]);
      npc -> set_wc(36);
      npc -> set_ac(16);
      tell_room(environment(who),
        "Your path is blocked by "+npc->short()+".\n");
      move_object(npc, this_object());
      npc -> attack_object(who);
      return 1;
    }
    else if((npc = (object)who->query_attack()))
      return (notify_fail("Your path is blocked by "+npc->short()+".\n"), 0);
  }
  if(dir == "east" && random(odds) <= 0)
    return (move_me(who, dir+"#/players/zeus/desert/r/ec9.c"));
  else if(dir == "northwest" && random(odds) <= 0)
    return (move_me(who, dir+"#"+DIR+"r/desert1.c"));
  else if(dir == "west" && random(odds) <= 0)
    return (move_me(who, dir+"#"+DIR+"r/desert2.c"));
  return 1;
}

int move_dir(){ return (move(this_player(), query_verb())); }

