object lucky, gold;
inherit "obj/monster";

reset(arg) {
::reset(arg);
if(!arg) {
set_alias("gorgon");
set_alt_name("beast");
    set_name("medusa");
set_short("The Gorgon Medusa");
    set_race("demon");
set_long(
"This is the legendary Medusa.  You have heard many rumours about her ability.\n"+
"to turn her foes to stone.  She is a hideous creature; half-female, half \n"+
"reptile.  Her hair is made up of a wiggling mass of poisonous snakes.\n"+
"You can't get a good look at her for fear that you will suffer a hideous death.\n"+
"As soon as she notices you, she charges you.  You have intruded here, and you\n"+
"will have to pay for that.\n");
set_hp(30);
gold = clone_object("obj/money");
gold->set_money(random(5000));
move_object(gold, this_object());
set_chance(5);
set_spell_mess1("Medusa turns her foe to stone!");
set_spell_dam(75);
set_chat_chance(10);
load_chat("Medusa screams: I must have blood!\n");
load_chat("Medusa hisses.\n");
load_chat("The snakes of Medusa's hair writhe about.\n");
set_a_chat_chance(10);
load_a_chat("Medusa says: You fool, I will devour you!\n");
set_spell_mess2("Medusa turns you partially to stone!");
load_a_chat("Medusa cackles at you.\n");
load_a_chat("Medusa doesn't seem to notice your attacks.\n");
   set_level(17);
   set_ac(20);
   set_wc(19);
   set_al(-3000);
set_dead_ob(this_object());
  set_aggressive(1);
}
}
monster_died(){
say("Medusa explodes into a million pieces.\nThe universe wavers for a moment.\n");
move_object(attacker_ob,"/players/unsane/chaos/split.c");
say("any luck?");
return 1;}
shatter(){
say("The entire universe around you begins to melt and then it implodes!\n");
move_object(lucky,"/players/unsane/chaos/split.c");
tell_object(lucky,"You think you are in a new place.\n");
return 1;}
