inherit "obj/treasure.c";
int coins;
int coinage;
string subject;
string argomento;
string str;
set_coinage2(coinage) { coins=coinage; }

set_subject2(subject) {
argomento= subject;

if(argomento=="calculus"){
    set_short("A Book of Calculus"); 
    set_long("The hardcover of this book is blue.  This book is used by students in\n"+
             "their first year of engineering when they have to build up the basis\n"+
             "for their further studies. It reports the study of basic mathematics\n"+
             "for engineers.\n");}

if(argomento=="chemistry"){
    set_short("A Book of Chemistry");
    set_long("The hardcover of this book is brown.  This book is used by students in\n"+
             "their first year of engineering when they have to build up the basis\n"+
             "for their further studies. It basically reports the study of the matter\n"+
             "and its transformations.\n");}

if(argomento=="drawing"){
    set_short("A Book of Drawing");
    set_long("This is not exactly a book, but rather a collection of wide sheets of\n"+
             "paper which report the basic schemes needed for preparing thecnical\n"+
             "figures.  The mechanical drawing is just a language for the engineers.\n"+
             "They use it to explain and to communicate to others their design.\n");}

if(argomento=="applied mechanics"){
    set_short("A Book of Applied Mechanics");
    set_long("The hardcover of this book is pale brown.  This book is used by mechanical\n"+
             "engineering students to learn the basic of the mechanisms able to transmit\n"+
             "the movement from one part to another of a mechanical device.  The last\n"+
             "pages of this book explains also something about vibrations.\n");}

if(argomento=="computer science"){
    set_short("A Book of Computer Science");
    set_long("The softcover of this book is yellow.  This book is used by students in\n"+
             "their first year of engineering when they have to build up the basis\n"+
             "for their further studies. It basically reports both the software and\n"+
             "hardware architecture of modern computers.  Its appendix is dedicated\n"+
             "to the LPC language.\n");}

if(argomento=="corrosion"){
    set_short("A Book of Corrosion");
    set_long("The hardcover of the book is gray.  This book is used by students in\n"+
             "their last year year of engineering when they have to learn their skill\n"+
             "in specific fields.  By reading the whole book, you will find several\n"+
             "examples of structures and components degradated by environmental effects.\n");}

if(argomento=="design of machines"){
    set_short("A Book of Design of Machines");
    set_long("The hardcover of this book is dark gray.  This fundamental subject is\n"+
             "generally taught to students in their junior year of mechanical engi-\n"+
             "neering curriculum.  Basic principles of design are explained with\n"+
             "a particular emphasis toward the 'Design for...' meaning how an engineer\n"+
             "could optimize his project by taking into account the application.\n");}

if(argomento=="electrotechnics"){
    set_short("A Book of Electrotechnics");
    set_long("The softcover of this book is pale red.  Two main subjects are shown\n"+
             "in this book: the electrical circuits and the electrical devices, such\n"+
             "as electrical engines, converters and transformers.\n");}

if(argomento=="engines"){
    set_short("A Book of Engines");
    set_long("The hardcover of the book is red.  Another fundamental subject of\n"+
             "mechanical engineering:  the transformation of chemical energy into\n"+
             "mechanical one is a key factor to learn for a good engineer.\n");}

if(argomento=="fluid dynamics"){
    set_short("A Book of Fluid Dynamics");
    set_long("The hardcover of this book is green.  This is another subject which\n"+
             "bridges the gap between the basic courses of math and the following\n"+
             "ones dedicated to the application.  Of course, both gases and liquids\n"+
             "are studied, like it might occur in the movement of a ship or an airplane.\n");}

if(argomento=="geometry"){
    set_short("A Book of Geometry");
    set_long("The hardcover of the book is pale green.  This book is used by students in\n"+
             "their first year of engineering when they have to build up the basis\n"+
             "for their further studies. It basically reports the study of how a shape\n"+
             "can be described by mathematical formulas.\n");}

if(argomento=="machines"){
    set_short("A Book of Machines");
    set_long("The hardcover of the book is dark green.  The basic principles of how\n"+
             "it is possible to describe the thermodynamic behaviour of fluids in order\n"+
             "to build up the theory needed for the construction of useful devices.\n"+
             "This subject is taught at the junior year of mechanical engineering.\n");}

if(argomento=="pruduction systems"){
    set_short("A Book of Production Systems");
    set_long("The hardcover of this book is magenta.  Not only the production of a\n"+
             "single piece by a single machine is important, yet in the modern industry\n"+
             "a key factor is the integration bewteen different machines and different\n"+
             "products. This is the subject covered by this book.\n");}

if(argomento=="management"){
    set_short("A Book of Management");
    set_long("The softcover of this book is dark brown.  The subject covered by this book\n"+
             "is basically the economics. Not only the mechanical engineers must know the\n"+
             "best design methods and technologies to make their products of high quality\n"+
             "yet they must compete in a global market from the ecnonomics and industrial\n"+
             "strategies points of view.  This is what this book is meant to teach.\n");}

if(argomento=="manufacturing"){
    set_short("A Book of Manufacturing");
    set_long("The hardcover of this book is pale blue.  This book is used by students in\n"+
             "their first year of engineering when they have to build up the basis\n"+
             "for their further studies. It basically reports the study of the matter\n"+
             "and its transformations.\n");}

if(argomento=="mechanics of materials"){
    set_short("A Book of Mechanics of Materials");
    set_long("The hardcover of the book is dark blue.  This book is used by students in\n"+
             "their second year of engineering and it introduces them to problem solving\n"+
             "related to the mechanical resistance of components and structures. The \n"+
             "mathematical formulations of the problems is still of great help here.\n");}

if(argomento=="metallurgy"){
    set_short("A Book of Metallurgy");
    set_long("The softcover of this book is white.  This book has two souls: one is related\n"+
             "to the inner matter constitution, the other is connected with the practical\n"+
             "operations that might be performed onto metals to modify them in order to\n"+
             "meet the aforeseen performances required by the engineers.\n");}

if(argomento=="operational research"){
    set_short("A Book of Operational Research");
    set_long("The softcover of the book is black.  Much mathematics is still present.\n"+
             "The methods for a comprehensive and rigorous approcah to problem solving\n"+
             "are shown and will permit the students to analyze also very complex systems.\n"+
             "This subject is taught at the third year of mechanical engineering.\n");}

if(argomento=="physics"){
    set_short("A Book of Chemistry");
    set_long("The hardcover of the book is pink.  This book is used by students in\n"+
             "their first year of engineering when they have to build up the basis\n"+
             "for their further studies. It basically reports the study of the\n"+
             "fundamental laws governing the nature, in terms of mechanics, thermo-\n"+
             "dynamics and electromagnetism.\n");}

if(argomento=="robotics"){
    set_short("A Book of Robotics");
    set_long("The softcover of this book is light magenta.  The application of the robots\n"+
             "will be wider and wider in the future, in order to save human beings from\n"+
             "heavy and repetitive tasks.  It is needed to study the laws governing the\n"+
             "use of such helpers,  yet a look is also taken to their construction.\n");}

if(argomento=="thermodynamics"){
    set_short("A Book of Thermodynamics");
    set_long("The hardcover of the book is light gray.  This book is used by students in\n"+
             "their second year of engineering in order to go deeper inside the heat\n"+
             "transfer problems.  It also shows interesting practical applications such\n"+
             "as the air conditioning and the waste recycling for energy saving.\n");}

}
reset(arg)
   { if(arg) return;}


id(str) { return str == "book" ; }

init() {
    add_action("return_book"); add_verb("return");
    add_action("put_book"); add_verb("put");   
    add_action("apply_degree"); add_verb("apply");
    return 1;
}




put_book(str) {
    if(!str) { write("Put what?\n") ; return 1; }
    if(str == "book on desk") {
     if(present("desk",environment()))  {
      if(present("book",this_player()))  {
       write("You put a book on the desk.\n");
      return 1;}
     return 1;}  
    return 1;}       
return 1;
}       
 
return_book(arg) {
    object item;
    if(!arg)
      {
       write("Return what??\n");
       return 1;
      }
    if(arg=="book" || arg==argomento)
    { 
    if(!present("marian",environment(this_player())))
     {
      write("Unfortunately, "+call_other(this_player(),"query_name")+", you cant return this book now.\n"+
            "You might try later.\n");
      return 1;
     }
    
      call_other(this_player(),"add_money",coins); 
      write("Thank you very much, "+call_other(this_player(),"query_name")+", I was exactly looking\n"+
            "for this book of "+argomento+".\n");
      destruct(this_object());
      return 1; 
   }
return 0;
 }


get() { return 1; }

query_weight() { return 1; }

query_value() { return (coins); }

drop() { return 0; }

query_save_flag() { return 1; } 


