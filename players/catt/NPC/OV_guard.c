inherit "obj/monster";
#include "/players/catt/AREAS/base_defines.c"
reset(arg) {
   object obj1;
   object obj2;
   object obj3;
   object obj4;
   object obj5;
   ::reset(arg);
   if(arg) return;
   set_name("orc guard");
   set_alias("orc");
   set_short("orc guard");
   set_long("An orc guard. A grey-green humaniod figure covered in \n"+
            "course hair with a slightly stooped posture, a snout instead\n"+
            "of a nose, short pointed ears, and sharp pointed teeth.\n");
   set_level(10);
   set_race("orc");
   set_hp(150+random(50));
   set_al(-500);
   set_wc(8);
   set_ac(3);
   set_aggressive(1);
   enable_commands();
   set_random_pick();
   obj1 = clone_object(ARM+"orcarmour");
   if(obj1) {
      move_object(obj1, this_object());
      command("wear "+obj1->query_name());
      }
   switch(random(4)) {
      case 0 : obj2 = clone_object(WPN+"orcsword"); break;
      case 1 : obj2 = clone_object(WPN+"orcaxe"); break;
      case 2 : obj2 = clone_object(WPN+"orcflail"); break;
      case 3 : obj2 = clone_object(WPN+"orchammer"); break;
   }
   if(obj2) {
      move_object(obj2, this_object());
      command("wield "+obj2->query_name());
      }
   switch(random(3)) {
      case 0 : obj3 = clone_object(ARM+"orcgloves"); break;
      case 1 : obj3 = clone_object(ARM+"orchelmet"); break;
      case 2 : obj3 = clone_object(ARM+"orcshield"); break;
   }
   if(obj3) {
      move_object(obj3, this_object());
      command("wear "+obj3->query_name());
   }
}
