int new_object;
int new_name;
int new_value;
int new_short;
int new_long;
int start_time;
 
start(ob) {
    move_object(this_object(), ob);
}
 
id(str) {
    return str == "wand"; }
 
long() {
 
  write("Catwoman's list!\n\n");
  write("diet      Diet <player> <amount>\n");
  return 1; }
 
 
init() {
    
    add_action("tend","diet");
 }
drop() { return 1;}
 
short() {
    return "A wand"; }
 
 
get() {
    return 1; }
 
reset(arg) {
    if (!arg)

    set_light(0); }
 
 
tend(str) {
  object player;
  int amount;
  string name;
  if(!str) return 0;
/*
  sscanf(str,"%s", name);
*/
  player = find_living(str);
  if(!player) {
  write("Player does not exist.\n");
  return 1; }
  call_other(player,"add_phys_at(3,-(20)");
  write("Ok. Healing complete.\n");
  return 1; }
 

lookplayer(str) {
    object ob;
    int i;
    if (!str)
       return 0;
    ob = find_living(str);
    if (!ob)
       return 0;
    write("Inventory of " + call_other(ob, "short") + ";\n");
    i = 0;
    ob = first_inventory(ob);
    while(ob) {
       string short_str;
       write(i + "\t");
       short_str = call_other(ob, "short");
       if (short_str)
          write(short_str + ",\t");
       write(ob); write("\n");
       ob = next_inventory(ob);
       i += 1;
   }
   return 1;
 }

