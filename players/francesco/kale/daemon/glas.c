inherit "obj/armor.c";

int current_page;

reset(arg)
{
    if(arg) return;
    current_page = 0;
}

short() { return "A coloured flier"; }

long(str) {
    write("The flier is made by four pages, folded to each other to make it\n"+
          "a compact and fast to use tool.  You may read the various pages.\n");
	return;
    }
    

init() {
    add_action("read_book","read");
}

id(str) { return str == "glass" ; }



read_book(stri) {
      if (!stri)
      {
      write("Read what?\n");
      return 1;
      }
     if(stri == "page 1") {
     write("The Department of Mechanical Engineering gives courses at the\n"+
           "Bachelor, Master and Phd levels.  Most of the courses are taught\n"+
           "by tenure professors,  some are taught by external teachers who\n"+
           "bring inside their professional expertise.\n");
     return 1; }
     if (stri=="page 2")  {
     write("At bachelor level we offer all the basics of Mechanical Engineering,\n"+
           "including  Mechanical Drawing,  Applied Mechanics,  Thermodynamics,\n"+
           "Engines,  Design of Machines,  Manufacturing Technology,  Fluidynamics.\n"+
           "The students will get a preparation more addressed to solve practical\n"+
           "problems,  yet always taking into account how and why they things occur.\n");
     return 1; }
     if (stri=="page 3")  {
     write("The master level will give expertise in the same areas than bachelor\n"+
           "level does, yet the subjects would go deeper into the mechanisms and\n"+
           "into the mathematical formulations of the phenomena.  We think that\n"+
           "this way of preparing our future management will allow them to face\n"+
           "any kind of problems, since our students now actually learn a methodology\n"+
           "rather than information only.\n");
     return 1;  }
     if (stri=="page 4")  {
     write("The PhD courses are strictly related to the scientific activities of\n"+
           "the Department which are particularly advanced in the fields of Design\n"+
           "of Machines, Engines, Manufacturing, Fluidodynamics.  Our PhD students\n"+
           "are very likely hired within the Universities and Research Centers after\n"+
           "their graduation.\n");
     return 1;  }
}
/*
{
    write("\n        February 4th\n"+
          "   Happy B-Day, Francesco!\n\n");
    return 1;
}
*/
