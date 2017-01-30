#include "/players/maledicta/ansi.h"
#include "/players/cosmo/guild/sigil/sigil.h"
#define USER environment(previous_object())
#define level USER->query_level()
#define extralevel USER->query_extra_level()
#define AT USER->query_attack()
#define AAT USER->query_alt_attack()

query_pmess() {
int plvl;
  plvl = previous_object()->query_plevel();
  if(level < 10){
    if(plvl < 4) return "low";
    else if(plvl < 7) return "medium";
    else if(plvl < 11) return "high";
    else return "error";
  }
  else if(level < 15){
    if(plvl < 6) return "low";
    else if(plvl < 11) return "medium";
    else if(plvl < 16) return "high";
    else return "error";
  }
  else if(extralevel < 5){
    if(plvl < 8) return "low";
    else if(plvl < 15) return "medium";
    else if(plvl < 21) return "high";
    else return "error";
  }
  else if(extralevel > 4){
    if(plvl < 9) return "low";
    else if(plvl < 18) return "medium";
    else if(plvl < 21) return "high";
    else if(plvl > 20) return "overload";
    else return "error";
  }
  else return "error";
}

power_set(str){
int plvl;
mapping map;

  if(level < 5){
    write("You are not high enough level to invoke the sigil!\n");
    return 0;
  }
  plvl = previous_object()->query_plevel();
  map = map_check();
  if(!str){
    write("You have the following power levels available:\n\n"+
      "\t  low\n"+"\t  medium\n"+"\t  high\n");
    if(extralevel > 4)
      write("\t  "+map["color"]+"OVERLOAD"+NORM+"\n");
    write("set_power <type> to change the setting.\n");           
    return plvl;
  }
  if(str == "low"){
    if(level < 10) plvl = 3;
    else if(level < 15) plvl = 5;
    else if(extralevel < 5) plvl = 7;
    else plvl = 8;
    write("Power level set to "+map["color"]+"Low"+NORM+".\n");
    return plvl;
  }
  if(str == "medium"){
    if(level < 10) plvl = 6;
    else if(level < 15) plvl = 10;
    else if(extralevel < 5) plvl = 14;
    else plvl = 17;
    write("Power level set to "+map["color"]+"Medium"+NORM+".\n");
    return plvl;
  }
  if(str == "high"){
    if(level < 10) plvl = 10;
    else if(level < 15) plvl = 15;
    else if(extralevel < 5) plvl = 20;
    else plvl = 20;
    write("Power level set to "+map["color"]+"High"+NORM+".\n");
    return plvl;
  }
  if(str == "overload" || str == "OVERLOAD"){
    if(extralevel < 5){
      write("Type: set_power with no arguments for a listing of settings.\n");
      return plvl;
    }
    plvl = 25;
    write("Power level set to "+map["color"]+"OVERLOAD"+NORM+".\n");
    return plvl;
  }
  write("Type: set_power with no arguments for a listing of settings.\n");
  return plvl;
}

new_sc(){
  if(level < 20){
    USER->score();
    write(
      " I ["+(USER->query_intoxination()*100)/(level+3)+"%] "+
      " F ["+(USER->query_stuffed()*100)/(level*8)+"%] "+
      " S ["+(USER->query_soaked()*100)/(level*8)+"%]\n"); 
    if(USER->query_fight_area())
      write(" Fight Zone: "+HIR+"PK Area"+NORM+"   ");
    else write(" Fight Zone: "+BOLD+"NON-PK Area"+NORM+"  ");
    if(environment(USER)->realm() == "NT")
      write(" Room Port: "+BOLD+"Non-Port"+NORM+"\n");
    else write(" Room Port: "+BOLD+"Port"+NORM+"\n");
    return 1;
  }
  return;
}

ditch_it(){
string place;
  place = previous_object()->query_location();
  write("You feel a burning sensation on your "+place+"...\n"+
        "The Sigil fades away.\n");
  destruct(previous_object());
  return 1;
}

/********
 Main attack: equivalent of game spells. Against npc type can get a bonus
 of random(10) damage if willpower > random(500)
*********/
invoke_spell(str) {
object target;
int plvl, damage, rcrit, rcrit2;
string sm1, sm2, msg, msg2, msg3;
string place;
mapping map;
        
  if(USER->query_ghost()) return 0;
  if(USER->query_spell_dam()) return 0;
  if(level < 5){
    write("You are not high enough level to use this power.\n");
    return 0;
  }
  if(!str && !AT) {
    write("You are not in combat.\n");
    return 0;
  }
  else if(!str && AT) target = AT;
  else target = present(str, environment(USER));
  if(!target){
    write("You don't see "+str+" here.\n");
    return 0;
  }
  if(!living(target)){
    write("You cannot attack "+str+"!\n");
    return 0;
  }
  plvl = previous_object()->query_plevel();
  if(USER->query_sp() < plvl){
    write("Your magical energies are too weak for that.\n");
    return 0;
  }
  if(plvl < 21) damage = random(plvl*2);
  else damage = random(34) + 12;
  sm1 = query_dam1_msg(damage);
  sm2 = query_dam2_msg("i");
  place = previous_object()->query_location();
  write("You invoke the power of the sigil on your "+place+"...\n");
  tell_room(environment(USER),
    USER->query_name()+"'s "+place+" begins to glow...\n", ({USER}));
  rcrit = random(500);
  rcrit2 = rcrit;

  /************* Critical hit or miscast **************************/
  if(USER->query_attrib("wil") > rcrit2){
    write("]"+BOLD+"CRITICAL"+NORM+"[ ");
    damage += random(10);
  }
  else if(rcrit2 > (470 + USER->query_attrib("wil"))){
    write("]"+BOLD+"MISCAST"+NORM+"[ ");
    if(damage > 10){
      damage -= random(10);
      sm1 = "grazed";
    }
    else{
      sm1 = "grazed";
      damage = 1;
    }
  }
  /****************************************************************/

  write("You "+sm1+" "+target->query_name()+" with "+sm2+".\n");
  tell_room(environment(USER),
     USER->query_name()+" "+sm1+" "+target->query_name()+" with "+sm2+".\n", ({USER}));
  msg = "";
  msg2 = "";
  msg3 = "";
  map = map_check();
  USER->spell_object(target, map["iname"], damage, plvl, msg, msg2, msg3);
  return 1;
}

/******* Cone attack: Splits damage between attacker and alt attacker ****/
cone_att() {
object target;
int damage, damage2; 
string sm1, sm2, sm3, sm4;
string msg, msg2, msg3;
int plvl;
string place;
mapping map;

  if(USER->query_ghost()) return 0;
  if(USER->query_spell_dam()) return 0;
  if(USER->query_extra_level() < 14) {
    write("You are not high enough level to use this power.\n");
    return 0;
  }
  if(!AT){
    write("You can only use this while in combat!\n");
    return 0;
  }
  plvl = previous_object()->query_plevel();
  if(USER->query_sp() < plvl + 10){
    write("Your magical energies are too weak for that.\n");
    return 0;
  }
  damage = random(plvl); 
  damage2 = random(plvl);
  sm1 = query_dam1_msg(damage);
  sm3 = query_dam1_msg(damage2);
  sm2 = query_dam2_msg("c");
  sm4 = query_dam2_msg("c");
  place = previous_object()->query_location();
  write(BOLD+"You invoke the power of the sigil on your "+place+"..."+NORM+"\n\n");
  map = map_check();
  write(map["cone1"]+"\n");
  tell_room(environment(USER),
     USER->query_name()+"'s "+place+" begins to "+map["color"]+"glow"+NORM+"...\n"+
     map["cone2"]+USER->query_name()+"!\n", ({USER}));
  write("You "+sm1+" "+AT->query_name()+" with a "+sm2+".\n");
  if(AAT && AAT != AT)
    write("You "+sm3+" "+AAT->query_name()+" with a "+sm4+".\n");
  tell_room(environment(USER),
     USER->query_name()+" "+sm1+" "+AT->query_name()+" with a "+sm2+".\n", ({USER}));
  if(AAT && AAT != AT)
    tell_room(environment(USER),
       USER->query_name()+" "+sm2+" "+AAT->query_name()+" with a "+sm4+".\n", ({USER}));
  if(AAT && AAT != AT)
    AAT->hit_player(damage2);
  msg = "";
  msg2 = "";
  msg3 = "";
  if(AT)
    USER->spell_object(AT, map["cname"], damage, (plvl + 10), msg, msg2, msg3);
  return 1;
}

/********** Keep guilded from using the sigil **************/
guild_check(){
  if(USER->query_level() > 19) return 0;
  if(USER->query_guild_name() && USER->query_guild_name() != 0){ return 1; }
  if(USER->query_guild_rank()){ return 1; }
  if(USER->query_guild_exp()){ return 1; }
  return 0;
}
/*************************************************************/

/********* Internal functions **************/
query_dam1_msg(int num) {
mapping map;
  map = map_check();
  switch(num){
    case 45..1000: return map["dam1"];
    case 40..44: return map["dam2"];
    case 33..39: return map["dam3"];
    case 27..32: return map["dam4"];
    case 17..26: return map["dam5"];
    case 10..16: return map["dam6"];
    case 5..9: return map["dam7"];
    case 1..4: return map["dam8"];
    default: return "missed";
  }
}

query_dam2_msg(string str) {
mapping map;
  map = map_check();
  switch(random(100)+1){
    case 75..1000: return map[str+"msg1"];
    case 50..74: return map[str+"msg2"];
    case 25..49: return map[str+"msg3"];
    case 1..24: return map[str+"msg4"];
    default: return map[str+"msg4"];
  }
}

map_check() {
string sigil_type;
  sigil_type = previous_object()->query_type();
  switch(sigil_type) {
    case "fire": return FIRE;
    case "ice": return ICE;
    case "electric": return ELECTRIC;
    default: return ([]);
  }
}
