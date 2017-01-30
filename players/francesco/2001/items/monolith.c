reset(){}

short() { return "A Monolith"; }

long() {
 write("The Monolith is a cube about fifteen feet on a side, and it is made of\n"+
       "some completely transparent material. Indeed, it is not easy to see except\n"+
       "when a powerful source of light glints on its edges.  Once upon a time\n"+
       "The Moonwatcher 'touch'ed it.\n"); }
    
init() {

}

id(str) { return str == "monolith" ; }


get(str) {
    if (str == "monolith") {
	write("What?  Get the Monolith?  Naawww.\n");
	return 0;}
    return 0;
}

