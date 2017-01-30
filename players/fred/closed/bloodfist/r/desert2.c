inherit "players/fred/closed/bloodfist/obj/desert_inherit";
#include "/players/fred/closed/bloodfist/defs.h"
object npc, trs, here;
int b;

reset(arg){
  if(arg) return;

  b = 2;
  long_desc=
"  You have come to some sort of graveyard.  Bones are scattered\n"+
"all across the sands here.  Many protrude a few feet from the ground,\n"+
"and end with sharp, broken off points.  The bones are all bleached\n"+
"white, showing their age.  The wind blows quickly through the desert.\n"+
"The sky above is black and ominous, and the desert is dark.\n"+
"    There is one obvious exit: leave\n";
  items=({
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
  "bones",
"The area is scattered with many bleached white bones.  Some of them\n"+
"are cracked and broken, others look to be in very good shape.  Many\n"+
"are covered in sand, however some protrude from the ground as though\n"+
"they are trying to escape",
  });
}

void init(){
  ::init();
  add_action("search", "search");
}

void atk(object r)
{
  if(environment(npc) == environment(r))
    npc->attack_object(r);
}

void arrv(object r)
{
  tell_room(here, "A spirit says, \"Noooo.......\"\n");
  npc = clone_object(DIR+"NPC/kasimir.c");
  move_object(npc, here);
  call_out("atk", 2, r);
  b = 1;
}

status search(string str)
{
  if(str != "bones" && str != "graveyard" && str != "area" && str != "sand")
    return (notify_fail("You search the area briefly and find nothing.\n"), 0);
  if(b == 2)
  {
    write("You search through the bones...\n");
    say(this_player()->query_name()+" searches through the bones...\n");
    call_out("arrv", 1, this_player());
    b = 3;
    here = this_object();
    return 1;
  }
  else if(present("spirit of kasimir"))
    return (notify_fail("A spirit says, \"Noooo.......\"\n"), 0);
  else if(b == 1){
    write("You search through the bones and discover some treasure.\n");
    say(this_player()->query_name()+" searches through the bones.\n");
    trs = clone_object(DIR+"obj/purse.c");
    move_object(trs, this_object());
    trs->set_value(9000+random(2000));
    trs = clone_object(DIR+"obj/scarab.c");
    move_object(trs, this_object());
    b = 0;
    return 1;
  }
  else if(b == 0)
    return (notify_fail("You search the bones and find nothing.\n"), 0);
  return 0;
}
