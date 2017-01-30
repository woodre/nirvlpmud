/* Mod'd by Verte so only one may be summoned by a player per reboot
*/
inherit "obj/monster";

object gold, disc;
int totaldam, rounds;

reset(arg) {
   ::reset(arg);
   if(!arg) {
      set_name("judge");
      set_short("An insectoid judge");
      set_race("insect");
      set_long(
         "A twisted and cruel looking insectoid creature.  He seems to be clicking\n"+
         "and gurgling to himself.  He has long pincers and a segmented frame.\n"+
         "He seems to be quite capable of killing and mangling.  Perhaps you should\n"+
         "ask him something instead?  Maybe about how to escape this forsaken place?\n"+
         "Insect can and will kill other players!\n");
      gold = clone_object("obj/money");
      gold -> set_money (random (3500) + 14);
      move_object(gold, this_object());
      move_object(clone_object("/players/unsane/closed/hell/claw.c"), this_object());
      disc = clone_object("players/unsane/closed/hell/disc");
      move_object(disc, this_object());
      set_level(20);
      set_ac(17);
      set_wc(30);
      set_hp(9000 + random(1000));
      set_al(-1000);
      set_aggressive(0);
      set_dead_ob(this_object());
set_heart_beat(1);
   }
}
heart_beat() {
object ob;
object wep;
ob = this_object()->query_attack();
if (!ob) rounds = totaldam = 0;
if (ob)
tell_room(environment(this_object()), "--------------------------------------------------=\n");
  ::heart_beat();

if (ob)
{
rounds++;
if (rounds == 100 || rounds == 200 || rounds == 300 || rounds == 400 || rounds == 500 || rounds == 600 || rounds == 700 || rounds == 800 || rounds == 900 || rounds == 100) set_ac(17);
totaldam += (max_hp-hit_point);
tell_room(environment(this_object()), rounds+"\tAverage: "+((totaldam*100)/rounds)+"\n");
hit_point = max_hp;
ob->heal_self(1000);
wep = ob->query_weapon();
wep->set_hits(1);wep->set_misses(1);
tell_room(environment(this_object()), "===================================================\n");
if (rounds >= 1000) {
  stop_fight(); ob->stop_fight();
}
}
else set_ac(17);
}

monster_died()
{
   object ob;
   ob = first_inventory(environment());
   while(ob) { 
      if(ob->query_attack() == this_object())
         "/players/unsane/closed/hell/circle1"->add_judge_killa((string)ob->query_real_name());
      ob = next_inventory(ob);
   }
   return 0;
}
