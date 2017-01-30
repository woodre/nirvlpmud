inherit "obj/armor";
#define EN environment(this_object())
#define ME capitalize(environment(this_object())->query_name())
#define IT capitalize(environment(this_object())->query_attack()->query_name())

reset(arg){
  if(arg) return;
  ::reset(arg);
  set_short("A suit of Rusty Platemail");
  set_long(
  "A full suit of Platemail Armor.  This suit of armor might have\n"+
  "been fashionable in its time, but now it is nothing more than a\n"+
  "mass of rusted metal.  The metal plates, although rusted, still\n"+
  "seem to be in decent shape.  Even the leather padding remains\n"+
  "mostly intact.\n");
  set_ac(4);
  set_weight(5);
  set_value(15000);
  set_alias("platemail");
  set_name("Rusty Platemail");
  set_type("armor");
  call_out("funks", 10);
}

funks(){
  int ranx;

  if(!worn){
    call_out("funks", 50);
    return 1;
  }

  ranx = random(5);

  if(ranx == 0) {
    tell_object(EN, "Flakes of rust fall from your armor.\n");
    room_say("Flakes of rust fall from "+ME+"'s armor.\n");
  }
  else if(ranx == 2) {
    tell_object(EN, "Your armor squeals loudly!\n");
    room_say(ME+"'s armor squeals loudly!\n");
  }
  else if(ranx == 3) {
    tell_object(EN, "Your platemail armor squeaks noisily as you move.\n");
    room_say(ME+"'s platemail armor squeaks noisily as "+
    EN->query_pronoun()+" moves.\n");
  }
  else if(ranx == 4) {
    tell_object(EN,
    "A plate of your armor falls off and clatters on the ground.\n"+
    "You hurriedly pick it up and strap it back on.\n");
    room_say(
    "A plate of "+ME+"'s armor falls off and clatters on the ground.\n"+
    ME+" hurriedly picks up the plate and straps it back on.\n");
  }

  call_out("funks", 30+random(180));
  return 1;
}

room_say(str) {
  object obj;
  int i;

  if(!environment(EN)) return;
  obj = all_inventory(environment(EN));
  for(i=0; i<sizeof(obj); i++) {
    if(obj[i] != EN) {
      tell_object(obj[i], str);
    }
  }
  return 1;
}

