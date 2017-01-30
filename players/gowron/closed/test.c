int *levels;

sort_func(int a, int b) {
   return levels[a] > levels[b];
}
query_level(ob) {
   return ob->query_level();
}
reset(arg) {
object *ob;
int i;
  ob = users();
  levels = map_array(ob, "query_level", this_object());
  for(i=0;i<sizeof(levels);i++)
     write(levels[i]+"\n");
  destruct(this_object());
}
