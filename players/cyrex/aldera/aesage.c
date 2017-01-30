inherit "obj/monster";
object staff;
int items;
reset(arg) {
        if(arg) return;

        set_name("elven sage");
        set_alias("sage");
        set_level(20);
        set_wc(35);
        set_ac(25);
set_dead_ob(this_object());
set_hp(2010);
         set_short("Elven Sage");
         set_long("An old wise teacher of the ancient ways. He is the one\n"+
                  "looked upon when situations in the village get out of\n"+
                  "control. He might look short, but he is deadly. Be warned\n"+
                  "do not attack him unless you are willing to face his well\n"+
                  "trained disciples in case he should fall. They WILL NOT\n"+
                  "LET YOU GO until DEATH.\n");
set_chance(15);
set_spell_mess1("The Elven Sage sprinkles some ancient powder.\n");
set_spell_mess2("The Elven Sage sprinkles some ancient powder on you.\n");
set_spell_dam(20);

set_chat_chance(10);
load_chat("Elven Sage says: I am getting old.\n");
load_chat("Elven Sage looks you over.\n");
load_chat("Elven Sage says: Why, what have we here? A visitor?\n");
set_a_chat_chance(20);
load_a_chat("Elven Sage ignores your feeble attacks.\n");
load_a_chat("Elven Sage says: You must not continue...or else!\n");

          set_al(-1000);
          set_race("elf");
          set_aggressive(0);

staff=clone_object("players/cyrex/aldera/aestaff");
move_object(staff, this_object());

          ::reset(0);

}

monster_died(obj) {
write("As the elven sage falls to the ground and breathes his last breath,\n"+
"two of his most loyal and skilled disciples come running in!\n\n");
write("Elven Disciple screams: What have you done foolish mortal!\n");
write("Elven Disciple screams: You shall pay with your own life!\n");
move_object(clone_object("players/cyrex/aldera/aedisciple"),
environment(this_object()));
move_object(clone_object("players/cyrex/aldera/aedisciple"),
environment(this_object()));
return 0;
}
