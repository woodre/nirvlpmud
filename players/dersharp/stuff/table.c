id(str) { return str =="table";}
reset() {}
short() { return "A magnificent dining table.";}
get() {return 0;}
query_weight() { return 1;}
query_value() {return 0;}
long() {write("      This table is made of the darkest mahogany.  The grain\n"+
              "seems to whorl in the center, creating an eye which is quite\n"+
              "interesting to look at though nothing is magical about it.\n"+
              "On the table are place mats and a candlebra which is unlit.\n");}
init() {
	add_action("light", "light");
}
light(str) {
	if(str =="candlebra") {
	write(capitalize(this_player()->query_real_name()) + " finds a match and lights the candles,\n"+
             "as the candles are lit the room goes dim, being illuminated only\n"+
             "by the candles now.\n");
	return 1;
}
	return 0;
}
