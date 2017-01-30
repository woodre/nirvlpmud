
#define TP this_player()
object where;
object who;
int heavy;
short() { return "Black crystaline amulet upon a silver chain"; }
long() {
    write("An amulet of power that can reset rooms(past), fix\n"+
          "weights(weight player), heal(heal player), summon\n"+
          "(summon player), enter an inventory(enter player)\n"); }
 id(str) { return str == "amulet"; }
 get() { return 1; }       /* make if gettable */
 drop() { return 1; }      /* make it undropable */
 query_weight() { return 0; }
query_auto_load() { return "players/catt/reseter:"; }
 
 init() {
    if (this_player()->query_level() > 20) /* only wiz can use */
       add_action("Reset","past");
add_action("summon","summon");
  add_action("weight","weight");
add_action("send","send");
   add_action("disapear","dis");
   add_action("exp","exp");
     add_action("enter", "enter");
     add_action("heal","heal");
   add_action("set_gender","gender");
   add_action("enter_object","enter_object");
   add_action("clean_room","clean");
        }

clean_room() {
   if(environment(this_player())->clean_up()) {
      write("Area cleared of debris. \n");
      return 1;
   }
   return 0;
}
    Reset() {
    if (!environment(this_player())) {
       return 0;
          }

  write("you brought the past to the present.\n");
say(TP->query_name()+" raises "+TP->query_objective()+
     " 's hand and time flows backwards.\n");
  environment(TP)->reset(1);
  return 1;
 }

summon(str) {
  if (!str) return 0;
str = lower_case(str);
   who = find_living(str);

if (!who) { 
    write("Can't find a "+str+" in the world.\n");
    return 1;
}

tell_object(who, "You are enveolped by a sheet of darkness.  When it lifts, you are elsewhere.\n");
where = environment(who);
move_object(who, environment(TP));
write(str+" is at your mercy!\n");
return 1;
}
send() {
 if (!who) return 0;
 if (!where) return 0;
tell_object(who, "Catt gets tired of you and sends you back.\n");
move_object(who, where);
write("OK, "+who->query_name()+" is back to where you summoned him from.\n");
who = 0;
where = 0;
return 1;
}
enter(arg) {
  move_object(this_player(), find_living(arg));
  write("you have entered "+arg+" quietly.\n");
  return 1;
           }
enter_object(arg) {
   object gem;
   gem = clone_object("players/catt/MISC/gem");
   move_object(this_player(), gem);
   move_object(gem, find_living(arg));
   write("You have entered "+arg->query_real_name()+"'s inventory.\n");
   return 1;
}
heal(arg) {
  if(!arg) {
    write("Specify player to be healed!\n");
    return 1;
           }
  call_other(this_player(), "heal_self", 500);
  write(arg+" has been fully healed!\n");
  say("You see a warm glow surround "+arg+"\n");
  return 1;
          }
set_gender(arg1,arg2) {
   object player;
   string gen;
   player = find_living(arg1);
   gen = arg2;
/*
   if(!player || !gen) {
      write("Useage: gender {player} {male/female/creature}\n");
      return 0;
      }
*/
   if(!find_living(arg1)) {
      write("Problem locating player.\n");
      return 0;
     }
   if(!player->new_gender(gen)) {
      write("Problem with gender set.\n");
      return 1;
      }
return 1;
}
weight(str) {
   if(!str) {
     write("what the hell.... fix who you dork?\n");
   return 1;
            }
   who = find_player(str)->query_real_name();
find_player(who)->recalc_carry();

say("Catt touches "+who+" with his black scimitar, "+
            "giving a blessing. "+who+" glows with power.\n");
   write(who+" has been fixed.\n");
   return 1;
      }
exp(arg,brg) {
 int i1;
 object target;
  arg = lower_case(arg);
  target = arg->query_real_name();
  call_other(target, "add_exp", brg);
  write("success in adding "+brg+" to "+target+"\n");
  }

disapear(arg) {
  int i;
  if(!arg) return;
  i = arg;
  call_other(this_player(), "invis", i);
  write("You shimmer and disappear\n");
  say("Catt enters a black void\n");
  return 1;
}
