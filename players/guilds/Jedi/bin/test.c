/* FOR TESTING ONLY */

#define PO previous_object()
main(string str) {
  string str2;
  int amt;

  if(!str) return 0;
  if(sscanf(str,"%s %d",str2,amt) != 2 ) {
    write("Usage: skill_test <skill> <amount>\n");
    return 1;
  }
  if(str2 == "skill") {
    PO->adj_skill_points(amt);
    write(str2+" now at: "+PO->query_skill_points()+".\n");
    return 1;
  }
  previous_object()->adj_skill(str2,amt);
  previous_object()->save_stats();
   write(str2+" now at: "+previous_object()->query_skill(str2)+".\n");
  return 1;
}
