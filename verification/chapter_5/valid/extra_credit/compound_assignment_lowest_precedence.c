int main(void) {
    int a = 10;
    int b = 12;
    int c = 14;
    int d = 16;

    a += 0 || b;  // a = 11
    b *= a && 0;  // b = 0

    c -= a || b;  // c = 13

    d /= c || d; // d = 16
    return (a == 11 && b == 0 && c == 13 && d == 16);
}
