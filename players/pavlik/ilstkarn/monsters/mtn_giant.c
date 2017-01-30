inherit "obj/monster";
#define IT capitalize(this_object()->query_attack()->query_name())
#define ROOM environment(this_object())

object obj;
string my_name;
int i;

reset(arg){
 ::reset(arg);
 if(arg) return;

 i = random(3);
 if(i == 0) my_name = "Pykryn";
 else if(i == 1) my_name = "Styokio";
 else if(i == 2) my_name = "Gredj";

 set_name(my_name);
 set_race("mountain giant");
 set_alias(lower_case(my_name));
 set_short(my_name+" the Mountain Giant");
 set_long(
 my_name+" is one of the gigantic Mountain Giants that roam the barren\n"+
 "peaks of the Ilstkarken mountains.  The Mountain Giants are famous\n"+
 "for using their long arms to tear the limbs from helpless travelers.\n");
 set_level(19);
 set_al(-(500+random(500)));
 if(i == 1) set_gender("female"); else set_gender("male");
 set_hp(450);
 set_wc(30+random(10));
 set_ac(14+random(4));
 set_aggressive(5);
 set_can_kill(1);
 money=400+random(400);
 move_object(clone_object("players/pavlik/ilstkarn/heals/keg"), this_object());
 call_out("kombat", 3);
 set_dead_ob(this_object());
}

id(str) {
  return str == my_name || str == lower_case(my_name) || str == "giant" ||
  str == "mtn_giant" || str == "ilstkarn_monster";
}

kombat(){
  int ranx;

  if(!this_object()->query_attack()){
    call_out("kombat", 15);
    return 1;
  }

  obj = this_object()->query_attack();
  ranx = random(10);

  if(!present(obj, ROOM)){
    call_out("kombat", 10);
    return 1;
  }

  if(ranx == 0) tell_room(ROOM,
  my_name+" grabs a boulder and hurls it at "+IT+"!\n"+
  "The boulder misses and goes crashing down the mountain side.\n");
  else if(ranx == 2) tell_room(ROOM,
  my_name+" pummels "+IT+" relentlessly with his huge fist!\n");
  else if(ranx == 4) tell_room(ROOM,
  "The Mountain Giant tries to crush "+IT+" under his foot!\n");
  else if(ranx == 6) tell_room(ROOM,
  my_name+" siezes "+IT+"'s arm and tries to rip it out of its socket!\n");
  else if(ranx == 9) tell_room(ROOM,
  my_name+" grabs a boulder and hurls it at "+IT+"!\n"+
  "The boulder SMASHES "+IT+"'s body against the rocks!\n");
  
  obj->hit_player(10+random(25));
  call_out("kombat", random(10)+2);
  return 1;
}

monster_died() {
  write_file("/players/pavlik/ilstkarn/KILL_LOG",
        ctime() + "\t"+query_name()+" killed by "+capitalize(this_player()->query_name())+" ("+ 
        this_player()->query_level()+")\n");
  return 0;
}

