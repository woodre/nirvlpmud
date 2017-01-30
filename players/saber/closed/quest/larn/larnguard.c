inherit "/obj/monster";
object ob, ob2;

reset(arg) {
  ::reset(arg);
  if(arg) return;
ob = clone_object("/players/saber/weapons/lspear.c");
move_object(ob,this_object());
ob2 = clone_object("/players/saber/armor/larnam.c");
move_object(ob2, this_object());
     init_command("wear amulet");
     init_command("wield spear");
     set_name("guard");
     set_short("A warrior priest of larn");
     set_alt_name("warrior");
     set_alias("priest");
     set_race( "human");
     set_long("The warrior priest is one of many guardians of the church of larn\n"+
        "against the forces of evil.  They are protectors of the weak and\n"+
        "champions of justice.\n");
     set_gender("male");
     set_level(19);
     set_ac(20);
     set_wc(30);
     set_hp(575);
     set_al(900);
     set_aggressive(0);
     set_chance(10);
     set_spell_dam(50);
     set_spell_mess1("\nThe warrior priest calls down the power of Larn upon his foe!\n");
     set_spell_mess2("\nThe warrior priest calls down the power of Larn upon you!\n");

set_object(this_object());
   set_function("hi_there");
   set_type("arrives");
   set_match("");

}
notify(str)  {
  say(str);
}

hi_there(str) {
string who;
if(sscanf(str, "%s arrives.", who) == 1)  {
  notify("The warrior priest of larn nods at "+who+".\n");
}  }

init()  {
  ::init();
   add_action("pass","north");
   add_action("pass","east");
   add_action("pass","west");
        }

pass()  {
if(this_player()->query_alignment() < 0)  {
  say("The warrior priest steps in front of "+this_player()->query_name()+".\n"+
    "The warrior priest glares and says \"\Evil shall not pass...\"\n");
  return 1;
        }
say("The warrior priest lets "+this_player()->query_name()+" pass.\n");
        }
