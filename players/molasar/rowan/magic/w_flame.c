
/*
 * WAND OF ENGULFING FLAME (3/19/94)
 * Moves wand to targeted object.  Will do damage to monster up to
 * max damage over a period of time
 */

#define MAX_DAMAGE 30

int total_damage;
object ob;
string old_sh_str, new_sh_str;
int short_desc;

reset(arg) {
   if(arg)
     return;
}

id(str) { return str == "wand"; }

init() { 
   add_action("engulf","engulf");
}

short() { 
   if(short_desc == 1) return 0;
   return "A wand of engulfing flame";
}

set_short(sh) { short_desc = sh; }

get() { return 1; }

long() {
   write("A small oak-carved wand.\n");
   write("You can surround your enemy in flames, causing damage.\n");
   write("Usage: engulf <monster>\n");
}

engulf(str) {
   object dest;
   
   dest = environment(this_player());
   ob = find_living(str);
   if(!ob || !present(ob, dest) || !ob->query_npc())
     return 0;
   old_sh_str = ob->short();
   new_sh_str = old_sh_str+" (engulfed in flames)";
   ob->set_short(new_sh_str);
   ob->attack_object(this_player());
   set_short(1);
   write("You use the wands power against "+capitalize(str)+".\n");
   tell_room(environment(this_player()),
       capitalize(this_player()->query_name())+" points a wand at "+
       capitalize(str)+", engulfing it in flames.\n");
   move_object(this_object(), ob);
   write("Your wand disappears.\n");
   call_out("damage_monster",5);
   return 1;
}

damage_monster() {
   int dam;

   if(!ob || (environment(this_object()) != ob)) {
     if(ob) {
       ob->set_short(old_sh_str);
       tell_room(environment(ob), "The flames surrounding "+
           capitalize(ob->query_name())+" die out.\n");
      }
     destruct(this_object());
     return 1;
   }
   if(total_damage >= MAX_DAMAGE) {
     ob->set_short(old_sh_str);
     tell_room(environment(ob), "The flames surrounding "+
         capitalize(ob->query_name())+" die out.\n");
     destruct(this_object());
     return 1;
   }
   dam = 3 + random(6);
   tell_room(environment(ob), capitalize(ob->query_name())+" screams in "+
       "pain!\n");
   ob->hit_player(dam);
   total_damage += dam;
   call_out("damage_monster", 10);
   return 1;
}

