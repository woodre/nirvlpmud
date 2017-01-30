/*  Basic Gurther */

#include <ansi.h>
inherit "/obj/monster";
#define OQJ +attacker_ob->query_objective()+
#define OQN +attacker_ob->query_name()+
#define TQP +this_object()->query_possessive()+
#define TIME 80

int random_type, value, help, type;
object guard;

reset(arg){
  ::reset(arg);
  if(!arg){

    help = 1;       /*  Can call help once  */

    set_name("gurther");
    set_race("gurther");
    set_al(500+random(500));
    set_chat_chance(2);
    set_a_chat_chance(1);
    load_a_chat("You stagger from the strength of the blow.\n");
    set_dead_ob(this_object());

    random_type = random(6);                /*  lv ac wc hp     */
    if(random_type == 0){   young();    }   /*  18 13 28 400    */
    if(random_type == 1){   hunter();   }   /*  20 13 36 500    */
    if(random_type == 2){   strong();   }   /*  20 17 30 600    */
    if(random_type == 3){   female();   }   /*  18 11 28 440    */
    if(random_type == 4){   guard();    }   /*  20 14 34 550    */
    if(random_type == 5){   worker();   }   /*  19 14 31 500    */
  }
}


young(){                  /*  1000 - 2000  */
  type = 0;
  set_short("A young gurther");
  set_alias("young");
  set_gender("male");
  set_long(
"Standing before you is a somewhat younger gurther.  Balancing on his\n"+
"hind legs, his smooth black skin is glistening in the light.  His\n"+
"limbs are adorned with sharp claws that look somewhat oversized for\n"+
"him.  Rows of white teeth are visible in his mouth.  Two  small horns\n"+
"protrude from atop his narrow head.\n");
  load_chat("The young gurther sits silently.\n");
  load_chat("The young gurther claws at the dirt.\n");
  load_chat("The young gurther scratches his skin.\n");
  set_level(18);
  set_ac(13);
  set_wc(28);
  set_wc_bonus(1);
  set_hp(400);
  value = 1000 + random(1000);
}

hunter(){                /*  4000 - 6000  */
  type = 1;
  set_short("A gurther hunter");
  set_alias("hunter");
  set_gender("male");
  set_long(
"This is a full grown male gurther.  His shiny black skin is tainted by\n"+
"numerous deep scars.  Both his front and back legs are adorned with large\n"+
"claws.  His face is long and narrow and looks almost deathly.  Two large\n"+
"horns are protruding from atop his head, each extremely sharp.\n");
  load_chat("The gurther hunter glares at you.\n");
  load_chat("The gurther hunter looks very uneasy.\n");
  load_chat("The gurther hunter digs his claws into the ground.\n");
  load_chat("The gurther hunter rocks back on his hind legs.\n");
  set_level(20);
  set_ac(13);
  set_wc(46);
  set_wc_bonus(4);
  set_hp(500);
  value = 4000 + random(2000);
}

strong(){               /*  3500 - 6500 */
  type = 1;
  set_short("A strong gurther");
  set_alias("strong");
  set_gender("female");
  set_long(
"This is a very powerful female gurther.  She is haunched on her hind legs,\n"+
"sitting and resting in the forest.  Her shiny, flawless black skin is\n"+
"glistening in the sunlight.  Her narrow face is highlighted by her deep\n"+
"eye sockets and beautiful horns.  She is an incredibly strong creature.\n");
  load_chat("The strong gurther scratches her skin.\n");
  load_chat("The strong gurther glares at you.\n");
  load_chat("The strong gurther digs her claws into the ground.\n");
  load_chat("The strong gurther tilts her head to the side.\n");
  load_chat("The strong gurther makes a soft humming noise.\n");
  set_level(20);
  set_ac(20);
  set_wc(35);
  set_wc_bonus(4);
  set_hp(600);
  value = 3500 + random(3000);
}

female(){               /*  1000 - 2000  */
  type = 0;
  set_short("A young female gurther");
  set_alias("female");
  set_gender("female");
  set_long(
"This young female gurther has a certain dark beauty about her.  Her sharp\n"+
"claws are digging into the dirt as she sits on her hind legs.  Her flawless\n"+
"black skin is reflecting the sunlight and looks very mystical.  Two horns\n"+
"are protruding from atop her head, each one curving slightly forward.\n");
  load_chat("The young female gurther smiles.\n");
  load_chat("The young female gurther claws at the ground.\n");
  load_chat("The young female gurther listens carefully.\n");
  set_level(18);
  set_ac(11);
  set_wc(28);
  set_wc_bonus(1);
  set_hp(440);
  value = 1000 + random(1000);
}

guard(){				/*  3500 - 6000 */
  type = 1;
  set_short("A gurther guard");
  set_alias("guard");
  set_gender("male");
  set_long(
"This is a tough looking gurther guard.  His muscular body features multiple\n"+
"deep scars that would seem to prove that he has seem much action in his\n"+
"life.  His sharp teeth can be seen in his open mouth, each glistening with\n"+
"saliva.  He is truly a vicious craeture\n");
  load_chat("The gurther guard asks: What do you want?\n");
  load_chat("The gurther guard asks: Why are you here?\n");
  load_chat("The gurther guard glares at you.\n");
  load_chat("The gurther guard rocks back on his hind legs.\n");
  set_level(20);
  set_ac(14);
  set_wc(39);
  set_wc_bonus(4);
  set_hp(550);
  value = 3500 + random(2500);
}

worker(){				/*  2000 - 5000 */
  type = 0;
  set_short("A gurther worker");
  set_alias("worker");
  set_gender("male");
  set_long(
"This gurther spends most of his time working to help his fellow gurthers.\n"+
"He is rather strong looking, and has beautiful black skin.  His claws on\n"+
"his forearms are covered in dirt.  Looking into his eyes, you almost think\n"+
"that he is tired.  Two beautiful horns protrude from his head.\n");
  load_chat("The gurther worker looks rather tired.\n");
  load_chat("The gurther worker watches you.\n");
  load_chat("The gurther worker listens to the sounds of the forest.\n");
  set_level(19);
  set_ac(18);
  set_wc(33);
  set_wc_bonus(1);
  set_hp(500);
  value = 2000 + random(3000);
}


monster_died(){
  int random_msg;
  object horn;
  horn = clone_object("/players/zeus/realm/OBJ/ghorn.c");
  horn->set_value(value);
  random_msg = random(4);
  switch(random_msg){
  case 0:
    tell_room(environment(),
"As the gurther colapses to the ground, one of "TQP" horns breaks off...\n");
    break;
  case 1:
    tell_room(environment(),
"With your final blow you break off one of the gurther's horns...\n");
    break;
  case 2:
    tell_room(environment(),
"You hear a crack..  one of the gurther's horns falls next to "TQP" body..\n");
    break;
  case 3:
    tell_room(environment(),
"As the powerful gurther dies, one of "TQP" horns becomes detatched...\n");
    break;
  }
  move_object(horn, environment());
}


call_help(){
  if(!help) return 0;
  if(!present(attacker_ob, environment())) return 0;
  guard = clone_object("/players/zeus/realm/NPC/gguard.c");
  tell_room(environment(),
    "\nThe gurther screams out for help!\n"+
    "A guard runs into the room...\n\n");
  move_object(guard, environment());
  guard->attack_object(attacker_ob);
  help = 0;
}


attack_special(){
  int x;
  if(!present(attacker_ob, environment())) return 0;
  x = random(3);
  switch(x){
  case 0:
    if(type) break;
    tell_object(attacker_ob,
      "The gurther hits you with a crushing blow!\n");
    tell_room(environment(),
      "The gurther hits "OQN" with a crushing blow!\n", ({ attacker_ob }));
    attacker_ob->hit_player(random(20));
    break;
  case 1:
    if(!type) break;
    tell_object(attacker_ob,
      "The gurther "+RED+" slashes "+NORM+" you across the face!\n");
    tell_room(environment(),
      "The gurther "+RED+" slashes "+NORM+""OQN" across the face!\n",
      ({attacker_ob}));
    attacker_ob->hit_player(5+random(20));
    break;
  case 2:
    if(!type) break;
    tell_object(attacker_ob,
      "\nThe gurther impales you on "TQP" claws...\n"+
      RED+"\tBLOOD "+NORM+" gushes from your body...\n\n");
    tell_room(environment(),
      "\nThe gurther impales "OQN" on "TQP" claws...\n"+
      RED+"\tBLOOD "+NORM+" gushes from "OQN"'s body...\n\n",
      ({ attacker_ob }));
    attacker_ob->hit_player(15+random(5));
    break;
  }
}


wimpy(){
  string *dirs;
  string str;
  int x, rand;
  if(!present(attacker_ob, environment())) return;
  if(!environment()->query_dest_dir()) return;
  if(hit_point < (max_hp / 10))
  {
    tell_room(environment(), "\n");
    dirs = environment()->query_dest_dir();
    rand = random(sizeof(dirs)-1);
    x = rand / 2 * 2;
    str = dirs[x + 1];
    str += "#";
    str += dirs[x];
    this_object()->move_player(str);
  }
}


heart_beat(){
  ::heart_beat();
  if(!environment()) 
    return;
  if(!attacker_ob) 
    return;
  if(!random(10))
    attack_special();
  if(!random(5))
    wimpy();
  if(!random(TIME) && help && hit_point < 200)
    call_help();
}
