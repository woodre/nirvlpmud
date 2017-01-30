#include "/players/francesco/univ/ansi.h"
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
    set_short(BLU+"A Book of Calculus"+NORM); 
    set_long("The hardcover of this book is blue.  This book is used by students in\n"+
             "their first year of engineering when they have to build up the basis\n"+
             "for their further studies. It reports the study of basic mathematics\n"+
             "for engineers.\n");}

if(argomento=="chemistry"){
    set_short(YEL+"A Book of Chemistry"+NORM);
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
    set_short(YEL+"A Book of Applied Mechanics"+NORM);
    set_long("The hardcover of this book is pale brown.  This book is used by mechanical\n"+
             "engineering students to learn the basic of the mechanisms able to transmit\n"+
             "the movement from one part to another of a mechanical device.  The last\n"+
             "pages of this book explains also something about vibrations.\n");}

if(argomento=="computer science"){
    set_short(HIY+"A Book of Computer Science"+NORM);
    set_long("The softcover of this book is yellow.  This book is used by students in\n"+
             "their first year of engineering when they have to build up the basis\n"+
             "for their further studies. It basically reports both the software and\n"+
             "hardware architecture of modern computers.  Its appendix is dedicated\n"+
             "to the LPC language.\n");}

if(argomento=="corrosion"){
    set_short(WHT+"A Book of Corrosion"+NORM);
    set_long("The hardcover of the book is gray.  This book is used by students in\n"+
             "their last year year of engineering when they have to learn their skill\n"+
             "in specific fields.  By reading the whole book, you will find several\n"+
             "examples of structures and components degradated by environmental effects.\n");}

if(argomento=="design of machines"){
    set_short(GRN+"A Book of Design of Machines"+NORM);
    set_long("The hardcover of this book is dark gray.  This fundamental subject is\n"+
             "generally taught to students in their junior year of mechanical engi-\n"+
             "neering curriculum.  Basic principles of design are explained with\n"+
             "a particular emphasis toward the 'Design for...' meaning how an engineer\n"+
             "could optimize his project by taking into account the application.\n");}

if(argomento=="electrotechnics"){
    set_short(RED+"A Book of Electrotechnics"+NORM);
    set_long("The softcover of this book is pale red.  Two main subjects are shown\n"+
             "in this book: the electrical circuits and the electrical devices, such\n"+
             "as electrical engines, converters and transformers.\n");}

if(argomento=="engines"){
    set_short(HIR+"A Book of Engines"+NORM);
    set_long("The hardcover of the book is red.  Another fundamental subject of\n"+
             "mechanical engineering:  the transformation of chemical energy into\n"+
             "mechanical one is a key factor to learn for a good engineer.\n");}

if(argomento=="fluid dynamics"){
    set_short(HIG+"A Book of Fluid Dynamics"+NORM);
    set_long("The hardcover of this book is green.  This is another subject which\n"+
             "bridges the gap between the basic courses of math and the following\n"+
             "ones dedicated to the application.  Of course, both gases and liquids\n"+
             "are studied, like it might occur in the movement of a ship or an airplane.\n");}

if(argomento=="geometry"){
    set_short(GRN+"A Book of Geometry"+NORM);
    set_long("The hardcover of the book is pale green.  This book is used by students in\n"+
             "their first year of engineering when they have to build up the basis\n"+
             "for their further studies. It basically reports the study of how a shape\n"+
             "can be described by mathematical formulas.\n");}

if(argomento=="machines"){
    set_short(HIR+"A Book of Machines"+NORM);
    set_long("The hardcover of the book is red.  The basic principles of how it is\n"+
             "possible to describe the thermodynamic behaviour of fluids in order\n"+
             "to build up the theory needed for the construction of useful devices.\n"+
             "This subject is taught at the junior year of mechanical engineering.\n");}

if(argomento=="production systems"){
    set_short(HIM+"A Book of Production Systems"+NORM);
    set_long("The hardcover of this book is magenta.  Not only the production of a\n"+
             "single piece by a single machine is important, yet in the modern industry\n"+
             "a key factor is the integration bewteen different machines and different\n"+
             "products. This is the subject covered by this book.\n");}

if(argomento=="management"){
    set_short(YEL+"A Book of Management"+NORM);
    set_long("The softcover of this book is dark brown.  The subject covered by this book\n"+
             "is basically the economics. Not only the mechanical engineers must know the\n"+
             "best design methods and technologies to make their products of high quality\n"+
             "yet they must compete in a global market from the ecnonomics and industrial\n"+
             "strategies points of view.  This is what this book is meant to teach.\n");}

if(argomento=="manufacturing"){
    set_short(HIC+"A Book of Manufacturing"+NORM);
    set_long("The hardcover of this book is pale blue.  This book is used by students in\n"+
             "their first year of engineering when they have to build up the basis\n"+
             "for their further studies. It basically reports the study of the matter\n"+
             "and its transformations.\n");}

if(argomento=="mechanics of materials"){
    set_short(BLU+"A Book of Mechanics of Materials"+NORM);
    set_long("The hardcover of the book is dark blue.  This book is used by students in\n"+
             "their second year of engineering and it introduces them to problem solving\n"+
             "related to the mechanical resistance of components and structures. The \n"+
             "mathematical formulations of the problems is still of great help here.\n");}

if(argomento=="metallurgy"){
    set_short(HIW+"A Book of Metallurgy"+NORM);
    set_long("The softcover of this book is white.  This book has two souls: one is related\n"+
             "to the inner matter constitution, the other is connected with the practical\n"+
             "operations that might be performed onto metals to modify them in order to\n"+
             "meet the aforeseen performances required by the engineers.\n");}

if(argomento=="operations research"){
    set_short(HIG+"A Book of Operations Research"+NORM);
    set_long("The softcover of the book is green.  Much mathematics is still present.\n"+
             "The methods for a comprehensive and rigorous approach to problem solving\n"+
             "are shown and will permit the students to analyze also very complex systems.\n"+
             "This subject is taught at the third year of mechanical engineering.\n");}

if(argomento=="physics"){
    set_short(WHT+"A Book of Physics"+NORM);
    set_long("The hardcover of the book is pink.  This book is used by students in\n"+
             "their first year of engineering when they have to build up the basis\n"+
             "for their further studies. It basically reports the study of the\n"+
             "fundamental laws governing the nature, in terms of mechanics, thermo-\n"+
             "dynamics and electromagnetism.\n");}

if(argomento=="robotics"){
    set_short(MAG+"A Book of Robotics"+NORM);
    set_long("The softcover of this book is light magenta.  The application of the robots\n"+
             "will be wider and wider in the future, in order to save human beings from\n"+
             "heavy and repetitive tasks.  It is needed to study the laws governing the\n"+
             "use of such helpers,  yet a look is also taken to their construction.\n");}

if(argomento=="thermodynamics"){
    set_short(WHT+"A Book of Thermodynamics"+NORM);
    set_long("The hardcover of the book is light gray.  This book is used by students in\n"+
             "their second year of engineering in order to go deeper inside the heat\n"+
             "transfer problems.  It also shows interesting practical applications such\n"+
             "as the air conditioning and the waste recycling for energy saving.\n");}

}
reset(arg)
   { if(arg) return;}

id(str) { return str == "book" || str =="libro"; }

init() {
    add_action("return_book","return");
    return 1;
}

return_book(arg) {
    object item;
    if(!arg)
      {notify_fail("Return what??\n"); return 0; }
    if(arg=="book" || arg=="argomento")
    { 
    if(!present("marian",environment(this_player())))
     {
      notify_fail("Unfortunately, "+call_other(this_player(),"query_name")+", you cant return this book now.\n"+
            "You may wish to try later, when the librarian will come back.\n");
      return 0;
     }
      call_other(this_player(),"add_money",coins); 
      write("The librarian softly says:  Thank you very much, "+call_other(this_player(),"query_name")+",\n"+
            "I was exactly looking for this book of "+argomento+".\n");
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


