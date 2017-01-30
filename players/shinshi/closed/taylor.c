inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>
string person;
int a, b, play, run;

reset(arg)
{
	::reset();
	if(arg) return;
	set_name("taylor");
	set_alt_name("swift");
	set_race("musician");
	set_alias("musician");
	set_short("Taylor Swift");
	set_long("\
	This is Taylor Swift. She is nineteen\n\
	years young and is absolutely gorgeous. She is a\n\
	famous country singer. She has long, blonde, wavy\n\
	hair that flows down to her mid back. Maybe you\n\
	can request a favor.\n");
	set_level(666);
	set_hp(9999 + random (999));
	set_ac(999 + random(999));
	set_wc(999 + random(999));
	set_al(7000);
	add_money(random(10000)+70000);
	set_chat_chance(1);
	load_chat(query_name()+" looks around for Shinshi.\n");
	load_chat(query_name()+" plays a note on her guitar.\n");
}
init(){
  ::init();
	add_action("love_story","love_story");
	add_action("our_song","oursong");
  }

love_story(){
  person = this_player();
  play = 1;
  call_out("talk",2,person);
  return 1; }

our_song(){
	person = this_player();
	run = 1;
	call_out("sing",2,person);
	return 1; }

talk(person){
  say_it();
	a += 1;
  if(a<66) call_out("talk",1,person);
  else {
	play = 0;
  a = 0;
  }
  return 1; }

sing(person){
	sing_it();
	b += 1;
	if(b<64) call_out("sing",1,person);
	else {
	run = 0;
	b = 0;
	}
	return 1; }

say_it(){
  string stuff;
   switch(a){
     case 0: stuff =  " "; break;
     case 1: stuff = "			Taylor picks up her guitar, clears her throat\n"+
     				 "                               and starts playing 'Love Story'."; break;
     case 2: stuff = " "; break;
     case 3: stuff = "			We were both young when I first saw you"; break;
     case 4: stuff = "			I close my eyes"; break;
     case 5: stuff = "			And the flashback starts"; break;
     case 6: stuff = "			I'm standing there"; break;
     case 7: stuff = "			On a balcony in summer air"; break;
     case 8: stuff = " "; break;
     case 9: stuff = "			See the lights"; break;
     case 10: stuff = "			See the party, the ball gowns"; break;
     case 11: stuff = "			I see you make your way through the crowd"; break;
     case 12: stuff = "			and say hello, little did I know"; break;
     case 13: stuff = " "; break;
     case 14: stuff = "			That you were Romeo, you were throwing pebbles"; break;
     case 15: stuff = "			And my daddy said stay away from Juliet"; break;
     case 16: stuff = "                        And I was crying on the staircase"; break;
     case 17: stuff = "			Begging you please don't go, and I said"; break;
     case 18: stuff = " "; break;
     case 19: stuff = "			Romeo take me somewhere we can be alone"; break;
     case 20: stuff = "			I'll be waiting all there's left to do is run"; break;
     case 21: stuff = "			You'll be the prince and I'll be the princess"; break;
     case 22: stuff = "			It's a love story baby just say yes"; break;
     case 23: stuff = " "; break;
     case 24: stuff = "			So I sneak out to the garden to see you"; break;
     case 25: stuff = "			We keep quiet 'cause we're dead if they knew"; break;
     case 26: stuff = "			So close your eyes"; break;
     case 27: stuff = "			Escape this town for a little while"; break;
	 case 28: stuff = " "; break;
     case 29: stuff = "			'Cause you were Romeo, I was a scarlet letter"; break;
     case 30: stuff = "			And my daddy said stay away from Juliet"; break;
     case 31: stuff = "			But you were everything to me"; break;
     case 32: stuff = "			I was begging you please don't go and I said"; break;
     case 33: stuff = " "; break;
     case 34: stuff = "			Romeo take me somewhere we can be alone"; break;
     case 35: stuff = "			I'll be waiting all there's left to do is run"; break;
     case 36: stuff = "			You'll be the prince and I'll be the princess"; break;
     case 37: stuff = "			It's a love story baby just say yes"; break;
     case 38: stuff = " "; break;
     case 39: stuff = "			Romeo save me, they try to tell me how to feel"; break;
     case 40: stuff = "			This love is difficult, but it's real"; break;
     case 41: stuff = "			Don't be afraid, we'll make it out of this mess"; break;
     case 42: stuff = "			It's a love story baby just say yes"; break;
     case 43: stuff = "			Oh, oh"; break;
     case 44: stuff = " "; break;
     case 45: stuff = "			I got tired of waiting"; break;
     case 46: stuff = "			Wondering if you were ever coming around"; break;
     case 47: stuff = "                        My faith in you was fading"; break;
     case 48: stuff = "			When I met you on the outskirts of town, and I said"; break;
     case 49: stuff = " "; break;
     case 50: stuff = "			Romeo save me I've been feeling so alone"; break;
     case 51: stuff = "			I keep waiting for you but you never come"; break;
     case 52: stuff = "			Is this in my head? I don't know what to think"; break;
     case 53: stuff = "			He knelt to the ground and pulled out a ring"; break;
     case 54: stuff = " "; break;
     case 55: stuff = "			And said, marry me Juliet"; break;
     case 56: stuff = "			You'll never have to be alone"; break;
     case 57: stuff = "			I love you and that's all I really know"; break;
     case 58: stuff = "			I talked to your dad, go pick out a white dress"; break;
     case 59: stuff = "			It's a love story baby just say yes"; break;
     case 60: stuff = " "; break;
     case 61: stuff = "			Oh, oh, oh"; break;
     case 62: stuff = "			Oh, oh, oh"; break;
     case 63: stuff = "			'Cause we were both young when I first saw you"; break;
     case 64: stuff = " "; break;
     case 65: stuff = "			Taylor puts down her guitar and smiles at you"; break; }
     tell_object(person,
     BOLD+stuff+NORM+"\n");
     return 1; }

sing_it(){
	string blab;
	  switch(b){
		case 0: blab = " "; break;
		case 1: blab = "                  Taylor picks up her guitar, clears her throat\n"+
                                 "                               and starts playing 'Our Song'."; break;
		case 2: blab = " "; break;
		case 3: blab = "			I was riding shotgun with my hair undone"; break;
		case 4: blab = "			In the front seat of his car"; break;
		case 5: blab = "			He's got a one-hand feel on the steering wheel"; break;
		case 6: blab = "			The other on my heart"; break;
		case 7: blab = " "; break;
		case 8: blab = "			I look around, turn the radio down"; break;
		case 9: blab = "			He says, 'Baby is something wrong??'"; break;
		case 10: blab = "			I say, 'Nothing, I was just thinking"; break;
		case 11: blab = "			How we don't have a song,' and he says"; break;
		case 12: blab = " "; break;
		case 13: blab = "			Our song is the slamming screen door"; break;
		case 14: blab = "			Sneakin' out late, tapping on your window"; break;
		case 15: blab = "			When we're on the phone and you talk real slow"; break;
		case 16: blab = "			'Cause it's late and your mama don't know"; break;
		case 17: blab = " "; break;
		case 18: blab = "			Our song is the way you laugh"; break;
		case 19: blab = "			The first date man, I didn't kiss her and I should have"; break;
		case 20: blab = "			And when I got home, 'fore I said amen"; break;
		case 21: blab = "			Asking God if He could play it again"; break;
		case 22: blab = " "; break;
		case 23: blab = "			I was walking up the front porch steps"; break;
		case 24: blab = "			After everything that day"; break;
		case 25: blab = "			Had gone all wrong or been trampled on"; break;
		case 26: blab = "			And lost and thrown away"; break;
		case 27: blab = " "; break;
		case 28: blab = "			Got to the hallway, well, on my way"; break;
		case 29: blab = "			To my lovin' bed"; break;
		case 30: blab = "			I almost didn't notice all the roses"; break;
		case 31: blab = "			And the note that said"; break;
		case 32: blab = " "; break;
		case 33: blab = "			Our song is the slamming screen door"; break;
		case 34: blab = "			Sneakin' out late, tapping on your window"; break;
		case 35: blab = "			When we're on the phone and you talk real slow"; break;
		case 36: blab = "			'Cause it's late and your mama don't know"; break;
		case 37: blab = " "; break;
		case 38: blab = "			Our song is the way you laugh"; break;
		case 39: blab = "			The first date man, I didn't kiss her and I should have"; break;
		case 40: blab = "			And when I got home, 'fore I said amen"; break;
		case 41: blab = "			Asking God if He could play it again"; break;
		case 42: blab = " "; break;
		case 43: blab = "			I've heard every album, listened to the radio"; break;
		case 44: blab = "			Waited for something to come along"; break;
		case 45: blab = "			That was as good as our song"; break;
		case 46: blab = " "; break;
		case 47: blab = "			'Cause our song is the slamming screen door"; break;
		case 48: blab = "			Sneakin' out late, tapping on his window"; break;
		case 49: blab = "			When we're on the phone and he talks real slow"; break;
		case 50: blab = "			'Cause it's late and his mama don't know"; break;
		case 51: blab = " "; break;
		case 52: blab = "			Our song is the way he laughs"; break;
		case 53: blab = "			The first date man, I didn't kiss him and I should have"; break;
		case 54: blab = "			And when I got home, 'fore I said amen"; break;
		case 55: blab = "			Asking God if He could play it again"; break;
		case 56: blab = "			Play it again, oh, yeah, oh, oh, yeah"; break;
		case 57: blab = " "; break;
		case 58: blab = "			I was riding shotgun with my hair undone"; break;
		case 59: blab = "			In the front seat of his car"; break;
		case 60: blab = "			I grabbed a pen and an old napkin"; break;
		case 61: blab = "			And I wrote down our song"; break;
		case 62: blab = " "; break;
		case 63: blab = "			Taylor puts down her guitar and smiles at you"; break; }
		tell_object(person,
		BOLD+blab+NORM+"\n");
		return 1; }