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
 if(i == 0) my_name = "Woelo";
 else if(i == 1) my_name = "Yeoric";
 else if(i == 2) my_name = "Emkeke";

 set_name(my_name);
 set_race("human");
 set_alias(lower_case(my_name));
 set_short(my_name);
 set_long(
 my_name+" is a fearless adventurer, scaling the mountains of Ilstkarn alone.\n"+
 "He is equipped with various sorts of climbing gear and other items neccesary\n"+
 "for survival in this dangerous environment.  "+my_name+" holds a short length\n"+
 "of rope in his hands, which he examines with a growing look of concern.\n");
 set_level(19);
 set_al(random(500));
 set_gender("male");
 set_hp(450);
 set_wc(30+random(10));
 set_ac(14+random(4));
 set_aggressive(0);
 set_can_kill(1);
 set_chat_chance(40);
 set_a_chat_chance(30);
 load_chat(my_name+" says: I can't belive it broke!\n");
 load_chat(my_name+" stares at the rope in disbelief.\n");
 load_chat(my_name+" says: Now what do I do?\n");
 load_chat(my_name+" says: Whew!  That was close!\n");
 load_a_chat(my_name+" says: You can't do this to me!\n");
 load_a_chat(my_name+" pummels you with his fist.\n");
 load_a_chat(my_name+" says: Oh no!  Not you!\n");
 load_a_chat(my_name+" kicks you in the shin!\n");
 set_chance(20);
 set_spell_dam(35);
 set_spell_mess1(
 my_name+" kicks his enemy in the shin!\n");
 set_spell_mess2("\n"+
 my_name+" grabs your leg and bites it!  OUCH!!!\n");
 money=900+random(400);
 move_object(clone_object("players/pavlik/ilstkarn/treasure/rope"), this_object());
 move_object(clone_object("players/pavlik/ilstkarn/heals/rations"), this_object());
 set_dead_ob(this_object());
}

id(str) {
  return str == my_name || str == lower_case(my_name) ||
  str == "mtn_climber" || str == "ilstkarn_monster";
}

monster_died() {
  write_file("/players/pavlik/ilstkarn/KILL_LOG",
        ctime() + "\t"+query_name()+" killed by "+capitalize(this_player()->query_name())+" ("+ 
        this_player()->query_level()+")\n");
  return 0;
}

