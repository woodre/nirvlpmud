#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster.c";

int shieldint;
int no_catch_tell;

reset(arg){
random_move();
::reset(arg);
if(arg) return;
set_name("snail");
set_alt_name("workroom");
set_race("snail");
set_wc(10);
set_ac(10000);
set_hp(100000);
set_chance(30);
set_ep(1000000);
set_spell_mess1("The Giant Snail plops down upon his adversary.  SQUISH.\n");
set_spell_mess2("\n\nWith amazing agility the gaint snail manages to leap into the\n"+
                  "air.  Suddenly the snail lands, crushing you beneath its body.\n"+
                  HIR+"\tS\tQ\tU\tI\tS\tH\t!\n\n"+OFF);
set_spell_dam(300);
set_chat_chance(5);
load_chat("Snail smiles.\n");
load_chat("Snail raises its head and observes the surroundings.\n");
load_chat("Snail slowly nibbles, chewing its food.\n");

move_object(this_object(),"/players/wocket/turtleville/tville_fount.c");
init_me();
}
/*
is_player(){ return 1; }
*/

/*
query_interactive(){ return 1; }
*/
init_me(){
#ifndef __LDMUD__
  add_action("blah"); add_xverb("");
#else
  add_action("blah", "", 3);
#endif
add_action("look","look");
}
look(){
string msg;
object ob;
int revert;
if(no_catch_tell){
  revert = 1;
  no_catch_tell = 0;
}
  write(environment(this_object())->short()+"\n");
  environment(this_object())->long();
  ob = first_inventory(environment(this_object()));
while(ob){
  msg += ob->short()+"\n";
  ob = next_inventory(ob);
}
  tell_room(this_object(),msg);
if(revert)
  no_catch_tell = 1;
}

move_player(str){
::move_player(str);
command("look",this_object());
}

blah(){
notify_fail("");
return 0;
}


short(){
object ob;
string msg;
if(this_player()){
if(environment(this_player()) == environment(this_object())){
  msg = HIR+"A Giant Snail"+OFF;
}
else
  msg = HIR+"A Giant Snail's Shell"+OFF;
}
return msg;
}

long(){
  if(environment(this_player()) == this_object()){
    write(HIR+"Wocket's Workroom\n"+OFF+
          "  The walls are made from the snail's shell. It spirals\n"+
          "upwards leaving small groves in it, which make very\n"+
          "nice benches.  A small hammock hangs near the top.  Light\n"+
          "shimmers and glances off the pearl-like substance, which\n"+
          "lines the shell, as an array of color fills the room.  There\n"+
          "are very small slits in the shells which allows one to see\n"+
          "out.  They cast unusual shadows only adding to the etheriel\n"+
          "atmosphere.\n"+
HIR+"A big red button you can 'press'.\n"+OFF+
          "    There is one obvious exit: leave\n");  
  if(shieldint)
    write(HIG+"The snail's natural shielding is activated.\n"+OFF);
  if(no_catch_tell)
    write(HIG+"The snail is silenced.\n"+OFF);
    return 1;
  }
  else
  {
    write("Before you slimes a GIANT snail.  Large tenticles\n"+
          "swirl around as if looking for something.  There\n"+
          "is a giant shell upon its back that looks large enough\n"+
          "to house a couple of people.  Be warned that if you\n"+ 
          "attack this snail you will die.\n");
    return 1;
   }
}

init(){
  ::init();
  if(environment(this_player()) == this_object()){
    add_action("leave","leave"); 
    add_action("button","press");
    if(this_player()->query_real_name() == "wocket"){
      add_action("snail_command","snail_com");
      add_action("silence","silence");
      add_action("toggle_shield","shield");
    }
    if(shieldint && this_player()->query_real_name() != "wocket"){
    move_object(this_player(),environment(this_object()));
    write(HIG+"\nYou have been deflected off of the snail's natural shielding.\n\n"+OFF);
    tell_room(this_object(),HIG+capitalize(this_player()->query_real_name())+" has been deflected off the shields.\n"+OFF);
    }
  }
  else
  {
    add_action("enter","enter");
  }
}

button(str){
  if(str == "button"){
  say(this_player()->query_name()+" presses the button.\n"+BEEP+"A beep is heard throughout the room.\n"+BEEP);
  return 1;
  }
notify_fail("What would you like to press?\n");
return 0;
}
toggle_shield(str){
  if(!str){
    notify_fail("Usage: shield <on> | <off>\n");
    return 0; 
  } 
  if("on" == str){
    shieldint = 1;
    write("Shields are now activated.\n");
    return 1;
  }
  if("off" == str){
    shieldint = 0;
    write("Shields are now deactivated.\n");
    return 1; 
  }
  write("Usage: shield <on> | <off> \n");
  return 1;
}

silence(str){
  if(str == "on"){
    no_catch_tell = 1;
    write("You have silenced the snail.\n");
    return 1;
  }
  if(str == "off"){
    no_catch_tell = 0;
    write("You allow the snail to speak.\n");
    return 1;
  }
  write("Usage: silence <on> | <off> \n");
  return 1;
}

snail_command(str){
  if(!str){
    notify_fail("What would you like the snail to do?\n");
    return 0;
  }
  command(str,this_object());
  return 1;
}

enter(str){
  if(!str || str != "shell"){
    notify_fail("What would you like to enter?\n");
    return 0;
  }
  if(shieldint && this_player()->query_real_name() != "wocket"){
    notify_fail("The natural shielding of the snail prevents you.\n");
    return 0;
  }
  say(this_player()->query_name()+" climbs into the shell of the snail.\n");
  write("You climb into the shell of the snail.\n");
  move_object(this_player(),this_object());
  command("look",this_player());
  say(this_player()->query_name()+" arrives after climbing up the shell.\n");
  return 1;
}

leave(){
  say(this_player()->query_name()+" climbs down out of the shell.\n");
  write("You climb down out of the shell.\n");
  move_object(this_player(),environment(this_object()));
  command("look",this_player());
  say(this_player()->query_name()+" climbs out of the shell.\n");
  return 1;
}

catch_tell(str){
if(!no_catch_tell){
if(this_player() && (environment(this_player()) == this_object()))
  return;
  tell_room(this_object(),str);
}
}

hit_player(i){
  if(previous_object()->query_level() > 19) destruct(previous_object());
  if(previous_object() == this_object()){
  say(BOLD+"\n     The I N S A N I T Y wavers!\n"+
           "     The snail regains its senses.\n"+OFF);
  stop_fight();
  }
  else
  ::hit_player(i);
}

calculate_worth(){ return 1000000; }

query_prevent_shadow(){ return 1; }
