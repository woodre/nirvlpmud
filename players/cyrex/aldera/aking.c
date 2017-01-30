inherit "obj/monster";
object sceptre;
int items;
reset(arg) {
        if(arg) return;

        set_name("aldera king");
        set_alias("king");
        set_level(20);
        set_wc(35);
        set_ac(25);
set_dead_ob(this_object());
set_hp(2010);
         set_short("King of Aldera");
         set_long("The ruler of the kingdom Aldera. He a huge man with a grey\n"+
                  "beard showing signs of age. For a man his age, he looks awefully\n"+
                  "powerful! Don't attack him unless you are willing to deal\n"+
                  "with his Royal Guards afterwards...\n");
set_chance(15);
set_spell_mess1("The king parries the attack!\n");
set_spell_mess2("The king dealt you a mighty blow!\n");
set_spell_dam(20);

set_chat_chance(10);
load_chat("The King says: I am getting old.\n");
load_chat("The King looks you over.\n");
load_chat("The King says: Why, what have we here? A visitor?\n");
set_a_chat_chance(20);
load_a_chat("The King ignores your feeble attacks.\n");
load_a_chat("The King says: You must not continue...or else!\n");

          set_al(-1000);
          set_race("human");
          set_aggressive(0);

sceptre=clone_object("players/cyrex/aldera/asceptre");
move_object(sceptre, this_object());

          ::reset(0);

}

monster_died(obj) {
write("As the almighty king slumps to the floor dead, his trusted guards\n"+
"come racing in!\n\n");
write("The Royal Guards gasps in astonishment!\n");
write("You will never leave here alive!\n");
move_object(clone_object("players/cyrex/aldera/aguardx"),
environment(this_object()));
move_object(clone_object("players/cyrex/aldera/aguardx"),
environment(this_object()));
return 0;
}
