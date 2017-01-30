#define WHO this_player()->query_real_name()
#define ME capitalize(owner)
#define NAME capitalize(name)
inherit "/obj/monster";
string name;
string owner, nme, type;
int follow, tellum;
reset(arg) {
   ::reset();
   if(arg) return;
   set_name("Pet");
   set_short("Pet");
   set_ep(0);
   set_alias("pet");
   set_can_kill(1);
   set_ep(0);
   set_ac(100);
   set_wc(55);
   set_hp(15);
   owner = "Nobody";
   type = "falcon";
   name = "pavlik";
   follow = 1;   tellum = 0;
   enable_commands();
  call_out("adjust_for_type", 2);
}

id(str) {
 return str == owner+"'s pet" || str == "monk pet" || str == "pet" ||
 str == name || str == type || str == owner+"'s "+type;
}

is_pet() { return 1; }

heart_beat() {
   ::heart_beat();
if(this_object()->query_attack()) {
if(!this_object()->query_attack()->query_npc()
&& !present("mrobe", this_object()->query_attack())) {
      if(this_object()->query_attack()->query_hp()>20)
         this_object()->query_attack()->add_hit_point(-50);
   }
 if(tellum == 5) {
tell_object(find_living(owner),
"["+capitalize(type)+": "+this_object()->query_hp()+" hps]\n");
tellum = 0;
} else {
tellum++; }
}
   if(!find_living(owner)) {
   say(NAME+" leaves to search for its master.\n");
      destruct(this_object());
   }
if(follow == 1 && environment(this_object()) !=
   environment(find_player(owner))) {
say(NAME+" slithers out of the room.\n");
    move_object(this_object(), environment(find_player(owner)));
say(NAME+" slithers into the room.\n");
   }
}

set_owner(str) { owner = str; }
set_type(str) { type = str; }
query_type() { return type; }
set_follow(str) { follow = str; }

go() { set_heart_beat(1); return 1; }
short(){ return NAME+", "+capitalize(owner)+"'s "+type; }
query_name() { return NAME; }


long() {
   object ob;
   object ob2;
   ob = this_player();
   ob2 = find_living(owner);
write(NAME+"\n");
if(type == "snake") {
write("An enormous Boa Constrictor, as big around as your thigh.\n"+
      "The Boa's long green body is mottled with black spots,\n"+
"blah");
}
if(owner==this_player()->query_real_name()) {
write("Your "+type+" has: "+this_object()->query_hp()+" HPs left.\n");
      }
}
   
init() {
 ::init();
 if(this_player()==find_living(owner)) {
add_action("carry_pet","get");
add_action("drop_pet","drop");
add_action("prey_corpse","prey");
add_action("post_pet","post");
add_action("release","release");
add_action("atak","gary");
add_action("get_from_pet","get");
        }
   }

name_my_pet(str){
  if(!str){
    write("Usage: namepet <str>.\n");
    return 1;
    }
  write("You rename your pet.\n");
  name = str;
  this_object()->set_short(capitalize(str)+", "+capitalize(owner)+
  "'s "+type);
  this_object()->set_name(capitalize(str));
  return 1;
}

   
release() {
if(type == "snake") {
write("You release your pet.\n");
say(NAME+" slithers from its master's shoulders onto the ground\n"+
      "and disappears into the wilds.\n");
  }
destruct(this_object());
return 1;
}
   
atak(str) {
      object ob;
if(!str) {
write("What would you like your "+type+" to attack?\n");
return 1; 
  }
if(!(ob=present(str, environment(this_object())))) {
write("That target is not here.\n");
return 1;
  }
if(!ob->query_npc()) {
write("Your "+type+" would be insulted to attack such\n"+
      "a meager target.\n");
return 1;
  }
if(ob == this_object()) {
write("Your pet will not attack itself!\n");
return 1;
  }
write("You command your "+type+" to attack!\n");
if(type == "falcon") {
say(NAME+" dives out of the sky and sets starts ripping "+
capitalize(str)+"\napart with razor sharp talons!\n");
  }
if(type == "wolf" || type == "panther" || type == "tiger") {
write("Your deadly predator leaps at "+capitalize(str)+" and begins\n"+
 "to tear it to pieces with its sharp fangs.\n");
say(NAME+" tears into its helpless target with sharp fangs.\n");
  }
if(type == "bear") {
say(NAME+" rises onto its hind legs and looses a mighty roar!\n"+
   "The Black Bear swats its helpless victim with a huge paw!\n");
  }
if(type == "wolverine") {
say(NAME+" rushes its enemy and begins ripping the helpless "+
   capitalize(str)+" to pieces.\n");
  }
if(type == "boar") {
say(ME+" crazed Boar boldy rushes "+capitalize(str)+" The Boar\n"+
  "buries its sharp tusks deeply into the enemy's body.\n");
  }
if(type == "snake") {
say(NAME+" slides from its master's shoulders onto its target.\n"+
 "The snakes long body wraps around "+capitalize(str)+" and it begins\n"+
 "to squeeze the life from its helpless target.\n");
  }
if(type == "elephant" || type == "rhinoceros") {
say(NAME+" is ordered to attack.  The huge beast charges into battle\n"+
   "with a deadly determination.  "+capitalize(str)+" trembles before "+
    "the wrath of\nthis titon!\n");
  }
if(type == "gorilla") {
say(NAME+" looses a primeval battle cry and rushes into the meelee.\n"+
"The ferocious beast begins to rip "+capitalize(str)+" to pieces!\n");
  }
if(type == "rock") {
say(NAME+" rolls over "+capitalize(str)+"'s foot!\n");
  }
if(type == "porcupine") {
say(NAME+" charges "+capitalize(str)+", firing sharp quills into the "+
" helpless enemy.\n");
  }
ob->set_can_kill(1);
this_object()->attack_object(ob);
return 1;
}
   
post_pet() {
if(type == "wolverine" || type == "boar" || type == "gorilla") {
write("Due to the tenacious manner of the "+type+", you cannot\n"+
      "post this pet.\n");
return 1;
  }
write("You command your pet to remain here.  The "+type+"\n"+
"obediently follows your command and waits.\n");
say(ME+" commands his "+type+" to stay.\n");
follow = 0;
return 1;
}

prey_corpse() {
object corpse;
if(type == "elephant" || type == "rock" || type == "porcupine") {
write("Your pet shows no interest in the corpse.\n");
return 1;
  }
if(!(present("corpse", environment(this_object())))) {
write("There is no corpse here for your "+type+" to feed on.\n");
return 1;
  }
if(this_object()->query_hp() == this_object()->query_mhp()) {
write("Your "+type+" isn't hungry right now.\n");
return 1;
  }
corpse = present("corpse", environment(this_object()));
if(type == "falcon") {
write("Your falcon gratefully swoops down on the corpse and\n"+
      "begins to pick the meat from its bones.\n");
say(NAME+" swoops down on a corpse and pecks the meat from its bones.\n");
  }
if(type == "wolf" || type == "panther" || type == "tiger") {
write("Your "+type+" ravages the carnage, stripping the corpse of\n"+
      "meat with its mighty jaws.\n");
say(NAME+" devours a corpse.\n");
  }
if(type == "bear") {
write("Your huge bear devours the entire corpse in just a few bites.\n");
say(NAME+" devours a corpse.\n");
  }
if(type == "wolverine") {
write("Your little pet ravages the corpse, tearing away the meat\n"+
      "with sharp teeth and savage claws.\n");
say(NAME+" ravages a corpse and strips the meat from its bones.\n");
  }
if(type == "boar" || type == "rhinoceros") {
write("Your "+type+" gleefully rips the corpse to pieces.\n");
say(NAME+" gleefully rips a corpse to pieces.\n");
  }
if(type == "snake") {
write("Your snake feeds on the corpse greedily.\n");
say(NAME+" devours a corpse.\n");
  }
if(type == "gorilla") {
say(NAME+" rips a corpse to pieces and devours it.\n");
  }
destruct(corpse);
this_object()->heal_self(10);
return 1;
}

bring_me() {
if(type == "boar" || type == "wolverine" || type == "snake" || type == "gorilla") {
tell_object(find_player(owner),
 "You cannot call your "+type+".\n");
 return 1;
   }
tell_object(find_player(owner),
"You touch the mind of your "+type+" and summon the animal to you.\n"+
"The "+type+" acknowledges your command and is on the way.\n");
call_out("go_owner", random(10)+10);
return 1;
}

go_owner() {
tell_object(find_player(owner),
"Your "+type+" has arrived!\n");
 follow = 1;
 return 1;
}

carry_pet(str) {
if(str == "wolf" || str == "bear" || str == "panther" || str == "boar"  ||
 str == "gorilla" || str == "tiger" || str == "elephant" ||
 str == "rhinoceros") {
write("Your "+type+" is much to large too carry!\n");
return 1;
if(type == "porcupine") {
write("Don't you think that would be a little painful?\n");
return 1;
  }
  }
if(str == "falcon" || str == "wolverine" || str == "snake" ||
 str == "rock") {
write("You carefully pick up your "+type+" and place it gently\n"+
"on your shoudler.  The "+type+" shifts until it is comfortable,\n"+
"and then seems quite content.\n");
say(ME+" picks up his "+type+".\n");
move_object(this_object(), this_player());
follow = 0;
return 1;
    }
}

drop_pet(str) {
if(str == type) {
follow = 1;
return 1;
   }
}

get_from_pet(str) {
object ob, obj;
string huh, heh;
sscanf(str, "%s %s", huh, heh);
if(heh == "from pet" || heh == "from "+type) {
ob = present(huh, this_object());
if(!ob) {
write("Your "+type+" does not have a "+huh+".\n");
return 1; }
say(ME+" takes a "+huh+" from his "+type+".\n");
move_object(ob, environment(this_player()));
command("get "+huh, this_player());
if(environment(ob) == environment(this_object()))
     move_object(ob, this_object());
return 1;
   }
}

adjust_for_type() {
if(type == "falcon") {
set_hp(175);  set_wc(15);  set_ac(5);
  }
if(type == "wolf") {
set_hp(175);  set_wc(15);  set_ac(5);
  }
if(type == "bear") {
set_hp(175);  set_wc(15);  set_ac(5);
  }
if(type == "panther" || type == "tiger") {
set_hp(175);  set_wc(15);  set_ac(5);
  }
if(type == "wolverine") {
set_hp(175);  set_wc(15);  set_ac(5);
  }
if(type == "boar") {
set_hp(175);  set_wc(15);  set_ac(5);
  }
if(type == "snake") {
set_hp(175);  set_wc(15);  set_ac(5);
  }
if(type == "elephant") {
set_hp(175);  set_wc(15);  set_ac(5);
  }
if(type == "gorilla") {
set_hp(175);  set_wc(15);  set_ac(5);
  }
if(type == "rock") {
set_hp(175);  set_wc(16);  set_ac(5);
  }
if(type == "rhinoceros") {
set_hp(175);  set_wc(15);  set_ac(5);
set_alias("rhino");
  }
if(type == "porcupine") {
set_hp(175);  set_wc(15);  set_ac(5);
  }
if(name == "pavlik") name = owner+"'s "+type;
set_name(owner+"'s "+type);
return 1;
}
query_pet() { return 1; }
   
query_owner() { return owner; }
