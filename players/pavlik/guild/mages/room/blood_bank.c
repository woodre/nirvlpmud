inherit "room/room";
#define tp this_player()
#define ME capitalize(this_player()->query_name())
  object obj;
 reset(arg) {
  if(!arg) {

set_light(1);
short_desc="The Bloodbank";
long_desc=
"You are in the crazed mage Grethon's chamber.  Hidden deep below the\n"+
"Mage's Tower, Grethon conducts his miraculous experiments.  The old\n"+
"wizard lost his left leg in the miscasting of a spell, and has been\n"+
"conducting strange experiments ever since to regain the limb.  Grethon\n"+
"has been known to pay very well for things that may help him out.\n"+
"There is a sign on the back wall.\n";

items=({"sign",
"       * Grethon's Laboratory *           \n"+
"Grethon will pay for blood donations and for\n"+
"corpses.  The going rates on blood are:\n"+
"   1 Pint   (50hp)    -   500gp\n"+
"   1 Quart  (100hp)   -  1000gp\n"+
"   1 Gallon (200hp)   -  2400gp\n"+
"Cash for corpses is dependent upon the condition\n"+
"of the corpse.  Use 'give <amt>' to donate blood\n"+
"            i.e. pint, quart, gallon\n"+
"or 'sell corpse' to sell a corpse\n"+
"All sales are final!\n"+
"        - Grethon",
});

dest_dir=({
  "/players/pavlik/guild/mages/room/bank_stairs", "up",
});

if(!present("grethon", this_object())){
  obj = clone_object("players/pavlik/guild/mages/rooms/npc/grethon");
  move_object(obj, this_object());
  }

   }
}

init() {
  ::init();
 add_action("give_blood","give");
 add_action("sell_corpse","sell");
}

give_blood(str){
  object obj;
  int x;

  if(str ) tell_room( this_object(), "Str: " + str + "\n");
  if(str != "pint" && str != "quart" && str != "gallon")
    return 0;

  if(str == "pint"){
    if(tp->query_hp() < 55){
      rejected();
      return 1;
      }
    drain_blood(50,500);
    return 1;
    }

  if(str == "quart"){
    if(tp->query_hp() < 105){
      rejected();
      return 1;
      }
    drain_blood(100,1000);
    return 1;
    }

  if(str == "gallon"){
    if(tp->query_hp() < 205){
      rejected();
      return 1;
      }
    drain_blood(200,2400);
    return 1;
    }

  write(
  "Grethon gives you a puzzled look.\n");
  return 1;
}


drain_blood(HP,MON){
  if((int)this_player()->query_money() > 80000) {
    write("You have too many coins already, you spud.\n");
    return 1;
  }
  write(
  "Grethon pulls a two-foot long needle from behind his back and\n"+
  "smiles wickedly.  He quickly plunges the needle into your arm\n"+
  "and begins to draw out the blood.  He grins nastily as he drains\n"+
  "your life's blood away!  After the crazed wizard drains your body\n"+
  "dry, he drops some coins into your withered palm.\n");
  say(
  "Grethon pulls out a very long, very sharp needle and goes over\n"+
  "to "+ME+".  The crazed wizard plunges the needle into "+ME+"'s arm\n"+
  "and begins to suck out his blood.  The insane mage grins nastily\n"+
  "as he drains "+ME+"'s life away.  Finally, he pulls the needle out\n"+
  "of "+ME+"'s withered husk and drops some coins into his hand.\n");
  this_player()->add_hit_point(-HP);
  present("mageobj", this_player())->add_donation(MON);
  return 1;
}

rejected(){
  write(
  "The crazed wizard looks you over carefully.\n"+
  "Grethon says: You are not healthy enough, go away!\n");
  return 1;
}

sell_corpse(str){
  object obj;
  int coinage;

  if(!str || str != "corpse"){
    return 0;
    }

  obj = present("corpse", this_player());

  if(!obj)
    obj = present("corpse", this_object());

  if(!obj){
    write(
    "Grethon says: There is no corpse here!  Unless, that is,\n"+
    "              You are volunteering...\n"+
    "The crazed mage smiles wickedly.\n");
    return 1;
    }

  write(
  "The crazed mage drags the body into the center of the room.\n"+
  "He carefully looks at the corpse, taking special note of\n"+
  "the body's feet.\n"+
  "Grethon says: Hhmm, yesss.  This one will do.\n"+
  "The Wizard drops some coins into your palm.\n");
  coinage = obj->heal_value() * 10;
  write("You sell a corpse for "+coinage+" gold coins.\n");
  say(
  ME+" sells a corpse to Grethon.\n");
  present("mageobj", this_player())->add_donation(coinage);
  destruct(obj);
  return 1;
}
