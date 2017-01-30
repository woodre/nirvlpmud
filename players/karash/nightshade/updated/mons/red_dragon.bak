inherit "obj/monster";
object wep, elf, gold;
reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("hephastus");
   set_alias("wyrm");
   set_alt_name("dragon");
   set_short("Hephastus the Red Dragon");
   set_long
   ("Hephastus is a mighty red dragon many centuries old. He has seen\n"+
      "many a battle and devoured even more opponents. His blood red scales\n"+
      "shine and his huge, heaving body swells with each great breath. Nearly\n"+
      "80 feet long he is by far one of the largest wyrms alive. Best be\n"+
      "careful with this one.\n");
   set_level(20);
   /* Changed from 475 to 525 - Snow */
   set_hp(525);
   set_al(-1000);
   set_ac(17);
   set_wc(50);
   set_chance(10);
   set_spell_dam(75);
   set_spell_mess1("You are almost blinded as Hephastus breaths a huge cone of fire!");
   set_spell_mess2("Hephastus inhales deeply and spews a cone of fire at you!");
}

id(str) { return (::id(str) || str == "hephastus the red dragon" || str == "red dragon"); }
