inherit "obj/monster.c";
/******************************************************************************
 * Program: nazi.c
 * Path: /players/cosmo/apt/mon
 * Type: Mob
 * Created: by Cosmo
 *
 * Purpose: A low level mob in Seinfield area
 * History:
 *          09/28/2014 - Gnar
 *            Updated to make soup from ninja turtle remains.
 ******************************************************************************/
#include "/players/cosmo/closed/ansi.h"

string customer;

reset(arg)  {
object chat;
object prize;
  ::reset(arg);
  if(arg) return;

set_name(HIY+"Soup Nazi"+NORM);
set_alias("soup nazi");
set_alt_name("nazi");
set_race("creature");
set_short("The Soup Nazi");
set_long(
  "  He's all business.  If you are in here, you should be\n"+
  "buying soup.  No loitering is this shop.  This shop is\n"+
  "also not the place to come for friendly service.  You will\n"+
  "never catch the Soup Nazi with a smile on his face; thus,\n"+
  "the name he has been given.\n");

set_level(12);
  set_hp(200);
  set_al(-1*(50+random(50)));
  set_wc(17);
  set_ac(8);
  set_heal(3,20);
  set_aggressive(0);
  set_dead_ob(this_object());

set_a_chat_chance(15);
  load_a_chat("The Soup Nazi exclaims: That's it! No soup for you!\n");

set_chance(10);
set_spell_dam(30);
set_spell_mess1(
  "\nYou see a bowl of soup go flying through the air.\n");
set_spell_mess2(
  "\nThe Soup Nazi throws a bowl of "+RED+"scalding hot"+NORM+" soup on you.\n");

chat = clone_object("/players/cosmo/apt/armor/chefhat");
move_object(chat,this_object());
prize = clone_object("/players/cosmo/apt/obj/scup");
move_object(prize,this_object());
}

monster_died() {
  tell_room(environment(this_object()),BOLD+
	"What a shame.  Now you can't buy any soup."+NORM+"\n");
return 0; }

catch_tell(string str) {
  string msg;
  object remains;
  if(sscanf(str,"%s gives",msg)) {
    remains = present("turtle remains", this_object());
    if(remains) {
      if( customer && !objectp( find_living(customer) ) )
        customer = 0;
      if( find_call_out("setup_soup") >= 0 || customer ) {
        write("Soup Nazi yells: I am busy. Come back later!\n");
        move_object( remains, environment() );
        return 1;
      }
      write( "Soup Nazi says: I make soup for you.\n");
      customer = this_player()->query_real_name();
      destruct(remains);
      call_out("setup_soup", 100, this_player());
    }
  }
  return 1;
}

setup_soup(object ob) {
  object soup;
  if(!ob || !environment() || !environment(ob) ) {
    customer = 0;
    return;
  }
  soup = clone_object("/players/wicket/ninja_turtles/heals/turtlesoup");
  if( environment(ob) == environment() ) {
    move_object( soup, ob );
    tell_object( ob, "Soup Nazi tells you: Here is your soup. Now go!\n");
    customer = 0;
    return 1;
  }
  else {
    move_object( soup, this_object() );
    tell_object( ob, "Soup Nazi tells you: Soup's on.\n" ); 
    return 1;
  }
}

init(){
  object soup;
  ::init();
  if(present("RangerCommunicator", this_player() ) )
    present("RangerCommunicator", this_player() )->TrainRangerSkill("donate",1,"cosmo","The Soup Nazi",90);

  if( customer ) {
    soup = present("turtle soup", this_object() ); 
    if( this_player() && (string)this_player()->query_real_name() == customer ) {
      if( soup ) {
        move_object( soup, this_player() );
        tell_object( this_player(), "Soup Nazi tells you: Here is your soup. Now go!\n");
        customer = 0;
      }
    }
  }
}

add_weight(w) { return 1; }
