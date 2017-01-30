inherit "obj/monster";

reset(arg) {
   ::reset(arg);
   if(arg) return;
   switch(random(18)+1) {
      case 1:
         set_name("Play-doh Dinosaur");
         set_alias("dinosaur");
         break;
      case 2:
         set_name("Play-doh Dog");
         set_alias("dog");
         break;
      case 3:
         set_name("Play-doh Woman");
         set_alias("woman");
         break;
      case 4:
         set_name("Play-doh Cat");
         set_alias("cat");
         break;
      case 5:
         set_name("Play-doh Elephant");
         set_alias("elephant");
         break;
      case 6:
         set_name("Play-doh Monkey");
         set_alias("monkey");
         break;
      case 7:
         set_name("Play-doh Boy");
         set_alias("boy");
         break;
      case 8:
         set_name("Play-doh Girl");
         set_alias("girl");
         break;
      case 9:
         set_name("Play-doh Pig");
         set_alias("pig");
         break;
      case 10:
         set_name("Play-doh Cow");
         set_alias("cow");
         break;
      case 11:
         set_name("Play-doh Chicken");
         set_alias("chicken");
         break;
      case 12:
         set_name("Play-doh Goat");
         set_alias("goat");
         break;
      case 13:
         set_name("Play-doh Lion");
         set_alias("lion");
         break;
      case 14:
         set_name("Play-doh Wolf");
         set_alias("wolf");
         break;
      case 15:
         set_name("Play-doh Hippo");
         set_alias("hippo");
         break;
      case 16:
         set_name("Play-doh Bird");
         set_alias("bird");
         break;
      case 17:
         set_name("Play-doh Snake");
         set_alias("snake");
         break;
      case 18:
         set_name("Play-doh Lizard");
         set_alias("lizard");
         break;
   }
   set_race("play-doh");
   set_level(6);
   set_hp(90);
   set_al(0);
   set_long("The Play-doh creature is full of bright play-doh colors.\n");
   set_wc(10);
   set_ac(5);
   set_alt_name("rand_playdoh");
   move_object(clone_object("/players/llew/Toys/misc/playdoh.c"),this_object());
}
