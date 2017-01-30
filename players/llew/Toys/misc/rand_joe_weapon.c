inherit "obj/treasure";

reset(arg) {
   if(arg) return;
   set_id("weapon");
   switch(random(3)+1) {
      case 1:
         set_alias("knife");
         set_short("A plastic knife");
         set_long("The plastic knife looks handy for a G.I.Joe,\n"+
            "but isn't much use to you.\n");
         break;
      case 2:
         set_alias("pistol");
         set_short("A plastic pistol");
         set_long("The plastic pistol looks handy for a G.I.Joe\n"+
            "but isn't much use to you.\n");
         break;
      case 3:
         set_alias("rifle");
         set_short("A plastic rifle");
         set_long("The plastic rifle looks handy for a G.I.Joe\n"+
            "but isn't much use to you.\n");
        break;
   }
   set_value(100);
   set_weight(1);
}
