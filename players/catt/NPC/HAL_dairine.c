inherit "obj/monster";
#include "/players/catt/AREAS/base_defines.c"
object demon;
reset(arg) {
object armor;
object weapon;
object money;
object spell;
::reset(arg);
if(arg) return;
set_name("dairine");
set_alias("sorceress");
set_short("Dairine the Dark Heart");
set_long("You see the evil sorceress in her prime. She wears a \n" +
    "cloak of darkness and it seems to boggle the eye as you try\n" +
    "pin point her exact location. She is cunning and very, very\n" +
    "beautiful, having long flaming red hair with emerald green\n" +
    "eyes. If you could you would try to take her for your own.\n");
set_level(17);
set_race("human");
set_hp(800);
set_al(-200);
set_wc(5);
set_ac(14);
add_spell("Magic Missle",
   "#MN# chants softly and you are hit by several magic missiles.\n",
   "#MN# chants softly and #TN# is hit by several magic missiles.\n",
   70, ({5,5,5,5}),({"magical","other|fire","other|ice","magical"}));

add_spell("Enervation Cloud",
   "#MN# raises her hands in the air and chants loudly. \n"+
   "A cloud of pure darkness forms around you.\n",
   "#MN# raises her hands in the air and chants loudly. \n"+
   "A cloud of pure darkness forms around #TN#.\n",
   10, 20, "other|dark", 1);

add_spell("Flamestrike",
   "#MN# gestures and a flamestrike hits you.\n",
   "#MN# gestures and a flamestrike slams into #TN#.\n",
   10,20,"other|fire");

set_multi_cast(0);
weapon = clone_object(MAGICAL+"tele");
if(weapon) {
move_object(weapon, this_object());
command("wield "+weapon->query_name(), this_object());
      }
spell = clone_object(MAGICAL+"flamestrike");
if(spell) {
  move_object(spell, this_object());
}
armor = clone_object(ARM+"black_cloak");
   if(armor) {
   move_object(armor, this_object());
     }
money = clone_object("obj/money");
money->set_money(800);
move_object(money, this_object());
set_heart_beat(1);
}
heart_beat() {
object ob;
if(query_attack()) {
   if(random(100) < 10) {
  say("Sorceress summons a fire demon to her side\n");
  write("Sorceress summons a fire demon to her side\n");
demon = clone_object(NPC+"firedemon");
move_object(demon, environment(this_object()));
}
  attack();
::heart_beat();
}
}
