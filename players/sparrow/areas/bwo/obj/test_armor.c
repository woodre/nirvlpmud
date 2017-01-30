#include "/sys/ansi.h"
inherit "/obj/armor.c";
inherit "/players/sparrow/areas/bwo/include/gear_funcs.c";

reset(arg){
  ::reset(arg);
  set_name("armor");
  set_ac(0);
  set_weight(random(2)+1);
}

generic_object() { return 1; }
query_save_flag() { return 0; }

string
short_by_stat(string dtype, int iden, int lore) {
  switch(dtype)
  {
    case "other|dark":
      if(iden > 28) {
        return HIW+"s"+HIK+"hadows"+NORM;
      }
      if(lore > 15) {
        return HIK+"onyx"+NORM;
      }
      return HIK+"gemstone"+NORM;
      break;
    case "other|light":
      if(iden > 28) {
        return HIY+"b"+NORM+"rilliance";
      }
      if(lore > 15) {
        return HIY+"s"+NORM+"un"+HIW+"s"+NORM+"tone";
      }
      return YEL+"gemstone"+NORM;
      break;
    case "other|water":
      if(iden > 28) {
        return HIB+"m"+HIC+"ist"+NORM;
      }
      if(lore > 15) {
        return HIB+"sapphire"+NORM;
      }
      return HIB+"gemstone"+NORM;
      break;
    case "other|fire":
      if(iden > 28) {
        return RED+"f"+HIR+"lame"+NORM;
      }
      if(lore > 15) {
        return HIR+"ruby"+NORM;
      }
      return HIR+"gemstone"+NORM;
      break;
    case "other|wind":
      if(iden > 28) {
        return HIW+"w"+NORM+"ind";
      }
      if(lore > 15) {
        return HIW+"pearl"+NORM;
      }
      return HIW+"gemstone"+NORM;
      break;
    case "other|earth":
      if(iden > 28) {
        return HIK+"s"+NORM+YEL+"tone"+NORM;
      }
      if(lore > 15) {
        return HIY+"s"+NORM+YEL+"andstone"+NORM;
      }
      return YEL+"gemstone"+NORM;
      break;
    case "other|ice":
      if(iden > 28) {
        return HIC+"f"+NORM+"rost";
      }
      if(lore > 15) {
        return HIC+"aquamarine"+NORM;
      }
      return HIC+"gemstone"+NORM;
      break;
    case "other|electric":
      if(iden > 28) {
        return HIY+"sparks"+NORM;
      }
      if(lore > 15) {
        return HIY+"topaz"+NORM;
      }
      return HIY+"gemstone"+NORM;
      break;
    case "other|laser":
      if(iden > 28) {
        return HIM+"e"+HIC+"ne"+HIM+"rg"+HIC+"y"+NORM;
      }
      if(lore > 15) {
        return MAG+"amethyst"+NORM;
      }
      return MAG+"gemstone"+NORM;
      break;
    case "other|evil":
      if(iden > 28) {
        return HIR+"d"+HIK+"estruction"+NORM;
      }
      if(lore > 15) {
        return HIK+"b"+NORM+RED+"lood"+HIK+"s"+NORM+RED+"tone"+NORM;
      }
      return HIR+"ge"+HIK+"m"+HIR+"sto"+HIK+"n"+HIR+"e"+NORM;
      break;
    case "other|good":
      if(iden > 28) {
        return HIY+"p"+NORM+"urity";
      }
      if(lore > 15) {
        return HIY+"o"+NORM+"pal";
      }
      return "gemstone";
      break;
    case "other|poison":
      if(iden > 28) {
        return HIG+"v"+NORM+GRN+"enom"+NORM;
      }
      if(lore > 15) {
        return HIG+"emerald"+NORM;
      }
      return HIG+"gemstone"+NORM;
      break;
    case "other|sonic":
      if(iden > 28) {
        return MAG+"w"+CYAN+"ailing"+NORM;
      }
      if(lore > 15) {
        return HIB+"lapis"+NORM;
      }
      return HIB+"gemstone"+NORM;
      break;
    case "other|mental":
      if(iden > 28) {
        return CYAN+"i"+HIW+"ll"+HIY+"us"+HIM+"ion"+NORM;
      }
      if(lore > 15) {
        return CYAN+"tourmaline"+NORM;      
      }
      return CYAN+"gemstone"+NORM;
      break;
    case "magical":
      if(iden > 28) {
        return "magic";
      }
      if(lore > 15) {
        return "Diamond";
      }
      return "gemstone";
      break;
    default:
      return "ERROR";
  } 
}
  
mixed
query_dtype_info() {
  mixed *dtype_info;
  mixed *params;
  int i, last;
  i = 0;
  if(this_object()->query_params()){
    params = (mixed) this_object()->query_params();
    last = sizeof(params)-1;
    /* Remove physical info */
    if(last > 3){
      last = last - 4;
      dtype_info = params[0..last];
      return dtype_info;
    }
  }  
  dtype_info = allocate(1);
  dtype_info[0] = "none";
  return dtype_info;
}

string
generate_short(){
  int lucky, i, count, power;
  mixed *params;
  if(this_player()) { 
    int lore, iden;
    string short_string, arm_type;
    power = 0;
    i=0;
    arm_type = (string) this_object()->query_type();
    short_string = capitalize(arm_type);
    lore = query_hidden_stats(this_player(), "lore");
    iden = query_hidden_stats(this_player(), "iden");
    params = (mixed) query_dtype_info();
    if(lore > 14) {
        short_string += " of the "+HIK+"Black Willow"+NORM;
    }
    count = sizeof(params);
    if(count > 1) {
      while(i < count) {
        if(count < 10) {
          short_string += " ["+short_by_stat(params[i], iden, lore)+"]";
        }
        power += params[i+2];
        i=i+4;
      }
      if(count > 9) {
        short_string += " ["+HIB+"e"+HIR+"l"+HIY+"e"+HIC+"m"+HIK+"e"+HIC+
          "n"+HIY+"t"+HIR+"a"+HIB+"l"+NORM+"]";
      }
      if(iden > 25) {
        if(power < 8) {
          short_string = "Lesser "+short_string+NORM;
        }
        if((power > 7) && (power < 14)) {
          short_string = YEL+"Moderate "+NORM+short_string+NORM;
        }
        if((power > 13) && (power < 18)) {
          short_string = HIY+"Greater "+NORM+short_string+NORM;
        }
        if(power > 17) {
          short_string = HIR+"Legendary "+NORM+short_string+NORM;
        }
      }
      return short_string;
    }
    return short_string;
  }
  return "Error Loading Short, Please report to Sparrow";
}

string
generate_description() {
  object viewer;
  string acc_type, description;
  int lore, iden, appraise, sim_lore, sim_iden, sim_appraise, value;
  mixed *params;
  description = "\n";
  viewer = this_player();
  lore = query_hidden_stats(viewer, "lore");
  iden = query_hidden_stats(viewer, "iden");
  appraise = query_hidden_stats(viewer, "appraise");
  acc_type = (string) this_object()->query_type();
  if(acc_type == "chest") {
    acc_type == "chestguard";
  }
  /* Begin construction of lore section of long description */
  /* Fear spending this much time and energy on making something */
  /* fun and unique for the players. Hint Hint */
  description += HIK+"["+HIC+"lore"+HIK+"]"+HIC+
  "  :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::  "+
  HIK+"["+HIC+"lore"+HIK+"]\n"+NORM;
  switch(acc_type) {
  
    
    case "amulet":
      /* Begin case: amulet */
      description += HIK+
      "  Hanging from the end of a dyed black leather cord, this amazing amulet\n"+
      "seems to be composed of";
      if(lore > 20) {
        description += 
        " mithril.  Mithril is a rare silvery metal prized\n"+
        "for its extremely light weight and unmatched strength.  Almost all of the\n"+
        "mithril in the realms is mined by the dwarven people.\n";
      }
      
      else {
        description +=
        " an unknown silver metal.  The amulet looks much\n"+
        "heavier than it actually is, leading you to believe that it may be one of\n"+
        "the fantastic metals only heard of in myths and legends.\n";
      }
      
      description +=
      "  In the center of the amulet is a carving of a";
      if(lore > 15) { 
        description += " lone black willow tree.\n"; 
      }
      
      else { 
        description += " lone tree of good health.\n";
      }
      
      description +=
      "In the background is a night scene, the moon rising up behind the tree\n"+
      "framing it perfectly.  You sense a calming aura coming from the amulet.\n";
      if(lore > 20) {
        description +=
        "You instantly recognize this symbol to be the mark of the Black Willow\n"+
        "Order, a religious organization dedicated to worshipping the powers of\n"+
        "the night and darkness.  Led by the Black Willow himself, this order\n"+
        "combines deadly hand-to-hand tecniques with powerfull spell abilities.\n";
      }
      
      params = (mixed) query_dtype_info();
      /* Begin addition of gemstones to lore section */
      /* If elemental */
      if(sizeof(params) > 9) {
        if(lore > 15) {
          description +=
          "The outside of the amulet is encrusted with six gemstones: sandstone, ruby,\n"+
          "sapphire, topaz, pearl and aquamarine.\n";
        }
        
        else {
          description +=
          "The outside of the amulet is encrusted with six gemstones.";
        }
        
      }
      
      if(lore > 15) { 
        sim_lore = 20;
        sim_iden = 20;
      }
      
      else {
        sim_lore = 13;
        sim_iden = 13;
      }
      
      /* If dual gemstone */
      if(sizeof(params) == 8) {
        description +=
        "You notice that the moon is inlaid with "+short_by_stat(params[0], sim_lore, sim_iden)+
        "s"+HIK+" and that the\nstars are actually comprised of "+
        short_by_stat(params[4], sim_lore, sim_iden)+HIK+" flakes.\n";
      }
      
      /* If single gemstone */
      if(sizeof(params) == 4) {
        description +=
        "You notice that the moon is inlaid with "+
        short_by_stat(params[0], sim_lore, sim_iden)+HIK+".\n";
      }
      
      break;
      /* End case Amulet */
    
    case "necklace":
      /* Begin case: necklace */
      description += HIK+
      "  This necklace is constructed of three rows of interlocking chain stacked\n"+
      "one on top of each other.  Studded into each gap is a three inch long spike\n"+
      "that has been pulled and twisted into a dangerous point.  The choker itself\n"+
      "seems to be composed of";
      if(lore > 20) { description += 
        " mithril.  Mithril is a rare silvery metal prized\n"+
        "for its extremely light weight and unmatched strength.  Almost all of\n"+
        "the mithril in the realms is mined by the dwarven people.\n";
      }
      
      else { description +=
        " an unknown silver metal.  The choker looks much\n"+
        "heavier than it actually is, leading you to believe that it may be one\n"+
        "of the fantastic metals only heard of in myths and legends.\n";
      }
      
      /* Add description and location of Black Willow Symbol */
      description +=
      "  Hanging in the front of the necklace is a metal tag of sorts. Embossed\n"+
      "into the tag is detailed symbol depicting a";
      if(lore > 15) { 
        description += " lone black willow tree.\n"; 
      }
      
      else { 
        description += " lone tree of good health.\n";
      }
      
      description +=
      "In the background is a night scene, the moon rising up behind the tree\n"+
      "framing it perfectly.  You sense a calming aura coming from the tag.\n";
      if(lore > 20) {
        description +=
        "You instantly recognize this symbol to be the mark of the Black Willow\n"+
        "Order, a religious organization dedicated to worshipping the powers of\n"+
        "the night and darkness.  Led by the Black Willow himself, this order\n"+
        "combines deadly hand-to-hand tecniques with powerfull spell abilities.\n";
      }
      
      params = (mixed) query_dtype_info();
      /* Begin addition of gemstones to lore section */
      /* If elemental */
      if(sizeof(params) > 9) {
        if(lore > 15) {
          description +=
          "Each spike is tipped with one of six gemstones: sandstone, ruby, sapphire,\n"+
          "topaz, pearl and aquamarine.\n";
        }
        
        else {
          description +=
          "Each spike is tipped with one of six gemstones.\n";
        }
        
      }
      
      if(lore > 15) { 
        sim_lore = 20;
        sim_iden = 20;
      }
      
      else {
        sim_lore = 13;
        sim_iden = 13;
      }
      
      /* If dual gemstone */
      if(sizeof(params) == 8) {
        description +=
        "You notice that the moon is inlaid with "+
        short_by_stat(params[0], sim_lore, sim_iden)+HIK+
        " and that the stars\n are actually comprised of "+
        short_by_stat(params[4], sim_lore, sim_iden)+HIK+" flakes.\n";
      }
      
      /* If single gemstone */
      if(sizeof(params) == 4) {
        description +=
        "You notice that the moon is inlaid with several "+
        short_by_stat(params[0], sim_lore, sim_iden)+HIK+".\n";
      }
      
      break;
      /* End case Necklace */
      
    case "bracelet":
      /* Begin case: Bracelet */
      description += HIK+
      "  This bracelet is constructed of a series of metal beads strung across\n"+
      "a thick leather cord.  The beads are separated by multi-colored shards\n"+
      "of cut glass that seem to glow with an inner light.\n";
      params = (mixed) query_dtype_info();
      /* Begin addition of gemstones to lore section */
      /* If elemental */
      if(sizeof(params) > 9) {
        if(lore > 15) {
          description +=
          "Six of pieces of cut glass appear to actually be gemstones: sandstone, ruby,\n"+
          "sapphire, topaz, pearl and aquamarine.\n";
        }
        
      }
      
      if(lore > 15) { 
        sim_lore = 20;
        sim_iden = 20;
      }
      
      else {
        sim_lore = 13;
        sim_iden = 13;
      }
      
      /* If dual gemstone */
      if(sizeof(params) == 8) {
        description +=
        "You notice that two of the pieces of glass seem to actually be gemstones.\n"+
        "You recognize that the stones are: "+short_by_stat(params[0], sim_lore, sim_iden)+
        HIK+" and "+short_by_stat(params[4], sim_lore, sim_iden)+HIK+".\n";
      }
      
      /* If single gemstone */
      if(sizeof(params) == 4) {
        description +=
        "You notice that one of the pieces of glass is actually "+
        short_by_stat(params[0], sim_lore, sim_iden)+".\n";
      }
      
      break;
      /* End case Bracelet */
      
    case "ring":
      /* Begin case: Ring */
      description += HIK+
      "  This silvery ring is made from three seperate strands of metal braided\n"+
      "into a single circular band.  The center of the ring has been milled down\n"+
      "to allow intricate runes to be carved into it.  The ring seems to have\n"+
      "been contructed from";
      if(lore > 20) {
        description += 
        " mithril.  Mithril is a rare silvery metal prized\n"+
        "for its extremely light weight and unmatched strength.  Almost all of the\n"+
        "mithril in the realms is mined by the dwarven people.\n";
      }
      
      else {
        description +=
        " an unknown silver metal.  The ring looks much\n"+
        "heavier than it actually is, leading you to believe that it may be one of\n"+
        "the fantastic metals only heard of in myths and legends.\n";
      }
      
      /* Add description and location of Black Willow Symbol */
      description +=
      "  Inspecting the ring further, you notice that the runes seem to have a\n"+
      "reoccouring theme throughout: a";
      if(lore > 15) { 
        description += " lone black willow tree.\n"; 
      }
      
      else { 
        description += " lone tree of good health.\n";
      }
      
      if(lore > 20) {
        description +=
        "You instantly recognize this symbol to be the mark of the Black Willow\n"+
        "Order, a religious organization dedicated to worshipping the powers of\n"+
        "the night and darkness.  Led by the Black Willow himself, this order\n"+
        "combines deadly hand-to-hand tecniques with powerfull spell abilities.\n";
      }
      
      params = (mixed) query_dtype_info();
      /* Begin addition of gemstones to lore section */
      /* If elemental */
      if(sizeof(params) > 9) {
        if(lore > 15) {
          description +=
          "Set into the ring are six gemstones: sandstone, ruby, sapphire, topaz, pearl\n"+
          "and aquamarine.\n";
        }
        
        else {
          description +=
          "Set into the ring are six colorful gemstones.\n";
        }
        
      }
      
      if(lore > 15) { 
        sim_lore = 20;
        sim_iden = 20;
      }
      
      else {
        sim_lore = 13;
        sim_iden = 13;
      }
      
      /* If dual gemstone */
      if(sizeof(params) == 8) {
        description +=
        "You notice that the ring is inlaid with "+
        short_by_stat(params[0], sim_lore, sim_iden)+HIK+" and "+
        short_by_stat(params[4], sim_lore, sim_iden)+".\n";
      }
      
      /* If single gemstone */
      if(sizeof(params) == 4) {
        description +=
        "You notice that the ring is inlaid with "+
        short_by_stat(params[0], sim_lore, sim_iden)+HIK+".\n";
      }
      
      break;
      /* End case Ring */  
      
    case "earring":
      /* Begin case: earring */
      description += HIK+
      "  This earring actually rests on top of the ear rather than going through\n"+  
      "the lobe.  The earring has been shaped into the form of a poisonouse snake.\n"+
      "The Serpent of Night twists through and around the beguiled wearerÕs ear.\n"+
      "The earring seems to be made from";
      if(lore > 20) {
        description += 
        " mithril.  Mithril is a rare silvery metal\n"+
        "prized for its extremely light weight and unmatched strength.  Almost all\n"+
        "of the mithril in the realms is mined by the dwarven people.\n";
      }
      
      else {
        description +=
        " an unknown silver metal.  The earring looks\n"+
        "much heavier than it actually is, leading you to believe that it may be\n"+
        "one of the fantastic metals only heard of in myths and legends.\n";
      }
      
      /* Add description and location of Black Willow Symbol */
      description +=
      "Embossed into the head of the the serpent is a";
      if(lore > 15) { 
        description += " lone black willow tree.\n"; 
      }
      
      else { 
        description += " lone tree of good health.\n";
      }
      
      if(lore > 20) {
        description +=
        "You instantly recognize this symbol to be the mark of the Black Willow\n"+
        "Order, a religious organization dedicated to worshipping the powers of\n"+
        "the night and darkness.  Led by the Black Willow himself, this order\n"+
        "combines deadly hand-to-hand tecniques with powerfull spell abilities.\n";
      }
      
      params = (mixed) query_dtype_info();
      /* Begin addition of gemstones to lore section */
      /* If elemental */
      if(sizeof(params) > 9) {
        if(lore > 15) {
          description +=
          "Set down the back of the serpent are six gemstones: sandstone, ruby,\n"+
          "sapphire, topaz, pearl and aquamarine.\n";
        }
        
        else {
          description +=
          "A row of gemstones line the back of the serpent.\n";
        }
        
      }
      
      if(lore > 15) { 
        sim_lore = 20;
        sim_iden = 20;
      }
      
      else {
        sim_lore = 13;
        sim_iden = 13;
      }
      
      /* If dual gemstone */
      if(sizeof(params) == 8) {
        description +=
        "The left eye of the serpent is "+
        short_by_stat(params[0], sim_lore, sim_iden)+HIK+
        " while the right is "+short_by_stat(params[4], sim_lore, sim_iden)+HIK+".\n";
      }
      
      /* If single gemstone */
      if(sizeof(params) == 4) {
        description +=
        "The right eye of the serpent seems to be made of"+
        short_by_stat(params[0], sim_lore, sim_iden)+HIK+".\n";
      }
      
      break;
      /* End case Earring */
  }
  description += HIK+"["+HIC+"lore"+HIK+"]"+HIC+
  "  :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::  "+
  HIK+"["+HIC+"lore"+HIK+"]\n\n"+NORM;
  
  /* Future location of Indentify section */
   
  /* Allow them to guess the value of the object based on appraise stat */
  value = (int) this_object()->query_value();
  if((appraise > 28) && (appraise < 32)) {
    switch(random(2)){
      case 0:
        value = value - ((value*random(21))/100);
        break;
      case 1:  
        value = value + ((value*random(21))/100);
        break;
    }
  }
  if((appraise > 20) && (appraise < 29)) {
    switch(random(2)){
      case 0:
        value = value - ((value*random(41))/100);
        break;
      case 1:  
        value = value + ((value*random(41))/100);
        break;
    }
  }
  if(appraise < 21) {
    switch(random(2)){
      case 0:
        value = value - ((value*random(61))/100);
        break;
      case 1:  
        value = value + ((value*random(61))/100);
        break;
    }
  }
  description += "You estimate that the value is around ["+value+"] coins.\n";      
  return description+NORM;
}

string
short() {
  return generate_short();
}

void
long() {
  string long_string;
  /* first add the name of the accessory using the generate_short() function */
  write(generate_short());
  /* now add the basic description of the item using generate_description()  */
  write(generate_description()+"\n");
}

