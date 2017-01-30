#include "/players/fred/defs.h"
#include "/players/fred/ansi.h"
inherit "obj/monster";
#define ON owner->query_name()
#define MEAT TO->query_attack()
#define MEATN MEAT->query_name()
string *poop,poof;
object owner;
int craps;
 
reset(arg)
{
  ::reset();
  if(arg) return;
  set_race("human");
  set_level(5);
  set_wc(9);
  set_ac(5);
  set_gender("female");
  set_hp(75);
  set_ep(1);
  set_dead_ob(this_object());
  set_can_kill(1);
  poop = ({"sandy","cindy","nikki","angela","mary","carla","barb","tammy","tina","susie",
           "brenda","nancy","bridgette","lisa","holly","jen","jenny","kalie","brittany",
           "sara","daphne","erin","grace","heidi","marta","nina","noel","patty","diane",
           "bobbi","lynn","jessie","april","heather","becky","courtney","dana","meagan",
           "lita","marcy","toni","tanya","janet","stephanie","terry","kathy","sheila"});
  set_name(snarf());
}

id(str)
{
  return str == poof || str == "fan" || 
         str == "human" || str == "bf_fan" ||
         str == "bf_person_four";
} 

snarf()
{
  int x,y;
  x = sizeof(poop);
  y = random(x - 1);
  poof = poop[y];
  return poof;
}
     
short()
{
  if(owner)
    return capitalize(poof)+", one of "+ON+"'s adoring fans";
  return capitalize(poof)+", someone's adoring fan";
}  

long()
{
  if(owner)
  {
    write("This is one of "+ON+"'s adoring fans.  "+capitalize(poof)+"'s only purpose\n"+
          "in life is to follow "+ON+" around and shower him with\n"+
          "compliments.  Kind of sad don't you think?\n");
  }
  else
  {
    write("This is someone's adoring fan.  "+capitalize(poof)+"'s only purpose\n"+
          "in life is to follow someone around and shower him with\n"+
          "compliments.  Kind of sad don't you think?\n");
  }
}

patch_owner(o)
{ 
  owner = o; 
}

query_owner()
{ 
  return owner; 
}

heart_beat()
{
  ::heart_beat();
  if(!environment()) return;
  if(!owner) return;
  if(owner && owner->query_ghost() && (craps < 1))
  {
    tell_room(environment(TO),
      capitalize(poof)+" looks down at the lifeless body of her beloved "+ON+" and lets out a shrill scream.\n");
    craps = 1;
    call_out("grief", 4);
  }
  if(owner && !owner->query_ghost())
  {
    if(ENV(TO) != ENV(owner))
    {
      say(capitalize(poof)+" races after "+capitalize(owner->query_name())+".\n");
      MO(TO, ENV(owner));
      say(capitalize(poof)+" races in after "+capitalize(owner->query_name())+".\n");
      set_heart_beat(1);
    }
    if(!random(15) && MEAT && MEATN != ON)
    {
      int woo;
      string ding;
      woo = random(5);
      switch(woo)
      {
        case 0: ding = "Knock it off!"; break;
        case 1: ding = "Leave us along, he's mine."; break;
        case 2: ding = "He doesn't like you, He likes me..."; break;
        case 3: ding = "Why don't you go back to work at the corner!"; break;
        case 4: ding = "Get away from us!"; break;
        case 5: ding = "Hey, leave my man alone!"; break;
        case 6: ding = "Stop it!"; break;      
        case 7: ding = "Back off hussy!"; break;
      }
      tell_room(environment(TO),
        capitalize(poof)+" yells at "+MEATN+" \""+ding+"\"\n");
    }
    if(!random(15) && MEAT && MEATN == ON)
    {
      int heh;
      string hungry;
      heh = random(6);
      switch(heh)
      {
        case 0: hungry = "Don't you love me anymore?"; break;
        case 1: hungry = "Why are you doing this to me?"; break;
        case 2: hungry = "Why won't you let me love you?"; break;
        case 3: hungry = "Please stop, I need you."; break;
        case 4: hungry = "Why can't we just be together?"; break;
        case 5: hungry = "I thought you loved me..."; break;
      }
      tell_object(owner,
        capitalize(poof)+" cries out to you, \""+hungry+"\"\n");
      tell_room(enviroment(TO),
        capitalize(poof)+" cries out to "+ON+" \""+hungry+"\"\n", ({ owner })); 
    }   
    if(!random(30))
    {
      int x;
      string what;
      x = random(20);
      switch(x)
      {
        case 0:  what = "handsome"; break;
        case 1:  what = "strong"; break;
        case 2:  what = "muscular"; break;
        case 3:  what = "wonderful"; break;
        case 4:  what = "great"; break;
        case 5:  what = "dapper"; break;
        case 6:  what = "breath taking"; break;
        case 7:  what = "fine"; break;
        case 8:  what = "robust"; break;
        case 9:  what = "virile"; break;
        case 10: what = "charming"; break;
        case 11: what = "dazzling"; break;
        case 12: what = "athletic"; break;
        case 13: what = "magnificent"; break;
        case 14: what = "impressive"; break;
        case 15: what = "noble"; break;
        case 16: what = "majestic"; break;
        case 17: what = "good-looking"; break;
        case 18: what = "stylish"; break;
        case 19: what = "enticing"; break;
      }
      tell_object(owner, capitalize(poof)+" says to you, \"Oh "+owner->query_name()+" you're so "+what+"!!\"\n");
      tell_room(environment(owner), capitalize(poof)+"exclaims, \"Oh "+owner->query_name()+" you're so "+what+"!!\"\n", ({ owner }));
    }
    if(!random(40))
    {
      int y;
      string huh;
      y = random(10);
      switch(y)
      {
        case 0: huh = "shrieks"; break;
        case 1: huh = "faints"; break;
        case 2: huh = "looks flustered"; break;
        case 3: huh = "winks"; break;
        case 4: huh = "squeals"; break;
        case 5: huh = "wiggles her bottom"; break;
        case 6: huh = "blows a kiss"; break;
        case 7: huh = "giggles softly"; break;
        case 8: huh = "smiles happily"; break;
        case 9: huh = "tries tp look innocent"; break;
      }
      tell_object(owner, capitalize(poof)+" looks at you and "+huh+".\n");
      tell_room(environment(owner), capitalize(poof)+" looks at "+owner->query_name()+" and "+huh+".\n", ({ owner }));
    }
    if(!random(5) && !MEAT)
    {
      object a,b,c;
      tell_room(environment(owner),
        capitalize(poof)+" looks around for any threats.\n");
      a = first_inventory(environment(TO));
      while(a)
      {
        b = next_inventory(a);
        if(a->query_bf_mob())
        {
          tell_room(environment(owner),
            capitalize(poof)+" screams in a jealous rage and attacks "+a->query_name()+"!\n");
          attacker_ob = a;
        }
        a = b;
      }
    }
  }
}

grief()
{
  tell_room(environment(TO),
    "Large tears begin to well up in "+capitzlie(poof)+"'s eyes.\n");
  call_out("grief2", 5);
}

grief2()
{
  tell_room(environment(TO),
    Capitlize(poof)+" sighs and says, \"I no longer have any reason to go on in life.\"\n");
  call_out("grief3", 5);
}

grief3()
{
  tell_room(environment(TO),
    "With one last final glance at "+ON+" "+capitalize(poof)+" runs out of the room to go kill herself.\n");   
  move_object(TO, "/room/void");
  destruct(TO);
}

