
id(str) { return str == "key" || str == "canyonero_enginekey"; }

short() { return "A Canyonero ignition key"; }

long()
{
    write("This is the largest ignition key for a vehicle you have ever seen.\n");
    write("It has a picture of Texas on it, and inside is inscribed the word 'Canyonero!'.\n");
}

get() { return 1; }
query_value() { return 100; }
query_weight() { return 1; }

