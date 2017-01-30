
id(str) { return str == "key" || str == "tiger1_enginekey"; }

short() { return "A Tiger 1 ignition key"; }

long()
{
    write("This is a small metal key with some German written on it, and a serial number.\n");
}

get() { return 1; }
query_value() { return 100; }
query_weight() { return 1; }

