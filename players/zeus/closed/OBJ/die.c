inherit "/obj/weapon.c";
string *roo, *num, *voo, *joo;

reset(arg) {
  ::reset(arg);
  if (arg) return;

  roo = ({ "drinking", "hawking", "juicing", "tripping", "walking",
    "riding", "diving", "falling", "breathing", "scolding", "running",
    "peacekeeping", "squirreling", "cutting", "sucking", "licking", });

  num = ({ "two", "three", "four", "five", "six", "seven", "eight",
    "nine", "ten", });

  voo =({ "three men", "black hawks", "a scooter", "an elephant",
  "drinking swallows", "a fat old cat", "lefty mc doogle", "pinky",
  "your fake hair", "nine cats in a cradle", "working life",
  "idealized happiness", "drinking knife", "cutting edge", "working out",
  "nine times out of ten", "each is his own scandal",
  "hoboesque moooners", "lifers", "hound dogs", "cuttlery owls",
  "hucking sacks", "doooos", "PE-LD", "is protects herself", });

  joo =({ "off a cliff", "out a window", "through a tunnel",
    "up a wall", "down an alley", "in a quarry", "over the hills",
    "through the woods", "into the chimney", "off a horse",
    "out a cloud", "in the sun", "behind the moon", "in my pants",
    "in your knees", "through your retinal cavity", "in the grass", });

  set_name("concept");
  set_type("misc");
  set_value(4800);
  set_weight(0);
  set_class(18);
  set_hit_func(this_object());
  message_hit=({
    "vestipolated", "",
    "subliminated", "",
    "delineated",   "",
    "idealized",    "",
    "actualized",   "",
    "agreed with",  " wholeheartedly",
    "listened to",  " thoughtfull",
  });
}

query_save_flag(){    return 1; }
query_dest_flag() { return 1; }

short(){
  if(environment() && living(environment()))
    short_desc = "concept of "+environment()->query_real_name();
  else
    short_desc = "concept of";
  return ::short();
}

long(){
  write(
"This is a concept weapon.  It can be used in many ways.  It has no\n"+
"physical form and thus is by no means a conventional weapon.  It\n"+
"flickers with an aura of imagination and conceptualization.\n");
}

int weapon_hit(object t){
  set_hits(0);
  set_misses(0);
  tell_room(environment(environment()), 
    environment()->query_real_name()+" "+
    roo[random(sizeof(roo))]+" "+num[random(sizeof(num))]+
    " "+voo[random(sizeof(voo))]+" "+joo[random(sizeof(joo))]+".\n");
  if(environment()->query_intoxination() && !random(8))
  {
    tell_room(environment(environment()),
      "\t\t\tlifah lifah lifah\n");
    environment()->drink_alcohol(-3);
    return random(-5);
  }
}
