#include "/players/fred/closed/bloodfist/defs.h"
#define ME "Seht Deyad"
#define SPC "                 \""
#define NM capitalize((string)me->query_real_name())
#define ONE_DAY 86400
object me, gob;
int cnt;

short(){ return 0; }
id(str){ return str == "bf_join_ob"; }

drop(){              return 1; } 
get(){               return 0; }
can_put_and_get(){   return 0; }

void init(){
  add_action("yes_no", "eahtpieh2pjH235zwh");
}

int checks()
{
  if(!me) return 1;
  if(!me->query_interactive()) return 1;
  return 0;
}

void dest(){ destruct(this_object()); }

void join4()
{
  if(checks()){ dest(); return; }
  tell_object(me,  "\n"+
    ME+" says, \"Head north into the ravine to get to the encampment. I\"\n"+
    SPC+"am going to stay here and guard the entrance.  If you have any\"\n"+
    SPC+"questions, look at the help files (bfhelp) or talk to other\"\n"+
    SPC+"people in the guild.  Good luck "+NM+", glad to have you.\"\n");
  gob = clone_object("/players/fred/closed/bloodfist/gob.c");
  move_object(gob, me);
  me->set_guild_name("bloodfist");
  /*
  gob->set_trail_period(time() + (7 * ONE_DAY));
  */
  gob->set_guild_age(time());
  gob->add_endurance(500);
  me->save_me();
  me->reset();
  call_out("dest", 4);
}


void join3()
{
  if(checks()){ dest(); return; }
  tell_object(me,
    "\n"+ME+" says, \"Here, take this, you'll need it.\n\n"+
    ME+" hands you a blood crystal.\n");
  call_out("join4", 9);
}

void join2()
{
  if(checks()){ dest(); return; }
  tell_object(me,
    "\n"+ME+" drags his knife across your hand making an X.\n");
  me->hit_player(((int)me->query_hp() - 20), "other|zeus");
  call_out("join3", 8);
}

void join()
{
  if(checks()){ dest(); return; }
  cnt = 3;
  command("eahtpieh2pjH235zwh", me);
  tell_room(environment(me), 
    "\n"+ME+" says, \"Alright, this will hurt a bit.\"\n");
  tell_object(me, 
    ME+" takes a dagger from his belt and grabs your left hand.\n");
  call_out("join2", 12);
}

void sit3()
{
  if(checks()){ dest(); return; }
  cnt = 2;
  tell_object(me, "\n"+ME+" says, \"So, are you sure you want to join the Bloodfist?\"\n"+
    "\t<Yes or No>\n");
  command("eahtpieh2pjH235zwh", me);
}

void sit2()
{
  if(checks()){ dest(); return; }
  tell_object(me,
    ME+" says, \"If you join, you can look around for awhile and see\"\n"+
    SPC+"what you think of things.  If you don't like it and don't\"\n"+
    SPC+"think it's right for you, come back to me and\"\n"+
    SPC+"type 'leave_bloodfist'.\"\n");
  call_out("sit3", 10);
}

void situation()
{
  if(checks()){ dest(); return; }
  tell_object(me,
    ME+" says, \"Okay "+NM+", here is where we stand right now.\"\n"+
    SPC+"We need new members.  We've lost a lot of great\"\n"+
    SPC+"warriors lately to raids by the desert fiends,\"\n"+
    SPC+"plus we only just recently found a good supplier\"\n"+
    SPC+"of water.\n\n");
  call_out("sit3", 12);
}

void yes_no_a(string str)
{
  if(str == "y" || str == "yes" || str == "nod" || str == "Y" || str == "Yes")
  {
    if(cnt == 2)
      join();
    else
      situation();
  }
  else {
    tell_object(me, ME+" says, \"Well then leave me alone.\"\n");
    destruct(this_object());
  }
}

status yes_no(){  
  if(cnt == 3)
  {
    string gr;
    HONOR_DAEMON->add_member((gr = (string)this_player()->query_real_name()));
    write_file("/players/fred/closed/bloodfist/log/join",
      ctime()[4..15]+" "+pad(gr, 13)+"["+this_player()->query_level()+
      "+"+this_player()->query_extra_level()+"]\n");
  }
  else 
    input_to("yes_no_a");  
  return 1; 
}

void begin(object who){  me = who;  }
