inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if(!arg) {
    set_name("professor");
set_alias("professor x");
set_short("Professor X");
    set_race("xman");
    set_long(
"  This is Professor Charles Xavier.  This mansion and this school is his \n"+
"dream.  He wanted a place where he could train young mutants and instruct\n"+
"on their place in society.  He envisions a society where humankind and\n"+
"mutantkind can coexist peacefully.  He is a bald man in is 40's perhaps, though\n"+
"he may be older.  An accident in his youth has crippled him and he\n"+
"relys on his wheelchair for transportation.  But don't let that fool\n"+
"you.  He is the world's strongest telepath.\n");
gold = clone_object("obj/money");
gold -> set_money (random (2000) + 1000);
move_object(gold, this_object());
move_object(clone_object("/players/unsane/xmen/ring.c"),this_object());
   set_level(20);
   set_ac(40);
   set_wc(20);
   set_hp(1000);
   set_al(600);
/*
set_chance(20);
set_spell_dam(75);
set_spell_mess2("Professor X blasts you with a mental bolt!");
set_spell_mess1("Professor X concentrates and his foe screams in pain!");
*/
  set_wc_bonus(10); /* (75/2 * .2 * 1.25 ~ 10 */
  set_aggressive(0);
    set_a_chat_chance(10);
   set_chat_chance(10);
load_chat("Professor X says: My old fried, I cannot accept this plan.\n");
load_chat("Professor X says: You sound more like Wolverine than yourself Magneto.\n");
load_chat("Professor X sighs sadly.\n");
load_chat("Professor X says:  Humankind and Mutantkind _can_ live together.\n");
load_chat("Professor X says: I will not abandon the dream Magneto.\n");
load_a_chat("The Professor erects a psychic shield.\n");
load_a_chat("Professor X says: You see, Magneto, the humans are frightened of us.\n");
load_a_chat("Professor X says: You should leave now...I don't wish to hurt you.\n");
load_a_chat("Professor X shakes his head.\n");
}
}

heart_beat()
{
     ::heart_beat();
     if(attacker_ob && !random(5))
       mental_bolt();
}

mental_bolt()
{
     tell_object(attacker_ob, "Professor X blasts you with a mental bolt!\n");
     tell_room(environment(), "Professor X concentrates and " + (string)attacker_ob->query_name() + " screams in pain!\n", ({ attacker_ob }));
     attacker_ob->hit_player(random(75), "other|mental");
}
