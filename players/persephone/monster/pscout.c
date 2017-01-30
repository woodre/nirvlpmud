inherit "obj/monster";
object cutlass,glove;
string chats;
reset(arg) {
 ::reset();
  if (arg) return;
   cutlass = clone_object("/players/persephone/weapon/cutlass.c");
   move_object(cutlass, this_object());
   glove = clone_object("/players/persephone/armour/glove.c");
   move_object(glove, this_object());
   set_name("pirate");
   set_level(13);
   set_al(-100);
   set_short("A pirate scout");
   set_long("One of the famed advance scouts of Long John Sliver.\n"+
            "You wonder why you see him so far away from his master.\n");
   set_hp(195);
   init_command("wield cutlass");
   init_command("wear glove");
   set_wc(17);
   set_ac(10);
   set_aggressive(0);
   set_chance(5);
   set_spell_dam(10);
   set_spell_mess1("Skillfully thrusts his cutlass.\n");
   set_spell_mess2("Strikes you with a sudden slice of his cutlass\n");
   if(!chats){
    chats=allocate(4);
    chats[0]="Ahoy me hearties what are you doing here.\n";
    chats[1]="This is Sliver's land he don't allow the likes of you around\n";
    chats[2]="What have you and Jenny done with the others\n";
    chats[3]="You know you should be cleaning up the bilges\n";
   }
   load_chat(12,chats);
}
