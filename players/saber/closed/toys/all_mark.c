#define tp this_player()->query_name()

short()  { return "A ruby medallion"; }

id(str)  {
  return str == "instrument" ||
         str == "mrobe" ||
         str == "vampire fangs"  ||
         str == "mark"  ||
         str == "life"  ||
         str == "medallion";
        }

drop()  { return 1; }

init()  {
  add_action("boo","skdkfkd");
  if(environment(this_object())->is_player())  {
  destuct(this_object());
  return 1;
        }
        }
