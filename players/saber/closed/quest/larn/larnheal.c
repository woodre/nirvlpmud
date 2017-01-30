inherit "/obj/monster";
object ob, ob2;

reset(arg) {
  ::reset(arg);
  ob2 = clone_object("/players/saber/armor/larnam.c");
  move_object(ob2, this_object());
if (!arg){
     init_command("wear amulet");
     set_name("guard");
     set_short("A priestess of larn");
     set_alias("priestess");
     set_race( "human");
     set_long("This priestess of Larn has been bless with the power to summon\n"+
      "holy food and drink.  If you wish to be healed, eat with her.\n"+
      "\nFor 1000 coins, you may type <feast> and be healed.\n"+
      "For FREE, you may type <cure_me>, and be cured of a disease.\n\n");
     set_gender("female");
     set_level(19);
     set_ac(20);
     set_wc(30);
     set_hp(575);
     set_al(900);
     set_aggressive(0);
     set_chance(10);
     set_spell_dam(50);
     set_spell_mess1("\nThe priestess calls down the power of Larn upon his foe!\n");
     set_spell_mess2("\nThe priestess calls down the power of Larn upon you!\n");

set_object(this_object());
   set_function("hi_there");
   set_type("arrives");
   set_match("");
   }

}

hi_there(str) {
string who;
if(sscanf(str, "%s arrives.", who) == 1)  {
  say("The priestess smiles at "+who+".\n");
}  }

init()  {
  ::init();
  add_action("feast","feast");
  add_action("cure_me","cure_me");
        }


feast()  {

  if(this_player()->query_money() < 1000)  {
    write("You must have 1000 coins before you may feast.\n");
  return 1;
        }

  write("The priestess serves you a Hero's Feast.\n"+
    "\nYou drink blessed mead.\n\nYou eat blessed bread.\n"+
    "\nYou feel your strength return!\n");
  say(this_player()->query_name()+" is served a Hero's Feast.\n");
  call_other(this_player(), "eat_food", 14);
  call_other(this_player(), "heal_self", 50);
  call_other(this_player(), "drink_alcohol", 14);
  call_other(this_player(), "heal_self", 50);
  call_other(this_player(), "add_money", -1000);
  return 1;
        }


cure_me()  {
object ob, ob2;
  ob = present("disease", this_player());
  if(!ob)  {
  write("You do not have a disease.\n");
  return 1;
            }
  write("\nThe priest lays hands on you.\n"+
        "You have been cured.\n");
  ob2 = clone_object("/players/saber/closed/virus/no_disease.c");
  move_object(ob2, this_player());
  destruct(ob);
  return 1;
            }
