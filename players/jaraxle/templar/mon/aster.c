#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";

string emote_action, ast;
reset(arg)  {
call_out("tea_pot", 5);
     ::reset(arg);
  if(arg) return;

set_name("aster");
set_alias("gardenkeeper");
set_alt_name("keeper");
set_race("human");
set_gender("female");
set_short("Aster, the Garden Keeper");
set_long(
    "  Aster is a very pretty young girl with long, blonde hair braided\n"+
    "into two pigtails. A purple ribbon is tied to the end of each braid,\n"+
    "and she wears a flowing, lavender gown. She has sparkling green eyes\n"+
    "and a wonderous smile.\n");
set_level(2);
   set_chat_chance(5);
   load_chat("Aster smiles at you.\n");
   load_chat("Aster dips her pail, and waters some of the flowers.\n");
   load_chat("Aster leans over to smell some flowers.\n");
   load_chat("Aster tickles you playfully.\n");
set_hp(30);
set_al(1500);
set_wc(6);
set_ac(3);
set_wander(37, 0, ({ "out" }));
MOCO("/players/jaraxle/templar/invite.c"),TO);
MOCO("/players/boltar/templar/templar.c"),TO);
MOCO("/players/jaraxle/templar/items/pail.c"),TO);
}
init(){
   ::init();
   add_action("help_me","kill");
   add_action("aster_action","hug");
   add_action("aster_action","smile");
   add_action("aster_action","wave");
   add_action("aster_action","kiss");
   add_action("aster_action","dance");
   add_action("aster_action","love");
   add_action("aster_action","sigh");
   add_action("aster_action","lick");
   add_action("aster_action","nod");
   add_action("aster_action","shake");
   add_action("aster_action","tackle");
   add_action("aster_action","tickle");
   add_action("aster_action","snuggle");
   add_action("aster_action","grin");
   add_action("aster_action","poke");
   add_action("aster_action","bow");
   add_action("aster_action","curtsey");
   add_action("aster_action","salute");
   add_action("aster_action","sex");
}

aster_action(who) {
   if(who == "aster") {
      emote_action = query_verb();
      call_out("aster_action2",2,this_player()->query_real_name());
   }
}

aster_action2(who) {
   if(!find_player(who) || environment(find_player(who)) != environment()) return;
   switch(emote_action) {
      case "sex":
         tell_object(find_player(who),"Aster gasps, then smacks you!\n");
         say("Aster gasps, then smacks "+capitalize(who)+"!\n",find_player(who));
         break;
      case "hug":
         tell_object(find_player(who),"Aster hugs you happily.\n");
         say("Aster hugs "+capitalize(who)+" happily.\n",find_player(who));
         break;
      case "lick":
         say("Aster wipes her face and goes, 'Eewwww!'\n");
         break;
      case "nod":
        tell_object(find_player(who),"Aster nods at you.\n");
         break;
      case "shake":
        tell_object(find_player(who),"Aster shakes your hand.\n");
         break;
      case "tackle":
         if(find_player(who)->query_attrib("ste") >= random(13)) {
         tell_object(find_player(who),"Aster nimbly dodges you.\n");
        say("Aster nimbly dodges from "+capitalize(who)+".\n",find_player(who));
         break;
         }
         tell_object(find_player(who),"Aster tickles you frantically.\n");
         say("Aster tickles "+capitalize(who)+" frantically.\n",find_player(who));
         break;
      case "smile":
         tell_object(find_player(who),"Aster smiles peacefully back.\n");
         say("Aster smiles at "+capitalize(who)+".\n",find_player(who));
         break;
      case "wave":
         tell_object(find_player(who),"Aster waves with a smile.\n");
         say("Aster waves at "+capitalize(who)+" with a smile.\n",find_player(who));
         break;
      case "kiss":
         if(find_player(who)->query_gender() == "male") {
         say("Aster giggles, and hides her face.\n");
            break;
         }
         tell_object(find_player(who),"Aster makes an 'Ick!' face.\n");
         say("Aster 'Icks!' at "+capitalize(who)+".\n",find_player(who));
         break;
      case "dance":
         tell_object(find_player(who),"Aster slides back into a dip.\n");
         say(""+capitalize(who)+" dips Aster gracefully.\n",find_player(who));
         say("Aster giggles happily.\n");
         break;
      case "love":
         tell_object(find_player(who),"Aster blushes a deep crimson red.\n");
         say("Aster blushes at "+capitalize(who)+".\n",find_player(who));
         break;
      case "sigh":
         tell_object(find_player(who),"Aster gazes at you with a concerned look in her eyes.\n");
         break;
      case "tickle":
         say("Aster giggles merrily.\n");
         break;
      case "snuggle":
            tell_object(find_player(who),"Aster holds you tightly..\n");
            say("Aster holds "+capitalize(who)+" tight.\n",find_player(who));
         break;
      case "grin":
         tell_object(find_player(who),"Aster winks at you.\n");
         say("Aster winks at "+capitalize(who)+".\n",find_player(who));
         break;
      case "poke":
         say("Aster yells, 'Ouch!'.\n");
         break;
      case "bow":
         say("Aster curtseys.\n");
         break;
      case "curtsey":
         say("Aster cursteys.\n");
         break;
      case "salute":
         say("Aster covers her heart with her fist and nods in a formal salute.\n");
         break;
   }
}
help_me(ast){
   if(ast == "aster"){
command("ahelp",TO);
}
}

tea_pot(){
    say("Aster sings, 'I'm a little tea pot...'\n");
call_out("tea_pot2", 5);
}
tea_pot2(){
    say("Aster sings, 'Short and stout...'\n");
call_out("tea_pot3", 5);
}
tea_pot3(){
    say("Aster sings, 'Here is my handle...'\n");
call_out("tea_pot4", 2);
}
tea_pot4(){
    say("Aster sings, 'Here is my spout...'\n");
call_out("tea_pot5", 5);
}
tea_pot5(){
    say("Aster sings, 'When I get all steamed up!..'\n");
call_out("tea_pot6", 5);
}
tea_pot6(){
    say("Aster sings, 'I just shout...'\n");
call_out("tea_pot7", 5);
}
tea_pot7(){
    say("Aster sings, 'TIP ME OVER!'\n");
call_out("tea_pot8", 2);
}
tea_pot8(){
    say("Aster sings, 'AND POUR ME OUT!'\n");
remove_call_out("tea_pot");
remove_call_out("tea_pot2");
remove_call_out("tea_pot3");
remove_call_out("tea_pot4");
remove_call_out("tea_pot5");
remove_call_out("tea_pot6");
remove_call_out("tea_pot7");
remove_call_out("tea_pot8");
call_out("tea_pot", 33);
}
