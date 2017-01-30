
inherit "obj/container.c";

void init () {
   ::init();
#ifndef __LDMUD__
   add_action("do_command"); add_xverb("");
#else
   add_action("do_command","",3);
#endif
}

int do_command ( string arg ) {
   move_object(this_player(), environment(this_object()));
   command(this_player(), query_verb() + " " + arg);
   move_object(this_player(), this_object());
}

int long ( string str ) {
   string *objs;
   object *all;
   write(long_desc);
   if ( !all = all_inventory(this_object()) )
      return;
   for ( i = 0; i < sizeof(all); i++ ) {
      objs += ({ all[i]->query_name() });
   }
   if ( sizeof(objs) < 1 )
      desc = objs[0];
   else 
      desc = implode(obj[0..sizeof(obj)-1], ", ") + obj(sizeof(objs));
   if ( desc ) {
      write(format("On the " + this_object()->query_name() + 
         " are " + desc + ".\n", 75));
   }
}
