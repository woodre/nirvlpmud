inherit "/players/mizan/core/object.c";
#include "/obj/ansi.h"

string fortunes;

reset(arg)
{
    fortunes = ({
    "What are you doing on the mud? Don't you have work to do?",
    "Life is so short but that there is always time for courtesy.\n\n\t\t\t-Ralph Waldo Emerson-",
    "Tolerance is another word for difference.\n\n\t\t\tW. Somerset Maugham",
    "It takes an endless amount of history to make even a little tradition.\n\n\t\t\tHenry James",
    "Tradtionalists are pessimists about the future and optimists about the past.\n\n\t\t\tLewis Mumford",
    "Tradition does not mean that the living are dead, but that the dead are living.\n\n\t\t\tGilbert K. Chesterson",
    "Better an ugly face than an ugly mind.\n\n\t\t\tJames Ellis",
    "Understanding is a two-way street.\n\n\t\t\tEleanor Roosevelt",
    "Vengeance has no foresight.\n\n\t\t\tNapoleon Bonaparte",
    "Revenge is the abject pleasure of an abject mind.\n\n\t\tJuvenal",
    "Popular opinion is the greatest lie in the world.\n\n\t\t\tThomas Carlyle",
    "Authority is no stronger than the man who wields it.\n\n\t\t\t-Dolores E. McGuire-",
    "When you take stuff from one writer, it's plagiarism; but when you take it from many writers, it's research.\n\n\t\t\tWilson Mizner",
    "Every new opinion, at its starting, is precisely a minority of one.\n\n\t\t\tThomas Carlyle",
    "Should'nt you be doing other work right now?",
    "The true work of art is but a shadow of the divine perfection.\n\n\t\t\t-Michelangelo-",
    "When angry, count four; when very angry, swear.\n\n\t\t\t-Mark Twain-",
    "Do not anticipate trouble, or worry about what may never happen. Keep in the sunlight.\n\n\t\t\t-Benjamin Frankin-",
    "The only sure thing about luck is that it will change.\n\n\t\t\t-Wilson Mizner-",
    "Cheer up, the worst is yet to come.\n\n\t\t\t-Philander Johnson-",
    "Nothing is more sad than the death of an illusion.\n\n\t\t\t-Arthur Koelstner-",
    "Everyone thinks of changing the world, but no one thinks of changing himself.\n\n\t\t\t-Leo Tolstoi-",
    });

    ::reset(arg);
    if(arg) return;


    set_get(0);
    set_short("A frozen " + BLU + "blue" + NORM + " button");
    set_long("This is a blue button suspended in nowhere in particular.\n"+
       "It cries out just to be pushed.\n");
    set_name("button");

    set_smell("The button smells like blueberries!\n");
    set_taste("The sign tastes like rotten blueberries. Ick!\n");
}

init() 
{
    add_action("on_pushme","push");
}

on_pushme(str) 
{
    if(!str || str != "button") return 0;
    write(fortunes[random(sizeof(fortunes))] + "\n");
    say((this_player()->query_name())+" pushes the button and recieves some profound information.\n");
    return 1;
}

