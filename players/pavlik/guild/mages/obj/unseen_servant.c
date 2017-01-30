inherit "obj/monster";
#define ME capitalize(owner->query_name())
#define DEST capitalize(destination->query_name())

int failed;
object owner;
object destination;
object cargo;

reset(arg){
 ::reset(arg);
 if(arg) return;
 set_name("Shadowy Servant");
 set_race("unseen_servant");
 set_short("A Shadowy Servant");
 set_long("A shadowy servant, summoned by a powerful Mage.\n");
 set_hp(100);
 set_ac(50);
 set_wc(1);
 set_al(0);
 set_level(1);
 call_out("serve", 10+random(20));
}

set_owner(ob){ owner = ob; }
set_destination(ob){ destination = ob; }
set_cargo(ob){ cargo = ob; }
set_failed(i){ failed = i; }

serve() {
  int value;

  if(!owner) {
    destruct(this_object());
    return 1;
  }
  if(!cargo) {
    tell_object(owner,
    "Your unseen servant spell was bugged.\n"+
    "Spell fail - cause unknown.\n");
    destruct(this_object());
    return 1;
  }
  if(failed) {
    tell_object(owner, "\n"+
    "Your unseen servant has broken the spell!\n"+
    "The trecherous servant has run away with your "+
    cargo->short()+".\n");
    destruct(this_object());
    return 1;
  }
  if(destination == this_object()) {

    tell_room(environment(owner),
    "A chill runs down your spin when a shadowy figure rises from the ground.\n"+
    "The ghostly figure gives something to "+ME+".\n"+
    "It bows deeply to "+ME+" and then disappears into the ground.\n");

    /* calculate the legal value of the object */
    value = cargo->query_value();
    if(value > 1000) value = 1000+random(400);
    if(value > cargo->query_value()) value = cargo->query_value();

    tell_object(owner,
    "Your servant gives you "+value+" gold coins.\n");
    owner->add_money(value);
    destruct(cargo);
    destruct(this_object());
    return 1;
  }
  if(!destination) {
    tell_room(environment(owner),
    "You feel a chill in your heart when a shadowy figure appears.\n"+
    "The gives something to "+ME+" and then disappears.\n");
    tell_object(owner,
    "The servant whispers to you: Mmmmaaaaaaster, He cound not be ffffound.\n");
    if(transfer(cargo, owner)) {
      tell_object(owner,
      "You cannot carry the object.  Your servant places it on the ground.\n");
      transfer(cargo, environment(owner));
    }
    else {
      transfer(cargo, owner);
    }
    destruct(this_object());
    return 1;
  }
  tell_room(environment(destination),
  "A chill enters your heart when a shadowy figure rises from the ground.\n"+
  "The shadow points a long narrow finger at "+DEST+".\n");
  tell_object(destination,
  "A shadowy servant whispers to you: "+ME+" has ssssent thissss to you.\n");
  if(transfer(cargo, destination)) {
    tell_object(destination,
    "You cannot carry this much.  The item is placed on the ground.\n");
    tell_room(environment(destination),
    "The shadow places something on the ground and disappears.\n");
    transfer(cargo, environment(destination));
  }
  else {
    tell_room(environment(destination),
    "The shade gives something to "+DEST+" and then disappears.\n");
    transfer(cargo, destination);
  }
  tell_object(owner,
  "Your servant whispers to you: The ttttask issss complete, Maassster.\n"+
  "The unseen servant disappears.\n");
  destruct(this_object());
  return 1;
}



