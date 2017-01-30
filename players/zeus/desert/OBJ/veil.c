inherit "obj/armor";

reset(arg){

  if(arg) return; ::reset(arg); /* these added by verte */
  set_name("veil");
  set_alias("veil of sand");
  set_short("A veil of sand");
  set_long(
"This delicate veil was once worn by a spirit of the desert.  It hangs\n"+
"down over the wearers face protecting them from attacks.  It seems to\n"+
"be made from a translucent material that looks like grains of sand.\n");
  set_ac(1);
  set_type("helmet");  
  set_weight(1);
  set_value(800+random(151));
}

do_special(owner){
  object atk;
  atk = owner->query_attack();
  if(!atk) return;
  if(!random(20))
  {
    tell_object(environment(owner),
      "A blast of sands suddenly whip out and strike "+atk->query_name()+"!\n");
    atk->hit_player(10+random(6), "other|earth");
  }
}

