inherit "obj/monster";
reset(arg) {
  if(arg) return ; ::reset(arg);
  set_name("bubba");
  set_short("Bubba");
  set_long(
 "Bubba the tattoo artist. A master in his field, Bubba has recently started\n"
+"body piercing. He is bald, and is wearing nothing but shorts, leaving his\n"
+"tattoed skin open for admiration. He could probably get you a tattoo.\n"
+"Type \"ask bubba\" for a list of commands.\n");
  load_chat("Bubba ripples his stomach, and a demon of some sort is lost in the aftershocks.\n");
  load_chat("Bubba smiles at you.\n");
  load_chat("Bubba flicks his nipple ring.\n");
  set_chat_chance(10);
  load_a_chat("Bubba looks for his night stick.\n");
  set_a_chat_chance(10);
  set_level(1);
  set_hp(150);
  set_wc(10);
  set_ac(35);
  set_al(-200);
  load_body();
}
init() {
  add_action("ask","ask");
  add_action("pierce","pierce");
  add_action("tattoo","tattoo");
  ::init();
}
heart_beat() {
 ::heart_beat();
  if(attacker_ob) {
    say("Bubba draws his night stick and slams the hell out of you.\n");
    attacker_ob->heal_self(-(50+random(80)));
  }
 ::attack();
}
ask(str) {
  if(str != "bubba") return 0;
  write("Bubba says: I do two things here:\n");
  write("I \"pierce <body_part>\", and I \"tattoo <place> <design>\"\n");
  write("Bubba says: You wanna see the options? Type \"list pierce\" or\n");
  write("\"list tattoo\".\n");
  return 1;
}
load_body() {
object *t,*r;
  int it,ir;
  it=random(4);
  ir=random(4);
  t=allocate(4); r=allocate(4);
  while(it) {
   t[it]=clone_object("/players/wizardchild/shop/tattoo");
  t[it]->init_arg(random_place()+"|"+random_design());
  move_object(t[it],this_object());
  it--;
  }
  while(ir) {
  r[ir] = clone_object("/players/wizardchild/shop/ring");
  r[ir]->init_arg(random_pierce()+"|"+random_type());
  move_object(r[ir],this_object());
  ir--;
  }
}
random_place() {
string *places;
places = ({"chest","backside","left cheek","right cheek","left arm","right arm","foot","neck","forehead","belly","left hand","right hand"});
return (places[random(sizeof(places))]);
}
random_design() {
string designs;
designs = explode(read_file("/players/wizardchild/shop/designs"),"\n");
return (designs[random(sizeof(designs))]);
}
random_pierce() {
string *places;
places = ({"left ear","right ear","left nostril","right nostril","left eyebrow","right eyebrow","lip","tongue","fingernail","thumbnail","left nipple","right nipple"});
return (places[random(sizeof(places))]);
}
random_type() {
string *types;
types = ({"gold","silver","steel","platinum"});
return (types[random(sizeof(types))]);
}
