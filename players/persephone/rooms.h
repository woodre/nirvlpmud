/* From the files of Jjan: /players/jjan/rooms.h
   Modified by Havoc (92 - 09 - 03) */
 
#define TPL          this_player()
#define TPLNM        (this_player()->query_real_name())
#define CAPTPLNM     capitalize(this_player()->query_real_name())
#define TOB          this_object()
#define ENV(x)       environment(x)
#define HERE         ENV(TPL)
#define NPC(x)       (x)->query_npc()
#define ISPL(x)      query_ip_name(x)
#define put_monster(str) { move_object(clone_object("players/persephone/monsters/"+str),TOB); }
#define put_object(str) { move_object(clone_object("players/persephone/obj/"+str),TOB); }

/* return 0 or weapon wielded by pl */

object
get_wielded_weapon(object pl) {
     int i;
     object w;

     if(!pl) return 0;
     i = 0;
     w = first_inventory(pl);
     while(w && !i) {
           if(w->query_wielded()) i=1;
           else w = next_inventory(w);
     }
     return w;
}
