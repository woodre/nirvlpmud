
id(str) { return str == "key" || str == "canyonero_key"; }

short() { return "A Canyonero door key"; }

long()
{
    write("This is a massive hunk of machined metal with a picture of Dick Cheney on it.\n");
    write("It is apparently used for the Canyonero door lock.\n");
}

get() { return 1; }
query_value() { return 100; }
query_weight() { return 1; }

