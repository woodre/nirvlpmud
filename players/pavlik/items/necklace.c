/*
 * An ojbect that allows Players to store HPs
 * this item has been approved.
  * BY WHO? let me know so I can demote their ass too. storing hp is not legal.
-Bp
 * It is gotten from Hzsade (/pavlik/dark/dragon.c)
*/
inherit "obj/armor";
int stored;
reset(arg){
 ::reset(arg);
 if(arg) return;
 set_short("HzSade's Crystal Amulet");
 set_long(
 "A chain of the finest spun gold and a large mysterious blue crystal.  The\n"+
 "large stone is about the size of your fist and appears to pulsate with\n"+
 "a life of its very own.  There is something written on the crystal.\n");
 set_ac(1);
 set_weight(1);
 set_value(200000);
 set_alias("necklace");
 set_name("HzSade's Amulet");
 set_type("amulet");
 set_save_flag(1);
 stored = 100;
}

init(){
 ::init();
 add_action("info","read");
 add_action("amulet","amulet");
}

amulet(str){
  string what;
  int much;
  if(!worn) return 0;
  if(!str){
    write("HzSade's Amulet has "+stored+" hit points stored in the magic crystal.\n");
    return 1;
  }
  if(!sscanf(str, "%s %d", what, much)==2) return 0;
  if(what == "store"){
    if(much < 1) return 0;
    if(much + stored > 200) much = 200 - stored;
    if(much >= this_player()->query_hp()) return 0;
    write("The magical amulet flashes briefly with powerful magic.\n");
    write("You store "+stored+" hit points in the magic crystal.\n");
    stored += much;
    this_player()->add_hit_point(-much);
    return 1;
  }
  if(what == "get"){
    if(much < 1) return 0;
    if(much > stored) return 0;
    write("The magical amulet flashes briefly with powerful magic.\n");
    write("You feel renewed as the crystal heals you "+much+" hit points.\n");
    stored -= much;
    this_player()->add_hit_point(much);
    if(stored == 0) write("The crystal is empty.\n");
    else write("There are "+stored+" hit points left in the crystal.\n");
    return 1;
  }
  return 0;
}

info(str){
  if(str == "amulet" || str == "necklace"){
  write(
  "This powerful artifact has the power to store a persons life force.\n"+
  "The deep blue crystal pulsates with power.  Commands are:\n"+
  "  amulet          : see how many hit points are stored.\n"+
  "  amulet store <x>: store <x> hit points [max 200]\n"+
  "  amulet get <x>  : retrieve <x> hit points.\n"+
  "The amulet must be worn for any of these powers to work.\n");
  return 1;
  }
}
