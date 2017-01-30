void assign(mixed destination, mixed source) {
            destination = source;
        }

        void extract_number(int destination, string source) {
            sscanf(source, "%d", destination);
        }

        void test() {
            int i;
            float f;
            mixed *a;

            extract_number(&i, "42 palantirs");
            assign(&f, 3.141592653589793);
            assign(&a, ({ i, f }));
            assign(&(a[<0..<1]), ({1,2,3,"sink","x","y","x"}));
            assign(&(a[5][0]), 'w');
            assign(&(a[5][<1]), 'g');
            printf("%O", a);
        }
