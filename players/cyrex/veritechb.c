inherit "obj/monster";
object gold, cannon;
int items;
reset(arg) {
        if(arg) return;

        set_name("Veritech");
        set_alias("veritech");
        set_alt_name("fighter");
        set_level(20);
        set_wc(30);
        set_ac(15);
set_dead_ob(this_object());
set_hp(750);
set_ep(5000);
         set_short("Veritech Fighter");
         set_long("A massive mech that posesses awesome fire power. It is\n"+
                  "capable of mechamorphisis where it can transform into\n"+
                  "three different types of battle modes. It is currently in\n"+
                  "battloid mode. It wields a mighty shuriken pulse cannon\n"+
                  "which provides awesome added power.\n");
set_chance(30);
set_spell_mess1("The Veritech crushes you under him!!\n");
set_spell_mess2("The Veritech has struck you with a mighty blow!\n");
set_spell_dam(20);

set_chat_chance(10);
load_chat("Veritech booms: The battle is over.\n");
load_chat("Veritech booms: The Zentradis' have been defeated.\n");
load_chat("Veritech booms: How may I be of assistance?\n");
set_a_chat_chance(20);
load_a_chat("Veritech ignores your measily attacks.\n");
load_a_chat("Veritech booms: You must cease this foolishness at once.\n");

          set_al(-1000);
          set_race("mech");
          set_aggressive(0);

gold=clone_object("obj/money");
gold->set_money(random(500)+1050);
move_object(gold, this_object());
cannon=clone_object("players/cyrex/cannon");
move_object(cannon, this_object());
init_command("wield cannon");

          ::reset(0);

}

monster_died(obj) {
write(
"As the Veritech explodes into flames, you see the veritech pilot eject!\n\n");
write("Veritech pilot screams: What have you done?\n");
write("Veritech pilot slaps you hard!\n");
move_object(clone_object("players/cyrex/vpilot"),
environment(this_object()));
return 0;
}

