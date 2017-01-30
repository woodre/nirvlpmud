#define FINAL     741070800
#define TP        this_player()
#define TO        this_object()
#define GLEVEL    TP->query_guild_rank()
#define NAME      TP->query_real_name()
#define CAP(str)  capitalize(str)
#define CN        CAP(NAME)
#define THIS      environment(TO)
#define ENV_THIS  environment(TP)
#define env(X)    environment(X)
#define LEVEL     TP->query_level()
#define QRN       query_real_name()
#define QGR       query_guild_rank()
#define QGEXP     query_guild_exp()
#define SP        TP->query_sp()
#define HP        TP->query_hp()
#define NOSP      write("You do not have enough spell points for that.\n");
#define HEAL_SWAP 20
int MUFFLED;
int HP_STORED;
object pet;
 
drop() { return 1; }
 
get() { return 1; }
 
query_possessive() {
  if(TP->query_gender()=="male") return "his";
  else if(TP->query_gender()=="female") return "hers";
  return "its";
}
 
query_muffled() { return MUFFLED; }
 
say_it_in_lingo(str) {
  object ob;
  if(!str) {
    write("Say what?\n");
    return 1;
  }
  ob = first_inventory(ENV_THIS);
  while(ob) {
    if(present(THISFACTION,ob) && ob!=TP)
      tell_object(ob,CN+" recites: "+str+"\n");
    else
      if(ob!=TP)
        tell_object(ob,CN+" speaks in a cryptic tongue.\n");
    ob = next_inventory(ob);
  }
  write("You recite: "+str+"\n");
  return 1;
}
 
who_is_on(low,hi) {
object people;
string sex;
object bad;
int n;
people = users();
write("-Name-\t\t-Sex-\t-Level-\t-Location-\n");
for(n=0; n<sizeof(people); n++) {
  if(present(THISFACTION,people[n])) {
    if(people[n]->query_invis() > LEVEL) {
      write("");
    } else {
    if(people[n]->QGR<(hi+1) &&
       people[n]->QGR>(low-1)) {
      write(capitalize(people[n]->QRN));
      if(strlen(people[n]->QRN)>7) { write("\t"); }
      else { write("\t\t"); }
      sex=people[n]->query_gender();
      if(sex=="male") sex="M";
      else if(sex=="female") sex="F";
      else sex="C";
      write(sex+"\t");
      write(people[n]->QGR+"\t");
      if(present("badge",people[n])->query_morphed()) {
        write(environment(people[n])->short()+" -> "+
        environment(environment(people[n]))->short());
      } else {
        write(environment(people[n])->short());
      }
      if(people[n]->query_invis() > 0) write("  (invis)");
      bad = present(THISFACTION,people[n]);
      if(bad->query_muffled()==1) write("  (muffled)");
      write("\n");
    }
    }
  }
}
return 1;
}
 
tell_the_guilders(str,lt,rt) {
  object people;
  int n;
  people=users();
  for(n=0;n<sizeof(people);n++)
    if(present(THISFACTION,people[n]) && 
       !present(THISFACTION,people[n])->query_muffled())
        tell_object(people[n],lt+CN+rt+": "+str+"\n");
  return 1;
}
 
lessp(i) {
  TP->add_spell_point((-1 * i));
  return 1;
}
 
guild_emote(str) {
  int i, lev;
  object people;
  lev = 10;
  if(GLEVEL<10) {
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  if(!str) {
    write("What do you want to emote?\n");
    return 1;
  }
  people = users();
  for(i=0;i<sizeof(people);i++) {
    if((present(THISFACTION,people[i])
      && people[i]->QGR>lev)) {
      if(!present(THISFACTION,people[i])->query_muffled())
        tell_object(people[i],"\n+>>"+CN+" "+str+"\n");
    }
  }
  lessp(2);
  write("You faction_emote:\n"+CN+" "+str+"\n");
  return 1;
}
 
getem(hit,sp,what,writemsg,saymsg) {
  object ob;
  if(SP<sp) { NOSP; return 1; }
  if(present(what,ENV_THIS))
    ob=present(what,ENV_THIS);
  else { write("That is not here.\n");
          return 1;
    }
  if(!ob->query_npc()) {
    write("That is not a monster.\n");
    return 1;
  }
  TP->attack_object(ob);
  ob->hit_player(hit);
  lessp(sp);
  write(writemsg+".\n");
  say(saymsg+".\n");
  return 1;
}
 
lvl_ok(x) {
  if(GLEVEL>(x-1)) return 1;
  write("You are not a high enough guild level for that yet.\n");
  return 0;
}
 
swap_coins_for_healing(x) {
  int amt;
  amt = x / HEAL_SWAP;
  if(TP->query_money()<x) {
    write("You do not have enough coins for that.\n");
    return 1;
  }
  if(x<1) {
    write("Yeah, right, like I'm gonna fall for that one.\n");
    return 1;
  }
  TP->add_money(-x);
  TP->heal_self(amt);
  write("You healed yourself for "+amt+" points.\n");
  say(CN+" healed "+query_possessive()+"elf.\n");
  return 1;
}
 
set_pet(ob) { pet = ob; }
 
set_hp_stored(x) { HP_STORED = x; }
 
nope() {
  write("Barbarians cannot use game spells.\n");
  return 1;
}
 
guild_who() {
  who_is_on(1,1000);
  return 1;
}
 
generic_shaddup() {
  write("Faction Lines: ");
  if(MUFFLED) write("OFF\n");
  else write("ON\n");
  MUFFLED = !MUFFLED;
  return 1;
}
 
coins_to_heal(str) {
  int amt;
  if(!sscanf(str,"%d",amt)) {
    write("How many coins do you want to swap?\n");
    return 1;
  }
  swap_coins_for_healing(amt);
  return 1;
}
 
hp_store(str) {
  int x;
  if(!(sscanf(str,"%d",x))) {
    write("How many hit points do you want to store?\n");
    return 1;
  }
  if(HP<x) {
    write("You do not have that many hit points.\n");
    return 1;
  }
  if(x<1) {
    write("Yeah, right, like I'm gonna fall for that one.\n");
    return 1;
  }
  if((HP_STORED+(x/2))>100) {
    write("That would put you over the limit...");
    x = (100*2) - (HP_STORED*2);
    write("adding "+x+" to max it.\n");
  }
  TP->add_hit_point(-x);
  HP_STORED += (x/2);
  write(HP_STORED+" total hit points now stored.\n");
  return 1;
}
 
hp_retrieve(str) {
  int x;
  if(!(sscanf(str,"%d",x))) {
    write("How many hit points do you want to retrive?\n");
    return 1;
  }
  if(x<1) {
    write("Yeah, right, like I'm gonna fall for that one.\n");
    return 1;
  }
  if(HP_STORED<x) {
    write("You do not have that many stored...");
    x = HP_STORED;
    write("retriving "+x+" hit points.\n");
  }
  TP->heal_self(x);
  HP_STORED -= x;
  write("Healed by "+x+" points.\n");
  return 1;
}
 
tame(str) {
  int x;
  x = random(100);
  if(!str) {
    write("What do you want to tame?\n");
    return 1;
  }
  if(!present(str,ENV_THIS)) {
    write("That is not in the room.\n");
    return 1;
  }
  if(SP<20) { NOSP; return 1; }
  if(x<21) {
    write("The attempt failed!\n");
    present(str,ENV_THIS)->attack_object(TP);
    say(CN+" tried to tame a "+CAP(str)+" but failed!\n");
    lessp(25);
    return 1;
  }
  present(str,ENV_THIS)->set_aggressive(0);
  lessp(20);
  write("You tame the beast.\n");
  say(CN+" tames a "+CAP(str)+".\n");
  return 1;
}
 
scare(str) {
  int x;
  object per;
  x = random(100);
  if(!str) {
    write("Who do you want to scare?\n");
    return 1;
  }
  if(SP<15) { NOSP; return 1; }
  if(!(per=present(str,ENV_THIS))) {
    write("That is not in the room.\n");
    return 1;
  }
  if(ENV_THIS->realm()=="NT") {
    write("That is not allowed in this room.\n");
    return 1;
  }
  if(x<21) {
    write("You fail!\n");
    say(CN+" tries to scare "+CAP(str)+" but fails!\n");
    lessp(15);
    TP->run_away();
    return 1;
  }
  if(per->query_npc()) {
    write("You cannot scare monsters!\n");
    return 1;
  }
  lessp(15);
  say(CN+" waves "+query_possessive()+" arms in the air and "+
      CAP(str)+"\nfreaks out and runs out of the room.\n");
  write("You scare "+CAP(str)+" and they run out of the room.\n");
  per->run_away();
  return 1;
}
 
pet2(str,what) {
  string first,second;
  if(!str) {
    pet2("help",what);
    return 1;
  }
  if(!(sscanf(str,"%s %s",first,second))) first = str;
  if(first=="summon") {
    if(pet) {
      write("You already have a "+what+".\n");
      return 1;
    }
    if(SP<100) { NOSP; return 1; }
    pet = clone_object("/players/grimm/closed/obj/badge_stuff/pet2");
    pet->set_owner(TP);
    pet->set_nme(CN);
    pet->set_own_name(NAME);
    pet->set_what(what);
    pet->set_short(CN+"'s "+what);
    pet->set_level(GLEVEL);
    pet->set_wc(15+(TP->weapon_class()));
    pet->set_ac(5+(TP->armor_class()));
    pet->set_hp(GLEVEL*15+100);
    pet->set_level(LEVEL);
    pet->set_heart_beat(1);
    move_object(pet, ENV_THIS);
    lessp(100);
    write("You summon a "+what+" to your side. (type \""+what+
          " help\" for more help)\n");
    say(CN+" summons a "+what+" to "+query_possessive()+" side.\n");
    return 1;
  }
  if(first=="help" || str=="help") {
    cat("/players/grimm/closed/obj/badge_stuff/"+what+".help");
    return 1;
  }
  if(!pet) {
    write("You do not have a "+what+" yet.\n");
    return 1;
  }
  if(first=="bring" || str=="bring") {
    write("Your "+what+" runs to your side.\n");
    say(CN+" orders "+query_possessive()+" "+what+" to "+query_possessive()+" side.\n");
    tell_room(environment(pet),CN+" orders "+query_possessive()+" "+what+" to "+query_possessive()+" side.\n");
    move_object(pet,ENV_THIS);
    return 1;
  }
  if(first=="north" || first =="n") pet->north();
  else if(first=="south" || first=="s") pet->south();
  else if(first=="east" || first=="e") pet->east();
  else if(first=="west" || first=="w") pet->west();
  else if(first=="northwest" || first=="nw") pet->nw();
  else if(first=="northeast" || first=="ne") pet->ne();
  else if(first=="southwest" || first=="sw") pet->sw();
  else if(first=="southeast" || first=="se") pet->se();
  else if(first=="up" || first=="u") pet->up();
  else if(first=="down" || first=="d") pet->down();
  else if(first=="look" || first=="l") pet->Look();
  else if(first=="say" || first=="'") pet->psay(second);
  else if(first=="emote" || first==":") pet->pemote(second);
  else if(first=="tell") pet->ptell(second);
  else if(first=="follow") pet->follow();
  else if(first=="stay") pet->stay();
  else if(first=="leave") {
    write("You release your "+CAP(what)+".\n");
    say(CN+" releases "+query_possessive()+" "+CAP(what)+".\n");
    destruct(pet);
    return 1;
  }
  else pet->other(str);
  return 1;
}
 
peek(str) {
  object ob, ob2, inv;
  if(!str) return;
  if(SP<5) { NOSP; return 1; }
  lessp(5);
  ob=env(TP);
  ob2=clone_object("players/grimm/closed/obj/badge_stuff/seer");
  move_object(ob2,environment(this_player()));
  move_object(TP,ob2);
  env(TP)->invis(1);
  if(!command(str,env(TP))) {
    write("That is not a valid exit.\n");
    move_object(TP,ob);
    destruct(ob2);
    return 1;
  }
  write("Exit: "+str+"\n\n");
  env(env(TP))->long();
  inv=first_inventory(env(env(TP)));
  while(inv) {
    if(inv->short()&&inv!=env(TP))
      write(inv->short()+"\n");
    inv=next_inventory(inv);
  }
  move_object(TP,ob);
  destruct(ob2);
  return 1;
}
