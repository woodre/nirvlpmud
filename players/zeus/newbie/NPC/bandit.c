inherit "/obj/monster";
int type;
string y;

eq(){
 int x;
 object eq;
 x = random(7);
 switch(x){
 case 0: eq = clone_object("/players/zeus/newbie/OBJ/shield.c"); break;
 case 1: eq = clone_object("/players/zeus/newbie/OBJ/helm.c"); break;
 case 2: eq = clone_object("/players/zeus/newbie/OBJ/boots.c"); break;
 case 3: eq = clone_object("/players/zeus/newbie/OBJ/vest.c"); break;
 case 4: eq = clone_object("/players/zeus/newbie/OBJ/gloves.c"); break;
 case 5: eq = clone_object("/players/zeus/newbie/OBJ/cloak.c"); break;
 case 6: eq = clone_object("/players/zeus/newbie/OBJ/knife.c"); break;
 }
 move_object(eq, this_object());
 if(6 == x)
   init_command("wield knife");
 else
   init_command("wear "+(string)eq->query_name());
}

reset(arg){
  ::reset(arg);

  eq();

   if(!arg){

 type = random(3);
 if(0 == type) y = "An angry"; else if(1 == type) y = "A mean looking";
 else if(2 == type) y = "A tough"; else if(3 == type) y = "A dirty";
 else if(4 == type) y = "An unhappy"; else if(5 == type) y = "A hot";
 else if(6 == type) y = "A tired";  else if(7 == type) y = "A swift";
 else if(8 == type) y = "An experienced"; else if(9 == type) y = "An old";
 else if(10 == type) y = "A young"; else if(11 == type) y = "A small";

 set_name("bandit");
 set_short(y+" bandit");
 set_long(
"This is one of the many bandits whom inhabit this forest.  His face\n"+
"is painted with some white and black stripes, and he is wearing some\n"+
"worn leather clothing.  He looks as though he is prepared to guard\n"+
"his territory with his life.\n");
 set_race("human");
 set_gender("male");
 set_level(10 + random(6));
 set_ac(6 + random (8));
 set_wc(10 + random(14));
 set_hp(100 + random(110));
 add_money(25+random(200));
 set_aggressive(0);
 set_al(-random(400));
 set_chat_chance(3);
 set_a_chat_chance(1);
 load_chat("The bandit asks, \"What're you doin here?\"\n");
 load_chat("The bandit grins at you.\n");
 load_chat("The bandit says, \"Watch your step around here.\"\n");
 load_chat("The bandit glances into the forest.\n");
 load_chat("The bandit asks, \"What're you lookin at?\"\n");
 load_chat("The bandit glances behind him.\n");
 load_chat("The bandit says, \"Don't make me hurt you.\"\n");
 load_chat("The bandit says, \"Don't make me have to get rough.\"\n");
 load_chat("The bandit looks at you with fierce eyes.\n");
 load_chat("The bandit watches you closely.\n");
 load_a_chat("The bandit yells, \"You're gunna pay for this!\"\n");
 load_a_chat("The bandit screams at you!\n");
 load_a_chat("The bandit yells, \"I will kill you!\"\n");
 set_chance(8);
 set_spell_dam(5+random(15));
 set_spell_mess1("The bandit gets a very angry look on his face.\n");
 set_spell_mess2("The bandit hits you with a crushing blow.\n");
} }

heal(){
  tell_room(environment(),
	  "The bandit takes a drink of water.\n");
  hit_point += 15;
}

atk(){
  int old;
  old = weapon_class;
  if(!attacker_ob->query_ghost()){
    weapon_class = weapon_class / 3;
    already_fight = 0; 
    ::attack();
  }
  weapon_class = old;
}

wimpy(){
  string *dirs, str;
  int x, rand;
  if(!present(attacker_ob, environment())) return 0;
  tell_room(environment(),	"\n");
  dirs = environment()->query_dest_dir();
  rand = random(sizeof(dirs)-1);
  x = rand / 2 * 2;
  str = dirs[x + 1];
  str += "#";
  str += dirs[x];
  this_object()->move_player(str);
}

void heart_beat(){
	::heart_beat();
	if(!environment()) return;
	if(!attacker_ob) return;
	if(!random(12)){ heal(); return; }
	if(!random(6)){ atk(); return; }
	if(!random(6) && hit_point <= 20) wimpy();
}


