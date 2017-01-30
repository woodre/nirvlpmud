#include "/players/pavlik/guild/mages/defs.h"
inherit "/players/pavlik/guild/mages/inherit/room";
inherit "room/room";

#define WIN capitalize(winner->query_real_name())
#define LOS capitalize(loser->query_real_name())

int COMBAT;
object m1, m2;

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The War Room";
  long_desc=
	"                 T h e  W A R  R o o m                       \n"+
	"The War Room is a large rounded chamber with dense magically-\n"+
	"enchanced walls.  The War Room is a proving ground for Mages.\n"+
	"In here Two Mages can fight it out to determine who is the\n"+
	"better.  There is a scroll containing the rules of combat next\n"+
	"to the door.\n";

  items=({
    "scroll",
	HIM+"  *     *   *  * * *** The WAR Room *** * *  *   *     *\n"+NORM+
	"This chamber was created so that Mages may test their magical\n"+
	"prowness agaisnt one another in One_on_One combat.  The winner\n"+
	"of the dual will be rewarded, the loser penalized.  The award is\n"+
	"donation points.  The loser will lose donation points, however no\n"+
	"experience is lost (lose of attributes WILL still occur).\n"+
	"The avaliable commands are:\n"+
	HIM+"Duel <player>"+NORM+" - challenge another to a duel.\n"+
	HIM+"Mercy"+NORM+" - Forfeit a duel before you are killed.\n"+
	HIM+"Revive"+NORM+" - MUST be used by someone 'killed' in a duel.\n"+
	"\n"+
	"The rules are simple: WIN",
  });

  dest_dir=({
	ROOM_DIR+"party_room",		"out",
  });

  COMBAT = 0;

}

query_mguild(){ return "War Room"; }
realm(){ return "NT"; }
query_arena(){ return 1; }
query_spar_area(){ return 1; }
query_combat(){ return COMBAT; }


init(){
 ::init();
  add_action("wuss","out");
  add_action("big_balls","duel");
  add_action("chicken_shit","mercy");
  add_action("sucker","make_reply");
  add_action("you_loser","revive");
  add_action("no_way_jose","quit");
}

loser_check(){
  if(!m1->query_interactive() || !m2->query_interactive()){
    tell_room(this_object(),
    "Disconnected - The duel is ended prematurely.\n");
    m1->stop_fight();
    m2->stop_fight();
    COMBAT = 0;
    return 1;
    }
  if(!present(m1, this_object()) || !present(m2, this_object())){
    COMBAT = 0;
    return 1;
  }
  if(m1->query_ghost()){
    COMBAT = 0;
    do_rewards(m1,m2);
    return 1;
    }

  if(m2->query_ghost()){
    COMBAT = 0;
    do_rewards(m2,m1);
    return 1;
    }

  call_out("loser_check", 2);
  return 1;
}

do_rewards(loser,winner){
  int n;

  n = winner->query_level() * 40+random(60);
  n = n + winner->query_guild_rank() * 50;
  present("mageobj", loser)->add_donation(-n);
  tell_object(loser, "\n"+HIR+
  "You have lost the duel!!!\n"+
  "You beaten corpse falls to the ground.  "+WIN+" stands over you truimphantly!\n"+
  "You lose "+n+" donation points for this defeat.\n");
  loser->clear_fight_area();
  
  n = loser->query_level() * 60+random(40);
  n = n + loser->query_guild_rank() * 50;
  present("mageobj", winner)->add_donation(n);
  tell_object(winner, "\n"+HIY+
  "You have won the duel!!!\n"+NORM+
  LOS+"'s beaten corpse lays at your feet.  You raise your arms in Truimph!\n"+
  "You have earned "+n+" donation points for this victory!\n");
  tell_everyone(HIC+"[~~"+WIN+" has defeated "+LOS+" in the War Room!~~]\n"+NORM);
  winner->clear_fight_area();
}

no_way_jose(){
  write("Not in here you don't!\n");
  return 1;
}

wuss(){
  if(this_player()->query_ghost()){
    write("You must use 'revive' before you leave.\n");
    return 1;
    }

  if(COMBAT == 1){
    if((this_player() == m1) || (this_player() == m2)){
      write(
      "The heavy iron door has slammed shut and been magically sealed.\n"+
      "The portal will not open again until there is a victor.\n");
      say(
      ME+" tried to leave, but the door is locked.\n");
      return 1;
      }
    write(
    "You quickly back out of the room to avoid the battle.\n");
    say(
    ME+" quickly leaves the room.\n");
    move_object(this_player(), "players/pavlik/guild/mages/room/party_room");
    command("look", this_player());
    return 1;
    }
  say(ME+" leaves the room.\n");
  move_object(this_player(), "players/pavlik/guild/mages/room/party_room");
  command("look", this_player());
  return 1;
}

big_balls(str){
  object obj;

  if(COMBAT == 1){
    write("There is already a battle going on, you must wait until\n"+
    "it has been concluded before beginning another.\n");
    return 1;
    }

  if(!str){
    write("Use: Duel <player>.\n");
    return 1;
    }

  obj = present(str, environment(this_player()));

  if(!obj){
    write("That person is not here.\n");
    return 1;
    }

  if(obj == this_player()){
    write("You can't challenge yourself!\n");
    return 1;
    }

  if(living(obj) && obj->query_npc() == 1){
    write("You can only challenge another player.\n");
    return 1;
    }

  write(
  "You issue a challenge to "+capitalize(str)+", waiting for a reply...\n");
  say(HIY+ME+" issues a challenge to "+capitalize(str)+".\n"+NORM);
  m1 = this_player();
  command("make_reply", obj);
  return 1;
}

sucker(){
  object obj;
  string name;
  name = capitalize(m1->query_real_name());

  write(
  name+" ["+m1->query_level()+"] has issued a challenge against you.\n"+
  "Do you accept this challenge? [y/n] > ");
  input_to("guts");
  return 1;
}

guts(str){
  int n;
  if(str == "n" || str == "N"){
    write("You refuse the challenge.\n");
    if(this_player()->query_level() > m1->query_level()){
      write("You are a coward.\n");
      n = random(this_player()->query_level() * 15);
      present("mageobj", this_player())->add_donation(-n);
      write("You lose "+n+" donation points for cowardice.\n");
      }
    say(ME+" has refused the challenge.\n");
    tell_object(m1,
    "The coward has refused your challenge.\n");
    return 1;
    }

  if(str == "y" || str == "Y"){
    write("You have accepted to the challenge!\n");
    if(this_player()->query_level() < (m1->query_level() - 5)){
      n = random(m1->query_level() * 20);
      present("mageobj", this_player())->add_donation(n);
      write("You earn "+n+" donation points for accepting the challenge "+
      "of such a\ndangerous opponent.\n");
      }
    write("You will now fight to the death!\n");
    say(ME+" has accepted the challenge!\n");
    m2 = this_player();
    COMBAT = 1;
    clear_room();
    call_out("loser_check", 2);
    tell_object(m1, "You will now fight to the death!\n");
    m1->set_fight_area();
    m2->set_fight_area();
    return 1;
    }

  write("Do you accept this challenge? [y/n] > ");
  input_to("guts");
  return 1;
}

clear_room(){
  object ob;

  ob = first_inventory(this_object());
  while(ob){
    object cur;
    cur = ob;
    ob = next_inventory(ob);

    if( (cur != m1) && (cur != m2) )
    {
      cur->clear_fight_area();
      command("out", cur);
    }
  }
  return 1;
}

chicken_shit(){
  string name;
  int n;

  if(COMBAT == 0){
    write("You can't use this command unless your in battle.\n");
    return 1;
    }

  if(this_player() == m1 || this_player() == m2){
    m1->stop_fight();  m1->stop_hunter();
    m2->stop_fight();  m2->stop_hunter();
    m1->clear_fight_area();
    m2->clear_fight_area();
    write(
    "You drop to your bloodied knees and grovel at your "+
    "opponents feet.\n");
    say(
    ME+" drops to his bloodied knees and grovels at your feet.\n"+
    "The coward begs for mercy as his kisses your toes.\n"+
    "You decide to let this pitiful creature live.\n");
    if(this_player() == m1)
      n = random(m2->query_level() * 25);
    else
      n = random(m1->query_level() * 25);
    present("mageobj", this_player())->add_donation(-n);
    write(
    "You lose "+n+" donation points for your failure.\n");
    if(this_player() == m1){
      n = random(m1->query_level() * 25);
      present("mageobj", m2)->add_donation(n);
      tell_object(m2,
      "You earn "+n+" donation points for this victory.\n");
    } else {
      n = random(m2->query_level() * 25);
      present("mageobj", m1)->add_donation(n);
      tell_object(m1,
      "You earn "+n+" donation points for this victory.\n");
    }
    COMBAT = 0;
    write("The battle has ended.\n");
    say("The battle has ended.\n");
    return 1;
    }

  write("Your not even fighting!\n");
  return 1;
}

you_loser(){
  int n;

  if(!this_player()->query_ghost()){
    write("Your not dead!\n");
    return 1;
    }

  call_other(this_player(), "remove_ghost", 0);
  write("You are returned to your 'normal' status.\n");
  write(ME+" reappears in a more solid form.\n");
  return 1;
}

tell_everyone(str){
 object ob, obj;
 int i;
 ob = users();
 for(i=0; i<sizeof(ob); i++){
  obj = present("mageobj", ob[i]);
  if(obj && !obj->query_muffled())
   tell_object(ob[i], str);
 }
 return 1;
}
