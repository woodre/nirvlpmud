/*
 *      File:             /obj/player/stats.c
 *      Function:         Inherited by player.c, controls attribs
 *      Notes:            05/11/06 Earwax: separated this from player.c
 *      Change History:
 */

/* Global Variables */
/* Old Attributes */
int strength, intelligence, stamina, will_power, magic_aptitude, piety, stealth;
int charisma, dexterity, luck;
int *atrbr;

/* New Attributes */
mapping bonuses;             /* ([ attrib : bonus total ])     */
int *stats;                  /* ({ str, con, dex, int, wil,    */                             
int *stat_maxes;             /*    luc, siz, hpr, epr, spr  }) */
static mapping StatIndices;  /* ([ "str" : 0, etc ])           */

/* Called from reset(0) */
void setup_stats()
{
  StatIndices = ([ "str" : 0, "strength" : 0,
                   "con" : 1, "constitution" : 1,
                   "dex" : 2, "dexterity" : 2,
                   "int" : 3, "intelligence" : 3,
                   "wil" : 4, "willpower" : 4,
                   "luc" : 5, "luck" : 5,
                   "siz" : 6, "size" : 6,
                   "hpr" : 7,
                   "epr" : 8,
                   "spr" : 9,
                 ]);
                 
  bonuses = ([ ]);
  stats = allocate(10);
  stat_maxes = allocate(10);
}
  
int query_stat(string arg) {
  if (arg == "luck" || arg == "luc") return luck;
}  
  
  
/* ==================================================================
 * Old attribute-handling functions
 * ==================================================================
 */

static ResetStats() {
  stamina = 5; intelligence = 5; will_power = 5; stealth = 5;
  magic_aptitude = 5; luck = 5; piety = 5; strength = 5;
  charisma = 5; dexterity=5;
}

raise_strength(arg){
  check_raise("strength",arg,strength);
  strength = strength + arg;
  tell_object(this_object(), "Your strength is now " + strength + "\n");
  return 1;
}
raise_intelligence(arg){
  check_raise("intell",arg,intelligence);
  intelligence = intelligence + arg;
  tell_object(this_object(), "Your intelligence is now " + intelligence + "\n");
  return 1;
}
raise_stamina(arg){
  check_raise("stamina",arg,stamina);
  stamina = stamina + arg;
  set_max_hp();
  tell_object(this_object(), "Your stamina is now " + stamina + "\n");
  return 1;
}
raise_will_power(arg){
  check_raise("willpower",arg,will_power);
  will_power = will_power + arg;
  tell_object(this_object(), "Your will power is now " + will_power + "\n");
  return 1;
}
raise_magic_aptitude(arg){
  check_raise("mag_apt",arg,magic_aptitude);
  magic_aptitude = magic_aptitude + arg;
  set_max_spell();
  tell_object(this_object(), "Your magic aptitude is now " + magic_aptitude + "\n");
  return 1;
}
raise_stealth(arg){
  check_raise("stealth", arg, stealth);
  stealth = stealth + arg;
  tell_object(this_object(), "Your stealth is now " + stealth + "\n");
  return 1;
}
raise_piety(arg){
  check_raise("piety", arg, piety);
  piety = piety + arg;
  tell_object(this_object(), "Your piety is now " + piety + "\n");
  return 1;
}
raise_luck(arg){
  check_raise("luck", arg, luck);
  luck = luck + arg;
  tell_object(this_object(), "Your luck is now " + luck + "\n");
  return 1;
}
raise_charisma(arg) {
  check_raise("charisma",arg,charisma);
  charisma = charisma+arg;
  tell_object(this_object(), "Your charisma is now " + charisma + "\n");
  return 1;
}
raise_dexterity(arg) {
  check_raise("dexterity",arg,dexterity);
  dexterity = dexterity+arg;
  tell_object(this_object(), "Your dexterity is now " + dexterity + "\n");
  return 1;
}
query_attrib(str) {
  if (!str || str == "") return 0;
  if (str == "str") return strength;
  if (str == "sta") return stamina;
  if (str == "wil") return will_power;
  if (str == "mag") return magic_aptitude;
  if (str == "pie") return piety;
  if (str == "ste") return stealth;
  if (str == "luc") return luck;
  if (str == "int") return intelligence;
  if (str == "dex") return dexterity;
  if (str == "cha") return charisma;
  return 0;
}
int query_total_stats() {
  return strength+stamina+will_power+magic_aptitude+piety+stealth+luck+intelligence+charisma+dexterity;
}
setup_atrbr() {
  if(!atrbr[0]) atrbr[0] = charisma;
  if(!atrbr[1]) atrbr[1] = dexterity;
  if(!atrbr[2]) atrbr[2] = intelligence;
  if(!atrbr[3]) atrbr[3] = luck;
  if(!atrbr[4]) atrbr[4] = magic_aptitude;
  if(!atrbr[5]) atrbr[5] = piety;
  if(!atrbr[6]) atrbr[6] = stamina;
  if(!atrbr[7]) atrbr[7] = stealth;
  if(!atrbr[8]) atrbr[8] = strength;
  if(!atrbr[9]) atrbr[9] = will_power;
  return;
}
rec_attrib_max(atb) {
   if(atb=="cha") atrbr[0] = charisma;
   if(atb=="dex") atrbr[1] = dexterity;
   if(atb=="int") atrbr[2] = intelligence;
   if(atb=="luc") atrbr[3] = luck;
   if(atb=="mag") atrbr[4] = magic_aptitude;
   if(atb=="pie") atrbr[5] = piety;
   if(atb=="sta") atrbr[6] = stamina;
   if(atb=="ste") atrbr[7] = stealth;
   if(atb=="str") atrbr[8] = strength;
   if(atb=="wil") atrbr[9] = will_power;
   return 1;
}
add_attrib_max(atb,atc) {
   if(atb=="cha") atrbr[0] += atc;
   if(atb=="dex") atrbr[1] += atc;
   if(atb=="int") atrbr[2] += atc;
   if(atb=="luc") atrbr[3] += atc;
   if(atb=="mag") atrbr[4] += atc;
   if(atb=="pie") atrbr[5] += atc;
   if(atb=="sta") atrbr[6] += atc;
   if(atb=="ste") atrbr[7] += atc;
   if(atb=="str") atrbr[8] += atc;
   if(atb=="wil") atrbr[9] += atc;
   return 1;
}
query_attrib_max(atb) {
   if(atb=="cha") return atrbr[0];
   if(atb=="dex") return atrbr[1];
   if(atb=="int") return atrbr[2];
   if(atb=="luc") return atrbr[3];
   if(atb=="mag") return atrbr[4];
   if(atb=="pie") return atrbr[5];
   if(atb=="sta") return atrbr[6];
   if(atb=="ste") return atrbr[7];
   if(atb=="str") return atrbr[8];
   if(atb=="wil") return atrbr[9];
   return 1;
}
query_total_max_atrbr() {
  int tot,aaa;
  for(aaa=0;aaa<10;aaa++)
     tot+=atrbr[aaa];
  return tot;
}  
check_raise(str, vvv,zzz){
  string t;
  int aaa;
  
  t = this_object()->query_real_name();
  aaa = zzz + vvv;
  if (previous_object()) {
  	log_file("ATTRIB", t + ": " + str + " raised by " + vvv + " from " + zzz + " to " + aaa  + " by " +
      file_name(previous_object()) + "\n");
    log_file("ATTRIB", t + " str-"+strength+" ste-"+stealth+" sta-"+stamina+
      " wil-"+will_power+" mag-"+magic_aptitude+" pie-"+piety+" lck-"+luck+
      " int-"+intelligence+" cha-"+charisma+" dex-"+dexterity+ "\n");
  	if (this_player() && this_player() != this_object() 
    && query_ip_number(this_player()))
      log_file("ATTRIB", "Done by " + this_player()->query_real_name() + "\n");
  }
  return 1;
}

set_attrib(str,arg){
  string tname;

  tname = (this_player() ? (string)this_player()->query_real_name() : "NO-TP");
  if (str=="str") strength = arg;
  if (str=="int") intelligence = arg;
  if (str =="sta") stamina =arg;
  if (str =="pie") piety = arg;
  if (str =="luc") luck = arg;
  if (str =="ste") stealth = arg;
  if(str=="wil") will_power = arg;
  if(str=="mag") magic_aptitude = arg;
  if (str=="dex") dexterity = arg;
  if (str=="cha") charisma = arg;
  if(this_player())
  log_file("ATTRIB2","set_attrib - "+tname+" "+str+" "+arg+" by "+this_player()->query_real_name()+"\n");
  if(previous_object())
  log_file("ATTRIB2",file_name(previous_object())+"-^\n");
  return 1;
}
