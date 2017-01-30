#define tp this_player()
#define tpn this_player()->query_name()
#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";
object player;

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("lykker");
set_alias("jerk");
set_alt_name("gigolo");
set_race("human");
set_gender("male");
set_short("Lykker");
set_long(
  "Standing before you is a tall, sandy haired young man.  His body is\n"+
  "muscled and well tanned.  He has deep blue eyes, beautiful white\n"+
  "teeth and is wearing a fairly short loincloth to show off his\n"+
  "physique.  His bare legs and chest have just a wisp of curly hair\n"+
  "but it's his hands that catch your eye.  They are not the rough,\n"+
  "calloused hands of a common laborer but soft and delicate... not\n"+
  "used to manual labor.  He is here to provide pleasure to those\n"+
  "ladies who desire it.  All one has to do is type 'pleasure me'.\n");

set_level(19);
set_hp(500);
set_al(0);
set_wc(28);
set_ac(16);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(13);
  load_chat("Lykker smiles and gently brushes your cheek.\n");
  load_chat("'I'd love to pleasure you', says Lykker\n");
  load_chat("'Gimme a taste of that honey', whispers Lykker\n");
  load_chat("'Only 1000 coins for my service', says the gigolo\n");
  load_chat("Lykker winks at you.\n");
  load_chat("Lykker whispers, 'I'm pretty sure I'm disease free.\n");
set_a_chat_chance(10);
  load_a_chat("Lykker SCREAMS, 'You bitch!'\n");
  load_a_chat("Lykker tries to kick you in the privates.\n");
  load_a_chat("The gigolo SCRATCHES your face.\n");

gold = clone_object("obj/money");
gold->set_money(1800);
move_object(gold,this_object());
}

init() {
  ::init();
  add_action("pleasure","pleasure");
}

monster_died() {
int num;
num = random(100);
if(num == 8 || num == 27 || num == 59 || num == 68 || num == 91) {
  write("As you deliver the killing blow, you rip open a major artery\n"+
	"and blood spatters the side of the cave and hits you square\n"+
	"in the face.\n");
  move_object(clone_object("players/eurale/closed/VD.c"),tp);
  write_file("/players/eurale/Glade/LOG/hookers",
  ctime(time())+"       mVD       "+tp->query_real_name()+"\n");
  return 1; }
return 0; }

pleasure(str) {
if(!str) {
  write("'Pleasure?  That's why I'm here', giggles Lykker\n");
  return 1; }
if(str == "me") {
if(tp->query_gender() == "male") {
  write("Lykker spits in your face and screams...\n"+
	BOLD+"     I don't do men you PERVERT!"+NORM+"\n");
  attack_object(this_player());
  return 1; }
if(present("tampon",tp)) {
  player = this_player();
  call_out("no_tampon",1);
  return 1; }
if(tp->query_money() < 1000) {
  write("Lykker snickers, 'You can't afford me!\n");
  return 1; }
else { tp->add_money(-1000); }
this_object()->add_money(100);
  if(money > 1950) money = 1900 + random(100);
write("Lykker smiles, takes your money and says, 'Thanks... now\n"+
      "lets get down to the nitty gritty and give you what you paid\n"+
	"for...'\n\n");
player = this_player();
write_file("/players/eurale/Glade/LOG/hookers",
  ctime(time())+"     Lick job     "+tp->query_real_name()+"\n");
if(random(100) < 30 && !present("crotchrot",tp)) {
  write_file("/players/eurale/Glade/LOG/hookers",
    ctime(time())+"     ** VD **     "+tp->query_real_name()+"\n");
  move_object(clone_object("players/eurale/closed/VD"),tp);
  return 1; }
this_object()->set_chat_chance(0);
call_out("bj",11);
return 1; }
}

no_tampon() {
object cob;
cob = present("tampon",player);
tell_object(player,
  "Lykker slowly looks you over and his eyes grow big.  He moves in\n"+
  "very close and says, 'I'll not have any obstructions once I get\n"+
  "going so let's get rid of this.'  He takes your tampon and throws\n"+
  "it deeper into the cave.  Then he whispers, 'Don't be embarrassed,\n"+
  "you'll be glad it's not in the way!'\n\n");
destruct(cob);
return 1; }

bj() {
tell_object(player,
  "Lykker slowly removes your armor.  He is very gentle and his eyes\n"+
  "sparkle as he takes off layer after layer, exposing more and more\n"+
  "of you.  He whispers, 'I'm really going to enjoy doing this to\n"+
  "you.\n\n");
call_out("bj2",15);
return 1; }

bj2() {
tell_object(player,
  "As the last piece is removed, he whistles softly under his breath.\n"+
  "You stand there in your nakedness and he reaches down and unties\n"+
  "his skimpy loincloth and lets it fall to the floor exposing his\n"+
  "male hardness.  His hands lightly slide down over your body starting\n"+
  "at your neck and ending at your hips.  He kisses you gently.\n\n");
call_out("bj3",20);
return 1; }

bj3() {
tell_object(player,
  "He looks directly into your eyes and winks.  He then slowly lowers\n"+
  "you onto the soft, fragrant mat he has on the cave floor.  He kisses\n"+
  "you again, this time deeper and then plants little kisses upon your\n"+
  "neck and ears.  His gentle hand lightly glides across your pubic\n"+
  "hair and comes to rest gently on your right breast.\n");
call_out("bj4",25);
return 1; }

bj4() {
tell_object(player,
  "His kisses get more passionate and he explores your body with his\n"+
  "hands.  He gently kisses your neck and then travels slowly down to\n"+
  "your erect nipples.  He circles your nipples with his tongue and\n"+
  "softly sucks at the nipple.  He kisses you tenderly between your\n"+
  "breasts and continues moving down.\n\n");
call_out("bj5",25);
return 1; }

bj5() {
tell_object(player,
  "He kisses your belly button and you feel his tongue circle it.  He\n"+
  "moves farther down and you can feel his hot breath as he nuzzles\n"+
  "softly in your pubic hair.  Gently, he spreads your legs.  He kisses\n"+
  "your inner thigh and his tongue touches the lips of your labia.  A\n"+
  "soft kiss and then his tongue gently caresses your clitoris.  He\n"+
  "slowly rubs his tongue across your clitoris, bringing you ever\n"+
  "closer to that climactic moment.\n\n");
call_out("bj6",30);
return 1; }

bj6() {
tell_object(player,
  "As the heat of the moment reaches almost unstandable heights, he\n"+
  "quickly withdraws and lays down besides you.  He embraces you and\n"+
  "slowly turns you so that you're on top of him.  As his hands find\n"+
  "the hard nipples of your breasts and begin to massage them, he\n"+
  "enters you.  Entwined legs allow you to get maximun penetration.\n"+
  "You rock up and down, enjoying the sensation.  You feel his legs\n"+
  "stiffen as you cry out in ecstasy.... and then all is still.  He \n"+
  "withdraws and says, 'Thanks, you were terrific!' and then stands\n"+
  "to indicate your time is up.\n\n");
this_object()->set_chat_chance(13);
return 1; }
