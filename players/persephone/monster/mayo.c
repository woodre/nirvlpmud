inherit "obj/monster";
#include "/players/persephone/rooms.h"
#define MOV_RATE 10
object grubble;
object cup;
object wabble;
void reset(int arg){
   ::reset(arg);
     if(arg) return;
       cup =clone_object("players/persephone/closed/maycup");
       move_object(cup, TOB);
       set_name("beggar");
       set_alias("mayor");
       set_short("An Unfortunate Old Man");
       set_long("One of Stormhold's and Nirvana's poor and unfortunate\n"+
                "underclass. He is dressed in ragged and tatty clothes.\n"+
                "He looks so poor you almost feel sorry for him.\n");
       set_level(10);
       set_wc(14);
       set_hp(150);
       set_ac(8);
       set_al(50);
       set_aggressive(0);
       set_gender ("male");
       set_chat_chance(20);
       set_a_chat_chance(30);
       load_chat("The beggar shakes his cup in hope\n");
       load_chat("The beggar sighs: I use to be someone important here.\n");
       load_chat("The beggar asks: Have you come to save Stormhold?\n");
       load_chat("The beggar asks: Do you have something for me?\n");
       load_a_chat("The beggar shouts: YOUR NOTHING BUT A RUFFIAN\n");
       load_a_chat("The beggar sighs: Youth today they have no respect\n");
       load_a_chat("The beggar sighs: What has happened to this fair town?\n");
       load_a_chat("The beggar asks: Why do you do this to me??\n");
       load_a_chat("The beggar states: I have done nothing to you!!\n");

       call_out("random_move",MOV_RATE);
}

status random_move(){

   int n;
   if(this_object()->query_attack()) {
      call_out("random_move",MOV_RATE);
      return 1;
   }
   n=random(4);    /* Six main directions of moving */
   switch(n) {
      case 0 : command("north"); break;
      case 1 : command("east"); break;
      case 2 : command("south"); break;
      case 3 : command("west"); break;
   }
   call_out("random_move",MOV_RATE);
   return 1;
} 
catch_tell(str){
 object from;
 string a, b, c;
 object next_dest;
 string next_out;
 from = TPL;
 if(!from)
  return 1;
 if(sscanf(str, "%s gives %s to Mayor.", a, b) == 2) {
  object ob, ob2;
  ob2 = TOB;
  ob = present(b, TOB);
  if(!ob || !ob->id("royal seal"))
   return 1;
  call_out("give_obj", 1, TPL);
 }
return 1;
}
second_life(){
  grubble=clone_object("players/persephone/closed/nyny3");
   move_object(grubble, TPL);
  ::second_life();
}
give_obj(object player){
 say("\nThe mayor thanks " + capitalize(player->query_real_name()) + " for the seal and wishes them luck\n");
 wabble=clone_object("players/persephone/closed/duny");
 move_object(wabble,player);
 destruct(present("seal"));
return 1;
}