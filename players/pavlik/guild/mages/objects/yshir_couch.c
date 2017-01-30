#include "/players/pavlik/guild/mages/defs.h"

object seated;

reset(arg) {
  if(arg) return;
  seated = 0;
}

id(str)
{
  return str == "couch";
}

short(){ 
  if(!seated) return "A plush couch [empty]";
  else return "A plush couch ["+seated->query_real_name()+"]";
}

long(){
  if(environment(this_player()) != this_object())
    write(
	"A fine plush couch invites you into its comfortable cushions.  The soft pillows\n"+
	"are made of fine silk and inlaid with intricate golden weavings.  Although the\n"+
	"couch is obviously a priceless artifact, you feel welcome to "+HIY+"sit"+NORM+" upon it.\n");
  else
    write(
	"You are stretched out comfortably on Yshir's couch.  Your mind drifts aimlessly\n"+
	"as your body is able to relax so completely.  You know you can "+HIY+"stand up"+NORM+" at\n"+
	"any time, so there is no hurry to leave the comfort of the couch.\n");
  return;
}

query_value(){ return 0; }
query_weight(){ return 999; }

set_seated(ob){ seated = ob; }
query_seated(){ return seated; }

init(){
  if(seated != 0 && !present(seated, this_object())) seated = 0;
  if(environment(this_player())==this_object()) {
    clear_intruder();
    add_action("stand_up","stand");
    add_action("stand_up","wake");
    add_action("say_it","say");
    add_action("not_now","quit");
#ifndef __LDMUD__
    add_action("say_it"); add_xverb("'");
#else
    add_action("say_it", "'", 3);
#endif
  }
  else {
    add_action("sit_couch","sit");
  }
}


say_it(str)
{
  string what, junk;

  if(!sscanf(str, "train %s", junk)==1 &&
     !sscanf(str, "teach %s", junk)==1)
  {
	write("You mumble something in a sleepy voice.\n");
	tell_room(environment(this_object()),
		ME+" mumbles something in "+PO+" sleep.\n");
	return 1;
  }

  write("You say: "+str+"\n");
  say(ME+" says: "+str+"\n");
  return 1;
}


clear_intruder()
{
  if(!this_player()->is_player()) return 1;
  if(!seated)
  {
	move_object(this_player(), ROOM_DIR+"yshir_room");
	return 1;
  }
  if(this_player() != seated)
  {
	move_object(this_player(), ROOM_DIR+"yshir_room");
	return 1;
  }
}


stand_up()
{
  write(
    "Regretfully you "+HIW+"wake"+NORM+" your body and stand up from the couch.  As your mind\n"+
    "becomes more awake Yshir "+HIBLK+"slowly dissolves"+NORM+" from sight.  You stand up fully\n"+
    "conscious and refreshed.\n"+
    "There is no sign of Yshir.\n");
  write("You wonder if maybe she was just a dream ... \n");

  move_object(this_player(), ROOM_DIR+"yshir_room");
  say(ME+" wakes and stands up from the couch.\n");
  seated = 0;

  if(present("yshir", this_object()))
	destruct(present("yshir", this_object()));

  return 1;
}


sit_couch()
{
  if(seated)
  {
	write("There is already someone on the couch.\n");
	return 1;
  }

  write("\n"+
    "You sit down and make yourself comfortable on the couch...\n"+
    "You float aimlessly on the verge of sleep.  Your eyelids seem so very heavy\n"+
    "and the cushions of Yshir's couch slide out from under your body as you effortlessly\n"+
    "drift away into sleep.\n");
  write("\n"+
    "A "+HIW+"beautiful woman"+NORM+" materializes before you.  She is dressed in a blue and gold gown\n"+
    "that swishes quietly as she walks.\n"+
    BLU+"Yshir"+NORM+" says:  "+HIY+"Greetings Mage"+NORM+".\n\n");

  say(ME+" lays down on the couch and instantly feels asleep.\n");

  seated = this_player();
  move_object(this_player(), this_object());

  if(!present("yshir", this_object()))
	move_object(clone_object(NPC_DIR+"yshir"), this_object());

  return 1;
}


not_now()
{
  write("Perhaps you should stand up first?\n");
  return 1;
}


realm(){ return "NT"; }

