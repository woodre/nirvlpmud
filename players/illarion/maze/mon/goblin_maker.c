/*
 *      File:                   goblin_maker.c
 *      Function:               daemon to create goblins
 *      Author(s):              Illarion@Nirvana
 *      Created:                9 Nov 2004
 *      Notes:                  
 *
 *      Change History:
 */

#include "/players/illarion/dfns.h"

/* Prototypes */
object make_goblin(int lev, int floor);
string generate_type(int lev);
void add_spells(object goblin, string type, int floor);

/* varies what by +/- by %
*/
int random_vary(int what, int by) {
  int vary;
  vary= 2*what*by/100;
  return what + vary/2 - random(vary+1);
}

int wc_guide(int level) {
  return 25 + random(level);
}
int ac_guide(int level) {
  return 15 + random(level);
}
int hp_guide(int level) {
  return 400 + 50 * random(level);
}
int gold_guide(int level, int floor) {
  int worth;
  worth = level * 1000 + floor * 750; 
  return random(worth / 2 + random(worth/2));
}

/* 
 * Function name: make_goblin
 * Description: creates a goblin
 * Arguments: the current level of the maze
 * Returns: the created goblin object
 */
 
object make_goblin(int lev, int floor) {
	object goblin;
	string type;

  floor *= 4;
  	
  lev = lev / 2 + random(lev);
  
	if(lev<1)
	  lev=1;

  
	if(lev>20)
	  lev=20;
	  
	goblin=clone_object("/obj/monster");
	goblin->set_level(lev);
	goblin->set_race("goblin");
	type=generate_type(lev);
  add_spells(goblin, type, floor);
	goblin->set_name("goblin "+type);
  goblin->set_alias(type);
	goblin->set_alignment(-100);
	goblin->set_gender(({"male","female"})[random(2)]);
	goblin->set_short("A goblin "+type);
	goblin->set_wc(floor+random_vary(wc_guide(lev),20));
	goblin->set_ac(floor+random_vary(ac_guide(lev),20));
	goblin->set_hp((floor*50)+random_vary(hp_guide(lev),20));
  goblin->add_money(gold_guide(lev, floor));
	goblin->set_long(
  "Nasty, brutish, short, green, and filthy, goblins will move in and fill\n"+
  "nearly every space left by other creatures, no matter how uninviting.\n"+
  "Most goblins are relatively harmless, but every once in a while one will\n"+
  "be born with enough potential and live long enough to become really\n"+
  "dangerous.\n");
	return goblin;
}

string generate_type(int lev) {
  switch(lev) {
    case 1..5:
      return ({"schmuck","runt","peon"})[random(3)];
    case 6..10:
      return ({"worker","miner","hunter"})[random(3)];
    case 11..15:
      return ({"fighter","rogue","archer"})[random(3)];
    case 16..17:
      return ({"shaman","champion"})[random(2)];
    case 18..19:
      return "chief";
    case 20:
      return "baron";
  }
}

add_spells(object goblin, string type, int floor) {
  switch(type)
  {
    case "fighter":
      goblin->add_spell("bash",
      "#MN# bashes you with #MP# shield!\n",
      "#MN# bashes #TN# with #MP# shield!\n",
      30, "2d6+"+floor);
    break;
    case "rogue":
      goblin->add_spell("bash",
      "#MN# somehow manages to sneak around and backstab you!\n",
      "#MN# somehow manages to sneak around and backstab #TN#!\n",
      20, "3d6+"+floor);
    break;
    case "archer":
      goblin->add_spell("multi",
      "#MN# shoots several arrows at you!\n",
      "#MN# shoots several arrows at #TN#!\n",
      25, "2d8+"+floor);    
    break;
    case "shaman":
      goblin->add_spell("fireball",
      "#MN# casts a fireball spell on you!\n",
      "#MN# casts a fireball spell on #TN#!\n",
      15, "4d4+"+floor, "other|fire");    
      goblin->add_spell("magic missile",
      "#MN# casts a magic missile spell on you!\n",
      "#MN# casts a magic missile spell on #TN#!\n",
      15, "8d4+"+floor, "magical");    
      goblin->add_spell("ice arrow",
      "#MN# casts an ice arrow spell on you!\n",
      "#MN# casts an ice arrow spell on #TN#!\n",
      15, "3d6+"+floor, "other|ice");       
      goblin->add_spell("summon",
      "#MN# calls for help!\n",
      "#MN# calls for help!\n",
      10, 0, 0, 0, "summon_help", this_object());
      goblin->set_wc_bonus(3);      
    break;
    case "champion":
      goblin->add_spell("bash",
      "#MN# bashes you with #MP# spiked shield!\n",
      "#MN# bashes #TN# with #MP# spiked shield!\n",
      20, "4d6+"+floor);
      goblin->add_spell("backhand",
      "#MN# backhands you across the face!\n",
      "#MN# backhands #TN# across the face!\n",
      20, "4d6+"+floor);
      goblin->add_spell("summon",
      "#MN# calls for help!\n",
      "#MN# calls for help!\n",
      10, 0, 0, 0, "summon_help", this_object());
      goblin->set_wc_bonus(3);
    break;
    case "chief":
      goblin->add_spell("punch",
      "#MN# punches you in the face with #MP# spiked gauntlet!\n",
      "#MN# punches #TN# in the face with #MP# spiked gauntlet!\n",
      20, "6d6+"+floor);    
      goblin->add_spell("summon",
      "#MN# calls for help!\n",
      "#MN# calls for help!\n",
      10, 0, 0, 0, "summon_help", this_object());    
      goblin->set_wc_bonus(3);
    break;
    case "baron":
      goblin->add_spell("kick",
      "#MN# kicks you into the wall!\n",
      "#MN# kicks #TN# into the wall!\n",
      20, "10d8+"+floor);    
      goblin->add_spell("summon",
      "#MN# calls for help!\n",
      "#MN# calls for help!\n",
      10, 0, 0, 0, "summon_help", this_object());    
      goblin->set_wc_bonus(3);
    break;
  }


}

summon_help(victim, room)
{
  int amt, level, x;
  object gob;
  if(!present(victim, room)) return;
  amt = 1+random(2)+random(2)+random(2);
  for(x=0; x< amt; x++) {
    level = 1+random(3)+random(3)+random(3);
    gob = make_goblin(level);
    move_object(gob, room);
    tell_object(victim, gob->query_name()+" scrambles into the room and attacks you!\n");
    tell_room(room, gob->query_name()+" scrambles into the room and attacks "+victim->query_name()+"!\n");
    gob->attack_object(victim);
  }
}