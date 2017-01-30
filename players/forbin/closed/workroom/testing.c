/*  Forbin | Create date:  sep2002.03 | Last mod:  sep2002.03  */

#include "/players/forbin/closed/workroom/define.h"
inherit "/players/forbin/closed/std/room.c";

reset(arg) {
  if(arg) return;

  short_desc = "Testing Room";
  long_desc =  "\n";
  set_light(1);
  add_property("NT");
}

void init() {
  ::init();
  add_action("cmd_list", "list");
  add_action("cmd_grab", "grab");
}

status cmd_list(string str) {
  write("\n"+
    " 1. Armor Set (ac9)\n"+
    " 2. Armor Set (ac13)\n"+
    " 3. Armor Set (ac17)\n"+
    " 4. Fallen Blade\n"+
    " 5. Temblor\n"+
    " 6. Elemental Mace\n"+
    " 7. Maillot Jaune (6 ea.)\n"+
    " 8. d'Huez Leaves (6 ea.)\n"+
    " 9. Galibier Root (6 ea.)\n"+
    "10. Mayias Bark (6 ea.)\n"+    
    "11. Mongie Berries (4 ea.)\n"+
    "12. Museeuw Tonic (4 ea.)\n"+        
    "13. Coins\n"+
    "       You may 'grab [#]'\n");
  return 1;
}

status cmd_grab(string str) {
  int num;
  object thing;
  if(member_array(TP->query_real_name(), TESTERS) == -1) {
    write(this_player()->query_name()+", you are not a tester.\n");
    return 1;
  }
  num = atoi(str);
  if(num < 1 || num > 13) {
    write("You can't grab that.\n");
    return 1;
  }
  switch(num) {
    case 1:
      thing = clone_object("/players/forbin/realms/misc/OBJ/testing_armor.c");
        thing->set_name("leather");
        thing->set_short(HIC+"padded leather armor ["+NORM+"testing armor"+HIC+"]"+NORM);
        thing->set_alias("armor");
        thing->set_weight(1);
        thing->set_ac(3);
        thing->set_long("Armor used for testing.\n");
        thing->set_value(0);
        thing->set_type("armor");
      move_object(thing, this_player());
      thing = clone_object("/players/forbin/realms/misc/OBJ/testing_armor.c");
        thing->set_name("cap");
        thing->set_short(HIC+"a leather cap ["+NORM+"testing armor"+HIC+"]"+NORM);
        thing->set_alias("leather cap");
        thing->set_weight(1);
        thing->set_ac(1);
        thing->set_long("Armor used for testing.\n");
        thing->set_value(0);
        thing->set_type("helmet");
      move_object(thing, this_player());      
      thing = clone_object("/players/forbin/realms/misc/OBJ/testing_armor.c");
        thing->set_name("buckler");
        thing->set_short(HIC+"a steel buckler ["+NORM+"testing armor"+HIC+"]"+NORM);
        thing->set_alias("steel buckler");
        thing->set_weight(1);
        thing->set_ac(1);
        thing->set_long("Armor used for testing.\n");
        thing->set_value(0);
        thing->set_type("shield");
      move_object(thing, this_player());  
      thing = clone_object("/players/forbin/realms/misc/OBJ/testing_armor.c");
        thing->set_name("boots");
        thing->set_short(HIC+"a pair of leather boots ["+NORM+"testing armor"+HIC+"]"+NORM);
        thing->set_alias("leather boots");
        thing->set_weight(1);
        thing->set_ac(1);
        thing->set_long("Armor used for testing.\n");
        thing->set_value(0);
        thing->set_type("boots");
      move_object(thing, this_player());
      thing = clone_object("/players/forbin/realms/misc/OBJ/testing_armor.c");
        thing->set_name("necklace");
        thing->set_short(HIC+"a woven necklace ["+NORM+"testing armor"+HIC+"]"+NORM);
        thing->set_alias("woven necklace");
        thing->set_weight(1);
        thing->set_ac(1);
        thing->set_long("Armor used for testing.\n");
        thing->set_value(0);
        thing->set_type("amulet");
      move_object(thing, this_player()); 
      thing = clone_object("/players/forbin/realms/misc/OBJ/testing_armor.c");
        thing->set_name("gloves");
        thing->set_short(HIC+"a pair of leather gloves ["+NORM+"testing armor"+HIC+"]"+NORM);
        thing->set_alias("leather gloves");
        thing->set_weight(1);
        thing->set_ac(1);
        thing->set_long("Armor used for testing.\n");
        thing->set_value(0);
        thing->set_type("ring");
      move_object(thing, this_player()); 
      thing = clone_object("/players/forbin/realms/misc/OBJ/testing_armor.c");
        thing->set_name("cloak");
        thing->set_short(HIC+"a blue cloak ["+NORM+"testing armor"+HIC+"]"+NORM);
        thing->set_alias("blue cloak");
        thing->set_weight(1);
        thing->set_ac(1);
        thing->set_long("Armor used for testing.\n");
        thing->set_value(0);
        thing->set_type("misc");
      move_object(thing, this_player());
      command("ready", this_player());                                 
      break;
    case 2:
      thing = clone_object("/players/forbin/realms/misc/OBJ/testing_armor.c");
        thing->set_name("chainmail");
        thing->set_short(HIC+"chainmail armor ["+NORM+"testing armor"+HIC+"]"+NORM);
        thing->set_alias("armor");
        thing->set_weight(1);
        thing->set_ac(4);
        thing->set_long("Armor used for testing.\n");
        thing->set_value(0);
        thing->set_type("armor");
      move_object(thing, this_player());
      thing = clone_object("/players/forbin/realms/misc/OBJ/testing_armor.c");
        thing->set_name("helm");
        thing->set_short(HIC+"a warhelm ["+NORM+"testing armor"+HIC+"]"+NORM);
        thing->set_alias("war helm");
        thing->set_weight(1);
        thing->set_ac(2);
        thing->set_long("Armor used for testing.\n");
        thing->set_value(0);
        thing->set_type("helmet");
      move_object(thing, this_player());      
      thing = clone_object("/players/forbin/realms/misc/OBJ/testing_armor.c");
        thing->set_name("tower shield");
        thing->set_short(HIC+"a large tower shield ["+NORM+"testing armor"+HIC+"]"+NORM);
        thing->set_alias("shield");
        thing->set_weight(1);
        thing->set_ac(2);
        thing->set_long("Armor used for testing.\n");
        thing->set_value(0);
        thing->set_type("shield");
      move_object(thing, this_player()); 
      thing = clone_object("/players/forbin/realms/misc/OBJ/testing_armor.c");
        thing->set_name("boots");
        thing->set_short(HIC+"a pair of leather boots ["+NORM+"testing armor"+HIC+"]"+NORM);
        thing->set_alias("leather boots");
        thing->set_weight(1);
        thing->set_ac(1);
        thing->set_long("Armor used for testing.\n");
        thing->set_value(0);
        thing->set_type("boots");
      move_object(thing, this_player());
      thing = clone_object("/players/forbin/realms/misc/OBJ/testing_armor.c");
        thing->set_name("guard");
        thing->set_short(HIC+"a neckguard ["+NORM+"testing armor"+HIC+"]"+NORM);
        thing->set_alias("neckguard");
        thing->set_weight(1);
        thing->set_ac(2);
        thing->set_long("Armor used for testing.\n");
        thing->set_value(0);
        thing->set_type("amulet");
      move_object(thing, this_player()); 
      thing = clone_object("/players/forbin/realms/misc/OBJ/testing_armor.c");
        thing->set_name("gloves");
        thing->set_short(HIC+"a pair of leather gloves ["+NORM+"testing armor"+HIC+"]"+NORM);
        thing->set_alias("leather gloves");
        thing->set_weight(1);
        thing->set_ac(1);
        thing->set_long("Armor used for testing.\n");
        thing->set_value(0);
        thing->set_type("ring");
      move_object(thing, this_player()); 
      thing = clone_object("/players/forbin/realms/misc/OBJ/testing_armor.c");
        thing->set_name("cloak");
        thing->set_short(HIC+"a blue cloak ["+NORM+"testing armor"+HIC+"]"+NORM);
        thing->set_alias("blue cloak");
        thing->set_weight(1);
        thing->set_ac(1);
        thing->set_long("Armor used for testing.\n");
        thing->set_value(0);
        thing->set_type("misc");
      move_object(thing, this_player()); 
      command("ready", this_player());                                                                 
      break;
    case 3:      
      thing = clone_object("/players/forbin/realms/misc/OBJ/testing_armor.c");
        thing->set_name("platemail");
        thing->set_short(HIC+"a suit of platemail ["+NORM+"testing armor"+HIC+"]"+NORM);
        thing->set_alias("armor");
        thing->set_weight(1);
        thing->set_ac(5);
        thing->set_long("Armor used for testing.\n");
        thing->set_value(0);
        thing->set_type("armor");
      move_object(thing, this_player());
      thing = clone_object("/players/forbin/realms/misc/OBJ/testing_armor.c");
        thing->set_name("helm");
        thing->set_short(HIC+"a warhelm ["+NORM+"testing armor"+HIC+"]"+NORM);
        thing->set_alias("war helm");
        thing->set_weight(1);
        thing->set_ac(2);
        thing->set_long("Armor used for testing.\n");
        thing->set_value(0);
        thing->set_type("helmet");
      move_object(thing, this_player());      
      thing = clone_object("/players/forbin/realms/misc/OBJ/testing_armor.c");
        thing->set_name("tower shield");
        thing->set_short(HIC+"a large tower shield ["+NORM+"testing armor"+HIC+"]"+NORM);
        thing->set_alias("shield");
        thing->set_weight(1);
        thing->set_ac(2);
        thing->set_long("Armor used for testing.\n");
        thing->set_value(0);
        thing->set_type("shield");
      move_object(thing, this_player());  
      thing = clone_object("/players/forbin/realms/misc/OBJ/testing_armor.c");
        thing->set_name("boots");
        thing->set_short(HIC+"a pair of combat boots ["+NORM+"testing armor"+HIC+"]"+NORM);
        thing->set_alias("combat boots");
        thing->set_weight(1);
        thing->set_ac(2);
        thing->set_long("Armor used for testing.\n");
        thing->set_value(0);
        thing->set_type("boots");
      move_object(thing, this_player());
      thing = clone_object("/players/forbin/realms/misc/OBJ/testing_armor.c");
        thing->set_name("guard");
        thing->set_short(HIC+"a neckguard ["+NORM+"testing armor"+HIC+"]"+NORM);
        thing->set_alias("neckguard");
        thing->set_weight(1);
        thing->set_ac(2);
        thing->set_long("Armor used for testing.\n");
        thing->set_value(0);
        thing->set_type("amulet");
      move_object(thing, this_player()); 
      thing = clone_object("/players/forbin/realms/misc/OBJ/testing_armor.c");
        thing->set_name("gloves");
        thing->set_short(HIC+"a pair of guantlets ["+NORM+"testing armor"+HIC+"]"+NORM);
        thing->set_alias("gauntlets");
        thing->set_weight(1);
        thing->set_ac(2);
        thing->set_long("Armor used for testing.\n");
        thing->set_value(0);
        thing->set_type("ring");
      move_object(thing, this_player()); 
      thing = clone_object("/players/forbin/realms/misc/OBJ/testing_armor.c");
        thing->set_name("cloak");
        thing->set_short(HIC+"a chainmail cloak ["+NORM+"testing armor"+HIC+"]"+NORM);
        thing->set_alias("chainmail cloak");
        thing->set_weight(1);
        thing->set_ac(2);
        thing->set_long("Armor used for testing.\n");
        thing->set_value(0);
        thing->set_type("misc");
      move_object(thing, this_player());  
      command("ready", this_player());                                                                
      break;          
    case 4:    
      move_object(clone_object("/players/zeus/realm/obj/fallen_blade.c"), this_player());    
      command("wield fallen blade", this_player());
    case 5:    
      move_object(clone_object("/players/snow/WEAPONS/temblor.c"), this_player());    
      command("wield temblor", this_player());
    case 6:    
      move_object(clone_object("/players/snow/closed/test/elemental_mace.c"), this_player());    
      command("wield elemental mace", this_player());      
    case 7:
      move_object(clone_object("/players/forbin/heals/jaune.c"), this_player());
      move_object(clone_object("/players/forbin/heals/jaune.c"), this_player());
      move_object(clone_object("/players/forbin/heals/jaune.c"), this_player());
      move_object(clone_object("/players/forbin/heals/jaune.c"), this_player());
      move_object(clone_object("/players/forbin/heals/jaune.c"), this_player());
      move_object(clone_object("/players/forbin/heals/jaune.c"), this_player());
      break;
    case 8:
      move_object(clone_object("/players/forbin/heals/dhuez.c"), this_player());
      move_object(clone_object("/players/forbin/heals/dhuez.c"), this_player());
      move_object(clone_object("/players/forbin/heals/dhuez.c"), this_player());
      move_object(clone_object("/players/forbin/heals/dhuez.c"), this_player());
      move_object(clone_object("/players/forbin/heals/dhuez.c"), this_player());
      move_object(clone_object("/players/forbin/heals/dhuez.c"), this_player());
      break;   
    case 9:
      move_object(clone_object("/players/forbin/heals/galibier.c"), this_player());
      move_object(clone_object("/players/forbin/heals/galibier.c"), this_player());
      move_object(clone_object("/players/forbin/heals/galibier.c"), this_player());
      move_object(clone_object("/players/forbin/heals/galibier.c"), this_player());
      move_object(clone_object("/players/forbin/heals/galibier.c"), this_player());
      move_object(clone_object("/players/forbin/heals/galibier.c"), this_player());
    case 10:
      move_object(clone_object("/players/forbin/heals/mayias.c"), this_player());
      move_object(clone_object("/players/forbin/heals/mayias.c"), this_player());
      move_object(clone_object("/players/forbin/heals/mayias.c"), this_player());
      move_object(clone_object("/players/forbin/heals/mayias.c"), this_player());
      move_object(clone_object("/players/forbin/heals/mayias.c"), this_player());
      move_object(clone_object("/players/forbin/heals/mayias.c"), this_player());
    case 11:
      move_object(clone_object("/players/forbin/heals/mongie.c"), this_player());
      move_object(clone_object("/players/forbin/heals/mongie.c"), this_player());
      move_object(clone_object("/players/forbin/heals/mongie.c"), this_player());
      move_object(clone_object("/players/forbin/heals/mongie.c"), this_player());
    case 12:
      move_object(clone_object("/players/forbin/heals/museeuw.c"), this_player());
      move_object(clone_object("/players/forbin/heals/museeuw.c"), this_player());
      move_object(clone_object("/players/forbin/heals/museeuw.c"), this_player());
      move_object(clone_object("/players/forbin/heals/museeuw.c"), this_player());
    case 13:
      this_player()->add_money(80000);
      break;
    }
  write("You withdraw #"+num+" from the armory.\n");
  say(TPN+" withdraws something from the armory.\n");
  return 1;      
}