
/*
 * SCROLL OF 2 CLERICAL SPELLS  (3/19/94)
 *    - cure serious wounds    will restore 8*pie hp
 *    - lay hands              complete heal
 */

int cure, heal;

reset(arg) {
   if(arg)
     return;
   cure = 1;
   heal = 1;
}

id(str) { return str == "scroll"; }

get() { return 1; }

query_value() {
   if(cure && heal)
      return 800;
   return 400;
}

short() { return "A scroll of clerical spells"; }

long() {
   write("A scroll written on fine parchment.\n");
   write("It is a scroll of clerical spells.\n");
   if(heal)
     write("--lay hands              Completely heal you.\n");
   if(cure)
     write("--cure serious wounds    Will cure some hp base on your Piety.\n");
}

init() {
   add_action("lay","lay");
   add_action("cure","cure");
}

cure(str) {
   int pie, tmp_heal;
   if(!str || str != "serious wounds" || !cure)
     return;
   pie = this_player()->query_attrib("pie");
   tmp_heal = pie*8;
   this_player()->heal_self(tmp_heal);
   say(capitalize(this_player()->query_name())+" reads from a scroll.\n");
   write("You feel healthier.\n");
   cure = 0;
   if(!heal)
     destruct(this_object());
   return 1;
}

lay(str) {
   if(!str || str != "hands" || !heal)
     return;
   this_player()->heal_self(1000);
   say(capitalize(this_player()->query_name())+" reads from a scroll.\n");
   write("You feel healthier.\n");
   heal = 0;
   if(!cure)
     destruct(this_object());
   return 1;
}
