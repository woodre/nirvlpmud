/* new pet object.. incorporates old pet ideas and kid ideas */

#include "/players/wocket/closed/ansi.h"
#define tpn this_player()->query_name()
inherit "obj/monster.c";

int assist;
int stay;
string type;
string mastername;
static object whoob,whatob;
static string who,what; 
object masterob;

short(){
  return "A pet "+type+" named "+cap_name;
}

id(str){
  return (str == type || str == name || str == "pet" || str == "neopet") ;
}

add_weight(){
write(cap_name+" can only carry delivers in his mouth.\n");
return 0; }

reset(arg){
if(arg) return;
::reset();  
  set_hp(50);
  set_wc(3);
  set_ac(0);
  set_alias("neopet");
  set_heart_beat(1);
  heal_intv = 10;
  heal_rate = 1;
  assist = 5;
  name = "pet";
  cap_name = "Pet";
  set_chat_chance(5);
  set_dead_ob(this_object());
  set_can_kill(1);
message_hit = ({
         "hit"," hard",
         "hit","",
     HIR+"BITES"+OFF," as "+HIR+"BLOOD"+OFF+" flows everywhere"+OFF,
     HIR+"bites"+OFF,HIR+" very hard"+OFF,
     HIR+"bites"+OFF,HIR+" hard"+OFF,
     HIR+"bites"+OFF," lightly",
     HIR+"scrapes"+OFF," with his teeth",
});
}

long(){
string msg;
  if(mastername){
    write("This is "+capitalize(mastername)+"'s pet "+type+".\n");
    if(long_desc) write(long_desc);
    msg = cap_name + " is in good shape.\n";
    if (hit_point < max_hp - 20) {
        msg = cap_name + " is slightly hurt.\n";
    }
    if (hit_point < max_hp/2) {
      msg = cap_name + " is somewhat hurt.\n";
    }
    if (hit_point < max_hp/5) {
      msg = cap_name + " is in bad shape.\n";
    }
    if(hit_point < max_hp/10){
      msg = cap_name + " is in very bad shape.\n";
    }
    write(msg);
    if(this_player() == masterob){
    if(weapon_class == 18 && armor_class == 7 && max_hp == 175 && assist == 50 && heal_rate == 10)
    write(cap_name+" looks as well trained as it may ever be.\n"+OFF);
    write("You may: \n"+HIR+"    name_pet, describe_pet, train_pet, pet_heel,\n"+
                            "    stay, sic, feed_pet, deliver, pet_drop\n"+OFF); 
    }
  }
  else{
    write("This object should not be cloned with out a masterob!\nPlease report to Wocket.\n");
  }
}

init(){
  ::init();
  add_action("petme","pet");
  if(mastername){
    if(!masterob){
      masterob = find_player(mastername);
    }
    if(this_player() && this_player() == masterob && !this_player()->query_ghost()) { /* query_ghost() check 6.24.01 by verte */
      add_action("name_pet","name_pet");
      add_action("describe_pet","describe_pet");
      add_action("train_pet","train_pet");
      add_action("pet_stay","stay");
      add_action("pet_call","pet_heel");
      add_action("sic","sic");
      add_action("feed_pet","feed_pet");
      add_action("deliver","deliver");
      add_action("pet_drop","pet_drop");
      if(present("no_pet",this_player())){
        tell_object(this_player(),"Your pet takes one look at you and has a heart attack.\n");
        death();
      }
    }
    jealous_check(this_player());
  }
}

name_pet(str){
string *p;
string file;
  if(!str){
    notify_fail("What would you like to name your pet?\n");
    return 0;
  }
  str = lower_case(str);
  p = explode(str,"");
  file = "pfiles/"+p[0]+"/"+str;
  if("/players/wocket/turtleville/PETS/playercheck.c"->playercheck(file)){
   notify_fail("Because of possible abuse you are not allowed to name yourself after a player.\n");
  return 0;
  }
  set_short("A "+type+" named "+capitalize(str));
  long_desc = "A "+type+" named "+capitalize(str)+".\n";
  name = str;
  cap_name = capitalize(str);
  write("You have named your pet: "+str+"\n");
  set_type(type);
  save_me();
  return 1;
}

describe_pet(){
  write("Enter description for your pet.  End with '"+CYN+"**"+OFF+"'.\n"+CYN+"] "+OFF);
  long_desc = "";
  input_to("get_describe");
  return 1;
}

get_describe(str){
  if(str == "**"){
    write("Description written.\n");
    return 1;
  }
  long_desc += str+"\n";
  write(CYN+"] "+OFF);
  input_to("get_describe");
  return 1;
}

train_pet(){
string extraexp,cost; 
  cost = 10000+random(10000);
  if(this_player()->query_extra_level()< 1)
    extraexp = this_player()->query_exp() -
      "room/adv_guild"->get_next_exp(this_player()->query_level()-1);
  else
    extraexp = this_player()->query_exp() - 
      "room/exlv_guild"->get_next_exp(this_player()->query_extra_level()-1);
  if(extraexp < cost){
    notify_fail("You lack the experience to train your pet right now.\n");
    return 0;
  }
switch(random(5)){
case 0:  if(weapon_class < 18){
           weapon_class++;
           break; }
case 1:  if(armor_class < 7){
           armor_class++;
            set_ac(armor_class);
           break; }
case 2:  if(max_hp < 175){
           max_hp = max_hp+random(25);
           if(max_hp > 175) max_hp = 175;
           break; }
case 3:  if(assist < 50){
           assist++;
           break; }
case 4:  if(heal_rate < 10){
           heal_rate++;
           break; }
}
this_player()->add_exp(-cost);
write_file("/players/wocket/closed/log/PETS",this_player()->query_real_name()+
           "- wc:"+weapon_class+" ac:"+armor_class+" maxhp:"+max_hp+
           " assist:"+assist+" heal_rate:"+heal_rate+" cost:"+cost+"\n");
/* an addition just for the Healers... how pathetic */
this_player()->add_xp(-cost);
write("You sit down and train your "+type+".\n");
if(weapon_class == 18 && armor_class == 7 && max_hp == 175 && assist == 50 && heal_rate == 10)
    write(cap_name+" looks as well trained as it may ever be.\n"+OFF);
save_me();
return 1;
}

pet_stay(){
  write("You say: STAY!\n");
  say(tpn+" says: STAY!\n",this_player());
  if(query_attack()){
    write("Your pet ignores you.\n");
    return 1;
  }
  stay = 1;
  write("Your pet follows your commands and stays.\n");
  return 1;
}

pet_call(){
  write("You say: HERE BOY!\n");
  say(tpn+" says: HERE BOY!\n",this_player());
  stay = 0;
  write("Your pet nuzzles up to your heel ready to serve you.\n");
  say(cap_name+" moves up beside "+this_player()->query_name()+".\n");
  set_heart_beat(1);
  return 1;
}

sic(str){
object ob; 
  if(!str){
    notify_fail("Who do you want your pet to sic?\n");
    return 0;
  }
  ob = present(str,environment(this_object()));
  write("You say: SIC 'EM!\n");
  say(tpn+" says: SIC 'EM!\n",this_player());
  if(!ob){
    notify_fail("Your pet looks confused.\n");
    return 0;
  }
  if(!ob->is_npc() || (ob == this_object()) ){
    notify_fail("Your pet won't attack that.\n");
    return 0;
  }
  if(random(40) < assist){
    say(BOLD+cap_name+" leaps to attack "+ob->query_name()+".\n"+OFF);
    this_object()->attack_object(ob);
    return 1;
  }
    notify_fail("Your pet ignores you.\n");
    return 0;
}

feed_pet(){
object ob;
  ob = present("corpse",environment(this_object()));
  if(!ob){
    notify_fail("Your pet looks around but doesn't find a corpse.\n");
    return 0;
  }
  if(random(30) > assist){
    notify_fail("Your pet ignores you.\n");
    say(cap_name+" chases its tail.\n");
    return 0;
  }
  say(cap_name+" devours the corpse.\n");
  hit_point += ob->heal_value();
  if(hit_point > max_hp) hit_point = max_hp;
  destruct(ob);
  return 1;
}

deliver(str){
 if(!str){
    notify_fail("What would you like to deliver?\n");
    return 0;
  }
  if(sscanf(str,"%s to %s",what,who) != 2){
    notify_fail("Your pet looks confused.\nUsage: deliver <what> to <who>\n");
    return 0;
  }
  whoob = find_player(who);
  whatob = present(what,this_player());
  write("You say: DELIVER THIS!\n");
  say(this_player()->query_name()+" says: DELIVER THIS!\n", this_player());
  if(random(30) > assist){
    notify_fail("You pet ignores you.\n");
    say(cap_name+" chases its tail.\n"); 
    return 0;
  }
  if(!whatob){
    notify_fail("Your pet looks confused.\nYou do not have that to have delivered.\n");
    return 0;
   }
  if(whatob->drop() || !whatob->query_weight() || whatob->query_auto_load() || !whatob->get()){
    notify_fail("You may not have that delivered.\n");
    return 0;
  }
  if(!whoob || whoob->query_invis()){
    notify_fail("Your pet can not locate that person.\n");
    return 0;
  }
  if((environment(this_player())->realm() == "NT") || (environment(whoob)->realm("NT"))){
    notify_fail("The trip is to dangerous for the pet to make.\n");
    return 0;
  }
  move_object(whatob,this_object());
  say(cap_name+" leaves to deliver "+what+" to "+who+".\n");
  move_object(this_object(),"/players/wocket/turtleville/pet_waiting_room.c"); 
  stay = 1;
  call_out("second_move",10);
  return 1;
}

second_move(){
 if(environment(whoob)->realm() == "NT"){
  tell_object(masterob,"Your pet got lost along the way.\n");
  move_object(whatob,masterob);
 }
 else{
  move_object(this_object(),environment(whoob));
  say(cap_name+" arrives.\n");
  say(cap_name+" drops "+what+".\n");
  move_object(whatob,environment(this_object()));
 }
  call_out("third_move",10);
}

third_move(){
  stay = 0;
  set_heart_beat(1);
}

pet_drop(str){
object ob;
  if(!str){
    notify_fail("What would you like your pet to drop?\n");
    return 0;
  }
  write("You say: DROP IT!\n");
  say(this_player()->query_name()+" says: DROP IT!\n");
  ob = present(str,this_object());
  if(!ob){
    notify_fail("Your pet does not have that.\n");
    return 0;
  }
  move_object(ob,environment(this_object()));
  say(cap_name+" drops "+str+".\n");
  return 1;
}

heart_beat(){
object ob;
object tempob;
::heart_beat();
if(masterob && stay != 1 && !masterob->query_ghost()){ /* query_ghost() check by verte 6.24.01 */
  if(environment(this_object()) != environment(masterob)){
    say(cap_name+" leaves after "+masterob->query_name()+".\n");
    move_object(this_object(),environment(masterob));
    say(cap_name+" arrives following "+masterob->query_name()+".\n");
    set_heart_beat(1);
  }
  if(masterob->query_attack() && !attacker_ob && !masterob->query_attack()->is_player()){
    if(random(50) < assist && hit_point > max_hp/4){
      say(BOLD+cap_name+" leaps to assist "+capitalize(mastername)+".\n"+OFF);
      attacker_ob = masterob->query_attack();  
    }
  }
  if(query_attack()){
    tell_object(masterob,"Pet: "+CYN+(hit_point*10/max_hp)+"/10\n"+OFF);
    if(hit_point < max_hp/4){
    if(query_attack() && query_attack()->query_attack()==this_object()) {
      query_attack()->stop_fight();
      query_attack()->stop_fight();	
 }
      stop_fight();
      stop_fight();
      say(HIR+cap_name+" runs and hides behind a rock to escape the fight.\n"+OFF);
    }
  }
  if(!query_attack() && !random(50) && environment()){
	emoteme();
  }
}
}

monster_died(){
 object c;
  switch(random(5)){
    case 0: if(max_hp > 30){
            max_hp = max_hp-random(25);
            if(max_hp < 25){ max_hp = 25; } 
            break; }
    case 1: if(assist > 5){ assist--; break; }
    case 2: if(heal_rate > 1){ heal_rate--; break; }
    case 3: if(weapon_class > 3){ weapon_class--; break; }
    case 4: if(armor_class > 0){ armor_class --; break; } 
  }
  heal_start = 0;
  save_me();
  say(HIR+cap_name+" screams in agony as he perishes.\n"+OFF);
  "/players/wocket/turtleville/tville_kennel.c"->remove_pets(masterob->query_real_name());
  "/players/wocket/turtleville/tville_kennel.c"->add_died(masterob->query_real_name());
  return 1;
  c = present("corpse",environment());
  if(c){
   set_prot_attribute("neopet_corpse", c);
  }
}

/*
monster_died(){
  max_hp = max_hp-random(25);
  if(max_hp < 25) max_hp = 25;
  assist--;
  if(assist < 5) assist = 5; 
  heal_rate--;
  if(heal_rate <1) heal_rate = 1;
  weapon_class--;
  if(weapon_class <3) weapon_class = 3;
  armor_class--;
  if(armor_class < 0) armor_class = 0;
  heal_start = 0;
  save_me();
  say(HIR+cap_name+" screams in agony as he perishes.\n"+OFF);
  return 1;
}
*/

save_me(){
  if(weapon_class > 18) weapon_class = 18;
  if(armor_class > 7) armor_class = 7;
  if(max_hp > 175) max_hp = 175;
  if(assist > 50) assist = 50;
  if(heal_rate > 10) heal_rate = 10;
  save_object("players/wocket/turtleville/PETS/saves/"+mastername);
}

is_pet(){
  if( (hit_point > 130)  || (weapon_class > 12) || (armor_class > 4))
    return 1;
  return 0;
}

is_neopet(){
  return 1;
}

/*
// [2005.06.21] Forbin
//  -added maximum checks/sets in set_master
*/
set_master(str){
  mastername = str;
  masterob = find_player(str);
  if(!restore_object("players/wocket/turtleville/PETS/saves/"+masterob->query_real_name())){
    set_call_outs();
    save_object("players/wocket/turtleville/PETS/saves/"+masterob->query_real_name());
  }
  if(weapon_class > 18) weapon_class = 18;
  if(armor_class > 7) armor_class = 7;
  if(max_hp > 175) max_hp = 175;
  if(assist > 50) assist = 50;
  if(heal_rate > 10) heal_rate = 10;
  set_ac(armor_class);
  heal_start = 0;
  set_heart_beat(1);
}

query_masterob(){ return masterob; }
query_master(){ return masterob; }
query_owner(){ return masterob; }

set_type(str){
  type = str; 
}

set_call_outs(){
string MPET;
MPET = capitalize(mastername)+"'s pet";
switch(type){
 case "dog":     load_chat(MPET+" barks.\n");
                 break;
 case "cat":     load_chat(MPET+" meows.\n");
                 break;
 case "bird":    load_chat(MPET+" squaks.\n");
                 break;
 case "snake":   load_chat(MPET+" hisses.\n");
                 break;
 case "turtle":  load_chat(MPET+" snaps at nothing.\n");
                 break;
 case "rat":      load_chat(MPET+" twitches his nose.\n");
		 break;
}
set_chat_chance(5);
}

jealous_check(ob){
  if(masterob){ 
    if( ob && ( (ob->query_master() == masterob) || (ob->query_owner() == masterob) ) ){
      if(random(3)==1){
        say(BOLD+cap_name+" flies into a jealous rage.\n"+OFF);
        this_object()->attack_object(ob);
      }
      else{
        say(BOLD+cap_name+" runs away, confused and bewildered.\n"+OFF);
        run_away();
        run_away();
        set_heart_beat(0);
        stay = 1;
      }
    }
  }
}
/* EMOTES */

petme(str){
  if(!str){
    notify_fail("What would you like to pet?\n");
    return 0;
  }
  if(id(str)){
    write("You pet "+cap_name+" as he rubs up against you.\n");
    say(this_player()->query_name()+" pets "+cap_name+" as he rubs up against "+this_player()->query_objective()+".\n",this_player());
    return 1;
  }
}


/* PET SPECIFIC EMOTES */
emoteme(){
	switch(type){
	case "cat": catmote();
		break;
	case "dog": dogmote();
		break;
	case "bird": birdmote();
		break;
	case "snake": snakemote();
		break;
	case "turtle": turtlemote();
		break;
	case "rat":  ratmote();
		break;
	}
}

catmote(){
string msg;
	switch(random(30)){
		case 0..10: msg = cap_name+" purrs loudly.\n";
			    break;
		case 11..20: msg = cap_name+" licks himself clean.\n";
			    break;
		case 21..28: msg = cap_name+" flicks his tail back and forth.\n";
		            break;
		case 29: msg = cap_name+" hacks up a fur ball.\n";
			    break;
	}
	tell_room(environment(this_object()),msg);
}

dogmote(){
string msg;
	switch(random(30)){
		case 0..10: msg = cap_name+" barks loudly.\n";
			  break;
		case 11..20: msg = cap_name+" pants loudly.\n";
			  break;
		case 21..28: msg = cap_name+" wags his tail back and forth.\n";
			  break;
		case 29: msg = cap_name+" sits.\n";
			  break;
	}
	tell_room(environment(this_object()),msg);
}
birdmote(){
string msg;
	switch(random(30)){
		case 0..10: msg = cap_name+" quickly chirps.\n";
			  break;
		case 11..20: msg = cap_name+" quickly looks from side to side.\n";
			  break;
		case 21..28: msg = cap_name+" pecks at the ground.\n";
			  break;
		case 29: msg = cap_name+" flutters his wings and tail feathers.\n";
			  break;
	}
	tell_room(environment(this_object()),msg);
}

snakemote(){
string msg;
	switch(random(30)){
		case 0..10: msg = cap_name+" hisses strongly.\n";
			  break;
		case 11..20: msg = cap_name+" slithers around in a circle.\n";
			  break;
		case 21..28: msg = cap_name+" flicks his tongue to smell the air.\n";
			  break;
		case 29: msg = cap_name+" strikes out at nothingness.\n";
			  break;
	}
	tell_room(environment(this_object()),msg);
}

turtlemote(){
string msg;
	switch(random(30)){
		case 0..10: msg = cap_name+" blinks.\n";
			  break;
		case 11..20: msg = cap_name+" flips off of his back.\n";
			  break;
		case 21..28: msg = cap_name+" hides back into his shell.\n";
			  break;
		case 29: msg = cap_name+" makes little turtle noises.\n";
			  break;
	}
	tell_room(environment(this_object()),msg);
}
ratmote(){
string msg;
	switch(random(30)){
         case 0..10: msg = cap_name+" twitches his whiskers.\n";
			  break;
		case 11..20: msg = cap_name+" searches for crumbs.\n";
			  break;
		case 21..28: msg = cap_name+" scurries about.\n";
			  break;
		case 29: msg = cap_name+" gnaws on some cheese impatiently\n";
			  break;
	}
	tell_room(environment(this_object()),msg);
}

/* 
//[2005.06.21] Forbin 
//  -modified set_wc() block so Fallen's empower spell works with wocket pets
//
// set_wc() { return; }
*/
void set_wc(int x)
{ 
	if(previous_object()->id("ruby_red_gem_damn"))
	  weapon_class = x;
	else 
	  return; 
}
