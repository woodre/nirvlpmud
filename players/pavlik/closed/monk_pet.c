#define WHO this_player()->query_real_name()
#define ME capitalize(owner)
#define NAME capitalize(owner)+"'s "+capitalize(type)
inherit "/obj/monster";
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
   set_ac(12);
   set_wc(17);
   set_hp(270);
   owner = "Nobody";
   type = "falcon";
   follow = 1;   tellum = 0;
   enable_commands();
  call_out("adjust_for_type", 2);
}

id(str) {
return str == owner+"'s pet" || str == "monk pet" || str == "pet" ||
  str == "guild_monster" || str == type || str == owner+"'s "+type;
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
if(type == "falcon")
say(NAME+" flies out of the room after its master.\n");
else if(type == "wolf")
say(NAME+" silently pads out of the room after its master.\n");
else if(type == "bear")
say(NAME+" lumbers out of the room after its master.\n");
else if(type == "panther" || type == "tiger")
say(NAME+" quietly exits the room after its master.\n");
else if(type == "wolverine" || type == "porcupine")
say(NAME+" scurries out of the room after its master.\n");
else if(type == "boar")
say(NAME+" charges from the room in pursuit of its master.\n");
else if(type == "elephant" || type == "rhinoceros")
say("You feel the ground shake as "+NAME+" leaves the room.\n");
else if(type == "gorilla")
say(NAME+" stomps out of the room.\n");
else if(type == "rock")
say(NAME+" rolls out of the room.\n");
else say(NAME+" slithers out of the room.\n");
    move_object(this_object(), environment(find_player(owner)));
if(type == "falcon")
say(NAME+" flies into the room and circles overhead.\n");
else if(type == "wolf")
say(NAME+" silently enters the room and "+
"sits obediently at its master's side.\n");
else if(type == "bear")
say(NAME+" enters the room and stands protectivly by its master.\n");
else if(type == "panther" || type == "tiger")
say(NAME+" enters the room and paces restlessly before its master.\n");
else if(type == "wolverine")
say(NAME+" scurries into the room bares its sharp fangs at you.\n");
else if(type == "boar")
say(NAME+" charges into the room.\n");
else if(type == "elephant" || type == "rhinoceros")
say("You feel the ground shake as "+NAME+" enters the room.\n");
else if(type == "gorilla")
say(NAME+" stomps into the room.\n");
else if(type == "rock")
say(NAME+" rolls into the room.\n");
else if(type == "porcupine")
say(NAME+" scurries into the room.\n");
else say(NAME+" slithers into the room.\n");
   }
}

set_owner(str) { owner = str; }
set_type(str) { type = str; }
query_type() { return type; }
set_follow(str) { follow = str; }

go() { set_heart_beat(1); return 1; }
short() { return NAME; }
query_name() { return NAME; }


long() {
   object ob;
   object ob2;
   ob = this_player();
   ob2 = find_living(owner);
write(NAME+"\n");
if(type == "falcon") {
write("A small and deadly bird of prey.  The Falcon glides easily\n"+
      "on the warm air above.  The bird's shrill cry echoes in your\n"+
      "ears and the glint of its sharp talons catch your eyes.\n"); }
if(type == "wolf") {
write("A cruel but loyal beast.  The wolf waits patiently by its\n"+
      "master's side.  An urge to hunt and kill is supressed by the\n"+
      "animal's fealty to its master.\n"); }
if(type == "bear") {
write("A huge black bear.  The creature stays protectivly by it's\n"+
       "master's side.  The bear licks its huge paws, paws that could\n"+
        "casually seperate your head with one swipe.\n"); }
if(type == "panther") {
write("A sleek black panther.  The muscles of this deadly predator\n"+
      "ripple beneath its shiny black coat.  Its strange amber eyes\n"+
      "stare at you hungrily.\n"); }
if(type == "wolverine") {
write("A small malicous fighter, the cunning Wolverine extends its\n"+
      "razor sharp claws and draws back its lips to snarl at you\n"+
      "with equally sharp teeth.\n"); }
if(type == "boar") {
write("The Wild Boar is an animal of unparelled rage.  The Boar\n"+
       "restlessly paws the ground, barely managing constraint.\n"); }
if(type == "snake") {
write("An enormous Boa Constrictor, as big around as your thigh.\n"+
      "The Boa's long green body is mottled with black spots,\n"+
     "a body eager to crush the breath from yours.\n"); }
if(type == "tiger") {
write("The deadly orange and black hunter sits before you patiently.\n"+
      "Strong teeth casually rip the meet from its latest kill.  The\n"+
      "Tiger's feline eyes stare you down.\n"); }
if(type == "elephant") {
write("A huge Elephant.  This titon could crush you easily with\n"+
      "a one of its gigantic feet.  The Elephant, normally known as\n"+
      "as a docile creature, can be a deadly and fearsome fighter.\n");
  }
if(type == "gorilla") {
write("The large black Gorilla stares you down with dangerously\n"+
     "intelligent eyes.  The primate flexes its long muscular arms\n"+
     "that could easily, if not happily, rip you apart.\n");
  }
if(type == "rock") {
write(ME+"'s pet rock.  A true and loyal friend.\n");
  }
if(type == "rhinoceros") {
write("The Rhino is an awesome beast of destruction.  Its body is\n"+
      "plated with a hard grey shell, and its head is adorned with\n"+
      "deadly horns that could tear down a building.\n");
  }
if(type == "porcupine") {
write("A small animal covered with bristling spines, like so many\n"+
      "deadly little spears.  The porcupine is normally a very\n"+
      "docile creature, but be wary if it is provoked!\n");
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
add_action("atak","attack");
add_action("get_from_pet","get");
        }
   }
   
release() {
if(type == "falcon") {
write("You set your falcon free.  The bird flies from you forearm\n"+
      "into the sky.  The Falcon circles overhead once then is gone.\n");
say(ME+" sets his falcon free. "+NAME+" leaps of its master's forearm\n"+
 "into the sky.  The bird circles once then is gone.\n");
  }
if(type == "wolf" || type == "panther" || type == "tiger") {
write("You set your "+type+" free.  The "+type+" slips its soft\n"+
      "muzzle into your hand, then quietly slips away.\n");
say(ME+" sets his "+type+" free.\n");
  }
if(type == "bear") {
write("You set your bear free.  The huge animal rises to its hind\n"+
      "feet and affectionatly wraps its forearms around you.\n"+
      "The Bear slips back down to all fours and lumbers off.\n");
write("\n");
say(ME+" frees his pet.  The huge black bear glares at you\n"+
      "menacingly, and then lumbers off.\n");
  }
if(type == "wolverine") {
write("You set your wolverine free.  The ferocious little animal\n"+
      "scurries away in a storm of snarls and growls.\n");
write("\n");
say(ME+" releases his wolverine.  The ferocious little animal\n"+
    "scurries away in a storm of snarls and growls.\n");
  }
if(type == "boar") {
write("You release your Boar from its duty.  The pig glares at you\n"+
   "defiantly with its beady eyes and then it charges off.\n");
say(ME+" releases his pet.\n");
  }
if(type == "snake") {
write("You release your pet.\n");
say(NAME+" slithers from its master's shoulders onto the ground\n"+
      "and disappears into the wilds.\n");
  }
if(type == "elephant" || type == "rhinoceros") {
write("You release your pet.\n");
say(ME+" releases his pet.  The huge beast thunders back into the\n"+
   "wilds.  The ground shakes beneath its mighty feet.\n");
  }
if(type == "gorilla") {
write("You release your Gorilla.\n");
say(ME+"'s large pet stomps of back into the wilds.\n");
  }
if(type == "rock") {
write("You give your pet rock a big hug then let it go.\n");
say(ME+"'s rock rolls away.\n");
  }
if(type == "porcupine") {
write("You release your pet porcupine.\n");
say(ME+" releases his pet porcupine.\n");
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
set_name(owner+"'s "+type);
return 1;
}
query_pet() { return 1; }
   
query_owner() { return owner; }
