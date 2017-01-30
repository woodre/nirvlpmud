
id(str) { return str == "oil drum" || str == "drum" || str == "tiger1_fuel"; }

short() { return "A 55 gallon oil drum"; }

long()
{
    write("This is a large, heavy tank filled with petrol, instead of oil for some reason.\n");
    write("You wonder what the hell could possibly consume all this fuel in one shot!\n");
}

get() { return 1; }
query_value() { return 100; }
query_weight() { return 10; }

query_fuel() { return 5; }