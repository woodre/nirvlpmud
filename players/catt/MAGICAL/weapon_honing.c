/***********************************/
/* A magical Item that hones       */
/* weapons, increasing their       */
/* wc for a specified amount       */
/* of time.                        */
/***********************************/

   id(str) { return str == "weapon hone"; }
   get() { return 1; }
   short() { return ""; }
   long() { 
      write("A weapon honing item.\n");
      return 1;
   }
   reset(arg) {
      if(arg) return;
   }

   init() {
      add_action("hone_weapon","hone");
   }

   hone_weapon(arg) {
      object weapon;
      int i,x;
   weapon = this_player()->query_weapon(arg);
      if(!weapon) return;
      i = weapon->weapon_class();
      if(i > 17 || weapon->query_info() == "honed weapon") {
         tell_object(this_player(), "This weapon can not be honed.\n");
         return 1;
      }
      x = i+3;
      weapon->set_class(x);
      weapon->set_info("honed weapon");
      tell_object(this_player(), "Your weapon is sharpened beyond beleif.\n");
      return 1;
   }
