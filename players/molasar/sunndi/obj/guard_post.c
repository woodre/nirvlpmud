
/*
 * Guard Post
 *
 * This guard post is created in rooms/sunndi_road/sunndi_road1.c
 *
 */

#include "/players/molasar/sunndi/include/filter_color.h"

void reset(int arg);
string short();
void long();
void init();
int id(string str);
int destroy();
int repair();
int query_destroyed();
int set_destroyed(int state);
int destroyed;

void reset(int arg) {

   if (arg)
      return;

   destroyed = 0;
  
}

int id(string str) {
   return str == "guard post" || str == "post";
}

string short() {
   if (destroyed)
      return filter_color("A Guard Post (destroyed)", HIY);
   else
      return filter_color("A Guard Post", HIY);
}

void long() {
   if (destroyed)
      write("What was once a state of the art guard post is now a pile of wood.\n");
   else 
      write("This is a pretty sweet looking guard post.\n");
}


void init() {
   add_action("destroy","destroy");
   add_action("repair","repair");
}

int destroy() {
   if (destroyed) {
      write("The Guard Post has already been destroyed!\n");
      return 1;
   }

   write("Bam!\n");
   destroyed = 1;
   return 1;

}

int repair() {
   if (!destroyed) {
      write("The Guard Post has not been damaged!\n");
      return 1;
   }

   write("You did it!\n");
   destroyed = 0;
   return 1;

}

int query_destroyed() {
   return destroyed;
}

int set_destroyed(int state) {
   destroyed = state >= 0 ? 1 : 0;
}







