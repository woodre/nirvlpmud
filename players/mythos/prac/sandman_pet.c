inherit "obj/monster";

object target, owner;
string name;
int level, hp, wc, ac, guarding;

is_pet() { return 1; }

reset(arg) {
   ::reset(arg);
   if (arg) return;
   set_name("pet");
   set_alias("pet");
   set_short("a generic pet");
   set_long("Yu can have you pet do the following things:\n"+
           "fight <thing>, eat corpse, menace <thing>,\n"+
          "name <name>, release pet, guard, and heel.\n");
   set_level(1);
   set_hp(1);
   set_wc(1);
   set_ac(1);
   enable_commands();
}

patch_owner(o) { owner = o; }

init() {
   ::init();
   add_action("fight","fight");
   add_action("eat","eat");
   add_action("menace","menace");
   add_action("release","release");
   add_action("guard","guard");
   add_action("heel","heel");
   add_action("name","name");
}

fight(str) {
   object target;
   if (!check_ok()) return 0;
   if (!str) return 0;
   target = present(str, environment(this_object()));
   if (!target || !living(target) || !target->query_npc()) {
      write("The pet looks at you with a confused expression.\n");
     return 1;
   }
   write("Your pet leaps to attack "+target->query_name()+".\n");
   say(owner->query_name()+"'s pet leaps to attack "+
      target->query_name()+".\n");
   this_object()->attack_object(target);
   return 1;
}

eat(str) {
   object target;
   if (!check_ok()) return 0;
   if (!str || str != "corpse") return 0;
   target = present("corpse",environment(this_object()));
   if(!target) {
      write("Your pet sniffs around but finds nothing to eat.\n");
      return 1;
   }
   write("Your pet digs into its meal!\n");
   say(owner->query_name()+"'s pet ravages a corpse!\n");
   destruct(target);
   this_object()->heal_self(10);
   return 1;
}

menace(str) {
   object target;
   if (!check_ok()) return 0;
   if (!str) return 0;
   target = present(str, environment(this_object()));
   if (!target) {
      write("The pet sorta looks at you funny.\n");
      return 1;
   }
   write("Your pet moves in on "+target->query_name()+
         ", growling and snapping.\n");
   say(owner->query_name()+"'s pet growls and snaps menacingly at "+
       target->query_name()+".\n");
   return 1;
}

release(str) {
   if (!check_ok()) return 0;
   if (str != "pet") return 0;
   write("You release your pet.\n");
   say(owner->query_name()+" releases the pet.\n");
   destruct(this_object());
   return 1;
}

guard() {
   if (!check_ok()) return 0;
   write("Your pet takes guard.\n");
   say(owner->query_name()+"'s pet looks over the room menacingly.\n");
   guarding = 1;
   return 1;
}

heel()
{
object target;
   if (!check_ok()) return 0;
   write("Your pet snaps to attention.\n");
   say(owner->query_name()+"'s pet snaps to attention.\n");
   target = this_object()->query_attack();
   if (target) {
      this_object()->stop_fight();
      target->stop_fight();
   }
   if (guarding) guarding = 0;
   set_heart_beat(1);
   return 1;
}

name(str) {
   if (!check_ok()) return 0;
   if (!str) return 0;
   set_name(str);
   set_short(str+", "+owner->query_name()+"'s pet");
   set_long("You can have your pet do the following things:\n"+
           "fight <thing>, eat corpse, menace <thing>,\n"+
           "name <name>, release pet, guard, and heel.\n");
   write("Ok - name changed!\n");
   return 1;
}

check_ok() {
   if (!owner) owner = this_player();
   if (this_player() != owner) {
      tell_object(owner, this_player()->query_name()+" is trying "+
                "to command your pet.\n");
      return 0;
   }
   if(this_player()->query_ghost()) {
   write("You are a ghost!\n");
  return 0; }
   return 1;
}

catch_tell(str) {
   string s1,s2;
   object target;
   if (!guarding) return 1;
   if (!owner) destruct(this_object());
   if(sscanf(str, "%s %s.",s1,s2) != 2) return;
   if (lower_case(s2) == "arrives") {
      target = find_living(lower_case(s1));
      if (target) {
         tell_object(owner, "\n\nYour pet tells you: "+
           target->query_name()+" just entered the room!\n\n");
        return 1;
      }
   }
   return 1;
}

heart_beat() {
   ::heart_beat();
     if(!owner || (owner && owner->query_ghost())) { destruct(this_object()); return 1; }
   if(owner->query_sp() > -10) 
        owner->add_spell_point(-1-random(5));
   if (guarding) return;
   if (environment(this_object()) != environment(owner)) {
      tell_room(environment(this_object()), this_object()->query_name()+
              " leaves the room.\n");
     tell_room(environment(owner), this_object()->query_name()+
              " arrives.\n");
      move_object(this_object(),environment(owner));
   }
}
