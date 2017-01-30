/* GUILD WEAPON BASE */
inherit "/obj/weapon.c";
#include "../../DEFS.h"


int prof, damage;



string query_wear_desc()
{
  int wear;
  string msg;

  wear = (int)query_wear();
  if (wear <  40)                msg="like new";
  if (wear >  39  && wear < 100) msg="a little worn";
  if (wear >  99  && wear < 200) msg="somewhat worn";
  if (wear > 199  && wear < 400) msg="worn";
  if (wear > 399)                msg="well worn";

  return msg;
}


long()
{
  int wear;
  string msg;

  write(long_desc);
  /* wear msg added by wocket 4.07.01 */
  msg="It is " + query_wear_desc() + ".\n";

  if ((int)TP->query_level() >= 40)
    write("Hits = "+hits+"    Misses = "+misses+"\n");
}


status wield(string str)
{
   if (!id(str)) return 0;
   if (environment() != TP) return 0;
   if(!message_hit)
      message_hit=({"massacre"," to small fragments",
         "smashed", " with a bone crushing sound",
         "hit",     " very hard",
         "hit",     " hard",
         "hit",     "",
         "grazed",  "",
         "tickled", " in the stomach"});
   if (wielded) {
      write("You already wield it!\n");
      return 1;
   }
   if(!IPTP) {
      write("You are not a "+FUNKYNAME+"!\n");
      destruct(this_object());
      return 1; 
   }
   wielded_by = TP;
   call_other(TP, "wield", this_object(), silentwield);
   wielded = 1;
   return 1;
}


string short()
{
   string tmp_short;
   if(TP)
   if((int)TP->query_level() > 30) {
      tmp_short = short_desc+"  < wc "+
      class_of_weapon+","+eff_wc+" >";
      if(broke) tmp_short += " <BROKEN> ";
      if(wielded) return tmp_short + " (wielded)";
      return tmp_short; }
   if(short_desc) { tmp_short = short_desc;
      if(broke) tmp_short += " <BROKEN> ";
      if(wielded) tmp_short += " (wielded)";
      return tmp_short;
   }
   else return "A messed-up CyberNinja weapon";
}


status id(string str)
{
   return str == WEAPON_ID || str == name_of_weapon ||
   str == alt_name  || str == alias_name ||
   str == "weapon" || str == "generic_wc_object" || str=="pro_object";
}


drop(silently)
{
  object ob;

  if (previous_object() && !living(previous_object()) ) return 0;
  if (wielded) {
      call_other(wielded_by, "stop_wielding");
      wielded = 0;
  }
/*added by wocket */
  if (!silently)
  {
    if (name_of_weapon != WEAPON_HANDS)
    {
      write(BOLD+"A vortex swirls above you.\n"+
            "You offer your "+name_of_weapon+" to the cyberspace.\n"+
            "The vortex closes around your "+name_of_weapon+".\n"+OFF);
      if (environment() && environment(this_object()))
      {
        ob = environment(this_object());
        say (OPN + " offers " + 
            ob->query_possessive() + " " + 
            name_of_weapon + " into the cyberspace.\n");
      }
    }
    else
    {
      write(BOLD+"You unfocus your Ch'i.\n"+OFF);
    }
  }
  set_weight(0);
  if(this_player())
    this_player()->recalc_carry();
  destruct(this_object());
  return 1;
}


query_pro_weapon() { return 1; }
mod_prof(int num)  { prof += num; }
set_prof(int num)  { prof = num; }
mod_damage(int num){ damage += num; }
set_damage(int num){ damage = num; }
query_prof()       { return prof; }
proficiency_hit()  { return prof; }
query_value()      { return 0; } 
query_save_flag()  { return 1; } 
count_misses()     { misses += 1; return 1; }
set_wielded(int num)      { wielded = num; }
set_wielded_by(object ob) { wielded_by = ob; }
query_no_sell(){ return 1; }
query_type()              { return WEAPON_ID; }

int gen_wc_bonus()
{
  if(!wielded) return 0;
  return (int)environment()->query_guild_rank() / 3;
}
