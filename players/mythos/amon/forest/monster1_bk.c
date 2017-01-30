/* this heap of code junk coded by mythos,
   totally rewritten by verte 2001 to support the std code that has
   been introduced since the old was created */

inherit "/obj/monster";

int wander;
int mult_at, mult_dam1, mult_chance, mult_dam2, mult_set;

int haunt_set;

int mass_dam, mass_chance;
string pet_cmd1, pet_cmd2;
int pet_command;
string mass_spell, haunt, owner;


void
reset(status arg)
{
  ::reset(arg);
    if(arg) return;
    mult_set = 0;
    haunt_set = 0;
    wander = 0;
}

void
tell_heap(object ob, string str)
{
    object x;
    x = first_inventory(ob);
    while(x)
    {
      tell_object(x, str);
      x = next_inventory(x);
    }
}

void
init()
{
    ::init();
    if(haunt_set)
    {
      if(find_call_out("haunting") == -1)
      call_out("haunting",5);
    }
    if(wander)
    {
      if(find_call_out("wandering") == -1)
      call_out("wandering",random(2000));
    }
   add_action("move_dir", "east");
   add_action("move_dir", "west");
   add_action("move_dir", "south");
   add_action("move_dir", "north");
   add_action("move_dir", "northeast");
   add_action("move_dir", "southwest");
   add_action("move_dir", "pass");
   add_action("move_dir", "around");
   add_action("move_dir", "southeast");
   add_action("move_dir", "enter");
   add_action("move_dir", "back");
}

void
heart_beat()
{
    int c;
    object e;

    ::heart_beat();

    if(!(e = environment())) return;

if(attacker_ob){
    if(mass_chance > random(100))
    {
      object laff;
      laff = first_inventory(e);
      tell_heap(e, mass_spell + "\n");
      if(attacker_ob)
        tell_object(attacker_ob, mass_spell + "\n");

      while(laff)
      {
        if(living(laff) && !laff->query_ghost() &&
      	(string)laff->query_name() != name)
                laff->hit_player(mass_dam, "magical");
        if(laff)
      	laff=next_inventory(laff);
      }
    }
}
  
    if(pet_command)
    {
    	object pets;
    	pets = first_inventory(e);
      if(attacker_ob)
        if((status)attacker_ob->query_npc())
        {
          say(pet_cmd1);
          attacker_ob->hit_player(100+random(100), "magical");
        }
      if(alt_attacker_ob)
        if((status)alt_attacker_ob->query_npc())
        {
          say(pet_cmd2);
          alt_attacker_ob->attack_object(attacker_ob);
          if(alt_attacker_ob)
            if((status)alt_attacker_ob->query_npc())
            {
              say(pet_cmd2);
              alt_attacker_ob->attack_object(attacker_ob);
   	      }
        }				
    	
      while(pets)
      {
        if((status)pets->query_npc())
          pets->attack_object(attacker_ob);
        pets = next_inventory(pets);
      }
    }

    if(attacker_ob && mult_set && present(attacker_ob, e))
    {
    	int x;
    	x=0;
    	if(!attacker_ob->query_ghost())
      {
    	  while(x<(mult_at -1))
        {
          if(mult_chance > random(100))
          {
            if(attacker_ob)
            if(!attacker_ob->query_ghost())
            {
              say(cap_name + " smashed " +
    ((string)attacker_ob->query_name()?(capitalize((string)attacker_ob->query_name())):"it")+
              " with a bone crushing sound.\n");  
              attacker_ob->hit_player(mult_dam1 + random(mult_dam2));
            }
          } 
          else 
            say(cap_name + " missed " + capitalize((string)attacker_ob->query_name()) + ".\n");
           
          x++;
        }
      }
    }
}

set_mass_dam(mn)
{
    mass_dam = mn;
}

set_mass_chance(mc)
{
	mass_chance= mc; }
	
set_mass_spell(ms) {
	mass_spell = ms; }

set_pet_command() {
	pet_command = 1; }
set_pet_cmd1(str) {  pet_cmd1 = str; }
set_pet_cmd2(str) {  pet_cmd2 = str;}

set_mult(ma) {  mult_at = ma; mult_set = 1;}
set_mult_dam1(md) { mult_dam1 = md;}
set_mult_dam2(mdd) { mult_dam2 = mdd;}
set_mult_chance(mc) { mult_chance = mc; }
set_haunt(hs) { haunt=hs; haunt_set=1;}
set_wander() { wander = 1;}

haunting()
{
    object pest;
    pest=find_player(lower_case(haunt));
    if(!pest) { destruct(this_object()); return 1; }
    if(pest->query_ghost() || !pest || !(pest->query_interactive())) {
      destruct(this_object());
      return 1;}
    if(!present(pest->query_real_name(),environment(this_object()))) {
      if(environment(pest) && !environment(pest)->query_no_fight())
        move_object(this_object(),environment(pest)); }
    if(!( this_object()->query_attack()) || kill_ob != pest) {
      kill_ob = pest; }
    call_out("haunting",5);
    return 1;
} 

wandering()
{
    if(this_object())
    run_away();
    call_out("wandering", 1 + random(5000));
    return 1;
}

set_owner(str) { owner=str;}
query_owner() {return owner;}

status calced;

int
calculate_worth()
{
    int exp_worth, bon;
/* This line results in the monster's original worth being counted
   twice.  - illarion 2 dec 2004
    exp_worth = (int)::calculate_worth();
*/
    if(haunt_set) exp_worth += 3333;
    if(pet_command) exp_worth += 6666;
    if(mass_chance > 0) bon += (((2 * mass_dam) * (mass_chance) / 100) / 3);
    if(mult_set) 
     bon += (mult_at * ((mult_dam1 + mult_dam2) * mult_chance) / 100);

    if(!calced)
    {
      wc_bonus += bon;
      calced = 1;
    }

    exp_worth = (exp_worth + (int)::calculate_worth());
    if(heal_rate < 1 || heal_intv > 700) exp_worth /= 2;
/* lib changes render this line more or less meaningless - ill    
    if(armor_class < 1 || weapon_class < 4) exp_worth /= 2;
*/
    return exp_worth;
}

int move_dir() {
  if(attacker_ob && random(10)) {
    write("You are FROZEN with FEAR!\n");
    this_player()->hit_player(10+random(10), "other|evil");
    return 1;
  }
  return 0;
}
