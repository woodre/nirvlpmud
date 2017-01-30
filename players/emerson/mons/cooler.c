inherit "obj/monster";
object heal;
   object heal2,heal3,heal4;

reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("Cooler");
   set_race("cooler");
   set_alias("cooler");
   set_long("This cooler has some refreshing pepsi in it, maybe you\n"+
      "should open it and grab a cold one.\n");
   set_level(14);
   set_hp(195);
   set_al(500);
   set_wc(22);
   set_ac(12);
   heal=clone_object("/players/emerson/heal/pepsi.c");
   move_object(heal, this_object());
   heal2=clone_object("/players/emerson/heal/pepsi.c");
   move_object(heal2, this_object());
   heal3=clone_object("/players/emerson/heal/pepsi.c");
   move_object(heal3, this_object());
   heal4=clone_object("/players/emerson/heal/pepsi.c");
   move_object(heal4, this_object());
}
init() {
   ::init();
   add_action("open","open");
   add_action("kill", "kill");
   add_action("kill","attack");
}
open(str) {
   if(str=="cooler") {
      this_player()->attacked_by(this_object());
      write("You tried to open the cooler and it got very pissed!\n");
      say(capitalize(this_player()->query_real_name())+" tried to open the cooler and it got very pissed!\n");
      return 1;
   }
}
kill(str) {
   if(id(str)){
      write("You can not \"kill\" cooler.\n");
      return 1;
   }
   return 0;
}
