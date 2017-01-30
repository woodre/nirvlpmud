/*
Clothing object
Feldegast@Nirvana
3-29-2000
This object is a separate, unworn piece of clothing.  When this
object is worn, it is destructed and its descriptions and data
are added to a single clothes object, so that many types of
clothing can be worn at once.

*/
#define CLOTHES "/players/feldegast/std/clothes.c"

inherit "/obj/treasure.c";

/* 
The type of each piece of clothing is an array, so that any single
piece of clothing can occupy more than one place.
*/

string *type;

void set_type(string *str) {
  type=str;
}

void init() {
  add_action("cmd_wear","wear");
}

int cmd_wear(string str) {
  object clothes;
  clothes=present("clothing_object");
  if(!clothes) {
    clothes=clone_object(CLOTHES);
    move_object(clothes,this_player());
  }
  if((int)clothes->test_type(type))
    return 1;
  clothes->add_item(short_desc,name,value,type);
  write("You put on "+short_desc+".\n");
  say((string)this_player()->query_name()+" puts on "+short_desc+".\n");
  destruct(this_object());
  return 1;
}

void set_short(string str) {
  short_desc=str;
  long_desc="It is "+str+".\n";
}

void set_id(string str) {
  name=str;
}
