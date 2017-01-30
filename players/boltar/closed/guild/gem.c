#include "/obj/user/shout_only.c"
int times;
object guil;


short()
{
       return "A small orange gem stone";
}

query_value()
{
        return 0;
}

  query_weight() {   return 0; }
long()
{
    write("The gem seems to be full of energy.\n");
}

init() {
     add_action("use"); add_verb("summon");
      add_action("move_morph","mm");
      add_action("mw","mw");
      add_action("me","me");
      add_action("ms","ms");
      add_action("mn","mn");
     add_action("rem_morph","dopp");
     add_action("aerosol","aerosol");
     add_action("aerosol","spray");
              add_action("info_gem","info_gem");
           add_action("munchie","munchie");
}

id(str) {
    return str == "ND" || str == "gem" || str == "orange gem";
}

use(str) {
    if(!cost(-5)) return 1;
  if(times > 6) {
   write("There are no charges left in the gem.\n");
   return 1;
   }
  times += 1;
chan_msg("The sky glows orange for a second.\n");
write("Your skin turns orange, then returns to normal.\n");
say("A Little Lotto Wizard Appears.\n");
write("You summon A Little Lotto Wizard.\n");
move_object(clone_object("players/boltar/things/lotto.c"), environment(this_player()));
return 1;
}

get() {
      write("You nearly burn your hand picking up the hot gem.\n");
    return 1;
}
query_auto_load() {
  return "/players/boltar/closed/guild/gem.c:";
 }
drop(str) {
  return 1;
  }
info_gem() {
cat("/players/boltar/closed/guild/info");
write("\n");
return 1;
}
aerosol() {
   object ob,ob2,clo;
    if(!cost(-10)) return 1;
clo = present("cloud",environment(this_player()));
  if(!clo) {
  write("There is no cloud here.\n");
  return 1;
   }
say(this_player()->query_name() + " pulls out an aerosol can and sprays all the CFC's on the cloud,\n eating it away.\n");
write("You pull out your CFC can and disperse the cloud.\n");
  ob = first_inventory(clo);
  while (ob) {
    ob2 = next_inventory(ob);
     tell_room(environment(this_player()),ob->query_name() + " falls down from the sky!\n");
     tell_object(ob, "Your cloud is dispersed by a large concentration of CFC's\n");
  if(present("mages_guild_object",ob))
    present("mages_guild_object",ob)->remove_cloud();
    move_object(ob,environment(this_player()));
    ob = ob2;
  }
  destruct(clo);
  return 1;
  }
munchie() {
  move_object(clone_object("players/boltar/things/munchies.c"),this_player());
  this_player()->add_spell_point(-20);
  write("You clone some munchies.\n");
  return 1;
}
rem_morph(str) {
  object play;
   if(!str) return 0;
    write("Searching for "+str+"\n");
    play=find_player(str);
   if(!play) {
  write("cannot find "+str+"\n");
   return 1;
   }
   guil=present("badge of dopplegangers guild",play);
    if(!guil) {
   write("No connection made to dopple badge.\n");
    return 1;
    }
   write("Connection made to dopple badge.\n");
   if(cost(-30))
    guil->change();
}
move_morph(str) {
   find_dopp();
   guil->extra_move(str);
    return 1;
 }
mn(){
 move_morph("north");
 return 1;
}
mw(){
 move_morph("west");
 return 1;
}
me(){
 move_morph("east");
 return 1;
}
ms(){
 move_morph("south");
 return 1;
}
find_dopp(str) {
   int index;
   object *people;
   people = users();
   write("Searching for a connection.\n");
index = 0;
guil = 0;
  while(index < sizeof(people)) {
   guil=present("badge of dopplegangers guild",people[index]);
   if(guil) index = 100;
    index+=1;
   }
   if(guil) 
   write("Connected to "+environment(guil)->query_real_name()+"\n");
   if(!guil) {
     move_object(this_player(),environment(environment(this_player())));
        write("You lose your connection.....\n");
    write("You stand next to your crippled morph.\n");
    return 0;
   }
 return 1;
}
cost(amt) {
  if(this_player()->query_spell_points() < amt) {
   write("You do not have enough spell points.\n");
   return 0;
   }
  this_player()->add_spell_point(amt);
   return 1;
 }
