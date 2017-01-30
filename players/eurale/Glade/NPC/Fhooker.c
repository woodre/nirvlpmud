#define tp this_player()
#define tpn this_player()->query_name()
#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";
object player;

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("asytrasil");
set_alias("tart");
set_alt_name("hooker");
set_race("human");
set_gender("female");
set_short("Asytrasil");
set_long(
  "This is Asytrasil, the glade tart.  She provides pleasure to those\n"+
  "who travel through this wooded wonderland.  She definitely seems\n"+
  "out of place in these parts.  She has beautiful blonde hair that\n"+
  "flows nearly to the middle of her back.  The tops of her creamy\n"+
  "breasts are visible above the low-cut neck of her dress and the\n"+
  "erect nipples push out against its fabric.  She has pool blue eyes\n"+
  "but it's her lips that captivate you.  They are pouty and very red\n"+
  "from the rouge that  highlights them.  She is here to give you\n"+
  "pleasure if you just type 'blow job'.\n");

set_level(19);
set_hp(475);
set_al(0);
set_wc(28);
set_ac(16);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(13);
  load_chat("Asytrasil licks her red lips seductively.\n");
  load_chat("Asytrasil whispers, 'Want one?'\n");
  load_chat("'Only 1000 coins for my service', says the tart\n");
  load_chat("Asytrasil winks at you.\n");
  load_chat("'I'm disease free, I think', says Asytrasil\n");
set_a_chat_chance(10);
  load_a_chat("Asytrasil SCREAMS, 'You bastard!'\n");
  load_a_chat("Asytrasil tries to kick you in the privates.\n");
  load_a_chat("The tart SCRATCHES your face.\n");

gold = clone_object("obj/money");
gold->set_money(1810);
move_object(gold,this_object());
}

init() {
  ::init();
  add_action("blow","blow");
}

monster_died() {
int num;
num = random(100);
if(num == 18 || num == 28 || num == 41 || num == 74 || num == 88) {
  write("As you inflict the killing blow, you sever a major artery \n"+
	"and blood spews about the room.... hitting you in the face!\n");
  move_object(clone_object("players/eurale/closed/VD.c"),tp);
  write_file("/players/eurale/Glade/LOG/hookers",
  ctime(time())+"        fVD     "+this_player()->query_real_name()+"\n");
  return 1; }
return 0; }

blow(str) {
if(!str) {
  write("'Blow what?', giggles Asytrasil\n");
  return 1; }
if(str == "job" || str == "me") {
if(tp->query_gender() == "female") {
  write("Asytrasil spits in your face and screams...\n"+
	BOLD+"     I don't do women you BITCH!"+NORM+"\n");
  attack_object(this_player());
  return 1; }
if(present("condom",tp)) {
  player = this_player();
  call_out("no_condom",1);
  return 1; }
if(tp->query_money() < 1000) {
  write("Asytrasil snickers, 'You can't afford me!\n");
  return 1; }
else { tp->add_money(-1000); }
this_object()->add_money(100);
  if(money > 1950) money = 1900 + random(100);
write("Asytrsil smiles, takes your money and says, 'Thanks... now\n"+
      "lets get down to the nitty gritty and give you what you paid\n"+
	"for...'\n\n");
player = this_player();
write_file("/players/eurale/Glade/LOG/hookers",
  ctime(time())+"     Blow job     "+tp->query_real_name()+"\n");
if(random(100) < 30 && !present("crotchrot",tp)) {
  write_file("/players/eurale/Glade/LOG/hookers",
    ctime(time())+"     ** VD **     "+tp->query_real_name()+"\n");
  move_object(clone_object("players/eurale/closed/VD"),tp);
  return 1; }
this_object()->set_chat_chance(0);
call_out("bj",11);
return 1; }
}

no_condom() {
object cob;
cob = present("condom",player);
tell_object(player,
  "Asytrasil looks at you and GASPS.  She sneers, 'We'll have none of\n"+
  "those contraptions here!'  Then she grabs your condom, blows it\n"+
  "into a big balloon and POPS it.  Asytrasil giggles...\n\n");
destruct(cob);
return 1; }

bj() {
tell_object(player,
  "Asytrasil slowly circles you... letting her hand lightly brush\n"+
  "your shoulders and neck as she walks around you....\n\n");
call_out("bj2",10);
return 1; }

bj2() {
tell_object(player,
  "She stops right in front of you, face to face.  You can smell\n"+
  "a delicate fragrance of flowers in her hair.  As she slowly\n"+
  "runs her tongue across her upper lip, you feel her hands grasp\n"+
  "and then undo the belt holding your pants up.  She slowly, ever so\n"+
  "slowly, pulls your pants open and lets them fall to the ground.\n\n");
call_out("bj3",20);
return 1; }

bj3() {
tell_object(player,
  "With a last look directly into your eyes.... and a smile, she\n"+
  "gently drops down to her knees, letting her hands trail down \n"+
  "over your chest and the rapidly growing bulge in your under-\n"+
  "shorts....  She daintily puts her fingers inside the wasteband of\n"+
  "your undershorts and pulls them down, making sure to hold them out\n"+
  "far enough to get past your fully erect cock.  She let's out a\n"+
  "slight gasp as she gets her first look....\n\n");
call_out("bj4",30);
return 1; }

bj4() {
tell_object(player,
  "She leans in real close and you feel her kiss the head of your dick.\n"+
  "Her hot breath warms the skin as her tongue glides up one side and\n"+
  "then the other of your manhood.  As her fingernails lightly rub\n"+
  "up the sides of your naked legs, it brings goose bumps to your\n"+
  "entire body....\n\n");
call_out("bj5",30);
return 1; }

bj5() {
tell_object(player,
  "As her lips close over your cock, you close your eyes and slowly\n"+
  "tip your head back.  She pumps up and down, first very slowly and\n"+
  "then more rapidly.  You feel her fingernails dig into your naked\n"+
  "buttocks...  And then with a moan, you STIFFEN and all is calm.\n\n");
call_out("bj6",20);
return 1; }

bj6() {
tell_object(player,
  "Asytrasil leans over and spits and then she looks up at you and\n"+
  "smiles.  She slowly stands and says, 'Hope you enjoyed that as\n"+
  "much as I did.  Thanks, and come back and see me again!'  Then she\n"+
  "turns her back to you to indicate that your time is up..\n\n");
this_object()->set_chat_chance(13);
return 1; }
