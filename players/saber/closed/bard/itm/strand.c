#define tp this_player()->query_name()

inherit "/players/saber/closed/bard/itm/shapeobj.c";

reset(arg)  {
  if(arg) return;
   set_name("strand");
   set_short("A strand of chaos");
   set_long("You see nothing special.\n");
   set_alt_name("aaaa");
   set_weight(0);
   set_read("There are no runes to read.\n");
   set_value(0);
   set_light(0);
        }

query_bardic_mark()  { return 1; }
