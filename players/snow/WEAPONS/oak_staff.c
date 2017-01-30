/*
A staff with spells capabilities.
*/
 
#define TP this_player()
#define TPS call_other(TP,"query_attrib","str")
#define TPI call_other(TP,"query_attrib","int")
#define TPW call_other(TP,"query_attrib","wil")
#define MEAT TP->query_attack()
#define MEATN capitalize(MEAT->query_name())
#define GEN TP->query_possessive()
#define TPN capitalize(TP->query_name())
 
int dartnum, firenum, boltnum, drainnum;
 
inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("oak staff");
    set_alias("staff");
    set_short("An Oak Staff");
    set_long(
"This is an oak staff about 6 feet long. It has engraved silver writing.\n");
    set_read("The silver writing reads:\n"+
"  To set spells you wish to cast, 'staffspell <spell name>'\n"+"\n"+
"SPELLS: dart, fire, bolt, drain\n"+"\n");
    set_class(15);
    set_weight(3);
    set_value(15000);
    set_hit_func(this_object());
dartnum = 0;
firenum = 0;
boltnum = 0;
drainnum = 0;
    set_save_flag(0);
}
 
init() {
  ::init();
add_action("staff_spell","staffspell");
}
 
weapon_hit() {
int W;
    W = random(50);
attack_spell();
  if(W < TPS)  {
  say(TPN+" crushes "+MEATN+" with "+GEN+" oak staff!\n");
  write("You crush "+MEATN+" with your oak staff!\n");
return TPS/3;
   }
       return;
}
 
staff_spell(arg) {
  if(!arg) { write("Staffspell <spell name>\n"); return 1; }
  if(!(arg == "dart" || arg == "fire" || 
       arg == "bolt" || arg == "drain")) {
     write(capitalize(arg)+" is not a staff spell.\n");
  return 1;
  }
  if(arg == "dart") {
     if(TP->query_level() < 5) { 
       write("You are not high enough level to activate this spell.\n");
     return 1;
     }
    write("Dart is now activated as a staff spell.\n");
dartnum = 1;
  return 1;
  }
  if(arg == "fire") {
     if(TP->query_level() < 15) { 
       write("You are not high enough level to activate this spell.\n");
     return 1;
     }
    write("Fire is now activated as a staff spell.\n");
firenum = 1;
  return 1;
  }
  if(arg == "bolt") {
     if(TP->query_level() < 15) { 
       write("You are not high enough level to activate this spell.\n");
     return 1;
     }
    write("Bolt is now activated as a staff spell.\n");
boltnum = 1;
  return 1;
  }
  if(arg == "drain") {
     if(TP->query_level() < 18) { 
       write("You are not high enough level to activate this spell.\n");
     return 1;
     }
    write("Drain is now activated as a staff spell.\n");
drainnum = 1;
  return 1;
  }
}
 
attack_spell() {
  int num, num2, mindnum, Y;
num = (dartnum + firenum + boltnum + drainnum)*25;
num2 = random(200);
mindnum = TPI + TPW;
Y = random(20);
  if(!MEAT->query_npc()) return 1;
 if(num > num2) {
   if(random(50) < mindnum) {
     if(Y < 10) {
       if(dartnum == 1) {
         write("You send magic darts burning into "+MEATN+"!\n");
       TP->spell_object(MEAT,"Magic Darts",6,10);
       }
     return 1;
     }
     if(Y > 9 && Y < 14) {
       if(firenum == 1) {
         write("You blast a stream of fire into "+MEATN+"!\n");
        TP->spell_object(MEAT,"Stream of Fire",15,20);
       }
     return 1;
     }
     if(Y > 13 && Y < 18) {
       if(boltnum == 1) {
         write("You fry "+MEATN+" with a bolt of lightning!\n");
        TP->spell_object(MEAT,"Bolt of Lightning",15,20);
       }
     return 1;
     }
     if(Y > 17) {
       if(drainnum == 1) {
         write("You drain the life force from "+MEATN+"!\n");
       TP->spell_object(MEAT,"Life Drain",20,40);
call_other(TP,"add_hit_point",random(5)+2);
         write("You feel stronger!\n");
       }
     return 1;
     }
   }
 }
return 1;
}
