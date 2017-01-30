/*
 *  Light: shield object
 *  A shield of light that has built in attack spell (4 charges)
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

inherit "obj/armor";

#include "/players/saber/closed/esc2.h"
#include "/players/saber/closed/ansi.h"

#define tp this_player()->query_name()

string charges_count, player_info;
int n, ahp;

init() {
  ::init();
add_action("sphere","orb");
add_action("globe","globe");
add_action("slarf","un_cry");
        }

  drop() { return 1; }
  get()  { return 1; }
  can_put_and_get()  { return 0; }

reset(arg){
  ::reset(arg);

  charges_count = 0;
  player_info = 0;
  count();

   set_name("sphere");
   set_short("A shield-sphere of "+HIY+"c"+HIR+"h"+HIG+"r"+HIC+"o"+HIM+"m"+HIB+"a"+HIR+"t"+HIY+"i"+HIB+"c"+NORM+" light");
   set_alias("light_shield");
   set_long();
   set_type("shield");
   set_ac(1);
   set_weight(0);
   set_value(0);
        }

long()  {
  write(
   "A shimmering shield sphere of "+HIY+"c"+HIR+"h"+HIG+
   "r"+HIC+"o"+HIM+"m"+HIB+"a"+HIR+"t"+HIY+"i"+HIB+"c"+NORM+" light.\n"+
   "You think the you could < wear > it as a shield.\n"+
   "To hurl a sphere of "+HIY+"light"+NORM+" - Syntax: < orb > < target >\n"+
   "To destruct the globe, type <un_cry>.\n"+
   "You can hurl "+player_info+" more spheres from the shield.\n");
        }


sphere(str) {
object ob;
string COLOR;

  if(!str && this_player()->query_attack())  {
    str = this_player()->query_attack()->query_real_name();
        }
  
  if(!str)  {  
    write("Syntax: sphere < target >\n");  
    return 1;
        }
  
  ob = present(str,environment(this_player()));
  
  if(!ob) {
    write("You do not see a "+capitalize(str)+".\n");
    return 1;  
        }

  if(!living(ob)) {
    write(capitalize(str)+" is not alive.\n");
    return 1;  
        }

  if (ob->query_npc()) {
    this_player()->attack_object(ob);
    if(living(ob))  ob->attack_object(this_player());
    n = random(22)+10;
    ahp = ob->query_hp();
      if(n>ahp) { n = ahp - 1; }
    ob->hit_player(n);
    count();
    str = capitalize(str);
    
    if(charges_count <  3)  COLOR = " "+HIB+"blue light"+NORM+" ";
    if(charges_count == 3)  COLOR = " "+HIR+"red light"+NORM+" ";
    if(charges_count == 4)  COLOR = " "+HIG+"green light"+NORM+" ";
    if(charges_count >  4)  COLOR = " "+HIM+"purple light"+NORM+" ";

    write("You hurl a sphere of");
    write(COLOR);
    write("at "+lower_case(ob->short())+".\n");
    
    say(tp+" hurls a sphere of");
    say(COLOR);
    say("at "+lower_case(ob->short())+".\n");  
    
    if (charges_count > 4 ) {
    command("remove shield", this_player());
 
    write("\nThe "+HIY+"c"+HIR+"h"+HIG+"r"+HIC+"o"+HIM+"m"+HIB+"a"+HIR+"t"+HIY+"i"+HIB+"c"+NORM+
    " sphere fades back into the "+BOLD+"chaos"+NORM+" from which it came.\n\n");
    say("\n"+tp+"'s "+HIY+"c"+HIR+"h"+HIG+"r"+HIC+"o"+HIM+"m"+HIB+"a"+HIR+"t"+HIY+"i"+HIB+"c"+NORM+
    " sphere fades back into the chaos from which it came.\n\n");

    destruct(this_object());
    return 1;
         }
         
    return 1;
         }
         
  write("The sphere of "+HIY+"light"+NORM+" will not effect players.\n");
  return 1;
         }


slarf()  {
  write("The colors of the globe fade back into the streams of chaos.\n");
  destruct(this_object());
  return 1;
        }
        

count()  {
charges_count = charges_count + 1;
player_info = 5 - charges_count;
        }
