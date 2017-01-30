inherit "obj/monster";
object target, owner;
  string name;
int level, hp, wc, ac, test, h;

reset(arg) {
  ::reset(arg);
  if(arg) return;
set_name("shadow");
set_alias("shadow");
set_short("Formless Shadow");
  set_long("Your worst nightmare has come true if this is your shadow\n"+
           "following you. It is a blackish grey in color and has your\n"+
           "likeness for it is a shadow of yourself after all.\n");
  set_level(10);
set_hp(350);
set_wc(15);
set_ac(10);
set_random_pick(9);
  enable_commands();
set_heart_beat(1);
}
catch_tell(str) {
  string s1, s2;
if(sscanf(str, "%s arrives.", s1) != 1) return;
if(!owner) {
  owner = this_player();
  test = 1;
           }
   return 1;
}
heart_beat() {
  ::heart_beat();
if(environment(this_object()) != environment(owner)) {
  tell_room(environment(this_object()), this_object()->query_name()+
   " stalks its pray\n");
  tell_room(environment(owner), this_object()->query_name()+
   " creeps in from the shadows\n");
  move_object(this_object(), environment(owner));
}
  name();
if(query_attack()) {
  attack(owner->query_real_name());
  if(random(100) < 15) {
  owner->hit_player(30);
tell_object(owner, "\n"+
"Your shadow slash's you with the famed SHADOW BLADE!\n");
    }
}
}
name() {
  if(test == 1) {
set_name("shadow");
  set_short(owner->query_real_name()+"'s Shadow of Darkness");
set_long("\n"+
"This is the shadow of "+owner->query_name()+". It looks much like\n"+
owner->query_name()+" but has nothing of substance to its being\n"+
"but a blackish grey mist. Shadows hate everything of this world\n"+
"and want to undo everything about it and their opposites here.\n"+
"If you encounter your shadow beware for they are very powerful\n"+
"and have you heard of any mortal hiding from their shadow? It is\n"+
"not possible to lose or hide from a shadow. You have been warned!\n"
+"BEWARE your shadow "+owner->query_name()+" and do not attack\n");
  return 1;
}
}
follow(str) {
string s1, dir;
  if(sscanf(str, "%s leaves %s", owner, dir) != 2) return;
  if(s1 == owner) {
   move_object(this_object(), environment(owner));
}
}
decorpse(str) {
  string s1;
  if(sscanf(str, "shadow takes corpse of %s", s1) != 1) return;
  this_object()->heal_self(30);
  tell_object(environment(owner), "\n"+
  "The shadow drains the corpse and becomes stronger\n");
  h += 1;
  if(h > 10) {
    if(h < 11) {
       set_hp(400);
                }
    if(h > 20) {
      if(h < 21) {
         set_hp(500);
                  }
                  }
    }
return 1;
}
