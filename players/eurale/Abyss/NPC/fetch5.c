#define tp this_player()
#define TO this_object()
#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("fetch");
set_alias("guardian");
set_alt_name("royal guardian");
set_race("creature");
set_short("Royal Fetch Guardian");
set_long(
  "You gaze upon the Royal Guardian who stands watch over the Diva's\n"+
  "door.  Although pale and haggard looking, his eyes are alert and\n"+
  "watchful.  The twisted grin that he gives you is not one of welcome\n"+
  "but one of knowlege about impending death.\n");

set_level(20);
set_hp(500 + random(50));
  set_al(-300 + random(300));
  set_wc(35);
  set_ac(18);
  set_aggressive(1);
  set_dead_ob(this_object());

set_chat_chance(10);
  load_chat("As the fetch looks at you, you feel pure HATRED!\n");
set_a_chat_chance(10);
  load_a_chat("ICY FINGERS curl tightly around your throat!\n");
  load_a_chat("FEAR partially immobilizes you!\n");
  load_a_chat("You stare at the fetch's demonic grin.....\n");

gold = clone_object("obj/money");
gold->set_money(4000 + random(1000));
move_object(gold,this_object());
}

heart_beat() {
  ::heart_beat();
if(TO->query_wc() < 35) set_wc(35);
if(TO->query_ac() < 18) set_ac(18);

if(present("pet",environment(TO))) {
  call_out("kill_pet",1);
  return 1; }
if(present("dragon",environment(TO))) {
  call_out("kill_dragon",1);
  return 1; }
if(present("spinal",environment(TO))) {
  call_out("kill_skeleton",1);
  return 1; }
if(present("wolf",environment(TO))) {
  call_out("kill_wolf",1);
  return 1; }
if(present("mech",environment(TO))) {
  call_out("kill_mech",1);
  return 1; }
return 1; }

kill_pet() {
object pob;
pob = present("pet",environment(TO));
tell_room(environment(this_object()),
  HIC+"\nThe fetch's eyes blaze blue...."+NORM+"\n"+
  "A flash of "+HIC+"BRILLIANT BLUE LIGHTNING"+NORM+" arcs to your pet\n"+
  "and when the smoke clears, nothing but ashes remain.\n\n");
  destruct(pob);
return 1; }

kill_dragon() {
object dob;
dob = present("dragon",environment(TO));
tell_room(environment(this_object()),
  "\nThe fetch raises its arms slowly, a smirk crosses its face...\n"+
  "a "+HIR+"RING OF FIRE"+NORM+" encircles your dragon..\n"+
  "and you witness its incineration before your eyes.\n\n");
  destruct(dob);
return 1; }

kill_skeleton() {
object skob;
skob = present("spinal",environment(TO));
tell_room(environment(this_object()),
  "\nThe fetch reaches out and touches your spinal with a boney finger.\n"+
  "The white bones immediately begin to turn "+BOLD+"JET BLACK"+NORM+"\n"+
  "and then CRUMBLE before your eyes...\n\n");
  destruct(skob);
return 1; }

kill_wolf() {
object wob;
wob = present("wolf",environment(TO));
tell_room(environment(this_object()),
  "\nThe fetch strokes your wolf...\n"+
  "     Its fur bursts into "+HIC+"BLUE FLAME"+NORM+"\n"+
  "          And it burns into a charred husk.\n\n");
  destruct(wob);
return 1; }

kill_mech() {
object mob;
mob = present("mech",environment(TO));
tell_room(environment(this_object()),
  "\nThe fetch GLARES at your mech....\n"+
  "You smell burning wires and hear crackling sounds..\n"+
  "and your mech "+BOLD+"EXPLODES"+NORM+" into tiny pieces.\n\n");
  destruct(mob);
return 1; }

monster_died() {
  tell_object(this_player(),
  "The color of envy needs, 'weep ye all with me as the gods are\n"+
  "cast down to their fate'.....and the fetch's eyes go into a blank,\n"+
  "death stare..\n");
  write_file("/players/eurale/Abyss/LOG/abyss",
  tp->query_real_name()+"     "+ctime(time())+"     fetch5\n");
return 0; }
