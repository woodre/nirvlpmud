#include <ansi.h>

int
rsharpenall() {
   object *p;
   object weapon;
   int h, s;
   
   p = users();
   s = sizeof(p);
   for (h = 0; h<s; h++) {
      weapon = (object)p[h]->query_weapon();
      if ( ((int)p[h]->query_wc() >= 7) &&
           weapon &&
            (int)weapon->query_broke() == 0) {
         weapon->set_hits(1);
         weapon->set_misses(1);
         tell_object(p[h], HIB+this_player()->query_name()+
            " sharpens your "+weapon->query_name()+"!"+NORM+"\n");
         write(p[h]->query_name()+"'s "+weapon->query_name()+" sharpened.\n");
        }
   }
   return 1;
}
