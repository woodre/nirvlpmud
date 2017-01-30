inherit "obj/monster";

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("cabbage patch kid");
   set_level(6);
   set_alias("kid");
   set_race("doll");
   set_hp(90);
   set_al(25);
   set_alt_name("rand_cabbage");
   set_long("The cute little cabbage patch kid has a loving look on its\n"+
      "face.  It looks like it needs a good family.\n");
   switch(random(8)+1) {
      case 1:
         set_short("A drooling cabbage patch kid");
         break;
      case 2:
         set_short("A crying cabbage patch kid");
         break;
      case 3:
         set_short("A sleeping cabbage patch kid");
         break;
      case 4:
         set_short("A red haired cabbage patch kid");
         break;
      case 5:
         set_short("A twin cabbage patch kid");
         break;
      case 6:
         set_short("A smiling cabbage patch kid");
         break;
      case 7:
         set_short("A wiggling cabbage patch kid");
         break;
      case 8:
         set_short("A crawling cabbage patch kid");
         break;
   }
   set_wc(10);
   set_ac(5);
   set_chat_chance(7);
   load_chat("The cabbage patch kid giggles.\n");
   load_chat("The cabbage patch kid cries.\n");
   load_chat("The cabbage patch kid whines.\n");
   load_chat("The cabbage patch kid says, \"Ga boog eh.\"\n");
   load_chat("The cabbage patch kid wiggles.\n");
   move_object(clone_object("/players/llew/Toys/misc/rand_cabbage_toy"),this_object());
}
