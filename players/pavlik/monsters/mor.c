inherit "/obj/monster";

string morph_short, morph_long, morph_alias;
string owner;

reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_name( "morph_object" );
 set_alias("morph");
 set_short("A Mage Morph");
 set_long("A Mage Morph");
 set_level(20);
 set_ac(30);
 set_wc(1);
 set_hp(1000);
 set_al(0);
 set_aggressive(0);
 owner = "noone";
 enable_commands();
}

can_put_and_get(){ return 0; }

id(str) {
  return str == "morph" || str == "mage_morph" ||
  str == morph_alias;
}

short() {
  if(environment(this_player()) == this_object())
    return environment(this_object())->short();
  else if(environment(this_player()) == environment(this_object()))
    if(this_player()->query_real_name() == owner) return;
    else return morph_short;
  else
    return "<location unknown>";
}

long() {
  if(environment(this_player()) == this_object()) {
    move_object(this_player(), environment(this_object()));
    command("look", this_player());
    move_object(this_player(), this_object());
  }
  else
    write(morph_long);

  return 1;
}

set_owner(str){ owner = str; }
query_owner(){ return owner; }

/* no teleporting in or out */
realm(){ return "NT"; }

/* these will keep us from being attacked */
query_npc(){ return 0; }
query_interactive(){ return 0; }

init(){
  if(environment(this_player()) == this_object()) {
    /* sorry, no visitors here */
    if(this_player()->query_real_name() != owner) {
      move_object(this_player(), environment(this_object()));
      return 1;
    }
    add_action("unmorph","unmorph");
    add_action("morph_emote","met");
    add_action("morph_quit","quit");
  }
}

morph_config(str) {
  int x;

  /*  x = random(3); */
  x = 0;
  if(str == "tree" || !str) {
    set_name("An old Oak Tree");
    morph_short = "An old Oak Tree";
    morph_long = "An old gnarled oak tree stands here.\n";
    morph_alias = "tree";
  }
  else if(str == "flower") {
    set_name("A blooming Flower");
    morph_short = "A blooming Flower";
    morph_long = "A beautiful yellow flower in full bloom.\n";
    morph_alias = "flower";
  }
  else if(str == "rainbow") {
    set_name("A rainbow");
    morph_short = "A rainbow";
    morph_long = "A shimmering rainbow arches across the sky.\n";
    morph_alias = "rainbow";
  }
  else if(str == "bucket") {
    set_name("A rusty bucket");
    morph_short = "A rusted Bucket";
    morph_long = "An old rusty Bucket.\n";
    morph_alias = "bucket";
  }
  else if(str == "fence") {
    set_name("A white picket Fence");
    morph_short = "A white picket Fence";
    morph_long = "A well-kept white picket fence is here.\n";
    morph_alias = "fence";
  }
  else {
    set_name("An Anvil");
    morph_short = "A huge iron Anvil";
    morph_long = "A huge iron Anvil is here.\n";
    morph_alias = "anvil";
  }

  return 1;
}

catch_tell(str) {
  string tmp;

  if(owner == "noone") return 1;

  if(!present(owner, this_object())) {
    destruct(this_object());
    return 1;
  }

  /* if we die somehow end the spell */
  if(present(owner, this_object())->query_ghost()) {
    tell_room(environment(this_object()),
    morph_short+" screams and falls to the ground ...dead.\n"+
    morph_short+" corpse shimmers and changes shape!\n");
    destruct(this_object());
    return 1;
  }

  if(sscanf(str, capitalize(owner)+" %s", tmp) == 1) {
    tell_room(environment(this_object()),
    morph_short+" "+tmp);
    return 1;
  }
  else {
    tell_room(this_object(), str);
    return 1;
  }
}

morph_emote(str) {
  if(!str) return 0;
  write("You emote:\n");
  tell_room(environment(this_object()), morph_short+" "+str+"\n");
  return 1;
}

unmorph(){
  write("You return to your normal shape.\n");
  move_object(this_player(), environment(this_object()));
  destruct(this_object());
  return 1;
}

morph_quit() {
  write("You must unmorph before you may quit.\n");
  return 1;
}

