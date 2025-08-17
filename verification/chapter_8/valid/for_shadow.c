int main(void) {
    int shadow = 1;
    int acc = 0;
    {
        int shadow;
        for (shadow = 0; shadow < 10; shadow = shadow + 1) {
            acc = acc + shadow;
        }
    }
    return acc == 45 && shadow == 1;
}
