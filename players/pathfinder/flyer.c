inherit "obj/treasure";
 
id(str) { return str == "brochure"; }
 
short() {
  return "A brochure of Detroit";
  }
  
long() {
  write("A brochure on the city of Detroit.  Read it to find out more.\n");
  }
  
init() {
  add_action("read_it", "read");
  }
  
query_weight() { return 5000; }

read_it(str) {
  if(!str || str != "brochure") {
    write("Read What?\n");
    return 1;
    }
  write("\n\n");
  write("To get to the City of Detroit from the Church go : \n");
  write("\n");
  write("  s, 6w, 2s, w then 'enter city'.\n");
  write("\nOh, yeah, there is also an area for those people who are under\n");
  write("level 5.\n");
  write("\n\n");
  write("Just remember one thing...\n");
  write(" Detroit, where the weak are killed and eaten(sometimes alive).\n\n\n");
  return 1;
}
