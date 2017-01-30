
#include "/players/eurale/closed/ansi.h"
#define tpn this_player()->query_name()  /* player name  */
#define tp this_player()
object player;
object player,tob;

id(str) { return str == "interferon"; }
short() { return "Interferon"; }
query_save_flag() { return 1; }
query_value() { return 1050; }

long() { write(
  "This is a small vial of greenish liquid with a needle on one end\n"+
  "and a syringe on the other to inject it.  It has potential life-\n"+
  "saving qualities but is very experimental and not thoroughly tested\n"+
  "yet.  The manufacturer makes no guarantees, either written or\n"+
  "express concerning th is product.  Just 'inject interferon'.\n");
  }

reset(arg) {
  if(arg) return;
}

init() {
  add_action("inject","inject"); }

inject(str) {
int num;
if(!str) { write("Usage: inject interferon\n"); return 1; }
if(str == "interferon") {
num = random(100);
if(num == 21 || num == 49 || num == 52 || num == 74 || num == 92) {
  write_file("/players/eurale/Glade/LOG/hookers",
  ctime(time())+"     VD cured     "+tp->query_real_name()+"\n");
  call_out("cured",1);
  player = this_player();
  tob = this_object();
  return 1; }
if(num == 11 || num == 37 || num == 68 || num == 71 || num == 89) {
  write_file("/players/eurale/Glade/LOG/hookers",
  ctime(time())+"     VD Cured     "+tp->query_real_name()+"\n");
  call_out("cured2",1);
  player = this_player();
  tob = this_object();
  return 1; }
if(num == 7 || num == 77) {
  write_file("/players/eurale/Glade/LOG/hookers",
  ctime(time())+"     Cure/die     "+tp->query_real_name()+"\n");
  call_out("dies_anyway",1);
  player = this_player();
  tob = this_object();
  return 1; }
else {
  write("You carefully select a spot.  You puncture the skin with\n"+
	"the razor-tipped needle and painfully inject the greenish\n"+
   "liquid into your system.  There is a stinging sensation.  You\n"+
	"pray the drug works as you carefully dispose of the empty\n"+
	"needle.\n");
  say(tpn+" injects "+tp->query_objective()+"self with interferon.\n");
  tp->heal_self(400);
  tp->recalc_carry();
  destruct(this_object());
  return 1; }
return 1; }
}

cured() {
object ob;
ob = present("crotchrot",environment(this_object()));
tell_object(player,
	"You stick the razor-tipped needle through your skin and slowly\n"+
	"squeeze all the greenish liquid into your veins.  Your body\n"+
	"feels as if it had liquid fire coursing through it.  Your\n"+
	"ears begin to ring and your heart begins to pound.  Then,\n"+
	"violently you retch....  As your heart begins to slow, you\n"+
	"realize you feel better but weaker.\n");
environment()->raise_strength(-5);
environment()->raise_magic(-4);
destruct(ob);
destruct(tob);
return 1; }

cured2() {
object ob;
ob = present("crotchrot",environment(this_object()));
tell_object(player,
  "You close your eyes and plunge the needle through your skin.  An\n"+
  "intese burning begins to course through your body.  You begin to\n"+
  "sweat profusely and then you go into CONVULSIONS.  When you stop\n"+
  "you feel drained and weak....\n");
environment()->raise_stamina(-4);
environment()->raise_strength(-5);
environment()->raise_magic(-4);
destruct(ob);
destruct(tob);
return 1; }

dies_anyway() {
tell_object(player,
  "The razor-tipped needle stings as it punctures your skin.  You\n"+
  "push the plunger and inject all of the greenish fluid into your\n"+
  "diseases body.  There is a calming sensation.....\n\n");
call_out("dies2",1);
return 1; }

dies2() {
object ob;
ob = present("crotchrot",environment(this_object()));
tell_object(player,
  "Suddenly, your heart begins to beat very fast.  It feels as if it\n"+
  "might jump right out of your chest.  Then PAIN!!!!  You feel your\n"+
  "heart stop and in that instant... you know you're going to die.\n");
destruct(ob);
destruct(tob);
player->hit_player(1000);
return 1; }

get() { return 1; }
query_weight() { return 1; }
