inherit "obj/monster";
object armor;
object gold;

reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("Toilet");
   set_race("toilet");
   set_alias("toilet");
   set_long("This toilet has some nasty shit floating in it, maybe you\n"+
      "should flush it.\n");
   set_level(14);
   set_hp(195);
   set_al(-500);
   set_wc(22);
   set_ac(12);
   gold=clone_object("obj/money");
   gold->set_money(350);
   move_object(gold,this_object());
   armor=clone_object("/players/emerson/armor/ucondom.c");
   move_object(armor, this_object());
}
init() {
   ::init();
   add_action("flush","flush");
   add_action("kill", "kill");
   add_action("kill","attack");
}
flush(str) {
   if(str=="toilet") {
      this_player()->attacked_by(this_object());
      write("You tried to flush the toilet and he got very pissed!\n");
      say(capitalize(this_player()->query_real_name())+" tried to flush the toilet and it got very pissed!\n");
      return 1;
   }
}
kill(str) {
   if(id(str)){
      write("You can not \"kill\" toilet.\n");
      return 1;
   }
   return 0;
}
