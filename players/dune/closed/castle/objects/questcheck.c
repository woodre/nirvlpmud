inherit "obj/clean";


int first_half, second_half;

id(str) { return str == "dunequestorb" || str == "orb"; }

get() { return 1; }
drop() { return 0; }
query_weight() { return 1; }
query_value() { return 1000; }

reset() {}

short() { return "The Flux Orb"; }
long() { write(
"     You hold the Flux Orb, ancient Sithi artifact.\n");
}

first_half_of_quest_is_solved(int new)  { first_half = new; }
second_half_of_quest_is_solved(int new) { second_half = new; }
int quest_number() { return (first_half + second_half); }
