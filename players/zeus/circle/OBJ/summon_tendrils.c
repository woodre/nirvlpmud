#include "/players/zeus/circle/defs.h"

static int tick;

id(str) { return str == "summon_tendrils"; }

drop() { return 1; }

get()  { return 1; }

reset(x)
{
   if(x) return;
   if(!root())
   call_out("tick",8 + random(3));
}

init()
{
#ifndef __LDMUD__
  add_action("cmd_hook"); add_xverb("");
#else
  add_action("cmd_hook", "", 3);
#endif
}

cmd_hook(str)
{
   if(this_player()->query_real_name() == "zeus" ||
      this_player()->query_real_name() == "forbin") return 0;
  if(str != "sc" && str != "score" && str != "mon")
  {      
     tell_object(USER, "You are meditating... be at peace.\n");
     return 1;
  }
}

void tick()
{
  object sf;
  int tend;

  tick += 1;
  if(tick > 5)
  {
  	tell_object(USER,
          "\nYou slowly rise.  You feel drained and tired.\n\n");
  	tell_room(environment(USER),
  	  (string)USER->QN+" slowly rises.\n", ({ USER }));
  	destruct(this_object());
  }
  if(tick > 4)
  {
  	tell_object(USER,
  	  "\nOn your hands and knees, you wretch violently as the shadows squirm their\n"+
  	  "way into your mouth, gagging as they snake their way inside.  You feel\n"+
  	  "feel a warm presence...\n"+
	"And then nothing...\n\n");
    tell_room(environment(USER),
      (string)USER->QN+" lies on the ground, wretching in pain and agony as\n"+
      "dark shadows swarm over "+(string)USER->noun()+".\n", ({ USER }));
  	USER->hit_player(50 + random(50), "other|zeus");
    if(USER->query_ghost())
    {
      destruct(this_object());
      return; 
    }  
    sf = clone_object("/players/zeus/circle/OBJ/shadow_tendrils.c"); 
    sf->set_tendrils(5 + random(6));
    move_object(sf, USER);
    USER->RegisterArmor(sf, ({ "physical", 0, 0, "tendrils" }));
    USER->RegisterArmor(sf, ({ "other|light", 0, (8 + random(5)), "" }));
    USER->RegisterArmor(sf, ({ "other|dark", 0, (8 + random(5)), "" }));
    move_object(clone_object("/players/zeus/circle/OBJ/zero_end_ob.c"), USER);
  }
  else if(tick > 3)
  {
    tell_object(USER,
  	  "\nThe shadows reach your feet and begin to crawl up your body, starting with\n"+
  	  "your legs, then encircling your torso, then reaching your extremities, and\n"+
  	  "finally swirling about your head. You clutch you chest as an excruciating\n"+
  	  "pain grips you and drops you to your knees.\n\n");
    tell_room(environment(USER),
      "Shadows slither about "+(string)USER->QN+", crawling over "+
      (string)USER->query_possessive()+" body.\n"+
      (string)USER->QN+" drops to the ground.\n", ({ USER }));
    USER->hit_player(100 + random(50), "other|zeus");
    if(USER->query_ghost())
    {
      destruct(this_object());
      return; 
    }        
  }
  else if(tick > 2)
  {
  	tell_object(USER,
  	  "\nThere is a tremendous flash of light from the hole.  You quickly glance\n"+
  	  "down and notice the piece of obsidian is gone.  In it's place, dark\n"+
  	  "shadows pour from the hole, snaking their way towards you.\n\n");
    tell_room(environment(USER),
      "There is a tremendous flash as shadows pour from the ground.\n", ({ USER }));
  }
  else if(tick > 1)
  {
    tell_object(USER,
      "\nYou slowly rise, outstreaching your arms and casting your gaze skyward.\n"+
      "With a slow groan, you feel the ground tremble beneath your feet...\n\n");
    tell_room(environment(USER),
      "The ground beneath you begins to shake.\n", ({ USER }));
  }
  else
  {
    tell_object(USER,
      "\nYou meticulously begin to pour glowing liquid onto the obsidian,\n"+
      "carefully tracing a familiar shape, the Fifth Symbol, with its\n"+
      "shimmering stream.\n"+
      "You continue to chant an ancient incantation...\n\n");
    tell_room(environment(USER),
      (string)USER->QN+" pours a glowing liquid upon the ground while\n"+
      "chanting in a strange language.\n", ({ USER }));
  }
  call_out("tick", 8 + random(3));
}
