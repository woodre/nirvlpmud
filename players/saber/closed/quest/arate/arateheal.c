inherit "/obj/monster";
object ob, ob2, ob3;

reset(arg) {
  ::reset(arg);
ob  = clone_object("/players/saber/armor/dark_chainmail.c");
ob2 = clone_object("/players/saber/armor/arateam.c");
ob3 = clone_object("/players/saber/weapons/mace.c");
move_object(ob3, this_object());
move_object(ob2, this_object());
move_object(ob,  this_object());
if (!arg){
     init_command("wear amulet");
     init_command("wear chainmail");
     init_command("wield mace");
     set_name("guard");
     set_short("A priestess of arate");
     set_alias("priestess");
     set_race( "human");
     set_long("This priestess of Arate has been bless with the power to summon\n"+
      "unholy food and drink.  If you wish to be healed, eat with her.\n"+
      "\nFor 1000 coins, you may type <feast> and be healed.\n");
     set_gender("female");
     set_level(19);
     set_ac(17);
     set_wc(30);
     set_hp(525);
     set_al(-900);
     set_aggressive(0);
     set_chance(10);
     set_spell_dam(50);
     set_spell_mess1("\nThe priestess calls down the power of Arate upon her foe!\n");
     set_spell_mess2("\nThe priestess calls down the power of Arate upon you!\n");

set_object(this_object());
   set_function("hi_there");
   set_type("arrives");
   set_match("");
   }

}
notify(str)  {
  say(str);
}

hi_there(str) {
string who;
if(sscanf(str, "%s arrives.", who) == 1)  {
  notify("The priestess looks at "+who+".\n");
}  }

init()  {
  ::init();
  add_action("feast","feast");
        }

feast()  {

  if(this_player()->query_money() < 1000)  {
    write("You must have 1000 coins before you may feast.\n");
  return 1;
        }

  write("The priestess serves you a Dark Feast.\n"+
    "\nYou drink blessed mead.\n\nYou eat blessed bread.\n");
  if(this_player()->query_aligment() > 0)  {
    write("You feel your head explode with unholy fire!\n");
    call_other(this_player(), "eat_food", 15);
    call_other(this_player(), "drink_alcohol", 15);
    call_other(this_player(), "add_money", -1000);
    call_other(this_player(), "heal_self", -50);
    say(this_player()->query_name()+" is served a Dark Feast.\n");
  return 1;
        }
 write("You feel your strength return!\n");
  say(this_player()->query_name()+" is served a Dark Feast.\n");
  call_other(this_player(), "eat_food", 15);
  call_other(this_player(), "heal_self", 50);
  call_other(this_player(), "drink_alcohol", 15);
  call_other(this_player(), "heal_self", 50);
  call_other(this_player(), "add_money", -1000);
  return 1;
        }
