/* edited 05-15-07 by Tallos to lower weight 'aura' 
should be nearly weightless but 1 seems fine, 
add mage guild bonus, and ansi*/

#define tp this_player()->query_name()
#define GUILDID "mageobj"
#define BONUS_TYPE "necromancy"
#define BONUS_AMOUNT 2 
string charges_count;
#include "/players/tallos/ansi.h"
inherit "obj/armor";
int n, ahp;

init() {
  ::init();
add_action("banshee","banshee");
}

reset(arg){
   if(arg) return;
   ::reset(arg);
   set_name("aura of death");
   set_short(""+HIY+""+BLK+"Aura "+HIW+"of "+BLK+"Death"+NORM+"");
   set_alias("aura");
   set_long("A hazy "+HIY+""+BLK+"black aura of death"+NORM+", once worn by a banshee.\n"+
     "It is obviously a strongly magical item.\n"+
     "To use type 'banshee <monster>' <limited charges>.\n");
   set_type("misc");
/* Changed ac from 1 to 2 and weight from 6 (?) to 3
 * this seems a little more thematic (weightwise) and
 * will make the armor good but unstorable, as it
 * should be. -Snow 5/99 */
   set_ac(2);
   /* added dtype protection - Illarion Dec 2004 */
   set_params("other|magical",2);
   set_weight(1);
   set_value(7000);
}
query_guild_bonus(){ return BONUS_AMOUNT; }

add_guild_bonus()
{
  if(present(GUILDID, this_player()))
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, BONUS_AMOUNT);
			
}

remove_guild_bonus()
{
  if(present(GUILDID, this_player()))
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, -BONUS_AMOUNT);
	
}

banshee(str) {
object ob;
string gender;
if(this_player()->query_level() < 4)
return 0;
if (!str)
{
write("banshee what?\n");
return 1; }
else
ob = present(str,environment(this_player()));
if(!ob) {
write("To use 'banshee <monster>'.\n");
return 1;  }
if(!living(ob)) { write("You can not banshee that!\n"); return 1; }

/* added to prevent using it in no_fight rooms - 7/26/00  Eurale  */
if(environment(this_player())->query_no_fight()) {
  write("Your voice echoes harmlessly into thin air...\n");
  return 1; }

if (ob->query_npc()){
n = random(30)+22;
ahp = ob->query_hp();
if(n>ahp) { n = ahp - 1; }
/* added dtype to damage - Dec 2004 Illarion */
ob->hit_player(n,"other|sonic");
charges_count = charges_count + 1;
str = capitalize(str);
gender = "its";
if(this_player()->query_gender() == "male"){gender = "his";}
if(this_player()->query_gender() == "female"){gender = "her";}
write("You glare at your foe and\n\n                                 S C R E A M\n\n");
write(str+"'s ears bleed.\n");
say(tp+" glares at "+gender+" foe and wails a banshee like\n\n                             S C R E A M\n\n");
say(str+"'s ears bleed.\n");
this_player()->attack_object(ob);
if(living(ob)) ob->attack_object(this_player());
if (charges_count > 4 ) {
command("remove aura",this_player());
write("The aura fades back into the darkness from which it came.\n");
say("The aura fades back into the darkness from which it came.\n");
destruct(this_object());
return 1;
}
return 1;
}
write("You cannot attack players with this.\n");
}

generic_object() { return 1;} 
locker_arg() { return "" + charges_count;}
locker_init(arg) { charges_count = atoi(arg);} 
restore_thing(str){
      restore_object(str);
      return 1;
   }
save_thing(str){
      save_object(str);
      return 1;
   }
