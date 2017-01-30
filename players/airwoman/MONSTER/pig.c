inherit "obj/monster";
reset(arg){
::reset(arg) ;
 if (!arg){
    set_name ("male chauvanist pig");
    set_short("A male chauvanist pig");
    set_alias("pig");
    set_long ("A male chauvanist pig who thinks females are mere sex\n"+
        "objects.  He doesnt wear a letter R on his jacket so you cant\n"+ 
	"tell he is a serial rapist\n"+
	"So people, LET's KILL THIS CREEP.\n"+
	"(At least chop off his prick)\n");
set_level(10);
set_ac(8);
set_hp(1000);
set_al(25);
set_aggressive(0);
set_wc(14);
set_can_kill(6);
set_heal(4,50);
set_chat_chance(1);
load_chat("Pig says: Men are superior!\n");
load_chat("Pig says: Suck my ****!\n");
load_chat("Someone whispers to you:  Be like Martin Yan!  Chop CHOP CHOP!\n");
set_a_chat_chance(40);
load_a_chat("Pig says: Yowwwwww!\n");
load_a_chat("Good aim.  I bet you can chop his prick off with your eyes closed.\n");
load_a_chat("Pig falls to the ground grabbing his crotch.\n");
}
{
  int n;
  n=random(5);
  if (n>2){
	write("You kick him hard in the balls.\n");
	say(this_player()->query_name()+" kicks the pig HARD in the balls!\n");
     }
   return n;
}
}
