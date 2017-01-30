inherit "/obj/weapon.c";
/* The code of this thing turned into a tangled mess.  See stick.2011.6.18.c */
#include "/players/jenny/define.h"
#define ME TP->query_possessive()
#define MEE TP->query_objective()

reset(arg){
  if(arg) return;
    ::reset(arg);
    
  set_alt_name("staff");
  set_alias("healing staff");
  set_name(YEL+"Revive, "+HIB+"Healing Staff of Virtue"+NORM);
  set_long(
    "Revive is a simple wooded staff engraved with simple ornate runes of healing.\n"+
    "It has helped many a clever healer recover in combat and it has mad the foolish\n"+
    "suffer for not understanding the simple power that lies within.\n");
  set_read("staff\n");
  set_class(1);
  set_type("staff");
  set_weight(3);
  set_value(10000);
  set_hit_func(this_object());
}

init() {
   ::init();
}
weapon_hit(attacker) { 

  int a;
  int b;
 
  a = 0;
  b = 0;
 

  if(a==0){  
    int miscslot;
    object MISC;
    if(!TP) return 0;
    MISC = present("misc",TP);
    if(!attacker || !MISC) return;
    MISC->do_special(wielded_by);
		write(HIW+BLINK+"MISC SPECIAL FIRE\n"+NORM);
  }
  
 /* if(a==0){  
    int armorslot;
    object ARMOR;
    if(!TP) return 0;
    ARMOR = present("armor",TP);
    if(!attacker || !ARMOR) return;
    ARMOR->do_special(wielded_by);
  }*/
  
  if(b==0){  
    int helmetslot;
    object HELMET;
    if(!TP) return 0;
    HELMET = present("helmet",TP);
    if(!attacker || !HELMET) return;
    HELMET->do_special(wielded_by);
	write(HIW+BLINK+"HELMET SPECIAL FIRE\n"+NORM);
  }
  
 /*   if(c==0){  
    int shieldslot;
    object SHIELD;
    if(!TP) return 0;
    SHIELD = present("shield",TP);
    if(!attacker || !SHIELD) return;
    SHIELD->do_special(wielded_by);
  }
  
    if(d==0){  
    int bootsslot;
    object BOOTS;
    if(!TP) return 0;
    BOOTS = present("boots",TP);
    if(!attacker || !BOOTS) return;
    BOOTS->do_special(wielded_by);
  }*/
  
    if(a==0){  
    int amuletslot;
    object AMULET;
    if(!TP) return 0;
    AMULET = present("amulet",TP);
    if(!attacker || !AMULET) return;
    AMULET->do_special(wielded_by);
	write(HIW+BLINK+"AMULET SPECIAL FIRE\n"+NORM);
  }
  /*
    if(f==0){  
    int chestslot;
    object CHEST;
    if(!TP) return 0;
    CHEST = present("chest",TP);
    if(!attacker || !CHEST) return;
    CHEST->do_special(wielded_by);
  }
  
  if(g==0){  
    int necklaceslot;
    object NECKLACE;
    if(!TP) return 0;
    NECKLACE = present("necklace",TP);
    if(!attacker || !NECKLACE) return;
    NECKLACE->do_special(wielded_by);
  }
  
  if(h==0){  
    int cloakslot;
    object CLOAK;
    if(!TP) return 0;
    CLOAK = present("cloak",TP);
    if(!attacker || !CLOAK) return;
    CLOAK->do_special(wielded_by);
  }
  
  if(i==0){  
    int pantsslot;
    object PANTS;
    if(!TP) return 0;
    PANTS = present("pants",TP);
    if(!attacker || !PANTS) return;
    PANTS->do_special(wielded_by);
  }
  
/*  if(a==0){  
    int beltslot;
    object BELT;
    if(!TP) return 0;
    CHEST = present("BELT",TP);
    if(!attacker || !BELT) return;
    BELT->do_special(wielded_by);
  }
  
  if(b==0){  
    int glovesslot;
    object GLOVES;
    if(!TP) return 0;
    GLOVES = present("gloves",TP);
    if(!attacker || !GLOVES) return;
    GLOVES->do_special(wielded_by);
  }*/
  
  if(a==0){  
    int earringslot;
    object EARRING;
    if(!TP) return 0;
    EARRING = present("earring",TP);
    if(!attacker || !EARRING) return;
    EARRING->do_special(wielded_by);
	write(HIW+BLINK+"EARRING SPECIAL FIRE\n"+NORM);
  } 
  
  if(a==0){  
    int braceletslot;
    object BRACELET;
    if(!TP) return 0;
    BRACELET = present("bracelet",TP);
    if(!attacker || !BRACELET) return;
    BRACELET->do_special(wielded_by);
	write(HIW+BLINK+"Bracelet SPECIAL FIRE\n"+NORM);
  }
  /*
  if(c==0){  
    int ringslot;
    object RING;
    if(!TP) return 0;
    RING = present("ring",TP);
    if(!attacker || !RING) return;
    RING->do_special(wielded_by);
  }
  
  if(d==0){  
    int underwareslot;
    object UNDERWARE;
    if(!TP) return 0;
    UNDERWARE = present("underware",TP);
    if(!attacker || !UNDERWARE) return;
    UNDERWARE->do_special(wielded_by);
  }*/
  
    
  
}
